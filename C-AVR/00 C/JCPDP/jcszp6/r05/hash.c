/* hash.c -- definiuje funkcje z argumentem */
#include <stdio.h>
void hash(int n);      // prototyp ANSI                              

int main(void)
{
  int razy = 5;
  char ch = '!';       // kod ASCII wykrzyknika to 33                
  float f = 6.0;

  hash(razy);         // argument typu int                           
  hash(ch);           // char jest automatycznie przetwarzany na int 
  hash(f);      // rzutowanie wymusza konwersje f do int       
  return 0;
}

void hash(int n)      // naglowek funkcji w stylu ANSI informuje,    
{                     // ze funkcja pobiera jeden argument typu int  
  while (n-- > 0)
       printf("#");
  printf("\n");
}

