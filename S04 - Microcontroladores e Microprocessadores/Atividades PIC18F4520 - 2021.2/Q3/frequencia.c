#include <p18f4520.h>

#define sinal PORTDbits.RD0

unsigned int periodo;
unsigned int frequencia;
unsigned char dezena;
unsigned char unidade;

void delay_100us (void)
{ 
	unsigned char i;
	for (i=0;i<29;i++) {}
	i=0;
	i=0; //ajuste fino do delay

}

void mede_periodo (void)
{
	periodo = 0;
	while (sinal){}
	while (!sinal){} 
	
	while (sinal)
	{
		delay_100us ();
		periodo ++;
	}
	 
	while (!sinal)
	{
		delay_100us ();
		periodo++;
	}
}

void calcula_frequencia (void)
{
	frequencia = 1/(periodo*0.0001);
}

void mostra_frequencia (void)
{
	if(frequencia > 99 || frequencia<10) PORTC = 0xEE; // se maior do que 99  ou menor que 10 = ERRO
	
	else
	{
		dezena = frequencia/10;
		unidade = frequencia%10;
		PORTC = dezena<<4|unidade; // 4 primeiros pertencem a dezena 
	}
}

main ()

{
	TRISDbits.RD0 = 1;
	TRISC = 0b00000000;
	
	delay_100us ();
	
	while (1)
	{
		mede_periodo();
		calcula_frequencia();
		mostra_frequencia();
	}
}