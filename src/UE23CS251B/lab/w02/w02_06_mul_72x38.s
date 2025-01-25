; week-02/6
; perform mul of 72x38 without using MUL instruction (use barrel shifter)

.text
    MOV r0, #72
    MOV r2, r0, LSL #5
    MOV r3, r0, LSL #2
    MOV r4, r0, LSL #1
    ADD r3, r3, r4
    ADD r3, r3, r2
    SWI 0x11
