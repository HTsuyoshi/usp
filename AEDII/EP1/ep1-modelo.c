//--------------------------------------------------------------
// NOME : Henrique Tsuyoshi Yara
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#include <malloc.h>

// ######### ESCREVA O NROUSP AQUI
int nroUSP () { 
    return 11796083; 
}

//-------------------------------------------

// nos das listas de adjacencias
typedef struct adj {
    int v;
    struct adj *prox;
} NO;

// vertices
typedef struct {
    NO *inicio;
} VERTICE;

// funcao principal
NO *caminhos_max_d(VERTICE *g, int n, int x, int y, int d);

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------

void removerUltimoNO (NO** lista) 
{
    // NO auxiliar para achar o ultimo NO
    NO *ultimo = (*lista);
    NO *penultimo = NULL;

    while (ultimo->prox) {
	penultimo = ultimo;
	ultimo = ultimo->prox;
    }
    if (penultimo) penultimo->prox = NULL;
    free(ultimo);
}

int adicionarNO (NO** lista, int v) 
{
    NO *novo = (NO*) malloc (sizeof (NO));
    novo->v = v;
    novo->prox = NULL;

    NO *aux = *lista;
    if (aux) {
	// Verificar caminho simples
	while (aux->prox) {
	    aux = aux->prox;
	    if (aux->v == v) return 0;
	}
	aux->prox = novo;
    } else
	lista = &novo;
    return 1;
}

void adicionarNOSemVerificar (NO** lista, int v) 
{
    NO *novo = (NO*) malloc (sizeof (NO));
    novo->prox = NULL;
    novo->v = v;

    NO *aux = *lista;
    if (aux) {
	while (aux->prox)
	    aux = aux->prox;
	aux->prox = novo;
    } else
	lista = &novo;
}

void copiarLista (NO** lista, NO** listaSaida, int tamanhoLista) 
{
    // Verificar se a lista ja existe na listaSaida
    int qntIgual, parar;
    NO *listaFinal = (*listaSaida);
    NO *listaAtual = (*lista)->prox;

    if (listaAtual)
	parar = listaAtual->v;
    else
	return;

    while (listaFinal) {
	listaAtual = (*lista)->prox;

	while (listaFinal->v == listaAtual->v) {
	    qntIgual = tamanhoLista;
	    listaFinal = listaFinal->prox;
	    listaAtual = listaAtual->prox;

	    while (listaFinal && listaAtual) {
		if (listaFinal->v == parar) break;
		if (listaAtual->v == listaFinal->v) 
		    qntIgual--;
		else
		    qntIgual++;

		listaFinal = listaFinal->prox;
		listaAtual = listaAtual->prox;
	    }

	    if (!qntIgual) return;

	    if (!listaFinal || !listaAtual) break;

	    listaAtual = listaAtual->prox;
	    listaFinal = listaFinal->prox;

	    if (!listaFinal || !listaAtual) break;
	}


	if (listaFinal)
	    listaFinal = listaFinal->prox;
    }

    // Copiar a lista auxiliar para a lista final
    listaFinal = (*listaSaida);
    listaAtual = (*lista)->prox;

    while (listaAtual) {
	adicionarNOSemVerificar (listaSaida, listaAtual->v);
	if (listaAtual->prox) listaAtual = listaAtual->prox;
	else break;
    }
}

void busca (VERTICE *g, NO** lista, NO** listaSaida, int n, int origem, int destino, int distanciaAtual, int distancia) 
{
    int caminhoSimples = 0;

    // Por algum motivo vai entrar em um VERTICE que nao existe
    if (origem > n || destino > n || origem < 1 || destino < 1) return;

    // Passou a distancia aceitavel
    if (distanciaAtual > distancia) return;

    // Adicionar NO
    caminhoSimples = adicionarNO (lista, origem);

    // Se o caminho não for simples
    if (caminhoSimples == 0) return;

    // Copiar a lista caso tenha chego no destino
    if (origem == destino) {
	copiarLista (lista, listaSaida, distanciaAtual);
	removerUltimoNO (lista);
	return;
    }

    // Entrar nos NOs que o NO atual aponta
    NO *aux = g[origem].inicio;
    while (aux) {
	busca (g, lista, listaSaida, n, aux->v, destino, distanciaAtual + 1, distancia);
	if (aux->prox) aux = aux->prox;
	else break;
    }

    // Remover o NO da lista auxiliar que ja passou
    removerUltimoNO (lista);
}

NO *caminhos_max_d (VERTICE* g, int n, int x, int y, int d) 
{
    if (x > n || y > n || x < 1 || y < 1) return NULL;

    NO *lista = (NO*) malloc (sizeof (NO));
    NO *listaSaida = (NO*) malloc (sizeof (NO));

    busca (g, &lista, &listaSaida, n, x, y, 0, d);
    NO *output = listaSaida->prox;

    free (listaSaida);
    free (lista);

    return output;
}

//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
// mas nao entregue o codido de main() nem inclua nada
// abaixo deste ponto
//---------------------------------------------------------

void inicializarValorNO(NO *no, int v) {
    no->v = v;
    no->prox = NULL;
}

