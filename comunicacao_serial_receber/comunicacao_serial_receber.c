
/*****************************************************************************/
/* RS232 communication demo wiht CCS C compiler                              */
/*****************************************************************************/
#include <16F877A.h>
#device adc=8
#FUSES NOWDT                     //No Watch Dog Timer
#FUSES WDT128                    //Watch Dog Timer uses 1:128 Postscale
#FUSES H4                        //High speed osc with HW enabled 4X PLL
#FUSES NOBROWNOUT                //No brownout reset
#FUSES LVP                       //Low voltage prgming
#FUSES NOXINST                   //Extended mode disabled (Legacy mode)
#use delay(clock=40000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

   VOID main()
   {
      INT value = 85;
   CHAR ch;
   CHAR string[64];
   puts("**********************************");
   puts("  RS232 demo with CCS C compiler  ");
   puts("**********************************");

   /* start a new line (CR + LF) */
   putc('\n');
   putc('\r');

   /* output variable in decimal format */
   printf("Decimal variable output: %d\n\r", value);

   /* output variable in hex format */
   printf("Hex variable output: %x\n\r", value);

   /* echo demo: PIC receives data and sends it back. */
   /*            IF ENTER key is received, this demo exits. */
   puts("Type on the keyboard, PIC will echo back the characters:");

   WHILE (1)
   {
      /* read a single character */
      ch = getc();

      /* echo back the received character */
      putc(ch);
   }
   }

