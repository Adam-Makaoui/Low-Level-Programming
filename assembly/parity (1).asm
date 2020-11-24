.cseg
.org 0


;def regs
.def a = r17
.def b = r18
.def result = r16
.def temp = r19
.def P = r0 ; parity flag; P===1 is even ; P == 0 is odd
.def ONE = r20
.def ZERO = r21


;ini regs
ldi a, 0x56
ldi b, 0xAB
ldi ONE, 0x01
ldi ZERO, 0x00

add temp, a ; temp = temp + a
add temp, b ; temp = temp + b

mov result, temp; a = temp ; 0x101 or 0b100000001 (odd)

sbrs result, 0 ;if odd skip
mov p, ONE; set P to 0x01 ;setting to 1 (1 == even)
sbrc result, 0 ;if even skip
mov p, ZERO; set P to 0x00 ;setting to 0 (odd)

done: rjmp done


