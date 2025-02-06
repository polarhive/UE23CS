.DATA
A: .BYTE 10, 20, 30, 40, 50  
COUNT: .BYTE 5                   
BYTESUM: .WORD 0                   

.TEXT
LDR R0, =A      
LDR R1, =COUNT        
LDRB R2, [R1]         
MOV R3, #0
LOOP:   LDRB R4, [R0], #1     
        ADD R3, R3, R4        
        SUBS R2, R2, #1       
        BNE LOOP              
LDR R5, =BYTESUM          
STR R3, [R5]          
SWI 0x11              

