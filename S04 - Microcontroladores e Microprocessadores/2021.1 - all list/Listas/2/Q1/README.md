# Relógio Digital - _PIC 18F4520_

![DEMO](https://github.com/jbrun0r/RelogioDigital-PIC18F4520/blob/gif/RelogioPIC.gif?raw=true)

Construção de um Relógio Digital ultizando PIC - 18F4520 sem Interrupções.

## Resumo:
Use o **PIC-18F4520** para construir um **_Relógio Digital_** de 6 dígitos
usando _displays BCD de 7 segmentos_. O relógio também deve contar
com o recurso de **alarme**. O relógio deve ter 1 botão de modo e 2
botões de ajuste para as horas e minutos. O botão de modo alterna
entre o modo de ajuste das horas ou ajuste do alarme e deve ser
acionado somente se pressionado por 2 segundos. Como saída de
alarme, use um beep sonoro.


## Design:

![fundo](https://github.com/jbrun0r/RelogioDigital-PIC18F4520/blob/gif/RELOGIOPIC.png?raw=true)
Utilizei o **Proteus Design Suite (Proteus)** para a criação do projeto eletrônico, composto por uma suíte de ferramentas, incluindo captura esquemática, simulação e módulos de projetos de placas de circuito impresso, usadas principalmente para o projeto de circuitos integrados. Utilizei O **MPLAB IDE** para gerenciamento do projeto e **Compilador C18**.\
Seguindo as orientações do datasheet do PIC supracitado, escreveremos o código/lógica em linguagem .c e compilamos com **C18** para arquivo **.cof** ou **.hex.**
___

#### Ferramentas:

* [PIC-18F4520](https://ww1.microchip.com/downloads/en/DeviceDoc/39631E.pdf)
* Proteus 7.8 Professional Portable
* [MPLAB IDE](https://www.microchip.com/en-us/tools-resources/archives/mplab-ecosystem)
* C18 Compiler
* **SO:** Windows 10/11 (64-bit Required)


