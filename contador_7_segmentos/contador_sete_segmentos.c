#include <contador_sete_segmentos.h>

/*
 * a = rb2
 * b = rb3
 * c = rb5
 * d = rb6
 * e = rb7
 * f = rb1
 * g = rb0       
 *              B4
 *     E  D  C       B  A  F  G
 * 0 = 1  1  1   0   1  1  1  0
 * 1 = 0  0  1   0   1  0  0  0
 * 2 = 1  1  0   0   1  1  0  1
 * 3 = 0  1  1   0   1  1  0  1
 * 4 = 0  0  1   0   1  0  1  1
 * 5 = 0  1  1   0   0  1  1  1
 * 6 = 1  1  1   0   0  1  1  1
 * 7 = 0  0  1   0   1  1  0  0
 * 8 = 1  1  1   0   1  1  1  1
 * 9 = 0  1  1   0   1  1  1  1 
 */

void main()
{
    while (TRUE)
    {
        for (int8 dezena = 0; dezena < 10; dezena++)
        {
            for (int8 unidade = 0; unidade < 10; unidade++)
            {
                mostrarNoDisplay(dezena, unidade);
            }
        }
    }
}

void mostrarNoDisplay(int8& dezena, int8& unidade)
{
    for (int8 timer = 0; timer < 10; timer++)
    {
        output_toggle(PIN_B4);
        setPinos(unidade);
        delay_ms(50);

        output_toggle(PIN_B4);
        setPinos(dezena);
        delay_ms(50);
    }
}

void setPinos(int8& numero)
{
    for (int8 pino = 0; pino < 7; pino++)
    {
        if (numeros[numero][pino] == 1)
            output_high(portas_b[pino]);
        else
            output_low(portas_b[pino]);
    }
}
