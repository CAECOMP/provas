/*  
 * file : HistogramEqualization.h* 
 * 
 * 
 * Entradaa: arquivos na formata��o definida no arquivo 'Imagens.h'
 * Sa�daa: matriz com os dados equalizados da imagem de entrada e os histogramas
 * de intensidades,fun��o de densidade,acumulado e equalizado para a referida 
 * imagem.
 *  
 * Plataforma Alvo : PIC18F4550 (Microchip)
 * Compilador : XC8 (Microchip)
 * IDE :  MPLABX (Microchip)
 * OBS:Taxa de Transmiss�o padr�o :  9600 (podendo ser alterado na fun��o MAIN).
 * 
 * O presente algoritmo foi implementado com referencia ao procedimento de 
 * equaliza��o de histogramas e imagens apresentado no livro Processamento DigitAL
 * de Imagens dos Autores Gonzales e Woods como trabalho na cadeira de Sistemas 
 * embarcados do CURSO DE ENGENHARIA DE COMPUTA��O DO IFCE CAMPUS FORTALEZA 
 * sob a orienta��o do PROFESSOR ELIAS TEODORO.   * 
 * 
 *  Authors : Andre Vieira e Luan Barroso
 * 
 *  Copyright (C) 2018 Andre Vieira <sgavsnake@gmail.com>
 *  Copyright (C) 2018 Luan Pontes  <pontesluanlx@gmail.com> * 
 *  Data de Atualiza��o : 30 de maio de 2018
 *   * 
 *  Modo de uso:  os valores dos vetores existentes neste arquivo s�o
 *              utilizados para calcular os histogramas nos algoritmos da aplica��o
 *              os valores definidos fazem referencia aos dados de uma imagem em formato .pgm
 *              doo tipo P2;
 *              O numero maximo de pixels de cada imagem testado para o armazenamento em 
 *              constantes para o presente trabalho foram de 4070 pixels,com dimens�es de 
 *              55 por 74 pixels. 
 *              Este trabalho possui duas imagens locaizadas na pasta Imagens.h formatadas
 *              com formato definido no cabe�alho de cada imagem para inserir outras imagens
 *              basta seguir o padr�o j� definido.
 *              Para uso do algoritmo altere o valor do parametro da fun��o 
 *              "selectEqualizeImagem(parametro)" para 1 ou 2 conforme imagem que deseja que sejam realizado
 *              os procedimentos do algoritmo ou valor que desejar caso tenha inserido alguma imagem.              
 *              Em um programa de terminal com interface serial os resultados ser�o impressos bastando
 *              transferi-los para um arquivo .txt e alterar o formato do arquivo para '.pgm'
 * 
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


#include <stdio.h> //uso da fun��o use a sprintf function
#include <p18f4550.h>//target dispositive 
#include <xc.h> //target compiler

#include "Cabecalho_Configuracao_Bits.h"////configura��o de registradores
#include"USART.h" // Arquivo para os metodos da transmiss�o serial UART
#include"Imagens.h"//Arquivo com os dados da imagens


#define MAXVALUEPIXELSINIMAGE 256 // maximo do pixel de uma imagem
long long int Histogram[MAXVALUEPIXELSINIMAGE]; //vetor global para o armazenamento do resultados dos calculos dos histogramas

//representa��o dos dados das imagens para aplica��o no algorimo

struct TImage {//struct tipo imagem ,abstra��o
    char * NameImage; //nome da imagem
    long long int SizeLine; //tamanho da linha da matriz da imagem
    long long int SizeColunm; //tamanho da coluna da matriz imagem
    long long int Size; //quantidade de pixels da imagens
    long long int Fator; //fator de corre��o para o c�lculo na imagem
    int MaxValue; //maior valr de intensidade presente na imagem        
} typedef Image; //defini��o de tipo Imagem


/*Fun��o  : Transmiss�o dos dados de um histograma via serial cada valor de posi��o do array � convertido 
 * em string e enviado pela serial.
 * 
 * Entrada : array -> Um vetor representando o histograma e o tamanho deste vetor.
 * Retorno : NADA
 * Sa�da   : Texto pela Serial em formato ASCII com formata��o para array ex:[0,1,2,3,4,5,6,...,n].
 
 * Vari�veis Locais: Index,y.
 * Vari�veis Globais Usadas : array Histogram(refenciada por parametro ArrayHistogram)
 * Vari�veis Globais Alteradas : NENHUMA
 */
