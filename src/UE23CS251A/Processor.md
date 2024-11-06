# Instruction Cycle 

> It performs the same 3-step process over and over again 

- Fetch an instruction from memory 
- Decode the instruction: Is it an ADD, SUB, etc.? 
- Execute the instruction: Perform the specified operation

## Components inside a processor

- [[ALU]]
- [[register|Registers]]: Data (usually) must be moved into registers 
# Control Circuitry

> Control circuitry is used to decode the instruction and then generate the
> necessary signals to complete its execution 

- Controls the [[ALU]]
- Selects Registers to be used as source and destination locations 

![[Pasted image 20241029113257.png]]

---

Assume `0x0201` is machine code for an ADD instruction of `R2  = R0 + R1`

Control Logic will 
- select the registers (R0 and R1)
- tell the ALU to add
- select the destination register (R2) 

![[Pasted image 20241029113349.png]]

--- ref: https://ee.usc.edu/~redekopp/cs356/slides/CS356Unit4_x86_ISA.pdf


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

## Program Counter

Recall that the processor must fetch instructions from memory before decoding and executing them.

> The PC/IP register holds the address of the next instruction to fetch

Maintains the current execution location in the program 

## Instruction Pointers

- The PC/IP contains the address of the instruction.
- The value in the PC/IP is placed on the address bus and the memory is told to read.
- The PC/IP is incremented, and the process is repeated for the next instruction
