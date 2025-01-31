; LOC A = [a1, a2, a3]
; LOC B = [b1, b2, b3]
; result = (a1 * b1) + (a2 * b2) + (a3 * b3)

.DATA
A: .WORD 1, 2, 3, 4, 5
B: .WORD 6, 7, 8, 9, 10

.TEXT
    LDR R0, =A
    LDR R1, =B
    MOV R4, #0 ;store final sum
    MOV R5, #5
loop:
    LDR R2, [r0], #4
    LDR R3, [r1], #4
    MLA R4, R2, R3, R4
    SUBS R5, R5, #1
    BNE loop

    SWI 0x11

