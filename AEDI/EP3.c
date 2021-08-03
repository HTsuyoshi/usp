// Henrique Tsuyoshi Yara

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>



// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("11796083");
}


// no da arvore
typedef struct estr {
        int chave;
        struct estr *esq;
	struct estr *dir;
} NO;



void organizar(NO* *raiz);

// func auxiliar

// Achar a chave que vai substituir a chave apagada

NO* acharMaiorNOEsq(NO* p) {
	if(!p->dir) return p;
	else return acharMaiorNOEsq(p->dir);
}

NO* acharMaiorNODir(NO* p) {
	if(!p->esq) return p;
	else return acharMaiorNODir(p->esq);
}

// Achar o pai da chave que vai substituir a chave apagada

NO* acharPaiMaiorNOEsq(NO* p, int ch) {
	if(p->dir) if(p->dir->chave == ch) return p;
	else return acharPaiMaiorNOEsq(p->dir, ch);
	return NULL;
}

NO* acharPaiMaiorNODir(NO* p, int ch) {
	if(p->esq) if(p->esq->chave == ch) return p;
	else return acharPaiMaiorNODir(p->esq, ch);
	return NULL;
}

NO* verificarRaiz(NO* raiz) {
	if(raiz->esq) {
		if(raiz->esq->chave > raiz->chave) {
			if(raiz->dir) {
				if(raiz->esq->chave > raiz->dir->chave) return raiz->esq;
				if(raiz->dir->chave < raiz->esq->chave) return raiz->esq;
			}
			if(raiz->esq->esq)
				if (raiz->esq->esq->chave > raiz->esq->chave) return raiz->esq;
			if(raiz->esq->dir)
				if(raiz->esq->dir->chave < raiz->esq->chave) return raiz->esq;
			return raiz;
		}
	}
	if(raiz->dir) {
		if(raiz->dir->chave < raiz->chave) {
			if(raiz->esq) {
				if (raiz->dir->chave < raiz->esq->chave) return raiz->dir;
				if (raiz->esq->chave > raiz->dir->chave) return raiz->dir;
			}
			if(raiz->dir->esq)
				if(raiz->dir->esq->chave > raiz->dir->chave) return raiz->dir;
			if(raiz->dir->dir)
				if(raiz->dir->dir->chave < raiz->dir->chave) return raiz->dir;
			return raiz;
		}
	}
	return NULL;
}

NO* acharErradoEsquerda(NO* p, NO* raiz) {
	if(p->esq) {
		if(p->esq->chave > raiz->chave) return p->esq;
		if(p->esq->chave > p->chave) return p->esq;
 		if(acharErradoEsquerda(p->esq, raiz)) return acharErradoEsquerda(p->esq, raiz);
	}
	if(p->dir){
		if(p->dir->chave > raiz->chave) return p->dir;
		if(p->dir->chave < p->chave) return p->dir;
		if(acharErradoEsquerda(p->dir, raiz))return acharErradoEsquerda(p->dir, raiz);
	}
	return NULL;
}

NO* acharErradoDireita(NO* p, NO* raiz) {
	if(p->esq) {
		if(p->esq->chave < raiz->chave) return p->esq;
		if(p->esq->chave > p->chave) return p->esq;
		if(acharErradoDireita(p->esq, raiz)) return acharErradoDireita(p->esq, raiz);
	}
	if(p->dir){
		if(p->dir->chave < raiz->chave) return p->dir;
		if(p->dir->chave < p->chave) return p;
		if(acharErradoDireita(p->dir, raiz))return acharErradoDireita(p->dir, raiz);
	}
	return NULL;
}

NO* acharErrado(NO* p, NO* raiz) {
	
	// ver se a raiz esta errada
	if(verificarRaiz(raiz)) return verificarRaiz(raiz);
	
	// verificar os casos onde so existe a chave da esquerda ou da direita
	if(p->esq && !p->dir)
		if(p->esq->chave > raiz->chave) return raiz;
	else if(p->dir && !p->esq)
		if(p->dir->chave < raiz->chave) return raiz;
	
	// verificar o lado esquerdo comparando com a raiz
	if(p->esq) {
		if(p->esq->chave > raiz->chave) return p->esq;
		if(acharErradoEsquerda(p->esq, raiz)) return acharErradoEsquerda (p->esq, raiz);
	}
	
	//verificar o lado direito comaprando com a raiz
	if(p->dir){
		if(p->dir->chave < raiz->chave) return p->dir;
		if(acharErradoDireita(p->dir, raiz)) return acharErradoDireita (p->dir, raiz);
	}
	
	return NULL;
}

// criar a arvore binaria

NO* inicializarNO(int ch) {
	NO* p;
	p = malloc ( sizeof (NO*));
	p->chave = ch;
	p->dir = NULL;
	p->esq = NULL;
	return p;
}

//------------------------------------------
// O EP consiste em implementar esta funcao
//------------------------------------------

void organizar(NO* *raiz) {

	// seu codigo AQUI
	
	NO* p = *raiz;
	NO* trocar;
	
	// verificar se existe alguma chave errada
	if (acharErrado(p, p)) trocar = acharErrado(p, p);
	else return;
	
	NO* maior;
	maior = trocar;
	NO* paiMaior;
	paiMaior = NULL;
	
	// pegar a chave que vai substituir a chave errada
	if(trocar->esq){
		maior = acharMaiorNOEsq(trocar->esq);
	
		// caso a maior chave da esquerda tenha filho
		if (maior->esq) {
			if (acharPaiMaiorNOEsq(trocar->esq, maior->chave)) paiMaior = acharPaiMaiorNOEsq(trocar->esq, maior->chave);
			if(paiMaior != NULL)
				paiMaior->dir = maior->esq;
			else
				trocar->esq = maior->esq;
		}
	} else if(trocar->dir) {
		maior = acharMaiorNODir(trocar->dir);
		
		// caso a maior chave da direita tenha filho
		if (maior->dir) {
			if (acharPaiMaiorNODir(trocar->dir, maior->chave)) paiMaior = acharPaiMaiorNODir(trocar->esq, maior->chave);
			if(paiMaior != NULL)
				paiMaior->esq = maior->dir;
			else
				trocar->dir = maior->dir;
		}
	}
	
	// liberar a memoria que estava sendo ocupada pela chave errada
	trocar->chave = maior->chave;
	free (maior);
	p = NULL;
	
}

//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main() {
	
}

// por favor nao inclua nenhum código abaixo da função main()
