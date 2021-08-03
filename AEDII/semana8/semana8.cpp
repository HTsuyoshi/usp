#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct aresta {
	struct aresta* prox;
	int v1;
	int v2;
	int custo;
} NO;

typedef struct {
	NO* inicio;
} VERTICE;

typedef struct {
	int v1;
	int v2;
	int custo;
} REGISTRO;

void instanciarNO (int v1, int v2, int custo, NO* no) 
{
	no->v1 = v1;
	no->v2 = v2;
	no->custo = custo;
}

NO* criarNO () 
{
	NO* novo = (NO*) malloc (sizeof (NO));
	novo->prox = NULL;
	novo->v1 = 0;
	novo->v2 = 0;
	novo->custo = 0;
	return novo;
}

void adicionarNO (NO** inicio, NO* novo)
{
	NO* aux = (*inicio);
	if (aux) {
		while (aux->prox)
			aux = aux->prox;
		aux->prox = novo;
	} else
		(*inicio) = novo;
}

void instanciarGrafo (VERTICE* grafo, NO* registros) 
{
	NO* aux = registros;
	while (aux) {
		// v1 para v2
		NO* novo = criarNO ();
		instanciarNO (aux->v1, aux->v2, aux->custo, novo);
		adicionarNO (&grafo[aux->v1].inicio, novo);

		if (aux->prox)
			aux = aux->prox;
		else
			break;
	}
}

VERTICE* criarGrafo ()
{
	int n = 10;
	VERTICE* novoGrafo = (VERTICE*) malloc (sizeof (VERTICE) * n);

	for (int i = 0; i < n; i++)
		novoGrafo[i].inicio = NULL;

	return novoGrafo;
}

void imprimirNO (NO* registro) 
{
	NO* inicio = registro;
	while (inicio) {
		printf ("v1: %d ", inicio->v1);
		printf ("v2: %d ", inicio->v2);
		printf ("custo: %d\n", inicio->custo);
		if (inicio->prox)
			inicio = inicio->prox;
		else
			break;
	}
}

void imprimirGrafo (VERTICE* grafo) 
{
	for (int i = 0; i < 10; i++) {
		printf ("No vertice %d:\n", i);
		NO* aux = grafo[i].inicio;
		imprimirNO (aux);
	}
}

void busca (VERTICE* grafo, int atual, int destino, int custoLocal, int* custo)
{
	if (atual == destino) {
		*custo = custoLocal;
		return;
	}
	if (*custo != -1) return;
	NO* auxiliar = grafo[atual].inicio;
	while (auxiliar) {
		busca (grafo, auxiliar->v2, destino, custoLocal + auxiliar->custo, custo);
		if (auxiliar->prox)
			auxiliar = auxiliar->prox;
		else
			break;
	}
}

int main () 
{
	FILE *arq;

	/*
	arq = fopen ("entrada.txt", "wb");
	REGISTRO alun[4] = {1, 2, 19, 3, 4, 34, 4, 2, 3, 2, 3, 43};
	fwrite(alun, sizeof(REGISTRO), 4, arq);
	fclose(arq);
	*/

	VERTICE *grafo;
	grafo = criarGrafo();

	arq = fopen ("entrada.txt", "rb");
	NO* inicio = NULL;
	REGISTRO auxiliar;

	while (0 != fread (&auxiliar, sizeof (REGISTRO), 1, arq)) { 
		NO* novo = criarNO ();
		novo->v1 = auxiliar.v1;
		novo->v2 = auxiliar.v2;
		novo->custo = auxiliar.custo;
		adicionarNO(&inicio, novo);
	}

	instanciarGrafo (grafo, inicio);
	// imprimirGrafo (grafo);

	int* custo = (int*) malloc (sizeof (int));
	*custo = -1;
	busca (grafo, 1, 3, 0, custo);
	printf ("Custo: %d\n", *custo);

	fclose (arq);
	return 0;
}
