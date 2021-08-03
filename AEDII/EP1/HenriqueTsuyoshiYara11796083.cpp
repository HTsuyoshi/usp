//--------------------------------------------------------------
// NOME : Henrique Tsuyoshi Yara
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
