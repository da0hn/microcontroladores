#include <comunicacao_serial.h>
#include <stdlib.h>



void main()
{  
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_DIV_2);
      
   while(true) {
      unsigned pot = read_adc();
      fprintf(PORT1, "%u\n\r", pot);
      delay_ms(3000);
   }
   
}
