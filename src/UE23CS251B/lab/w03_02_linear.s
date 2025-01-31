.DATA
A: .HWORD 1, 2, 3, 4, 5, 6, 7, 8, 9

.TEXT
    LDR R0, =A
    MOV R1, #11
    MOV R2, #-1

loop:
    ADD R2, R2, #1
    LDRH R3, [R0]
    ADD R0, R0, #2; increment HWORD pointer
    CMP R1, R3
    BNE loop

    SWI 0x11

