# include <p18f4520.h>

# define PORT_LCD	 				PORTD
# define RS							PORTCbits.RC0
# define EN 						PORTCbits.RC2

unsigned long int ODOMETRO = 17339;
unsigned int ONI;
unsigned char OMU;
unsigned char OMD;
unsigned char OMC;
unsigned char OMUM;
unsigned char OMDM;
unsigned char OMCM;
unsigned int VELOCIDADE;
unsigned char VMU;
unsigned char VMD;
unsigned char VMC;
unsigned char RPMI; 
unsigned char RPM; 
unsigned char S = 0;
unsigned char DELTA_S = 0;

char ZAN[10] = {
	0b00110000, // 0
	0b00110001, // 1
	0b00110010, // 2
	0b00110011, // 3
	0b00110100, // 4
	0b00110101, // 5
	0b00110110, // 6
	0b00110111, // 7
	0b00111000, // 8
	0b00111001, // 9
};

void CONFIGURA_PIC();
void alta_prioridade(); 
void delay();
void INICIA_LCD(); 
void MOSTRA_VELOCIDADE(); 
void MOSTRA_RPM();	
void MOSTRA_ODOMETRO();	
void CALCULA_VELOCIDADE();	
void CALCULA_RPM(); 
void DISSECA_ODOMETRO(); 

