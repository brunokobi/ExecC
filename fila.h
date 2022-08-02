#ifndef __FILA_H_
#define __FILA_H_

/***

    DEFINICAO DAS ESTRUTURAS DO TAD

    A nossa estrutura fila, vai ser composta por uma estrutura "cabe�alho" que cont�m dois ponteiros
    que v�o apontar para os elementos que est�o na primeira e na �ltima posi��o da fila. Esta estrutura
    cabe�alho se chama Fila.

    Os elementos da fila, ou seja, os dados em si, ser�o armazenados em outra estrutura, que representa
    os n�s da fila. Esta outra estrutura se chama NoFila e � composta de um campo valor, que vai guardar
    o valor do elemento e um ponteiro para o pr�ximo n� da fila

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
