#include <stdio.h>
#include <stdlib.h>
#include "listade.h"

int main(){
	
    int op, cod, peso, res;
    ListaDE lt;
    Dado d;
    
    criaLista(&lt);

    do {
      printf("\n0. Fim                         5. Exclui do Inicio                     9. Inclui Depois\n");    
      printf("1. Inclui no Inicio            6. Inclui no Fim                          10. Exclui Nodo\n");    
      printf("2. Exibe Lista                 7. Exclui do Fim                          11. Ler Arquivo\n");    
      printf("3. Quantidade de Nodos         8. Consulta por Codigo                    12. Gravar Arquivo\n");    
      printf("4. Exibe Situacao da Lista\n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
                 printf("[cd][peso]\n");
                 scanf (" %d %f", &d.cod,&d.peso);
                 if (incluiNoInicio(&lt, d) == 0){
                 	printf("Operacao Realizada com Sucesso!\n");
				 }
                 else{
                 	printf("Operacao NAO realizada: Faltou Memoria!");
				 }
                 break;
            
            case 2:
					exibe(lt);
            		break;
            case 3:
            		quantidadeDeNodos(lt);
            		break;
            
            case 4:
            		if(exibeSituacao(lt) == 1){
            			printf("A lista esta vazia!\n");
					}
					else{
						printf("A lista nao esta vazia!\n");
					}
					break;
			
			case 5:
					if(excluiDoInicio(&lt, &d) == 1){
						printf("A lista esta vazia!\n");
					}
					else{
						printf("%d %.2f foi apagado!\n", d.cod, d.peso);
					}
					break;
			
			case 6:
					printf("[cd][peso]\n");
                	scanf (" %d %f", &d.cod,&d.peso);
					if (incluiNoFim(&lt, d) == 0){
                 		printf("Operacao Realizada com Sucesso!\n");
				 	}
                 	else{
                 		printf("Operacao NAO realizada: Faltou Memoria!");
					}
					break;
					
			case 7:
					if(excluiDoFim(&lt, &d) == 1){
							printf("A lista esta vazia!\n");
					}
					else{
						printf("%d %.2f foi apagado\n", d.cod, d.peso);
					}
					break;
			
			case 8:
					printf("Digite um codigo para verificar: ");
					scanf("%d", &cod);
					if(consultaPorCodigo(lt, &d, cod) == 3){
						printf("Codigo inexistente!\n");
					}
					else{
						printf("Dado do codigo informado %.2f\n", d.peso);
					}
					break;
					
			case 9:
					printf("Digite um codigo para inserir depois: ");
					scanf("%d", &cod);
					printf("[cd][peso]\n");
                	scanf (" %d %f", &d.cod,&d.peso);	
					
					res = incluiDepois(&lt, d, cod);				
					
					if(res == 2){
						printf("Faltou memoria!\n");
					}
					else if(res == 1){
						printf("A lista esta vazia!\n");						
					}
					else if(res == 0){
						printf("Dados inseridos com sucesso!\n");												
					}
					else{
						printf("Codigo inexistente!\n");
					}
					break;
					
				case 10:
					printf("Digite o codigo do nodo para apagar: ");
					scanf("%d", &cod);
					
					res = excluiNodo(&lt, &d, cod);
					if(res == 1){
						printf("A lista esta vazia!\n");
					}
					else if(res == 3){
						printf("Codigo inexistente!\n");
					}
					else{
						printf("%d %.2f foi apagado!\n", d.cod, d.peso);
					}
					break;
					
				case 11:
					lerArquivo (&lt, d);
					break;
					
				case 12:
					gravar(&lt, d);
					break;										
      }
      
    	exibe(lt);
            
    } while (op!=0);  

  return(0);
}

