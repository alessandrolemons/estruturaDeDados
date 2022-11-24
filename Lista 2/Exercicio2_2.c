#include <stdio.h>

struct Data{
    int dia, mes, ano;
};

struct Aluno{
    int matricula;
};

main(){

    struct Data dt, dtHoje;
    
    dtHoje.dia = 28;   
    dtHoje.mes = 10;
    dtHoje.ano = 2022;
    
    struct Aluno al;

do{
    printf("Digite a matricula do aluno: ");
    scanf("%i", &al.matricula);

    if(al.matricula < 0){
        break;
    }

    printf("Digite o dia de nascimento do aluno: ");
    scanf("%i", &dt.dia);
    
    printf("Digite o mes de nascimento do aluno: ");
    scanf("%i", &dt.mes);

    printf("Digite o ano de nascimento do aluno: ");
    scanf("%i", &dt.ano);

        if(dtHoje.ano - dt.ano >= 18 && dtHoje.mes >= dt.mes && dtHoje.dia >= dt.dia){
			printf("Maior de idade \n");
		}
		else if(dtHoje.ano - dt.ano > 18 && dtHoje.mes < dt.mes){
			printf("Maior de idade \n");
		}
		else if(dtHoje.ano - dt.ano >= 18 && dtHoje.mes > dt.mes){
			printf("Maior de idade \n");
		}

} while (al.matricula > 0);

}