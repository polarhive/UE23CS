.TEXT
LDR R0, =MAT1       
LDR R1, =MAT2       
LDR R2, =RESULT     
MOV R3, #9          
LOOP:   LDRB R4, [R0], #1   
        LDRB R5, [R1], #1   
        ADD R6, R4, R5      
        STRB R6, [R2], #1   
        SUBS R3, R3, #1     
        BNE LOOP            
SWI 0x11            

.DATA
MAT1:   .BYTE 1, 2, 3, 4, 5, 6, 7, 8, 9  
MAT2:   .BYTE 9, 8, 7, 6, 5, 4, 3, 2, 1  
RESULT: .BYTE 0, 0, 0, 0, 0, 0, 0, 0, 0
