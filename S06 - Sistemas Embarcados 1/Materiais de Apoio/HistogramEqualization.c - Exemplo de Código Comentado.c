/*  
 * file : HistogramEqualization.h* 
 * 
 * 
 * Entradaa: arquivos na formatação definida no arquivo 'Imagens.h'
 * Saídaa: matriz com os dados equalizados da imagem de entrada e os histogramas
 * de intensidades,função de densidade,acumulado e equalizado para a referida 
 * imagem.
 *  
 * Plataforma Alvo : PIC18F4550 (Microchip)
 * Compilador : XC8 (Microchip)
 * IDE :  MPLABX (Microchip)
 * OBS:Taxa de Transmissão padrão :  9600 (podendo ser alterado na função MAIN).
 * 
 * O presente algoritmo foi implementado com referencia ao procedimento de 
 * equalização de histogramas e imagens apresentado no livro Processamento DigitAL
 * de Imagens dos Autores Gonzales e Woods como trabalho na cadeira de Sistemas 
 * embarcados do CURSO DE ENGENHARIA DE COMPUTAÇÃO DO IFCE CAMPUS FORTALEZA 
 * sob a orientação do PROFESSOR ELIAS TEODORO.   * 
 * 
 *  Authors : Andre Vieira e Luan Barroso
 * 
 *  Copyright (C) 2018 Andre Vieira <sgavsnake@gmail.com>
 *  Copyright (C) 2018 Luan Pontes  <pontesluanlx@gmail.com> * 
 *  Data de Atualização : 30 de maio de 2018
 *   * 
 *  Modo de uso:  os valores dos vetores existentes neste arquivo são
 *              utilizados para calcular os histogramas nos algoritmos da aplicação
 *              os valores definidos fazem referencia aos dados de uma imagem em formato .pgm
 *              doo tipo P2;
 *              O numero maximo de pixels de cada imagem testado para o armazenamento em 
 *              constantes para o presente trabalho foram de 4070 pixels,com dimensões de 
 *              55 por 74 pixels. 
 *              Este trabalho possui duas imagens locaizadas na pasta Imagens.h formatadas
 *              com formato definido no cabeçalho de cada imagem para inserir outras imagens
 *              basta seguir o padrão já definido.
 *              Para uso do algoritmo altere o valor do parametro da função 
 *              "selectEqualizeImagem(parametro)" para 1 ou 2 conforme imagem que deseja que sejam realizado
 *              os procedimentos do algoritmo ou valor que desejar caso tenha inserido alguma imagem.              
 *              Em um programa de terminal com interface serial os resultados serão impressos bastando
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


#include <stdio.h> //uso da função use a sprintf function
#include <p18f4550.h>//target dispositive 
#include <xc.h> //target compiler

#include "Cabecalho_Configuracao_Bits.h"////configuração de registradores
#include"USART.h" // Arquivo para os metodos da transmissão serial UART
#include"Imagens.h"//Arquivo com os dados da imagens


#define MAXVALUEPIXELSINIMAGE 256 // maximo do pixel de uma imagem
long long int Histogram[MAXVALUEPIXELSINIMAGE]; //vetor global para o armazenamento do resultados dos calculos dos histogramas

//representação dos dados das imagens para aplicação no algorimo

struct TImage {//struct tipo imagem ,abstração
    char * NameImage; //nome da imagem
    long long int SizeLine; //tamanho da linha da matriz da imagem
    long long int SizeColunm; //tamanho da coluna da matriz imagem
    long long int Size; //quantidade de pixels da imagens
    long long int Fator; //fator de correção para o cálculo na imagem
    int MaxValue; //maior valr de intensidade presente na imagem        
} typedef Image; //definição de tipo Imagem


/*Função  : Transmissão dos dados de um histograma via serial cada valor de posição do array é convertido 
 * em string e enviado pela serial.
 * 
 * Entrada : array -> Um vetor representando o histograma e o tamanho deste vetor.
 * Retorno : NADA
 * Saída   : Texto pela Serial em formato ASCII com formatação para array ex:[0,1,2,3,4,5,6,...,n].
 
 * Variáveis Locais: Index,y.
 * Variáveis Globais Usadas : array Histogram(refenciada por parametro ArrayHistogram)
 * Variáveis Globais Alteradas : NENHUMA
 */
