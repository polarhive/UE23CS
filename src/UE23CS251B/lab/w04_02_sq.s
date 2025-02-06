.TEXT
LDR R0, =SIZE
LDR R0, [R0]
LDR R1, =MATRIX
MOV R2, #0
OUTER_LOOP:
MOV R3, #0
INNER_LOOP:
        CMP R2, R3
        MOVEQ R4, #5
        MOVNE R4, #0
        STRB R4, [R1], #1
        ADD R3, R3, #1
        CMP R3, R0
        BLT INNER_LOOP
        ADD R2, R2, #1
        CMP R2, R0
        BLT OUTER_LOOP
MOV PC, LR

.DATA
SIZE:   .WORD 4
MATRIX: .BYTE 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16