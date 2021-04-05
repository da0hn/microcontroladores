#include <leitor_serial.h>

#include "lcd_util.c"
#include <2404.c>

static char buffer[10];
static unsigned contador = 0;
#INT_RDA
void  RDA_isr(void) 
{      
   output_toggle(PIN_D0); 
   int ch = getc();
   
   if(contador > 30) contador = 0;
   
   printf(lcd_escreve, "\f%d", ch);
   write_ext_eeprom(contador++, ch);
}

void main()
{
   
   init_ext_eeprom();
   lcd_ini();
   delay_ms(10);
   
   
   printf(lcd_escreve, "\f   Iniciando");
   delay_ms(1000);
   
   enable_interrupts(GLOBAL); 
   enable_interrupts(INT_RDA);
   
   
   while(TRUE)
   {
      printf(lcd_escreve, "\f%s", buffer);
      delay_ms(1000);
   }

}
