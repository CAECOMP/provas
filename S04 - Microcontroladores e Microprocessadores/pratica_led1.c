   // Pisca Leds ligados nos pinos B0 e B1
   #include <16F871.h>
   #use   delay(clock=20000000)// Ser� usado um cristal de 20MHz para clock externo.

   #define  led0      pin_b0
   #define  led1      pin_b1
   

/*********************************************************************
*     Configura modo de I/O, inicia portas                           *
*     ( inicializa��o r�pida)                                        *
*********************************************************************/
   
   #use  fast_io(b)
  
   #byte porta = 0x05
   #byte portb = 0x06
   #byte portc = 0x07
   

main()
{  int   tempo;
         tempo=250;
               
      
      set_tris_b(0b00000000);// RB0 e RB1 configurados como sa�da.
      
      
      portb = 0x00;
      

     
      


   while (true)
 {
      output_high(led0);
      output_low(led1);
      delay_ms (tempo);
      delay_ms (tempo);
      delay_ms (tempo);
      delay_ms (tempo);
         
   
      output_low(led0);
      output_high(led1);
      delay_ms (tempo);
      delay_ms (tempo);
      delay_ms (tempo);
      delay_ms (tempo);
      
   }  
}
