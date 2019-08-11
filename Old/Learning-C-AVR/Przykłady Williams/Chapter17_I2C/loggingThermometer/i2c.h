// Funkcje do komunikacji i2c
#include <avr/io.h>
#include "pinDefines.h"

void initI2C(void);
    /* Włącza oporniki podciągające i inicjuje magistralę na szybkość 100kHz (przy FCPU=8MHz) */

void i2cWaitForComplete(void);
                       /* Czeka aż sprzęt włączy znacznik TWINT */

void i2cStart(void);
                               /* wysyła sygnał startu (włącza TWSTA) */
void i2cStop(void);
                                /* wysyła sygnal stopu (włącza TWSTO) */

void i2cSend(uint8_t data);
                   /* ładuje dane, wysyła je i czeka na zakończenie transmisji */

uint8_t i2cReadAck(void);
              /* odczytuje dane z urządzenia podległego i wysyła sygnał ACK (włącza TWEA) */
uint8_t i2cReadNoAck(void);
              /* odczytuje dane z urządzenia podległego i wysyła sygnał NOACK (bez TWEA) */
