; week-01/6
; Write ALP to find factorial

; num in R0
; save values in R1 without using LDR and STR instr
; only use reg
; mult contents of R0 and R1 save in R1
; subtract contents of R0 by 1 and calc n-1
; check if R0 is 1
; repeat until R0 reaches 1
; end when it R0 is 1

.text
    MOV R0, #5             ; (input number)
    MOV R1, #1             ; Initialize R1 to 1 (factorial result accumulator)
    MOV R2, R0             ; Copy R0 (number) to R2 (used for decrementing)

factorial_loop:
    CMP R2, #1             ; Compare R2 (current number) with 1
    BEQ end_factorial      ; (factorial calculation done)

    MOV R3, R1             ; Copy R1 (result) to R3
    MUL R1, R3, R2         ; Multiply R1 by R2 (R1 = R3 * R2), store result in R1
    SUB R2, R2, #1         ; Decrement R2 by 1 (R2 = R2 - 1)

    B factorial_loop       ; Repeat the loop

end_factorial:
    MOV R0, R1             ;
    SWI 0x011              ;
