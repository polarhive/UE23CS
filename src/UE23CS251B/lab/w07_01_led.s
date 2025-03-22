.text
    MOV r0, #1
    MOV r1, #64000

loop:
    SWI 0x201
    SUBS r1, r1, #1
    BNE loop
    BEQ inc

inc:
    MOV r1, #64000
    ADD r0, r0, #1
    CMP r0, #3
    BNE loop

    SWI 0x11

