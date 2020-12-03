#include <pwm_potenciometro_com_timer.h>

int8 contadorOverflow = 0;


#INT_RTCC
void  RTCC_isr(void) 
{
    if(contadorOverflow >= 19) contadorOverflow = 0;

    // 1000 / 51.2 = 19.53125
    int16 potencia = read_adc();
    
    int8 tOn = (int8)potencia * 0.076593137;  // 19.53125/255 * potencia
   
    if(contadorOverflow < tOn) {
        output_high(PIN_B1);
    }
    else {
        output_low(PIN_B1);
    }
    contadorOverflow++;
}

void main()
{
    setup_adc_ports(AN0);
    setup_adc(ADC_CLOCK_INTERNAL);
    setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);        //51.2 us overflow


    enable_interrupts(INT_RTCC);
    enable_interrupts(GLOBAL);

    while(TRUE)
    {
        
    }

}
