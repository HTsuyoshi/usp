1.
Pre ordem: 18 17 12 3 9 15 2 13 16 6 5
Em ordem: 3 12 9 17 15 2 13 18 6 16 5
Pos ordem: 3 9 2 13 12 15 17 6 5 16 18
 
2.
NO* achar(NO* p, int ch){
    if(p) {
        if(p->chave == ch) return p;
            if(p->dir) {
                if(achar(p->dir, ch)->chave == ch){
                    p = achar(p->dir, ch);
                    return p;
                }
            }
            if(p->esq) {
                if(achar(p->esq, ch)->chave == ch){
                    p = achar(p->esq, ch);
                    return p;
                }
            }
        }
    return p;
    }
 
void excluirFolha (NO* *raiz, int ch) {
    NO* p;
    p = achar(*raiz, ch);
    free(p);
}

