#include <blink_interrupcao.h>

long overflowInterno = 0;

#INT_RTCC
void RTCC_isr(void) 
{
    // 1000ms / 6.5ms
    boolean overflow = overflowInterno > 153;
    
    if(overflow) {
       output_toggle(PIN_B0);
       overflowInterno = 0;
    }
    
    overflowInterno++;
}

void main()
{
    setup_timer_0(RTCC_INTERNAL|RTCC_DIV_128|RTCC_8_bit);        //6,5 ms overflow
    
    output_low(PIN_B0);

    enable_interrupts(INT_RTCC);
    enable_interrupts(GLOBAL);

    while(TRUE)
    {
    }

}
