//--------------------------------------------------------------
// NOME : Henrique Tsuyoshi Yara
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ######### ESCREVA O NROUSP AQUI
int nroUSP() {
    return 11796083;
}

//-------------------------------------------

// CHLINK eh um par <chave,link> - dentro de cada página há 3 CHLINKs
typedef struct {
    int chave;
    int linkdir;
} CHLINK;

// definicao de pagina da árvore / registro do aquivo
typedef struct {
    int np; // armazene aqui o nro da pagina no arquivo
    int cont; // armazene aqui a quantidade de chaves existentes no vetor CHLINK[]
    CHLINK item[3]; // a chave[0] eh desprezada, e o linkdir[0] eh na verdade o link esquerdo da chave[1]
} PAGINA;


// funcao principal
void inserir(char nomearq[], int* raiz, int ch);


//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------

#define defseek(np) fseek(f, sizeof(PAGINA)*np, SEEK_SET)
#define defdividir(p, prom) dividir(f, r, fSize, p, prom)
#define pch0 p->item[0].chave
#define pch1 p->item[1].chave
#define pch2 p->item[2].chave
#define pln0 p->item[0].linkdir
#define pln1 p->item[1].linkdir
#define pln2 p->item[2].linkdir

int getSize (FILE* f) {
    fseek(f, 0, SEEK_END);
    return ftell(f) / sizeof(PAGINA);
}

void pWrite(FILE* f, PAGINA* p) {
    defseek(p->np);
    fwrite(p, sizeof(PAGINA), 1, f);
}

void ins(FILE * f, PAGINA* p, int ch) {
    p->cont++;
    if(pch1 == -1) pch1 = ch;
    else if(ch > pch1) pch2 = ch;
    else {
        pch2 = pch1;
        pch1 = ch;
    }
    pWrite(f, p);
}

PAGINA* instPag(FILE* f, int* np) {
    PAGINA* p = (PAGINA*) malloc(sizeof(PAGINA));
    p->np= *np;
    *np += 1;
    p->cont = 0;
    for(int i=0; i<3; i++)
        p->item[i].chave = -1;
    for(int i=0; i<3; i++)
        p->item[i].linkdir = -1;
    pWrite(f, p);
    return p;
}

PAGINA* dividir(FILE* f, int* r, int* fSize, PAGINA* p, PAGINA* prom) {
    if(p->cont < 2) {
        ins(f, p, prom->item[1].chave);
        *fSize -= 1;
        if(prom->item[1].chave == pch1) {
            pln2 = pln1;
            pln0 = prom->item[0].linkdir;
            pln1 = prom->item[1].linkdir;
        } else {
            pln1 = prom->item[0].linkdir;
            pln2 = prom->item[1].linkdir;
        }
        free(prom);
        pWrite(f, p);

        return NULL;
    } else {
        PAGINA* promLoc = NULL;
        PAGINA* pLoc = instPag(f, fSize);

        int prom_esq = prom->item[0].linkdir;
        int prom_dir = prom->item[1].linkdir;
        prom->item[0].linkdir = pLoc->np;
        prom->item[1].linkdir = p->np;

        if(pln0 != -1 || pln1 != -1 || pln2 != -1) {
            if (prom->item[1].chave < pch1) {
                pln0 = pln1;
                pln1 = pln2;
                pLoc->item[0].linkdir = prom_esq;
                pLoc->item[1].linkdir = prom_dir;
            } else if (prom->item[1].chave < pch2 || pln2 == -1) {
                pLoc->item[0].linkdir = pln0;
                pLoc->item[1].linkdir = prom_esq;
                pln0 = prom_dir;
                pln1 = pln2;
            } else if (pln2 != -1) {
                pLoc->item[0].linkdir = pln0;
                pLoc->item[1].linkdir = pln1;
                pln0 = prom_esq;
                pln1 = prom_dir;
            }
            pln2 = -1;
        }

        if(prom->item[1].chave < pch1) {
            int t = prom->item[1].chave;
            prom->item[1].chave = pch1;
            ins(f, pLoc, t);
            pch1 = pch2;
        } else if(prom->item[1].chave < pch2) {
            ins(f, pLoc, pch1);
            pch1 = pch2;
        } else {
            int t = prom->item[1].chave;
            prom->item[1].chave = pch2;
            ins(f, pLoc, pch1);
            pch1 = t;
        }
        pch2 = -1;
        p->cont--;

        pWrite(f, p);
        pWrite(f, pLoc);
        pWrite(f, prom);

        if(p->np != *r ) promLoc = prom;
        else *r = prom->np;

        free(pLoc);
        return promLoc;
    }
}

PAGINA* busca(FILE* f, int* r, int* fSize, PAGINA* p, int ch) {
    if(pch1 == ch || pch2 == ch) return NULL;

    if(pln0 != -1 || pln1 != -1 || pln2 != -1) {
        PAGINA* filho = (PAGINA*) malloc(sizeof(PAGINA));
        int filhoNp;
        if(ch < pch1) filhoNp = 0;
        else if(ch < pch2) filhoNp = 1;
        else if(pln2 != -1) filhoNp = 2;
        else filhoNp = 1;

        defseek(p->item[filhoNp].linkdir);
        fread(filho, sizeof(PAGINA), 1, f );

        PAGINA* prom = busca(f, r, fSize, filho, ch);
        if(prom != NULL) {
            if(pln2 == -1 || (p->np == *r && pln2 != -1)) defdividir(p, prom);
            else return defdividir(p, prom);
        }
        free(filho);
    } else {
        if(p->np == *r) {
            PAGINA* prom = instPag(f, fSize);
            ins(f, prom, ch);
            defdividir(p, prom);
            return NULL;
        } 

        if(p->cont < 2) ins(f, p, ch);
        else { PAGINA* promf1 = instPag(f, fSize); PAGINA* promf2= instPag(f, fSize); PAGINA* prom = instPag(f, fSize);
            prom->item[0].linkdir = promf1->np;
            prom->item[1].linkdir = promf2->np;

            int pCh = pch1, pCh1 = ch, pCh2= pch2;
            if(ch > pch2) {
                pCh = pch2;
                pCh1 = pch1;
                pCh2 = ch;
            } else if(ch > pch1) { 
                pCh = ch;
                pCh1 = pch1;
                pCh2 = pch2;
            }

            ins(f, prom, pCh);
            ins(f, promf1, pCh1);
            ins(f, promf2, pCh2);

            return prom;
        }
    }
    return NULL;
}


void inserir(char nomearq[], int* raiz, int ch) {
    int fSize = 0;
    FILE* f;
    PAGINA* p = (PAGINA*) malloc(sizeof(PAGINA));
    if(*raiz == -1) {
        *raiz = 0;
        f = fopen(nomearq, "w");
        p = instPag(f, &fSize);
        ins(f, p, ch);
    } else if(*raiz > -1) {
        f = fopen(nomearq, "rb+");
        defseek(*raiz);
        fread(p, sizeof(PAGINA), 1, f);
        fSize = getSize(f);
        busca(f, raiz, &fSize, p, ch);
    }
    fclose(f);
    free(p);
}
