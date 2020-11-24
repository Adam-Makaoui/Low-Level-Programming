#define LCD_LIBONLY
.include "lcd.asm"

.def ZERO = r20
.def ONE = r21

.equ A = 13
.equ C = 17
.equ SEED = 19

.cseg

    ldi ZERO, 0
    ldi ONE, 1

    ;initialization (comment this code because it conflicts with the driver of LCD,
	;turning off the background light of LCD)
    ;ldi r16, 0b00001010
    ;out DDRB, r16
	;ldi r16, 0b10101010
    ;sts DDRL, r16h

	call lcd_init

    ldi r16, SEED

repeat:

    rcall rand				;generate random value
	rcall led				;illuminate LEDs
	rcall itoa_binary		;show binary string
	rcall itoa_decimal		;show decimal string
	rcall show_binary_str	;show binary string
	rcall show_decimal_str	;show decimal string
    rcall delay				;delay 1 second
	
    rjmp repeat

;description: ; generate a random number in range 0~63
;input: R16 - seed or previous random number
;output:R16 - new random number 
rand:
    
	;-----------------------------------------------
	;             you code goes here
	;-----------------------------------------------

	ret

;description: ; illuminate LEDs
;input: R16 - controlling value
;output:none
led:
    
	;-----------------------------------------------
	;             you code goes here
	;-----------------------------------------------

	ret


;description: convert a value to binary string
;input: R16 - the value
;output: "bstr" in data memory
itoa_binary:

	;-----------------------------------------------
	;             you code goes here
	;-----------------------------------------------

	ret

;description: convert a value to decimal string
;input: R16 - the value
;output: "dstr" in data memory
itoa_decimal:

	;-----------------------------------------------
	;             you code goes here
	;-----------------------------------------------

	ret

;description: show binary on LCD at the 2st row (right aligned; 6 bits)
;input: string in data memory with label "bstr"
;output: none
show_binary_str:

	;-----------------------------------------------
	;             you code goes here
	;-----------------------------------------------


	ret

;description: show decimal on LCD at the 1st row (left aligned; two digits)
;input: string in data memory with label "dstr"
;output: none
show_decimal_str:

	;-----------------------------------------------
	;             you code goes here
	;-----------------------------------------------


	ret


;description: delay for some time
;input: none
;output: none
delay:
	push r16
	ldi r16, 0
loop_delay:
	call dly_ms
	inc r16
	cpi r16,250
	brlo loop_delay
	pop r16
	ret



.dseg

	bstr: .byte 100	;for temporarily storing string (for binary display)
	dsstr: .byte 100	;for temporarily storing string (for decimal display)