# Architecture

Computer instructions indicate both the operation to perform and the operands to use. The operands may come from memory, registers, or from the instruction
itself.

The first part of the assembly instruction, `add`, is called the **mnemonic** and indicates what operation to perform. The operation is performed on b and c, the source operands, and the result is written to a, the destination operand.

Instead of having to memorise the `add` operation in terms of 1's and 0's we can alias this operation to `add` in MIPS assembly.

| `.py`     | `.s`        |
| --------- | ----------- |
| a = b +c  | add a, b, c |
| a = b - c | sub a, b, c |

---
### Design Principle 1: Simplicity favours regularity

Instructions with a consistent number of operands, in this case, two sources and one destination—are easier to encode and handle in hardware. More complex high-level code translates into multiple MIPS instructions

The assembly language program requires a temporary variable say `t` to store the intermediate result. Using multiple assembly language instructions.

| High-Level Code                        | MIPS Assembly Code                                    |
| -------------------------------------- | ----------------------------------------------------- |
| `a = b + c −d; // single-line comment` | `sub t, c, d # t = c −d`<br>`add a, b, t # a = b + t` |
### Design Principle 2: Make the common case fast.

The MIPS instruction set makes the common case fast by including only simple, commonly used instructions. The number of instructions is kept small so that the hardware required to decode the instruction and its operands can be simple, small, and fast.

A RISC architecture minimises the hardware complexity and the necessary instruction encoding by keeping the set of distinct instructions small. For example, an instruction set with 64 simple instructions would need log<sub>2</sub>64 = 6 bits to encode the operation. An instruction set with 256 complex instructions would need log<sub>2</sub>256 = 8 bits of encoding per instruction.

Instructions need to access operands quickly so that they can run fast. But operands stored in memory take a long time to retrieve. Therefore, most architectures specify a small number of registers that hold commonly used operands. The MIPS architecture uses `32` registers, called the register set or register file. The fewer the registers, the faster they can be accessed.

### Design Principle 3: Smaller is faster.

The SRAM array uses a small decoder and bitlines connected to relatively few memory cells, so it has a shorter critical path than a large memory does. MIPS register names are preceded by the `$` sign. 

The variables a, b, and c are arbitrarily placed in `$s0`, `$s1`, and `$s2`. The name `$s1` is pronounced "register s1" or "dollar s1". 

The instruction adds the 32-bit values contained in `$s1` (b) and `$s2` (c) and writes the 32-bit result to `$s0` (a). MIPS generally stores variables in 18 of the 32 registers: `$s0–$s7`, and `$t0–$t9`. Register names beginning with `$s` are called saved registers. Following MIPS convention, these registers store variables such as a, b, and c. 

Saved registers have special connotations when they are used with function calls. Register names beginning with `$t` are called temporary registers. They are used for storing temporary variables. Code Example 6.5 shows MIPS assembly code using a temporary register, `$t0`, to store the intermediate calculation of `c – d`

#### Register operands

| High-Level Code | MIPS Assembly Code                                               |
| --------------- | ---------------------------------------------------------------- |
| `a = b + c;`    | `# $s0 = a, $s1 = b, $s2 = c`<br>`add $s0, $s1, $s2 # a = b + c` |
#### Temporary registers

| High-Level Code | MIPS Assembly Code                                                                                              |
| --------------- | --------------------------------------------------------------------------------------------------------------- |
| a = b + c −d;`` | `# $s0 = a, $s1 = b, $s2 = c, $s3 = d`<br><br>`sub $t0, $s2, $s3 # t = c −d`<br>`add $s0, $s1, $t0 # a = b + t` |





