# include<p18f4520.h>

//João Bruno Rodrigues de Freitas 



int string[][8] = {
/*O*/	{0b11111111, 	0b10000001, 0b00000000, 0b00111100, 0b00111100, 0b00000000, 0b10000001, 0b11111111},
/*N*/	{0b11111111, 	0b00000000,	0b00000001,	0b11100011,	0b11000111,	0b00000000,	0b00000000,	0b11111111}, 
/*U*/	{0b11111111, 	0b00000001, 0b00000000, 0b11111100, 0b11111100, 0b00000000, 0b00000001, 0b11111111}, 
/*R*/	{0b11111111, 	0b10011100, 0b00001001, 0b00100011, 0b00100111, 0b00000000, 0b00000000, 0b11111111},
/*B*/	{0b11111111, 	0b11110001, 0b10000000, 0b00101100, 0b00101100, 0b00000000, 0b00000000, 0b11111111},
/* */ 	{0b11111111, 	0b11111111,	0b11111111,	0b11111111,	0b11111111,	0b11111111,	0b11111111,	0b11111111}, 
/*O*/	{0b11111111, 	0b10000001, 0b00000000, 0b00111100, 0b00111100, 0b00000000, 0b10000001, 0b11111111},
/*A*/	{0b11111111, 	0b10000000, 0b00000000, 0b00110011, 0b00110011, 0b00000000, 0b10000000, 0b11111111},
/*O*/	{0b11111111, 	0b10000001, 0b00000000, 0b00111100, 0b00111100, 0b00000000, 0b10000001, 0b11111111},
/*J*/	{0b11111111, 	0b00111111, 0b00111111, 0b00000001, 0b00000000, 0b00111100, 0b00110000, 0b11110001},
};


char imagem = 0; // basicamente é o elemento que preciso mostrar no display.
char ala = 0;


int delay(){
	int i=0;	
	for(i;i<250;i++){
	}
}

int delays(){
	long int i=0;
	for(i;i<2500;i++){
	}
}

char dotmatrix2(char imagem2){
	char ala = 0;
	for(ala; ala < 8; ala++){
				if(ala == 0){
					PORTC = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala];
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 1){
					PORTC = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 1];
					delay();
					PORTD = 0b00000010;
					delay();

				
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala];
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 2){
					PORTC = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 2];
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 1];
					delay();
					PORTD = 0b00000010;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala];
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 3){
					PORTC = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 3];
					delay();
					PORTD = 0b00001000;
					delay();

					
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 2];
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 1];
					delay();
					PORTD = 0b00000010;
					delay();
					
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala];
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 4){
					PORTC = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 4];
					delay();
					PORTD = 0b00010000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 3];
					delay();
					PORTD = 0b00001000;
					delay();


					PORTD = 0b00000000;
					delay();					
					PORTB = string[imagem2][ala - 2];
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 1];
					delay();
					PORTD = 0b00000010;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala];
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 5){
					PORTC = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 5];
					delay();
					PORTD = 0b00100000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 4];
					delay();
					PORTD = 0b00010000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 3];
					delay();
					PORTD = 0b00001000;
					delay();

					
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 2];
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 1];
					delay();
					PORTD = 0b00000010;
					delay();
		
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala];
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 6){
					PORTC = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 6];
					delay();
					PORTD = 0b01000000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 5];
					delay();
					PORTD = 0b00100000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 4];
					delay();
					PORTD = 0b00010000;
					delay();


					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 3];
					delay();
					PORTD = 0b00001000;
					delay();

					
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 2];
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 1];
					delay();
					PORTD = 0b00000010;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala];
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 7){
					PORTC = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 7];
					delay();
					PORTD = 0b10000000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 6];
					delay();
					PORTD = 0b01000000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 5];
					delay();
					PORTD = 0b00100000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 4];
					delay();
					PORTD = 0b00010000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 3];
					delay();
					PORTD = 0b00001000;
					delay();

					
					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 2];
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala - 1];
					delay();
					PORTD = 0b00000010;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTB = string[imagem2][ala];
					delay();
					PORTD = 0b00000001;
					delay();
					PORTD = 0b00000000;
					delay();
				}
			}
			ala = 0;
}


main(){
	TRISB = 0b00000000;
	TRISC = 0b00000000;
	TRISD = 0b00000000;
	while(1){
		PORTB = 0b11111111;
		PORTC = 0b11111111;
		PORTD = 0b00000000;
		for(imagem; imagem < 10; imagem++){
			for(ala; ala < 8; ala++){
				if(ala == 0){
					PORTB = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala];
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 1){
					PORTB = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 1];
					delay();
					PORTD = 0b00000010;
					delay();

				
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala];
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 2){
					PORTB = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 2];
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 1];
					delay();
					PORTD = 0b00000010;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 3){
					PORTB = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 3];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00001000;
					delay();

					
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 2];
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 1];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000010;
					delay();
					
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 4){
					PORTB = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 4];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00010000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 3];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00001000;
					delay();


					PORTD = 0b00000000;
					delay();					
					PORTC = string[imagem][ala - 2];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 1];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000010;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 5){
					PORTB = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 5];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00100000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 4];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00010000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 3];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00001000;
					delay();

					
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 2];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 1];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000010;
					delay();
		
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 6){
					PORTB = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 6];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b01000000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 5];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00100000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 4];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00010000;
					delay();


					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 3];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00001000;
					delay();

					
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 2];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 1];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000010;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000001;
					delay();
				}
				if(ala == 7){
					PORTB = 0b11111111;
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 7];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b10000000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 6];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b01000000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 5];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00100000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 4];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00010000;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 3];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00001000;
					delay();

					
					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 2];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000100;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala - 1];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000010;
					delay();

					PORTD = 0b00000000;
					delay();
					PORTC = string[imagem][ala];
					PORTD = 0b00000000;
					delay();
					PORTD = 0b00000001;
					delay();
					PORTD = 0b00000000;
					delay();
					dotmatrix2(imagem);
				}
			}
			ala = 0;
			delays();
		}
		imagem = 0;
	}
}