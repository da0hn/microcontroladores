
unsigned char readKeyboard(unsigned int timeout)
{
  unsigned char k = 0;
  for(unsigned contador=0; ((contador<timeout)||(!timeout)) && (!k); contador+=5) {
    output_low(PIN_D0);output_high(PIN_D1);output_high(PIN_D2);output_high(PIN_D3);
    delay_ms(20);
    if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='1';};
    if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='4';};
    if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='7';};
    if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='*';};
    //habilita segunda coluna do teclado
    output_high(PIN_D0);output_low(PIN_D1);output_high(PIN_D2);output_high(PIN_D3);
    delay_ms(20);
    if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='2';};
    if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='5';};
    if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='8';};
    if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='0';};
    //habilita terceira coluna do teclado
    output_high(PIN_D0);output_high(PIN_D1);output_low(PIN_D2);output_high(PIN_D3);
    delay_ms(20);
    if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='3';};
    if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='6';};
    if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='9';};
    if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='#';};
      //habilita quarta coluna do teclado
    output_high(PIN_D0);output_high(PIN_D1);output_high(PIN_D2);output_low(PIN_D3);    
    delay_ms(20);
    if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='A';};
    if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='B';};
    if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='C';};
    if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='D';};
    delay_ms(5);
  }
  if(!k) { k=255; }
  return k;
}
