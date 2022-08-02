#ifndef __PILHA_H_
#define __PILHA_H_

/*** DEFINICAO DAS ESTRUTURAS DO TAD ***/

typedef struct no
{
	int dado;
	struct no *prox;
} No;

typedef struct pilha
{
	No *inicio;
} Pilha;

/*** DEFINICAO DOS CABECALHOS DAS FUNCOES DO TAD ***/

Pilha* novaPilha();
int pilhaVazia(Pilha*);
Pilha* push(Pilha*, int);
Pilha* pop(Pilha*);
No* topo(Pilha*);
void imprimePilha(Pilha*);

// SE HOUVER OUTRAS FUNCOES QUE SERAO IMPLEMENTADAS PELA PILHA, DECLARE AS ASSINATURAS DELAS AQUI

#endif /*__PILHA_H_*/
