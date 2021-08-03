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

int main () 
{
	FILE *arq;

	arq = fopen ("entrada.txt", "wb");
	REGISTRO alun[4] = {1, 2, 19, 3, 4, 34, 4, 2, 3, 2, 3, 43};
	fwrite(alun, sizeof(REGISTRO), 4, arq);
	fclose(arq);

	REGISTRO tabela_indices[100];

	arq = fopen ("entrada.txt", "rb");
	NO* inicio = NULL;
	REGISTRO auxiliar;

	int i = 0;
	while (0 != fread (&auxiliar, sizeof (REGISTRO), 1, arq)) { 
		tabela_indices[i].v1 = auxiliar.v1;
		tabela_indices[i].v2 = auxiliar.v2;
		tabela_indices[i].custo = auxiliar.custo;
		i++;
	}

	for (int j = 0; j < i; j++ ) {
		printf ("v1: %d, v2: %d e custo: %d\n", tabela_indices[j].v1, tabela_indices[j].v2, tabela_indices[j].custo);
	}

	fclose (arq);
	return 0;
}
