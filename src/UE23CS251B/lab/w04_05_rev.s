.TEXT
    LDR R0, =A       
    MOV R1, R0       
    ADD R1, R1, #36  

LOOP:
    LDR R2, [R0]     
    LDR R3, [R1]     
    STR R3, [R0]     
    STR R2, [R1]     
    ADD R0, R0, #4   
    SUB R1, R1, #4   
    CMP R0, R1       
    BLT LOOP         
    SWI 0x11

.DATA
A: .WORD 1,2,3,4,5,6,7,8,9,10