void exibirFolhas(NO* p){
    if(p){
        if(!p->esq && !p->dir) printf("[%d] ", p->chave);
        exibirFolhas(p->dir);
        exibirFolhas(p->esq);
    }
}
 
int exibeAncestrais(NO* p, int x){
    if(p){
        if(p->chave == x) return 1;
        if(exibeAncestrais(p->dir, x) == 1){
            printf("[%d] ", p->chave);
            return 1;
        }
        if(exibeAncestrais(p->esq, x) == 1){
            printf("[%d] ", p->chave);
            return 1;
        }
    }
}

