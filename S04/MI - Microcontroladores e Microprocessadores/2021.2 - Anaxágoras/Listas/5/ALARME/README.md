# Alarme Residencial 4 zonas - _PIC 18F4520_

![DEMO](https://github.com/jbrun0r/Alarme-Residencial---PIC-18F4520/blob/main/ALARME.gif?raw=true)

**Alarme Residencial** de 4 zonas utilizando o **PIC-18F4520.**

## Resumo:
Usando um **PIC-18F4520** e as ferramentas **MPLAB** e **Proteus**, desenvolva
o seguinte _Sistema Embarcado_: Desenvolva um **Alarme Residencial** com _4 zonas de
monitoramento_. Os sensores de presença instalados em cada uma
das _zonas_, devem ser monitorados usando a interrupção ligada
à PORTA B. Quando ocorre uma invasão em uma das zonas, o
respectivo sensor vai para nível alto. A saída do alarme é um
alto-falante que funciona por frequência. A frequência do
alto falante deve ser gerada por **pwm**. O alarme deve gerar
ainda um _log_ de ocorrências enviado pela serial a um
computador remoto. Uma ocorrência no log deve conter o evento
acontecido e a hora do evento. _Ex: Zona 1 (03:21:13)_.

## Design:

![fundo](https://github.com/jbrun0r/Alarme-Residencial---PIC-18F4520/blob/main/ALARME.png?raw=true)\
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

___

#### Alarme em Funcionamento: [Link](https://drive.google.com/file/d/1lLIa-KZNK7gJDIKCiYbW4sJhqAsrm2u7/view?usp=sharing)
