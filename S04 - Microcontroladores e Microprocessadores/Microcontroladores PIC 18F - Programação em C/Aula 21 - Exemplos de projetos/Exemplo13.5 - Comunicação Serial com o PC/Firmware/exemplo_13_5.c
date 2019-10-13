#include <p18f4520.h>
#include <stdio.h>
#include "pic_simb.h"
#include "meu_lcd16x2.c"

#pragma config OSC = XT, WDT = OFF, MCLRE = ON
#pragma config DEBUG = ON, LVP = OFF, PWRT = ON, BOREN = OFF

#define S1	PORTBbits.RB0	
#define S2	PORTBbits.RB1
#define L3	LATBbits.LATB2
#define L4	LATBbits.LATB3

#define TX_BUF_SIZE   32  	// Buffer de transmissão = 32 caracteres
#define RX_BUF_SIZE   32  	// Buffer de recepção = 32 caracteres

volatile char txbuffer[TX_BUF_SIZE], rxbuffer[RX_BUF_SIZE];
volatile char tx_buf_read_pointer, tx_buf_write_pointer;
volatile char rx_buf_read_pointer, rx_buf_write_pointer;
struct
{
  char rx_flag      : 1;  	// há caracteres no buffer de recepção
  char tx_buf_empty : 1;  	// buffer de transmissão vazio
} flags;

unsigned char str[6];

/*
  Função de tratamento da interrupção de recepção da EUSART
  Os caracteres recebidos são armazenados no buffer de recepção  
*/
#pragma interrupt RX_ISR
void RX_ISR(void)
{
  char temp;
  temp = RCSTA;		// lê RCSTA para verificar se houve erro
  if (temp & 0x06)   		// algum erro de recepção?
  { // sim, le o dado e o descarta
    RCSTAbits.CREN = 0;	// desabilita recepção e apaga o erro
		RCSTAbits.CREN = 1;	// reabilita a recepção
    return;
  }
	// Lê e armazena o caractere recebido, incrementa o ponteiro de escrita de leitura
  rxbuffer[rx_buf_write_pointer++] = RCREG;
  if (rx_buf_write_pointer>=RX_BUF_SIZE) rx_buf_write_pointer = 0;
  flags.rx_flag = 1;  		// seta o flag de recepção (há dados no buffer)
}

/*
  Função de tratamento da interrupção de transmissão da EUSART
	Lê os caracteres do buffer de transmissão e os envia pela EUSART
  Se não houver caracteres a ser transmitidos, desabilita a interrupção de transmissão
*/  
#pragma interrupt TX_ISR
void TX_ISR(void)
{
  if (tx_buf_read_pointer==tx_buf_write_pointer)
  {
    // se os ponteiros de leitura e de escrita forem iguais, não há mais dados a serem
		// transmitidos, desabilita a interrupção de transmissão e seta o flag de buffer vazio
    PIE1bits.TXIE = 0;	// desabilita a interrupção de transmissão
    flags.tx_buf_empty = 1;	// buffer de transmissão está vazio
  } else
  {
    if (PIR1bits.TXIF)
    {
      // se houver algum dado no buffer, envia o próximo caractere e avança
			// o ponteiro de leitura do buffer
      TXREG = txbuffer[tx_buf_read_pointer++];
			// se o ponteiro ultrapassar o final do buffer, volta para o início
      if (tx_buf_read_pointer>=TX_BUF_SIZE) tx_buf_read_pointer = 0;
    }
  }
}

#pragma code isr_baixa = 0x0008
void ISR_baixa_prioridade(void)
{
	if (PIR1bits.RCIF) _asm BRA RX_ISR _endasm
	if (PIR1bits.TXIF) _asm BRA TX_ISR _endasm
}
#pragma code

// Função para escrever um caractere no buffer de transmissão
void EUSART_escreve_char_buffer(unsigned char data)
{
	while (tx_buf_write_pointer==tx_buf_read_pointer &&  !flags.tx_buf_empty);
  flags.tx_buf_empty = 0;   	// o buffer de transmissão não está mais vazio
  // escreve o dado no buffer e incrementa o ponteiro de escrita
  txbuffer[tx_buf_write_pointer++] = data;
  // se o ponteiro ultrapassar o final do buffer, volta para o início
  if (tx_buf_write_pointer>=TX_BUF_SIZE) tx_buf_write_pointer = 0;
  PIE1bits.TXIE = 1;	// habilita a interrupção de transmissão
}

