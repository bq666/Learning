/* samoglos.c -- wykorzystuje etykiety wielokrotne */
#include <stdio.h>
int main(void)
{
  char ch;
  int a_licz, e_licz, i_licz, o_licz, u_licz, y_licz;
  a_licz = e_licz = i_licz = o_licz = u_licz = y_licz = 0;
  printf("Wpisz jakis tekst; # konczy program.\n");
  while ((ch = getchar()) != '#')
  {
      switch (ch)
      {
        case 'a' :
        case 'A' :  a_licz++;
                    break;
        case 'e' :
        case 'E' :  e_licz++;
                    break;
        case 'i' :
        case 'I' :  i_licz++;
                    break;
        case 'o' :
        case 'O' :  o_licz++;
                    break;
        case 'u' :
        case 'U' :  u_licz++;
                    break;
        case 'y' :
        case 'Y' :  y_licz++;
                    break;
        default :   break;
      }                                 // koniec switch
  }                                     // koniec petli while
  printf("liczba samoglosek:   A    E    I    O    U    Y\n");
  printf("                  %4d %4d %4d %4d %4d %4d\n",
        a_licz, e_licz, i_licz, o_licz, u_licz, y_licz);
  return 0;
}

