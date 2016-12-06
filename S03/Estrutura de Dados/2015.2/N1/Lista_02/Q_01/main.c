#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"


int main(void) {

	int dimensao, comando;
	Candidato *listaDeCandidatos;
	printf("Digite a dimensao:\n");
	scanf("%d", &dimensao);

	listaDeCandidatos = (Candidato*)malloc(sizeof(Candidato)*dimensao);
	if(listaDeCandidatos == NULL){
		printf("Momória insuficiente.");
		return 0;
	}
    lerLista(listaDeCandidatos, dimensao);
    mostraLista(listaDeCandidatos, dimensao);

    relatorios(listaDeCandidatos, dimensao);

	return 0;
}
