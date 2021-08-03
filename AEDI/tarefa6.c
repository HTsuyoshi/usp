    PDINAM pilha;
    NO* copiaa;
    pilha.topo = NULL;
    if(!p) return NULL;
    while(p)
    {
        push(p->chave, &pilha);
        printf("%d ", p->chave);
        p = p->prox;
    }
    copiaa = copia(pilha.topo);
    while(p)
    {
        pop(&pilha);
        printf("%d ", p->chave);
        p = p->prox;
    }
    return copiaa;
}

 

