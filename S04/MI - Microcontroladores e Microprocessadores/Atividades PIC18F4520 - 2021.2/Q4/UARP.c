#include <p18f4520.h>

#define tx PORTCbits.RC0
#define rx PORTCbits.RC1

void delay_1200bps (void)
{
	unsigned int i;
	for(i=0;i<108;i++) {}
}

void delay_meiobit (void)
{
	unsigned int i;
	for(i=0;i<53;i++) {}
}


void transmite_serial (char dado)
{
	int mascara = 0x01;
	unsigned int i=0;
	
	tx = 1;
	delay_1200bps ();	//repouso 	
	tx = 0;
	delay_1200bps ();	//start
	
	for (i = 0;i <=7;i++)
	{
		tx = (dado & mascara) ;
		delay_1200bps ();
		dado = dado >>1;
	}
	
	tx = 1;
	delay_1200bps();
}

char recebe_serial (void)
{
	char dado = 0x00;
	char mascara = 0x01;
	char estado_de_rx = 0x00;
	int i;
	
	delay_1200bps();
	delay_meiobit();
	
	while(rx);
	
	delay_1200bps();
	
	for(i = 0; i < 7; i++)
	{
		estado_de_rx = rx<<i;
		dado = dado + (estado_de_rx & mascara);
		mascara = mascara<<1;
		delay_1200bps();
	}
	
	return dado;
}

main()
{
	TRISCbits.RC0 = 0;    //tx -> saida
	TRISCbits.RC1 = 1;    //rx -> entrada

	
	while(1)
	{
		transmite_serial(recebe_serial());
	}
}	