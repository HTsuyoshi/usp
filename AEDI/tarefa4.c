int ocorrencias(LISTA* l, int x){
    NO* p = l->inicio;
    int vezes = 0;
    while(p) {
        if(p->chave == x) vezes++;
        p = p->prox;
    }
    return vezes;
}
 
bool identicas(LISTA* l1, LISTA* l2){
    NO* lista1 = l1->inicio;
    NO* lista2 = l2->inicio;
    int tam1 = 0, tam2 = 0;
    while(lista1 || lista2){
        if(lista1) tam1++;
        if(lista2) tam2++;
        if(lista1->chave != lista2->chave || tam1 != tam2)  return false;
            lista1 = lista1->prox;
            lista2 = lista2->prox;
}
    return true;
}

