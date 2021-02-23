#include <questao_tres.h>

#ifndef lcd_enable
#define lcd_enable pin_e1 // pino enable do LCD
#define lcd_rs pin_e2     // pino rs do LCD
#define lcd_d4 pin_d4     // pino de dados d4 do LCD
#define lcd_d5 pin_d5     // pino de dados d5 do LCD
#define lcd_d6 pin_d6     // pino de dados d6 do LCD
#define lcd_d7 pin_d7     // pino de dados d7 do LCD
#endif

#include "mod_lcd.c"

void mostraFrequencia(int16 valor)
{

  int16 milhar = (valor / 1000);       // extrai milhar
  int8 centena = (valor % 1000) / 100; // extrai centena
  int8 dezena = (valor % 100) / 10;    // extrai dezena
  int8 unidade = (valor % 100) % 10;   // extrai unidade

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

void ativaBuzzer()
{
  // T = 1/2073 = 0.0004823 S4 RB2 482.3 us 241.15
  // T = 1/3951 = 0.0002531 S3 RB1 253.1 us 126.5
  // 2017178440081
  // S4 = 2073hz, Dó (C)
  // s3 = 3951hz, Si (B)
  output_low(PIN_A5);
  if (input_state(PIN_B1) == 1)
  {
    while (input_state(PIN_B1) == 1)
    {
      output_high(PIN_A5);
      delay_us(126);
      output_low(PIN_A5);
      delay_us(126);
    }
  }
  else
  {
    output_low(PIN_A5);
  }
  if (input_state(PIN_B2) == 1)
  {
    while (input_state(PIN_B2) == 1)
    {
      output_high(PIN_A5);
      delay_us(241);
      output_low(PIN_A5);
      delay_us(241);
    }
  }
  else
  {
    output_low(PIN_A5);
  }
}

void main()
{
  lcd_ini();

  while (TRUE)
  {
    printf(lcd_escreve, "Gabriel Honda\nSi e Do");
    mostraFrequencia(2073);
    // ativaBuzzer();
    printf(lcd_escreve, "\f");
  }
}
