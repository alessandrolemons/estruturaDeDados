#include <stdio.h>
#include <stdlib.h>
#include "pilhaSE.h"

void criaPilha(Pilha *pl){
    pl->topo = NULL;
}

void exibe(Pilha pl){
    Nodo *pAux;
    
    pAux = pl.topo;
	printf("PILHA: ");
    while(pAux != NULL){
     	printf(" %d %.2f ", pAux->info.cod, pAux->info.peso);
        pAux = pAux->prox;
    }
    printf("\n\n");
}

int empilha(Pilha *pl, Dado d){
		system("cls");
        Nodo *pNodo;

        pNodo = (Nodo *) malloc (sizeof (Nodo));
        
        if(pNodo == NULL){ 
            return (FALTOU_MEMORIA);
        }
        else{
        	pNodo->info = d;
        	pNodo->prox = pl->topo;
        	pl->topo = pNodo;
            return(SUCESSO);
		}
}

int desempilha(Pilha *pl, Dado *d){
	system("cls");

	Nodo *pAux;
	
	if(pl->topo == NULL){
		return (PILHA_VAZIA);
	}
	else{
		if(pl->topo->prox == NULL){
			printf("Pilha excluida com sucesso!\n");
		}
		pAux = pl->topo;
		*d = pAux->info;
		pl->topo = pAux->prox;
		free(pAux);
		return(SUCESSO);
	}
}

int estaVazia(Pilha pl){
	system("cls");
	if(pl.topo == NULL){
		return (PILHA_VAZIA);
	}
	else{
		return (SUCESSO);
	}
}

int consultaTopo(Pilha pl, Dado *d){
	system("cls");
	Nodo *pAux;
	if(pl.topo == NULL){
		return (PILHA_VAZIA);
	}
	else{
		pAux = pl.topo;
		*d = pAux->info;
		return (SUCESSO);
	}
}

int quantidadeDeNodos(Pilha pl){
	system("cls");
	int qtd = 0;
	Nodo *pAux = pl.topo;
	
		while(pAux != NULL){
			pAux = pAux->prox;
			qtd++;
		}
		return (qtd);
}	

