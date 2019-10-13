#include <stdio.h>
#include <stdlib.h>
#define N 100
#define FALSE 0
#define TRUE !FALSE

int main()
{

	int dimensaoX, dimensaoY, dimensaoW, i, menorX, maiorX, z, achou;
	int vetorX[N], vetorY[N], vetorW[N];
	printf("Digite a dimensão do vetor X, no máximo %d:", N);
	scanf("%d", &dimensaoX);
	for(i = 0; i < dimensaoX; i++){
		printf("Digite o elemento %d:\n", i);
		scanf("%d", &vetorX[i]);
	}

	dimensaoY = 0;
	dimensaoW = 0;
	menorX = vetorX[0];
	maiorX = vetorX[0];
	for(i = 0; i < dimensaoX; i++){

		if(vetorX[i] > maiorX)
			maiorX = vetorX[i];
		if(vetorX[i] < menorX)
			menorX = vetorX[i];
		if(vetorX[i] > 10 && vetorX[i] < 40){
			vetorY[dimensaoY] = vetorX[i];
			dimensaoY++;
		}
		//Posicoes pares
		if(!(i%2)){
			vetorW[dimensaoW] = vetorX[i];
			dimensaoW++;
		}
	}

	printf("Vetor X:\n");
	mostraVetor(vetorX, dimensaoX);
	printf("Vetor Y:\n");
	mostraVetor(vetorY, dimensaoY);
	printf("Vetor W:\n");
	mostraVetor(vetorW, dimensaoW);

	printf("Maior elemento de X: %d\n", maiorX);
	printf("Menor elemento de X: %d\n", menorX);

	do{
		printf("Digite o numero Z que deseja pesquisar: ");
		scanf("%d", &z);
		achou = FALSE;
		for(i = 0; i < dimensaoX; i++){
			if(vetorX[i]== z){
				achou = TRUE;
				printf("Elemento %d encontrado na posição %d. ", vetorX[i], i);
				return 0;
			}
		}
	}while(!achou);
	return 0;
}


void mostraVetor(int *vetor, int dimensao){
	int i;
	for(i = 0; i < dimensao; i++)
		printf("Elemento [%d]: %d\n", i, vetor[i]);
}
