#include <stdio.h>

#define MAX 50

struct registro_aluno 
{
    char nrousp[10];
    char nome[20];
    char idade[2];
};

void ler (FILE *arq, registro_aluno *registro) 
{
    fread (registro->nrousp, sizeof (registro->nrousp), 1, arq);
    fread (registro->nome, sizeof (registro->nome), 1, arq);
    fread (registro->idade, sizeof (registro->idade), 1, arq);
}

void escrever (FILE *arq, registro_aluno *registro) 
{
    fwrite (registro->nrousp, sizeof (registro->nrousp), 1, arq);
    fwrite (registro->nome, sizeof (registro->nome), 1, arq);
    fwrite (registro->idade, sizeof (registro->idade), 1, arq);
}

int main () 
{
    FILE *arq;
    int i = 0;

    char nome[50];

    printf ("Coloque o nome do arquivo: ", nome);
    scanf ("%s", nome);

    if ( !(arq=fopen (nome, "r")))
        printf ("Arquivo nao encontrado\n");
    else {
	registro_aluno registro1;
    	registro_aluno registro2;
	registro_aluno auxiliar;
	int endereco_registro1;
	int endereco_registro2;
	printf ("Coloque os dois enderecos: ");
    	fflush (stdin);
	scanf ("%d %d", &endereco_registro1, &endereco_registro2);
	fseek (arq, sizeof (registro_aluno) * endereco_registro1, SEEK_SET);
	ler(arq, &registro1);
	fseek (arq, sizeof (registro_aluno) * endereco_registro2, SEEK_SET);
	ler (arq, &registro2);

	FILE *saida=fopen("saida.txt", "w");
	rewind(saida);
	fseek (arq, 0, SEEK_SET);
	while (1==fread (&auxiliar, sizeof (registro_aluno), 1, arq)) { 
	    if (i == endereco_registro2 )
		escrever (saida, &registro1);
	    else if (i == endereco_registro1)
		escrever (saida, &registro2);
	    else 
		escrever (saida, &auxiliar);

	    i++;
	}
    }
    
    fclose (arq);
    return 0;
}
