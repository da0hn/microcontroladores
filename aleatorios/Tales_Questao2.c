
#include <16F877A.h>
#device ADC=8
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used FOR I/O
#use delay(crystal=20000000)

unsigned INT8 posicao[4]={0b0011, 0b0110, 0b1100, 0b1001};
signed INT8 passo=0;
int1 dar_passo=0;
signed INT8 sentido=-1;
unsigned INT8 ref,contador=0;

#INT_RTCC

void  RTCC_isr(VOID) 
{
   IF (++contador >= 50)
   {
      dar_passo=1;
      contador =0;
   }
   
   IF (input_state(pin_b0) == 1)
      sentido *= (-1);
   
   IF (dar_passo == 1)
   {
      passo = passo + sentido;
      IF (passo > 3) passo = 0;
      IF (passo < 0) passo = 3;
      OUTPUT_D (posicao[passo]);
      dar_passo = 0;
   }
}

void main()
{
   setup_adc_ports (AN0) ;
   setup_adc (ADC_CLOCK_DIV_2) ;
   setup_timer_0 (RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit); //51, 2 us overflow
   setup_timer_2 (T2_DIV_BY_16, 255, 1); //819 us overflow, 819 us interrupt
   setup_ccp1 (CCP_PWM) ;
   set_pwm1_duty ( (INT16) 510) ;
   enable_interrupts (INT_RTCC) ;
   enable_interrupts (GLOBAL) ;
   set_adc_channel (0) ;
   delay_us (50) ;
   ref = 1;

   WHILE (TRUE)
   {
      set_adc_channel (0) ;
      delay_us (50) ;
      
      ref = read_adc ();
      
      set_pwm1_duty ( (INT16) (ref * 1021 / 255));
         
   }
}

