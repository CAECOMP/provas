//**************************************************************************
//* Funções básicas para módulo LCD de caractere
//* Autor: Fábio Pereira
//* Para o livro PIC18 Detalhado: Hardware e Software
//**************************************************************************

// Os defines a seguir setam os pinos padrão do display LCD
#define LCD_ENABLE      LATEbits.LATE1 		// ENABLE no pino RE1
#define LCD_RS		    LATEbits.LATE0 		// R/S no pino RE0

#define LCD_SEC_LINE    0x40    	 		// Address of the second line of the LCD

// LCD configuration constants
#define CURSOR_ON       2
#define CURSOR_OFF      0
#define CURSOR_BLINK    1
#define CURSOR_NOBLINK  0
#define DISPLAY_ON      4
#define DISPLAY_OFF     0
#define DISPLAY_8X5     0
#define DISPLAY_10X5    4
#define _2_LINES        8
#define _1_LINE         0

#define FOSC_CLK		4000

// Variável global de configuração do display
static char lcd_mode;	

//**************************************************************************
//* Protótipos
//**************************************************************************
void LCD_send_nibble(char data);
void LCD_send_byte(char address, char data);
void LCD_init(char mode1, char mode2);
void LCD_pos_xy(char x, char y);
void LCD_write_char(char c);
void LCD_write_string (char *c);
void LCD_display_on(void);
void LCD_display_off(void);
void LCD_cursor_on(void);
void LCD_cursor_off(void);
void LCD_cursor_blink_on(void);
void LCD_cursor_blink_off(void);

//**************************************************************************
//* Uma função de atraso utilizada pelas funções do LCD
//**************************************************************************
//* Argumentos:
//* unsigned char time: tempo aproximado em milisegundos
//**************************************************************************
void LCD_delay_ms (unsigned char time)
{
	unsigned char temp;
	for(;time;time--) for(temp=(FOSC_CLK/20);temp;temp--);
}

//**************************************************************************
//* Escreve um byte no LCD
//**************************************************************************
//* Argumentos:
//* char address : 0 para comandos, 1 para dados
//* char data : comando ou dado a ser escrito
//**************************************************************************
void LCD_send_byte(char address, char data)
{
	unsigned char temp;
	LCD_RS = address;               // configura linha R/S	
	LATD = data;					// escreve o dado
	LCD_ENABLE = 1;                 // habilita o display
	for (temp=100; temp; temp--);
	LCD_ENABLE = 0;					// desabilita display
	for (temp=100; temp; temp--);
}


//**************************************************************************
//* Inicialização do LCD
//**************************************************************************
//* Argumentos de chamada:
//* char mode1 : modo (número de linhas e tamanho do caractere)
//* char mode2 : modo (cursor e estado do display)
//**************************************************************************
void LCD_init(char mode1, char mode2)
{
	char aux;
	// configura os pinos de dados do LCD para zero
	TRISD = 0;
	TRISEbits.TRISE0 = 0;
	TRISEbits.TRISE1 = 0;
	LATD = 0;
	LCD_RS = 0;
	LCD_ENABLE = 0;
	LCD_delay_ms(50);
	// Sequencia de inicialização do LCD para 8 bits
	// Envia três vezes o valor 0x30
	for(aux=0;aux<3;++aux)
	{		
	  LCD_send_byte(0,0x30);
	  LCD_delay_ms(5);
	}
	// Envia configuração
	LCD_send_byte(0,0x30 | mode1);
	LCD_send_byte(0,0x08);
	LCD_send_byte(0,0x01);
	LCD_send_byte(0,0x06);
	LCD_send_byte(0,0x08 | mode2);
	lcd_mode = 0x08 | mode2;
}

//**************************************************************************
//* Configura a posição do cursor
//**************************************************************************
//* Argumentos de chamada:
//* char x : coluna (começando por 0)
//* char y : linha (0 ou 1)
//**************************************************************************
void LCD_pos_xy(char x, char y)
{
  char address;
  if (y) address = LCD_SEC_LINE; else address = 0;
  address += x;
  LCD_send_byte(0,0x80|address);
}

//**************************************************************************
//* Escreve um caractere no display
//**************************************************************************
//* Argumentos de chamada:
//* char c : caractere a ser escrito
//**************************************************************************
//* Notas :
//* \f apaga o display
//* \n e \r retornam o cursor para a linha 0 coluna 0
//**************************************************************************
void LCD_write_char(char c)
{
  switch (c)
	{
	  case '\f' :	
	    LCD_send_byte(0,1);
	    LCD_delay_ms(5);
	    break;
	  case '\n' :
	  case '\r' :	
	    LCD_pos_xy(0,0);
	    break;
	  default:
	    LCD_send_byte(1,c);
   }
}

//**************************************************************************
//* Escreve uma string da memória de programa no display
//**************************************************************************
//* Argumentos de chamada:
//* const rom char *c : ponteiro para a string na memória de programa
//**************************************************************************
void LCD_write_string_rom (const rom char *c)
{
	while (*c) LCD_write_char(*c++);
}

//**************************************************************************
//* Escreve uma string no display
//**************************************************************************
//* Argumentos de chamada:
//* char *c : ponteiro para a string
//**************************************************************************
void LCD_write_string (char *c)
{
	while (*c) LCD_write_char(*c++);
}

//**************************************************************************
//* Liga o display
//**************************************************************************
void LCD_display_on(void)
{
	lcd_mode |= 4;
	LCD_send_byte (0,lcd_mode);
}

//**************************************************************************
//* Desliga o display
//**************************************************************************
void LCD_display_off(void)
{
	lcd_mode &= 0xFB;
	LCD_send_byte (0,lcd_mode);
}

//**************************************************************************
//* Liga o cursor
//**************************************************************************
void LCD_cursor_on(void)
{
  	lcd_mode |= 2;
	LCD_send_byte (0,lcd_mode);
}

//**************************************************************************
//* Desliga o cursor
//**************************************************************************
void LCD_cursor_off(void)
{
	lcd_mode &= 0xFD;
	LCD_send_byte (0,lcd_mode);
}
//**************************************************************************
//* Liga o cursor piscante
//**************************************************************************
void LCD_cursor_blink_on(void)
{
	lcd_mode |= 1;
	LCD_send_byte (0,lcd_mode);
}

//**************************************************************************
//* Desliga o cursor piscante
//**************************************************************************
void LCD_cursor_blink_off(void)
{
	lcd_mode &= 0xFE;
	LCD_send_byte (0,lcd_mode);
}

