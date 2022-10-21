#include <p18f4520.h>

void delay_varredura(void)
{
	unsigned int i;
	for(i = 0; i < 800; i++);
}

	
unsigned int *ponteiro,*ponteiro2;
unsigned int mensagem_painel[] = {
0b11111111, //<-ponteiro
0b11111111,	
0b11111111,	
0b11111111,	
0b11111111,	
0b11111111,	
0b11111111,	
0b11111111,	
0b11111111,	//<-ponteiro2
0b11111111,	//ponteiro2+1
0b11111111,	//ponteiro2+2
0b11111111,	//ponteiro2+3
0b11111111,	//ponteiro2+4
0b11111111,	//ponteiro2+5
0b11111111,	//ponteiro2+6
0b11111111,	//ponteiro2+7

0b00000001,//M
0b11111011,
0b11110111,
0b11111011,
0b00000001,
0b11111111,//espaço
0b00000011,//A
0b11101101,
0b11101101,
0b00000001,
0b11111111,//espaço
0b11111111,//espaço
0b11111101,//T
0b11111101,
0b00000001,
0b11111101,
0b11111101,
0b11111111,//espaço
0b00000001,//E
0b01101101,
0b01101101,
0b01101101,
0b11111111,//espaço
0b11111111,//espaço
0b10000001,//U
0b01111111,
0b01111111,
0b10000001,
0b11111111,//espaço
0b11111111,//espaço
0b01110011,//S
0b01101101,
0b01101101,
0b10011101,
0b11111111,//espaço
0b11111111,//espaço


0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,
0b11111111,




};
char contagem[]={
0b00000001,
0b00000010,
0b00000100,
0b00001000,
0b00010000,
0b00100000,
0b01000000,
0b10000000,
};
void mostra_nome(void){
		unsigned int aux=1;
		unsigned char mascara;
		PORTB = 0b11111111;
		PORTC = 0b11111111;
		ponteiro= &mensagem_painel[0];
		ponteiro2= &mensagem_painel[8];
		while(ponteiro2<&mensagem_painel[67]){
			if(aux==9){
        		ponteiro2=ponteiro2-7;
        		ponteiro=ponteiro-7;
        		aux=1;
    		} 
    		PORTC = *ponteiro;
    		PORTB = *ponteiro2;
    		ponteiro2=ponteiro2+1;
			ponteiro=ponteiro+1;	
			delay_varredura();
			
			if(PORTD == 0b00000000){
				mascara=0b00000001;
				PORTD=mascara;
			}
			else {
				mascara=mascara<<1;
				PORTD=mascara;
				aux++;
			}
		}
}
void main(void)
{
	TRISB = 0; 	//varredura painel 1 e 2
	TRISC = 0; 	//barramento painel 1
	TRISD = 0; 	//barramento painel 2
	ADCON1 = 0b00001111;
	while(1)
	{
		mostra_nome();
	}	
}