// Função para escrever uma string no buffer de transmissão
void EUSART_escreve_string_buffer(unsigned char *data)
{
  while (*data) EUSART_escreve_char_buffer(*data++);  
}

// Função para escrever uma string no buffer de transmissão
void EUSART_escreve_string_buffer_rom(rom unsigned char *data)
{
  while (*data) EUSART_escreve_char_buffer(*data++);  
}

// Função para leitura de um caractere do buffer de recepção
char EUSART_le_caractere_buffer(void)
{
  char temp;
  temp = rxbuffer[rx_buf_read_pointer++];
  // se o ponteiro ultrapassar o final do buffer, volta para o início
  if (rx_buf_read_pointer>=RX_BUF_SIZE) rx_buf_read_pointer = 0;
  // se os ponteiros de leitura e de escrita forem iguais, apaga o flag de recepção
  PIE1bits.RCIE = 0;	// desabilita a interrupção de recepção
  if (rx_buf_read_pointer==rx_buf_write_pointer) flags.rx_flag = 0;
  PIE1bits.RCIE = 1;	// reabibilita a interrupção de recepção
  return (temp);	// retorna o caractere lido do buffer
}

void MCU_init(void)
{
	LATA = LATB = LATD = 0;
	TRISA = 0x02;		// pino 2 da porta A como entrada
	TRISB = 0x03;		// RB0 e RB1 como entradas, RB2 a RB7 como saídas
	TRISC = 0x81;		// RC7 e RC0 como entradas
	TRISD = 0;			// RD0 a RD7 como saídas
	CMCON = 0x07;		// desliga pinos analógicos do comparador
	ADCON1 = 0x0F;		// Desliga entradas analógicas do ADC
	TXSTA = bTXEN | bBRGH;	// TXSTA = 0x24 -> TXEN=1 e BRGH=1
	RCSTA = bSPEN | bCREN;	// RCSTA = 0x80 -> SPEN=1 e CREN=1
	SPBRG = 25;	// configura a velocidade da EUSART (9600bps para Fosc = 4MHz)
	PIE1 = bRCIE | bTXIE;		// habilita as interrupções de transmissão e recepção
	INTCON = bGIE | bPEIE;
	LCD_init(DISPLAY_8X5|_2_LINES,DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);
	LCD_write_char('\f'); // apaga o display
	flags.tx_buf_empty = 1;	// buffer de transmissão inicialmente vazio
}

void imprime_menu(void)
{
	EUSART_escreve_string_buffer_rom("PIC18 Detalhado\r\n");
	EUSART_escreve_string_buffer_rom("Teste da EUSART com buffer\r\n");
	EUSART_escreve_string_buffer_rom("Pressione:\r\n");
	EUSART_escreve_string_buffer_rom("1- Ligar led L3\r\n");
	EUSART_escreve_string_buffer_rom("2- Desligar led L3\r\n");
	EUSART_escreve_string_buffer_rom("3- Ligar led L4\r\n");
	EUSART_escreve_string_buffer_rom("4- Desligar led L4\r\n");
	EUSART_escreve_string_buffer_rom("5- Limpar LCD\r\n");
	EUSART_escreve_string_buffer_rom("6- Imprimir menu\r\n");
}

char le_teclas(void)
{
	static char ultima_tecla;
	char tecla=0;
	if (!S1) tecla = 1;
	if (!S2) tecla = 2;
	if (ultima_tecla==tecla) return 0;
	ultima_tecla = tecla;
	return tecla;
}

void main(void)
{
	char aux;
	MCU_init();
	imprime_menu();
	while(1)
	{
		if (flags.rx_flag)
		{
			aux = EUSART_le_caractere_buffer();
			switch (aux)
			{
				case '1' : L3 = 1; break;
				case '2' : L3 = 0; break;
				case '3' : L4 = 1; break;
				case '4' : L4 = 0; break;
				case '5' : LCD_write_char('\f'); break;
				case '6' : imprime_menu(); break;
				default: LCD_write_char(aux); break; 
			}
		}
		aux = le_teclas();
		if (aux==1) EUSART_escreve_string_buffer_rom("Tecla S1\r\n");
		if (aux==2) EUSART_escreve_string_buffer_rom("Tecla S2\r\n");
	}
}
