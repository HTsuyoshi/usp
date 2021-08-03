#include<stdio.h>
#include <stdlib.h>

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
	no->peso = rand() % 10;
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
			printf("\tpeso: %d ", no->peso);
			printf("\n");
no = no->prox;
			j++;
		}
		printf("\n");
		i++;
	}
}

typedef struct registro {
	int i;
	struct registro* prox;
} REGISTRO;

typedef struct {
	REGISTRO* inicio;
	REGISTRO* fim;
} FILA;

void inicializarFila(FILA* f) {
	f->inicio = NULL;
	f->fim = NULL;
}

int sairFila(FILA* f) {
	if (!f->inicio) return -1;
	int i = f->inicio->i;
	REGISTRO* apagar = f->inicio;
	f->inicio = f->inicio->prox;
	free(apagar);
	if (!f->inicio) f->fim = NULL;
	return i;
}

void entrarFila (FILA* f, int i) {
	REGISTRO* novo = (REGISTRO*)malloc(sizeof(REGISTRO*));
	novo->i = i;
	novo->prox = NULL;
	if (!f->inicio) f->inicio = novo;
	else f->fim->prox = novo;
	f->fim = novo;
}

int custoChaveMaisProxima(VERTICE* g, int i) {
	int custo;
	FILA f;
	inicializarFila(&f);
	g[i].flag = 1;
	entrarFila(&f, i);

	while (f.inicio) {
		custo = 0;
		i = sairFila(&f);
		NO* p = g[i].inicio;
		while (p) {
			custo += p->peso;
			if(g[p->v].flag==0) {
				g[p->v].flag = 1;
				entrarFila(&f, p->v);
			}
			if (g[i].temChave == 1)	break;
			p = p->prox;
		}
		if (g[i].temChave == 1)	break;
		g[i].flag = 2;
	}
	return custo;
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

	NO* listaLigada = NULL;

	int custo;
	custo = custoChaveMaisProxima(vertice, 0);
	printf("%d\n", custo);

   	return 0;
}