void transmitHistogramValues(long long int Array[], int Size) {
    char y[10]; //string para buffer da função da de tranmissão de string pela serial  
    int Index; //controle de carredura de vetores 
    USART_SendString("{"); //envio de caracter para abrir formatação na saida
    for (Index = 0; Index < Size - 1; Index++) {
        sprintf(y, "%lld", Array[Index]); //conversão de  numerico para string
        USART_SendString(y); //conversão de  numerico para string
        USART_SendString(", "); //envio de caracter para formatação na saida
        __delay_ms(10); //delays para facilitar o monitoramento da saida
    }
    sprintf(y, "%lld", Array[Index]); //conversão de  numerico para string
    USART_SendString(y); //conversão de  numerico para string
    USART_SendString("]"); //envio de caracter para fechar formatação na saida    
    USART_SendString("\r\n"); //envio de caracter para fechar formatação na saida retorno de carro e salto de linha
}

/*Função: Calcula o Histograma de Intensidades,cada posição do histograma representa uma
 * intensidade de pixel da imagem que é incrementada cada vez que é encontrada na matriz de
 * intensidades da imagem.
 * 
 * Entrada : Tipo Image -> abstraçao com os dados da imagem
 *           array long long int ArrayHistogram -> histogram com estado inicial
 *           const int arrayImage -> matriz dos pixels da imagem alvo
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "histogram")...
 * Saída   : NADA
 * 
 * Variáveis Locais: Index
 * Variáveis Globais Usadas : array Histogram (referenciada por parametro ArrayHistogram)
 *                            const arrayImage -> parametro que referencia a matriz da imagem armazenda na memória ROM.
 * 
 * Variáveis Globais Alteradas : Histogram (agora guarda os valores do histograma de intensidades)
 */
void CalcHistogramIntensities(Image Image, const int ArrayImage[], long long int ArrayHistogram[]) {
    int Index;//indexidador para controle de varredura do vetor
    for (Index = 0; Index < Image.Size; Index++) {//varredura incremental
        ArrayHistogram[ArrayImage[Index]]++;//calculo da intensidades para o histogram
    }    
}


/*Função: Calcula o Função de Probabilidade de Densidade da Imagem,cada posição do histograma de intensidades é 
 * mutiplicado por um fator que define a precisão em casa decimais requerida sendo depois 
 * normalizado,dividido pelo pelo quantidade de pixels da matriz que representa a imagem.
 * 
 * Entrada : Tipo Image,abstraçao com os dados da imagem
 *           array long long int ArrayHistogram com Histograma de intensidades calculado
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "histogram")... * 
 * Saída   : NADA
 * 
 * Variáveis Locais: int Index
 * Variáveis Globais Usadas : Histogram (referenciada por parametro ArrayHistogram)
 * Variáveis Globais Alteradas : Histogram (agora guarda os valores do histograma da Função de Densidade de Probabilidade)
 */
void CalcHistogramPDF(Image Image, long long int ArrayHistogram[]) {    
    int Index;//indexidador para controle de varredura do vetor
    for (Index = 0; Index < Image.MaxValue; Index++) {//varredura incremental
        ArrayHistogram[Index] = (ArrayHistogram[Index] * Image.Fator) / Image.Size;//calculo da da densidade para o cada posição do histogram com fator decimal
    }    
}

/*Função: Calcula o Acmulado da Função de Probabilidade de Densidade da Imagem,cada posição
 * é a soma do PDFHistogram na Posição atual mais a soma de todos os valores das posições anteriores
 * do a calculados.
 * 
 * Entrada : Tipo Image ->abstração da imagem
 *           array long long int ArrayHistogram com Histograma da Função de Densidade de Probabilidade calculado(PDF).
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "histogram")...
 * Saída   : NADA
 * 
 * Variáveis Locais: int Index
 * Variáveis Globais Usadas : Histogram (referenciada por parametro ArrayHistogram)
 * Variáveis Globais Alteradas : Histogram (agora guarda os valores do histograma do acumulado da PDF)
 */
void CalcAccumulatedHistogram(Image Image, long long int ArrayHistogram[]) {
    int Index;//controle de indexição do vator
    for (Index = 1; Index < Image.MaxValue; Index++) {//varredura incremental
        ArrayHistogram[Index] = ArrayHistogram[Index - 1] + ArrayHistogram[Index];//calculo do acumulado(ver comentário)
    }
}


/*Função: Calcula o Histograma Equalizado,cada posição do vetor é o produto do Histograma Acumulado
 * ,guardado na variável global "Histogram ", na posição atual pela resolução da camada da imagem 
 * sendo posteriormente corrigido por um fator predeinido que devolve os valores das intensidades do histograma
 *  resultante à faixa adequada de valores dos pixels da matriz da imagem de entrada.
 * 
 * Entrada : Tipo Image -> abstração da imagem
 *           array long long int ArrayHistogram com Histograma do Acumulado Função de Densidade de Probabilidade calculado(PDF)
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "histogram")... * 
 * Saída   : NADA.
 * 
 * Variáveis Locais: int Index
 * Variáveis Globais Usadas : Histogram (referenciada por parametro ArrayHistogram)
 * Variáveis Globais Alteradas : Histogram (agora guarda os valores do histograma Equalizado)
 */
