/*
 * picknum.asm
 *
 *  Created: 
 *   Author: 
 */ 

.equ COUNT = 20

.cseg

.org 0

	rjmp start

	src: .db 33, 60, 24, 55, 20, 44, 38, 90, 40, 0, 22, 80, 57, 43, 31, 100, 33, 27, 24, 18

start:

	; your code goes here

done:
	rjmp done

.dseg

.org 0x200

	dest: .byte 20