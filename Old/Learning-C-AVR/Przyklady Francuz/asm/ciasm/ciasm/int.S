
/*
 * int.S
 *
 * Created: 2013-01-20 15:55:03
 *  Author: tmf
 */ 

 #include <avr/io.h>
 #include <avr/interrupt.h>

 .extern x

 .global TIMER1_OVF_vect
 TIMER1_OVF_vect:
  push	r16
  in	r16, _SFR_IO_ADDR(SREG)	; 63
  push	r16
  lds	r16, x
  subi	r16, 0xFF	; 255
  sts	x, r16
  pop r16
  out _SFR_IO_ADDR(SREG), r16
  pop r16
  reti

  .global asm_inc
  asm_inc:
   inc r22
   adc r23, 0
   adc r24, 0
   adc r25, 0
   ret

  .extern asm_txt

  .global asm_read_byte
  asm_read_byte:
   ldi r30, lo8(asm_txt)
   ldi r31, hi8(asm_txt)
   ld r24, Z
   ret

.extern c_zero
.global asm_zero
asm_zero:
   ldi r30, pm_lo8(c_zero)
   ldi r31, pm_hi8(c_zero)
   icall
   ret