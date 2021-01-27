#include <mini_teste.h>


void ativaLed(unsigned int8 seg_a, unsigned int8 seg_b, unsigned int8 seg_c) {
   if(seg_a == 1) {
      output_high(A);
   }
   else {
      output_low(A);
   }

   if(seg_b == 1) {
      output_high(B);
   }
   else {
      output_low(B);
   }
   
   if(seg_c == 1) {
      output_high(C);
   }
   else {
      output_low(C);
   }
}

void classificacaoDoAlerta(unsigned int8 nivel) {
   // 0=0,0,0 3=1,0,1
   // 4=0,1,0 5=1,1,0 
   // 6=0,1,1 1=1,0,0
   // 2=0,0,1 7=1,1,1
   // N1 = 0
   if(nivel < 143) {
      ativaLed(0, 0, 0);
   }
   // N2 = 3
   else if(nivel >= 143 && nivel < 159) {
      ativaLed(1, 0, 1);
   }
   // N3 = 4
   else if(nivel >= 159 && nivel < 175) {
      ativaLed(0, 1, 0);
   }
   // N4 = 5
   else if(nivel >= 175 && nivel < 191) {
      ativaLed(1, 1, 0);
   }
   // N5  6
   else if(nivel >= 191 && nivel <207) {
      ativaLed(0, 1, 1);
   }
   // N6  1
   else if(nivel >= 207 && nivel < 223) {
      ativaLed(1, 0, 0);
   }
   // N7  2
   else if(nivel >= 223 && nivel < 239) {
      ativaLed(0, 0, 1);
   }
   // N8  7
   else if(nivel >= 239 && nivel < 255) {
      ativaLed(1, 1, 1);
   }

}

void main()
{

   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_DIV_2);
   set_adc_channel(0);
   delay_us(10);
   
   while(TRUE)
   {
      unsigned nivel = read_adc();
      classificacaoDoAlerta(nivel);
      delay_ms(50);
   }

}


