#include <cooler_pwm.h>

unsigned potenciometro = 0;
int8 contador = 0;
int16 tempoOn = 0;

#INT_RTCC
void RTCC_isr(void)
{

	potenciometro = read_adc();
	/**
    * 
    * tempoOn           ---- 19.53125 
    * potenciometro ---- 255
    * Quero que o
		* 
    * 1000us / 51,2us = 19 ciclos
		* 
		* 19.53125 / 255 = 0.0766
    */
	tempoOn = potenciometro * 0.0766;

	if (contador >= 19)
		contador = 0;

	if (contador > tempoOn)
	{
		output_low(pin_c2);
	}
	else
	{
		output_high(pin_c2);
	}

	contador++;
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
		//TODO: User Code
	}
}
