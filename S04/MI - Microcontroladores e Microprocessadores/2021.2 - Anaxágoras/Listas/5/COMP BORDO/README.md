# Computador de Bordo Veicular- _PIC 18F4520_

![DEMO](https://github.com/jbrun0r/Computador-de-Bordo-PIC-18F4520/blob/main/Comp%20Bordo.gif?raw=true)

**Computador de Bordo Veicular** utilizando o **PIC-18F4520.**

## Resumo:
Usando um **PIC-18F4520** e as ferramentas **MPLAB** e **Proteus**, desenvolva
o seguinte _Sistema Embarcado_: Desenvolva um **Computador de Bordo** de um _veículo_ que mostre a
quilometragem, a velocidade atual e a rotação do motor em
RPM.\

* Utilize o LCD como Interface de display;
* Utilize interrupções externas para a leitura dos
sensores de rotação do motor e de rotação do pneu.
* Utilize a Interrupção de Timer para a base de tempo.

## Design:

![fundo](https://github.com/jbrun0r/Computador-de-Bordo-PIC-18F4520/blob/main/COMPUTADORBORDO.png?raw=true)\
\
Utilizei o **Proteus Design Suite (Proteus)** para a criação do projeto eletrônico, composto por uma suíte de ferramentas, incluindo captura esquemática, simulação e módulos de projetos de placas de circuito impresso, usadas principalmente para o projeto de circuitos integrados. Utilizei O **MPLAB IDE** para gerenciamento do projeto e **Compilador C18**.\
Seguindo as orientações do datasheet do PIC supracitado, escreveremos o código/lógica em linguagem .c e compilamos com **C18** para arquivo **.cof** ou **.hex.**
___

#### Ferramentas:

* [PIC-18F4520](https://ww1.microchip.com/downloads/en/DeviceDoc/39631E.pdf)
* Proteus 7.8 Professional Portable
* [MPLAB IDE](https://www.microchip.com/en-us/tools-resources/archives/mplab-ecosystem)
* C18 Compiler
* **SO:** Windows 10/11 (64-bit Required)
