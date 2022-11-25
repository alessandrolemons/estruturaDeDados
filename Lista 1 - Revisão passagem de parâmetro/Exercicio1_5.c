#include <stdio.h>

void maiorNumero(){

    int N, num1, num2;

    do{
        printf("Escreva o numero de vezes que deseja verificar: ");
        scanf("%i", &N);
    } while (N < 0);
    
    for (int i = 0; i < N; i++){
        printf("\nDigite dois numeros separados por um espaco: ");
        scanf("%i %i", &num1, &num2);

            if(num1 > num2){
            printf("%i ", num1);
        }else{
            if(num2 > num1){
            printf("%i ", num2);
            }else{
                printf("Eles sao iguais");
            }
        }
    }
}


main(){

    maiorNumero();

}