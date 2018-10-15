#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dimensaoA, dimensaoC, i;
    int *vetorA, *vetorB, *vetorC;
    printf("Digite a dimensão para vetores A e B:");
    scanf("%d", &dimensaoA);
    dimensaoC = 2*dimensaoA;
    vetorA = malloc(sizeof(int)*dimensaoA);
    vetorB = malloc(sizeof(int)*dimensaoA);
    vetorC = malloc(sizeof(int)*dimensaoA*2);
    if(vetorA == NULL || vetorB == NULL || vetorC == NULL)
    {
        printf("Memoria Insuficiente");
        return 0;
    }
    printf("Recebendo valores do Vetor A:\n");
    for(i = 0; i < dimensaoA; i++){
        printf("Digite o elemento %d:\n", i);
        scanf("%d", vetorA+i);
    }
    printf("Recebendo valores do Vetor B:\n");
    for(i = 0; i < dimensaoA; i++){
        printf("Digite o elemento %d:\n", i);
        scanf("%d", vetorB+i);
    }


    printf("Vetor A\n");
    mostraVetor(vetorA, dimensaoA);
    printf("Vetor B\n");
    mostraVetor(vetorB, dimensaoA);
    dimensaoC = 0;
    for(i = 0; i < dimensaoA; i++){
        *(vetorC+dimensaoC) = *(vetorA+i);
        *(vetorC+dimensaoC+1) = *(vetorB+i);
        dimensaoC += 2;
    }
    printf("Vetor C\n");
    mostraVetor(vetorC, dimensaoC);

    return 0;
}

void mostraVetor(int *vetor, int dimensao){
	int i;
	for(i = 0; i < dimensao; i++)
		printf("Elemento [%d]: %d\n", i, vetor[i]);
}

