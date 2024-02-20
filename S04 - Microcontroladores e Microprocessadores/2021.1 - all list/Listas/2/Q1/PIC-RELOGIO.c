# include <p18f4520.h>

# define luz_hora					PORTEbits.RE1						
# define luz_alarme					PORTEbits.RE2						

char horas = 23;															
char minutos = 58;														
char segundos = 50;														

char horas_alarme = 00;												
char minutos_alarme = 00;												

char aux; 																
char resp;																	

char num [60] = {
	0b00000000, 0b00000001,	0b00000010,	0b00000011,	0b00000100,	0b00000101,	0b00000110,	0b00000111,	0b00001000,	0b00001001, 0b00010000,	0b00010001,	0b00010010, 0b00010011,	0b00010100,	0b00010101,	0b00010110,	0b00010111, 0b00011000, 0b00011001,							
	0b00100000,	0b00100001,	0b00100010,	0b00100011,	0b00100100,	0b00100101,	0b00100110,	0b00100111,	0b00101000,	0b00101001,	0b00110000,	0b00110001,	0b00110010, 0b00110011,	0b00110100,	0b00110101,	0b00110110,	0b00110111,	0b00111000,	0b00111001,				
	0b01000000, 0b01000001,	0b01000010,	0b01000011,	0b01000100,	0b01000101,	0b01000110, 0b01000111,	0b01001000,	0b01001001,	0b01010000,	0b01010001,	0b01010010,	0b01010011,	0b01010100,	0b01010101,	0b01010110,	0b01010111,	0b01011000, 0b01011001,							
};

void delay_s(unsigned int tempo){											// FUNÇÃO DO SECUNDO:
	unsigned short long i;
	for(i = 0; i < 90000; i++){}
	
}

void mostrar_as_horas(char h, char m, char s){								// 
	LATB = num[horas];     													// EXIBIR AS HORAS
	LATC = num[minutos];													// EXIBIR OS MINUTOS
	LATD = num[segundos];													// EXIBIR OS SEGUNDOS
	delay_s(1);															
	segundos++;															
	if(segundos > 59){													
		segundos = 0;														
		minutos++;															
		if(minutos > 59){													
			minutos = 0;													
			horas++;														
			if(horas > 23){													
				horas = 0;													// HORAS RECEBE 0 E TODAS AS VARIAVEIS ZERAM
			}
		}
	}		
}

void definicao_da_hora(){													
	while(1){															
		char horas_d = PORTAbits.RA4;									
		char minutos_d = PORTAbits.RA6;										
		
		segundos++;
		if(segundos > 59){
			segundos = 0;
		}
	
		LATB = num[horas];  												 											
		LATC = num[minutos];												
		LATD = num[segundos];												
		
		if(horas_d == 1 && minutos_d == 1){									// SE HORAS_D TIVER 1 E MINUTOS TAMBÉM TIVER 1, QUER DIZER QUE FOI FEITO O AJUSTE DAS HORAS E QUER SAIR DA FUNÇÃO DE DEFINIÇÃO_DA_HORA 
			luz_hora = 0;													// APAGA A LUZ QUE INDICA A FUNÇÃO
			delay_s(1);													
			break;														
		}
		else{																// SE NÃO TIVER 1 NOS PINOS A4 E A6 AO MESMO TEMPO, QUER DIZER QUE QUEREMOS MUDAR AS HORAS
			if(horas_d == 1){												// SE TIVER 1 NA A4, QUER DIZER QUEREMOS MUDAR AS HORAS
				horas++;													// SOMA 1 NA HORA
				if(horas > 23){												// SE AS HORAS FOR MAIOR QUE 23:
					horas = 0;												// HORAS RECEBE 0
				}
				delay_s(1);													// ESPERA 1 SEGUNDO, PARA NÃO FAZER MULTIPLAS LEITRURAS DA PORTA A4
			}
			if(minutos_d == 1){												// SE TIVER 1 NA PORTA A6, QUER DIZER QUE QUEREMOS MUDAR OS MINUTOS.
				minutos++;													// SOMA 1 NOS MINUTOS
				if(minutos > 59){											// SE MINUTOS FOR MAIOR QUE 59:
					minutos = 0;											// MINUTOS RECEBE 0
				}
				delay_s(1);													// ESPERAR 1 SEGUNDO PARA FAZER A LEITURA DE APENAS UM CLIQUE, PARA NÃO LER VÁRIAS VEZES
			}
		}
		delay_s(1);	
	}
}