void transmitHistogramValues(long long int Array[], int Size) {
    char y[10]; //string para buffer da fun��o da de tranmiss�o de string pela serial  
    int Index; //controle de carredura de vetores 
    USART_SendString("{"); //envio de caracter para abrir formata��o na saida
    for (Index = 0; Index < Size - 1; Index++) {
        sprintf(y, "%lld", Array[Index]); //convers�o de  numerico para string
        USART_SendString(y); //convers�o de  numerico para string
        USART_SendString(", "); //envio de caracter para formata��o na saida
        __delay_ms(10); //delays para facilitar o monitoramento da saida
    }
    sprintf(y, "%lld", Array[Index]); //convers�o de  numerico para string
    USART_SendString(y); //convers�o de  numerico para string
    USART_SendString("]"); //envio de caracter para fechar formata��o na saida    
    USART_SendString("\r\n"); //envio de caracter para fechar formata��o na saida retorno de carro e salto de linha
}

/*Fun��o: Calcula o Histograma de Intensidades,cada posi��o do histograma representa uma
 * intensidade de pixel da imagem que � incrementada cada vez que � encontrada na matriz de
 * intensidades da imagem.
 * 
 * Entrada : Tipo Image -> abstra�ao com os dados da imagem
 *           array long long int ArrayHistogram -> histogram com estado inicial
 *           const int arrayImage -> matriz dos pixels da imagem alvo
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "histogram")...
 * Sa�da   : NADA
 * 
 * Vari�veis Locais: Index
 * Vari�veis Globais Usadas : array Histogram (referenciada por parametro ArrayHistogram)
 *                            const arrayImage -> parametro que referencia a matriz da imagem armazenda na mem�ria ROM.
 * 
 * Vari�veis Globais Alteradas : Histogram (agora guarda os valores do histograma de intensidades)
 */
void CalcHistogramIntensities(Image Image, const int ArrayImage[], long long int ArrayHistogram[]) {
    int Index;//indexidador para controle de varredura do vetor
    for (Index = 0; Index < Image.Size; Index++) {//varredura incremental
        ArrayHistogram[ArrayImage[Index]]++;//calculo da intensidades para o histogram
    }    
}


/*Fun��o: Calcula o Fun��o de Probabilidade de Densidade da Imagem,cada posi��o do histograma de intensidades � 
 * mutiplicado por um fator que define a precis�o em casa decimais requerida sendo depois 
 * normalizado,dividido pelo pelo quantidade de pixels da matriz que representa a imagem.
 * 
 * Entrada : Tipo Image,abstra�ao com os dados da imagem
 *           array long long int ArrayHistogram com Histograma de intensidades calculado
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "histogram")... * 
 * Sa�da   : NADA
 * 
 * Vari�veis Locais: int Index
 * Vari�veis Globais Usadas : Histogram (referenciada por parametro ArrayHistogram)
 * Vari�veis Globais Alteradas : Histogram (agora guarda os valores do histograma da Fun��o de Densidade de Probabilidade)
 */
void CalcHistogramPDF(Image Image, long long int ArrayHistogram[]) {    
    int Index;//indexidador para controle de varredura do vetor
    for (Index = 0; Index < Image.MaxValue; Index++) {//varredura incremental
        ArrayHistogram[Index] = (ArrayHistogram[Index] * Image.Fator) / Image.Size;//calculo da da densidade para o cada posi��o do histogram com fator decimal
    }    
}

