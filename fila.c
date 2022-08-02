#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/***

	ESTE ARQUIVO CONTEM A IMPLEMENTACAO DE TODAS AS FUNCOES LISTADAS NO ARQUIVO "fila.h".

	A TIPO DE RETORNO E A LISTA DE PARAMETROS DAS FUNCOES DEVE OBEDECER AS ASSINATURAS
	DESSAS FUNCOES QUE ESTA NO ARQUIVO "fila.h".

	SE FOR IMPLEMENTAR UMA NOVA FUNCAO, COLOQUE A ASSINATURA DELA NO "fila.h" E DEPOIS
	A IMPLEMENTE NESTE ARQUIVO

	ESTE ARQUIVO DEVE CONTER APENAS AS FUNCOES USADAS PARA A MANIPULACAO DO TAD PILHA E
	ELE NAO CONTEM A FUNCAO "main()".

***/

/**
FUN��O: novaFila
DESCRI��O: Fun��o que cria uma nova fila para armazenar os elementos. Esta fun��o j� vai
        alocar espa�o para a estrutura cabe�alho da fila (Fila) e inicializar os campos
        desta estrutura, os ponteiros que apontam para o primeiro e �ltimo elementos da
        fila.
ENTRADA:
SA�DA: Fila* - que � a refer�ncia da estrutura cabe�alho.
**/
Fila* novaFila()
{
    // Aloca dinamicamente um espa�o para a estrutura cabe�alho. Para realizar a aloca��o
    // din�mica de mem�ria, usa-se a fun��o malloc(). Esta fun��o, conforme foi implementada,
    // retorna um ponteiro para void (void*). � feita uma convers�o expl�cita deste ponteiro
    // para void, para um ponteiro para um Fila (Fila*).
    Fila* f = (Fila*)malloc(sizeof(Fila));

    // inicializando os campos da estrutura. Neste caso, como a fila inicialmente n�o possui
    // elementos, os campos da estrutura s�o incializados com NULL.
    f->prim = f->ult = NULL;

    // retornando a estrutura cabe�alho.
	return f;
}

/**
FUN��O: filaVazia
DESCRI��O: Fun��o que verifica se uma fila est� vazia. A fila est� vazia quando ela n�o
        possui elementos, ou seja, quando um dos ponteiros da estrutura cabe�alho est�
        apontando para NULL.
ENTRADA: Fila* - a refer�ncia para uma fila.
SA�DA: int - representando ou o valor l�gico VERDADEIRO (1), ou o valor l�gico FALSO (0).
**/
int filaVazia(Fila* f)
{
	if(f->prim == NULL)
		return 1;
	else return 0;
}

/**
FUN��O: push
DESCRI��O: Fun��o que insere um novo elemento em uma fila. A fun��o cria um elemento do
        tipo n� fila e insere este elemento na �ltima posi��o da fila.
ENTRADA: Fila* - a refer�ncia para uma fila.
         elem - o valor do elemento a ser inserido
SA�DA: Fila* - a refer�ncia para a fila com o  novo elemento inserido.
**/
Fila* push(Fila* f, int elem)
{
	// Cria uma nova caixinha para armazenar o novo elemento. Este elemento � do tipo
	// n� fila. Portanto, ao usar o malloc para criar dinamicamente este novo elemento
	// devemos converter o retorno da fun��o malloc para o tipo NoFila.
	NoFila *novo = (NoFila*)malloc(sizeof(NoFila));
	// Preenche os campos da caixinha
	novo->valor = elem;		// Atribui o valor
	novo->prox = NULL;		// O pr�ximo na nova caixinha recebe NULL

    // Verifica se a fila est� vazia.
    if(filaVazia(f))
    {
        // Caso esteja, o novo elemento a ser inserido, ser� tanto o primeiro quanto
        // o �ltimo elemento da fila. Logo temos que apontar os dois ponteiros do
        // cabe�alho (prim e ult) para este elemento.
        f->prim = f->ult = novo;
    }
    // Caso a fila n�o esteja vazia, o novo elemento deve ser inserido no final da fila.
    else
    {
        // f->ult referencia o �ltimo elemento do tipo NoFila, ou seja, o �ltimo elemento
        // da fila. O �ltimo elemento da fila deixar� de ser o �ltimo, dado que um novo
        // elemento est� sendo inserido. Portanto, devemos fazer o campo prox do �ltimo
        // elemento apontar para o novo.
        f->ult->prox = novo;

        // Atualiza na estrutura cabe�alho quem � o �ltimo elemento da fila. O �ltimo
        // elemento � o novo que acabou de ser inserido.
        f->ult = novo;
    }

	// Retorna a estrutura cabe�alho da fila
	return f;
}

/**
FUN��O: pop
DESCRI��O: Fun��o que remove o primeiro elemento da fila. A fun��o certifica que a fila
        n�o est� vazia para remover o primeiro elemento.
ENTRADA: Fila* - a refer�ncia para uma fila.
SA�DA: Fila* - a refer�ncia para a fila com o primeiro elemento removido, se houver pelo
        menos um elemento na fila. Caso contr�rio o retorno ser� NULL.
**/
Fila* pop(Fila* f)
{
	// Verifica se a fila est� vazia
	if(filaVazia(f))
	{
	    // Retorna NULL para sinalizar que a fila esta vazia
	    return NULL;
	}


	// Caso a fila n�o esteja vazia, cria um ponteiro auxiliar para apontar para o elemento
	// a ser removido, ou seja, o primeiro elemento da fila. Este ponteiro, como vai apontar
	// para um elemento da fila e n�o para a estrutura cabe�alho, deve ser do tipo NoFila
	NoFila *aux = f->prim;

	// Como o primeiro elemento da fila ser� removido, o novo primeiro elemento � o atual
	// segundo elemento. Logo, temos que atualizar o ponteiro prim da estrutura cabe�alho
	// para apontar para o segundo elemento, e assim n�o perder a refer�ncia dos elementos
	// da fila
	f->prim = aux->prox;    // Este comando tamb�m pode ser escrito desta forma: f->prim = f->prim->prox;

	// Agora que atualizamos todos os ponteiros necess�rios da nossa fila, podemos apagar
	// o primeiro elemento, ou seja, chamar a fun��o free passando como par�metro o aux
	free(aux);

	// Retorna a estrutura cabe�alho f, que agora est� sem o primeiro elemento
	return f;
}

/**
FUN��O: primeiro
DESCRI��O: Fun��o que retorna a refer�ncia do primeiro elemento da fila. O primeiro elemento
        da fila � um elemento do tipo NoFila.
ENTRADA: Fila* - a refer�ncia para uma fila.
SA�DA: NoFila* - a refer�ncia para o primeiro elemento da fila.
**/
NoFila* primeiro(Fila* f)
{
	return f->prim;
}

/**
FUN��O: imprimeFila
DESCRI��O: Fun��o que exibe na tela todos os elementos existentes na fila.
ENTRADA: Fila* - a refer�ncia para uma fila.
SA�DA: void - como a fun��o exibe os elementos e para isso ela n�o altera em nada a fila,
        a fun��o retorna void.
**/
void imprimeFila(Fila *f)
{
    // Todos os elementos a serem exibidos na tela s�o do tipo NoFila.
	NoFila *aux = f->prim;

    // Enquanto houver elemento na fila, ou seja, enquanto o ponteiro que percorre todos
    // os Nofila's for diferente de NULL
	while(aux != NULL)
	{
	    // Exibe o dado preenchido no campo valor
		printf("%d -> ", aux->valor);
		aux = aux->prox;
	}
}
