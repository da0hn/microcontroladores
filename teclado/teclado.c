//#include "C:\Alberto\IFMT 2020 - II\Microcontroladores\Projetos CCS\Teclado\teclado.h"

#include <16F877A.h>
#device adc = 8

#FUSES HS         //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOPUT      //No Power Up Timer
#FUSES NOPROTECT  //Code not protected from reading
#FUSES NODEBUG    //No Debug mode for ICD
#FUSES NOBROWNOUT //No brownout reset
#FUSES NOLVP      //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD      //No EE protection
#FUSES NOWRT      //Program memory not write protected

#use delay(clock = 20Mhz)

#ifndef lcd_enable
#define lcd_enable pin_E1 // pino enable do LCD
#define lcd_rs pin_E2     // pino rs do LCD
//#define lcd_rw      pin_e2      // pino rw do LCD
#define lcd_d4 pin_d4 // pino de dados d4 do LCD
#define lcd_d5 pin_d5 // pino de dados d5 do LCD
#define lcd_d6 pin_d6 // pino de dados d6 do LCD
#define lcd_d7 pin_d7 // pino de dados d7 do LCD
#endif

#include "mod_lcd.c"
#include "teclado_interrupt.c"

int16 timeout = 1500;
unsigned char ch = 255;

#INT_RTCC
void RTCC_isr(void)
{

   ch = readKeyboard(timeout);

   if (ch != 255)
   {
      printf(lcd_escreve, "\fKey: %c", ch);
   }
   else
   {
      printf(lcd_escreve, "\fEsperando...");
   }
}

void main()
{
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_1 | RTCC_8_bit); // 51.2us

   lcd_ini(); // Inicializa LCD
   delay_ms(10);

   printf(lcd_escreve, "\f iniciando...");
   delay_ms(1000);

   printf(lcd_escreve, "\f   TECLADO  ");
   delay_ms(2000);

   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);
}
