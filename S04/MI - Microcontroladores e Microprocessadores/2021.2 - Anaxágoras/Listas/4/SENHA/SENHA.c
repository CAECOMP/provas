#include <p18f4520.h>

#define RS			LATCbits.LATC0	
#define EN			LATCbits.LATC1
#define VERDE		LATCbits.LATC2
#define VERMELHO	LATCbits.LATC3
#define porta_lcd	LATD


#define l1 PORTBbits.RB3
#define l2 PORTBbits.RB2
#define l3 PORTBbits.RB1
#define l4 PORTBbits.RB0

#define c1 LATBbits.LATB4
#define c2 LATBbits.LATB5
#define c3 LATBbits.LATB6

unsigned char posicao=0XC0;				//PRIMEIRA POSIÇÃO DA SEGUNDA LINHA DO LCD

unsigned int tecla,num, ms, cs, ds, us;				//VARS PARA MANIPULAR OS NUMERO INSERIDOS
			


void delay_ms(void){
	unsigned int i;
	for(i=0; i<300;i++){}
}

void delay(void){
	unsigned int i;
	for(i=0;i<9000;i++){}
}

void delay_set(unsigned int n){
	unsigned int long j;
	for(j=0; j<n;j++){
		delay();
	}
}

void envia_comando_lcd_inicia(unsigned char comando){
	
	RS=0;		//HABILITA RECEBER INSTRUÇÃO
	EN=0;		//ENABLE
	EN=1;
	porta_lcd = comando;
	EN=0;
	delay_ms();
	}

void envia_comando_lcd(unsigned char comando){
	
	RS=0;		//HABILITA RECEBER INSTRUÇÃO
	EN=0;		//ENABLE
	EN=1;
	porta_lcd = comando;
	EN=0;
	delay_ms();
	
	comando=(comando<<4);
	
	RS=0;		//HABILITA RECEBER INSTRUÇÃO
	EN=0;		//ENABLE
	EN=1;
	porta_lcd = comando;
	EN=0;
	delay_ms();

}

void envia_dado_lcd(unsigned char dado){
	
	RS=1;					//HABILITA RECEBER DADO
	//RW=0;
	EN=0;					//ENABLE
	EN=1;
	porta_lcd = dado;		//ENVIA O UPPER(4BITS) AO LCD, POIS É UMA ARQUITETURA DE 4 BITS, MANDO OS PRIMEIROS 4 BITS E DPS OS 4 BITS RESTANTES DO BYTE DO CARACTERES OU INSTRUÇÃO
	EN=0;					//ENABLE DE DESCIDA, MOSTRAR CARACTERE
	delay_ms();
	

	dado=(dado<<4); 		//ARRASTA O LOWERR(4BITS) PARA SER O UPPER(4BITS) DO BYTES, PREPARANDO PARA ENVIAR OS 4 BITS RESTANTES DO BYTE
	
	RS=1;					//HABILITA RECEBER DADO
	//RW=0;		
	EN=0;					//ENABLE
	EN=1;
	porta_lcd = dado;		//PLOTA OS 4 ULTIMOS BITS DO BYTE QUE FORAM ARRASTADOS PARA SEREM OS 4 PRIMEIROS
	EN=0;
	delay_ms();
	
}

void inicializa_lcd(void){
	
	delay_ms();						//ESPERA A ESTABILIZAÇÃO DA ALIMENTAÇÃO DO LCD.
	envia_comando_lcd_inicia(0X20); //EM BINARIO=00100000	0010 UPPER(4BITS) NECESSARIO E LOWERR(4BITS) IRRELEVANTE	
	envia_comando_lcd_inicia(0X20);
	envia_comando_lcd_inicia(0X80);	//0bNFXXXFXX , N=LINE MODE, F=TAMANHO DA MATRIZ LCD
	
	delay_ms();
	
	envia_comando_lcd_inicia(0X0);	
	envia_comando_lcd_inicia(0XE0);	//0b1DCBXXXX , D=DISPLAY ON/OFF, C=CURSOR ON/OFF, B=PISCAR
	
	delay_ms();						//DELAY NECESSARIO APOS CADA INSTRUÇÃO
			


}

