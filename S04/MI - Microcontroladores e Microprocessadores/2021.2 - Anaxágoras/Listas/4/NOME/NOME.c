#include <p18f4520.h>

#define RS			LATCbits.LATC0
#define RW			LATCbits.LATC1
#define EN			LATCbits.LATC2
#define porta_lcd	LATD

void delay_s(void){
	unsigned int i;
	for(i=0; i<90000;i++) {}
}

void delay_ms(void){
	unsigned int i;
	for(i=0; i<300;i++) {}
}

//FUNÇÃO QUE RECEBE OS ESTADOS EQUIVALENTE AO COMANDO/INSTRUÇÃO DESEJADA

void envia_comando_lcd(unsigned char comando){
	
	RS=0;					//HABILITA RECEBER INSTRUÇÃO
	RW=0;		
	EN=0;					//ENABLE
	EN=1;
	porta_lcd = comando; 	//MANDA O COMANDO EM BINARIO PARA O LCD
	EN=0;
	delay_ms();
	
}

//FUNC QUE RECEBE CARACTERE OU NUMERO 0b EQUIVALENTE A CARACTERE NA TABELA ASCII E PLOTA NO LCD

void envia_dado_lcd(unsigned char dado){
	
	RS=1;					//HABILITA RECEBER DADO
	RW=0;
	EN=0;					//ENABLE
	EN=1;
	porta_lcd = dado;		//ENVIA O UPPER(4BITS) AO LCD, POIS É UMA ARQUITETURA DE 4 BITS, MANDO OS PRIMEIROS 4 BITS E DPS OS 4 BITS RESTANTES DO BYTE DO CARACTERES OU INSTRUÇÃO
	EN=0;					//ENABLE DE DESCIDA, MOSTRAR CARACTERE
	delay_ms();
	

	dado=(dado<<4); 		//ARRASTA O LOWERR(4BITS) PARA SER O UPPER(4BITS) DO BYTES, PREPARANDO PARA ENVIAR OS 4 BITS RESTANTES DO BYTE
	
	RS=1;					//HABILITA RECEBER DADO
	RW=0;		
	EN=0;					//ENABLE
	EN=1;
	porta_lcd = dado;		//PLOTA OS 4 ULTIMOS BITS DO BYTE QUE FORAM ARRASTADOS PARA SEREM OS 4 PRIMEIROS
	EN=0;
	delay_ms();
}

void inicializa_lcd(void){
	
	delay_ms();						//ESPERA A ESTABILIZAÇÃO DA ALIMENTAÇÃO DO LCD.
	envia_comando_lcd(0b00100000); 	//0010 UPPER(4BITS) NECESSARIO E LOWERR(4BITS) IRRELEVANTE	
	envia_comando_lcd(0b00100000);
	envia_comando_lcd(0b0000000);	//0bNFXXXFXX , N=LINE MODE, F=TAMANHO DA MATRIZ LCD
	
	delay_ms();
	
	envia_comando_lcd(0b00000000);	
	envia_comando_lcd(0b11100000);	//0b1DCBXXXX , D=DISPLAY ON/OFF, C=CURSOR ON/OFF, B=PISCAR
	
	delay_ms();						//DELAY NECESSARIO APOS CADA INSTRUÇÃO
			
	envia_comando_lcd(0b00000000);	//0b0000XXXX
	envia_comando_lcd(0b00010000);	//0b0001XXXX
	


}

main(){
	
	TRISD = 0B00001111;			//HABILITA AS PORTAS
	TRISC = 0B11111000;			//HABILITA AS PORTAS
	
	inicializa_lcd();			//INICIALIZA O LED COM OS DEVIDOS ESTADOS PARA ARQUITETURA DE 4 BITS
	
	while(1){
		
		
		envia_dado_lcd('J');	//ENVIA O CARACTERE 'J' PARA POSIÇÃO 0X80 DO LCD
		envia_dado_lcd('o');	//ENVIA O CARACTERE 'o' PARA POSIÇÃO 0X81 DO LCD
		envia_dado_lcd('a');	//ENVIA O CARACTERE 'a' PARA POSIÇÃO 0X82 DO LCD E ASSIM SUCESSIVAMENTE
		envia_dado_lcd('o');
		envia_dado_lcd(' ');
		envia_dado_lcd('B');
		envia_dado_lcd('r');
		envia_dado_lcd('u');
		envia_dado_lcd('n');
		envia_dado_lcd('o');
		envia_dado_lcd(' ');
		
		delay_s();
		
	}


}