/*Fun��o: Calcula o Acmulado da Fun��o de Probabilidade de Densidade da Imagem,cada posi��o
 * � a soma do PDFHistogram na Posi��o atual mais a soma de todos os valores das posi��es anteriores
 * do a calculados.
 * 
 * Entrada : Tipo Image ->abstra��o da imagem
 *           array long long int ArrayHistogram com Histograma da Fun��o de Densidade de Probabilidade calculado(PDF).
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "histogram")...
 * Sa�da   : NADA
 * 
 * Vari�veis Locais: int Index
 * Vari�veis Globais Usadas : Histogram (referenciada por parametro ArrayHistogram)
 * Vari�veis Globais Alteradas : Histogram (agora guarda os valores do histograma do acumulado da PDF)
 */
void CalcAccumulatedHistogram(Image Image, long long int ArrayHistogram[]) {
    int Index;//controle de indexi��o do vator
    for (Index = 1; Index < Image.MaxValue; Index++) {//varredura incremental
        ArrayHistogram[Index] = ArrayHistogram[Index - 1] + ArrayHistogram[Index];//calculo do acumulado(ver coment�rio)
    }
}


/*Fun��o: Calcula o Histograma Equalizado,cada posi��o do vetor � o produto do Histograma Acumulado
 * ,guardado na vari�vel global "Histogram ", na posi��o atual pela resolu��o da camada da imagem 
 * sendo posteriormente corrigido por um fator predeinido que devolve os valores das intensidades do histograma
 *  resultante � faixa adequada de valores dos pixels da matriz da imagem de entrada.
 * 
 * Entrada : Tipo Image -> abstra��o da imagem
 *           array long long int ArrayHistogram com Histograma do Acumulado Fun��o de Densidade de Probabilidade calculado(PDF)
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "histogram")... * 
 * Sa�da   : NADA.
 * 
 * Vari�veis Locais: int Index
 * Vari�veis Globais Usadas : Histogram (referenciada por parametro ArrayHistogram)
 * Vari�veis Globais Alteradas : Histogram (agora guarda os valores do histograma Equalizado)
 */
void CalcEqualizedHistogram(Image Image, long long int ArrayHistogram[]) {
    int Index;//controle de indexa��o da varredura
    for (Index = 0; Index < Image.MaxValue; Index++) {//varredura incremental
        ArrayHistogram[Index] = ((Image.MaxValue - 1) * (ArrayHistogram[Index])) / Image.Fator;//calculo  do equalizado
    }    
}

/*Fun��o: Transmite o caba�alho que representa a imagem em formato PGM tipo P2
 * com os dados pertinentes ao formato.
 *  
 * Entrada : Tipo Image. -> //abstra��o da imagem
 * 
 * Retorno : NADA(void).
 * Sa�da   : Saida em formatao ASCII pela serial dos dados do formato da imagem .pgm tipo P2.
 * 
 * Vari�veis Locais: y
 * Vari�veis Globais Usadas : NENHUMA.
 * Vari�veis Globais Alteradas : NENHUMA.
 */
void transmitHeaderImage(Image Image){
    unsigned char y[4];        
    USART_SendString("P2");//Envio pela serial do formato de escrita dos pixels da imagem
    USART_SendString("\r\n");//envio pela seria retorno de carro salto de linha
    sprintf(y, "%d", Image.SizeColunm - 1);//convers�o tamanho da coluna da imagem para string 
    USART_SendString(y);//envio pela serial da string convertida 
    USART_SendString(" ");//envio pela serial caracter espa�o
    sprintf(y, "%d", Image.SizeLine - 1);//convers�o tamanho da linha da imagem para string 
    USART_SendString(y);//envio pela seria retorno de carro salto de linha
    USART_SendString("\r\n");//envio pela serial retorno de carro salto de linha
    sprintf(y, "%d", Image.MaxValue - 1);//convers�o maior valor de pixels da imagem para string 
    USART_SendString(y);//envio pela serial a string convertida
    USART_SendString("\r\n");    //envio pela serial retorno de carro salto de linha
}


