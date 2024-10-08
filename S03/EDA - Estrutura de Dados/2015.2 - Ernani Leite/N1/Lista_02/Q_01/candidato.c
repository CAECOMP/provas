#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"


void lerLista(Candidato *ptr, int dimensao){
    int i;
    for(i = 0; i < dimensao; i++){
        printf("Candidato %d\n", i);
        lerCandidato(ptr+i);
    }

}
void mostraLista(Candidato *ptr, int dimensao){
    int i;
    for(i = 0; i < dimensao; i++){
        printf("\n-----------------------------\n");
        printf("Candidato %d\n", i);
        mostraCandidato(ptr+i);
        printf("\n-----------------------------\n");

    }


}
void lerCandidato(Candidato *ptr){
	printf("Digite o nome:\n");
	scanf("%s", ptr->nome);
	printf("Digite a idade:\n");
	scanf("%d", &ptr->idade);
	printf("Digite o Sexo M ou F:\n");
    getchar();
    scanf("%c", &ptr->sexo);
	printf("Experiencia S ou N:\n");
	getchar();
	scanf("%c", &ptr->experiente);

}

void mostraCandidato(Candidato *ptr){
	printf("Nome: %s\n", ptr->nome);
	printf("Sexo: %c\n", ptr->sexo);
	printf("Idade:%d\n", ptr->idade);
	printf("Experiencia:%c\n", ptr->experiente);

}
void relatorios(Candidato *ptr, int dimensao){
    int i, novinhasExperientes;
    int totalFeminino,totalMasculino, totalHomensVelhos, homensExperientes;
    float percentualHomensVelhos, mediaIdadeExperientes;

    totalHomensVelhos = 0;
    totalMasculino = 0;
    totalFeminino = 0;
    homensExperientes = 0;
    novinhasExperientes = 0;
    mediaIdadeExperientes = 0;
    percentualHomensVelhos = 0;
    for(i = 0; i < dimensao; i++){
        if((ptr+i)->sexo == 'M'){
            totalMasculino++;
            if((ptr+i)->idade > 45){
                totalHomensVelhos++;
            }
            if((ptr+i)->experiente == 'S'){
                mediaIdadeExperientes += (ptr+i)->idade;
                homensExperientes++;
            }


        }
        else if((ptr+i)->sexo == 'F'){
            totalFeminino++;
            if((ptr+i)->idade < 35 && (ptr+i)->experiente == 'S'){
                novinhasExperientes++;
            }
        }
    }
    if(homensExperientes)
        mediaIdadeExperientes = (float)mediaIdadeExperientes/(float)homensExperientes;
    if(totalMasculino)
        percentualHomensVelhos = (float)totalHomensVelhos/(float)totalMasculino*100;
    printf("%d candidatos do sexo feminino e %d candidatos do sexo masculino.\n", totalFeminino, totalMasculino);
    printf("Percentual de homens com mais de 45 anos: %.2f %%\n", percentualHomensVelhos);
    printf("Idade media dos homens experientes: %.2f \n", mediaIdadeExperientes);
    printf("Mulheres com menos de 35 experientes: %d \n", novinhasExperientes);

}


