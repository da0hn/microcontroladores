#include <16F84A.h>

#FUSES NOWDT                     //No Watch Dog Timer
                        
#use delay(crystal=4,000,000)

#define DELAY_PARA_PROXIMO_LED 1000

#define VERDE PIN_B0
#define AMARELO PIN_B1
#define VERMELHO PIN_B2

void ativaSinalDoSemaforo(int8 cor, int16 delay);
