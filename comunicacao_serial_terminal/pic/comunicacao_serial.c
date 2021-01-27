#include <comunicacao_serial.h>
#include <stdlib.h>

int32 serieDeNumeros[10] = {1, 3, 5, 6, 8, 10, 18, 23, 25, 39};


void main()
{  
   int8 contador = 0;
   char buffer[4];
   
   while(TRUE)
   {
      while(contador < 10) {
         int32 numero = serieDeNumeros[contador];
         itoa(numero, 10, buffer);
         puts(buffer);
         contador++;
         delay_ms(1000);
      }
      contador = 0;
      
      delay_ms(5000);
   }

}
