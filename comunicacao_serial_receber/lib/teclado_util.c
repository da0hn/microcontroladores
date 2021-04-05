unsigned char tc_tecla(){
    unsigned char k = 0;

    output_low(PIN_B0);output_high(PIN_B1);output_high(PIN_B2);output_high(PIN_B3);
    delay_ms(30);
    if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='1';};
    if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='4';};
    if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='7';};
    if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='*';};

    output_high(PIN_B0);output_low(PIN_B1);output_high(PIN_B2);output_high(PIN_B3);
    delay_ms(30);
    if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='2';};
    if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='5';};
    if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='8';};
    if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='0';};
   
    output_high(PIN_B0);output_high(PIN_B1);output_low(PIN_B2);output_high(PIN_B3);
    delay_ms(30);
    if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='3';};
    if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='6';};
    if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='9';};
    if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='#';};
 
    output_high(PIN_B0);output_high(PIN_B1);output_high(PIN_B2);output_low(PIN_B3);
    delay_ms(30);
    if (input(PIN_B4) == 0){while(input(PIN_B4) == 0);k='A';};
    if (input(PIN_B5) == 0){while(input(PIN_B5) == 0);k='B';};
    if (input(PIN_B6) == 0){while(input(PIN_B6) == 0);k='C';};
    if (input(PIN_B7) == 0){while(input(PIN_B7) == 0);k='D';};
    
    if(!k)k=255;
    
    return k;
}
