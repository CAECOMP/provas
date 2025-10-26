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
#define c4 LATBbits.LATB7

//VARS PARA ARMAZENAR O RESULTADO DA OPERACAO DE FORMA DISSECADA, EM CADA DISPLAY:
short long int sdis=0, cdis=0, qdis=0, tdis=0, ddis=0, udis=0; 

//VARS TEMP PARA REPASSAR OS VALORES INSERIDOS NO TECLADO PARA VAR num1 e num2:
unsigned short long s=0, c=0, q=0, t=0, d=0, u=0; 

//VAR PARA ARMAZENAR TEMP O VALOR TECLADO.
unsigned short long char tecla;	

//VAR OPERACAO DEFINE QUAL OPERACAO DEVE SER REALIZADA
int operacao=0, igual=0;	 //VAR IGUAL INDENTIFICAR SE A TECLA"=" FOI CLICADA.

//VAR resultado PARA ARMAZENAR O VALOR DA OPERACAO ENTRE num1 e num2
short long int num1=0,num2=0,resultado=0;	

//VAR PARA RESULTADO DA DIVISÃO
short long float resultado_float=0;

//PARA MANIPULAR num1 e num2 EM FORMATO FLOAT
short long float aux_float,n1,n2;

unsigned char converte_7segmentos [16] = {
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
	0b01000000,		//hifen
	0b01111001,		//E
	0b01010100,		//r
	0b01011100,		//o
	0b00000000,		//DESLIGADO
	0b10000000,		//PONTO '.'
};

//DELAY DE 5ms:
void delay_varredura(void) {
	unsigned int i;
	for(i=0;i<700;i++){};
}

//FUNCAO VARRE O DISPLAY INSERINDO OS VALORES DA INSERÇÃO DE VALORES
//EM CADA UM DOS 6 DIGITOS DO DISPLAY 
void varre_displays(void){
	
	d1 = 1;
	d2 = 1;
	d3 = 1;
	d4 = 1;
	d5 = 1;
	d6 = 1;
	
	barramento = converte_7segmentos[s];
	d1=0;
	delay_varredura();
	d1=1;

	barramento = converte_7segmentos[c];
	d2=0;
	delay_varredura();
	d2=1;
	
	barramento = converte_7segmentos[q];
	d3=0;
	delay_varredura();
	d3=1;
	
	barramento = converte_7segmentos[t];
	d4=0;
	delay_varredura();
	d4=1;
	
	barramento = converte_7segmentos[d];
	d5=0;
	delay_varredura();
	d5=1;
	

	barramento = converte_7segmentos[u];
	d6=0;
	delay_varredura();
	d6=1;
	
}

void mostra_resultado(void){
	
	d1 = 1;
	d2 = 1;
	d3 = 1;
	d4 = 1;
	d5 = 1;
	d6 = 1;
	
	barramento = converte_7segmentos[sdis];
	d1=0;
	delay_varredura();
	d1=1;

	barramento = converte_7segmentos[cdis];
	d2=0;
	delay_varredura();
	d2=1;
	
	barramento = converte_7segmentos[qdis];
	d3=0;
	delay_varredura();
	d3=1;
	
	barramento = converte_7segmentos[tdis];
	d4=0;
	delay_varredura();
	d4=1;
	
	barramento = converte_7segmentos[ddis];
	d5=0;
	delay_varredura();
	d5=1;
	

	barramento = converte_7segmentos[udis];
	d6=0;
	delay_varredura();
	d6=1;
	
}

