#include <stdlib.h>
#include <stdio.h>
#include "funcionario.h"



void lerLista(Funcionario *ptr, int dimensao){
    int i;
    for(i = 0; i < dimensao; i++){
        printf("Funcionario %d\n", i);
        lerFuncionario(ptr+i);
    }

}
void mostraLista(Funcionario *ptr, int dimensao){
    int i;
    for(i = 0; i < dimensao; i++){
        printf("\n-----------------------------\n");
        printf("Funcionario %d\n", i);
        mostraFuncionario(ptr+i);
        printf("\n-----------------------------\n");

    }


}
void lerFuncionario(Funcionario *ptr){
	printf("Digite o nome:\n");
	scanf("%s", ptr->nome);
	printf("Digite a producao:\n");
	scanf("%d", &ptr->producao);
	printf("Digite o Sexo M ou F:\n");
    getchar();
    scanf("%c", &ptr->sexo);

}

void mostraFuncionario(Funcionario *ptr){
	printf("Nome: %s\n", ptr->nome);
	printf("Sexo: %c\n", ptr->sexo);
	printf("Producao:%d\n", ptr->producao);
}
void relatorios(Funcionario *ptr, int dimensao){
    int i, producaoTotal, producaoMasculina, producaoFeminina, maiorProducao;
    char *nomeDoCampeao;

    maiorProducao = 0;
    producaoFeminina = 0;
    producaoMasculina = 0;
    producaoTotal = 0;
    for(i = 0; i < dimensao; i++){
        producaoTotal += (ptr+i)->producao;
        if(maiorProducao < (ptr+i)->producao){
            maiorProducao = (ptr+i)->producao;
            nomeDoCampeao = (ptr+i)->nome;
        }
        if((ptr+i)->sexo == 'M')
        {
            producaoMasculina += (ptr+i)->producao;
        }
        else if((ptr+i)->sexo == 'F'){

            producaoFeminina += (ptr+i)->producao;

        }
    }
    printf("Producao total: %d, producao masculina: %d, producao feminina: %d\n", producaoTotal, producaoMasculina, producaoFeminina);
    printf("Campeao de producao foi %s com %d pecas produzidas\n", nomeDoCampeao, maiorProducao);


}

