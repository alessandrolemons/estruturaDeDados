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

int excluiDoInicio(ListaDE *lt, Dado *d){
	system("cls");
	Nodo *pTemp;
	if(lt->n == 0){
		return (LISTA_VAZIA);
	}
	else{
		pTemp = lt->inicio;
		*d = pTemp->info;
		if(lt->n == 1){
			lt->inicio = NULL;
			lt->fim = NULL;
		}
		else{
			lt->inicio = lt->inicio->prox;
			lt->inicio->ant = NULL;
		}
		free(pTemp); 
		lt->n--;
		return(SUCESSO);
	}
}

int incluiNoFim(ListaDE *lt, Dado d){
	system ("cls");
	Nodo *pNodo;
	
	pNodo = (Nodo *) malloc (sizeof(Nodo));
	
	if(pNodo == NULL){
		return (FALTOU_MEMORIA);
	}
	else{
			pNodo->info = d;
			
				if(lt->n == 0){
					lt->inicio = pNodo;
					lt->fim = pNodo;
					pNodo->prox = NULL;
					pNodo->ant = NULL;
					lt->n++;
					return(SUCESSO);
				}
				
				if(lt->n == 1){
					lt->inicio->prox = pNodo;
					pNodo->ant = lt->inicio;
					pNodo->prox = NULL;
					lt->fim = pNodo;
					lt->n++;
					return(SUCESSO);
				}
				
				else{
					lt->fim->prox = pNodo;
					pNodo->ant = lt->fim;
					pNodo->prox = NULL;
					lt->fim = pNodo;
					lt->n++;
					return (SUCESSO);
				}
	}
}

int excluiDoFim(ListaDE *lt, Dado *d){
	system("cls");
	Nodo *pAux;
	
	if(lt->n == 0){
		return (LISTA_VAZIA);
	}
	else{
		*d = lt->fim->info;
			if(lt->n == 1){
				pAux = lt->fim;
				lt->inicio = NULL;
				lt->fim = NULL;
			}
			else{
				pAux = lt->fim;
				lt->fim->ant->prox = NULL;
				lt->fim = lt->fim->ant;
			}
				
		free(pAux);
		lt->n--;
		return (SUCESSO);
	}
}

int consultaPorCodigo(ListaDE lt, Dado *d, int cod){
	system("cls");
	Nodo *pAux;
	
	pAux = lt.inicio;
	
	while(pAux != NULL){
			if(pAux->info.cod == cod){
				*d = pAux->info;
				return(SUCESSO);
			}
		pAux = pAux->prox;
	}
	
	return (CODIGO_INEXISTENTE);
}

int incluiDepois(ListaDE *lt, Dado d, int cod){
	system("cls");
	Nodo *pNodo, *pAux, *pProx;
	
	pNodo = (Nodo *) malloc (sizeof(Nodo));
		if(pNodo == NULL){
			return (FALTOU_MEMORIA);
		}
		else{
			if(lt->n == 0){
				return (LISTA_VAZIA);
			}
			
			pAux = lt->inicio;
			pNodo->info = d;
			
			if(lt->n == 1 && lt->inicio->info.cod == cod){
				lt->inicio->prox = pNodo;
				pNodo->prox = NULL;
				pNodo->ant = lt->inicio;
				lt->fim = pNodo;
				lt->n++;
				return (SUCESSO);
			}
			
			if(lt->n > 1 && lt->fim->info.cod == cod){
				pNodo->ant = lt->fim;
				lt->fim->prox = pNodo;
				pNodo->prox = NULL;
				lt->fim = pNodo;
				lt->n++;
				return (SUCESSO);
			}
				
			while(pAux != NULL){
					if(pAux->info.cod == cod){
						pNodo->prox = pAux->prox;
						pNodo->ant = pAux;
						pAux->prox = pNodo;
						pNodo->prox->ant = pNodo;
						lt->n++;
						return(SUCESSO);
					}
				
				pAux = pAux->prox;
			}
		}
		return (CODIGO_INEXISTENTE); 
}

int excluiNodo(ListaDE *lt, Dado *d, int cod){
	system("cls");
	Nodo *pAux, *pTemp;
	
	if(lt->n == 0){
		return (LISTA_VAZIA);
	}
	
	if(lt->n == 1 && cod == lt->inicio->info.cod){
		pTemp = lt->inicio;
		*d = pTemp->info;
		lt->inicio = NULL;
		lt->fim == NULL;
		lt->n--;
		free(pTemp);
		return (SUCESSO);
	}
	
	if(lt->inicio->info.cod == cod){
		pTemp = lt->inicio;
		*d = pTemp->info;
		lt->inicio->prox->ant = NULL;
		lt->inicio = lt->inicio->prox;
		lt->n--;
		free(pTemp);
		return (SUCESSO);
	}
	
	if(lt->fim->info.cod == cod){
		pTemp = lt->fim;
		*d = pTemp->info;
		lt->fim->ant->prox = NULL;
		lt->fim = lt->fim->ant;
		lt->n--;
		free(pTemp);
		return (SUCESSO);
	}
	
	pAux = lt->inicio;
	
	while(pAux != NULL){
			if(pAux->info.cod == cod){
				pTemp = pAux;
				*d = pTemp->info;
				pAux->ant->prox = pAux->prox;
				pAux->prox->ant = pAux->ant;
				lt->n--;
				free(pTemp);
				return (SUCESSO);
			}
		
		pAux = pAux->prox;
	}

	return(CODIGO_INEXISTENTE);

}

void lerArquivo (ListaDE *lt, Dado d){
	
	FILE *file;	
	int arqDados;
	char bDados[10];

				printf("Escolha um dos arquivos: 1 | 2 | 3: \n");
				scanf("%d", &arqDados);
				
				if(arqDados == 1){
					strcpy(bDados,"dados.txt");
				}
				else if(arqDados == 2){
					strcpy(bDados,"dados2.txt");
				}
				else if (arqDados == 3){
					strcpy(bDados,"dados3.txt");
				}

		if ((file = fopen(bDados,"r" )) == NULL){
			printf("Nao foi possivel abrir\n");
		}
		else{
			criaLista(lt);
			while(fscanf(file,"%d %f\n", &d.cod, &d.peso) != EOF){
				incluiNoFim(lt, d);	
			}
			
			fclose(file);
			printf("Importacao Realizada com Sucesso!\n");
		}
}

void gravar(ListaDE *lt, Dado d){
	
	FILE *file;	
	char nome[20];
	Nodo *pAux;
		
	printf("Digite um nome para o arquivo(Finalize com .txt): ");
	scanf("%s", &nome);	
	
	file = fopen(nome, "w");

		if(file == NULL){
			printf("Nao foi possivel gravar seus dados!\n");
		}
		else{			
			while(pAux != NULL){
				fprintf(file, "%d %f\n", pAux->info.cod, pAux->info.peso);
				printf("entrou\n");
				pAux = pAux->prox;
			}
			printf("Seu arquivo foi gravado com com sucesso!");
		}
}


