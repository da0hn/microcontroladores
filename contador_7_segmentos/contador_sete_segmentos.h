#include <16F84A.h>

#FUSES NOWDT                     //No Watch Dog Timer

#use delay(crystal=4MHz)

/*
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
 *     E D C B A F G
 * 0 = 1 1 1 1 1 1 0
 * 1 = 0 0 1 1 0 0 0
 * 2 = 1 1 0 1 1 0 1
 * 3 = 0 1 1 1 1 0 1
 * 4 = 0 0 1 1 0 1 1
 * 5 = 0 1 1 0 1 1 1
 * 6 = 1 1 1 0 1 1 1
 * 7 = 0 0 1 1 1 0 0
 * 8 = 1 1 1 1 1 1 1
 * 9 = 0 1 1 1 1 1 1  
 */

#define ALTERNADOR_DISPLAY PIN_B4

#define A PIN_B2
#define B PIN_B3
#define C PIN_B5
#define D PIN_B6
#define E PIN_B7
#define F PIN_B1
#define G PIN_B0

void contador();
void setPinos(int8 pinos[7]);
void setDisplayUnidade(int8 pinos[7]);
void setDisplayDezena(int8 pinos[7]);
