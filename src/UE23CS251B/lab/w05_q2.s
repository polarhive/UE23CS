.data
  str: .asciz "9+10"
  str_size: .word 3
  res:      .word

.text
  ldr r0, =str
  ldr r1, =str_size
  ldr r1, [r1]

  ldr r7, =res

  ldrb r2, [r0]
  add r0, r0, #1

  sub r3, r2, #48
  ldrb r4, [r0]
  add r0, r0, #1
  ldrb r2, [r0]
  add r0, r0, #1
  sub r5, r2, #48
  cmp r4, #43
  beq add
  cmp r4, #45
  beq sub

  b invalid_op

add:
  add r6, r3, r5
  str r6, [r7]
  b exit

sub:
  sub r6, r3, r5
  str r6, [r7]
  b exit

invalid_op:
  b exit

exit:
  swi 0x11

