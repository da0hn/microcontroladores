#include <16F877A.h>
#device ADC = 10

#FUSES NOWDT      //No Watch Dog Timer
#FUSES NOBROWNOUT //No brownout reset
#FUSES NOLVP      //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal = 20MHz)

#define display_milhar PIN_A2
#define display_centena PIN_A3
#define display_dezena PIN_A4
#define display_unidade PIN_A5

const int8 numeros[] = {
    0b0111111,
    0b0000110,
    0b1011011,
    0b1001111,
    0b1100110,
    0b1101101,
    0b1111101,
    0b0000111,
    0b1111111,
    0b1101111,
};