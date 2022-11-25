#include <stdio.h>

typedef struct{
    int numeroConta;
    float saldoConta;
} Conta;

void criarConta(int num, Conta *p){

    p->saldoConta = 0;
    p->numeroConta = num;
}

void retiradaDaConta(Conta *p, float valor){

    p->saldoConta -= valor;
}

void depositaNaConta(Conta *p, float valor){

    p->saldoConta += valor;
}

void obtemSaldo(Conta *p){

    return p->saldoConta;
}

main(){

    int num, menu;
    float valor;

    Conta contaCorr;
    Conta contaPoup;

    printf("Digite o numero da conta: ");
    scanf("%d", &num);

    criarConta(num, &contaCorr);
    criarConta(num, &contaPoup);  

    do{  
        system("cls");
        printf("\nSaldo da Conta Corrente: %.3f \n", contaCorr.saldoConta);
        printf("Saldo da Conta Poupanca: %.3f \n\n", contaPoup.saldoConta);

        printf("1.Deposito na Conta Corrente \n");
        printf("2.Deposito na Conta Poupanca \n");
        printf("3.Saque Conta Corrente \n");
        printf("4.Saque Conta Poupanca \n");
        printf("5.Fim \n \n");

        scanf("%d", &menu);

        switch(menu){
            case 1:
            printf("Digite um valor: \n");
            scanf("%f", &valor);
            depositaNaConta(&contaCorr, valor);
            printf("%.2f \n", contaCorr.saldoConta);
            break;
            
            case 2:
            printf("Digite um valor: \n");
            scanf("%f", &valor);
            depositaNaConta(&contaPoup, valor);
            printf("%.2f \n", contaPoup.saldoConta);
            break;
            
            case 3:
            printf("Digite um valor: \n");
            scanf("%f", &valor);
             
            float aux;

            if(contaCorr.saldoConta - valor < 0){
                float saldoNeg = contaCorr.saldoConta - valor;
                 printf("Saldo da Conta Corrente: %.3f \n", contaCorr.saldoConta);
                 printf("Saldo da Conta Poupanca: %.3f \n\n", contaPoup.saldoConta);

                if(contaPoup.saldoConta >= saldoNeg * -1 ){
                    contaCorr.saldoConta += saldoNeg * -1; 
                    contaPoup.saldoConta += saldoNeg;
                    printf("Saldo da Conta Corrente: %.3f \n", contaCorr.saldoConta);
                    printf("Saldo da Conta Poupanca: %.3f \n\n", contaPoup.saldoConta);

                    retiradaDaConta(&contaCorr, valor);

                    printf("%.2f \n", contaCorr.saldoConta);
                }else{
                    printf("Saldo insuficiente! \n");
                    getch();
                }
            }else{
                    retiradaDaConta(&contaCorr, valor);
            }

            break;
            
            case 4:
            printf("Digite um valor: \n");
            scanf("%f", &valor);
            retiradaDaConta(&contaPoup, valor);
            printf("%.2f \n", contaPoup.saldoConta);
            break;
        }

    }while(menu!=5);
}