void CalcEqualizedHistogram(Image Image, long long int ArrayHistogram[]) {
    int Index;//controle de indexação da varredura
    for (Index = 0; Index < Image.MaxValue; Index++) {//varredura incremental
        ArrayHistogram[Index] = ((Image.MaxValue - 1) * (ArrayHistogram[Index])) / Image.Fator;//calculo  do equalizado
    }    
}

/*Função: Transmite o cabaçalho que representa a imagem em formato PGM tipo P2
 * com os dados pertinentes ao formato.
 *  
 * Entrada : Tipo Image. -> //abstração da imagem
 * 
 * Retorno : NADA(void).
 * Saída   : Saida em formatao ASCII pela serial dos dados do formato da imagem .pgm tipo P2.
 * 
 * Variáveis Locais: y
 * Variáveis Globais Usadas : NENHUMA.
 * Variáveis Globais Alteradas : NENHUMA.
 */
void transmitHeaderImage(Image Image){
    unsigned char y[4];        
    USART_SendString("P2");//Envio pela serial do formato de escrita dos pixels da imagem
    USART_SendString("\r\n");//envio pela seria retorno de carro salto de linha
    sprintf(y, "%d", Image.SizeColunm - 1);//conversão tamanho da coluna da imagem para string 
    USART_SendString(y);//envio pela serial da string convertida 
    USART_SendString(" ");//envio pela serial caracter espaço
    sprintf(y, "%d", Image.SizeLine - 1);//conversão tamanho da linha da imagem para string 
    USART_SendString(y);//envio pela seria retorno de carro salto de linha
    USART_SendString("\r\n");//envio pela serial retorno de carro salto de linha
    sprintf(y, "%d", Image.MaxValue - 1);//conversão maior valor de pixels da imagem para string 
    USART_SendString(y);//envio pela serial a string convertida
    USART_SendString("\r\n");    //envio pela serial retorno de carro salto de linha
}


/*Função: Equaliza a matriz da imagem de entrada,resgata os valores calculados guardados na variável global Histogram
 * de acordo com cada pixel da matriz da imagem original.Cada valor de intensidade de pixel da imagem
 * representa uma posição do vetor equalizado cujo valor referente é o valor corrente na posição do equalizedHistogram que 
 * é enviado pela serial.
 * 
 * Entrada : Tipo Image -> Abstração da imagem de entrada.
 *           array long long int ArrayHistogram com Histograma Equalizado
 *           const int ArrayImage -> matriz da imagem de entrada * 
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "Histogram")...
 * Saída   : Saida em formatao ASCII pela serial dos valores dos pixels da imagem  de entrada equalizados em formato de vetor.
 * 
 * Variáveis Locais: int Index.
 * Variáveis Globais Usadas : Histogram (referenciada pelo parametro ArrayHistogram).
 *                            const arrayImage -> parametro que referencia a matriz da imagem armazenda na memória ROM.
 * Variáveis Globais Alteradas : NENHUMA.
 */
void EqualizeArrayImage(Image Image, const int ArrayImage[], long long int ArrayHistogram[]) {
    char y[4];//string buffer para a conversão dos valores para envia pela serial
    transmitHeaderImage(Image); //tranmissão pela serial do cabeçalho da imagem resultante
    int Index;//controle de indexação do vetor na varredura
    for (Index = 0; Index < Image.Size - 1; Index++) {//varredura incremental
        if (Index % (Image.SizeColunm - 1) == 0 & Index > 0) {//verificação para saltar ao final de cada linha
            USART_SendString("\r\n");//envio de retorno de carro e salto de linha
        }
        sprintf(y, "%d", ArrayHistogram[ArrayImage[Index]]);//conversão de valores para string
        USART_SendString(y);//envio de string convertida pela serial
        USART_SendString(" ");//envio de caracter espaço
    }
    sprintf(y, "%d", ArrayHistogram[ArrayImage[Index]]);//conversão de valores para string
    USART_SendString(y);//envio de string convertida pela serial
    USART_SendString("\r\n");//envio de espaço
}