/*Fun��o: Equaliza a matriz da imagem de entrada,resgata os valores calculados guardados na vari�vel global Histogram
 * de acordo com cada pixel da matriz da imagem original.Cada valor de intensidade de pixel da imagem
 * representa uma posi��o do vetor equalizado cujo valor referente � o valor corrente na posi��o do equalizedHistogram que 
 * � enviado pela serial.
 * 
 * Entrada : Tipo Image -> Abstra��o da imagem de entrada.
 *           array long long int ArrayHistogram com Histograma Equalizado
 *           const int ArrayImage -> matriz da imagem de entrada * 
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "Histogram")...
 * Sa�da   : Saida em formatao ASCII pela serial dos valores dos pixels da imagem  de entrada equalizados em formato de vetor.
 * 
 * Vari�veis Locais: int Index.
 * Vari�veis Globais Usadas : Histogram (referenciada pelo parametro ArrayHistogram).
 *                            const arrayImage -> parametro que referencia a matriz da imagem armazenda na mem�ria ROM.
 * Vari�veis Globais Alteradas : NENHUMA.
 */
void EqualizeArrayImage(Image Image, const int ArrayImage[], long long int ArrayHistogram[]) {
    char y[4];//string buffer para a convers�o dos valores para envia pela serial
    transmitHeaderImage(Image); //tranmiss�o pela serial do cabe�alho da imagem resultante
    int Index;//controle de indexa��o do vetor na varredura
    for (Index = 0; Index < Image.Size - 1; Index++) {//varredura incremental
        if (Index % (Image.SizeColunm - 1) == 0 & Index > 0) {//verifica��o para saltar ao final de cada linha
            USART_SendString("\r\n");//envio de retorno de carro e salto de linha
        }
        sprintf(y, "%d", ArrayHistogram[ArrayImage[Index]]);//convers�o de valores para string
        USART_SendString(y);//envio de string convertida pela serial
        USART_SendString(" ");//envio de caracter espa�o
    }
    sprintf(y, "%d", ArrayHistogram[ArrayImage[Index]]);//convers�o de valores para string
    USART_SendString(y);//envio de string convertida pela serial
    USART_SendString("\r\n");//envio de espa�o
}

/*Fun��o: Envia pela serial a matriz equalizada da imagem de entrada,resgata os valores calculados do histograma equalizado
 * guardados na vari�vel global Histogram de acordo com cada pixel da matriz da imagem original.Cada valor de intensidade de pixel da imagem
 * representa uma posi��o do vetor equalizado cujo valor referente � o valor corrente na posi��o do equalizedHistogram que 
 * � enviado pela serial.
 * 
 * Entrada : Tipo Image -> Abstra��o da imagem de entrada. 
 *           const int ArrayImage -> matriz da imagem de entrada.
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "Histogram")...
 * Sa�da   : Saida em formatao ASCII pela serial dos valores dos Histogramas e dos pixels da imagem equalizado.
 * 
 * Vari�veis Locais: NENHUMA
 * Vari�veis Globais Usadas : Histogram (referenciada pelo parametro ArrayHistogram).
 *                            const arrayImage -> parametro que referencia a matriz da imagem armazenda na mem�ria ROM.
  * Vari�veis Globais Alteradas : Histogram (agora guarda os valores do histograma do Equalizado). *                               
 */
