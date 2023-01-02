// Inclusão de bibliotecas e componentes utilizados
#include "16F874.h" // Precisa ser essa a biblioteca do controlador usado!
#device adc=8
#use delay(clock=1000000)
#fuses XT,NOWDT,NOPUT

void main()
{
   float ek=0, ek_1=0, uk=0, uk_1=0; // Instanciando variaveis utiliadas

   int out = 0, ref=127; // Instanciando variaveis utiliadas
   
   //*********************//
   float yk = 0;      //**// <---------- O MAIS IMPORTANTE PARA ESTABILIZAR O SINAL NO PROTEUS FOI ISSO AQUI!
   //*********************//             (Colocar o 'yk' para tipo 'float' kkkkk sim isso msm! Cuidado com os tipos da variáveis isso
                                      // pode afetar o resultado do circuito !!!)

   // "Setando" configurações iniciais dos componentes usados no PIC
   setup_adc_ports(ALL_ANALOG);
   setup_adc(ADC_CLOCK_INTERNAL);
   set_adc_channel(0);
   setup_timer_2(T2_DIV_BY_4,65,1); // *Importante ser 65 um dos parâmetros!
   setup_ccp1(CCP_PWM);

   enable_interrupts(GLOBAL | INT_TIMER2);
   delay_us(100);

   // Iniciando o laço
   while(1)
   {
      yk = read_adc();
      // yk = yk*(5000/255);
      ek = ref - yk;

      // Estrutura direta não canônica
      uk = 0.09346 * ek_1 + uk_1; // Coloque aqui os valores obtidos nos cálculos das equações!
      out = (int)(uk);

      // Tratando o sinal para se estabilizar em 6V (Que é o pedido no trabalho!)
      if (yk > 255){
         yk = 255;
      }
      if (yk < 0){
         yk = 0;
      }

      // Config pwm signal (Pedido no trabalho)
      set_pwm1_duty(out);


      // Estrutura direta não canônica (Continuando o ciclo no laço 'while true')
      uk_1 = uk;
      ek_1 = ek;

   }
}

