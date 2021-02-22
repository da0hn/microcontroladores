#include <contador_lcd.h>

#ifndef lcd_enable
#define lcd_enable pin_e1 // pino enable do LCD
#define lcd_rs pin_e2			// pino rs do LCD
//#define lcd_rw		  pin_e2		// pino rw do LCD
#define lcd_d4 pin_d4 // pino de dados d4 do LCD
#define lcd_d5 pin_d5 // pino de dados d5 do LCD
#define lcd_d6 pin_d6 // pino de dados d6 do LCD
#define lcd_d7 pin_d7 // pino de dados d7 do LCD
#endif

#include "mod_lcd.c"

void main()
{

	setup_adc_ports(AN0);
	set_adc_channel(0);
	delay_ms(10);
	setup_adc(ADC_CLOCK_DIV_2);

	lcd_ini();
	delay_ms(100);

	int8 contador = 0;
	unsigned valorLido = 0;

	while (TRUE)
	{
		valorLido = read_adc();

		printf(lcd_escreve, "Valor Lido: %u", valorLido);

		delay_ms(1000);

		printf(lcd_escreve, "\f");
	}
}
