; Program to search an element in an array using functions
; let key element and the array start address be the parameters
; use register parameter assing technique
	LDR R1,=A
	LDR R2,=KEY
	BL SEARCH
	SWI 0X011
	
SEARCH: LDR R4,[R2]
		MOV R5,#10

  LOOP: LDR R3,[R1],#4
		CMP R3, R4
		BEQ L1
		SUBS R5, R5, #1
		BNE LOOP
	    MOV R0, #0
	    B L2
    L1: MOV R0,#01
    L2: MOV PC, R14

.TEXT
A: .WORD 1,2,3,4,5,6,7,8,9,10
KEY: .WORD 5
