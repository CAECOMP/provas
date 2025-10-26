# include <p18f4520.h>

# define tx PORTCbits.RC0
# define rx PORTCbits.RC2

char j = 7;

char dados[8] = {0, 0, 0, 0, 0, 0, 0, 0};


void delay_1200bps(){
	unsigned int i;
	for (i = 0; i < 109; i++){}
}

void delay_meiobit(){ 
	unsigned int i;
	for(i = 0; i < 53; i++){}
}

void transmite_serial(){
	tx = 1;
	delay_1200bps(); // repouso
	tx = 0;
	delay_1200bps();// start

	for(j;j>=0;j--){
		tx = dados[j];
		delay_1200bps();
	}
	j = 7;

	tx = 1;
	delay_1200bps();
}

void recebe(){
	delay_meiobit();
	while(rx != 1){
		delay_1200bps();
		for(j;j>=0;j--){
			dados[j] = rx;
			delay_1200bps(); 
		}
		j = 7;
		delay_1200bps();
		transmite_serial();
		
	}

}

main(){
	TRISCbits.RC0 = 0; // saída.
	TRISCbits.RC2 = 1; // entrada.	
	
	

	while(1){
		recebe();
	}
}