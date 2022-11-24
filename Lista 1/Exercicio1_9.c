#include <stdio.h>


void duplaClassificada(int *n1, int *n2, int ordem){

    int aux;

    if(ordem == 0){
        if(*n1 > *n2){
            aux = *n1;
            *n1 = *n2;
            *n2 = aux;
        }
    }else{
        if(*n1 < *n2){
            aux = *n1;
            *n1 = *n2;
            *n2 = aux;
        }
    }
}

main(){

    int n1, n2, ordem;

        printf("Escolha a ordem dos numeros: 0 - Crescente | 1 - Decrescente ");
        scanf("%i", &ordem);

        printf("\nEscreva dois numeros separados por um espaco: ");
        scanf("%i %i", &n1, &n2);

    int *x = &n1;
    int *y = &n2;
    

    duplaClassificada(x, y, ordem);
        
    printf("%i %i", n1, n2);

}