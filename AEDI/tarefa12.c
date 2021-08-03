int maiorAltura(int a, int b){
     if(a > b) return a;
     return b;
}

int altura(NO *p){
    if(!p || (!p->esq && !p->dir)) return 0;
    else return 1 + maiorAltura(altura(p->esq), altura(p->dir));
}
int menorChave(NO* p){
    if(!p->esq) return p->chave;
    if(!p) return -1;
    return menorChave(p->esq);
}

 
