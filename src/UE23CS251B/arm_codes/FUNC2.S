; Program to save the contents ( register contents)
    LDR R0, =A
	MOV R1, #5
	MOV R2, #6
	MOV R3, #7
	MOV R4, #8

	BL SAVE
	SWI 0X011
	
SAVE: STMIA R0!,{R1-R4}
      MOV PC, R14


.TEXT
A: .WORD 0,0,0,0