
   #include <16F871.h>
   #use  delay(clock=20000000)
   #fuses   HS,NOWDT,PUT,NOLVP
/*********************************************************************
*     Configura modo de I/O inicia portas                            *
*     ( inicialização rápida                                         *
*********************************************************************/
   #use  fast_io(a)
   #use  fast_io(b)
   

   #byte porta = 0x05
   #byte portb = 0x06
  
   #define chave input(pin_a0)  
  /*********************************************************************/

   testa_bot(int  cont)
   {
   int1 led;
   if(chave)return cont;
   delay_ms(5);
   if(chave) return cont;
   delay_ms(5);
   while(!chave);
   cont++ ;
   return cont;
    }




   void liga_led(int n)
   {
   switch(n)
      {
            case  0: portb=0b00000000;
            break;

            case  1: portb = 0b00000001;
            break;
            case  2: portb = 0b00000010;

            break;
           case  3:  portb = 0b00000100;
            break;
       default:
            portb=0x00;

      }

    }

   main()
   { int n;

    setup_adc_ports(no_analogs);
    
      set_tris_a(0b00000001);
      set_tris_b(0b00000000);
      
      portb=0;
      n = 0;

   
   While(true)
   {
   while(chave);
      delay_ms(5);
      n = testa_bot(n);
      liga_led(n);
      delay_ms(10);
      if(n==4)n=0;
   }
   }
   




