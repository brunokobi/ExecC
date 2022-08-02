#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/***
	ESTE ARQUIVO CONTEM A IMPLEMENTACAO DE TODAS AS FUNCOES LISTADAS NO ARQUIVO "pilha.h".

	A TIPO DE RETORNO E A LISTA DE PARAMETROS DAS FUNCOES DEVE OBEDECER AS ASSINATURAS
	DESSAS FUNCOES QUE ESTA NO ARQUIVO "piha.h".

	SE FOR IMPLEMENTAR UMA NOVA FUNCAO, COLOQUE A ASSINATURA DELA NO "pilha.h" E DEPOIS
	A IMPLEMENTE NESTE ARQUIVO

	ESTE ARQUIVO DEVE CONTER APENAS AS FUNCOES USADAS PARA A MANIPULACAO DO TAD PILHA E
	ELE NAO CONTEM A FUNCAO "main()".
***/

Pilha* novaPilha()
{
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->inicio = NULL;
	return p;
}

int pilhaVazia(Pilha* p)
{
	if(p->inicio == NULL)
		return 1;
	else return 0;
}

Pilha* push(Pilha* p, int elem)
{
	// Cria uma nova caixinha para armazenar o novo valor
	No *novo = (No*)malloc(sizeof(No));
	// Preenche os campos da caixinha
	novo->dado = elem;				// Atribui o valor
	novo->prox = p->inicio;			// Liga a nova caixinha ao antigo topo
	p->inicio = novo;				// Atualiza o topo da pilha

	// Retorna a nova caixinha que será o atual topo
	return p;
}

Pilha* pop(Pilha* p)
{
	// Verifica se a pilha está vazia
	if(pilhaVazia(p))
		return NULL;

	// Caso a pilha não esteja vazia, cria um auxiliar
	No *aux = p->inicio->prox;
	// Apaga o topo da pilha
	free(p->inicio);
	// Faz o ponteiro do topo da pilha apontar para o elemento que está abaixo dele
	p->inicio = aux;

	// Retorna p, que será o novo topo
	return p;
}

No* topo(Pilha* p)
{
	if(pilhaVazia(p))
		return NULL;
	else 
		return p->inicio;
}

void imprimePilha(Pilha *p)
{
	No *aux = p->inicio;

	while(aux != NULL)
	{
		printf("%d -> ", aux->dado);
		aux = aux->prox;
	}
}