void cria_cadeados(void){
	
//=============== FECHADO ==================
		envia_comando_lcd(0X80);
		
		envia_dado_lcd(0X0);	
		envia_comando_lcd(0X40);
	
		envia_dado_lcd(0b00001110);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00010001);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011011);
		envia_dado_lcd(0b00011011);
		envia_dado_lcd(0b00011111);
		
//=============== ABERTO =================
		envia_comando_lcd(0X80);
		
		envia_dado_lcd(0X1);
		envia_comando_lcd(0X48);
		
		envia_dado_lcd(0b00001110);
		envia_dado_lcd(0b00000001);
		envia_dado_lcd(0b00000001);
		envia_dado_lcd(0b00011111);
		envia_dado_lcd(0b00011011);
		envia_dado_lcd(0b00011011);
		envia_dado_lcd(0b00011111);

}



void cadeado_fechado(void){
	
		envia_comando_lcd(0X8F);
		delay_ms();
		envia_dado_lcd(0X0);		
}

void cadeado_aberto(void){
	
		envia_comando_lcd(0X8F);
		delay_ms();
		envia_dado_lcd(0X1);				
}

void limpa_lcd(void){
	envia_comando_lcd_inicia(0X0);	//0b0000XXXX
	envia_comando_lcd_inicia(0X10);	//0b0001XXXX
	delay_ms();
}

int varre_teclado(void){
	
	c1 = 0; 	//HABILITA SOMENTE COLUNA C1
	c2 = 1;
	c3 = 1;
	
	if(!l1){
		while(!l1){};	//ESPERA SOLTAR TECLA
		envia_dado_lcd('1');
		delay();
		return 11;		//RETORNA O VALOR CORRESPONDENTE EM ASCII
	}
	
	if(!l2){
		while(!l2){};
		envia_dado_lcd('4');
		delay();
		return 4;
	}
	
	if(!l3){
		while(!l3){};
		envia_dado_lcd('7');
		delay();
		return 7;
	}
	
	c1 = 1;
	c2 = 0; 	//HABILITA SOMENTE COLUNA C2
	c3 = 1;
	
	if(!l1){
		while(!l1){};	//ESPERA SOLTAR TECLA
		envia_dado_lcd('2');
		delay();
		return 2;
	}
	
	if(!l2){
		while(!l2){};
		envia_dado_lcd('5');
		delay();
		return 5;
	}
	
	if(!l3){
		while(!l3){};
		envia_dado_lcd('8');
		delay();
		return 8;
	}
	if(!l4){
		while(!l4){};
		envia_dado_lcd('0');
		delay();
		return 10;
	}
	c1 = 1;
	c2 = 1;
	c3 = 0; 	//HABILITA SOMENTE COLUNA C3
	
	if(!l1){
		while(!l1){};	//ESPERA SOLTAR TECLA
		envia_dado_lcd('3');
		delay();
		return 3;
	}
	
	if(!l2){
		while(!l2){};
		envia_dado_lcd('6');
		delay();
		return 6;
	}
	
	if(!l3){
		while(!l3){};
		envia_dado_lcd('9');
		delay();
		return 9;
	}
	
	if(!l4){				//SE O # FOR PRESIONADO
		while(!l4){};		//ESPERA PARAR DE CLICAR
					//SAIDA=1; PARA SAIR DO LOOP DE AJUSTE DE HORAS
	}	return 0;
	
	c1=1;
	c2=1;
	c3=1;
	
	return 0;
}

