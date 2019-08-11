#ifndef _ENCODER_H
#define _ENCODER_H

#include <stddef.h>
#include <stdbool.h>

void EncoderInit();
int8_t Read1StepEncoder();
int8_t Read2StepEncoder();
int8_t Read4StepEncoder();
void Timer0Init();
bool GetEncButton();

#endif
