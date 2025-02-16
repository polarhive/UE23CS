;Program to find factorial of a number using functions
	MOV R1,#3
	BL FACT
	SWI 0X011

FACT:MOV  R3, #1
 L1: MUL  R3, R1, R3
     SUBS R1, R1, #1
     BNE L1	 
	 MOV PC, LR
	
	