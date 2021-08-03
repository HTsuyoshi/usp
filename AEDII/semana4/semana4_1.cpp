#include <stdio.h>
#include <string.h>

bool igual(char frase1[], char frase2[]) {
    int index1=0, tamanho = strlen(frase2);
    while(frase1[index1] != '\n') {
	while(frase1[index1] == ' ')
		index1++;
	bool equivalente = true;
	int index2=0;
	while(index2 != tamanho && equivalente) {
	    if(frase1[index1] != frase2[index2])
	        equivalente = false;
	    index1++;
	    index2++;
	}
	if(equivalente && (frase1[index1] == ' ' ||
		    frase1[index1] == '\n'))
	    return true;
	else
	    while (frase1[index1] != ' ' && 
		    frase1[index1] != '\n') 
		index1++;
    }
    return false;
}

int main() {
    // Pegar o arquivo
    printf("Coloque o nome do arquivo: ");
    char nome[50];
    scanf("%s", nome);

    // Abrir o arquivo
    FILE *entrada = fopen(nome, "r");
    if (entrada == NULL) 
	return 1;

    // Pegar o termo
    printf("Coloque o termo: ");
    char termo[50];
    scanf("%s", termo);

    // Comparar
    char frase[100];
    int tamanho = sizeof(frase);
    while(fgets(frase ,tamanho, entrada)) {
	int tamanho_frase = strlen(termo);
	bool aux = igual(frase, termo);
	if(!aux)
	    printf("nao ");
	printf("tem\n");
    }
    return 0;
}
