#include <display_sete_seg_potenciometro.h>

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
	int8 unidade = valorLido % 10;
	int8 dezena = (valorLido - (valorLido % 10)) / 10;
	int8 centena = (valorLido - (valorLido % 100)) / 100;
	int8 milhar = (valorLido - (valorLido % 1000)) / 1000;

	
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
