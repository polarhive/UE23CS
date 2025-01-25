; week-02/4
; find greatest element in arr

.data
A: .WORD 10, 50, 41, 55, 30, 20, 11, 5, 100, 77

.text
    LDR r0, =A
    MOV r1, #10
    LDR r2, [r0], #4
loop:
    LDR r3, [r0], #4
    CMP r3, r2
    MOVGT r2, r3

    SUB r1, r1, #1
    CMP r1, #1
    BNE loop
