.DATA
    A: .WORD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
    B: .WORD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.TEXT
    LDR R0, =A
    LDR R1, =B
    MOV R6, #0

loop:
    LDMIA R0!, {R2 - R5}
    STMIA R1!, {R2 - R5}
    ADD R6, R6, #1
    CMP R6, #8
    BNE loop
    SWI 0x11
