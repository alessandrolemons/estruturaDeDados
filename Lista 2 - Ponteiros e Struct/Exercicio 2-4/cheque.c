#include <stdio.h>
#include "cheque.h"

void criaCheque(int num, Cheque *p){
    
    p->num = num;
    p->valor = 0;
    p->situacao = 0;

}


void obtemSituacao(Cheque *p){
	
	printf("\nSituacao do cheque: %d", p->situacao);
	
}

void obtemNumero(Cheque *p){
	
	printf("\nNumero do cheque: %d", p->num);
	
}

void exibeCheque(Cheque *p){
	
	printf("\nNumero: %d \nValor: %.2f \nSituacao: %d ", p->num, p->valor, p->situacao);
	
}

float obtemValor(Cheque *p){
	
	return p->valor;
	
}

int compensaCheque(Cheque *p){
	
	if(p->situacao == 1){
		p->situacao = 2;
	}
	
}

void emiteCheque(float valor, Cheque *p){
	
	if(p->situacao == 0){
		p->valor = valor;
		p->situacao = 1;
		return 0;
	}else{
		return 1;
	}
	
}



