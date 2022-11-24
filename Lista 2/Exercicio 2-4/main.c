#include <stdio.h>
#include "cheque.h"

main() {
	
	Cheque cheque, cheque2;
	
	int num, num2;
	
	printf("Digite o numero do cheque: ");
	scanf("%d", &num);
	
	printf("Digite o numero do segundo cheque: ");
	scanf("%d", &num2);
	
	criaCheque(num, &cheque);
	criaCheque(num2, &cheque2);
	
	float valorChequeUm, valorChequeDois;
	
	printf("Digite o valor do primeiro cheque: ");
	scanf("%f", &valorChequeUm);
	
	printf("Digite o valor do segundo cheque: ");
	scanf("%f", &valorChequeDois);
	
	emiteCheque(valorChequeUm, &cheque);
	emiteCheque(valorChequeDois, &cheque2);	
	
	exibeCheque(&cheque);
	exibeCheque(&cheque2);
	
	if(obtemValor(&cheque) > obtemValor(&cheque2)){
		compensaCheque(&cheque);
	}else{
		compensaCheque(&cheque2);
	}
	
	
	obtemSituacao(&cheque);
	obtemSituacao(&cheque2);

	obtemNumero(&cheque);
	obtemNumero(&cheque2);
	
	
	

	
}
