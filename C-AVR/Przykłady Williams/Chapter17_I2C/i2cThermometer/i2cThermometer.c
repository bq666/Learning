     /* Odczytuje temperaturę z układu LM75 i przesyła ją przez port szeregowy */

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>

#include "pinDefines.h"
#include "USART.h"
#include "i2c.h"

// -------- Definicje -------- //

#define LM75_ADDRESS_W               0b10010000
#define LM75_ADDRESS_R               0b10010001
#define LM75_TEMP_REGISTER           0b00000000
#define LM75_CONFIG_REGISTER         0b00000001
#define LM75_THYST_REGISTER          0b00000010
#define LM75_TOS_REGISTER            0b00000011
// -------- Funkcje --------- //

int main(void) {

  uint8_t tempHighByte, tempLowByte;

  // -------- Inicjalizacja --------- //
  clock_prescale_set(clock_div_1);                                     /* 8MHz */
  initUSART();
  printString("\r\n====  Termomert i2c ====\r\n");
  initI2C();

  // ------ Pętla zdarzeń ------ //
  while (1) {
                    /* Aby wybrać rejestr zaadresuj układ LM75 w trybie zapisu */
    i2cStart();
    i2cSend(LM75_ADDRESS_W);
    i2cSend(LM75_TEMP_REGISTER);
    i2cStart();      /* i od początku, wystarczy ponownie wysłać sygnał startu */
                                   /* przygotuj i wyślij adres z bitem odczytu */
    i2cSend(LM75_ADDRESS_R);
                            /* teraz odbierz dwa bajty z wartością temperatury */
    tempHighByte = i2cReadAck();
    tempLowByte = i2cReadNoAck();
    i2cStop();

    // Wypisz wartość temperatury przez port szeregowy...
    printByte(tempHighByte);
    if (tempLowByte & _BV(7)) {
      printString(",5\r\n");
    }
    else {
      printString(",0\r\n");
    }

                                                             /* raz na sekundę */
    _delay_ms(1000);

  }                                                    /* koniec pętli zdarzeń */
  return (0);                           /* ta instrukcja nie zostanie wykonana */
}
