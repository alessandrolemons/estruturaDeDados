#include <stdio.h>


void duplaCrescente(int *n1, int *n2){

    int aux;

    if(*n1 > *n2){
        aux = *n1;
        *n1 = *n2;
        *n2 = aux;
    }

}

main(){

    int n1 = 4;
    int n2 = 2;

    int *x = &n1;
    int *y = &n2;

    duplaCrescente(x, y);

    printf("%i %i ", n1, n2);

}