#include<stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

typedef struct grafo {
	int vertices;
	int arestas;
	TIPOPESO **adj;
} GRAFO;

typedef struct aresta {
	struct aresta* prox;
	int v;
	int peso;
} NO;

typedef struct vert {
	NO* inicio;
	int flag;
	int temChave;
} VERTICE;

void inicializarValorNO(NO* no, int v, int peso, int flag, int temChave)
{
	no->v = v;
	no->peso = peso;
	no->prox = NULL;
}

VERTICE* inicializarVetor(int n)
{
	VERTICE* novo = (VERTICE*) malloc(sizeof(VERTICE)*n);

	for(int i=0; i<n; i++) {
		novo[i].flag = 0;
		if(rand() % 2 == 1)
			novo[i].temChave = 1;
		else
			novo[i].temChave = 0;
		NO* no = (NO*) malloc(sizeof(NO*));
		inicializarValorNO(no, 0, 0, 0, 0);
		novo[i].inicio = no;
	}
	return novo;
}

void instanciarVertice(VERTICE* vetor, int array[], int index, int size)
{
	NO* no = vetor[index].inicio;
	inicializarValorNO(no, array[0], 0, 0, 0);
	for(int i=1; i<size; i++){
		NO* novo = (NO*) malloc(sizeof(NO*));
		inicializarValorNO(novo, array[i], 0, 0, 0);
		no->prox = novo;
		no = no->prox;
	}
}

void printTodosOsVertices(VERTICE* vetor, int n)
{
	int i=0;
	while(i<n) {
		NO* no = vetor[i].inicio;
		int j=0;
		printf("Vetor %d ", i);
		printf("chave: %d\n", vetor[i].temChave);
		while(no) {
			printf("\taresta %d: ", j);
			printf("\tv: %d ", no->v);
			printf("\n");
no = no->prox;
			j++;
		}
		printf("\n");
		i++;
	}
}


void salasComChaves(VERTICE* g, int i, NO** listaLigada)
{
	g[i].flag = 1;

	if(g[i].temChave == 1) {
		if(!(*listaLigada)) {
			(*listaLigada) = (NO*) malloc(sizeof(NO*));
			(*listaLigada)->v = g[i].inicio->v;
			(*listaLigada)->peso = g[i].inicio->peso;
		} else {
			NO* aux = (*listaLigada);
			while(aux->prox)
				aux = aux->prox;
			aux->prox = (NO*) malloc(sizeof(NO*));
			aux->prox->v = g[i].inicio->v;
			aux->prox->peso = g[i].inicio->peso;
		}
	}

	NO* p = g[i].inicio;

	while(p) {
		if(g[p->v].flag == 0)
			salasComChaves(g, p->v, listaLigada);
		p = p->prox;
	}

	g[i].flag = 2;
}

int main()
{
	int n = 5;
	VERTICE* vertice = inicializarVetor(n);
	NO* no = vertice->inicio;

	// Inicializar
	int array1[] = {1};
	instanciarVertice(vertice, array1, 0, 1); int array2[] = {2};
	instanciarVertice(vertice, array2, 1, 1);
	int array3[] = {4, 0};
	instanciarVertice(vertice, array3, 2, 2);
	int array5[] = {1};
	instanciarVertice(vertice, array5, 3, 1);
	int array4[] = {3};
	instanciarVertice(vertice, array4, 4, 1);

	printTodosOsVertices(vertice, n);
	printf("------------------------------------------------\n");
	printf("a\n");

	NO* listaLigada = NULL;

	salasComChaves(vertice, 0, &listaLigada);

	if(!listaLigada)
		printf("queissocaralho\n");
	while(listaLigada) {
		printf("%d", listaLigada->v); 
		listaLigada = listaLigada->prox;
   	}
   	return 0;
}
