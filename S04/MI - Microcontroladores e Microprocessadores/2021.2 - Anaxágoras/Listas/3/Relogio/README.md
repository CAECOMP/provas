# Relógio Digital KeyPad  - _PIC 18F4520_

![DEMO](https://github.com/jbrun0r/RELOGIO-KEYPAD-PIC-18F4520/blob/main/RELOGIOTECLADO.gif?raw=true)

**Relógio Digital** com 6 dígitos, com acerto através de um _Teclado Matricial 4x3._

## Resumo:
Usando um **PIC-18F4520** e as ferramentas **MPLAB** e **Proteus**, desenvolva
os seguintes _Sistemas Embarcados_, aplicando a técnica de varredura
para a leitura de teclado e impressão em displays de 7 segmentos: Um **Relógio Digital** com 6 dígitos, com acerto das horas feito
por _teclado matricial 4x3_ (componente _KEYPAD-PHONE_ no proteus).


## Design:

![fundo](https://github.com/jbrun0r/RELOGIO-KEYPAD-PIC-18F4520/blob/main/RELOGIOTECLADO.png?raw=true)\
Utilizei o **Proteus Design Suite (Proteus)** para a criação do projeto eletrônico, composto por uma suíte de ferramentas, incluindo captura esquemática, simulação e módulos de projetos de placas de circuito impresso, usadas principalmente para o projeto de circuitos integrados. Utilizei O **MPLAB IDE** para gerenciamento do projeto e **Compilador C18**.\
Seguindo as orientações do datasheet do PIC supracitado, escreveremos o código/lógica em linguagem .c e compilamos com **C18** para arquivo **.cof** ou **.hex.**
___

#### Ferramentas:

* [PIC-18F4520](https://ww1.microchip.com/downloads/en/DeviceDoc/39631E.pdf)
* Proteus 7.8 Professional Portable
* [MPLAB IDE](https://www.microchip.com/en-us/tools-resources/archives/mplab-ecosystem)
* C18 Compiler
* **SO:** Windows 10/11 (64-bit Required)
