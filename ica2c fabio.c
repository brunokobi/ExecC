#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,media=0;
    int vet[4][4];

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("digite o elemento [%d] [%d] da matriz = ",i,j);
            scanf("%d",&vet[i][j]);
            if(i==j)
                media+=vet[i][j];

        }
    }


    printf("\n");
    printf("A media da diagonal: %d \n",media/4);




    return 0;
}


