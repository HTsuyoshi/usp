#include <stdio.h>

#define MAX 100

struct info_aluno {
    char nrousp[10];
    char nome[20];
    char idade[2];
};

int main () {
    FILE *arquivo;

    int r1 = 1;
    int r2 = 4;
    info_aluno reg;
    info_aluno reg1;

    if((arquivo=fopen("trocar.txt", "r+"))==NULL)
	printf("Arquivo nao encontrado\n");
    else {

	fseek(arquivo, sizeof(info_aluno)*r1, SEEK_SET);
	fread (reg.nrousp, sizeof(reg.nrousp), 1, arquivo);
	fread (reg.nome, sizeof(reg.nome), 1, arquivo);
	fread (reg.idade, sizeof(reg.idade), 1, arquivo);

	fseek(arquivo, sizeof(info_aluno)*r2, SEEK_SET);
	fread (reg1.nrousp, sizeof(reg.nrousp), 1, arquivo);
	fread (reg1.nome, sizeof(reg.nome), 1, arquivo);
	fread (reg1.idade, sizeof(reg.idade), 1, arquivo);

	rewind(arquivo);

	fseek(arquivo, sizeof(info_aluno)*r1, SEEK_SET);
	fwrite(reg1.nrousp, sizeof(reg.nrousp), 1, arquivo);
    	fwrite(reg1.nome, sizeof(reg.nome), 1, arquivo);
    	fwrite(reg1.idade, sizeof(reg.idade), 1, arquivo);

	fseek(arquivo, sizeof(info_aluno)*r2, SEEK_SET);
	fwrite(reg.nrousp, sizeof(reg.nrousp), 1, arquivo);
    	fwrite(reg.nome, sizeof(reg.nome), 1, arquivo);
    	fwrite(reg.idade, sizeof(reg.idade), 1, arquivo);
    }
    fclose (arquivo);
    return 0;
}