VERTICE *inicializarVetor(int n) {
    VERTICE *novo = (VERTICE *)malloc(sizeof(VERTICE) * n);

    for (int i = 0; i < n; i++) {
	NO *no = (NO *)malloc(sizeof(NO *));
	inicializarValorNO(no, 0);
	novo[i].inicio = no;
    }
    return novo;
}

void instanciarVertice(VERTICE *vetor, int array[], int index, int size) {
    NO *no = vetor[index].inicio;
    if (size > 0)
	inicializarValorNO(no, array[0]);
    else
	vetor[index].inicio = NULL;
    for (int i = 1; i < size; i++) {
	NO *novo = (NO *)malloc(sizeof(NO *));
	inicializarValorNO(novo, array[i]);
	no->prox = novo;
	no = no->prox;
    }
}

void printTodosOsVertices(VERTICE *vetor, int n) {
    int i = 1;
    while (i < n) {
	NO *no = vetor[i].inicio;
	int j = 0;
	printf("Vetor %d \n", i);
	while (no) {
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

void printarLista(NO *auxiliar, int comeco) {
    if (auxiliar)
	while (auxiliar) {
	    if (auxiliar->v == comeco)
		printf("%d ", auxiliar->v);
	    else
		printf("%d ", auxiliar->v);
	    auxiliar = auxiliar->prox;
	}
    else
	printf("NULL");
    printf("\n\n");
}

int main() {
    if (nroUSP() == 0)
	printf("\n\nNro USP nao informado!!!\n\n");
    int n = 17;
    VERTICE *vertice = inicializarVetor(n);
    NO *no = vertice->inicio;

    // Inicializar
  int array1[] = {2, 3, 4};
  int quantidade = sizeof(array1) / sizeof(int);
  instanciarVertice(vertice, array1, 1, quantidade);

  int array2[] = {1, 5};
  quantidade = sizeof(array2) / sizeof(int);
  instanciarVertice(vertice, array2, 2, quantidade);

  int array3[] = {1, 5, 7, 8};
  quantidade = sizeof(array3) / sizeof(int);
  instanciarVertice(vertice, array3, 3, quantidade);

  int array4[] = {1, 8, 9};
  quantidade = sizeof(array4) / sizeof(int);
  instanciarVertice(vertice, array4, 4, quantidade);

  int array5[] = {2, 3, 6, 7};
  quantidade = sizeof(array5) / sizeof(int);
  instanciarVertice(vertice, array5, 5, quantidade);
  
  int array6[] = {5, 7};
  quantidade = sizeof(array6) / sizeof(int);
  instanciarVertice(vertice, array6, 6, quantidade);

  int array7[] = {5, 6, 3, 8, 12};
  quantidade = sizeof(array7) / sizeof(int);
  instanciarVertice(vertice, array7, 7, quantidade);

  int array8[] = {3, 7, 4, 11, 10};
  quantidade = sizeof(array8) / sizeof(int);
  instanciarVertice(vertice, array8, 8, quantidade);

  int array9[] = {4, 10};
  quantidade = sizeof(array9) / sizeof(int);
  instanciarVertice(vertice, array9, 9, quantidade);

  int array10[] = {8, 9, 11, 14, 15, 16};
  quantidade = sizeof(array10) / sizeof(int);
  instanciarVertice(vertice, array10, 10, quantidade);
  
  int array11[] = {8, 10, 12, 13, 14};
  quantidade = sizeof(array11) / sizeof(int);
  instanciarVertice(vertice, array11, 11, quantidade);

  int array12[] = {7, 13, 11};
  quantidade = sizeof(array12) / sizeof(int);
  instanciarVertice(vertice, array12, 12, quantidade);
  
  int array13[] = {12, 14};
  quantidade = sizeof(array13) / sizeof(int);
  instanciarVertice(vertice, array13, 13, quantidade);

  int array14[] = {11, 13, 15};
  quantidade = sizeof(array14) / sizeof(int);
  instanciarVertice(vertice, array14, 14, quantidade);

  int array15[] = {14, 10, 16};
  quantidade = sizeof(array15) / sizeof(int);
  instanciarVertice(vertice, array15, 15, quantidade);

  int array16[] = {10, 15};
  quantidade = sizeof(array16) / sizeof(int);
  instanciarVertice(vertice, array16, 16, quantidade);


    printTodosOsVertices(vertice, n);
    printf("------------------------------------------------\n");

    NO *saida;
    int comeco = 1;
    saida = caminhos_max_d(vertice, 16, 7, 11, 2);
    printarLista(saida, comeco);
    saida = caminhos_max_d(vertice, 16, 1, 3, 3);
    printarLista(saida, comeco);
    saida = caminhos_max_d(vertice, 16, 1, 2, 3);
    printarLista(saida, comeco);
    saida = caminhos_max_d(vertice, 16, 1, 7, 3);
    printarLista(saida, comeco);
    saida = caminhos_max_d(vertice, 16, 3, 10, 4);
    printarLista(saida, comeco);
    saida = caminhos_max_d(vertice, 16, 1, 16, 5);
    printarLista(saida, comeco);
    //saida = caminhos_max_d(vertice, 16, 1, 14, 14);
    printarLista(saida, comeco);
    saida = caminhos_max_d(vertice, 16, 7, 11, 1);
    printarLista(saida, comeco);

    return 0;
}
