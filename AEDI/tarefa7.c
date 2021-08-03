

NO* exibirInvertida(LISTA* l) {
    NO* p;
    p = l->cabeca;
    printf("Lista Invertida:\n");
    p = p->ant;
    while (p != l->cabeca)  {
        printf("[%d] ", p->chave);
        p = p->ant;
    }
    printf("\n");
}

void inserirAntes(LISTA* l, int ch, NO* atual) {
    NO* novo;
    NO* ant;
    novo = (NO*) malloc(sizeof(NO));
    ant = atual->ant;
    novo->chave = ch;
    novo->prox = atual;
    novo->ant = ant;
    ant->prox = novo;
    atual->ant = novo;
    if(atual == l->cabeca) l->cabeca = novo;
}

