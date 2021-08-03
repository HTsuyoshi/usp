NO* listaNumerada(int n){
    NO* lista;
    lista = (NO*) malloc(sizeof(NO));
    lista->prox = NULL;
    lista->chave = n;
    n--;
 
    while (n > 0){
        NO* aux;
        aux = (NO*) malloc(sizeof(NO));
        aux->prox = lista;
        lista->ant = aux;
        lista = lista->ant;
        lista->chave = n;
        n--;
    }
 
    lista->ant = NULL;
    return lista;
}
 
void moverParaFim(LISTA* l, NO* p){
    NO* aux;
    aux = l->inicio;
 
    if(l->inicio == aux) l->inicio = l->inicio->prox;
 
    while(aux != p){
        aux = aux->prox;
    }
 
    NO* aux1;
    aux1 = aux;
 
    if(aux->prox){
    if(aux->ant){
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    aux = aux->prox;
 
    while(aux->prox){
        aux = aux->prox;
    }
 
    aux1-> prox = NULL;
    aux->prox = aux1;
    aux1->ant = aux;
    }
}

