.TEXT
    LDR R0, =STRING     
    LDR R1, =SUBSTRING  
    MOV R4, #0          

CHECK_NEXT:
    LDRB R2, [R0]
    CMP R2, #0
    BEQ NOT_FOUND       

    MOV R3, R0          

CHECK_SUBSTRING:
    LDRB R5, [R1], #1   
    CMP R5, #0
    BEQ FOUND           

    LDRB R6, [R3], #1   
    CMP R5, R6
    BNE RESET_SUBSTRING 
    B CHECK_SUBSTRING   

RESET_SUBSTRING:
    LDR R1, =SUBSTRING  
    ADD R0, R0, #1      
    B CHECK_NEXT        

FOUND:
    MOV R4, #1          
    LDR R0, =MSG_FOUND  
    SWI 0x02            
    B END_PROGRAM       

NOT_FOUND:
    MOV R4, #0          
    LDR R0, =MSG_NOT_FOUND  
    SWI 0x02            

END_PROGRAM:
    SWI 0x11            

.DATA
STRING:    .ASCIZ "Hello World"
SUBSTRING: .ASCIZ "No"
MSG_FOUND: .ASCIZ "Substring found\n"
MSG_NOT_FOUND: .ASCIZ "Substring not found\n"       

