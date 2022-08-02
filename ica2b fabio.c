#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,negativo=0,positivo=0,zero=0;
    int vet[3][5];

    for(i=0;i<3;i++){
        for(j=0;j<5;j++){
            printf("digite o elemento [%d] [%d] da matriz = ",i,j);
            scanf("%d",&vet[i][j]);
            if(vet[i][j]>0)
                positivo++;
            else if(vet[i][j]<0)
                negativo++;
            else
                zero++;

        }
    }


    printf("\n");
    printf("numeros positivos : %d \n",positivo);
    printf("numeros negativos : %d \n",negativo);
    printf("numeros zeros : %d \n",zero);



    return 0;
}


