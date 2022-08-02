#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
	int valor;
	struct no *prox;
} No;

typedef struct lista
{
    No *inicio;
} Lista;

Lista* novaLista()
{
    // Aloca dinamicamente um espaço para a estrutura cabeçalho. Para realizar a alocação
    // dinâmica de memória, usa-se a função malloc(). Esta função, conforme foi implementada,
    // retorna um ponteiro para void (void*). É feita uma conversão explícita deste ponteiro
    // para void, para um ponteiro para um Lista (Lista*).
    Lista* l = (Lista*)malloc(sizeof(Lista));

    // inicializando os campos da estrutura. Neste caso, como a lista inicialmente não possui
    // elementos, os campos da estrutura são incializados com NULL.
    l->inicio = NULL;

    // retornando a estrutura cabeçalho.
	return l;
}


int listaVazia(Lista* l)
{
	if(l->inicio == NULL)
		return 1;
	else return 0;
}

Lista* push(Lista* l, int elem)
{
	// Cria uma nova caixinha para armazenar o novo elemento. Este elemento é do tipo
	// nó lista. Portanto, ao usar o malloc para criar dinamicamente este novo elemento
	// devemos converter o retorno da função malloc para o tipo NoLista.
	No *novo = (No*)malloc(sizeof(No));
	// Preenche os campos da caixinha
	novo->valor = elem;		// Atribui o valor
	novo->prox = NULL;		// O próximo na nova caixinha recebe NULL

    // Verifica se a lista está vazia.
    if(listaVazia(l))
    {
        // Caso esteja, o novo elemento a ser inserido, será tanto o primeiro quanto
        // o último elemento da lista. Logo temos que apontar os dois ponteiros do
        // cabeçalho (prim e ult) para este elemento.
        l->inicio = novo;
    }
    // Caso a lista não esteja vazia, o novo elemento deve ser inserido no final da lista.
    else
    {
        // declara um aux que aponta para o início da lista.
        No *aux = l->inicio;

		// enquanto o aux for diferente de NULL, anda com ele para adiante... até o último
		// elemento da lista
		while(aux->prox != NULL)
			aux = aux->prox;

        // liga o último elemento da lista ao novo elemento.
        aux->prox = novo;
    }

	// Retorna a estrutura cabeçalho da lista
	return l;
}


void printLista(Lista *l)
{
    // Todos os elementos a serem exibidos na tela são do tipo NoLista.
	No *aux = l->inicio;

    // Enquanto houver elemento na lista, ou seja, enquanto o ponteiro que percorre todos
    // os Nolista's for diferente de NULL
	while(aux != NULL)
	{
	    // Exibe o dado preenchido no campo valor
		printf("%d -> ", aux->valor);
		aux = aux->prox;
	}
}

int fatorialN(int n) {
    if(n) {
        return n * fatorialN(n - 1);
    } else {
        return 1;
    }
}

void imprimeListafatorial(Lista *l)
{
    // Todos os elementos a serem exibidos na tela são do tipo NoLista.
	No *aux = l->inicio;

    // Enquanto houver elemento na lista, ou seja, enquanto o ponteiro que percorre todos
    // os Nolista's for diferente de NULL
	while(aux != NULL)
	{
	    // Exibe o dado preenchido no campo valor
		printf("%d -> ",fatorialN(aux->valor));
		aux = aux->prox;
	}
}


int tamanhoLista(Lista *l)
{
    // Todos os elementos a serem exibidos na tela são do tipo NoLista.
	No *aux = l->inicio;
	int tam = 0;

    // Enquanto houver elemento na lista, ou seja, enquanto o ponteiro que percorre todos
    // os Nolista's for diferente de NULL
	while(aux != NULL)
	{
	    tam++;
	    // contador de elementos
		aux = aux->prox;
	}
	return tam;
}


int posicaoLista(Lista* l,No* no)
{
	// Verifica se a lista não está vazia
	if(!listaVazia(l))
	{
		// Caso a lista não esteja vazia, declara um aux que aponta para o início da lista.
		No *aux = l->inicio;
		int posicao=0;

		// Percorre a lista em busca do no
		while(aux != NULL && aux != no){
			posicao++;
			aux = aux->prox;
		}

		// Se o elemento foi encontrado
		if(aux != NULL && aux == no)
		{
			// Retorna a posicao do no na lista
			return posicao;
		}
	}
	// Ou a lista está vazia ou no não existente
	return -1;
}


No* NoPosicaoLista(Lista* l, int posicao)
{
    int i,tamanho;
	tamanho=tamanhoLista(l);//acha o tamanho d lista
	// Verifica se a lista não está vazia ou é posicao é maior que o tamanho
	if(!listaVazia(l)||posicao>tamanho)
	{
		// Caso a lista não esteja vazia, declara um aux que aponta para o início da lista.
		No *aux = l->inicio;
		// Percorre a lista em busca do elemento
		for(i=0;i<posicao;i++){
			aux = aux->prox;
		}
	// Se o elemento foi encontrado retorna o nó
	return aux;
	}
	// Ou a lista está vazia ou o elemento não existente
	return NULL;
}


No* menorNoLista(Lista* l,int posicao)
{
	// Verifica se a lista não está vazia
	if(!listaVazia(l))
	{
		// Caso a lista não esteja vazia, declara um aux que aponta para o início da lista.
		No *aux = NoPosicaoLista(l,posicao);
		No *menorNo = aux;
		if(aux != NULL)

		// Percorre a lista em busca do no
		while(aux != NULL){
		    // Se o elemento foi encontrado
		    if(aux->valor < menorNo->valor)
		    {
			// Retorna a posicao do no na lista
			menorNo=aux;
    		}
    	aux = aux->prox;
		}
	return menorNo;
	}
	// Ou a lista está vazia ou no não existente
	return NULL;
}


void trocaNoLista(Lista *l,No *Num1,No *Num2)
{
    int posicaoNum1=posicaoLista(l,Num1);//posicao do 1º numero na lista
    int posicaoNum2=posicaoLista(l,Num2);//posicao do 2º numero na lista

    if(Num1==Num2)//se os nós  forem iguais apenas sair
        return;

    No* antesNum2 = NoPosicaoLista(l,posicaoNum2-1);

    if(Num1==l->inicio){
        l->inicio=Num2;
    }
    else{
        No* antesNum1 = NoPosicaoLista(l,posicaoNum1-1);
        antesNum1->prox=Num2;
    }
    antesNum2->prox=Num1;

    No* aux = Num1->prox;
    Num1->prox=Num2->prox;
    Num2->prox=aux;

}


void ordenarCLista(Lista *l)
{


	for(int i=0;i<tamanhoLista(l);i++){
	    trocaNoLista(l, NoPosicaoLista(l,i), menorNoLista(l,i));
	}

    No *aux = l->inicio;
	while(aux != NULL)
	{
		printf("%d -> ", aux->valor);
		aux = aux->prox;
	}
}


int main()
{
    int numero=1;
    Lista *l = novaLista();


    while(numero>=1&&numero<=1000){// LOOP DE LEITURA DA VARIAVEL
        scanf("%d",&numero);
        if(numero<0)// SAIR DO LOOP
            break;
        else{
        l = push(l, numero);// LISTA ORIGINAL
        }
    }

    printf("Lista Normal \n");
    printLista(l);
    printf("\n");
    printf("Lista Ordenada \n");
    ordenarCLista(l);
    printf("\n");
    printf("Lista Fatorial \n");
    imprimeListafatorial(l);
    printf("\n");

    return 0;
}


