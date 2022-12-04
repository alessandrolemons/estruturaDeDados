#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void criaFila(Fila *fila){
	fila->frente = NULL;
	fila->re = NULL;
}

void exibe(Fila fila){
	Nodo *pAux;

	pAux = fila.frente;
	printf("FILA:");
	
	while(pAux != NULL){
		printf(" %d %.2f ", pAux->info.cod, pAux->info.peso);
		pAux = pAux->prox;
	}
	printf("\n\n");	
}

int insere(Fila *fila, Dado d){
	system("cls");
	Nodo *pNodo = (float *) malloc(sizeof(Nodo));
	
	if(pNodo == NULL){
		return (FALTOU_MEMORIA);
	}
	else{
		pNodo->info = d;
		pNodo->prox = NULL;
		
		if(fila->frente == NULL){
			fila->frente = pNodo;
		}
		else{
			fila->re->prox = pNodo;
		}
		fila->re = pNodo;

		return (SUCESSO);
	}
}

int retira(Fila *fila, Dado *d){
	system("cls");
	Nodo *pTemp;
	
	if(fila->frente == NULL){
		return (FILA_VAZIA);
	}
	else{
		pTemp = fila->frente;
		*d = pTemp->info;
		
		if(fila->frente->prox == NULL){
			fila->frente = NULL;
		}
		else{
			fila->frente = fila->frente->prox;
		}
			free(pTemp);
		
		return (SUCESSO);
	}
}

int quantidadeDeNodos(Fila fila){
	system("cls");
	int qtd = 0;
	Nodo *pAux = fila.frente;
	
		while(pAux != NULL){
			pAux = pAux->prox;
			qtd++;
		}
		return (qtd);
}	

int estaVazia(Fila fila){
	system("cls");
	if(fila.frente == NULL){
		return (FILA_VAZIA);
	}
	else{
		return (SUCESSO);
	}
}

int consulta(Fila fila, Dado *d){
	system("cls");
	Nodo *pAux = fila.frente;
	if(fila.frente == NULL){
		return (FILA_VAZIA);
	}
	else{
		*d = pAux->info;
	}
}


