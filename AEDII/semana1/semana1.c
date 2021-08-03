#include <stdio.h>
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
} VERTICE;


/*
   GRAFO* criaGrafo(int v)
   {
   GRAFO* g = (GRAFO*) malloc(sizeof(GRAFO));
   g->vertices = v;
   g->arestas = 0;
   g->adj = (VERTICE*) malloc(sizeof(VERTICE)*v);
   for(int i=0; i<v; i++)
   g->adj[i].cab = NULL;
   return g;
   }
   */

void inicializarValorNO(NO* no, int v, int peso)
{
    no->v = v;
    no->peso = peso;
    no->prox = NULL;
}

VERTICE* inicializarVetor(int n)
{
    VERTICE* novo = (VERTICE*) malloc(sizeof(VERTICE)*n);

    for(int i=0; i<n; i++) {
        NO* no = (NO*) malloc(sizeof(NO*));
        inicializarValorNO(no, 0, 0);
        novo[i].inicio = no;
    }
    return novo;
}

void instanciarVertice(VERTICE* vetor, int array[], int index, int size)
{
    NO* no = vetor[index].inicio;
    inicializarValorNO(no, array[0], 0);
    for(int i=1; i<size; i++){
        NO* novo = (NO*) malloc(sizeof(NO*));
        inicializarValorNO(novo, array[i], 0);
        no->prox = novo;
        no = no->prox;
    }
}

/*
   void printTodosOsVertices(VERTICE* vetor, int n)
   {
   int i=0;
   while(i<n) {
   NO* no = vetor[i].inicio;
   int j=0;
   printf("v%d: ", i);
   while(no) {
   printf("v%d", no->v);
   no = no->prox;
   j++;
   }
   printf("\n");
   i++;
   }
   }
   */

void printTodosOsVertices(VERTICE* vetor, int n)
{
    int i=0;
    while(i<n) {
        NO* no = vetor[i].inicio;
        int j=0;
        printf("Vetor %d\n", i);
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

void adjacencia2incidencia(VERTICE* g, int n)
{
    // Por causa do slide eu considerei os valores v começando em 1 e nao em 0 como seria normalmente
    int i, j;
    NO* auxiliar[n][n];
    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
            auxiliar[i][j] = NULL;

    // Iterar sobre os NOs
    NO* aux;
    for(i=0; i<n; ++i)
        if(g[i].inicio) {
            NO* iterar = g[i].inicio;
            NO* prox;
            while(iterar) {
                prox = iterar->prox ? iterar->prox : NULL;
                auxiliar[i][iterar->v] = iterar;
                iterar->v = i;
                iterar->prox = NULL;
                iterar = prox;
            }
        }

    // Resetar o vetor
    for(i=0; i<n; ++i)
        g[i].inicio = NULL;

    // Colocar os valores no lugar certo
    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
            if (auxiliar[i][j])
                if(g[j].inicio) {
                    aux = g[j].inicio;
                    if (aux->prox)
                        while (aux->prox)
                            aux = aux->prox;
                    aux->prox = auxiliar[i][j];
                } else
                    g[j].inicio = auxiliar[i][j];
}

int main()
{
    int n = 5;
    VERTICE* vertice = inicializarVetor(n);
    NO* no = vertice->inicio;

    // Inicializar
    int array1[] = {1};
    instanciarVertice(vertice, array1, 0, 1);
    int array2[] = {2};
    instanciarVertice(vertice, array2, 1, 1);
    int array3[] = {4, 0};
    instanciarVertice(vertice, array3, 2, 2);
    int array5[] = {1};
    instanciarVertice(vertice, array5, 3, 1);
    int array4[] = {3};
    instanciarVertice(vertice, array4, 4, 1);

    printTodosOsVertices(vertice, n);
    printf("------------------------------------------------\n");
    adjacencia2incidencia(vertice, n);

    printTodosOsVertices(vertice, n);

    return 0;
}
