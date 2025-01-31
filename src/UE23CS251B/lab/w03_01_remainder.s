.DATA
A: .WORD 10
B: .WORD 3

.TEXT
    LDR R0, =A
    LDR R1, =B
    LDR R2, [r0]
    LDR R3, [r1]
    MOV R4, #0
loop:
    ADD R4, R4, #1
    MUL R5, R3, R4
    CMP R2, R5; if the dividend is greater than the current multiple
    BGT loop;

    SUB R4, R4, #1
    MUL R5, R3, R4
    SUB R6, R2, R5; remainder

    SWI 0x11

