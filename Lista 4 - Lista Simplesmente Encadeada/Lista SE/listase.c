#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

void criaLista(ListaSE *lt){
     lt->inicio = NULL;
}

int incluiNoInicio(ListaSE *lt, Dado d){
	system("cls");
    Nodo *pNodo;
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if (pNodo == NULL)
       return(FALTOU_MEMORIA);
    else {
       pNodo->info = d;
       pNodo->prox = lt->inicio;
       lt->inicio = pNodo;
       return(SUCESSO);
    }
}
 
void exibe(ListaSE lt){
     Nodo *pAux;
     pAux = lt.inicio;
     printf("\nInicio: %p \n", lt.inicio);
     printf("Exibindo a Lista\n");
     printf("[EndNodo]	  [cd] [peso]	[EndProx]\n");
     while (pAux != NULL) {
           printf("%p - %3d %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
}

int quantidadeDeNodos(ListaSE lt){
    int conta = 0;
    Nodo *pAux;
    
    pAux = lt.inicio;
    while (pAux != NULL){
           conta++;
           pAux = pAux->prox;
    }
    return(conta);
}

int estaVazia(ListaSE lt){
	system("cls");
    if (lt.inicio==NULL)
       return(LISTA_VAZIA);
    else
       return(0);     
}

int exibeSituacao(ListaSE lt){
	system("cls");

	if (lt.inicio==NULL){
		return(LISTA_VAZIA);
	}
	else{
		return(SUCESSO);
	}
}

int excluiDoInicio(ListaSE *lt, Dado *d){
	system("cls");

	Nodo *pAux;
	if (lt->inicio==NULL){
		return(LISTA_VAZIA);
	}
	else{
		*d = lt->inicio->info;
		pAux = lt->inicio;
		lt->inicio = pAux->prox;
		free(pAux);
		return (SUCESSO);
	}
}

int incluiNoFim(ListaSE *lt, Dado d){
	system("cls");

    Nodo *pNodo, *pAux;
    
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    
    if (pNodo == NULL){
    	return(FALTOU_MEMORIA);
	}
    else{	
    	pAux = lt->inicio;
    	
    	if(lt->inicio == NULL){
    		lt->inicio = pNodo;
			pNodo->info = d;
			pNodo->prox = NULL;	
		}
		else{
			while (pAux != NULL) {
				if(pAux->prox == NULL){
					pAux->prox = pNodo;
					pNodo->info = d;
					pNodo->prox = NULL;
					return (SUCESSO);
				}
           	pAux = pAux->prox;
	}
			}
		}
}

int excluiDoFim(ListaSE *lt, Dado *d){
	system("cls");

	Nodo *pAux, *pTemp, *penultimo;
		pAux = lt->inicio;

	
	if (lt->inicio==NULL){
		return(LISTA_VAZIA);	
	}
	
	else if(pAux->prox == NULL){
		*d = pAux->info;
		pTemp = pAux;
		free(pTemp);
		lt->inicio = NULL;
		return (SUCESSO);
	}
	
	else{
		while(pAux != NULL){
			if(pAux->prox == NULL){
				*d = pAux->info;
				pTemp = pAux;
				penultimo->prox = NULL;
				free(pTemp);
				return (SUCESSO);
			}
			penultimo = pAux;
			pAux = pAux->prox;	
		}
	}   
}

int consultaPorCodigo(ListaSE lt, int cod, Dado *d){
	Nodo *pAux;
	system("cls");

	if(lt.inicio == NULL){
		return (LISTA_VAZIA);
	}
	else{
		pAux = lt.inicio;
		
		while(pAux != NULL){
			if(pAux->info.cod == cod){
				*d = pAux->info;
				return (SUCESSO);
			}
			pAux = pAux->prox;
		}
		return (CODIGO_INEXISTENTE);
	}
}

int incluiDepois(ListaSE *lt, int cod, Dado d){

    Nodo *pNodo, *pAux;
    
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    
    if (pNodo == NULL){
    	return(FALTOU_MEMORIA);
	}
    else{
    	pAux = lt->inicio;

		while(pAux != NULL){
			if(pAux->info.cod == cod){
				pNodo->info = d;
				pNodo->prox = pAux->prox;
				pAux->prox = pNodo;
				return (SUCESSO);
			}
			pAux = pAux->prox;
		}
		return (CODIGO_INEXISTENTE);

	}
}

int excluiNodo(ListaSE *lt, int cod, Dado *d){
	system("cls");

	Nodo *pAux, *pTemp, *penultimo;
	int flag = 0;
	
	if (lt->inicio==NULL){
		return(LISTA_VAZIA);	
	}
	else{
		pAux = lt->inicio;
		
		while(pAux != NULL){
				if(pAux->info.cod == cod){
					if(flag == 0){
						*d = pAux->info;
						pTemp = pAux;
						penultimo->prox = pAux->prox;
						lt->inicio = pAux->prox;
						free(pTemp);
						return (SUCESSO);	
						
					}
					else{
						*d = pAux->info;
						pTemp = pAux;
						penultimo->prox = pAux->prox;
						free(pTemp);
						return (SUCESSO);	
					}
				}
			flag = 1;
			penultimo = pAux;
			pAux = pAux->prox;
		}
	}
}

