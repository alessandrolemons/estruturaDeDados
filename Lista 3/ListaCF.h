/* Arquivo: ListaCF.h */

#ifndef ListaCF_H
#define ListaCF_H

#define MAX_NODOS 5

#define SUCESSO            0
#define LISTA_VAZIA        1
#define LISTA_CHEIA        2
#define POSICAO_INVALIDA   3
#define CODIGO_INEXISTENTE 4

typedef struct{
	int cod;
	float peso;
} Dado;

typedef struct{
    int n;
	Dado v[MAX_NODOS];
} ListaCF;

/* Prototipos das funcoes */

void criaLista(ListaCF *lt);
int incluiNoFim(ListaCF *lt, Dado d);
void exibe(ListaCF lt);
int quantidadeDeNodos(ListaCF lt);
int estaCheia(ListaCF lt);
int estaVazia(ListaCF lt);
int excluiDoFim(ListaCF *lt, Dado *d);
int consultaPorCodigo(ListaCF lt, Dado *d, int num);
int incluiNoInicio(ListaCF *lt, Dado d);
void excluiDoInicio(ListaCF *lt, Dado *d);
void excluiNodo(ListaCF *lt, Dado *d, int num);
void incluiAntes(ListaCF *lt, Dado *d, int num);
void gravar (ListaCF *lt, Dado d);
void lerArquivo (ListaCF *lt, Dado d);


#endif
