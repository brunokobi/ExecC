#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

void menu()
{
	printf("1. Inserir um novo elemento\n");
	printf("2. Apagar um elemento\n");
	printf("3. Imprimir o primeiro da fila\n");
	printf("4. Imprimir todos os elementos da fila\n");
	printf("5. Sair\n");
}

main()
{
	int opcao, num;
	Fila *f = novaFila();

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
				f = push(f, num);

				system("clear");
				printf("\nNumero adicionado com sucesso\n\n");
				break;

			case 2:
				system("clear");
				if(filaVazia(f))
					printf("\nErro ao remover! A fila estah vazia\n\n");
				else
				{
					f = pop(f);
					printf("\nElemento removido com sucesso\n\n");
				}
				break;

			case 3:
				system("clear");
				if(filaVazia(f))
					printf("\nErro ao remover! A fila estah vazia\n\n");
				else
				{
                    NoFila *t = primeiro(f);
                    printf("\nPrimeiro: %d\n\n", t->valor);
				}
				break;

			case 4:
				system("clear");
				printf("\n");
				imprimeFila(f);
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
