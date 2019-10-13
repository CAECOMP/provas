

#include <stdio.h>

int main()
{
	int i;
	int v, d, u, aux;
	double tempo = 0;
	double velocidade;

	for(i = 0; i < 1024; i++){
		tempo += 0.001;
		velocidade = 0.004/(tempo/3600);
		v = (int)velocidade;
		d = 14;
		u = 14;
		if(v < 99){
			d = v/10;
			aux = d*10;
			u = v-aux;
		}
		printf("0x%x%x,\n", u, d);

	}

    return 0;
}

