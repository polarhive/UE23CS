.DATA
    SUM:    .WORD 0

.TEXT
    LDR R1, =0x00000788
    MOV R2, #0
    MOV R3, #8

loop:
    AND R4, R1, #0xF
    ADD R2, R2, R4
    MOV R1, R1, LSR #4
    SUBS R3, R3, #1
    BNE loop
    LDR R0, =SUM
    STR R2, [R0]

    SWI 0x11
