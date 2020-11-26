#include <contador_sete_segmentos.h>

void main()
{
    int8 incremento = 1;
    int8 contador = 0;
    while (true)
    {   
            int8 unidade = contador % 10;
            int8 dezena  = (contador - (contador % 10))/10;

            mostrarNoDisplay(dezena, unidade);

            // Inverte o estado da flag caso o botão esteja pressionado
            if (!input(PIN_A1))
                incremento = -incremento;
            // Executa a rotina de incremento/decremento de acordo com a flag
            if(contador >= 99)
                incremento = -1;
            if(contador <= 0)
                incremento = 1;
            
            contador += incremento;
    }
}

/**
 * Realiza o print no display dos valores das variáveis dezena e unidade
 * */
void mostrarNoDisplay(int8 dezena,int8 unidade)
{
    for (int8 timer = 0; timer < 10; ++timer)
    {
        // Ativa o display do lado direito
        output_high(PIN_B4);
        // Ativa os pinos de acordo com o número
        setPinos(unidade);
        delay_ms(18);
        // Ativa o display do lado esquerdo
        output_low(PIN_B4);
        // Ativa os pinos de acordo com o número
        setPinos(dezena);
        delay_ms(18);
    }
}

/**
 * Seta os pinos do display de acordo com o número passado no argumento
 * */
void setPinos(int8 numero)
{
    for (int8 pino = 0; pino < 7; ++pino)
    {
        output(portas_b[pino], numeros[numero] & (1 << pino));
    }
}
