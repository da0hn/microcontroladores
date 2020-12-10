#include <pwm_rgb.h>

/**
 * 
 * cor  <---> RGB
 * 1020 <---> 255
 * 
 * cor = RGB * 1020 / 255
 * cor = RGB * 4		-> (1020/255)
 * quando RGB = 0, cor = 0 (desligado)
 * quando RBG = 255, cor = 1020 (máximo)
 * */

int16 RED=0, GREEN=0;
unsigned contador = 0;

#INT_RTCC
void RTCC_isr(void)
{

	if(contador >= 19) contador = 0;

	set_adc_channel(0);
	delay_us(10);
	unsigned potenciometro_1 = read_adc();

	set_adc_channel(1);
	delay_us(10);
	unsigned potenciometro_2 = read_adc();

	set_adc_channel(3);
	delay_us(10);
	unsigned potenciometro_3 = read_adc();

	RED   		= potenciometro_1 * 4;
	GREEN 		= potenciometro_2 * 4;
	int16 pwm   = potenciometro_3 * 0.076593137;
	// 1000us /  51,2us = 19,53125
	if(pwm < contador)
		output_high(BLUE);
	else 
		output_low(BLUE);
	contador++;
}

void main()
{
	setup_adc_ports(AN0_AN1_AN3);
	setup_adc(ADC_CLOCK_DIV_2);
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit); //51,2 us overflow
	setup_timer_2(T2_DIV_BY_16, 255, 1);	  //819 us overflow, 819 us interrupt

	setup_ccp1(CCP_PWM);
	setup_ccp2(CCP_PWM);
	
	enable_interrupts(INT_RTCC);
	enable_interrupts(GLOBAL);

	while (TRUE)
	{
		set_pwm1_duty(RED);
		set_pwm2_duty(GREEN);
	}
}
