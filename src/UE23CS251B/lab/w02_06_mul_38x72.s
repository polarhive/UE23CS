; week-02/6
; perform mul of 38x72 without using MUL instruction (use barrel shifter)

    MOV r0, #38
    MOV r1, r0, LSL #6
    MOV r2, r0, LSL #3
    ADD r3, r1, r2

    SWI 0x11

