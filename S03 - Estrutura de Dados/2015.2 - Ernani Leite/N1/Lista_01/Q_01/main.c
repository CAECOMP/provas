#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE !FALSE


int main(){
	int lista[100];
	int dimensao, i, houveTroca, aux, impar, par, media;
	printf("Digite a dimensão, no máximo 100:");
	scanf("%d", &dimensao);
	for(i = 0; i < dimensao; i++){
		printf("Digite o elemento %d:\n", i);
		scanf("%d", &lista[i]);
		if(lista[i] > 256)
			i--;
	}
	printf("\nLista como foi digitada:\n ");
	mostraVetor(lista,dimensao);

	//Ordem decrescente.
	do{
		houveTroca = FALSE;
		for(i = 0; i < (dimensao - 1); i++){
			if(lista[i] < lista[i+1]){
				aux = lista[i];
				lista[i] = lista[i+1];
				lista[i+1] = aux;
				houveTroca = TRUE;
			}
		}
	}while(houveTroca);
	printf("\nLista ordenada:\n ");
	mostraVetor(lista, dimensao);
	impar = 0;
	par = 0;
	aux = 0;
	media = 0;
    printf("Teste");
	for(i = 0; i < dimensao; i++){
		if(lista[i]%2){
			impar++;
			if(lista[i] > 50)
			{
				media += lista[i];
				aux++;
			}
		}
		else
			par++;
	}
	printf("--------------\n");
	if(aux)
        media = media/aux;
	printf("Impares: %d\n", impar);
	printf("Pares: %d\n", par);
	printf("Media dos impares maiores que 50: %d\n", media);
	return 0;
}

void mostraVetor(int *vetor, int dimensao){
	int i;
	for(i = 0; i < dimensao; i++)
		printf("Elemento [%d]: %d\n", i, vetor[i]);
}
