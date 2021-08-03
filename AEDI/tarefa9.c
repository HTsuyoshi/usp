int valor(MATRIZ* m, int i, int j){
    if(m->maxlin < i || m->maxcol < j) return 0;
    NO* p;
    p = m->inicio;
    while(p){
        if(p->col == j && p->lin == i) return p->chave;
        p = p->prox;
    }
    return 0;
}
 
void exibirLinha(MATRIZ* m, int i) {
    NO* p;
    p = m->inicio;
    i = i - 1;
    int k, j;
    for(k = 0; k < m->maxlin; k++){
        for(j = 0; j < m->maxcol; j++){
            if(p->lin == i) printf("[%d] ", p->chave);
            if(p->lin > i) break;
            p = p->prox;
        }
    printf("\n");
    if(p->lin > i) break;
    }
}
 
void zerarDiagonal(MATRIZ* m) {
    NO* p;
    p = m->inicio;
    while(p){
        if(p->col == p->lin) p->chave = 0;
        p = p->prox;
    }
}
