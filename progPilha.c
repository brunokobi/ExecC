#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

void menu()
{
	printf("1. Inserir um novo elemento\n");
	printf("2. Apagar um elemento\n");
	printf("3. Imprimir o topo da pilha\n");
	printf("4. Imprimir todos os elementos da pilha\n");
	printf("5. Sair\n");
}

main()
{
	int opcao, num;
	Pilha *p = novaPilha();

	do
	{
		menu();
		printf("Digite a sua opcao: ");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("clear");
				printf("\nDigite o numero a inserir: ");
				scanf("%d", &num);
				p = push(p, num);

				system("clear");
				printf("\nNumero adicionado com sucesso\n\n");
				break;

			case 2:
				system("clear");
				if(pilhaVazia(p))
					printf("\nErro ao remover! A pilha estah vazia\n\n");
				else
				{
					p = pop(p);
					printf("\nElemento removido com sucesso\n\n");
				}
				break;

			case 3:
				system("clear");
				No *t = topo(p);
				if(t != NULL)
					printf("\nTopo: %d\n\n", t->dado);

				break;

			case 4:
				system("clear");
				printf("\n");
				imprimePilha(p);
				printf("\n");

				break;

			case 5:
				system("clear");
				printf("\nSaindo do sistema!\n\n");
				break;

			default:
				system("clear");
				printf("\nOpcao invalida!\n\n");
		}
	} while (opcao != 5);
}
