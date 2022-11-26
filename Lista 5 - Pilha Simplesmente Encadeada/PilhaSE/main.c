#include <stdio.h>
#include <stdlib.h>
#include "pilhaSE.h"


main(){

    int op;
	Pilha pl;
	Dado d;

	criaPilha(&pl);

	do{
		printf("0-Fim\n");
		printf("1-Empilha\n");
		printf("2-Desempilha\n");		
		printf("3-Quantidade de nodos\n");
		printf("4-Exibe situacao da pilha\n");
		printf("5-Consulta topo\n");
			
		printf("Informe a operacao: \n");
		scanf("%d",&op);

		switch (op){
			
			case 1:
				printf("Digite o codigo e o peso: ");
				scanf("%d %f", &d.cod, &d.peso);
				empilha(&pl, d);
				break;
				
			case 2:
				if(desempilha(&pl, &d) == 1){
					printf("A pilha esta vazia!\n\n");
				}
				else{
					printf("Dado apagado: %d %.2f\n\n", d.cod, d.peso);
				}
				break;
				
			case 3:
					printf("Quantidade de nodos: %d\n\n", quantidadeDeNodos(pl));
				break;	
			
			case 4:
				if(estaVazia(pl) == 1){
					printf("A pilha esta vazia!\n\n");
				}
				else{
					printf("A pilha nao esta vazia!\n\n");
				}
				break;
				
			case 5:
				if(consultaTopo(pl, &d) == 1){
					printf("A pilha esta vazia!");
				}
				else{
					printf("Topo -> %d %.2f\n", d.cod, d.peso);
				}
				break;
		}
		
		exibe(pl);

	} while (op != 0);
	

}
