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
    int v1;
    int v2;
    int custo;
} REGISTRO;

void adicionarNO (NO* *inicio, NO* novo)
{
    NO* aux = (*inicio);
    if (aux) {
	while (aux->prox)
	    aux = aux->prox;
	aux->prox = novo;
    } else
	(*inicio) = novo;
}

NO* criarNO () {
    NO* novo = (NO*) malloc (sizeof (NO));
    novo->prox = NULL;
    novo->v1 = 0;
    novo->v2 = 0;
    novo->custo = 0;
    return novo;
}

int main () 
{
    FILE *arq;

    arq = fopen ("entrada.txt", "wb");
    REGISTRO alun[4] = {1123, 2, 19, 123, 34, 34, 1, 2, 3, 12, 32, 43};
    fwrite(alun, sizeof(REGISTRO), 4, arq);
    fclose(arq);

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

    while (inicio) {
	printf ("v1: %d ", inicio->v1);
	printf ("v2: %d ", inicio->v2);
	printf ("custo: %d\n", inicio->custo);
	if (inicio->prox)
	    inicio = inicio->prox;
	else
	    break;
    }

    fclose (arq);
    return 0;
}
