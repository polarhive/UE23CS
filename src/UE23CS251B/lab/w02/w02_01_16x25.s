; week-02/1
; perform mul of 16x25 without using MUL instruction (use barrel shifter)

.text
    MOV R1, #25
    MOV R2, R1, LSL#4
    SWI 0x11

