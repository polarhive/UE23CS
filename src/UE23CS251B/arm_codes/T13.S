; Program to search an element in an array

	LDR R1,=A
	LDR R2,=KEY
	LDR R4,[R2]
	MOV R5,#10
	
LOOP: LDR R3,[R1],#4
      CMP R3, R4
	  BEQ L1
	  SUBS R5, R5, #1
	  BNE LOOP
	  MOV R0, #0
	  SWI 0X011
L1: MOV R0,#01
    SWI 0X011


.TEXT
A: .WORD 1,2,3,4,5,6,7,8,9,10
KEY: .WORD 5
