#include <potenciometro.h>

void main()
{
    int16 potencia = 0;
    
    setup_adc(ADC_CLOCK_INTERNAL);
    setup_adc_ports(AN0);
    set_adc_channel(0);
    delay_us(10);

    while (true)
    {
        potencia = read_adc();
        int16 value0_99 = (99 * potencia) / 255;
        mostrarNoDisplay(value0_99);
    }
}

/**
 * Realiza o print no display dos valores das variáveis dezena e unidade
 * 0~9 | 0~9
 * 55 ~> 5 | 5
 * 
 * */
void mostrarNoDisplay(int16 numero)
{
    int8 unidade = numero % 10;
    int8 dezena = (numero - (numero % 10)) / 10;

    for (int8 timer = 0; timer < 10; ++timer)
    {
        // Ativa o display do lado direito
        output_high(displayUnidade);
        // Ativa os pinos de acordo com o número
        setPinos(unidade);
        delay_ms(25);
        output_low(displayUnidade);
        // Ativa o display do lado esquerdo
        output_high(displayDezena);
        // Ativa os pinos de acordo com o número
        setPinos(dezena);
        delay_ms(25);
        output_low(displayDezena);
    }
}

/**
 * Seta os pinos do display de acordo com o número passado no argumento
 * */
void setPinos(int8 numero)
{
    for (int8 pino = 0; pino < 7; ++pino)
    {
        if (numeros[numero][pino])
            output_high(portas_b[pino]);
        else
            output_low(portas_b[pino]);
    }
}
