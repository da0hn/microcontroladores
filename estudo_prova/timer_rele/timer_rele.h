#include <16F877A.h>
#device ADC=8

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES NOLVP                 	//No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20MHz)

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
const int8 numeros[] = {0x3F, 0x0C, 0x5B, 0x5E, 0x6C, 0x76, 0x77, 0x1C, 0x7F, 0x7E};
