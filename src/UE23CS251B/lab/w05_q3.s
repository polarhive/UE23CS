; C -> ARM ASM
; i = 1;
; while (i <= 8) {
;     g = h + A[i];
;     i++;
; }
; g: Register R1,
; h: Register R2,
; Register R3: base address of A

.data
A:  .word 1, 2, 3, 4, 5, 6, 7, 8      ; arr A
g:  .word 10                          ; g
h:  .word 20                          ; h

.text
  ldr r1, =g           ; Load the address of g into R1
  ldr r2, =h           ; Load the address of h into R2
  ldr r3, =A           ; Load the base address of array A into R3

  ldr r6, [r2]         ; Load the value of h into R6 (h = *r2)

  mov r4, #8           ; R4 will hold the upper limit (8)
  mov r5, #1           ; R5 will hold the loop counter (i = 1)

loop: 
  cmp r5, r4           ; Compare i (R5) with 8
  bgt exit             ; Exit the loop if i > 8
  
  ldr r7, [r3], #4     ; Load A[i] into R7 and increment R3 to the next element
  add r6, r6, r7       ; g = g + A[i] (add the value of A[i] to g)
  add r5, r5, #1       ; i++

  b loop               ; Go back to the beginning of the loop

exit:
  str r6, [r1]        
  swi 0x11             
