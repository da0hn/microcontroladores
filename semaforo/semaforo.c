#include <semaforo.h>

void main()
{
    // Em funcionamento sem pedestre o sinal
    // e sempre verde para os carros e vermelho
    // para a passagem de pedestre
    sinalPedestre(vermelho);
    output_high(sinalVerde);

    while (true)
    {
        boolean pedestreQuerAtravessar = !(input(botaoDireito) && input(botaoEsquerdo));
        if (pedestreQuerAtravessar)
        {
            // Apos um pedestre pressionar o botao os
            // sistema espera 10 segundo mantendo o
            // verde para os carros e vermelho para o pedestre.
            delay_segundos(10);

            pedestreAtravessando();
        }
    }
}

void transicaoDoSinal(int8 de, int8 para)
{
    output_low(de);
    delay_ms(500);
    output_high(para);
}

void pedestreAtravessando()
{
    // Entao, sinal muda amarelo para os carros e
    // continua vermelho para os pedestre por 2 segundos.
    transicaoDoSinal(sinalVerde, sinalAmarelo);
    delay_segundos(2);

    // Após o tempo com amarelo ligado, o sinal dos
    // carros muda para vermelho, espera um
    // segundo e o sinal do pedestre vai para verde;
    transicaoDoSinal(sinalAmarelo, sinalVermelho);
    delay_segundos(2);
    sinalPedestre(verde);

    // Depois de 10 segundos dando passagem para
    // os pedestres, o sinal (do pedestre) começa a piscar e fica
    // assim por mais 5 segundos
    delay_segundos(10);
    piscaSinalDoPedestre();

    // Então o sinal do pedestres fica vermelho
    sinalPedestre(vermelho);
    // Após um segundo o sinal para os carros
    // muda para verde, mantendo assim até um
    // pedestre pressionar o botão novamente.
    transicaoDoSinal(sinalVermelho, sinalVerde);
}

void piscaSinalDoPedestre()
{
    // (500 + 500) * 5 = 5000ms
    for (int8 timer=0; timer < 5; ++timer)
    {
        sinalPedestre(vermelho);
        delay_ms(500);
        sinalPedestre(verde);
        delay_ms(500);
    }
}
