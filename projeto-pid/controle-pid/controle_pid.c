#include <controle_pid.h>

#include "lcd_util.c"

signed int16 somatorioPID = 0.0, ultimaTemperatura = 0.0, temperaturaLM35 = 0.0, 
proporcional = 0.0, integrativo = 0.0, 
derivativo = 0.0, temperaturaReferencia = 0.0, erro = 0.0;

int16 contador = 0;

#INT_RTCC
void  RTCC_isr(void) 
{
   if(contador <= somatorioPID) {
      output_high(PIN_C5);
   }
   else {
      output_low(PIN_C5);
   }
  
   contador++;
   
   if(contador >= 19) {
      contador = 0;
   }
}

void main()
{  
   
   setup_adc_ports(AN0_AN1_AN2_AN3_AN4);
   
   lcd_ini();  
   delay_ms(10);
   
   setup_adc(ADC_CLOCK_DIV_16);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);      //51,2 us overflow
   setup_timer_2(T2_DIV_BY_16,255,1);      //819 us overflow, 819 us interrupt

   setup_ccp1(CCP_PWM);
   set_pwm1_duty((int16)510);

   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);


   while(TRUE)
   {
      set_adc_channel(0);
      delay_us(10);

      /**
       * temperatura:
       * 
       * 28 --- 76
       * 0  --- 1023
       * 
       * 76 - 28 = 48
       * 48 / 1023 = 0,0469208211143695
       */
      temperaturaReferencia = (read_adc() * 0.0469208211143695) + 28;
      
      set_adc_channel(2);
      delay_us(10);

      temperaturaLM35 = (read_adc()/2);
      
      set_adc_channel(1);
      delay_us(10);
      /**
       * Controle da velocidade do cooler via PWM
       */
      set_pwm1_duty(read_adc());

      erro = temperaturaReferencia - temperaturaLM35;
      proporcional = erro * 100;                                  // kp
      integrativo += erro * 0.01;                                 // ki
      derivativo = (ultimaTemperatura - temperaturaLM35) * 0.01;  // kd
      
      ultimaTemperatura = temperaturaLM35;

      somatorioPID = proporcional + integrativo + derivativo;


      printf(lcd_escreve, "\fRef=%Ld,Err=%Ld\n\rTemp=%Ld,pid=%Ld", temperaturaReferencia, erro, temperaturaLM35, somatorioPID);
      fprintf(SERIAL, "%ld,%ld,%ld\n", temperaturaReferencia, temperaturaLM35, erro);
      delay_ms(10);
   }
}
