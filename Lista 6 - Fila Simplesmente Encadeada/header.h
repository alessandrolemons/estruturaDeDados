#ifndef header_h

#define header_h

#define SUCESSO 0
#define FILA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct {
	int cod;
	float peso;
} Dado;
        
typedef struct nodo Nodo;

struct nodo {
    Dado info;
    Nodo *prox;
};

typedef struct {
    Nodo *frente;
    Nodo *re;
} Fila;


void criaFila(Fila *fila);
void exibe(Fila fila);
int insere(Fila *fila, Dado d);
int retira(Fila *fila, Dado *d);
int quantidadeDeNodos(Fila fila);
int estaVazia(Fila fila);
int consulta(Fila fila, Dado *d);

#endif
