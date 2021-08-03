//Henrique Tsuyoshi Yara
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>


// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("11796083");
}


// ######### ESCREVA SEU NOME AQUI
const char* nome() {
    return("Henrique Tsuyoshi Yara");
}

// elemento da pilha
typedef struct estrutura {
	struct estrutura *prox;
    int tipo; // 1=char e 2=float
    union {
        char simbolo;
        float valor;
    };
} NO;

// funcoes auxiliares

typedef struct {
 NO* topo;
} PDINAM;

// Inicialização da pilha dinâmica
void inicializarPdinam(PDINAM* p) {
 p->topo = NULL;
}

// Inserir item no topo
void pushValores(int ch, PDINAM* p) {
 NO* novo = (NO*) malloc(sizeof(NO));
 novo->tipo = 2;
 novo->valor = ch - 48;
 novo->prox = p->topo;
 p->topo = novo;
}

void pushSimbolos(int ch, PDINAM* p) {
 NO* novo = (NO*) malloc(sizeof(NO));
 novo->tipo = 1;
 novo->simbolo = ch;
 novo->prox = p->topo;
 p->topo = novo;
}

void pushResposta(float ch, PDINAM* p) {
 NO* novo = (NO*) malloc(sizeof(NO));
 novo->tipo = 2;
 novo->valor = ch;
 novo->prox = p->topo;
 p->topo = novo;
}

// Retirar a chave do topo ou -1
float pop(PDINAM* p) {
 NO* aux;
 float ch;
 if(!p->topo) return(-1);
 aux = p->topo;
 if(aux->tipo == 2) ch = aux->valor;
 else ch = aux->simbolo;
 p->topo = p->topo->prox;
 free(aux);
 return(ch);
}



// funcao principal (retorna float e int)
float calcular(char* expressao, int* codigo);


//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
float calcular(char* expressao, int* codigo){

	float resp = 0.0;
	*codigo = 999;

	// seu codigo AQUI
	PDINAM pilha;
	inicializarPdinam (&pilha);
	
	int i;
	for(i = 0; expressao[i] != '\000'; i++) {
		if(expressao[i] == ')') {
			
			float n1;
			n1 = pop(&pilha);
			
			char op;
			op = pop(&pilha);
			
			float n2;
			n2 = pop(&pilha);
			
			char ini;
			ini = pop(&pilha);
			if(ini != '(') *codigo = -1;
			
			if(op == '/' && n1 == 0.0) {
				*codigo = 0;
				break;
			}
			
			switch(op){
				
				case '*':
					n1 = n2 * n1;
					break;
				case '/':
					n1 = n2 / n1;
					break;
				case '+':
					n1 = n2 + n1;
					break;
				case '-':
					n1 = n2 - n1;
					break;
				default:
					*codigo = -1;
					
			}
			
			pushResposta(n1, &pilha);
		} else {
			if(expressao[i] >= '0' && expressao[i] <='9') pushValores(expressao[i], &pilha);
			else pushSimbolos(expressao[i], &pilha);
		}
	}
	resp = pop(&pilha);
	if(*codigo != 0 && *codigo != -1 && !pilha.topo) *codigo = 1;
	else if(*codigo != 0 && *codigo != -1 && pilha.topo) *codigo = -1;
	return resp;
}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {
}

// por favor nao inclua nenhum código abaixo da função main()
