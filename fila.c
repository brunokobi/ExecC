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
FUNÇÃO: novaFila
DESCRIÇÃO: Função que cria uma nova fila para armazenar os elementos. Esta função já vai
        alocar espaço para a estrutura cabeçalho da fila (Fila) e inicializar os campos
        desta estrutura, os ponteiros que apontam para o primeiro e último elementos da
        fila.
ENTRADA:
SAÍDA: Fila* - que é a referência da estrutura cabeçalho.
**/
Fila* novaFila()
{
    // Aloca dinamicamente um espaço para a estrutura cabeçalho. Para realizar a alocação
    // dinâmica de memória, usa-se a função malloc(). Esta função, conforme foi implementada,
    // retorna um ponteiro para void (void*). É feita uma conversão explícita deste ponteiro
    // para void, para um ponteiro para um Fila (Fila*).
    Fila* f = (Fila*)malloc(sizeof(Fila));

    // inicializando os campos da estrutura. Neste caso, como a fila inicialmente não possui
    // elementos, os campos da estrutura são incializados com NULL.
    f->prim = f->ult = NULL;

    // retornando a estrutura cabeçalho.
	return f;
}

/**
FUNÇÃO: filaVazia
DESCRIÇÃO: Função que verifica se uma fila está vazia. A fila está vazia quando ela não
        possui elementos, ou seja, quando um dos ponteiros da estrutura cabeçalho está
        apontando para NULL.
ENTRADA: Fila* - a referência para uma fila.
SAÍDA: int - representando ou o valor lógico VERDADEIRO (1), ou o valor lógico FALSO (0).
**/
int filaVazia(Fila* f)
{
	if(f->prim == NULL)
		return 1;
	else return 0;
}

/**
FUNÇÃO: push
DESCRIÇÃO: Função que insere um novo elemento em uma fila. A função cria um elemento do
        tipo nó fila e insere este elemento na última posição da fila.
ENTRADA: Fila* - a referência para uma fila.
         elem - o valor do elemento a ser inserido
SAÍDA: Fila* - a referência para a fila com o  novo elemento inserido.
**/
Fila* push(Fila* f, int elem)
{
	// Cria uma nova caixinha para armazenar o novo elemento. Este elemento é do tipo
	// nó fila. Portanto, ao usar o malloc para criar dinamicamente este novo elemento
	// devemos converter o retorno da função malloc para o tipo NoFila.
	NoFila *novo = (NoFila*)malloc(sizeof(NoFila));
	// Preenche os campos da caixinha
	novo->valor = elem;		// Atribui o valor
	novo->prox = NULL;		// O próximo na nova caixinha recebe NULL

    // Verifica se a fila está vazia.
    if(filaVazia(f))
    {
        // Caso esteja, o novo elemento a ser inserido, será tanto o primeiro quanto
        // o último elemento da fila. Logo temos que apontar os dois ponteiros do
        // cabeçalho (prim e ult) para este elemento.
        f->prim = f->ult = novo;
    }
    // Caso a fila não esteja vazia, o novo elemento deve ser inserido no final da fila.
    else
    {
        // f->ult referencia o último elemento do tipo NoFila, ou seja, o último elemento
        // da fila. O último elemento da fila deixará de ser o último, dado que um novo
        // elemento está sendo inserido. Portanto, devemos fazer o campo prox do último
        // elemento apontar para o novo.
        f->ult->prox = novo;

        // Atualiza na estrutura cabeçalho quem é o último elemento da fila. O último
        // elemento é o novo que acabou de ser inserido.
        f->ult = novo;
    }

	// Retorna a estrutura cabeçalho da fila
	return f;
}

/**
FUNÇÃO: pop
DESCRIÇÃO: Função que remove o primeiro elemento da fila. A função certifica que a fila
        não está vazia para remover o primeiro elemento.
ENTRADA: Fila* - a referência para uma fila.
SAÍDA: Fila* - a referência para a fila com o primeiro elemento removido, se houver pelo
        menos um elemento na fila. Caso contrário o retorno será NULL.
**/
Fila* pop(Fila* f)
{
	// Verifica se a fila está vazia
	if(filaVazia(f))
	{
	    // Retorna NULL para sinalizar que a fila esta vazia
	    return NULL;
	}


	// Caso a fila não esteja vazia, cria um ponteiro auxiliar para apontar para o elemento
	// a ser removido, ou seja, o primeiro elemento da fila. Este ponteiro, como vai apontar
	// para um elemento da fila e não para a estrutura cabeçalho, deve ser do tipo NoFila
	NoFila *aux = f->prim;

	// Como o primeiro elemento da fila será removido, o novo primeiro elemento é o atual
	// segundo elemento. Logo, temos que atualizar o ponteiro prim da estrutura cabeçalho
	// para apontar para o segundo elemento, e assim não perder a referência dos elementos
	// da fila
	f->prim = aux->prox;    // Este comando também pode ser escrito desta forma: f->prim = f->prim->prox;

	// Agora que atualizamos todos os ponteiros necessários da nossa fila, podemos apagar
	// o primeiro elemento, ou seja, chamar a função free passando como parâmetro o aux
	free(aux);

	// Retorna a estrutura cabeçalho f, que agora está sem o primeiro elemento
	return f;
}

/**
FUNÇÃO: primeiro
DESCRIÇÃO: Função que retorna a referência do primeiro elemento da fila. O primeiro elemento
        da fila é um elemento do tipo NoFila.
ENTRADA: Fila* - a referência para uma fila.
SAÍDA: NoFila* - a referência para o primeiro elemento da fila.
**/
NoFila* primeiro(Fila* f)
{
	return f->prim;
}

/**
FUNÇÃO: imprimeFila
DESCRIÇÃO: Função que exibe na tela todos os elementos existentes na fila.
ENTRADA: Fila* - a referência para uma fila.
SAÍDA: void - como a função exibe os elementos e para isso ela não altera em nada a fila,
        a função retorna void.
**/
void imprimeFila(Fila *f)
{
    // Todos os elementos a serem exibidos na tela são do tipo NoFila.
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
