#include <display_sete_seg_potenciometro.h>

unsigned int16 valorLido = 0;
int8 contador = 0;

#INT_RTCC
void RTCC_isr(void)
{
  // 1000us / 51.2us = 19,...

  if (contador > 19)
  {
    contador = 0;
  }

  contador++;
}

void mostraDisplay(unsigned int16 valorLido)
{
  // https://www.youtube.com/watch?v=CbJPSeapQ5U
  int16 milhar = (valorLido / 1000);       // extrai milhar
  int8 centena = (valorLido % 1000) / 100; // extrai centena
  int8 dezena = (valorLido % 100) / 10;    // extrai dezena
  int8 unidade = (valorLido % 100) % 10;   // extrai unidade

  output_high(display_milhar);
  output_d(numeros[milhar]);
  delay_ms(5);
  output_low(display_milhar);

  output_high(display_centena);
  output_d(numeros[centena]);
  delay_ms(5);
  output_low(display_centena);

  output_high(display_dezena);
  output_d(numeros[dezena]);
  delay_ms(5);
  output_low(display_dezena);

  output_high(display_unidade);
  output_d(numeros[unidade]);
  delay_ms(5);
  output_low(display_unidade);
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
    valorLido = read_adc();
    mostraDisplay(valorLido);
  }
}
