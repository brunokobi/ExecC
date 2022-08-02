#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,m,maior=0,menor=9999999;
    printf("digite N da matriz =");
    scanf("%d",&n);

    printf("digite M da matriz =");
    scanf("%d",&m);

    int vet[n][m];

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("digite o elemento [%d] [%d] da matriz = ",i,j);
            scanf("%d",&vet[i][j]);
            if(vet[i][j]>maior)
                maior=vet[i][j];

            if(vet[i][j]<menor)
                menor=vet[i][j];

        }
    }


    printf("\n");
    printf("o maior numero :%d \n",maior);
    printf("o menor numero :%d \n",menor);


    return 0;
}


