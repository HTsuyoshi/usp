#include <stdio.h>

// visualizador de arquivos
int main() {
	char c;
	char nome[20];
	FILE *arq;

	printf("Nome do arquivo: ");
	fgets(nome);
	if (nome[0]=='\0') return(0);
	if ((arq=fopen(nome,"rb"))==NULL) {
		printf("Arquivo nao encontrado...\n"); 
	}
	else {
		while (!feof(arq)) {
			c = getc(arq);
			putchar(c);
		}
	fclose(arq);
	}

	printf("\nTecle algo...\n");
	c = getc();
}
