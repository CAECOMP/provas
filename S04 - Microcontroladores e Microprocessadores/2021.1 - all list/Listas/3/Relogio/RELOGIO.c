#include <p18f4520.h>

#define barramento LATC
#define d1 LATDbits.LATD0
#define d2 LATDbits.LATD1
#define d3 LATDbits.LATD2
#define d4 LATDbits.LATD3
#define d5 LATDbits.LATD4
#define d6 LATDbits.LATD5

#define l1 PORTBbits.RB3
#define l2 PORTBbits.RB2
#define l3 PORTBbits.RB1
#define l4 PORTBbits.RB0

#define c1 LATBbits.LATB4
#define c2 LATBbits.LATB5
#define c3 LATBbits.LATB6


unsigned char dh=10, uh=10, dm=10, um=10, ds=10, us=10;

unsigned char tecla;	//VAR PARA ARMAZENAR TEMP O VALOR TECLADO

int saida=0; //AUX PARA SAIR DO LOOP AJUSTAR HORA. QUANDO CLICADO EM #, SAIDA = 1;

unsigned char converte_7segmentos [11] = {
	0b00111111,		//0
	0b00000110,		//1
	0b01011011,		//2
	0b01001111,		//3
	0b01100110,		//4
	0b01101101,		//5
	0b01111101,		//6
	0b00000111,		//7
	0b01111111,		//8
	0b01101111,		//9
	0b01000000,		//'-'
};
//delay de 5ms:
void delay_varredura(void) {
	unsigned int i;
	for(i=0;i<700;i++){};
}

void varre_displays(void){
	
	d1 = 1;
	d2 = 1;
	d3 = 1;
	d4 = 1;
	d5 = 1;
	d6 = 1;
	
	barramento = converte_7segmentos[dh];
	d1=0;
	delay_varredura();
	d1=1;

	barramento = converte_7segmentos[uh];
	d2=0;
	delay_varredura();
	d2=1;
	
	barramento = converte_7segmentos[dm];
	d3=0;
	delay_varredura();
	d3=1;
	
	barramento = converte_7segmentos[um];
	d4=0;
	delay_varredura();
	d4=1;
	
	barramento = converte_7segmentos[ds];
	d5=0;
	delay_varredura();
	d5=1;
	

	barramento = converte_7segmentos[us];
	d6=0;
	delay_varredura();
	d6=1;
	
}



char varre_teclado(void){
	
	c1 = 0; 	//HABILITA SOMENTE COLUNA C1
	c2 = 1;
	c3 = 1;
	
	if(!l1){
		while(!l1){};	//ESPERA SOLTAR TECLA
		return '1';		//RETORNA O VALOR CORRESPONDENTE EM ASCII
	}
	
	if(!l2){
		while(!l2){};
		return '4';
	}
	
	if(!l3){
		while(!l3){};
		return '7';
	}
	
	c1 = 1;
	c2 = 0; 	//HABILITA SOMENTE COLUNA C2
	c3 = 1;
	
	if(!l1){
		while(!l1){};	//ESPERA SOLTAR TECLA
		return '2';
	}
	
	if(!l2){
		while(!l2){};
		return '5';
	}
	
	if(!l3){
		while(!l3){};
		return '8';
	}
	if(!l4){
		while(!l4){};
		return '0';
	}
	c1 = 1;
	c2 = 1;
	c3 = 0; 	//HABILITA SOMENTE COLUNA C3
	
	if(!l1){
		while(!l1){};	//ESPERA SOLTAR TECLA
		return '3';
	}
	
	if(!l2){
		while(!l2){};
		return '6';
	}
	
	if(!l3){
		while(!l3){};
		return '9';
	}
	
	if(!l4){				//SE O # FOR PRESIONADO
		while(!l4){};		//ESPERA PARAR DE CLICAR
		saida=1;			//SAIDA=1; PARA SAIR DO LOOP DE AJUSTE DE HORAS
		return 0;
	}	
	
	
	return 0;
}

void atualiza_relogio(void){		//INCREMENTA OS SEGUNDOS, MINUTOS E HORAS.
	
	
	if(++us >=10){
		us=0;
		ds++;
	}
	if(ds>=6 && us>=0){
		us=0;
		ds=0;
		if(++um >= 10){
			um=0;
			dm++;
		}
	}
	if(dm>=6 && um>=0){
		dm=0;
		um=0;
		if(++uh >= 10){
			uh=0;
			dh++;
		}
	}
	if(dh>=2 && uh>=4){		//ZERA O RELOGIO INTEIRO POIS SÃO 23:59:59.
		dh=0;
		uh=0;
		dm=0;
		um=0;
		ds=0;
		us=0;
	}
	

}

void mostrar_horario(void){
	unsigned long int i;
	for(i=0;i<32;i++){			//DELAY PARA COMPLETAR 1s.
		varre_displays();		//DEMORA ~30ms
	}
}

void ajustar_relogio(void){		
		while(saida!=1){			//ENQUANTO # NÃO FOR CLICADO, INSERIR HORARIO
		varre_displays();			
		tecla = varre_teclado();	//ATRIBUI A TECLA CLICADA A VAR TECLA.	
		if(tecla){
			dh=uh;
			uh=dm;
			dm=um;
			um=ds;
			ds=us;
			us=tecla-0x30;		//CONVERTE ASCII PARA BINARIO
		}
		
	}

}

main(){
	TRISC = 0B00000000;
	TRISD = 0B00000000;
	ADCON1 = 0B00001111;	//DESABILITA PINOS ANALOGICOS
	TRISB = 0B10001111;		//LINHAS(ENTRADA)/COLUNAS(SAÍDA)
	
	ajustar_relogio();		//AJUSTAR RELOGIO, INSERIR HORARIO ATÉ QUE CLIQUEM EM #.
	
	while(1){
		
		
		mostrar_horario();		//MOSTRA O HORARIO NO DISPLAY.
		atualiza_relogio();		//INCREMENTAÇÕES DE SEGUNDOS, MINUTOS E HORAS. 
		
		
	}	
}