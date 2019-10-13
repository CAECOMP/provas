#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "fila.h"


int main() {



	Fila *fila;
	Fila *atendidos;
	int valor;
	int hora = 3600;
	int i, clientesAtendidos, numeroDeServidores, j;
	int variacao;
	float tempoMedioDeEspera;

	srand((unsigned)time(NULL));

	fila = filaCria();
	atendidos = filaCria();
	tempoMedioDeEspera = 0;
	clientesAtendidos = 0;
	printf("Digite o número de servidores: \n");
	scanf("%d", &numeroDeServidores);
	variacao = 0;

	for (i = 0; i < hora; i++) {
		if (i <= 900) {
			//Chega gente de 20 em 20 segundos
			//Não começou a distribuição.



			if (!(i % 20)) {
				//Variar entre -5 e +5
				variacao = (-5+rand()%10);
				filaInsere(fila, (i+variacao), 0);
			}
		} else if (i > 900 && i <= 1500) {
			//Entra gente de 10 em 10 segundos.
			//Ainda não começou a distribuição.
			if (!(i % 10)) {
				//Variar entre -6 e +6
				variacao = (-6+rand()%12);

				filaInsere(fila, (i+variacao), 0);

			}

		} else if (i > 1500 && i <= 1800) {
			//Entra gente de 5 em 5 segundos.
			if (!(i % 5)) {
				//Variar entre -3 e +3
				variacao = (-3+rand()%6);
				filaInsere(fila, (i+variacao), 0);

			}
			//Não começou a distribuição.

		} else if (i > 1800 && i <= 2400) {


			//Entra gente de 10 em 10 segundos na fila.
			if (!(i % 10)) {
				//Variar entre -8 e +8
				variacao = (-8+rand()%16);
				filaInsere(fila, (i+variacao), 0);
			}
			//Inicia-se a entrega do lanche. de 4 em 4 segundos cada servidor
			if (!(i % 4)) {

				for (j = 0; j < numeroDeServidores; j++) {
					if (!filaVazia(fila)) {
						valor = filaRetira(fila);
						filaInsere(atendidos, valor, (i-valor));
						valor = i - valor;
						tempoMedioDeEspera += valor;
						clientesAtendidos++;


					}
				}
			}

		} else if (i > (1800 + 600) && i <= (1800 + 1200)) {
			//Entre 10 e 20 minutos.
			//Entra gente de 20 em 20 segundos.

			if (!(i % 20)) {
				//Variar entre -15 e +15
				variacao = (-15+rand()%30);

				filaInsere(fila, (i+variacao), 0);

			}
			if (!(i % 4)) {

				for (j = 0; j < numeroDeServidores; j++) {
					if (!filaVazia(fila)) {
						valor = filaRetira(fila);
						filaInsere(atendidos, valor, (i-valor));
						valor = i - valor;
						tempoMedioDeEspera += valor;
						clientesAtendidos++;

					}
				}
			}
		} else if (i > (1800 + 1200) && i <= (1800 + 1800)) {
			//entra gente de 30 em 30 segundos.
			if (!(i % 30)) {
				//Variar entre -5 e +5
				variacao = (-5+rand()%10);
				filaInsere(fila, (i+variacao), 0);

			}
			if (!(i % 4)) {

				for (j = 0; j < numeroDeServidores; j++) {
					if (!filaVazia(fila)) {
						valor = filaRetira(fila);
						filaInsere(atendidos, valor, (i-valor));
						valor = i - valor;
						tempoMedioDeEspera += valor;
						clientesAtendidos++;

					}
				}
			}
		}

	}
	printf("Acabou!!!\n");
	printf("Tempo do termino: ");
	printHora(i);
	printf("\n");
	tempoMedioDeEspera = (float) tempoMedioDeEspera / (float) clientesAtendidos;
	printf("Tempo medio de espera: ");
	printHora((int) tempoMedioDeEspera);
	printf("\n");
	printf("Total de clientes atendidos %d\n", clientesAtendidos);
	printf("\n\n\n");
	printf("Para justificar os dados pode verificar o tempo de atendimento de cada um:\n");
	filaImprime(atendidos);
	return 0;

}

