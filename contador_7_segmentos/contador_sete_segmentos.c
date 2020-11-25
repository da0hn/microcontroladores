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
    int8 dezena = 0, unidade = 0;
    int1 flag = 1;
    output_low(PIN_A1);

    while (TRUE)
    {
        while (dezena < 10)
        {
            while (unidade < 10)
            {
                mostrarNoDisplay(dezena, unidade);
                
                if(!input(PIN_A1)) flag = flag == 1 ? 0 : 1;
                
                if (flag) {
                    if(unidade+1 == 10 && dezena+1 == 10) {
                        flag = 0;
                    }
                    else if(unidade+1 == 10) {
                        unidade = 0;
                        dezena++;
                    }
                    else {
                        unidade++;
                    }

                } else {
                    if(unidade-1 == -1) {
                        unidade = 9;
                        if(dezena-1 == -1) {
                            dezena=0;
                            unidade=0;
                            flag = 1;
                        }
                        else {
                            dezena--;
                        }
                    }
                    else {
                        unidade--;
                    }
                }
            }
        }
    }
}

void mostrarNoDisplay(int8 &dezena, int8 &unidade)
{
    for (int8 timer = 0; timer < 10; timer++)
    {
        output_high(PIN_B4);
        setPinos(unidade);
        delay_ms(25);

        output_low(PIN_B4);
        setPinos(dezena);
        delay_ms(25);
    }
}

void setPinos(int8 &numero)
{
    for (int8 pino = 0; pino < 7; pino++)
    {
        if (numeros[numero][pino] == 1)
            output_high(portas_b[pino]);
        else
            output_low(portas_b[pino]);
    }
}
