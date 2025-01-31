; week-01/1
; Write ALP to perform adition of two numbers of size
; a) 64 bit.
; b) 128 bit.
;
; save the result in the reg (reuse reg to store the result)
; 1. save 8 32 bit numbers (r0-7)
; 2. add two reg at a time with their carry generated according to their bit position
; 3. final result in r11, 10, 6, 7 and end execution

.text
; a) 64-bit addition
    MOV r0, #200
    MOV r2, #250
    MOV r1, #12
    MOV r3, #5
    ADDS r4, r0, r2
    ADC r5, r1, r3

    MOV r6, #255         
    MOV r8, #11
    MOV r7, #32         
    MOV r9, #9          
    ADDS r6, r6, r8      
    ADCS r7, r7, r9      

; b) 128-bit addition (r7r6 + r5r4)
    ADDS r10, r4, r6
    ADC r11, r5, r7

    ; The result of the 128-bit addition is now in r11 and r10
    SWI 0x11             
    