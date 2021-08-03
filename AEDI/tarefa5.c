
void ExcluirOcorrencias (LISTA* l, int x) {
 
    NO* p = l->inicio;
    NO* ant = NULL;
 
    while (p) {
 
    if (p->chave == x) {
 
    if(ant){
        NO* aux = ant->prox;
        ant->prox = p->prox;
        free(aux);
        p = ant->prox;
    } else {
        NO* aux = p;
        l->inicio = p->prox;
        p = p->prox;
        free(aux);
    }
 
    } else {
 
        ant = p;
        p = p->prox;
 
        }
 
    }
 
}
 
NO* copia (NO* p) {
 
    NO* inicio = (NO*) malloc(sizeof(NO));
    if(!p) {
        inicio = NULL;
        return inicio; 
    }
    inicio->chave = p->chave;
    inicio->prox = NULL;
    NO* aux = inicio;
    p = p->prox;
 
    while(p){
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = p->chave;
        novo->prox = NULL;
        aux->prox = novo;
        aux = aux->prox;
        p = p->prox;
    }
 
    return inicio;
 
}

