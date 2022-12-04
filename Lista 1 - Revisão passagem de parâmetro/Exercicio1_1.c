#include <stdio.h>


main(){

    int Q, sexo, c = 0;
    float altura;
    float aux = 0;
    float aux2 = 0;

    printf("Digite o numero de alunos: ");
    scanf("%i", &Q);

    float alturaM[Q];

    for (int i = 0; i < Q; i++){
        printf("Digite a altura: ");
        scanf("%f", &altura);

       do{
        printf("Escolha o sexo: 1-Masculino 2-Feminino ");
        scanf("%i", &sexo);
       } while (sexo < 1 || sexo > 2);


       if(sexo == 1){
        alturaM[i] = altura;
       }else{
        if(sexo == 2){
        aux += altura;
        c++;
        }
       }

    }
    
    for (int i = 0; i < Q; i++){
        if(aux2 < alturaM[i]){
            aux2 = alturaM[i];
        }
    }
    

    printf("Aluno mais alto da turma: %.2f", aux2);
    printf("\nMedia de altura das alunas: %.2f", aux / c);

}