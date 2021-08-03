#include <stdio.h>

#define MAX 50

struct registro_aluno 
{
    char nrousp[10];
    char nome[20];
    int idade;
};

void escrever (struct registro_aluno vetor_alunos[], int proximo, FILE *arq)
{
    fprintf (arq, "\n--------------------------------------\n");
    fprintf (arq, "Ha %d alunos cadastrados.\n", proximo);
    for (int i = 0; i < proximo; i++) {
	fprintf (arq, "\n%7s ", vetor_alunos[i].nrousp);
	fprintf (arq, "%20s ", vetor_alunos[i].nome);
	fprintf (arq, "%d", vetor_alunos[i].idade);
    }
    fprintf (arq, "\n--------------------------------------\n");
}

int main () 
{
    int i = 0;
    FILE *arq;
    int proximo = 1;

    struct registro_aluno vetor_alunos [MAX];

    if ( !(arq=fopen ("alunos.txt", "r")))
	printf ("Arquivo nao encontrado\n");
    else {
	do {
	    fscanf(arq, "%[^/]%*c", vetor_alunos[i].nrousp);
	    fscanf (arq, "%[^/]%*c", vetor_alunos[i].nome);
	    proximo = fscanf (arq, "%d", &vetor_alunos[i].idade);
	    fflush (arq);
	    if (proximo >= 1) i++;
	} while (proximo >= 1);
	fclose (arq);
    }

    arq = fopen ("saida.txt", "w");
    escrever (vetor_alunos, i, arq);
    
    fclose (arq);
    return 0;
}
