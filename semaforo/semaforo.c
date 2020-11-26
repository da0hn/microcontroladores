#include <semaforo.h>

void main()
{
    // Em funcionamento sem pedestre o sinal
    // é sempre verde para os carros e vermelho
    // para a passagem de pedestre
    sinalVermelhoPedestre();
    output_high(sinalVerde);

    while (true)
    {
        if (!input(botaoDireito) || !input(botaoEsquerdo))
        {
            pedestreQuerAtravessar();
        }
    }
}

void transicaoDoSinal(int8 de, int8 para)
{
    output_low(de);
    delay_ms(500);
    output_high(para);
}

void sinalVermelhoPedestre()
{
    output_high(sinalPareDireita);  // sinal vermelho
    output_high(sinalPareEsquerdo); // sinal vermelho
}
void sinalVerdePedestre()
{
    output_low(sinalPareDireita);  // sinal verde
    output_low(sinalPareEsquerdo); // sinal verde
}

void pedestreQuerAtravessar()
{
    // Após um pedestre pressionar o botão os
    // sistema espera 10 segundo mantendo o
    // verde para os carros e vermelho para o pedestre.
    sinalVermelhoPedestre();
    output_high(sinalVerde);
    delay_segundos(10);

    // Então, sinal muda amarelo para os carros e
    // continua vermelho para os pedestre por 2 segundos.
    transicaoDoSinal(sinalVerde, sinalAmarelo);
    delay_segundos(2);

    // Após o tempo com amarelo ligado, o sinal dos
    // carros muda para vermelho, espera um
    // segundo e o sinal do pedestre vai para verde;
    transicaoDoSinal(sinalAmarelo, sinalVermelho);
    delay_segundos(2);
    sinalVerdePedestre();

    // Depois de 10 segundos dando passagem para
    // os pedestres, o sinal (do pedestre) começa a piscar e fica
    // assim por mais 5 segundos
    delay_segundos(10);
    piscaSinalDoPedestre();

    // Então o sinal do pedestres fica vermelho
    sinalVermelhoPedestre();
    // Após um segundo o sinal para os carros
    // muda para verde, mantendo assim até um
    // pedestre pressionar o botão novamente.
    transicaoDoSinal(sinalVermelho, sinalVerde);
}

void piscaSinalDoPedestre()
{
    int8 timer = 0;
    // (500 + 500) * 5 = 5000ms
    while (timer++ < 5)
    {
        sinalVermelhoPedestre();
        delay_ms(500);
        sinalVerdePedestre();
        delay_ms(500);
    }
}
