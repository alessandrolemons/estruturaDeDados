#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

int main()
{
    int op,cd,peso, x = 0;
    ListaSE lt;
    Dado d;
    
    criaLista(&lt);

    do{
      printf("\n0. Fim                         5. Exclui do Inicio         10. Exclui Nodo\n");    
      printf("1. Inclui no Inicio            6. Inclui no Fim            \n");    
      printf("2. Exibe Lista                 7. Exclui do Fim            \n");    
      printf("3. Quantidade de Nodos         8. Consulta por Codigo      \n");    
      printf("4. Exibe Situacao da Lista     9. Inclui Depois.           \n");
      printf("\nOperacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
                 printf("[cd][peso]\n");
                 scanf (" %d %f", &d.cod,&d.peso);
                 if (incluiNoInicio(&lt, d) == 0)
                    printf("Operacao Realizada com Sucesso!\n");
                 else
                    printf("Operacao NAO realizada: Faltou Memoria!");
                 break;
                 
            case 3:
            	 system("cls");
                 printf("Quantidade de Nodos = %d\n", quantidadeDeNodos(lt));
                 break;
                 
            case 4:
            	if(exibeSituacao(lt) == 1){
            		printf("A lista esta vazia!");
				}
				else{
					printf("A lista possui 1 ou mais nodos!");
				}
            	 break;
            	 
            case 5:
            	if(excluiDoInicio(&lt, &d) == 1){
            		printf("A lista esta vazia!");
				}
				else{
					printf("Operacao Realizada com Sucesso!\n");
					printf("\n%d %.2f foi apagado!\n", d.cod, d.peso);
				}
				break;
			
			case 6:
					printf("[cd][peso]\n");
                 	scanf (" %d %f", &d.cod,&d.peso);
                 	
					if(incluiNoFim(&lt, d) == 2){
						printf("Faltou Memoria!");
					}
					else{
                    	printf("Operacao Realizada com Sucesso!\n");
					}
					break;
			
			case 7: 
					if(excluiDoFim(&lt, &d) == 1){
						printf("A lista esta vazia!");
					}
					else{
						printf("Operacao Realizada com Sucesso!\n");
						printf("\n%d %.2f foi apagado!\n", d.cod, d.peso);
					}
					break;
			
			case 8:
					printf("Digite um codigo: ");
					scanf("%d", &cd);
					x = consultaPorCodigo(lt, cd, &d);
					if(x == 1){
						printf("\nA lista esta vazia!\n");
					}
					else if(x == 3){
						printf("\nCodigo nao encontrado!\n");
					}
					else{
						printf("\nDado armazenado no codigo informado: %f\n", d.peso);
					}
					break;
					
			case 9:
					printf("[cd][novo cd][peso]\n");
                 	scanf ("%d %d %f", &cd, &d.cod,&d.peso);
                 	x = incluiDepois(&lt, cd, d);
                 	if(x == 2){
						printf("Faltou Memoria!");
					}
					else if(x == 3){
						printf("\nCodigo nao encontrado!\n");
					}
					else{
						printf("Operacao Realizada com Sucesso!\n");
					}

					break;
					
			case 10:
					printf("Digite um codigo: ");
					scanf("%d", &cd);
					if(excluiNodo(&lt, cd, &d) == 1){
						printf("\nA lista esta vazia!\n");
					}
					else if (excluiNodo(&lt, cd, &d) == 3){
						printf("\nCodigo nao encontrado!\n");
					}
					else{
						printf("Operacao Realizada com Sucesso!\n");
						printf("\n%d %.2f foi apagado!\n", d.cod, d.peso);
					}
      }
      exibe(lt);            
    } while (op!=0); 

  return(0);
}


