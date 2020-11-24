/*
 * picknum.asm
 *
 *  Created: 
 *   Author: 
 */ 

.equ COUNT = 20

.cseg

.org 0
	.def currentcount = r16 ; count to maintain how many times we should read prog mem based on num items in "scr:"
	.def oddeventest = r18 ; not used
	.def temp = r21 ; used to hold r17, read prog. mem. for performing AND

	

	rjmp start

	src: .db 33, 60, 24, 55, 20, 44, 38, 90, 40, 0, 22, 80, 57, 43, 31, 100, 33, 27, 24, 18

start:
	; your code goes here
	;initialize
	ldi ZL, low(src<<1) ;location to read data, prog. mem.
	ldi ZH, high(src<<1)	;location to read data, prog. mem.
	ldi YL, low(dest) ;location to store, data mem.
	ldi YH, high(dest)	;location to store, data mem.
	ldi currentcount, 0
	ldi oddeventest , 0x01


readMem:
	cpi currentcount, 20
	breq done
	lpm r17, Z+ ; read from prog. mem. to r17, r17<-Z, Z++
	inc currentcount

	cpi r17, 40 ; "40)" - less than 40 check
	brsh readMem ; loop again, read next prog. mem. item (r17 >= 40)

	cpi r17, 20 ; "[20" - greater or equal to 20 check
	brlo readMem ; loop again, read next prog. mem. item (r17 < 20)
	
	mov temp, r17
	and temp , oddeventest
	cpi temp, 0x0 ;if not = 000000, then its 000001, hence odd
	brne readMem

	st Y+,  r17 ; if in range >= 20 & < 40  "[20,40)" store that value into data mem. Y<-r17, Y++
	cpi currentcount, 20
	brlo readMem


	;my code ends here

done:
	rjmp done

.dseg

.org 0x200

	dest: .byte 20 ;last bits of the hundredth of seconds