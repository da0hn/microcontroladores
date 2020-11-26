#include <16F84A.h>

#FUSES NOWDT                     //No Watch Dog Timer

#use delay(crystal=4MHz)

#define output(pin, bit) (bit) ? output_high(pin) : output_low(pin)
#define ALTERNADOR_DISPLAY PIN_B4

#define A PIN_B2
#define B PIN_B3
#define C PIN_B5
#define D PIN_B6
#define E PIN_B7
#define F PIN_B1
#define G PIN_B0

/**
 * rb7 rb6 rb5 rb4 rb3 rb2 rb1 rb0 
 *  E   D   C  tgl  B   A   F   G    
 *
 * a = rb2
 * b = rb3
 * c = rb5
 * d = rb6
 * e = rb7
 * f = rb1
 * g = rb0
 * 
 *     E  D  C  B  A  F  G
 *    {1, 1, 1, 1, 1, 1, 0}, // zero      -> 3F
 *    {0, 0, 1, 1, 0, 0, 0}, // um        -> 0C
 *    {1, 1, 0, 1, 1, 0, 1}, // dois      -> 5B
 *    {0, 1, 1, 1, 1, 0, 1}, // três     -> 5E
 *    {0, 0, 1, 1, 0, 1, 1}, // quatro    -> 6C
 *    {0, 1, 1, 0, 1, 1, 1}, // cinco     -> 76
 *    {1, 1, 1, 0, 1, 1, 1}, // seis      -> 77
 *    {0, 0, 1, 1, 1, 0, 0}, // sete      -> 1C
 *    {1, 1, 1, 1, 1, 1, 1}, // oito      -> 7F
 *    {0, 1, 1, 1, 1, 1, 1}, // nove      -> 7E
 */
const int8 portas_b[] = {E, D, C, B, A, F, G};
const int8 numeros[] = {0x3F, 0x0C, 0x5B, 0x5E, 0x6C, 0x76, 0x77, 0x1C, 0x7F, 0x7E};

void setPinos(int8);
void mostrarNoDisplay(int8, int8);
