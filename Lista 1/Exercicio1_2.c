#include <stdio.h>


void exibeDivisores(int num){

    for (int i = 1; i <= num; i++){
        if(num % i == 0){
            printf("%i ", i);
        }
    }

}

main(){

exibeDivisores(15);

}