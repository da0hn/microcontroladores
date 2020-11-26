#include <16F84A.h>

#FUSES NOWDT                     //No Watch Dog Timer
                        
#use delay(crystal=4Mhz)

#define delay_segundos(segundos) delay_ms((segundos)*1000)  

const int8 sinalVerde        = PIN_B7;
const int8 sinalAmarelo      = PIN_B6;
const int8 sinalVermelho     = PIN_B5;

const int8 botaoEsquerdo     = PIN_A1;
const int8 botaoDireito      = PIN_A2;

const int8 sinalPareEsquerdo = PIN_B0;
const int8 sinalPareDireita  = PIN_B1;


void piscaSinalDoPedestre();
void pedestreQuerAtravessar();
void sinalVermelhoPedestre();
void sinalVerdePedestre();
void transicaoDoSinal(int8 de, int8 para);
