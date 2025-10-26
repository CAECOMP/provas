#include <p18f4520.h>

#define RS			LATDbits.LATD0
#define EN1			LATDbits.LATD1
#define EN2			LATDbits.LATD2

unsigned char bits1;
unsigned char bits2;

#define porta_lcd	LATD

void delay_s(void){
	unsigned int i;
	for(i=0; i<90000;i++) {}
}

void delay_ms(void){
	unsigned int i;
	for(i=0; i<300;i++) {}
}

void envia_comando_lcd(unsigned char comando){
	
	RS=0;		//HABILITA RECEBER INSTRU플O
	EN1=0;		//ENABLE
	EN2=0;
	
	EN1=1;
	EN2=1;
	
	porta_lcd = comando; 	//ENVIO A INSTRU플O EM BINARIO PRA O LCD
	
	EN1=0;
	EN2=0;
	
	delay_ms();
	
}

//FUNC PARA ENVIAR CARATERES AO LCD 1

void envia_lcd1(unsigned char dado){
	
	bits1 = (dado>>4);//ARRASTO O UPPER(4BITS) PARA O LOWER(4BITS), 0b0000UPPER
	bits1 = ((bits1<<4)|00000001);//FACO O PROCESSO REVERSO PARA TER O LOWERR(4BITS) EM ESTADO 0
	//E FACO A OPERA플O LOGICA PARA MANTER O BITS DE ESCRITA JUNTO COM A PRIMEIRA PARTE DO BYTE(UPPER(4BITS))
	
	
	RS=1;		//HABILITA RECEBER DADO
	EN1=0;		//ENABLE
	EN1=1;
	
	porta_lcd = bits1;//ENVIO O UPPER(4BITS) PARA O LCD E DEIXO 0001 NO ESTADO DE ESCRITA
	
	EN1=0;
	delay_ms();
	

	RS=1;		//HABILITA RECEBER DADO
	EN1=0;		//ENABLE
	EN1=1;
	
	bits2 = ((dado<<4)|00000001); //TRANSFORMO O LOWERR(4BITS) DO DADO PARA UPPER(4BITS) PARA ENVIAR AO LCD

	porta_lcd = bits2; //ENVIO O UPPER(4BITS) E DEIXO NO ESTADO DE ESCRITO 0001;
	//CONSERVANDO RS=1, QUE SIGNIFICA RECEBER PARA ESCRITA
	EN1=0;
	delay_ms();
	
}

//FUNC SEMELHANTE A ANTERIOR MUDANDO SOMENTE O DADO E O ENABLE QUE SER� PARA O LCD 2

void envia_lcd2(unsigned char dado){
	
	bits1 = (dado>>4);
	bits1 = ((bits1<<4)|00000001);
	
	RS=1;		//HABILITA RECEBER DADO
	EN2=0;		//ENABLE
	EN2=1;
	
	porta_lcd = bits1;
	
	EN2=0;
	delay_ms();
	

	RS=1;		//HABILITA RECEBER DADO
	EN2=0;		//ENABLE
	EN2=1;
	
	bits2 = ((dado<<4)|00000001);

	porta_lcd = bits2;
	
	EN2=0;
	delay_ms();
	
}

void inicializa_lcd(void){
	
	delay_ms();		//ESPERA A ESTABILIZA플O DA ALIMENTA플O DO LCD.
	envia_comando_lcd(0b00100010); 		
	envia_comando_lcd(0b00100010);		
	envia_comando_lcd(0b00000010);
	
	delay_ms();
	
	envia_comando_lcd(0b00000010);
	envia_comando_lcd(0b11000010);
	
	delay_ms();	
			
	envia_comando_lcd(0b00000010);
	envia_comando_lcd(0b00010010);
	


}

main(){
	
	TRISD = 0B00000000;
	
	inicializa_lcd();	//CONFIGURA O LED E DEFINE SUA OPERA플O, DEIXANDO USUAL
	
	while(1){
		
		envia_lcd1('S');
		envia_lcd1('i');
		envia_lcd1('s');
		envia_lcd1('t');
		envia_lcd1('e');
		envia_lcd1('m');
		envia_lcd1('a');
		envia_lcd1(' ');
		envia_lcd1('S');
		envia_lcd1('o');
		envia_lcd1('l');
		envia_lcd1('a');
		envia_lcd1('r');
		
		
		envia_lcd2('S');
		envia_lcd2('o');
		envia_lcd2('l');
		envia_lcd2('a');
		envia_lcd2('r');
		envia_lcd2(' ');
		envia_lcd2('S');
		envia_lcd2('y');
		envia_lcd2('s');
		envia_lcd2('t');
		envia_lcd2('e');
		envia_lcd2('m');

		delay_s();
		
	}


}