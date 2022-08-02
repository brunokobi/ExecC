#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*** DEFINICAO DAS ESTRUTURAS DO TAD ***/

typedef struct no
{
	int dado;
	struct no *prox;
} No;

typedef struct pilha
{
	No *inicio;
} Pilha;

/*** FIM DEFINICAO DAS ESTRUTURAS DO TAD ***/

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

int inttopo(Pilha* p)
{
	if(pilhaVazia(p))
		return NULL;
	else
		return p->inicio->dado;
}

void imprimePilha(Pilha *p)
{
	No *aux = p->inicio;
	Pilha *pi;
	pi = novaPilha();

	while(aux != NULL)
	{
		//printf("%d ", aux->dado);
		pi = push(pi,aux->dado);
		aux = aux->prox;
	}
	aux = pi->inicio;
	while(aux != NULL)
	{
		printf("%d ", aux->dado);
		aux = aux->prox;
	}
}

// FUNÇÃO PRA LOCALIZAR O ELEMENTO NAS PILHAS
int locPilha(Pilha *p,int elem)
{
	No *aux = p->inicio;

	while(aux != NULL)
	{
		if(aux->dado==elem){
        return elem;
       }
		aux = aux->prox;
	}
	return -1;
}



main()
{
	int  n,y=0,a,b,i,origem=0,destino=0,op=0,valor,cont=0,x=0,f1,f2,n1,n2;
	char p1[7],p2[2];
	scanf("%d",&n);
	Pilha *vetPilha[n];
	Pilha *aux;
	aux=novaPilha();


	for(i=0;i<n;i++)
	vetPilha[i] = novaPilha();

	for(i=0;i<n;i++)
	vetPilha[i] = push(vetPilha[i],i);

	for(i=0;i<n;i++){
	printf("%d: ",i);
	imprimePilha(vetPilha[i]);
	printf("\n");
	}


	//inico  do prog
	while(p1!="fim"){
	scanf("%s",&p1);
	if (strcmp (p1,"fim") == 0)
        break;
    if (strcmp (p1, "coloque") == 0)
        f1=1;
    if (strcmp (p1, "empilhe") == 0)
        f2=1;
	scanf("%d",&a);
	scanf("%s",&p2);
    if (strcmp (p2, "no") == 0)
        n1=1;
    if (strcmp (p2, "em") == 0)
        n2=1;
	scanf("%d",&b);
	if(a==b){
        op=0;
        destino=0;
        origem =0;
        a=0;
        b=0;
        continue;
	}

	fflush(stdin);

//CHAMADA DA FUNCAO LOCALIÇÃO DESTINO PILHA
	for(i=0;i<n;i++){
        if(locPilha(vetPilha[i],a)==a){
        origem=i;
        }
	}


//CHAMADA DA FUNCAO LOCALIÇÃO DESTINO PILHA
	for(i=0;i<n;i++){
        if(locPilha(vetPilha[i],b)==b){
        destino=i;
        }
	}

// validação do sistema  origem e destino nao pode ser na mesma pilha
	if(origem==destino){
        op=0;
        destino=0;
        origem =0;
        a=0;
        b=0;
        continue;
	}


	//INICIO COLOQUE EM
	if(f1==1&&n2==1){
	while(a!=inttopo(vetPilha[origem]))
	{
		valor=inttopo(vetPilha[origem]);
		vetPilha[valor]=push(vetPilha[valor],valor);
		pop(vetPilha[origem]);
	}

	while(b!=inttopo(vetPilha[destino]))
	{
		valor=inttopo(vetPilha[destino]);
		vetPilha[valor]=push(vetPilha[valor],valor);
		pop(vetPilha[destino]);
	}
	vetPilha[destino]=push(vetPilha[destino],a);
	pop(vetPilha[origem]);

	//IMPRIMI PILHA
	for(i=0;i<n;i++){
	printf("%d: ",i);
	imprimePilha(vetPilha[i]);
	printf("\n");
	}
	}


    //INICIO COLOQUE A NO B
	if(f1==1&&n1==1){
	while(a!=inttopo(vetPilha[origem]))
	{
		valor=inttopo(vetPilha[origem]);
		vetPilha[valor]=push(vetPilha[valor],valor);
		pop(vetPilha[origem]);
	}

	vetPilha[destino]=push(vetPilha[destino],a);
	pop(vetPilha[origem]);

	//IMPRIMI PILHA
	for(i=0;i<n;i++){
	printf("%d: ",i);
	imprimePilha(vetPilha[i]);
	printf("\n");
	}
	}

// INICIO EMPILHE A EM B
    if(f2==1&&n2==1){
	while(a!=inttopo(vetPilha[origem]))
	{
	    x = inttopo(vetPilha[origem]);
		aux = push(aux,x);
		pop(vetPilha[origem]);
		cont++;
	}
	aux = push(aux,inttopo(vetPilha[origem]));
	pop(vetPilha[origem]);

	while(b!=inttopo(vetPilha[destino]))
	{
		valor=inttopo(vetPilha[destino]);
		vetPilha[valor]=push(vetPilha[valor],valor);
		pop(vetPilha[destino]);
	}


	while(y<cont+1){
	vetPilha[destino]= push(vetPilha[destino],aux->inicio->dado);
	pop(aux);
	y++;
	}

	//IMPRIMI PILHA
	for(i=0;i<n;i++){
	printf("%d: ",i);
	imprimePilha(vetPilha[i]);
	printf("\n");
	}
	}

	// INICIO EMPILHE A NO B
    if(f2==1&&n1==1){
	while(a!=inttopo(vetPilha[origem]))
	{
	    x = inttopo(vetPilha[origem]);
		aux = push(aux,x);
		pop(vetPilha[origem]);
		cont++;
	}
	aux = push(aux,inttopo(vetPilha[origem]));
	pop(vetPilha[origem]);

	while(y<cont+1){
	vetPilha[destino]= push(vetPilha[destino],aux->inicio->dado);
	pop(aux);
	y++;
	}

	//IMPRIMI PILHA
	for(i=0;i<n;i++){
	printf("%d: ",i);
	imprimePilha(vetPilha[i]);
	printf("\n");
	}
	}

op=0;
destino=0;
origem =0;
a=0;
b=0;
f1=0;
f2=0;
n1=0;
n2=0;
y=0;
cont=0;
i=0;

	}//FIM PROGRAMA



}
