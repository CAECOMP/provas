#include <p18f4520.h>

#define sinal PORTDbits.RD0
 
unsigned int periodo;
unsigned int f;
unsigned char dezena;
unsigned char unidade;


//ERRO DE 1% NA AFERIÇÃO

void calcula_frequencia(void){
	f = 1/(periodo*0.0001);
}

void mostra_frequencia(void){
	unsigned char BCD;
	if(f<5 || f>99){
		BCD = 0b11101110;
		LATC = BCD;
	}
	else{
		int u = f %10;
		int d = ((f-u)/10)%10;
		dezena = d;
		unidade = u;
		BCD =(unidade<<4|dezena);
		LATC = BCD;
	}
}

void delay_100us(void){

	unsigned char i;
	for(i=0;i<29;i++){}
}
int mede_periodo(void){

	periodo = 0;
	while(sinal){};		//ESEPERA SINAL DESCER
	while(!sinal){};		//ESEPERA SINAL SUBIR

	while(sinal){
		delay_100us();
		periodo++;
	}
	while(!sinal){
		delay_100us();
		periodo++;
	}	

}

main(){
	//CONFIGURAÇÕES DO SISTEMA

	TRISDbits.RD0 = 1;  //SINAL DE FREQUENCIA
	TRISC = 0b00000000; //MOSTRAR

	delay_100us();

//SISTEMA OPERACIONAL

while(1){
		mostra_frequencia();
		mede_periodo();
		calcula_frequencia();

	}
}