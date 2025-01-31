; week-02/5
; parity of given no
.text
    MOV r0, #2
    MOV r2, #1; even/odd

loop:
    EOR r2, r2, #1
    SUB r3, r0, #1
    ANDS r0, r0, r3
    BNE loop
    SWI 0x11
