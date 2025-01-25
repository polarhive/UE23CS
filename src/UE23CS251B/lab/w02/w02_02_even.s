; week-02/2
; sum of even elements from the array

.data
    A: .WORD 15,10,12,13,9,45,16,8,25,33
    evensum: .WORD

.text
    LDR r0, =A
    LDR r1, =evensum
    MOV r3, #10; size of array
    MOV r4, #0;

loop:
    LDR r2, [r0], #4
    TST r2, #1;
    BEQ add

    SUBS r3, r3, #1
    BEQ end
    BNE loop

add:
    ADD r4, r4, r2
    SUBS r3, r3, #1
    BEQ end
    BNE loop

end:
    STR r4, [r1]
    SWI 0x11