void delay(void){
	int i = 0;
	for(i; i < 133; i++){}
}
void CONFIGURA_PIC(){
	ADCON1 = 0B00001111;
	TRISB = 0B11111111;
	TRISC = 0B11101000;
	TRISD = 0B00000000;

	T0CONbits.T08BIT = 1; 			
	T0CONbits.PSA = 0; 					
	T0CONbits.T0PS2 = 1;
	T0CONbits.T0PS1 = 1;
	T0CONbits.T0PS0 = 1;

	T0CONbits.T0CS = 0; 			
	T0CONbits.TMR0ON = 1; 			
	TMR0L = 0; 						
	INTCONbits.TMR0IF = 0; 
	INTCONbits.TMR0IE = 1;

	INTCONbits.INT0IE = 1; 
	INTCONbits.INT0IF = 0; 
	INTCON2bits.INTEDG0 = 1; 

	INTCON3bits.INT2IE = 1;
	INTCON3bits.INT2IF = 0; 
	INTCON2bits.INTEDG2 = 1;
	INTCONbits.GIE = 1;
}
void INICIA_LCD(){
	delay();
	RS = 0;
	EN = 0;
	PORT_LCD = 0b00111000;
	EN = 1;
	EN = 0;
	
	delay();
	PORT_LCD = 0b00001100;
	EN = 1;
	EN = 0;
	delay();
}
void MOSTRA_VELOCIDADE(){
	RS = 0;
	PORT_LCD = 0x80;
	EN = 1;
  	EN = 0;
	delay();
	RS = 1;
	PORT_LCD = ZAN[VMC];
	EN = 1;
	EN = 0;
	delay();
	PORT_LCD = ZAN[VMD];
	EN = 1;
	EN = 0;
	delay();
	
	RS = 1;
	PORT_LCD = ZAN[VMD]; 
	EN = 1;
	EN = 0;
	delay();
	RS = 1;
	PORT_LCD = 0X4B; 
	EN = 1;
	EN = 0;
	delay();
	RS = 1;
	PORT_LCD = 0X6D; 
	EN = 1;
	EN = 0;
	delay();	
	RS = 1;
	PORT_LCD = 0X2F; 
	EN = 1;
	EN = 0;
	delay();	
	RS = 1;
	PORT_LCD = 0X68; 
	EN = 1;
	EN = 0;
	delay();
}
void MOSTRA_ODOMETRO(){
	DISSECA_ODOMETRO();
	RS = 0;
	PORT_LCD = 0xC0; 
	EN = 1;
	EN = 0;
	delay();
	RS = 1;
	PORT_LCD = 0X4B; 
	EN = 1;
	EN = 0;
	delay();
	RS = 1;
	PORT_LCD = 0X6D; 
	EN = 1;
	EN = 0;
	delay();
	RS = 0;
	PORT_LCD = 0xC2;
	EN = 1;
	EN = 0;
	delay();
	
	RS = 1;
	PORT_LCD = ZAN[OMCM];
	EN = 1;
	EN = 0;
	delay();	
	RS = 1;
	PORT_LCD = ZAN[OMDM];
	EN = 1;
	EN = 0;
	delay();
	RS = 1;
	PORT_LCD = ZAN[OMUM];
	EN = 1;
	EN = 0;
	delay();
	RS = 1;
	PORT_LCD = ZAN[OMC];
	EN = 1;
	EN = 0;
	delay();	
	RS = 1;
	PORT_LCD = ZAN[OMD];
	EN = 1;
	EN = 0;
	delay();
	RS = 1;
	PORT_LCD = ZAN[OMU];
	EN = 1;
	EN = 0;
	delay();
}
void MOSTRA_RPM(){
	RS = 0;
	PORT_LCD = 0x89;
	EN = 1;
	EN = 0;
	delay();
	RS = 1;
	PORT_LCD = ZAN[RPM];
	EN = 1;
	EN = 0;
	delay();
	PORT_LCD = ZAN[0];
	EN = 1;
	EN = 0;
	delay();
	PORT_LCD = ZAN[0];
	EN = 1;
	EN = 0;
	delay();
	PORT_LCD = ZAN[0];
	EN = 1;
	EN = 0;
	delay();
	PORT_LCD = 0x72; 
	EN = 1;
	EN = 0;
	delay();
	PORT_LCD = 0x70; 
	EN = 1;
	EN = 0;
	delay();
	PORT_LCD = 0x6D; 
	EN = 1;
	EN = 0;
	delay();
}
void CALCULA_VELOCIDADE(){

	if(DELTA_S > 72){ 
		DELTA_S = 72;

		VELOCIDADE = DELTA_S * 3.6;
		DELTA_S = 0;
	
		VMU = VELOCIDADE % 10; // ok
		VMD = (((VELOCIDADE - VMU) / 10) % 10);
		VMC = (((VELOCIDADE - (VMU+(10 * VMD )))/100)%10);
	}
	else{
		VELOCIDADE = DELTA_S * 3.6;
		DELTA_S = 0;
	
		VMU = VELOCIDADE % 10; // ok
		VMD = (((VELOCIDADE - VMU) / 10) % 10);
		VMC = (((VELOCIDADE - (VMU+(10 * VMD )))/100)%10);
		}
}
void CALCULA_RPM(){

	if(RPMI > 9){
		RPM = 9;
		RPMI = 0;
	}
	else{
		if(RPM != RPMI){
			RPM = RPMI;
		}
		RPMI = 0;
	}
}
void DISSECA_ODOMETRO(){
	OMU = ODOMETRO%10;
	OMD = (((ODOMETRO - OMU)/10)%10);
	OMC = (((ODOMETRO - (OMU + (10 * OMD)))/100)%10);
	OMUM = (((((ODOMETRO - (OMU + (10 * OMD)))/100) - OMC)/10)%10);
	OMDM = (((((((ODOMETRO - (OMU + (10 * OMD)))/100) - OMC)/10) - OMUM)/10)%10);
	OMCM = ((((((((ODOMETRO - (OMU +(10 * OMD)))/100)- OMC)/10) - OMUM)/10) - OMDM)/10);
}
# pragma code vetor_alta = 0x0008
	void interrupt_alta(){
		_asm GOTO alta_prioridade _endasm
	}
# pragma code
# pragma interrupt alta_prioridade

void alta_prioridade(){
	if(INTCONbits.TMR0IF == 1){
		S++;
		INTCONbits.TMR0IF = 0;
		TMR0L = 0;
		if(S == 31){
			S = 0;
			CALCULA_VELOCIDADE();
			CALCULA_RPM();
		}
	}
	if(INTCONbits.INT0IF == 1){ 
		DELTA_S++; 
		ONI++; 
		if(ONI== 1000){
			ONI = 0;
			ODOMETRO++;
			DISSECA_ODOMETRO();
		}
		INTCONbits.INT0IF = 0;
	}
	if(INTCON3bits.INT2IF == 1){
		RPMI++;
		INTCON3bits.INT2IF = 0;
	}
}

main(){
	CONFIGURA_PIC();
	INICIA_LCD();
	MOSTRA_ODOMETRO();
	while(1){
		MOSTRA_VELOCIDADE();
		MOSTRA_RPM();
		MOSTRA_ODOMETRO();
	}
}