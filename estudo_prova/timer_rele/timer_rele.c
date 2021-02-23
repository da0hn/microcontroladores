#include <timer_rele.h>


int8 contador = 0;

#INT_RTCC
void RTCC_isr(void)
{
	if (!input(PIN_B3))
	{
		// ativa o rele 1
		output_high(PIN_C0);
	}
	else
	{
		output_low(PIN_C0);
	}
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
	}
}
