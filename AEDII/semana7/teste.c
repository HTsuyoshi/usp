#include<stdio.h>
struct  alunos {
   int matric;
   char nome[10];
   int idade;
  };
int main()
{
   FILE *farq;
   struct alunos al, alun[4] = {1, "Maria", 20, 2, "Ana", 19, 3, "Carlos", 16, 4, "Celso",19};

   farq = fopen("arqtexto.txt", "wb");
   fwrite(alun, sizeof(struct alunos), 4, farq); // grava o array de registros alunos
   fclose(farq);
   farq = fopen("arqtexto.txt", "rb");
   fseek(farq, 3*sizeof(struct alunos), SEEK_SET); // posiciona a leitura no quarto registro
   fread(&al, sizeof(struct alunos), 1, farq); // lê o quarto registro de aluno
   printf("\n\n%d\n%s\n%d", al.matric, al.nome, al.idade);
   fclose(farq);
}
