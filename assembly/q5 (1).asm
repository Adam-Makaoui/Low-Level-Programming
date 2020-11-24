/*
 * rled.asm
 *
 *  Created:
 *   Author:
 */ 

 .def ZERO = r20
 .def ONE = r21

 .cseg

.org 0

	ldi ZERO, 0
	ldi ONE, 1

	;necessary initialization

repeat:

	; generate a random number in range 0~63 and store it in R16

	; illuminate LEDs according to value in R16
	
	; delay 1s
	clr r19
	clr r18
loop1:
	ldi r20, 20
loop2:
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	dec r20
	cpi r20, 0
	brne loop2
	add r18, ONE
	adc r19, ZERO
	cpi r19, 250
	brne loop1

	;another round
	rjmp repeat
