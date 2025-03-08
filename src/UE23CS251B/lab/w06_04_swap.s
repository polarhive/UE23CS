.TEXT
    LDR R0, =ORIGINAL
    SWI 0x02                
    LDR R0, =STRING
    SWI 0x02                
    LDR R0, =NEWLINE
    SWI 0x02                
    LDR R0, =STRING
    LDRB R1, [R0]           
    MOV R2, R0              

LAST_CHARACTER:
    LDRB R3, [R2], #1
    CMP R3, #0
    BNE LAST_CHARACTER
    SUB R2, R2, #2          
    LDRB R3, [R2]           
    STRB R3, [R0]           
    STRB R1, [R2]           
    LDR R0, =MODIFIED
    SWI 0x02                
    LDR R0, =STRING
    SWI 0x02                
    LDR R0, =NEWLINE
    SWI 0x02                
    SWI 0x11                

.DATA
STRING:    .ASCIZ "DOG"
ORIGINAL:  .ASCIZ "The original string is "
MODIFIED:  .ASCIZ "The modified string is "
NEWLINE:   .ASCIZ "\n"
