#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE !FALSE

void mostraVetor(int *vetor, int dimensao){
	int i;
	for(i = 0; i < dimensao; i++)
		printf("Elemento [%d]: %d\n", i, vetor[i]);
}
void ordenacaoBolha(int *lista, int dimensao){
    int houveTroca, i, aux;
	do{
		houveTroca = FALSE;
		for(i = 0; i < (dimensao - 1); i++){
			if(lista[i] > lista[i+1]){
				aux = lista[i];
				lista[i] = lista[i+1];
				lista[i+1] = aux;
				houveTroca = TRUE;
			}
		}
	}while(houveTroca);
}
int pesquisaBinaria(int *lista, int dimensao, int pesquisado){
    int comeco = 0;
    int fim = dimensao - 1;
    int meio;


    while(comeco <= fim){
        meio = (comeco+fim)/2;
        if(pesquisado < lista[meio])
            fim = meio - 1;
        else if(pesquisado > lista[meio])
            comeco = meio + 1;
        else
            return meio;
    }
    return -1;

}
void retiraDaLista(int *lista, int *dimensao, int posicao){
    int i;
    for(i = posicao; i < (*dimensao)-1; i++){
        *(lista+i) = *(lista+i+1);
    }
    (*dimensao)--;
}

int main()
{
    int dimensao, i,j, flagRepetiu, removidos, pesquisado;
    int *lista;
    printf("Digite o valor de N, dimensao do vetor:\n");
    scanf("%d", &dimensao);
    lista = malloc(sizeof(int)*dimensao);
    if(!lista){
        printf("Memoria insuficiente\n");
        return 0;
    }
    for(i = 0; i < dimensao; i++){
        printf("Digite o elemento %d:", i);
        scanf("%d", (lista+i));
    }
    removidos = 0;

    for(i = 0; i < dimensao; i++){
        for(j = (i+1); j < dimensao; j++){
            if(*(lista+i)== *(lista+j)){
                removidos++;
                retiraDaLista(lista, &dimensao, i);
                i--;
                break;
            }
        }
    }
    if(!removidos){
        printf("Ok\n");
    }else{
        printf("%d removido(s):\n", removidos);
    }


    printf("Digite o elemento que deseja pesquisar:\n");
    scanf("%d", &pesquisado);
    ordenacaoBolha(lista, dimensao);
    printf("Lista ordenada:\n");
    mostraVetor(lista, dimensao);
    i = pesquisaBinaria(lista, dimensao, pesquisado);
    if(i != -1)
        printf("Encontrei na posicao %d\n", i);
    else
        printf("Nao encontrado\n");

    return 0;



}
