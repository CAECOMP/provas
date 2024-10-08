#ifndef FERIADO_H
#define FERIADO_H


#define CAMOCIM 1
#define MORRO_BRANCO 2
#define ARACATI 3
#define GUARAMIRANGA 4
#define OUTROS_LOCAIS 5

#define AUTOMOVEL 1
#define CAMINHAO 2
#define ONIBUS 3
#define OUTRO_VEICULO 4


typedef struct feriado{
    int destino;
    int veiculo;
}Feriado;


void lerLista(Feriado *ptr, int dimensao);
void lerFeriado(Feriado *ptr);
void relatorio(Feriado *ptr, int dimensao);

#endif // FERIADO_H_INCLUDED
