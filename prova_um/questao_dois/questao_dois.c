#include <questao_dois.h>

unsigned int8 posicao[4] = {0b0011, 0b0110, 0b1100, 0b1001}; //3=0011 6=0110 12=1100 9=1001 // {1, 2, 4, 8};
int1 dar_passo = 0;
int8 sentido = -1, passo = 0;
unsigned int8 valorLidoPotenciometro, contador = 0;

int8 velocidadeDoMotor = 100;

#INT_RTCC
void RTCC_isr(void)
{
  contador++;
  if (contador > velocidadeDoMotor)
  {
    dar_passo = 1;
    contador = 0;
  }
  if (input_state(pin_b0) == 1)
    sentido *= (-1);

  if (dar_passo == 1)
  {
    passo = passo + sentido;
    if (passo > 3)
      passo = 0;
    if (passo < 0)
      passo = 3;
    output_d(posicao[passo]);
    dar_passo = 0;
  }
}

void main()
{
  setup_adc_ports(AN0);
  setup_adc(ADC_CLOCK_DIV_2);
  setup_timer_0(RTCC_INTERNAL | RTCC_DIV_1 | RTCC_8_bit); //51,2 us overflow
  setup_timer_2(T2_DIV_BY_16, 255, 1);                    //819 us overflow, 819 us interrupt

  setup_ccp1(CCP_PWM);
  set_pwm1_duty((int32)510);

  enable_interrupts(INT_RTCC);
  enable_interrupts(GLOBAL);

  delay_us(50);
  valorLidoPotenciometro = 1;

  WHILE(true)
  {
    set_adc_channel(0);
    delay_us(50);

    valorLidoPotenciometro = read_adc();
    set_pwm1_duty((int16)(valorLidoPotenciometro * 1021) / 255);
  }
}
