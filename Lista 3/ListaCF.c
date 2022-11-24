/* Arquivo: ListaCF.c */

#include <stdio.h>
#include "ListaCF.h"

/* S: uma lista */

void criaLista(ListaCF *lt){
	lt->n = 0;
}

/* E/S: uma lista | E: um dado | R: SUCESSO ou LISTA_CHEIA */

int incluiNoFim(ListaCF *lt, Dado d){
	if (lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	}
	else{
		lt->v[lt->n] = d;
		lt->n++;
		return SUCESSO;
	}	
}

/*  E: uma lista */
void exibe(ListaCF lt){
	int i;
	
	printf("-------------\n");
	printf("Lista:\n");
	for (i=0; i<lt.n; i++){
		printf("   %d %.2f\n", lt.v[i].cod,lt.v[i].peso);
	}
	printf("-------------\n\n");			
}

int quantidadeDeNodos(ListaCF lt){
	return lt.n;	
}

int estaCheia(ListaCF lt){
	if(lt.n == 5){
		return 1;
	}else{
		return 0;
	}
}

int estaVazia(ListaCF lt){
	if(lt.n == 0){
		return 1;
	}else{
		return 0;
	}
}

int excluiDoFim(ListaCF *lt, Dado *d){
	if(lt->n == 0){
		return LISTA_VAZIA;
	}
	else{
	*d= lt->v[lt->n-1];
	lt->n--;
	return SUCESSO;
	}
}

int consultaPorCodigo(ListaCF lt, Dado *d, int num){
	int i;
	int flag = 0;
		for(i = 0; i < lt.n; i++){
			if(num == lt.v[i].cod){
				*d = lt.v[i];
				flag = 1;
				return SUCESSO;
			}
		}
			if(flag == 1){
				return CODIGO_INEXISTENTE;
			}
}

int incluiNoInicio(ListaCF *lt, Dado d){
	int i;
	if (lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	}
	else{
		for(i = lt->n; i >= 1; i--){
			lt->v[i] = lt->v[i-1];
		}
	 	lt->v[0] = d;
		lt->n++;
		return SUCESSO;
	}
	
}

void excluiDoInicio(ListaCF *lt, Dado *d){
		int i;

		if (lt->n == 0){
			printf("A lista esta vazia!");
		}
	else{
		
		*d = lt->v[0];
			
		for(i = 0; i <= lt->n; i++){
			lt->v[i] = lt->v[i+1];
		}

		lt->n--;
		
		printf("%d  %.2f foi excluido\n", d->cod, d->peso);
	}
}

void excluiNodo(ListaCF *lt, Dado *d, int num){

	if(lt->n == 0){
		printf("A lista esta vazia!");
	}
	else{
		int aux;
		int i;
		int flag = 0;
		
		for(i = 0; i < lt->n; i++){
			if(num == lt->v[i].cod){
				*d = lt->v[i];
				aux = i;
				flag = 1;
			}
		}
		
		if(flag == 0){
			printf("Codigo nao encontrado!\n");
		}
		else{
			for(i = aux; i < lt->n; i++){
			lt->v[i] = lt->v[i+1];
		}
		
		lt->n--;
				
		printf("%d %.2f foi excluido!\n", d->cod, d->peso);
		
		}	
	}
}

void incluiAntes(ListaCF *lt, Dado *d, int num){
	
	if(lt->n == MAX_NODOS){
		printf("A lista esta cheia!");
	}
	else if(lt->n == 0){
		printf("A lista esta vazia!");
	}	
	else{
		int aux;
		int i;
		int flag = 0;

		for(i = lt->n; i >= 0; i--){
			if(num == lt->v[i].cod){
					aux = i;
					flag = 1;	
			}
		}
		
		if(flag == 0){
			printf("Codigo nao encontrado!\n");
		}
		else{
			for(i = lt->n; i > aux; i--){
				lt->v[i] = lt->v[i-1];
			}	
				
			lt->v[aux] = *d;
			lt->n++;
			
			printf("Dados Incluidos com SUCESSO!\n");
		}
	}
}
void lerArquivo (ListaCF *lt, Dado d){
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
			printf("Nao foi possivel abrir");
		}
		else{
			criaLista(lt);
			while(fscanf(file,"%d %f\n", &d.cod, &d.peso) != EOF)
			incluiNoFim(lt, d);
			fclose(file);
			printf("Importacao Realizada com Sucesso!\n");
		}
}

void gravar(ListaCF *lt, Dado d){
	
	FILE *file;	
	char nome[20];
		
	printf("Digite um nome para o arquivo(Finalize com .txt): ");
	scanf("%s", &nome);	
	
	file = fopen(nome, "w");

		if(file == NULL){
			printf("Nao foi possivel gravar seus dados!");
		}
		else{
				int i;
			for(i = 0; i < lt->n; i++){
				fprintf(file, "%d %f\n", lt->v[i].cod, lt->v[i].peso);
			}
			printf("Seu arquivo foi gravado com com sucesso!");
		}
}

