#ifndef Listase_H
#define Listase_H

#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct{
    int cod;
    float peso;
} Dado;

struct Nodo{
    Dado info;
    Nodo *prox;
};

typedef struct{
    Nodo *topo;
} Pilha;


void criaPilha(Pilha *pl);

#endif


