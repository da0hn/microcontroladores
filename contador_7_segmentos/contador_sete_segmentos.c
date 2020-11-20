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

int8 ordemPinos[] = {E, D, C, B, A, F, G};

int1 numeros[][7] = {
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

void main() {
    while(TRUE) {
        for(int8 i=0; i<10; i++) {
            for(int8 j=0; j<7; j++) {
                numeros[i][j] == 1 ? output_high(ordemPinos[j]) : output_low(ordemPinos[j]);                
            }
            delay_ms(1000);
        }
    }
}

void setPinos(int8 pinos[7]) {
    (pinos[0] == 1 ? output_high(E) : output_low(E));
    (pinos[1] == 1 ? output_high(D) : output_low(D));
    (pinos[2] == 1 ? output_high(C) : output_low(C));
    (pinos[3] == 1 ? output_high(B) : output_low(B));
    (pinos[4] == 1 ? output_high(A) : output_low(A));
    (pinos[5] == 1 ? output_high(F) : output_low(F));
    (pinos[6] == 1 ? output_high(G) : output_low(G));
}

void setDisplayUnidade(int8 pinos[7]) {
    output_high(ALTERNADOR_DISPLAY);
    setPinos(pinos);
    delay_ms(500);
}

void setDisplayDezena(int8 pinos[7]) {
    output_low(ALTERNADOR_DISPLAY);
    setPinos(pinos);
    delay_ms(1500);
}

void contador() {
    for(int8 numero=0, unidade=0; numero<100; numero++, unidade++) {
        int8 dezena = numero % 10;
        
        int8 timer = 0;
        
        setDisplayUnidade(numeros[unidade]);
        
        while((++timer) < 10) {
            setDisplayDezena(numeros[dezena]);
            setDisplayUnidade(numeros[unidade]);
        }

        if(unidade+1 == 10) unidade=0;
    }
}

