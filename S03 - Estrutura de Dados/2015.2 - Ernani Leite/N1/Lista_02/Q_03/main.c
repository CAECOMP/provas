#include <stdio.h>
#include <stdlib.h>
#include "feriado.h"


int main()
{
    int dimensao;
	Feriado *listaDeRespostas;
	printf("Digite a dimensao:\n");
	scanf("%d", &dimensao);

	listaDeRespostas = (Feriado*)malloc(sizeof(Feriado)*dimensao);
	if(listaDeRespostas == NULL){
		printf("Momória insuficiente.");
		return 0;
	}
    lerLista(listaDeRespostas, dimensao);
    relatorio(listaDeRespostas, dimensao);
    return 0;
}
