.DATA
A: .WORD 1, 2, 3, 4, 5, 6, 7, 8, 9

.TEXT
    LDR R0, =A
    MOV R1, #1; i
    MOV R2, #2; j

    MOV R6, #3
    MLA R3, R1, R6, R2; i = i*m + j
    MOV R4, R3

loop:
    MOV R5, R0
    ADD R0, R0, #4
    SUBS R4, R4, #1
    BNE loop

    SWI 0x11

