MOV r2, #4
  MOV r6, #5
  MOV r7, #7
  B forward
  ADD r1, r2, #4
  ADD r0, r6, #2
  ADD r3, r7, #4
forward:
  SUB r1, r2, #4
  B backward
backward:
  ADD r1, r2, #4
  ADD r4, r6, r7
  B backward
SUB r1, r1, r2
ADD r1, r1, r2

; Consider the starting address as 0X0001000 for the program.
; Find the Hexadecimal format of instruction encoding for all Branch instructions.
