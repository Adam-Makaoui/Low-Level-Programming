.equ COUNT = 4

.cseg
.org 0

	rjmp start

	nums: .db 0x12, 0x45, 0x89, 0xCD

start:

	ldi ZL, low(nums<<1)
	ldi ZH, high(nums<<1)

	ldi r17, 0
loop:
	lpm r16, Z+
	ldi XL, low(str)
	ldi XH, high(str)
	rcall itoa

	inc r17
	cpi r17, COUNT
	brlo loop

done:
	rjmp done


;description: convert a signed magnitude value into 0-endign string
;input: R16 - the value
;       X   - starting address of the string
;output:none   
itoa:
	
	;-----------------------------------------------
	;             you code goes here
	;-----------------------------------------------

	ret



.dseg

.org 0x200

	str: .byte 100