void definicao_da_hora_do_alarme(){                                         // FUNÇÃO DA DEFINIÇÃO DO TEMPO PARA ALARMAR
	while(1){																// LOOP INFINITO

		char alarme_horas = PORTAbits.RA4;									// PORTA A4 RECEBE O NOME DE ALARME_HORAS
		char alarme_minutos = PORTAbits.RA6;								// PORTA A6 RECEBE O NOME DE ALARME_MINUTOS
		
		delay_s(1);
		segundos++;
		if(segundos > 59){
			segundos = 0;
		}
		
		LATB = num[horas_alarme];											// EXIBI AS HORAS DO ALARME EM TEMPO REAL DE ALTERAÇÃO
		LATC = num[minutos_alarme];                                         // EXIBI OS MINUTOS DO ALARME EM TEMPO REAL DE ALTERAÇÃO
		LATD = num[segundos];												// EXIBI OS SEGUNDOS DO RELOGIO

		if(alarme_horas == 1 && alarme_minutos == 1){						// SE NA PORTA A4 E A6 TIVER 1 AO MESMO TEMPO, QUER DIZER QUE QUEREMOS SAIR DA FUNÇÃO DEFINIÇÃO_DA_HORA_DO_ALARME
			luz_alarme = 0;													// APAGA A LUZ QUE INDICA A FUNÇÃO DO ALARME
			delay_s(1);														
			break;														
			
		}
		else{														
			if(alarme_horas == 1){									
				horas_alarme++;												
				if(horas_alarme > 23){										
					horas_alarme = 0;										
				}
				delay_s(1);												
			}
			if(alarme_minutos == 1){										// SE TIVER 1 NA PORTA A6, QUER DIZER QUE QUEREMOS MUDAR OS MINUTOS
				minutos_alarme++;											// SOMA 1 NO MINUTOS DO ALARME
				if(alarme_minutos > 59){									// SE MINUTOS DO ALARME, FOR MAIOR QUE 59 =>
					minutos_alarme = 0;										// MINUTOS DO ALARME, RECEBE 0
				}
				delay_s(1);													// ESPERA 1 SEGUNDO, PARA FAZER APENAS UMA LEITURA DA PORTA A6
			}
		}
	}
}

void toca_alarme(){															// FUNÇÃO ALARME
	while(1){															
		char o = PORTAbits.RA4;												
		char k = PORTAbits.RA6;											
		
		LATB = num[horas];												
		LATC = num[minutos];											
		LATD = num[segundos];											

		delay_s(1);														
		segundos++;														
		if(segundos > 59){													// SE SEGUNDOS FOR MAIOR QUE 59:
			segundos = 0;													// SEGUNDOS RECEBE 0 E:
			minutos++;														// MINUTOS SOMA 1
			if(minutos > 59){												// SE MINUTOS FOR MAIOR QUE 59
				minutos = 0;												// MINUTOS RECEBE 0 E:
				horas++;													// HORAS SOMA 1
				if(horas > 23){												// SE HORAS FOR MAIOR QUE 23:
					horas = 0;												// HORAS RECEBE ZERO E INICIA NOVO CICLO.
				}
			}
		}
		if(o == 1 && k == 1 || minutos - minutos_alarme == 2){				// SE "O" E "K" FOR IGUAL A 1 OU SUBTRAÇÃO DE MINUTOS - MINUTOS DO ALARME FOR 2:
			horas_alarme = 0;												// HORAS_ALARME RECEBE 0
			minutos_alarme = 0;												// MINUTOS_ALARME RECEBE 0
			luz_hora = 0;													// LUZ_HORA APAGA
			luz_alarme = 0;													// LUZ_ALARME APAGA
			break;														
		}
		else{																// SE "O" E "K" FOR DIFERENTE DE 1 E A SUBTRAÇÃO FOR MENOR QUE 2:
			if(segundos % 2 == 0){											// VERIFICA SE SEGUNDOS É PAR:
				luz_hora = 1;												// SE FOR PAR, ACENDE LUZ_HORA
			}
			else{															// SE FOR ÍMPA:
				luz_alarme = 1;												// ACENDE A LUZ_ALARME
			}
		}
	}
}


main(){
	// configuração dos display
	TRISB = 0b00000000;														// DISPLAY DAS HORAS.
	TRISC = 0b00000000;														// DISPLAY DOS MINUTOS.
	TRISD = 0b00000000;														// DISPLAY DOS SECUNDOS.

	TRISAbits.RA4 = 1;														// MODO / HORAS / HORAS_DO_ALARME
	TRISAbits.RA6 = 1; 														// MINUTOS / MINUTOS_DO_ALARME.
																			// (MODO/HORAS/MINUTOS) => OK
		
	TRISEbits.RE1 = 0;														// LED DAS HORAS.
	TRISEbits.RE2 = 0;														// LED DO ALARME.

	while(1){
		char modo = PORTAbits.RA4;										
		if(modo == 1){													
			for(aux = 0; aux < 4; aux++){											
				char modo = PORTAbits.RA4;								
				if(aux == 0 && modo == 1){									
					resp++;												
				}
				if(aux == 1 && modo == 1){								
 					resp++;													
				}
				if(aux == 2 && modo == 1){									
					resp++;													
				}
				if(aux == 3 && modo == 1){									
					resp++;													
				}

				delay_s(1);													
			}

			if(resp == 2){ 													// SE NO FINAL DA CONTAGEM, RESP TIVER 2:
				resp = 0;													// RESP RECEBE 0
				luz_hora = 1;												// LIGA A LUZ DA HORA
				definicao_da_hora();										// ABRE A FUNÇÃO DA DEFINIÇÃO DAS HORAS
			}
			if(resp >= 3){													// SE NO FINAL DA CONTAGEM, RESP TIVER 3 OU MAIS:
				resp = 0;													// RESP RECEBE 0
				luz_alarme = 1;												// LIGA A LUZ DO ALARME
				definicao_da_hora_do_alarme(); 								// ABRI A FUNÇÃO DA DEFINIÇÃO DAS HORAS DO ALARME
			}
		}
		else{																// SE NÃO TIVER 1, NA PORTA A4,FAZ.
			if(horas == horas_alarme && minutos == minutos_alarme){			// VERIFICA, SE AS HORAS ATUAL É IGUAL A HORA DO ALARME.
				toca_alarme();												// ABRE A FUNÇÃO D ALARME.
			}
			mostrar_as_horas(horas, minutos, segundos);						// ABRE A FUNÇÃO, MOSTRAR AS HORAS.
		}
		
	}
}