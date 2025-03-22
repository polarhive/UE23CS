.data  
str: .asciz "NATHAN MATTEHW PAUL PES2UG23CS368" 
num: .word 15000

.text
    MOV r0, #30  
    MOV r1, #7    
    MOV r7, #0
    LDR r8, =num
    LDR r8, [r8]
    LDR r2, =str

loop: 
    SWI 0x204  
    BL sum
    CMP r0, #0
    SUBNE r0, r0, #1
    SWIeq 0x11  
    B loop

sum:  
    CMP r7, r8
    ADDNE r7, r7, #1
    BNE sum
    SWI 0x206   
    MOV r7, #0
    MOV pc, lr

