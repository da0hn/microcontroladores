#include <controle_pid.h>

#include "lcd_util.c"

unsigned int16 temperaturaReferencia = 0;
unsigned int16 temperaturaLM35 = 0;
unsigned int16 ultimaTemperatura = 0;

int16 proporcional = 0, integrativo = 0, derivativo = 0;

int16 somatorioPID = 0;

int16 contador = 0;

#INT_RTCC
void  RTCC_isr(void) 
{

   if(contador == 19) {
      contador = 0;
   }

   if(contador <= somatorioPID) {
      output_high(PIN_C5);
   }
   else {
      output_low(PIN_C5);
   }
   contador++;

}

void main()
{  
   
   setup_adc_ports(AN0_AN1_AN2_AN3_AN4);
   setup_adc(ADC_CLOCK_DIV_2);
   delay_ms(10);

   lcd_ini();
   delay_ms(10);

   setup_ccp1(CCP_PWM);
   set_pwm1_duty((int16)510);
   delay_ms(10);
   
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);      //51,2 us overflow
   setup_timer_2(T2_DIV_BY_16,255,1);      //819 us overflow, 819 us interrupt
   delay_ms(10);

   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);
   delay_ms(10);

   while(TRUE)
   {
      set_adc_channel(0);
      delay_ms(10);

      /**
       * temperatura:
       * 
       * 28 --- 76
       * 0  --- 1023
       * 
       * 76 - 28 = 48
       * 48 / 1023 = 0,0469208211143695
       */
      temperaturaReferencia = (read_adc() * 0.0469) + 28;
      
      set_adc_channel(1);
      delay_ms(10);

      /**
       * Controle da velocidade do cooler via PWM
       */
      //unsigned int16 velocidadeCooler = read_adc();
      set_pwm1_duty(read_adc());

      set_adc_channel(2);
      delay_ms(10);

      temperaturaLM35 = (read_adc()/2);

      int8 erro = temperaturaReferencia - temperaturaLM35;
      proporcional = erro * 100;                                  // kp
      integrativo += erro * 0.01;                                 // ki
      derivativo = (ultimaTemperatura - temperaturaLM35) * 0.01;  // kd
      
      ultimaTemperatura = temperaturaLM35;

      somatorioPID = proporcional + integrativo + derivativo;


      printf(lcd_escreve, "\fRef=%lu,Err=%d\n\rTemp=%lu", temperaturaReferencia, erro, temperaturaLM35);
      fprintf(SERIAL, "%lu,%lu,%d\n", temperaturaReferencia, temperaturaLM35, erro);
      delay_ms(10);
   }
}
