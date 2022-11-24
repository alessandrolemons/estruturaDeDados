#include <stdio.h>

main(){

    int Q;

    do{
        printf("Digite o numero de elementos do vetor: ");
        scanf("%i", &Q);
    } while (Q > 10 || Q < 1);
    
    int vetorZ[Q];

    for (int i = 0; i < Q; i++){
        printf("Digite um valor para o vetor: ");
        scanf("%i", &vetorZ[i]);
    }

    int c = 0;
    int j = 0;
    int Y;
    
    printf("Digite um valor: ");
    scanf("%i", &Y);

    for (int i = 0; i < Q; i++){
        if(vetorZ[i] > Y){
            c++;
        }
    }
    
    int vetorW[c];

    for (int i = 0; i < Q; i++){
        if(vetorZ[i]>Y){
            vetorW[j] = vetorZ[i];
            j++;
        }
    }
    
    for (int i = 0; i < c; i++){
        printf("%i ", vetorW[i]);
    }
    


}