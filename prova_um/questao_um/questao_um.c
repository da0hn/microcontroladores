#include <questao_um.h>

// 2017178440081
// 0 + 8 + 1 + 100 = 181

const int8 vezesPorSegundo = 109; // vezes por segundo
const int8 vezesPorMinuto = 109;  // vezes por minuto
const int8 vezesPorHora = 101;    // vezes por hora

// 1s para us -> 100000
// 1min para us -> 60000000
// 1h para us -> 3600000000
const int16 pressaoOverflow = (int16)(1000000 / 51.2) * vezesPorSegundo;
const int16 velocidadeOverflow  = (int16)(60000000 / 51.2) * vezesPorMinuto;
const int16 temperaturaOverflow = (int16)(3600000000 / 51.2) * vezesPorHora;

int16 contadorPressao = 0;
int16 contadorVelocidade = 0;
int16 contadorTemperatura = 0;


#INT_RTCC
void RTCC_isr(void)
{
  contadorPressao++;
  contadorVelocidade++;
  contadorTemperatura++;
}

void main()
{

  setup_adc_ports(AN0_AN1_AN3);
  setup_adc(ADC_CLOCK_DIV_2);
  setup_timer_0(RTCC_INTERNAL | RTCC_DIV_1 | RTCC_8_bit); //51,2 us overflow

  enable_interrupts(INT_RTCC);
  enable_interrupts(GLOBAL);

  while (TRUE)
  {
    if(contadorPressao >= pressaoOverflow) {
      set_adc_channel(0);
      int8 pressao = read_adc();
    }
    if(contadorVelocidade >= velocidadeOverflow) {
      set_adc_channel(1);
      int8 velocidade = read_adc();
    }
    if(contadorTemperatura >= temperaturaOverflow) {
      set_adc_channel(3);
      int8 temperatura = read_adc();
    }
  }
}
