# Control Circuitry

> Control circuitry is used to decode the instruction and then  generate the necessary signals to complete its execution 

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

--- 
ref: https://ee.usc.edu/~redekopp/cs356/slides/CS356Unit4_x86_ISA.pdf