/*Função: Envia pela serial a matriz equalizada da imagem de entrada,resgata os valores calculados do histograma equalizado
 * guardados na variável global Histogram de acordo com cada pixel da matriz da imagem original.Cada valor de intensidade de pixel da imagem
 * representa uma posição do vetor equalizado cujo valor referente é o valor corrente na posição do equalizedHistogram que 
 * é enviado pela serial.
 * 
 * Entrada : Tipo Image -> Abstração da imagem de entrada. 
 *           const int ArrayImage -> matriz da imagem de entrada.
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "Histogram")...
 * Saída   : Saida em formatao ASCII pela serial dos valores dos Histogramas e dos pixels da imagem equalizado.
 * 
 * Variáveis Locais: NENHUMA
 * Variáveis Globais Usadas : Histogram (referenciada pelo parametro ArrayHistogram).
 *                            const arrayImage -> parametro que referencia a matriz da imagem armazenda na memória ROM.
  * Variáveis Globais Alteradas : Histogram (agora guarda os valores do histograma do Equalizado). *                               
 */
void principal(Image image, const int arrayImage[]) {    
    USART_SendString("\r\nProcessando Histogramas da Imagem :");//envio pela serial de string informando estado do programa
    USART_SendString(image.NameImage);//envio serial do nome da imagem no processamento corrente 
    USART_SendString("\r\n"); //envio de retorno de carro e salto de linha
    
    USART_SendString("Calculando Histograma de Intensidades\r\n");//envio de string informando estado do programa
    CalcHistogramIntensities(image, arrayImage, Histogram);    //calculo do histograma de intensidades
    transmitHistogramValues(Histogram,image.MaxValue);//envio de histograma de intensadades
    USART_SendString("\r\n");     //envio de retorno de carro e salto de linha
    
    USART_SendString("Calculando Histograma de Função de Densidade\r\n");//envio de string informando estado do programa
    CalcHistogramPDF(image, Histogram); //calculo do histograma da função de densidade
    transmitHistogramValues(Histogram,image.MaxValue);//envio pela serial de histograma da função de densidade
    USART_SendString("\r\n"); //envio de retorno de carro e salto de linha    

    USART_SendString("Calculando Histograma de Acumulado da Função de Densidade\r\n");//envio de string informando estado do programa
    CalcAccumulatedHistogram(image, Histogram);//calculo do histograma do acumulado da funcçao de densidade
    transmitHistogramValues(Histogram,image.MaxValue);//envio pela serial de histograma Acumulado
    USART_SendString("\r\n");     //envio de retorno de carro e salto de linha
    
    USART_SendString("Calculando Histograma Equalizado\r\n");//envio de string informando estado do programa
    CalcEqualizedHistogram(image, Histogram);//calculo do histograma Equalizado 
    transmitHistogramValues(Histogram,image.MaxValue);//envio pela serial de histograma equalizado
    USART_SendString("\r\n");     //envio de retorno de carro e salto de linha
    
    USART_SendString("Equalizando Matriz da Imagem\r\n");//envio de string informando estado do programa
    EqualizeArrayImage(image, arrayImage, Histogram);    //Equalização da matriz da imagem 
    USART_SendString("\r\n");         //envio de retorno de carro e salto de linha
    USART_SendString("\r\n...FIM...");//envio de string informando estado do programa
}


/*Função: Seleciona a imagem,mapeia os dados da imagem da memória ROM para uma struct Image, para o processamento de calculo  dos histograma e equalização 
 * da matriz da imagem e chama a função principal passando a imagem como parametro para a função.
 * 
 * Entrada : int opt -> inteiro que identifica uma imagem armazenada na ROM.
 * 
 * Retorno : NADA(void) ...OBS:(altera o valor do vetor global "Histogram")...
 * Saída   : Saida em formatao ASCII pela serial dos valores dos Histogramas e dos pixels da imagem equalizado.
 * 
 * Variáveis Locais: Image Image  -> abstração da imagem.
 * Variáveis Globais Usadas : Histogram (referenciada pelo parametro ArrayHistogram).
 *                            const arrayImage -> parametro que referencia a matriz da imagem armazenda na memória ROM.
  * Variáveis Globais Alteradas : Histogram (ao final guarda os valores do histograma do Equalizado). *                               
 */
void selectEqualizeImagem(int opt) {
    Image image;//inicialização do tipo imagem    
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

/*Função: Ponto de Entrada,Configura comunicação serial e  Executa uma unica vez o algoritmo ficandopresa em loop.
 * Entrada : NADA
 * Retorno : NADA
 * Saída   : NADA
 * 
 * Variáveis Locais: NENHUMA
 * Variáveis Globais Usadas : NENHUMA
  * Variáveis Globais Alteradas : Histogram (ao final guarda os valores do histograma do Equalizado). *                               
 */
void main() {
    USART_Start(9600);//configuração da velocidade de transmissão
    selectEqualizeImagem(1);//chamada da função para selecionar a imagem    
    while (1);//loop infinito
}


