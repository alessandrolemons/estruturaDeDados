#include <stdio.h>

int maiorNumero(int num1, int num2){

    if(num1 > num2){
        return num1;
    }else{
        if(num2 > num1){
            return num2;
        }else{
            return -1;
        }
    }

}

main(){

    printf("%i ", maiorNumero(5,5));

}