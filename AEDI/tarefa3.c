void trocar(LISTA* l){
    if(l->nroElem > 2){
        int aux;
        aux = l->A[0].chave;
        l->A[0].chave = l->A[l->nroElem - 1].chave;
        l->A[l->nroElem - 1].chave = aux;
    }
}
 
void sobrescrever(LISTA* l, int i){
    if(i != l->nroElem){
        l->A[i+1].chave = l->A[i].chave;
    }
}

