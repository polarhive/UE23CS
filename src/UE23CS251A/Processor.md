# Instruction Cycle 

> It performs the same 3-step process over and over again 

- Fetch an instruction from memory 
- Decode the instruction: Is it an ADD, SUB, etc.? 
- Execute the instruction: Perform the specified operation

## Components inside a processor

- [[ALU]]
- [[register|Registers]]: Data (usually) must be moved into registers 
- [[Control Circuitry]]

---
## What if we didn’t have registers? 

> [!F = (X+Y) – (X*Y)]
> Requires an `ADD`  instruction, `MUL`tiply instruction and `SUB`tract instruction.

> [!proce]
> ADD: Load X, Y from memory and store the result to memory.
> MUL: Load X, Y from memory and store the result to memory.
> SUB: Load results from ADD and MUL and store the result to memory.
> 

> [!WARNING] 
(9 memory access!!)

## What if we didn’t have registers? 

`F = (X+Y) – (X*Y)` 

Requires an `ADD`  instruction, `MUL`tiply instruction and `SUB`tract instruction.

> [!note]
> ADD: Load X, Y from memory and store the result to memory.
> MUL: Load X, Y from memory and store the result to memory.
> SUB: Load results from ADD and MUL and store the result to memory.
> 

> [!WARNING] 
(9 memory access!!)

---
## Example with Registers

- Load X and Y into registers 
- ADD: R0 + R1 and store result in R2
- MUL:  R0 * R1 and store result in R3
- SUB:  R2 – R3 and store result in R4 
- Store R4 back to memory 
- 3 total memory access 

## Other Registers

- [[Program counters]]
- [[Instruction Pointers]]