; week-02/1
; perform mul of 25x16 without using MUL instruction (use barrel shifter)

.text
    MOV R1, #16
    MOV R2, R1, LSL#4
    ADD R2, R2, R1, LSL#3
    ADD R2, R2, R1
    SWI 0x11
