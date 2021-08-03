NO* encontrarPrecedente(NO* p, int ch) {
    if(p) {
        if(p->chave == ch) {
        if(p->esq) return p->esq;
        return NULL;
    }
    if(p->dir) {
        if(p->dir->esq)
            if(!p->dir->esq->esq)
                if(p->dir->esq->chave == ch)
            return p;
        if(p->dir->chave == ch)
            return p;
    }
        if(encontrarPrecedente(p->esq, ch)) return encontrarPrecedente(p->esq, ch);
        if(encontrarPrecedente(p->dir, ch)) return encontrarPrecedente(p->dir, ch);
    }
}
 
void precedente(NO* p, int ch) {
    p = encontrarPrecedente(p, ch);
    if(p) printf("%d\n", p->chave);
}