void principal(Image image, const int arrayImage[]) {    
    USART_SendString("\r\nProcessando Histogramas da Imagem :");//envio pela serial de string informando estado do programa
    USART_SendString(image.NameImage);//envio serial do nome da imagem no processamento corrente 
    USART_SendString("\r\n"); //envio de retorno de carro e salto de linha
    
    USART_SendString("Calculando Histograma de Intensidades\r\n");//envio de string informando estado do programa
    CalcHistogramIntensities(image, arrayImage, Histogram);    //calculo do histograma de intensidades
    transmitHistogramValues(Histogram,image.MaxValue);//envio de histograma de intensadades
    USART_SendString("\r\n");     //envio de retorno de carro e salto de linha
    
    USART_SendString("Calculando Histograma de Fun��o de Densidade\r\n");//envio de string informando estado do programa
    CalcHistogramPDF(image, Histogram); //calculo do histograma da fun��o de densidade
    transmitHistogramValues(Histogram,image.MaxValue);//envio pela serial de histograma da fun��o de densidade
    USART_SendString("\r\n"); //envio de retorno de carro e salto de linha    

    USART_SendString("Calculando Histograma de Acumulado da Fun��o de Densidade\r\n");//envio de string informando estado do programa
    CalcAccumulatedHistogram(image, Histogram);//calculo do histograma do acumulado da func�ao de densidade
    transmitHistogramValues(Histogram,image.MaxValue);//envio pela serial de histograma Acumulado
    USART_SendString("\r\n");     //envio de retorno de carro e salto de linha
    
    USART_SendString("Calculando Histograma Equalizado\r\n");//envio de string informando estado do programa
    CalcEqualizedHistogram(image, Histogram);//calculo do histograma Equalizado 
    transmitHistogramValues(Histogram,image.MaxValue);//envio pela serial de histograma equalizado
    USART_SendString("\r\n");     //envio de retorno de carro e salto de linha
    
    USART_SendString("Equalizando Matriz da Imagem\r\n");//envio de string informando estado do programa
    EqualizeArrayImage(image, arrayImage, Histogram);    //Equaliza��o da matriz da imagem 
    USART_SendString("\r\n");         //envio de retorno de carro e salto de linha
    USART_SendString("\r\n...FIM...");//envio de string informando estado do programa
}


/*Fun��o: Seleciona a imagem,mapeia os dados da imagem da mem�ria ROM para uma struct Image, para o processamento de calculo  dos histograma e equaliza��o 
 * da matriz da imagem e chama a fun��o principal passando a imagem como parametro para a fun��o.
 * 
 * Entrada : int opt -> inteiro que identifica uma imagem armazenada na ROM.
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "Histogram")...
 * Sa�da   : Saida em formatao ASCII pela serial dos valores dos Histogramas e dos pixels da imagem equalizado.
 * 
 * Vari�veis Locais: Image Image  -> abstra��o da imagem.
 * Vari�veis Globais Usadas : Histogram (referenciada pelo parametro ArrayHistogram).
 *                            const arrayImage -> parametro que referencia a matriz da imagem armazenda na mem�ria ROM.
  * Vari�veis Globais Alteradas : Histogram (ao final guarda os valores do histograma do Equalizado). *                               
 */
void selectEqualizeImagem(int opt) {
    Image image;//inicializa��o do tipo imagem    
    switch (opt) {//mais detalhes no arquivo sobre o mapeamento em Imagem.h
        case 1:
            //inicio  mapeamento dos dados da imagem na struct Imagem
            image.NameImage = NAMEIMAGE;
            image.SizeLine = LINESIZE;
            image.SizeColunm = COLUNMSIZE;
            image.Size = SIZE;
            image.MaxValue = MAXVALUE;
            image.Fator = FATOR;
            principal(image, arrayImage);
            //fim  mapeamento dos dados da imagem na struct Imagem
            break;
        case 2:
            //inicio  mapeamento dos dados da imagem na struct Imagem
            image.NameImage = NAMEIMAGE001;
            image.SizeLine = LINESIZE001;
            image.SizeColunm = COLUNMSIZE001;
            image.Size = SIZE001;
            image.MaxValue = MAXVALUE001;
            image.Fator = FATOR001;
            principal(image, arrayImage001);
            USART_SendString("\r\nProcessando Histogramas da Imagem :");
            //fim  mapeamento dos dados da imagem na struct Imagem
        default:
            USART_SendString("\r\nValor Invalido...");
    }
}

/*Fun��o: Ponto de Entrada,Configura comunica��o serial e  Executa uma unica vez o algoritmo ficandopresa em loop.
 * Entrada : NADA
 * Retorno : NADA
 * Sa�da   : NADA
 * 
 * Vari�veis Locais: NENHUMA
 * Vari�veis Globais Usadas : NENHUMA
  * Vari�veis Globais Alteradas : Histogram (ao final guarda os valores do histograma do Equalizado). *                               
 */
void main() {
    USART_Start(9600);//configura��o da velocidade de transmiss�o
    selectEqualizeImagem(1);//chamada da fun��o para selecionar a imagem    
    while (1);//loop infinito
}


