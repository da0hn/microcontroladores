
#include <16F877A.h>
#device ADC=16
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used FOR I/O
#use delay(crystal=20000000)

unsigned INT8 posicao[4]={0b0011, 0b0110, 0b1100, 0b1001};//3=0011 6=0110 12=1100 9=1001 // {1, 2, 4, 8};
signed INT8 passo=0;
int1 dar_passo=0;
signed INT8 sentido=-1;
unsigned INT8 ref,contador=0;

#INT_RTCC

void  RTCC_isr(VOID) 
{
   IF (++contador > ref)
   {
      dar_passo=1;
      contador =0;
   }
}

#INT_EXT

void EXT_isr(VOID)
{
   sentido *=(-1);
}

void main()
{
   setup_adc_ports(AN0_AN1_AN2_AN3_AN4);
   setup_adc(ADC_CLOCK_DIV_16);
   
   setup_timer_2 (T2_DIV_BY_16, 255, 1); //819 us overflow, 819 us interrupt
   setup_ccp1 (CCP_PWM) ;
   set_pwm1_duty ( (INT16) 510) ;
   
   enable_interrupts (INT_EXT) ;
   ext_INT_edge (L_TO_H) ;
   
   enable_interrupts (INT_RTCC) ;
   enable_interrupts (GLOBAL) ;
   
   set_adc_channel(0);
   delay_us(50);
   ref =1;

   WHILE (TRUE)
   {
      ref = read_adc ();
      IF (ref < 1) ref  = 1;
      IF (ref > 254) ref = 254;

      IF (dar_passo == 1)
      {
         passo = passo + sentido;
         IF (passo > 3) passo = 0;
         IF (passo < 0) passo = 3;
         OUTPUT_D (posicao[passo]) ;
         dar_passo = 0;
      }
   }
}

