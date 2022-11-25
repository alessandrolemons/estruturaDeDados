#ifndef main_c
#define main_c

typedef struct{
    int num, situacao;
    float valor;
} Cheque;


void criaCheque(int num, Cheque *p);
void obtemSituacao(Cheque *p);
void obtemNumero(Cheque *p);
void exibeCheque(Cheque *p);
float obtemValor(Cheque *p);
int compensaCheque(Cheque *p);
void emiteCheque(float valor, Cheque *p);


#endif

