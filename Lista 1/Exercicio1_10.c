#include <stdio.h>


void duplaClassificada(int *n1, int *n2){

    int aux;

    if((*n1 + *n2) % 2 == 0){
        
        if(n1 > n2){
            aux = *n1;
            *n1 = *n2;
            *n2 = aux;
        }else{
            aux = *n2;
            *n2 = *n1;
            *n1 = aux;
        }
        
    }else{
        if(n2 < n1){
            aux = *n1;
            *n1 = *n2;
            *n2 = aux;
        }
    }

}


main(){

    int n1, n2;

    do{
        printf("\nEscreva dois numeros separados por um espaco: ");
        scanf("%i %i", &n1, &n2);

        if (n1==n2){
            break;
        }

        int *x = &n1;
        int *y = &n2;
            
        duplaClassificada(x,y);

        printf("%i %i", n1, n2);

    }while (n1!=n2);


}