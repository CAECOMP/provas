#include <stdio.h>
#include <stdlib.h>


typedef struct box{
    char conteudo;
    struct box *proximo;

}Box;


Box* inserir_inicio(Box* lista, char conteudo){
    Box* novo = (Box*)malloc(sizeof(Box));
    novo->conteudo = conteudo;
    novo->proximo = lista;
    return novo;
}
void box_listar(Box* lista){
    Box *p;
    printf("\n\n-----------Listando-----------\n\n");
    for(p = lista; p != NULL; p = p->proximo){
        printf("Conteudo: %c\n", p->conteudo);
    }
}
void inserir_final(Box *lista, char conteudo){
    Box *p = lista;

    for(p = lista; p->proximo != NULL; p = p->proximo){
    }
    p->proximo = (Box*)malloc(sizeof(Box));
    p->proximo->proximo = NULL;
    p->proximo->conteudo = conteudo;
}
void insere_entre_dois(Box*lista, char primeiro, char proximo, char conteudo){
    Box*novo;

    Box *p = lista;
    for(p = lista; p != NULL; p = p->proximo){
        if(p->proximo == NULL)
            break;
        if(p->conteudo == primeiro && p->proximo->conteudo == proximo)
        {

            novo = (Box*)malloc(sizeof(Box));
            novo->proximo = p->proximo;
            novo->conteudo = conteudo;
            p->proximo = novo;

        }

    }
}

void eliminar_por_busca(Box*lista, char conteudo){
    Box*anterior;
    Box *p;

    anterior = lista;
    for(p = anterior->proximo; p != NULL; p = p->proximo){
        if(anterior == NULL)
            break;
        if(p->conteudo == conteudo)
        {
            anterior->proximo = p->proximo;
            free(p);

        }

    }
}

Box* eliminar(Box*lista, char conteudo){
    Box *p, *anterior, excluido;
    anterior = lista;
    if(anterior->conteudo == conteudo){
        p = anterior->proximo;
        free(anterior);
        return p;
    }

    for(p = anterior->proximo; p != NULL; p = p->proximo){
        if(p->conteudo == conteudo){
            anterior->proximo = p->proximo;
            free(p);
            return lista;
        }
        anterior = anterior->proximo;

    }
    return lista;
}
Box* excluir_primeiro(Box*lista){
    Box*excluido;
    excluido = lista;
    lista = lista->proximo;
    free(excluido);
    return lista;
}
void eliminar_final(Box *lista){
    Box *p = lista;
    Box *anterior;
    for(p = lista; p->proximo != NULL; p = p->proximo){
        anterior = p;
    }
    anterior->proximo = NULL;
    free(p);
}


int main()
{
    char letra;
    Box *lista = NULL;


    lista = inserir_inicio(lista, 'c');
    //1
    inserir_final(lista, 'A');
    box_listar(lista);
    //2
    lista = inserir_inicio(lista, 'B');
    box_listar(lista);
    //3
    inserir_final(lista, 'C');
    box_listar(lista);
    //4
    inserir_final(lista, 'D');
    box_listar(lista);

    //5
    insere_entre_dois(lista, 'A', 'C', 'E');
    box_listar(lista);

    //6
    lista = eliminar(lista, 'C');
    box_listar(lista);

    //7
    inserir_final(lista, 'F');
    box_listar(lista);

    //8
    lista = inserir_inicio(lista, 'G');
    box_listar(lista);

    //9
    eliminar_final(lista);
    lista = excluir_primeiro(lista);
    box_listar(lista);

    //10
    insere_entre_dois(lista, 'A', 'E', 'H');
    box_listar(lista);
    //11
    lista = eliminar(lista, 'a');
    box_listar(lista);
    //12
    insere_entre_dois(lista, 'E', 'D', 'I');
    box_listar(lista);

    //13
    inserir_final(lista, 'J');
    box_listar(lista);
   //14
    insere_entre_dois(lista, 'B', 'H', 'K');
    box_listar(lista);
    //15
    lista = eliminar(lista, 'D');
    lista = eliminar(lista, 'K');
    lista = eliminar(lista, 'I');
    lista = eliminar(lista, 'B');

    box_listar(lista);
    //16
    inserir_final(lista, 'L');
    box_listar(lista);





    box_listar(lista);

    return 0;
}
