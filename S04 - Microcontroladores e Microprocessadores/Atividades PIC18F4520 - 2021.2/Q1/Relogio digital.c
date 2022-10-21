#include <p18f4520.h>

#define BOTAO1 PORTAbits.RA0
#define BOTAO2 PORTAbits.RA1
#define BOTAO3 PORTAbits.RA2
#define BUZZER PORTEbits.RE0
#define BUZZEROFF PORTEbits.RE1


int i;
unsigned char contador = 0;
unsigned char dezenaS,dezenaM=0,dezenaH=0;
unsigned char unidadeS,unidadeM=0,unidadeH=0;
unsigned char aux_unidadeS=0,aux_dezenaS=0,aux_unidadeM,aux_dezenaM,aux_unidadeH,aux_dezenaH,alarme_ativado;
unsigned char pressionado;




void contador_decimal (void)

{
	
	if (BOTAO1 == 1 && pressionado == 0) unidadeM++;
	if (unidadeM>=10)
		 {
		 	unidadeM = 0;
				
		 	if(++dezenaM>=10)
		 	{
			dezenaM = 0;
			}
		}
	
		
	if (BOTAO2 == 1  && pressionado == 0) unidadeH++;
	if (unidadeH>=10)
		 {
		 	unidadeH = 0;
				
		 	if(++dezenaH>=10)
		 	{
			dezenaH = 0;
			}
		}
	

	if(++unidadeS>=10) //contador em base decimal 
	{
		unidadeS = 0;
		if (++dezenaS>=6)
		{
			dezenaS = 0;
			if(++unidadeM>=10)
			{
				unidadeM = 0;
				
				if(++dezenaM>=6)
				{
					dezenaM = 0;
					
				}
			}
		}
		
	}

}


void alarme (void)
{
	if (unidadeM ==aux_unidadeM && dezenaM == aux_dezenaM && unidadeH == aux_unidadeH && dezenaH == aux_dezenaH && alarme_ativado==1 && pressionado ==0)
	{
		BUZZER = 1;	
	}
	
	if (BUZZEROFF ==1)
	{
		BUZZER = 0;
	}	
}

void configurar_alarme (void)
{
	if (BOTAO1 == 1  && pressionado == 1) aux_unidadeM++;
	if (aux_unidadeM>=10)
		 {
		 	aux_unidadeM = 0;
				
		 	if(++aux_dezenaM>=10)
		 	{
			aux_dezenaM = 0;
			}
		}
	
		
	if (BOTAO2 == 1  && pressionado == 1) aux_unidadeH++;
	if (aux_unidadeH>=10)
		 {
		 	aux_unidadeH = 0;
				
		 	if(++aux_dezenaH>=10)
		 	{
			aux_dezenaH = 0;
			}
		}
		
	LATB = aux_dezenaH<<4|aux_unidadeH;
	LATC = aux_dezenaM<<4|aux_unidadeM;
	LATD = aux_dezenaS<<4|aux_unidadeS;
	
	alarme_ativado = 1;
	
}

void mostra_contador ()
{
	

	LATD = dezenaS<<4|unidadeS;
	LATC = dezenaM<<4|unidadeM;
	LATB = dezenaH<<4|unidadeH;
	
	
}




void delay_s (unsigned int segundos)

{
	unsigned short long int i;
	for (i=0;i<50000;i++) {}
}

void main (void)
{
	ADCON1 = 0b00001111;
	TRISA = 0xFF;
	TRISB = 0b00000000;
	TRISC = 0b00000000;
	TRISD = 0b00000000;
	TRISE = 0b00000000;

	
	while (1)
	{
		
		contador_decimal ();
		if(BOTAO3 ==1)
		{
			delay_s (1);
			delay_s (1);
			if(BOTAO3 == 1)
			{
				pressionado =1;
				
			}else pressionado = 0;
		}
		
		
		if( pressionado == 1)
		{
			configurar_alarme();	
		}else
			mostra_contador ();
			
		
		alarme ();
		delay_s (1);
	}
	
}