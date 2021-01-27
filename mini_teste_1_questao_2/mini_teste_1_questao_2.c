#include <mini_teste_1_questao_2.h>

#define BOTAO PIN_B4

#define LED_A PIN_B7
#define LED_B PIN_B6
#define LED_C PIN_B5

#define LED_BOTAO PIN_B3

unsigned int16 ledUm = 0;
unsigned int16 ledDois = 0;
unsigned int16 ledTres = 0;

#INT_RTCC
void  RTCC_isr(void) 
{
   ledUm++;
   ledDois++;
   ledTres++;
}

void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);      //51,2 us overflow


   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {  
      // 83.47ms / 51.2us = 1630
      if(ledUm >= 1630) {
         output_toggle(LED_A);
         ledUm = 0;
      }
      // 55.55ms / 51.2us = 1084
      if(ledDois >= 1084) {
         output_toggle(LED_B);      
         ledDois = 0;
      }
      // 31.74ms / 51.2us = 619
      if(ledTres >= 619) {
         output_toggle(LED_C);
         ledTres = 0;
      }

      if(input(BOTAO)) {
         output_high(LED_BOTAO);
      }
      else {
         output_low(LED_BOTAO);
      }
   }

}
