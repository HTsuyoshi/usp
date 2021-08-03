#include <stdlib.h>
#include <stdio.h>

typedef struct p{
	struct p *prox;
	int v;
} NO;

void criarListaRecursiva (NO** lista, int n)
{
	if (n == 1)
		return;

	// Descobri que atribuir (*lista) para uma variavel
	// e depois tentar acessar a lista criada no main 
	// por algum motivo nao funciona ???
	if (!(*lista)) {
		(*lista) = (NO*) malloc(sizeof(NO*));
		(*lista)->v = n;
	} else {
		NO* aux = (*lista);
		while (aux->prox){
			aux = aux->prox;
		}
		aux->prox = (NO*) malloc(sizeof(NO*));
		aux->prox->v = n;
	}
	criarListaRecursiva(lista, n-1);
}

int main()
{
	NO* lista = (NO*) malloc (sizeof(NO*)*10);
	lista = NULL;

	criarListaRecursiva (&lista, 10);

	while (lista) {
		printf("%d ", lista->v);
		lista = lista->prox;
	}

	return 0;
}
