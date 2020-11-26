#include <16F84A.h>

#FUSES NOWDT                     //No Watch Dog Timer
                        
#use delay(crystal=4Mhz)

#define delay_segundos(segundos) delay_ms((segundos)*1000)

#define sinalVerde     PIN_B7
#define sinalAmarelo   PIN_B6
#define sinalVermelho  PIN_B5
#define botaoEsquerdo  PIN_A1
#define botaoDireito   PIN_A2

#define vermelho high
#define verde    low 

#define sinalPedestre(SIGNAL) \ 
    output_##SIGNAL(PIN_B0);  \
    output_##SIGNAL(PIN_B1)


void transicaoDoSinal(int8, int8);
void piscaSinalDoPedestre();
void pedestreAtravessando();
