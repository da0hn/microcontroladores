#include <16F877A.h>
#device ADC = 10

#FUSES NOWDT      //No Watch Dog Timer
#FUSES NOBROWNOUT //No brownout reset
#FUSES NOLVP      //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal = 20MHz)

#define output(pin, bit) (bit) ? output_high(pin) : output_low(pin)
#define ALTERNADOR_DISPLAY PIN_B4

#define A PIN_B2
#define B PIN_B3
#define C PIN_B5
#define D PIN_B6
#define E PIN_B7
#define F PIN_B1
#define G PIN_B0

const int8 portas_b[] = {E, D, C, B, A, F, G};
const int8 numeros[] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};