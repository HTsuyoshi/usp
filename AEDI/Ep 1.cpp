//Henrique Tsuyoshi Yara
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// 11796083 ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("11796083");
}


// Henrique Tsuyoshi Yara ESCREVA SEU NOME AQUI
char* nome() {
    return("Henrique Tsuyoshi Yara");
}

// elemento da lista
typedef struct estr {
        int valor;
        struct estr* prox;
} NO;

// Funcoes auxiliares

void inicializarNO (int ch, NO* p){
	p->valor = ch;
	p->prox = NULL;
}

void anexarElemNO (int ch, NO* p) {
	NO* novo;
	NO* ant;
	while(p) {
		ant = p;
		p = p->prox;
	}
	novo = (NO*) malloc(sizeof(NO));
 	novo->valor = ch;
 	novo->prox = NULL;
	if(!ant) p->prox = novo;
 	else ant->prox = novo;
}

void exibirLista (NO* p) {
	while (p) {
		printf("[%d] ", p->valor);
		p = p->prox;
	}
}

// funcao principal
NO* uniao (NO* p1, NO* p2);


//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO* uniao (NO* p1, NO* p2) {

	NO* resp;
	resp = NULL;

	// seu codigo AQUI
	
	// Caso as duas listas sejam vazias
	if(!p1 && !p2) return resp;
	
	// Inicalizar a lista resp (existe pelo menos uma lista)
	resp = (NO*) malloc(sizeof(NO));
	NO* aux = resp;
	
	// Inicializar o aux->valor caso sÛ uma lista exista
	NO* listaQueSobrou = p2;
	if(!p1 ^ !p2) {
		if(p1) listaQueSobrou = p1;
		aux->valor = listaQueSobrou->valor;
		resp->prox = NULL;
	}
	// Caso as duas listas existam, inicializar a lista resp
	if(p1 && p2)  {
		if(p1->valor > p2->valor) resp->valor = p1->valor;
		else resp->valor = p2->valor;
		resp->prox = NULL;

	// Colocar os elementos nas duas listas
		while (p1 && p2) {
			
			if(p1->valor < p2->valor){
			
				if(aux->valor != p1->valor) {
					anexarElemNO(p1->valor, resp);
					aux = aux->prox;
				}
				p1 = p1->prox;
			
			} else {
			
				if(aux->valor != p2->valor) {
					anexarElemNO(p2->valor, resp);
					aux = aux->prox;
				}
				p2 = p2->prox;
		 
			}
		
		}
	
	// Colocar a lista que tem proximos elementos
	listaQueSobrou = p2;
	if(p1) listaQueSobrou = p1;
	}
	
	while (listaQueSobrou) {
		if(aux->valor != listaQueSobrou->valor) {
			anexarElemNO(listaQueSobrou->valor, resp);
			aux = aux->prox;
		}
		listaQueSobrou = listaQueSobrou->prox;
	}
	
	return resp;
}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {

	NO* p1 = (NO*) malloc(sizeof(NO));
	NO* p2 = (NO*) malloc(sizeof(NO));

	// aqui vc pode incluir codigo para inserir elementos
	// de teste nas listas p1 e p2
	
	// Inicializando lista 1

	inicializarNO(1, p1);
	
	anexarElemNO(1, p1);
	anexarElemNO(2, p1);
	anexarElemNO(2, p1);
	anexarElemNO(6, p1);
	anexarElemNO(8, p1);
	anexarElemNO(9, p1);
	anexarElemNO(10, p1);
	anexarElemNO(10, p1);
	anexarElemNO(11, p1);
	anexarElemNO(15, p1);
	anexarElemNO(15, p1);
	anexarElemNO(15, p1);
	anexarElemNO(15, p1);
	anexarElemNO(15, p1);
	anexarElemNO(15, p1);
	anexarElemNO(15, p1);
	anexarElemNO(15, p1);
	
	// Inicializando lista 2
	
	inicializarNO(1, p2);
	
	anexarElemNO(1, p2);
	anexarElemNO(2, p2);
	anexarElemNO(4, p2);
	anexarElemNO(5, p2);
	anexarElemNO(7, p2);
	anexarElemNO(7, p2);
	anexarElemNO(15, p2);
	anexarElemNO(15, p2);
	anexarElemNO(15, p2);
	anexarElemNO(15, p2);
	anexarElemNO(20, p2);
	anexarElemNO(99, p2);
	anexarElemNO(100, p2);
	
	// o EP sera testado com chamadas deste tipo
	
	// Exibindo as listas
	printf("Lista 1:");
	exibirLista(p1);
	printf("\n");
	
	printf("Lista 2:");
	exibirLista(p2);
	printf("\n");
	
	// Teste com duas listas n„o vazias
	
	NO* teste = uniao(p1,p2);
	
	printf("Lista 1 e 2:");
	exibirLista(teste);
	printf("\n");
	
	// Teste com uma so lista e outra lista vazia
	
	NO* testeListaVazia = NULL;
	
	testeListaVazia = uniao(testeListaVazia, p2);

	printf("Lista Vazia e lista 2:");
	exibirLista(testeListaVazia);
	printf("\n");
	
	testeListaVazia = uniao(testeListaVazia, p1);

	printf("Lista Vazia e lista 1:");
	exibirLista(testeListaVazia);
	printf("\n");
	
	// Teste comduas listas vazias
	
	NO* duasListasVazias = NULL;
	
	duasListasVazias = uniao(duasListasVazias, duasListasVazias);

	printf("Duas listas vazias:");
	exibirLista(duasListasVazias);
	printf("\n");
}

// por favor nao inclua nenhum c√≥digo abaixo da fun√ß√£o main()
