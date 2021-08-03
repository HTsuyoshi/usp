void novoEsquerdo(NO* p){
    if(!p->esq){
        NO* novo;
        novo = (NO*) malloc(sizeof(NO));
        if(p->dir) novo->chave = p->dir->chave + p->chave;
        else novo->chave = p->chave;
        p->esq = novo;
    }
}

