/*  
 * file : USART.h
 * 
 * Authors : Andre Vieira e Luan Barroso
 * 
 *  Copyright (C) 2018 Andre Vieira <sgavsnake@gmail.com>
 *  Copyright (C) 2018 Luan Pontes  <pontesluanlx@gmail.com>
 *
 * Adaptado de www.electronicwings.com com uso do  dataSheet para o dispositivo PIC18F4550. 
 * 
 * 
 * This file or program is a free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public
 * License version 3 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License version 3 for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License version 3 along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */


#include <pic18f4550.h> //definição das bibliotecas padrões paa o dispositivo
#include"Cabecalho_Configuracao_Bits.h"////cabeçalho de configuração dos registradores do dispositivo

#define _XTAL_FREQ 8000000//frequencia de clock do oscilator interno
#define F_CPU 8000000/64//#define Baud_value(baud_rate) (((float)(F_CPU)/(float)baud_rate)-1)
#define Baud_value (((float)(F_CPU)/(float)baud_rate)-1)//calculo do taxa de transmissão serial para Uart


void USART_Init(long);
void USART_TxChar(char);
void USART_Start(long);
void USART_SendString(const char *);
void MSdelay(unsigned int val);


/*****************************USART Initialization*******************************/
void USART_Init(long baud_rate) {
    float temp;
    TRISC6 = 0; /*Make Tx pin as output*/
    TRISC7 = 1; /*Make Rx pin as input*/
    temp = Baud_value;
    SPBRG = (int) temp; /*baud rate=9600, SPBRG = (F_CPU /(64*9600))-1*/
    TXSTA = 0x20; /*Transmit Enable(TX) enable*/
    RCSTA = 0x80; /*Receive Enable(RX) enable and serial port enable */
    
}
/******************TRANSMIT CARACTERFUNCTION*****************************************/
void USART_TxChar(char out) {//transmit char by a serial uart
    while (TXIF == 0); /*wait for transmit interrupt flag*/
    TXREG = out; /*wait for transmit interrupt flag to set which indicates TXREG is ready
                                    for another transmission*/
}
/******************TRANSMIT STRING FUNCTION*****************************************/ 
void USART_SendString(const char *out) {//transmit a string by in serial uart
    while (*out != '\0') { //pointer outer is a note end of string /0
        USART_TxChar(*out); //transmit a char
        out++; //increment pointer for the new char
    }
}

//*******************RECEIVE FUNCTION*****************************************
char USART_RxChar() {//Recever char caracter function
    while (RCIF == 0); /*wait for receive interrupt flag*/
    if (RCSTAbits.OERR) {
        CREN = 0; //enable port C busy transmit data
        NOP();    //nothing asm instruction
        CREN = 1; //disabled port C busy transmit data
        RCIF = 0; //Set down a rx interrupt flag
    }
    return (RCREG); /*receive data is stored in RCREG register and return */
}

void MSdelay(unsigned int val) {//delay for a loop implementacion
    unsigned int i, j; //variable init
    for (i = 0; i <= val; i++) //loop 
        for (j = 0; j < 81; j++); /*This count Provide delay of 1 ms for 8MHz Frequency */
}

void USART_Start(long BaudRate){//hability a Uart serial Rs232 comunication
    USART_Init(BaudRate);  /*Init a baudRate transmission*/
    OSCCON = 0x72; /*set internal oscillator frequency= 8 MHz*/
    USART_Init(9600); /*initialize USART with 9600 baud rate*/
    MSdelay(250);/*delay a persist config of UART*/
}
