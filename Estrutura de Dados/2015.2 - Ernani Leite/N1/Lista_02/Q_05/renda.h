#ifndef RENDA_H_INCLUDED
#define RENDA_H_INCLUDED

#define FALSE 0
#define TRUE !FALSE

#define SOLTEIRO 0
#define CASADO 1
#define VIUVO 2
#define DIVORCIADO 3


typedef struct renda{
    char sexo;
    int estadoCivil;
    int idade;
    float rendaAnual;
}Renda;

int retornaDimensao(const char *filename);
int recordVector(const char *filename, Renda *ptr, int dim);
int loadVector(const char *filename, Renda *ptr, int dim);
void lerLista(Renda *ptr, int dimensao);
void mostraLista(Renda *ptr, int dimensao);
void lerRenda(Renda *ptr);
void mostrarRenda(Renda *ptr);
void relatorio(Renda *ptr, int dimensao);

#endif // RENDA_H_INCLUDED
