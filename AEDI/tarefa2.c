int ocorrencias(LISTA* l, int x){
    int cont = 0, i;
    for(i=0;i<=l->nroElem;i++)if(l->A[i].chave == x)cont++;
    return cont;
}

bool identicas(LISTA* l1, LISTA *l2){
    int i=0;
    if(l1->nroElem!=l2->nroElem)return false;
    for(;i<l1->nroElem;i++) if(l1->A[i].chave!=l2->A[i].chave) return false;
    return true;
}

