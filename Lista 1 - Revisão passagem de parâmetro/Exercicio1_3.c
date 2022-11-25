#include <stdio.h>


void exibeDivisores(){

    for (int  c = 1; c <= 20 ; c++){
        printf("%i: ", c);
        
            for (int i = 1; i <= c; i++){
            if(c % i == 0){
                printf("%i ", i);
            }
        }

        printf("\n");
    }

}

main(){

exibeDivisores();

}