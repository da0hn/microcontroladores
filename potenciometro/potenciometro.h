#include <16F877A.h>
#device ADC=8

#FUSES NOWDT                     //No Watch Dog Timer
#FUSES NOBROWNOUT                //No brownout reset
#FUSES NOLVP                     //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#use delay(crystal=4MHz)

#define A PIN_D0
#define B PIN_D1
#define C PIN_D2
#define D PIN_D3
#define E PIN_D4
#define F PIN_D5
#define G PIN_D6

#define displayUnidade PIN_A5
#define displayDezena  PIN_A4

#define output(pin, bit) (bit) ? output_high(pin) : output_low(pin)

const int8 portas_b[] = {E, D, C, B, A, F, G};
const int8 numeros[][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // zero
    {0, 0, 1, 1, 0, 0, 0}, // um
    {1, 1, 0, 1, 1, 0, 1}, // dois
    {0, 1, 1, 1, 1, 0, 1}, // três
    {0, 0, 1, 1, 0, 1, 1}, // quatro
    {0, 1, 1, 0, 1, 1, 1}, // cinco
    {1, 1, 1, 0, 1, 1, 1}, // seis
    {0, 0, 1, 1, 1, 0, 0}, // sete
    {1, 1, 1, 1, 1, 1, 1}, // oito
    {0, 1, 1, 1, 1, 1, 1}, // nove
};

void setPinos(int8);
void mostrarNoDisplay(int16);