//VARRE O TECLADO E RETORNA O VALOR DA TECLA CLICADA +10.
//NO MOMENTO DE ARMAZENAR SUBTRAIO O +10 RETORNADO DESTA FUNÇÃO.
int varre_teclado(void){
	
	//VERIFCA SE ALGUMA TECLA FOI CLICADA NA COLUNA C1 DO KEYPAD
	
	c1 = 0; 	//HABILITA SOMENTE COLUNA C1
	c2 = 1;		//DESABILITA COLUNA C2
	c3 = 1;		//DESABILITA COLUNA C3
	c4 = 1;		//DESABILITA COLUNA C4
	
	if(!l1){
		while(!l1){};	//ESPERA SOLTAR TECLA
		return 17;		//RETORNA O VALOR CORRESPONDENTE EM ASCII
	}
	
	if(!l2){
		while(!l2){};
		return 14;
	}
	
	if(!l3){
		while(!l3){};
		return 11;
	}
	if(!l4){			//BOTÃO ON/C NO KEYPAD
		while(!l4){};
	}
	
	
	//VERIFCA SE ALGUMA TECLA FOI CLICADA NA COLUNA C2 DO KEYPAD
	
	c1 = 1;		//DESABILITA COLUNA C1
	c2 = 0; 	//HABILITA SOMENTE COLUNA C2
	c3 = 1;		//DESABILITA COLUNA C3
	c4 = 1;		//DESABILITA COLUNA C4
	
	if(!l1){
		while(!l1){};	//ESPERA SOLTAR TECLA
		return 18;
	}
	
	if(!l2){
		while(!l2){};
		return 15;
	}
	
	if(!l3){
		while(!l3){};
		return 12;
	}
	if(!l4){
		while(!l4){};
		return 10;
	}
	c1 = 1;
	c2 = 1;
	c3 = 0; 	//HABILITA SOMENTE COLUNA C3
	c4 = 1;
	
	if(!l1){
		while(!l1){};	//ESPERA SOLTAR TECLA
		return 19;
	}
	
	if(!l2){
		while(!l2){};
		return 16;
	}
	
	if(!l3){
		while(!l3){};
		return 13;
	}
	
	if(!l4){			//BOTÃO ' = ' NO KEYPAD.
		while(!l4){};	//ESPERA PARA DE CLICAR.
		igual=1;		//INCREMENTA IGUAL PARA DECLARAR QUE "=" FOI CLICADO
	}					//E MOSTRAR O RESULTADO DA OPERAÇÃO.
	
	c1 = 1;
	c2 = 1;
	c3 = 1;
	c4 = 0;	
	
	if(!l1){			//BOTÃO ' / ' NO KEYPAD.
		while(!l1){};	//ESPERA PARA DE CLICAR.
		operacao=4;		//DECLARA OPERAÇÃO = 4;
	}					//OPERACÃO = VALOR 4, CORRESPONDE DIVISÃO.
	
	if(!l2){			//BOTÃO ' X ' NO KEYPAD.
		while(!l2){};	//ESPERA PARA DE CLICAR.
		operacao=3;		//OPERAÇÃO VALOR 3 = MULTIPLICAÇÃO.
	}
	
	if(!l3){			//BOTÃO ' - ' NO KEYPAD.
		while(!l3){};	//ESPERA PARA DE CLICAR.
		operacao=2;		//OPERAÇÃO VALOR 2 = SUBTRAÇÃO.
	}
	
	if(!l4){			//BOTÃO ' + ' NO KEYPAD.
		while(!l4){};	//ESPERA PARA DE CLICAR.
		operacao=1;		//OPERAÇÃO = 1 CORRESPONDE A OPERAÇÃO DE ADIÇÃO.
	}
	
	return 0;
}


//FUNCÃO PARA INSERIR NUMERO 1 E NUMERO 2 DA OPERAÇÃO MATEMATICA.
void inserir(void){		
		while(operacao==0){			//ENQUANTO OPERAÇÃO NÃO FOR CLICADO, INSERE NUM 1.
		varre_displays();			//MOSTRA NO DISPLAY O NUMERO INSERIDO.
		tecla = varre_teclado();	//ATRIBUI A TECLA CLICADA A VAR TECLA.	
		if(tecla){
			s=c;
			c=q;
			q=t;
			t=d;
			d=u;
			u=(tecla-10);			//PERCORRE DISPLAY E ATRIBUI A VAR CORRESPONDE O VALOR DA
		}							//TECLA CLICADA -10, PARA O VALOR SER DE 0 A 9.
	}
	
	//TRANSFORMA O NUMERO DE FORMA DISSECADA EM FORMATO NORMAL,
	//AFIM DE SIMPLIFICAR A OPERAÇÃO.
	//NUM 1 = UNIDADE + DEZENA + CENTENA + MILHAR....
	
	num1 = (u+(10*d)+(100*t)+(1000*q)+(10000*c)+(100000*s));
	
	//ZERA OS VALORES OBTIDOS DE FORMA DISSECADO, 
	//POIS O NUMERO JA FOI ARMAZENADO EM NUM 1 
	//E ESSAS VARS SERÃO USADA NA INSERÇÃO DE NUM 2.
	
	s=0, c=0, q=0, t=0, d=0, u=0;	
	
	while(igual==0){				//ENQUANTO A TECLA "=" NÃO FOR CLICADA.
		varre_displays();			//MOSTRA NO DISPLAY VALOR TECLADO.
		tecla = varre_teclado();	//ATRIBUI A TECLA CLICADA A VAR TECLA.	
		if(tecla){
			s=c;
			c=q;
			q=t;
			t=d;
			d=u;
			u=(tecla-10);			//CONVERTE ASCII PARA BINARIO
		}
		
	}
	
	//NUM 2 = UNIDADE + DEZENA + CENTENA + MILHAR +....
	num2 = (u+(10*d)+(100*t)+(1000*q)+(10000*c)+(100000*s));
	
	//ZERA O VALOR DIGITADO.
	s=0, c=0, q=0, t=0, d=0, u=0;

	

}

//EXIBE MENSAGEM " Erro " NOS DISPLAYS QUANDO O NUMERO EXCEDE OS 6 DIGITOS DO DIPLAYS.
void msg_erro(void){
	sdis = 14;		//DESLIGADO
	cdis = 11;		// " E "
	qdis = 12;		// " r "
	tdis = 12;		// " r "
	ddis = 13;		// " o "
	udis = 14;		//DESLIGADO
}


