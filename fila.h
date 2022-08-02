#ifndef __FILA_H_
#define __FILA_H_

/***

    DEFINICAO DAS ESTRUTURAS DO TAD

    A nossa estrutura fila, vai ser composta por uma estrutura "cabeçalho" que contém dois ponteiros
    que vão apontar para os elementos que estão na primeira e na última posição da fila. Esta estrutura
    cabeçalho se chama Fila.

    Os elementos da fila, ou seja, os dados em si, serão armazenados em outra estrutura, que representa
    os nós da fila. Esta outra estrutura se chama NoFila e é composta de um campo valor, que vai guardar
    o valor do elemento e um ponteiro para o próximo nó da fila

 ***/

typedef struct noFila
{
	int valor;
	struct noFila *prox;
} NoFila;

typedef struct fila
{
    NoFila *prim;
    NoFila *ult;
} Fila;

/*** DEFINICAO DOS CABECALHOS DAS FUNCOES DO TAD ***/

Fila* novaFila();
int filaVazia(Fila*);
Fila* push(Fila*, int);
Fila* pop(Fila*);
NoFila* primeiro(Fila*);
void imprimeFila(Fila*);

// SE HOUVER OUTRAS FUNCOES QUE SERAO IMPLEMENTADAS PELA FILA, DECLARE AS ASSINATURAS DELAS AQUI

#endif /*__FILA_H_*/
