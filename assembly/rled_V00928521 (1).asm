 
.cseg ;select current segment as code

.org 0 ;begin assembling at address 0 of the flash memory

 ; ------------------------ Xi+1 = (A*Xi + C) mod M ---------------------------
 .def ZERO = r20
 .def ONE = r21

.def Xseed = r16	; X_0 should also carry the result
.def A_val = r17	 
.def C_val = r25
.def M_val = r24
.def ANSL = R0       ;To hold low-byte of answer   ---- ---- xxxx xxxx ; holds 1st 2^0 -> 2^7
.def ANSH = R1       ;To hold high-byte of answer  xxxx xxxx ---- ---- ; holds 2nd 2^8 -> 2^15

	;---------------necessary initialization-----------------

	ldi Xseed,19	;load X (R16) to 19
	ldi A_val,13	;load A (R17) to 13
	ldi C_val,17	;load C (R18) to 17
	ldi M_val,63	;load M (R19) to 64


	; **************** Device (via DDR) accepts all signals ******************
	ldi r22, 0xFF ;11111111 = processor sends to ext device to accept signals (ddr), 00000.... is for recieving
	sts DDRL, r22	;port L has 8 pins, 1111 makes every bit accept signals
	out DDRB, r22

	;???
	ldi ZERO, 0
	ldi ONE, 1
	;-----------------done initialization-------------------

repeat:

	; generate a random number in range 0~63 and store it in R16

	mul A_val, Xseed ;Multiply contents of A and X (Result remains in ANSL and ANSH)
 	mov Xseed, R0 ;copying r0 to r16
	add Xseed, C_val  
	and Xseed, M_val


	; illuminate LEDs according to value in R16
		sbrc r16, 5
		sts PORTL, r16
		sbrc r16, 4
		sts PORTL, r16
		sbrc r16, 3
		sts PORTL, r16
		sbrc r16, 2
		sts PORTL, r16


		sbrc r16, 1
		out PORTB, r16
		sbrc r16, 0
		out PORTB, r16
	
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