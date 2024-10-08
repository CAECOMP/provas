#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

int main(void) {

	int dimensao, comando;
	Funcionario *listaDeFuncionarios;
	printf("Digite a dimensao:\n");
	scanf("%d", &dimensao);

	listaDeFuncionarios = (Funcionario*)malloc(sizeof(Funcionario)*dimensao);
	if(listaDeFuncionarios == NULL){
		printf("Momória insuficiente.");
		return 0;
	}
    lerLista(listaDeFuncionarios, dimensao);
    mostraLista(listaDeFuncionarios, dimensao);
    relatorios(listaDeFuncionarios, dimensao);
	return 0;
}
