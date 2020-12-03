#include <pwm_potenciometro_sem_timer.h>

void main()
{
    unsigned int8 potencia;
    setup_adc_ports(AN0);
    setup_adc(ADC_CLOCK_DIV_2);
    
    while(TRUE)
    {
        potencia = read_adc(); 
        
        int16 tOn=0, tOff=0;           
        
        // T = 1ms|1000us, F=1Khz        
        // (potencia*1000)/255 -> pot * 3.92...
        tOn = potencia*3.921568627; 
        tOff = (int16)(1000-tOn);
        
        output_high(PIN_B1);
        delay_us(tOn);
        output_low(PIN_B1);
        delay_us(tOff);
    }

}
