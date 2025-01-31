; week-02/3
; Seperate the odd and even numbers into 2 arrays

.data
    ARRAY: .WORD 10,50,41,55,30,20,11,5,100,77
    LOCA: .WORD 0, 0, 0, 0, 0, 0
    LOCB: .WORD 0, 0, 0, 0, 0, 0

.text
    LDR r0, =ARRAY
    LDR r1, =LOCA
    LDR r2, =LOCB
    MOV r3, #10 ;

loop:
    LDR r4, [r0], #4
    TST r4, #1

    STREQ r4, [r1], #4
    STRNE r4, [r2], #4

    SUBS r3, r3, #1
    BNE loop
    SWI 0x11
