#ifndef FILA_H
#define FILA_H



struct lista {

	int info;
	int saida;
	struct lista *proximo;

};
typedef struct lista Lista;


typedef struct fila {
	Lista*inicio;
	Lista*fim;

} Fila;



void printHora(int intTempo);
Fila* filaCria();
void filaInsere(Fila *fila, int entrada, int saida);
int filaVazia(Fila *fila);
float filaRetira(Fila *fila);
void filaImprime(Fila *fila);
void mostrarCliente(Lista *lista);

#endif /* FILA_H */
