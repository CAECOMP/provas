# Calculadora Arimética: Sistema Embarcado - _PIC 18F4520_

![DEMO](https://github.com/jbrun0r/Calculadora-Aritm-tica-PIC-18F4520/blob/main/CALCULADORA.gif?raw=true)

**Calculadora Arimética** utilizando o **PIC-18F4520.**

## Resumo:
Usando um **PIC-18F4520** e as ferramentas **MPLAB** e **Proteus**, desenvolva
os seguintes _Sistemas Embarcados_, aplicando a técnica de varredura
para a leitura de teclado e impressão em displays de 7 segmentos: Uma **Calculadora** com as 4 operações aritméticas (somar,
subtrair, multiplicar e dividir). O mostrador da calculadora
deve ser de 6 dígitos. Indicar erro quando o resultado da
operação exceder 6 dígitos e mostrar números fracionados
(substituir a vírgula pelo ponto). Usar o componente
_KEYPAD-SMALLCALC_ do proteus.

## Design:

![fundo](https://github.com/jbrun0r/Calculadora-Aritm-tica-PIC-18F4520/blob/main/CALC.png?raw=true)\
Utilizei o **Proteus Design Suite (Proteus)** para a criação do projeto eletrônico, composto por uma suíte de ferramentas, incluindo captura esquemática, simulação e módulos de projetos de placas de circuito impresso, usadas principalmente para o projeto de circuitos integrados. Utilizei O **MPLAB IDE** para gerenciamento do projeto e **Compilador C18**.\
Seguindo as orientações do datasheet do PIC supracitado, escreveremos o código/lógica em linguagem .c e compilamos com **C18** para arquivo **.cof** ou **.hex.**
___

#### Ferramentas:

* [PIC-18F4520](https://ww1.microchip.com/downloads/en/DeviceDoc/39631E.pdf)
* Proteus 7.8 Professional Portable
* [MPLAB IDE](https://www.microchip.com/en-us/tools-resources/archives/mplab-ecosystem)
* C18 Compiler
* **SO:** Windows 10/11 (64-bit Required)
