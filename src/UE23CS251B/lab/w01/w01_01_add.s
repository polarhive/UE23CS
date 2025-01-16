; week-01/1
; Write ALP to perform adition of two numbers of size
; a) 64 bit.
; b) 128 bit.
;
; save the result in the reg (reuse reg to store the result)
; 1. save 8 32 bit numbers (r0-7)
; 2. add two reg at a time with their carry generated according to their bit position
; 3. final result in r3 and end execution

.TEXT
    // 8 nos
    MOV R0, #0xFFFFFFFF
    MOV R1, #0xFFFFFFFF
    MOV R2, #0xFFFFFFFF
    MOV R3, #0xFFFFFFFF
    MOV R4, #0xFFFFFFFF
    MOV R5, #0xFFFFFFFF
    MOV R6, #0xFFFFFFFF
    MOV R7, #0xFFFFFFFF

    // add 8 nos w carry forward
    ADDS R8, R0, R4
    ADCS R9, R1, R5
    ADCS R10, R2, R6
    ADCS R11, R3, R7

    // reuse locations
    MOV R0, R8
    MOV R1, R9
    MOV R2, R10
    MOV R3, R11
    SWI 0x011