//FUNÇÃO PARA DISSECAR NUMERO EM UNIDADE, DEZENA, CENTENA...
//AFIM DE MOSTRAR CADA DIGITO NOS 6 DIGITOS DO DISPLAY.
//RESULTADO =   6 ,   5 ,   4 ,   3 ,   2 ,  1
//resultado = sdis, cdis, qdis, tdis, ddis, udis
void disseca_num(void){
	udis = resultado%10;
	ddis = (((resultado-udis)/10)%10);
    tdis = (((resultado-(udis+(10*ddis)))/100)%10);
    qdis = (((((resultado-(udis+(10*ddis)))/100)-tdis)/10)%10);
    cdis = (((((((resultado-(udis+(10*ddis)))/100)-tdis)/10)-qdis)/10)%10);
    sdis = ((((((((resultado-(udis+(10*ddis)))/100)-tdis)/10)-qdis)/10)-cdis)/10);
}

//FUNÇÃO DE OPERACAO ADIÇÃO
void adicao(void){
	
	resultado = num1+num2; 
	
	if(resultado>999999){		//SE O RESULTADO EXCEDER O DISPLAY
		msg_erro();				//EXIBA MENSAGEM DE ERRO.
	}else{
	disseca_num();				//DISSECAR O NUMERO PARA FICAR NO FORMATO.
	}							//PARA EXIBIR NO DISPLAY.
}

void subtracao(void){
	
	if(num1>num2){				//SE O NUMERO 1 FOR MAIOR QUE O NUMERO 2
		resultado = num1-num2;	//NUMERO 1 - NUMERO 2
		disseca_num();			//FORMATA PARA EXIBIR NO DISPLAY
	}
	if(num2>num1){				//SE O NUMERO 1 FOR MAIOR QUE O NUMERO 2
		resultado = num2-num1;	//RESULTADO = NUMERO 2 - NUMERO 1
		disseca_num();			//FORMATA PARA EXIBIR NO DISPLAY
		sdis=10;				//DEIXA O NUMERO NEGATIVO ADICIONADO " - "
	}
	
	if(resultado>999999){		//SE O RESULTADO EXCEDER O DISPLAY
		msg_erro();				//EXIBA MENSAGEM DE ERRO.
	}

}

void multiplicacao(void){
	resultado = num1*num2;
	disseca_num();				//FORMATA PARA EXIBIR NO DISPLAY
	
	if(resultado>999999){		//SE O RESULTADO EXCEDER O DISPLAY
		msg_erro();				//EXIBA MENSAGEM DE ERRO.
	}
}
void divisao(void){
	n1 = num1;							//TRANSFORMA int num1 em float n1;
	n2 = num2;							//AFIM DE ADCIONAR " . " AO NUMERO
	resultado_float = n1/n2;			//REALIZA A DIVISÃO E GUARDA EM FORMATO FLOAT.
	resultado=resultado_float*100;		//TIRA O .
	aux_float=resultado;				//GUARDA O VALOR EM FORMATO INT EM VAR AUX
	resultado_float=(aux_float/100);	
	resultado = resultado_float*10;		//TRANSFORMA O NUMERO FLOAT EM INT COM O NUMERO DPS DO .
	
	if(resultado>99999){
		msg_erro();
	}else{
	disseca_num();
	
	//ARRASTA O NUMERO A ESQUERDA DO QUE SERIA O PONTO.
	sdis = cdis;
	cdis = qdis;
	qdis = tdis;
	tdis = ddis;
	ddis = 15;		//ADICIONAR O PONTO.
	}
}

main(){
	TRISC = 0B00000000;
	TRISD = 0B00000000;
	ADCON1 = 0B00001111;	//DESABILITA PINOS ANALOGICOS
	TRISB = 0B00001111;		//LINHAS(ENTRADA)/COLUNAS(SAÍDA)

	inserir();
	if(operacao==1){		//SE A TECLA ADIÇÃO FOR CLICADA.
		adicao();			//CHAME A FUNÇÃO ADIÇÃO E REALIZE A OPERAÇÃO.
		operacao=0;			//ZERA OPERAÇÃO PARA O PROXIMO CLIQUE ADCIONAR VALOR CORRESPONDENTE.
	}
	if(operacao==2){		//SE A TECLA SUBTRAÇÃO FOR CLICADA.
		subtracao();		//CHAME A FUNÇÃO SUBTRAÇÃO E REALIZE A OPERAÇÃO.
		operacao=0;			//ZERA OPERAÇÃO PARA O PROXIMO CLIQUE.
	}
	if(operacao==3){		//SE A TECLA MULTIPLICAÇÃO FOR CLICADA.
		multiplicacao();	//CHAME A FUNÇÃO MULTIPLICAÇÃO E REALIZE A OPERAÇÃO.
		operacao=0;			//ZERA OPERAÇÃO PARA O PROXIMO CLIQUE DE OPERAÇÃO.
	}
	if(operacao==4){		//SE A TECLA DIVISÃO FOR CLICADA.
		divisao();			//CHAMA FUNC DIVISÃO E REALIZA DIVISÃO
		operacao=0;
	}
	
	while(1){
		mostra_resultado();	//MOSTRA RESULTADO DA OPERAÇÃO NO DISPLAY.
	}	
}