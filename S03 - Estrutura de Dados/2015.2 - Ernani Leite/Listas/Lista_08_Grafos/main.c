#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct T_Vertice *P_Vertice;
typedef struct T_Aresta *P_Aresta;
typedef struct T_Grafo V_Grafo;

struct T_Aresta
{
    int N_Vertice;
    int N_Distancia;
    P_Aresta Proxima_Aresta;
};

struct T_Vertice
{
    int N_Vertice;
    int N_Grau;
    int B_Visitado;
    P_Vertice Proximo_Vertice;
    P_Aresta Primeira_Aresta;
    P_Aresta Ultima_Aresta;
};

struct T_Grafo
{
    P_Vertice Primeiro_Vertice;
    P_Vertice Ultimo_Vertice;
};
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
//Funções do gráfo
void Ini_Grafo_Vazio(V_Grafo *P_Grafo)
{
    P_Grafo->Primeiro_Vertice = (P_Vertice)malloc(sizeof(struct T_Vertice));
    P_Grafo->Primeiro_Vertice->N_Vertice = -1;
    P_Grafo->Primeiro_Vertice->N_Grau = -1;
    P_Grafo->Primeiro_Vertice->Proximo_Vertice = NULL;
    P_Grafo->Primeiro_Vertice->Primeira_Aresta = NULL;
    P_Grafo->Primeiro_Vertice->Ultima_Aresta = NULL;
    P_Grafo->Ultimo_Vertice = P_Grafo->Primeiro_Vertice->Proximo_Vertice;
}
////////////////////////////////////////
int eh_Grafo_Vazio(V_Grafo *P_Grafo)
{
    return (P_Grafo->Primeiro_Vertice == P_Grafo->Ultimo_Vertice);
}
////////////////////////////////////////
P_Vertice Busca_Vertice(int N_Vertice_Buscado,V_Grafo *P_Grafo)
{
    P_Vertice Temp_Vertice = P_Grafo->Primeiro_Vertice->Proximo_Vertice;
    while((Temp_Vertice != NULL) && (Temp_Vertice->N_Vertice != N_Vertice_Buscado))
    {
        Temp_Vertice = Temp_Vertice->Proximo_Vertice;
    }
    return (Temp_Vertice);
}
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
//OPERAÇÃO COM VERTICES
void Cria_Adj_Vazia(P_Vertice V_Vertice)
{
    V_Vertice->Primeira_Aresta = (P_Aresta)malloc(sizeof(struct T_Aresta));
    V_Vertice->Primeira_Aresta->N_Vertice = -1;
    V_Vertice->Primeira_Aresta->N_Distancia = -1;
    V_Vertice->Primeira_Aresta->Proxima_Aresta = NULL;
    V_Vertice->Ultima_Aresta = V_Vertice->Primeira_Aresta;
}
////////////////////////////////////////
int eh_Vertice_Adj_Vazia(P_Vertice V_Vertice)
{
    return (V_Vertice->Primeira_Aresta == V_Vertice->Ultima_Aresta);
}
////////////////////////////////////////
P_Aresta Busca_Aresta(int N_Aresta,P_Vertice V_Vertice)
{
    P_Aresta Temp_Aresta = V_Vertice->Primeira_Aresta->Proxima_Aresta;
    while((Temp_Aresta != NULL) && (Temp_Aresta->N_Vertice != N_Aresta))
    {
        Temp_Aresta = Temp_Aresta->Proxima_Aresta;
    }
    return(Temp_Aresta);
}
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
//Funções de Inserção
void Insere_Vertice(int N_Vertice,V_Grafo *P_Grafo)
{
    P_Vertice temp = P_Grafo->Primeiro_Vertice;
    while(temp->Proximo_Vertice != NULL)
    {
        temp = temp->Proximo_Vertice;
    }
    temp->Proximo_Vertice = (P_Vertice)malloc(sizeof(struct T_Grafo));
    temp->Proximo_Vertice->N_Vertice = N_Vertice;
    temp->Proximo_Vertice->N_Grau = 0;
    Cria_Adj_Vazia(temp);
    temp->Proximo_Vertice->Proximo_Vertice = P_Grafo->Ultimo_Vertice;

}
////////////////////////////////////////
void Insere_Aresta(int N_Aresta,int N_Destino,int N_Distancia,P_Vertice Vertice_Origem)
{
    Vertice_Origem->Ultima_Aresta->Proxima_Aresta = (P_Aresta)malloc(sizeof(struct T_Aresta));
    Vertice_Origem->Ultima_Aresta = Vertice_Origem->Ultima_Aresta->Proxima_Aresta;
    Vertice_Origem->Ultima_Aresta->N_Vertice = N_Destino;
    Vertice_Origem->Ultima_Aresta->N_Distancia =N_Distancia;
    Vertice_Origem->Ultima_Aresta->Proxima_Aresta = NULL;
    Vertice_Origem->N_Grau = Vertice_Origem->N_Grau + 1;
}
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
//Funções Para remoção de arestas
P_Aresta Busca_Aresta_Anterior(int N_Aresta,P_Vertice V_Vertice)
{
    P_Aresta Temp_Aresta_Anterior = V_Vertice->Primeira_Aresta;
    P_Aresta Temp_Aresta_Atual = V_Vertice->Primeira_Aresta->Proxima_Aresta;
    while((Temp_Aresta_Atual != NULL)&& (Temp_Aresta_Atual->N_Vertice != N_Aresta ))
    {
        Temp_Aresta_Anterior = Temp_Aresta_Atual;
        Temp_Aresta_Atual = Temp_Aresta_Atual->Proxima_Aresta;
    }
    return(Temp_Aresta_Anterior);
}
////////////////////////////////////////
void Remove_Aresta(P_Aresta V_Aresta,P_Vertice V_Vertice)
{
    P_Aresta Temp_Aresta = V_Aresta->Proxima_Aresta;
    V_Aresta->Proxima_Aresta = Temp_Aresta->Proxima_Aresta;
    if(V_Aresta->Proxima_Aresta == NULL)
    {
        V_Vertice->Ultima_Aresta = V_Aresta;
    }
    V_Vertice->N_Grau = V_Vertice->N_Grau -1;

    free(Temp_Aresta);
}
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
//Função para remoção de Vertices
P_Vertice Busca_Vertice_Anterior(int N_Vertice,V_Grafo *P_Grafo)
{
    P_Vertice Temp_Vertice_Anterior = P_Grafo->Primeiro_Vertice;
    P_Vertice Temp_Vertice_Atual = P_Grafo->Primeiro_Vertice->Proximo_Vertice;
    while((Temp_Vertice_Atual != NULL) && (Temp_Vertice_Atual->N_Vertice != N_Vertice))
    {
        Temp_Vertice_Anterior = Temp_Vertice_Atual;
        Temp_Vertice_Atual = Temp_Vertice_Atual->Proximo_Vertice;
    }
    return (Temp_Vertice_Anterior);
}
////////////////////////////////////////
void Remove_Vertice(P_Vertice V_Vertice,V_Grafo *P_Grafo)
{
    P_Vertice Vertice_Destino,Vertice_Origem = V_Vertice->Proximo_Vertice;
    P_Aresta Aresta2,Aresta1 = Vertice_Origem->Primeira_Aresta;
    while(!eh_Vertice_Adj_Vazia(Vertice_Origem))
    {
        Vertice_Destino = Busca_Vertice(Aresta1->Proxima_Aresta->N_Vertice,P_Grafo);
        Aresta2 = Busca_Aresta_Anterior(Vertice_Origem->N_Vertice,Vertice_Destino);
        Remove_Aresta(Aresta1,Vertice_Origem);
        Remove_Aresta(Aresta2,Vertice_Destino);
    }
    free(Vertice_Origem->Primeira_Aresta);

    V_Vertice->Proximo_Vertice = Vertice_Origem->Proximo_Vertice;
    if(V_Vertice->Proximo_Vertice == NULL)
    {
        P_Grafo->Ultimo_Vertice = V_Vertice;
    }
    free(Vertice_Origem);
}
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////


void imprime_vertices(V_Grafo *P_Grafo)
{
   P_Vertice temp = P_Grafo->Primeiro_Vertice;
    while(temp != NULL)
    {
        printf("%d",temp->N_Vertice);
        temp = temp->Proximo_Vertice;
    }
}


int main()
{
    V_Grafo *Grafo = (V_Grafo*)malloc(sizeof(V_Grafo));

    Ini_Grafo_Vazio(Grafo);
    Insere_Vertice(2,Grafo);
    Insere_Vertice(3,Grafo);
    Insere_Vertice(4,Grafo);



    imprime_vertices(Grafo);

    printf("\n%d",eh_Grafo_Vazio(Grafo));
    setlocale(LC_ALL,"Portuguese");
    return 0;
}















