#include <stdio.h>

    struct Horario{
        float hora, minuto, segundo;
    };
    

main(){

    struct Horario hr, aux;


    printf("Digite a hora: ");
    scanf("%f", &hr.hora);

    printf("Digite os minutos: ");
    scanf("%f", &hr.minuto);

    printf("Digite os segundos: ");
    scanf("%f", &hr.segundo);

    printf("--------------\n");


    struct Horario hr2;


    printf("Digite a hora: ");
    scanf("%f", &hr2.hora);

    printf("Digite os minutos: ");
    scanf("%f", &hr2.minuto);

    printf("Digite os segundos: ");
    scanf("%f", &hr2.segundo);


    if(hr.hora < hr2.hora){
        aux = hr;
    }else{
        aux = hr2;
    }


    if(hr.hora == hr2.hora){
        if(hr.minuto < hr2.minuto){
            aux = hr;
        }
    }


    if(hr.hora == hr2.hora && hr.minuto == hr2.minuto){
        if(hr.segundo < hr2.segundo){
            aux = hr;
        }
    }


    if(hr.hora == hr2.hora && hr.minuto == hr2.minuto && hr.segundo == hr2.segundo){
        printf("Horas iguais");  
    }else{
        printf("\%.0f:%.0f:%.0f ", aux.hora, aux.minuto, aux.segundo);
    }

}