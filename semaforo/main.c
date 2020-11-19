#include <main.h>

void ativaSinalDoSemaforo(int8 cor, int16 delay) {
        output_high(cor);
        delay_ms(delay);
        output_low(cor);
        delay_ms(DELAY_PARA_PROXIMO_LED); 
}

void main() {
    while(TRUE) {
        ativaSinalDoSemaforo(VERMELHO, 5000);
        ativaSinalDoSemaforo(VERDE, 4000);
        ativaSinalDoSemaforo(AMARELO, 2000);
    }
}
