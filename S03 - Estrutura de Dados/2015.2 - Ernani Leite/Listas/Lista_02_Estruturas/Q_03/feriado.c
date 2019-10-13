#include <stdio.h>
#include <stdlib.h>

#include "feriado.h"


void lerLista(Feriado *ptr, int dimensao){
    int i;
    for(i = 0; i < dimensao; i++){
        printf("Respostas motorista %d\n", i);
        lerFeriado(ptr+i);
    }

}

void lerFeriado(Feriado *ptr){
    printf("Qual o seu destino? \n");
    printf("1-  Camocim,\n");
    printf("2-  Morro Branco,\n");
    printf("3-  Aracati,\n");
    printf("4-Guaramiranga e 5- Outros Locais;\n");
    scanf("%d", &ptr->destino);
    printf("Qual o veículo? \n");
    printf("1-  Automóvel, 2-  Caminhão, 3-  Ônibus e 4-Outros Veículos");
    scanf("%d", &ptr->veiculo);


}

void relatorio(Feriado *ptr, int dimensao){
    int i, totalDeCaminhoes, caminhouesPraCamocim, totalDeOnibus, totalDeVeiculos;
    int destinoAracati = 0;
    float auxiliar = 0;
    totalDeCaminhoes = 0;
    totalDeOnibus = 0;
    totalDeVeiculos = 0;
    caminhouesPraCamocim = 0;

    for(i = 0; i < dimensao; i++){
        totalDeVeiculos++;
        if((ptr+i)->destino == ARACATI && (ptr+i)->veiculo == AUTOMOVEL)
            destinoAracati++;
        if((ptr+i)->veiculo == CAMINHAO && (ptr+i)->destino == CAMOCIM){
            caminhouesPraCamocim++;
        }
        if((ptr+i)->veiculo == ONIBUS)
            totalDeOnibus++;
    }

    printf("\n\nTotal de automoveis com destino a aracati: %d\n", destinoAracati);
    auxiliar = 0;

    if(totalDeVeiculos)
        auxiliar = (float)caminhouesPraCamocim/(float)totalDeVeiculos*100;
    printf("Percentual de caminhoues com destino a camocim em relacao ao total de veiculos: %.2f\n", auxiliar);
    auxiliar = 0;
    if(totalDeVeiculos)
        auxiliar = (float)totalDeOnibus/(float)totalDeVeiculos*100;
    printf("A porcentagem de Ônibus que trafegam pela rodovia:%.2f\n", auxiliar);
}
