#include <stdio.h>
#include <stdlib.h>


void lervetor(int vet[])
{
	for(int i=0;i<10;i++){
        printf(" digite o elemento %d  =  ",i+1);
        scanf("%d",&vet[i]);
	}
}

void imprimirvetor(int vet[])
{
    printf("o vetor digitado: ");

	for(int i=0;i<10;i++){
        printf("%d ",vet[i]);
	}

}

void igualvetor(int vet[])
{
    int valor, cont=0;
    printf("digite um valor = ");
        scanf("%d",&valor);

	for(int i=0;i<10;i++){
        if(valor==vet[i])
            cont++;
	}
	if(cont==0){
        printf("nao tem elementos iguais ");
        return 0;
	}
    else
        printf("o elemento digitado existe %d vezes no vetor",cont);

}

int main()
{
    int vet[10];

    lervetor(vet);
    printf("\n");

    imprimirvetor(vet);
    printf("\n");

    igualvetor(vet);
    printf("\n");

    return 0;
}


