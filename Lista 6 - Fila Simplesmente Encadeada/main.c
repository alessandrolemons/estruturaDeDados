#include <stdio.h>
#include <stdlib.h>
#include "header.h"

main(){
	
	Fila fila;
	Dado d;
	int op;
	
	criaFila(&fila);
	
	do{
		printf("0-Fim\n");
		printf("1-Insere\n");
		printf("2-Retira\n");		
		printf("3-Quantidade de nodos\n");
		printf("4-Exibe situacao da fila\n");
		printf("5-Consulta frente\n");
			
		printf("Informe a operacao: \n");
		scanf("%d",&op);

		switch (op){
			
			case 1:
				printf("Digite o codigo e o peso: ");
				scanf("%d %f", &d.cod, &d.peso);
				if(insere(&fila, d) == FALTOU_MEMORIA){
					printf("Faltou memoria!");
				}
				else{
					printf("Dados incluidos com sucesso!\n");
				}
				break;
				
			case 2:
				if(retira(&fila, &d) == 1){
					printf("A fila esta vazia!\n");
				}
				else{
					printf("Dado excluido %d %.2f\n", d.cod, d.peso);
				}
				break;
			
			case 3:
				printf("Quantidade de nodos: %d\n\n", quantidadeDeNodos(fila));
				break;
			
			case 4:
				if(estaVazia(fila) == 1){
					printf("A fila esta vazia!\n\n");
				}
				else{
					printf("A fila nao esta vazia!\n\n");
				}
				break;
			
			case 5:
				if(consulta(fila, &d) == 1){
					printf("A fila esta vazia!\n");
				}
				else{
					printf("%d %.2f\n", d.cod, d.peso);
				}
		}
		
		exibe(fila);
		
	} while (op != 0);	
	
	system("cls");
	printf("Programa finalizado!");
}
