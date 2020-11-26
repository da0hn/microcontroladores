#include <contador_sete_segmentos.h>


void main()
{
    int8 dezena = 0, unidade = 0;
    int1 flag = 1;
    while (TRUE)
    {
        while (dezena < 10)
        {
            while (unidade < 10)
            {
                mostrarNoDisplay(dezena, unidade);

                // Inverte o estado da flag caso o botão esteja pressionado
                if (!input(PIN_A1))
                    flag = !flag;

                // Executa a rotina de incremento/decremento de acordo com a flag

                if (flag)
                {
                    modoCrescente(flag, dezena, unidade);
                }
                else
                {
                    modoDecrescente(flag, dezena, unidade);
                }
            }
        }
    }
}

/**
 * unidade = numero % 10
 * dezena  = (numero - (numero % 10)); 
 * */

/**
 * Executa o contador no modo crescente alterando as variáveis dezena e unidade
 * */
void modoCrescente(int1 &flag, int8 &dezena, int8 &unidade)
{
    // Se o valor das variaveis forem 99 ativa a flag para o modo decrescente
    if (unidade + 1 == 10 && dezena + 1 == 10)
    {
        flag = 0;
    }
    // Se houver overflow da unidade incrementa a dezena e reseta a unidade para 0
    else if (unidade + 1 == 10)
    {
        unidade = 0;
        dezena++;
    }
    else
    {
        unidade++;
    }
}

/**
 * Executa o contador no modo decrescente alterando as variáveis dezena e unidade
 * */
void modoDecrescente(int1 &flag, int8 &dezena, int8 &unidade)
{
    // Unidade=0, reseta para 9 caso a dezena > 0
    if (unidade - 1 == -1)
    {
        unidade = 9;
        // Caso a dezena < 0 reseta unidade e dezena para 0,
        // muda a flag para 1 (crescente)
        if (dezena - 1 == -1)
        {
            dezena = 0;
            unidade = 0;
            flag = 1;
        }
        // Caso contrário a dezena > 0 decrementa o contador
        else
        {
            dezena--;
        }
    }
    // Caso contrário apenas decrementa a unidade
    else
    {
        unidade--;
    }
}

/**
 * Realiza o print no display dos valores das variáveis dezena e unidade
 * */
void mostrarNoDisplay(int8 &dezena, int8 &unidade)
{
    for (int8 timer = 0; timer < 10; timer++)
    {
        // Ativa o display do lado direito
        output_high(PIN_B4);
        // Ativa os pinos de acordo com o número
        setPinos(unidade);
        delay_ms(25);
        // Ativa o display do lado esquerdo
        output_low(PIN_B4);
        // Ativa os pinos de acordo com o número
        setPinos(dezena);
        delay_ms(25);
    }
}

/**
 * Seta os pinos do display de acordo com o número passado no argumento
 * */
void setPinos(int8 &numero)
{
    // numeros[numero] & (1 << pino) ? output_high(portas_b[pino]) : output_low(portas_b[pino]);
    for(int8 pino=0; pino<7; pino++) {
        output(portas_b[pino], numeros[numero] & (1 << pino));
    }
}
