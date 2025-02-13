.data
array:      .word  14, 24, 5, 2, 252, 1
array_size: .word  6

.text
  ldr r0, =array
  ldr r1, =array_size
  ldr r1, [r1]
  bl  selection_sort
  swi 0x11

selection_sort:
  stmfd sp!, {r4-r8, lr}
  mov r4, r0
  mov r5, r1
  mov r6, #0

first_loop:
  cmp r6, r5
  bcs end
  
  mov r7, r6
  mov r8, r6
  add r8, r8, #1

second_loop:
  cmp r8, r5
  bcs check_swap

  ldr r2, [r4, r8, lsl #2]
  ldr r3, [r4, r7, lsl #2]
  
  cmp r2, r3
  bcs next_element
  mov r7, r8

next_element:
  add r8, r8, #1
  b second_loop

check_swap:
  cmp r7, r6
  beq no_change
  
  ldr r2, [r4, r6, lsl #2]
  ldr r3, [r4, r7, lsl #2]
  str r2, [r4, r7, lsl #2]
  str r3, [r4, r6, lsl #2]

no_change:
  add r6, r6, #1
  b first_loop

end:
  ldmfd sp!, {r4-r8, pc}
  .end

