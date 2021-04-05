#include <stdio.h>
#include <stdlib.h>

#define LINHA 16
#define COLUNA 6
unsigned char memoriaNull = 0xFF;

unsigned char dados[LINHA][COLUNA];

void salvaMemoria()
{ // salva todos os dados alterados na memoria
   int contador = 0;
   for (int i = 0; i < LINHA; i++)
   {
      for (int j = 0; j < COLUNA; j++)
      {
         write_ext_eeprom(contador, dados[i][j]);
         contador++;
      }
   }
}

int verificaSenha(unsigned char cadastro[4], int linhaDado)
{
   return (dados[linhaDado][2] == cadastro[0] && dados[linhaDado][3] == cadastro[1] && dados[linhaDado][4] == cadastro[2] && dados[linhaDado][5] == cadastro[3]);
}

int consultaId()
{
   int id = dados[0][0] - '0';
   dados[0][0] = (id + 1) + '0';
   return id;
}

void apagaColunaMemoria(int linhaDado)
{
   for (int j = 0; j < COLUNA; j++)
   {
      dados[linhaDado][j] = memoriaNull;
   }
}

void apagaMemoria()
{ //apaga todos os dados da memoria
   for (int i = 0; i < LINHA; i++)
   {
      apagaColunaMemoria(i);
   }
   salvaMemoria();
}

void carregaMemoria()
{ //carrega dados da memoria para a matriz "dados"
   int contador = 0;
   for (int i = 0; i < LINHA; i++)
   {
      for (int j = 0; j < COLUNA; j++)
      {
         dados[i][j] = read_ext_eeprom(contador);
         contador++;
      }
   }
}

int verificaPosicaoNula()
{ //verifica se existe posi��es nulas para cadastro
   for (int i = 1; i < LINHA; i++)
   {
      if (dados[i][0] == memoriaNull)
      {
         return i;
      }
   }
   return (-1);
}

void novoUsuario(unsigned char cadastro[4])
{ //cadastras um novo usuario na memoria
   int posicaoLinha = verificaPosicaoNula();
   dados[posicaoLinha][0] = consultaId() + '0'; //id do usuario
   dados[posicaoLinha][1] = '0';                //status

   if (posicaoLinha == (-1))
   {
      printf(lcd_escreve, "\fErro!\n\r");
      printf(lcd_escreve, "Memoria Cheia!!");
      delay_ms(2000);
      return;
   }

   for (int i = 2; i < COLUNA; i++)
   {
      dados[posicaoLinha][i] = cadastro[i - 2];
   }
   salvaMemoria();
}

void excluiUsuario(unsigned char cadastro[4])
{ //exclui um usuario da memoria
   for (int i = 1; i < LINHA; i++)
   {
      if (verificaSenha(cadastro, i))
      {
         apagaColunaMemoria(i);
      }
   }
   salvaMemoria();
}

int verificaUsuario(unsigned char cadastro[4])
{
   if (verificaSenha(cadastro, 0))
   {
      printf(lcd_escreve, "\fBem Vindo Admin!");
      delay_ms(2000);
      return 1;
   }
   for (int i = 1; i < LINHA; i++)
   {
      if (verificaSenha(cadastro, i))
      {
         return 0;
      }
   }
   return (-1);
}

void configuracaoMemoria()
{ // configura��es inicias da memoria
   if (dados[0][0] == memoriaNull)
   {
      //id inicial
      dados[0][0] = '1';
      //senha do admin
      dados[0][2] = '0';
      dados[0][3] = '0';
      dados[0][4] = '0';
      dados[0][5] = '0';
      salvaMemoria();
   }
}

void alteraStatus(unsigned char cadastro[4])
{
   for (int i = 1; i < LINHA; i++)
   {
      if (verificaSenha(cadastro, i))
      {
         if (dados[i][1] == '0')
         {
            dados[i][1] = 1 + '0';
         }
         else if (dados[i][1] == '1')
         {
            dados[i][1] = 0 + '0';
         }
         salvaMemoria();
         return;
      }
   }
}

int status(unsigned char cadastro[4])
{
   for (int i = 1; i < LINHA; i++)
   {
      if (verificaSenha(cadastro, i))
      {
         return dados[i][1] - '0';
      }
   }
   return -1;
}

void enviaDados(){
   for(int i = 0; i < LINHA; i++){
      for(int j = 0; j < COLUNA; j++){
         if(j == 5){
            fprintf(PORT1, "%d", dados[i][j] - '0');  
         }else{       
            fprintf(PORT1, "%d,", dados[i][j] - '0');             
         }
      }
      fprintf(PORT1, "\n\r"); 
    }
}

void recebeDados(){
   
  for (int i = 0; i < LINHA; i++)
    {
       for (int J = 0; J < COLUNA; J++)
       {
           gets(dados[i][j]);
       }
     }
     salvaMemoria();
}
