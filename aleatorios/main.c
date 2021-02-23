#include <main.h>

#define disp_mil PIN_A2
#define disp_cen PIN_A3
#define disp_dez PIN_A4 
#define disp_uni PIN_A5

unsigned int16 valorLido = 0;
int8 contador = 0;

#INT_RTCC
void  RTCC_isr(void) 
{

}

void mostraDisplay(unsigned int16 valorLido)
{
   int8 num[] = {0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};
   
   int16 milhar = (valorLido / 1000); 
   int8 centena = (valorLido % 1000) / 100;
   int8 dezena = (valorLido % 100) / 10;
   int8 unidade = (valorLido % 100) % 10;
   
   /*
   int8 centena = (valorLido / 100);
   int8 dezena = (valorLido % 100) / 10;
   int8 unidade = (valorLido % 100) % 10;
   */
   
   output_high(disp_mil); 
   output_d(num[milhar]); 
   delay_ms(5);
   output_low(disp_mil);
   
   output_high(disp_cen); 
   output_d(num[centena]); 
   delay_ms(5);
   output_low(disp_cen);
   
   output_high(disp_dez); 
   output_d(num[dezena]); 
   delay_ms(5);
   output_low(disp_dez); 
         
   output_high(disp_uni); 
   output_d(num[unidade]); 
   delay_ms(5);
   output_low(disp_uni);
}


void main()
{
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);      //51,2 us overflow


   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {
   
      valorLido = read_adc();
      mostraDisplay(valorLido);
   }

}

/*
#define disp_mil PIN_A2
#define disp_cen PIN_A3
#define disp_dez PIN_A4 
#define disp_uni PIN_A5

unsigned int16 valorLido = 0;
int8 contador = 0;

#INT_RTCC
void RTCC_isr(void)
{
   valorLido = read_adc();

   // 1000us / 51.2us = 19,...

   if (contador > 19)
   {
      contador = 0;
   }

   contador++;
}

void mostraDisplay(unsigned int16 valorLido)
{
   int8 num[] = {0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};
   
   int8 unidade = valorLido % 10;
   int8 dezena = (valorLido - (valorLido % 10)) / 10;
   int8 centena = (valorLido - (valorLido % 100)) / 100;
   int8 milhar = (valorLido - (valorLido % 1000)) / 1000;
   
   output_high(disp_mil); 
   output_d(num[milhar]); 
   delay_ms(10);
   output_low(disp_mil);
   
   output_high(disp_cen); 
   output_d(num[centena]); 
   delay_ms(10);
   output_low(disp_cen);
   
   output_high(disp_dez); 
   output_d(num[dezena]); 
   delay_ms(10);
   output_low(disp_dez); 
         
   output_high(disp_uni); 
   output_d(num[unidade]); 
   delay_ms(10);
   output_low(disp_uni);
}

void main()
{
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_1 | RTCC_8_bit); //51,2 us overflow

   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

   while (TRUE)
   {
      mostraDisplay(valorLido);
   }
}
void main()
{

   while(TRUE)
   {
      //TODO: User Code
   }

}
*/
