#include <stdio.h>
#include <stdlib.h>
#include "caixa.h"


int main()
{
    int listaCarregada = FALSE;
    int comando;
    int dimensao;
    char filename[35];
    Caixa *lista;

    do{
        if(!listaCarregada){
            printf("\n\n-----Pesquisa Pato branco------\n\n");
            printf("Digite 0 para sair \n1 para nova lista\n2 para abrir arquivo\n");
            scanf("%d", &comando);
            switch(comando){
                case 1:
                    printf("Digite a dimensao:\n");
                    scanf("%d", &dimensao);
                    lista = malloc(sizeof(Caixa)*dimensao);
                    if(lista == NULL){
                        printf("Erro na tentativa de alocar\n");
                        continue;
                    }
                    listaCarregada = TRUE;
                    lerLista(lista, dimensao);
                break;
                case 2:
                    printf("Digite o nome do arquivo:\n");
                    scanf("%s", filename);
                    dimensao = retornaDimensao(filename);
                    lista = malloc(sizeof(Caixa)*dimensao);
                    if(lista == NULL){
                        printf("Erro na tentativa de alocar\n");
                        continue;
                    }
                    if(!loadVector(filename, lista, dimensao)){
                        printf("Erro na tentativa de abrir arquivo\n");
                        continue;
                    }
                    listaCarregada = TRUE;
                break;
                default:
                    printf("Comando nao localizado\n");
                    continue;
                break;
            }
        }else
        {

            printf("Digite 0 para encerrar\n");
            printf("1 para exibir a lista\n");
            printf("2 para exibir o relatorio\n");
            printf("3 para gravar em arquivo\n");
            printf("4 para fechar a lista e voltar ao menu principal\n");
            scanf("%d", &comando);
            switch(comando){

                case 1:
                    mostraLista(lista, dimensao);

                break;
                case 2:
                    relatorio(lista, dimensao);
                    break;
                case 3:
                    printf("Digite o nome do arquivo:\n");
                    scanf("%s",filename);
                    if(recordVector(filename, lista, dimensao))
                        printf("Arquivo salvo com sucesso\n");
                    else
                        printf("Erro ao tentar abrir arquivo\n");

                break;
                case 4:
                    listaCarregada = FALSE;
                    free(lista);
                    dimensao = 0;
                    break;
                default:
                    printf("Comando nao localizado\n");
                    continue;
                break;

            }

        }
    }while(comando);
    printf("\n\nAdeus!\n\n");

    return 0;
}
