#include <stdio.h>
#include <stdlib.h>
#include "listade.h"

void criaLista(ListaDE *lt){
     lt->inicio = NULL;
     lt->fim = NULL;
     lt->n = 0;
}

void exibe(ListaDE lt){
     Nodo *pAux;
     pAux = lt.inicio;
     printf("Inicio: %p \n", lt.inicio);
     printf("Fim: %p\nN = %d\n\n", lt.fim, lt.n);

     printf("[End Ant] 	  [cd] [End Nodo]      [peso] [End Prox]\n");
     while (pAux != NULL) {
           printf("%p - %3d %p %.2f - %p\n", pAux->ant, pAux->info.cod, pAux, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
}

int incluiNoInicio(ListaDE *lt, Dado d){
	system("cls");
    Nodo *pNodo;
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if (pNodo == NULL)
       return(FALTOU_MEMORIA);
    else {
       pNodo->info = d;
       pNodo->prox = lt->inicio;
       pNodo->ant = NULL;
       
       if (lt->n == 0)
          lt->fim = pNodo;
       else
          lt->inicio->ant = pNodo;  

       lt->inicio = pNodo;
       lt->n++;
       return(SUCESSO);
    }
}

int quantidadeDeNodos(ListaDE lt){
	system("cls");
	printf("Quantidade de nodos: %d\n", lt.n);
	return(SUCESSO);
}

int exibeSituacao(ListaDE lt){
	system("cls");
	if(lt.n == 0){
		return (LISTA_VAZIA);
	}
	else{
		return (SUCESSO);
	}
}
