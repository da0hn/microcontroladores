#include <contador_sete_segmentos.h>

/*
 * a = rb2
 * b = rb3
 * c = rb5
 * d = rb6
 * e = rb7
 * f = rb1
 * g = rb0       
 *              B4
 *     E  D  C       B  A  F  G
 * 0 = 1  1  1   0   1  1  1  0
 * 1 = 0  0  1   0   1  0  0  0
 * 2 = 1  1  0   0   1  1  0  1
 * 3 = 0  1  1   0   1  1  0  1
 * 4 = 0  0  1   0   1  0  1  1
 * 5 = 0  1  1   0   0  1  1  1
 * 6 = 1  1  1   0   0  1  1  1
 * 7 = 0  0  1   0   1  1  0  0
 * 8 = 1  1  1   0   1  1  1  1
 * 9 = 0  1  1   0   1  1  1  1 
 */

void main() {
   while(TRUE) {
         output_b(0b11101110);
         delay_ms(1000);
         
         output_b(0b00101000);
         delay_ms(1000);
         
         output_b(0b11001101);
         delay_ms(1000);
         
         output_b(0b00101011);
         delay_ms(1000);
         
         output_b(0b11001101);
         delay_ms(1000);
         
         output_b(0b01101101);
         delay_ms(1000);
         
         output_b(0b01100111);
         delay_ms(1000);
         
         output_b(0b11100111);
         delay_ms(1000);
         
         output_b(0b00101100);
         delay_ms(1000);
         
         output_b(0b11101111);
         delay_ms(1000);
         
         output_b(0b01101111);
         delay_ms(1000);
         
   }
}

void output_all_low() {
    output_b(0b00010000);
}

void exibirNumero(Display& display) {
    
}

void separarNumero(int8& numero, int8& primeiroDigito, int8& segundoDigito) {
    
}
