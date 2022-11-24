/* Arquivo: mainListaCF.c */

#include <stdio.h>
#include "ListaCF.h"
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main() {
	
	ListaCF lista;
	Dado dado;
	
	FILE *stream;
	char bDados[10];
	
	int menu, num;
	
	criaLista(&lista);

	do{
		printf("0-Fim\n");
		printf("1-Inclui no fim\n");
		printf("2-Exibe lista\n");		
		printf("3-Quantidade de nodos\n");
		printf("4-Exibe situacao da lista\n");
		printf("5-Exclui do fim\n");
		printf("6-Inclui no inicio\n");
		printf("7-Exclui do inicio\n");
		printf("8-Consulta por codigo\n");	
		printf("9-Inclui antes\n");		
		printf("10-Exclui nodo\n");
		printf("11-Ler arquivo\n");
		printf("12-Gravar arquivo\n\n");
			
		printf("Informe a operacao: ");
		scanf("%d",&menu);
		
		switch (menu){
			
			case 1 : 
					printf("Informe o codigo: ");
					scanf("%d",&dado.cod);
					printf("Informe o peso: ");
					scanf("%f",&dado.peso);
					if (incluiNoFim(&lista,dado) == LISTA_CHEIA){
					 	printf("ERRO: Lista Cheia!\n");
					}	
					else{
					 	printf("Dados Incluidos com SUCESSO!\n");
					}
					break;
					 
			case 2 :
					exibe(lista);
					break;
					
			case 3 :
					printf("\nQuantidade de nodos: %i \n", quantidadeDeNodos(lista));
					break;
					
			case 4 : 
					if(estaCheia(lista) == 1){
						printf("A lista esta cheia!\n");
					}
					else if(estaVazia(lista) == 1){
						printf("A lista esta vazia!\n");
					}
					else{
						printf("A lista possui 1 ou mais nodos!\n");
					}
					break;
					
			case 5 :	
					if(excluiDoFim(&lista, &dado) == LISTA_VAZIA){
						printf("A lista esta vazia!\n");
					}
					else{
						printf("SUCESSO!\n");
						printf("%d %.2f foi excluido\n", dado.cod, dado.peso);
					}
					break;
					
			case 6: 
					printf("Informe o codigo: ");
					scanf("%d",&dado.cod);
					
					printf("Informe o peso: ");
					scanf("%f",&dado.peso);
					
					if(incluiNoInicio(&lista, dado) == SUCESSO){
					 	printf("Dados Incluidos com SUCESSO!\n");
					}
					else{
						printf("A lista esta cheia!\n");
					}
					break;
					
			case 7 :
					excluiDoInicio(&lista, &dado);
					break;
					
			case 8 :
					printf("Digite um numero:");
					scanf("%d", &num);
					
					if(consultaPorCodigo(lista, &dado, num) == SUCESSO){
						printf("SUCESSO");
					}
					else{
						printf("CODIGO INEXISTENTE");
					}
					printf("\n%.2f\n", dado.peso);
					break;
					
			case 9 :
					printf("Digite um codigo: ");
					scanf("%d", &num);
						
					printf("Informe o codigo: ");
					scanf("%d",&dado.cod);
					printf("Informe o peso: ");
					scanf("%f",&dado.peso);
					
					incluiAntes(&lista, &dado, num);
					break;
					
			case 10:                  
					printf("Digite um codigo: ");
					scanf("%d", &num);
					excluiNodo(&lista, &dado, num);
					break;
					
			case 11:
					lerArquivo (&lista, dado);
					break;
					
			case 12:
					gravar(&lista, dado);
					return 0;
		}
			
		if (menu != 2){
			exibe(lista);
		}
		
	}while(menu!= 0);
	
	return 0;
}
