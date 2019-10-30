#ifndef CAIXA_H_INCLUDED
#define CAIXA_H_INCLUDED
#define FALSE 0
#define TRUE !FALSE

typedef struct data{
    int dia;
    int mes;
    int ano;

}Data;


typedef struct caixa{
    char situacao;
    Data data;
    char tipo;//Despesa D, Receita R
    float valor;
}Caixa;



void lerCaixa(Caixa *ptr);
void mostraLista(Caixa *ptr, int dimensao);
void mostrarCaixa(Caixa *ptr);
void lerLista(Caixa *ptr, int dimensao);
void relatorio(Caixa *ptr, int dimensao);
int retornaDimensao(const char *filename);
int loadVector(const char *filename, Caixa *ptr, int dim);
int recordVector(const char *filename, Caixa *ptr, int dim);
#endif // CAIXA_H_INCLUDED
