#include <p18f4520.h>

#define RS			LATCbits.LATC0	
#define EN			LATCbits.LATC1
#define porta_lcd	LATD

void delay_a(void){
	unsigned int i;
	for(i=0; i<50000;i++) {}
}

void delay_ms(void){
	unsigned int i;
	for(i=0; i<300;i++) {}
}

void delay_bateria(unsigned int n){
	unsigned int long j;
	for(j=0; j<n;j++){
		delay_ms();
	}
}




void envia_comando_lcd(unsigned char comando){
	
	RS=0;		//HABILITA RECEBER INSTRU플O
	EN=0;		//ENABLE
	EN=1;
	porta_lcd = comando;	//ENVIA COMANDO DE UM BYTE EM BINARIO AO LCD
	EN=0;
	delay_ms();
	
}

void envia_dado_lcd(unsigned char dado){
	
	RS=1;		//HABILITA RECEBER DADO
	EN=0;		//ENABLE
	EN=1;
	porta_lcd = dado;	//ENVIA O DADO DE UM BYTE EM BINARIO AO LCD
	EN=0;
	delay_ms();
}

//CONFIGURA O LCD EM UMA ARQUITETURA DE 8BITS

void inicializa_lcd(void){
	
	delay_ms();		//ESPERA A ESTABILIZA플O DA ALIMENTA플O DO LCD.
	envia_comando_lcd(0b00110100);//RS=0,RW=0,0b0011NFXX, N=LINE MODE, F=TAMANHO MATRIZ DISPLAY LCD	

	delay_ms();

	envia_comando_lcd(0b00001100);//0b00001DCB, D=DISPLAY ON/OFF, C=CURSO, B=PISCAR
	
	delay_ms();	


}

void cria_bateria_frames(){
	
//=============== BATERIA EM 0% ==================
		envia_comando_lcd(0x80);
		
		envia_dado_lcd(0b00000000);		//BUSCO O CARACTERE 0
		envia_comando_lcd(0b01000000);  //ACESSO A CG RAM DO CARAC 0
	
		envia_dado_lcd(0b00001110);		//ESCREVO OS BYTES NA CG RAM QUE IR홒 FORMAR O CARACTERES
		envia_dado_lcd(0b00011011);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00011111);
		
//=============== BATERIA EM 25% =================
		envia_comando_lcd(0x80);
		
		envia_dado_lcd(0b00000001);
		envia_comando_lcd(0b01001000);
		
		envia_dado_lcd(0b00001110);
		envia_dado_lcd(0b00011011);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);

//=============== BATERIA EM 50% =================
		envia_comando_lcd(0x81);
		
		envia_dado_lcd(0b00000010);
		envia_comando_lcd(0b01010000);
		
		envia_dado_lcd(0b00001110);
		envia_dado_lcd(0b00011011);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		
//================ BATERIA EM 75% =================		
		envia_comando_lcd(0x82);
		
		envia_dado_lcd(0b00000011);
		envia_comando_lcd(0b01011000);
		
		envia_dado_lcd(0b00001110);
		envia_dado_lcd(0b00011011);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		
//================= BATERIA EM 95% =================	
		envia_comando_lcd(0x83);
		
		envia_dado_lcd(0b00000100);
		envia_comando_lcd(0b01100000);
		
		envia_dado_lcd(0b00001110);
		envia_dado_lcd(0b00011011);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		
//================== BATERIA EM 100% ================		
		envia_comando_lcd(0x84);
		
		envia_dado_lcd(0b00000101);
		envia_comando_lcd(0b01101000);
		
		envia_dado_lcd(0b00001110);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011111);

}

//FUN플O QUE EXIBE O CONJUNTO DE CARACTERES(FRAMES) QUE IR홒 FORMAR
//A ANIMA플O NA POSI플O 0X8F DO LCD. 

void bateria_carregando(void){
	
	unsigned int i;
	for(i=0; i<10;i++){
		
		
		envia_comando_lcd(0x8F);		//CURSOR NA POSI플O 0X8F
		delay_ms();						//DELAY APOS INSTRU플O
		envia_dado_lcd(0b00000000);		//ENVIA O CARACTERE 0 CRIADO		
		delay_bateria(100);
		
		
		envia_comando_lcd(0x8F);
		delay_ms();
		envia_dado_lcd(0b00000010);
		delay_bateria(100);
			
		
		envia_comando_lcd(0x8F);
		delay_ms();
		envia_dado_lcd(0b00000011);
		delay_bateria(100);

	
		envia_comando_lcd(0x8F);
		delay_ms();
		envia_dado_lcd(0b00000100);
		delay_bateria(100);
	
		
		envia_comando_lcd(0x8F);
		delay_ms();
		envia_dado_lcd(0b00000101);
		delay_bateria(100);
	}
}

void imprime_carregando(void){
	envia_dado_lcd('B');
	envia_dado_lcd('a');
	envia_dado_lcd('t');
	envia_dado_lcd('e');
	envia_dado_lcd('r');
	envia_dado_lcd('i');
	envia_dado_lcd('a');

}

void limpa_lcd(void){
	envia_comando_lcd(0b00000001);
	delay_ms();
}

main(){
	
	TRISD = 0B00000000;
	TRISC = 0B11111000;
	
	inicializa_lcd();		//CONFIGURA O LED
	
	cria_bateria_frames();	//CRIA OS FRAMES, CADA CARACTERES ESPECIAL
	delay_ms();
	
	limpa_lcd();			//LIMPA O LCD APOS CRIAR OS CARACTERES
	
	while(1){

		imprime_carregando();	//IMPRIME O NOME BATERIA

		bateria_carregando();	//IMPRIME A ANIMA플O DA BATERIA CARREGANDO
		
		
		delay_a();
		
	}


}