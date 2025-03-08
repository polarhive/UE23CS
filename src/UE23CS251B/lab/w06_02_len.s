.TEXT
    LDR R0, =A
    MOV R1, #0
LOOP:
    LDRB R2, [R0], #1
    CMP R2, #0
    BEQ END_PROGRAM
    ADD R1, R1, #1
    B LOOP
END_PROGRAM:
    SWI 0x11
.DATA
A:  .asciz "Nathan"

