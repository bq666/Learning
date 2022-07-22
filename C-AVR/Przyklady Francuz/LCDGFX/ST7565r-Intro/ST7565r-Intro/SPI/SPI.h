/*
 * SPI.h
 *
 * Created: 2013-04-25 20:26:18
 *  Author: tmf
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

//Inicjalizacja interfejsu SPI
void SPI_init();

//Odbiór/wys³anie jednego bajtu po SPI
void SPI_RW_Byte(uint8_t byte);


#endif /* SPI_H_ */