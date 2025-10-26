#include <p18f4520.h>


#define LED		LATCbits.LATC0
#define TX PORTCbits.RC6
#define D PORTCbits.RC1

unsigned char periodo=20;
unsigned char inc_dec=1;

void delay_ms(int ms){
	unsigned int i;
	for(;ms>0;ms--){
		for(i=0;i<131;i++){
		}
	}
}
void delay_s(int s){
	int i;
	for(;s>0;s--){
		delay_ms(1001);
		for(i=0;i<60;i++){
		}
	}
}

void CONFIGURA_PWM(void){
	//CONFIGURA O PWM 1
	
	//SAIDA PWN
	
	TRISCbits.RC2 = 1;		//PINO DO PWN 1
	
	//TIMER2
	
	T2CONbits.T2CKPS1 = 1;		//PRESCALER DO TM2 1:16 (8us a 8MHz)
	T2CONbits.T2CKPS0 = 1;
	T2CONbits.TMR2ON = 1;		//LIGA TMR2
	
	//MODULO PWN
	
	PR2 = periodo;			//PERIODO DO PWN 8us x PR2 = 1Khz
	CCPR1L = periodo/2;		//duty cicle do PWN (min)
	
	CCP1CONbits.CCP1M3 = 1;	//MODO PWN 1
	CCP1CONbits.CCP1M2 = 1;
	CCP1CONbits.CCP1M1 = 0;
	CCP1CONbits.CCP1M0 = 0;
}

void ACIONA_ALARME(void){
	
	TRISCbits.RC2 = 0;
	
	while(1){
		PR2 = periodo;		//periodo do PWN
		CCPR1L = periodo/10;	//duty cycle do PWN
		delay_ms(7);
		
		if(inc_dec==1){
			periodo= periodo+10;
		}else{
		periodo=periodo-10;
		}
		
		if(periodo>240){
			inc_dec=0;
		}
		if(periodo<30){
			inc_dec=1;
		}
		if(D==1){
			TRISCbits.RC2 = 1;
			LED=~LED;
			break;
			
		}
	}
}

void CONFIGURA_PORTB(void){
	INTCONbits.RBIE = 1;	//HABILITA PORTB
	INTCONbits.RBIF = 0;	//FLAG
	
	INTCONbits.GIE = 1;		//HABILITA SISTEMA DE INTERRUPÇÃO
}

void T_UART(char dado){
	TXREG = dado;
	while(TXSTAbits.TRMT){};
	delay_ms(5);
}

void CONFIGURA_EUART(void){
	TRISCbits.RC6 = 0;
	TRISDbits.RD7 = 1;
	
	TXSTA = 0b00100100;
	RCSTA = 0b10010000;
	BAUDCON = 0b00000000;
	SPBRG = 207;
}

void ENVIA_LOG(char ZONA){
	T_UART('Z');
	T_UART('o');
	T_UART('n');
	T_UART('a');
	T_UART(' ');
	T_UART(ZONA);
	T_UART(' ');
	T_UART('(');
	T_UART('0');
	T_UART('0');
	T_UART(':');
	T_UART('0');
	T_UART('0');
	T_UART(':');
	T_UART('0');
	T_UART('0');
	T_UART(')');
	T_UART(' ');	
}

void CABECALHO_LOG(void){
	T_UART('L');
	T_UART('o');
	T_UART('g');
	T_UART(':');
	T_UART(' ');
}

void ALTA(void);

#pragma code ALTA_PRIORIDADE = 0x0008

void ALTA_INTERRUPCAO(void){
	_asm GOTO ALTA _endasm
}

#pragma code

#pragma interrupt ALTA

void ALTA(void){
	if(INTCONbits.RBIF){
		if(PORTBbits.RB4){
			LED = ~LED;
			ENVIA_LOG('1');
			ACIONA_ALARME();
			INTCONbits.RBIF=0;
		}
	if(INTCONbits.RBIF){
		if(PORTBbits.RB5){
			LED = ~LED;
			ENVIA_LOG('2');
			ACIONA_ALARME();
			INTCONbits.RBIF=0;
		}
	}
	if(INTCONbits.RBIF){
		if(PORTBbits.RB6){
			LED = ~LED;
			ENVIA_LOG('3');
			ACIONA_ALARME();
			INTCONbits.RBIF=0;
		}
	}
	if(INTCONbits.RBIF){
		if(PORTBbits.RB7){
			LED = ~LED;
			ENVIA_LOG('4');
			ACIONA_ALARME();
			INTCONbits.RBIF=0;
		}		
	}
	}
}

void main(){
	
	TRISC = 0B11111110;
	TRISB = 0B11111111;
	ADCON1 = 0B00001111;
	
	CONFIGURA_PORTB();
	CONFIGURA_PWM();
	CONFIGURA_EUART();
	
	CABECALHO_LOG();
	
	
	
	
	
	
	while(1){
	}
}