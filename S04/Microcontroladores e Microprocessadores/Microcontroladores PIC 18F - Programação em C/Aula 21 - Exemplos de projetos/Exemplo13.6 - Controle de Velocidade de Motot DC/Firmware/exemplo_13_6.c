#include <p18f4520.h>
#include <stdio.h>
#include "pic_simb.h"
#include "meu_lcd16x2.c"

#pragma config OSC = XT, WDT = OFF, MCLRE = ON
#pragma config DEBUG = ON, LVP = OFF, PWRT = ON, BOREN = OFF

#define S1	PORTBbits.RB0	/* Decrementa rotação */
#define S2	PORTBbits.RB1	/* Incrementa rotação */
#define NUM_PAS	7

unsigned char str[6], tmr1tmp;
unsigned char timer_atualiza_lcd;
unsigned int rpm, rpm_alvo, pwm;
struct
{
	char atualiza_rpm :1;
} flags;

// Interrupção do TMR0: uma interrupção aproximadamente a cada 120ms
#pragma interrupt TMR0_ISR
void TMR0_ISR(void)
{
	INTCONbits.TMR0IF = 0;	// apaga flag de interrupção
	// 469 contagens para uma interrupção
	TMR0H = 0xFE;
	TMR0L = 0x2B;
	tmr1tmp = TMR1L;				// armazena a contagem do TMR1
	TMR1L = 0;
	flags.atualiza_rpm = 1;
	if (timer_atualiza_lcd) timer_atualiza_lcd--;
}

#pragma code isr_baixa = 0x0008
void ISR_baixa_prioridade(void)
{
	if (INTCONbits.TMR0IF) _asm BRA TMR0_ISR _endasm
}
#pragma code

void bin16_to_string(unsigned int val, char string[])
{
	unsigned int subtrator = 10000;
	unsigned char indice=0, elim_zero=1;
	while (indice<5) string[indice++]=0;
	indice = 0;
	while (val)
	{
		if (val>=subtrator)
		{
			val -= subtrator;
			string[indice]++;
		} else
		{
			subtrator /= 10;			
			indice++;
		}
	}
	indice=0;
	while (indice<4)
	{
		if (elim_zero && !string[indice]) string[indice++]=' ';
		else
		{
			string[indice++]+='0';
			elim_zero = 0;
		}
	}
	string[4]+='0';
	string[5]=0;
}

void atualiza_LCD(void)
{
	LCD_pos_xy(0,0); 	// posiciona o cursor na primeira coluna da primeira linha
	LCD_write_string_rom("RPM = "); // velocidade atual do motor
	bin16_to_string(rpm,str);
	LCD_write_string(str);
	LCD_pos_xy(0,1);	// posiciona o cursor na primeira coluna da segunda linha
	LCD_write_string_rom("Alvo= "); // velocidade desejada do motor
	bin16_to_string(rpm_alvo,str);
	LCD_write_string(str);
}

void atualiza_PWM(unsigned int val)
{
	CCPR2L = val>>2;
	CCP2CONbits.DC2B1 = val & 0x02;
	CCP2CONbits.DC2B0 = val & 0x01;
}

void controle(void)
{
	unsigned int dif;
	if (rpm<rpm_alvo)
	{
		dif = rpm_alvo - rpm;
		if (dif>750) pwm+=50;
			else if (dif>500) pwm+=20;
				else if (dif>250) pwm+=10; else pwm++;
		if (pwm>1023) pwm=1023;
	}
	if (rpm>rpm_alvo)
	{
		dif = rpm - rpm_alvo;
		if (dif>750) pwm-=50;
			else if (dif>500) pwm-=20;
				else if (dif>250) pwm-=10; else pwm--;		
		if (pwm>1023) pwm=0;
	}
	atualiza_PWM(pwm);
}

void MCU_init(void)
{
	LATA = LATB = LATD = 0;
	TRISA = 0x02;		// pino 2 da porta A como entrada
	TRISB = 0x0F;		// RB0 a RB3 como entradas, RB4 a RB7 como saídas
	TRISC = 0x01;		// RC0 como entrada
	TRISD = 0;			// RD0 a RD7 como saídas
	CMCON = 0x07;		// desliga pinos analógicos do comparador
	ADCON1 = 0x0F;		// Desliga entradas analógicas do ADC
	T2CON = bTMR2ON; 	// liga o timer 2 (prescaler = 1)
	CCP2CON = 0x0C;	// CCP2 no modo PWM
	CCPR2L = 0x7F;	// ciclo ativo = metade do período (PR2=255, valor default)
	T1CON = bT1CLK_EXT | bTMR1ON;
	TMR1L = TMR1H = 0;
	T0CON = bTMR0ON | bT0CLK_PRE256;
	TMR0H = 0xFE;
	TMR0L = 0x2B;	
	INTCON = bGIE | bTMR0IE;
	LCD_init(DISPLAY_8X5|_2_LINES,DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
	LCD_write_char('\f'); // apaga o display
	timer_atualiza_lcd = 3;
}

void calcula_RPM(void)
{
	rpm = (int)tmr1tmp*72;
	controle();
	flags.atualiza_rpm = 0;
}

void main(void)
{
	char aux;
	MCU_init();
	rpm = 0;
	atualiza_LCD();
	rpm_alvo=0;
	pwm = 0;
	while(1)
	{
		if (!timer_atualiza_lcd) 
		{
			atualiza_LCD();
			timer_atualiza_lcd = 3;
			if (!S1) rpm_alvo += 50;
			if (rpm_alvo>5000) rpm_alvo=5000;
			if (!S2) rpm_alvo -= 50;
			if (rpm_alvo>5000) rpm_alvo=0;
		}
		if (flags.atualiza_rpm) calcula_RPM();
	}
}

