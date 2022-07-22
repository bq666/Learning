/* mroz.c -- znajduje odsetek mroznych dni */
#include <stdio.h>

int main(void)
{

  const int MROZ = 0;
  float temperatura;
  int mrozne_dni = 0;
  int wszystkie_dni = 0;

  printf("Podaj liste najnizszych temperatur dnia.\n");
  printf("Uzyj skali Celsjusza. Aby zakonczyc, wpisz q.\n");
  while (scanf("%f", &temperatura) == 1)
  {
       wszystkie_dni++;
       if (temperatura < MROZ)
            mrozne_dni++;
  }
  if (wszystkie_dni != 0)
       printf("Calkowita liczba dni: %d, z czego %.1f%% bylo mrozne.\n",
              wszystkie_dni, 100.0 * (float) mrozne_dni / wszystkie_dni);
  if (wszystkie_dni == 0)
       printf("Nie wpisano danych!\n");
  return 0;
}

