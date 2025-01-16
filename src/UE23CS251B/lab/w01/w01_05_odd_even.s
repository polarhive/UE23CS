; week-01/5
; Write ALP to find odd/even
; at the end R2 contains 0 if even or else 1 if odd

; num in R1
; AND op bw the given number and constant 1, result of and is in R2
; (use ANDS for updation of flag)
; if LSB of R2 after AND is 0 it indicates even num, if true branch to L1 copy 00 into R0
; else if the LSB of R2 after and is 1 it indicates odd no if true branch to L2 and copy FF to R0

.text
    MOV R1, #0x10          ; even
    ANDS R2, R1, #0x01     ; AND of R1 and 1, store result in R2 and update flags
                           ; R2 = R1 & 0x01 

    BEQ L1                 ; AND operation is 0 (LSB is 0), branch to L1 (even number)

    MOV R0, #0xFF          ; If odd, move 0xFF into R0
    B L2                   ; Jump to the end

L1:
    MOV R0, #0x00          ; If even, move 0x00

L2:
    SWI 0x011