int insere_senha(void){
		int num;
				
		while(1){			//ENQUANTO # NÃO FOR CLICADO, INSERIR HORARIO
					
		tecla = varre_teclado();	//ATRIBUI A TECLA CLICADA A VAR TECLA.	
		if(tecla){
			num=tecla;
			break;				
		}
		delay();	
	}
	
	if(num==11){					//CONTROLE PARA O CARACTERE 01, PARA NÃO IMPRIMIR CADEADO
		num=1;
	}
	
	delay();						
	envia_comando_lcd(posicao);		//2° LINHA
	delay_ms();
	envia_dado_lcd('*');			//SOBESCREVE ASTERISCO NO NUMERO DIGITADO, PARA MANTER A SEGURANÇA DA SENHA.
	tecla=0;						//RESETA VAR TECLA
	
	posicao++;						//CAMINHA POSIÇÃO NA SEGUNDA LINHA
	if(num==10){					//CONTROLE PARO RETURN 0;
		num=0;						
	}
	return num;						//RETORNA A TECLA DIGITADA ATRAVES DA VAR NUM.
}


//FUNC PARA IMPRIMIR: "INSERIR SENHA: " NA 1° LINHA DO LCD 

void imprime_inserir_senha(void){
	
	envia_comando_lcd(0X80);		//CURSO NA PRIMEIRA POSIÇÃO DO LCD
	envia_dado_lcd('I');
	envia_dado_lcd('n');
	envia_dado_lcd('s');
	envia_dado_lcd('i');
	envia_dado_lcd('r');
	envia_dado_lcd('a');
	envia_dado_lcd(' ');
	envia_dado_lcd('S');
	envia_dado_lcd('e');
	envia_dado_lcd('n');
	envia_dado_lcd('h');
	envia_dado_lcd('a');
	envia_dado_lcd(':');
}

//FUNC PARA IMPRIMIR QUE A PORTA FOI LIBERADA.

void imprime_liberada(void){
	envia_comando_lcd(0X80);
	
	envia_dado_lcd('P');
	envia_dado_lcd('o');
	envia_dado_lcd('r');
	envia_dado_lcd('t');
	envia_dado_lcd('a');
	
	envia_dado_lcd(' ');

	envia_dado_lcd('L');
	envia_dado_lcd('I');
	envia_dado_lcd('B');
	envia_dado_lcd('E');
	envia_dado_lcd('R');
	envia_dado_lcd('A');
	envia_dado_lcd('D');
	envia_dado_lcd('A');
}

//FUNC PARA EXPRESSAR QUE A SENHA ESTÁ INCORRETA.

void imprime_negado(void){
	envia_comando_lcd(0X80);
	
	envia_dado_lcd('A');
	envia_dado_lcd('c');
	envia_dado_lcd('e');
	envia_dado_lcd('s');
	envia_dado_lcd('s');
	envia_dado_lcd('o');
	
	envia_dado_lcd(' ');
	
	envia_dado_lcd('N');
	envia_dado_lcd('E');
	envia_dado_lcd('G');
	envia_dado_lcd('A');
	envia_dado_lcd('D');
	envia_dado_lcd('O');

}

//FUNC PARA VERIFICAR A SENHA INSERIDA

void verifica_senha(void){
	limpa_lcd();
	if(ms==1 && cs==2 && ds==3 && us==4){	//SENHA=1234, SE SIM:
		VERDE=1;
		VERMELHO=0;
		imprime_liberada();					//IMPRIME PORTA LIBERADA
		cadeado_aberto();					//IMPRIME CADEADO ABERTO
	}else{									//SE NÃO:
	VERDE=0;
	VERMELHO=1;	
	imprime_negado();						//ACESSO NEGADO
	cadeado_fechado();						//CADEADO PERMANECE FECHADO
	}
}


void main(void){
	
	TRISD = 0X0;
	TRISC = 0XF0;
	ADCON1 = 0XF;
	TRISB = 0X8F;
	
	inicializa_lcd();

	delay_ms();
	
	cria_cadeados();

	limpa_lcd();
	
	
	while(1){
		
		VERDE = VERMELHO = 0;
		
		imprime_inserir_senha();
		cadeado_fechado();
		
		envia_comando_lcd(0XC0);
	
		ms = insere_senha();
		cs = insere_senha();
		ds = insere_senha();
		us = insere_senha();
		
	
		verifica_senha();
		
		delay_set(55);
		
		limpa_lcd();
		
		posicao=0xC0;
		
	}


}