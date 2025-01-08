# Computer Architecture

> The specifications around which a computer's [[U3_Computer_Organization|organizational]] layout is defined.

- Microcontroller: Embedded all in one device. Specific tasks
- Microprocessor: Processor <-> memory / timer. More generic.

| RISC                                | CISC                     |
| ----------------------------------- | ------------------------ |
| simpler                             | complex                  |
| fixed len: '32' only                | variable len: 32, 64 bit |
| multiple reg set                    | single reg set           |
| single cycle                        | multi cycle              |
| hardware control                    | microprogram control     |
| highly [[U2_Pipelining\|pipelined]] | less pipelining          |
| only `LOAD` `STORE`                 | many memory instructions |

---

# ARM

Advanced RISC Machine. It's a family of instruction set architectures (ISAs) for computer processors. ARM processors are used in a variety of devices, including mobile phones, portable media players, and GPS navigation systems.

## Features of ARM

1. Conditional Instrutctions
2. Load / Save Architecture
3. 32 bit width
4. A general shift/ALU op in a single clock-cycle
5. 3 addr instruction format

%% - The register bank stores the processor state: 2 read; 1 write; port

- Barrel Shifter: `LSL`, `ROR`, `ROL`
- AR, Inc: Generate Sequential addresses
- Data Reg: Holds data going to memory
 %%

## Tradeoffs

1. Moving data from one place to another: A common misconception is most time goes in (ALU work)
2. Used to calc address/data of where the program is stored (1).
3. The RISC compiler bridges the gaps, We should also design a good ISA

| Data movement            | 43% |
| ------------------------ | --- |
| Control Flow (branching) | 23% |
| ALU                      | 15% |
| Comparison               | 13% |
| Logical                  | 5%  |

> Instead, we can start a new **fetch** phase after the first decode is in progress: 3-Stage Pipeline

| Fetch  | Decode | Execute |
| ------ | ------ | ------- |
| one -> | by->   | one->   |

1. Concurrency: via [[U2_Pipelining|Pipelining]]
2. Caching: To reduce average time for frequently used data
3. Super Scaling -> [[HPCA]]

---

## ARM Instructions

1. Shortform: `ADD`, `SUB`
	Condition (modifier): `EQ`, `EG`, `MI`, `GT`, `LE`
2. {S} optional suffix: Sets `N`, `O`, `C`, `V`, `Z`
3. {Rd}: Reg Destination
4. Operand 1 and 2
	1. Either register or immediate value
	2. Flexible: Can be immediate value or a register with optional shift

> They can be classified as:

1. Data Proc: `MOV, ADD, SUB`
2. Data Transfer: `LDR, STR`
3. Control Flow: `B, BL, BEQ, BGT`

## Program Structure

```c
Addr | Instr, Data
------------------
set	 | .text
by 	 | ADD <instr>
proc |
	 | .data
	 | var <x>
	 | .end
```

---

# 7 ARM modes

| code  | mode   |
| ----- | ------ |
| 10000 | user   |
| 10001 | FIQ    |
| 10010 | IRQ    |
| 10011 | SUPER  |
| 10111 | ABORT  |
| 11011 | Undef  |
| 11111 | System |

## Register Windows

- Large number of registers
- Processor entry / exit moved to visible windows to give each procedure access to new registers.
- Saves state on stack, and then branch
- This reduces traffic b/w processor <-> memory

## Delayed Branches

They use delayed branches so it doesn't interrupt the smooth flow as we know a branch can result in T/F. But it isn't great for super-scalar processors.

## Status Registers (SR)

> The state of CSPR -> SPSR on every transition

- N: prev was -ve
- Z: produces 0
- C: carry out
- V: prev was signed bit

> [!Tip] Flags
>
> >  I = 1, disables IRQ
> >  F = 1, disables FIQ
> >  T bit: (arch with thumb mode only)
> > 	 T= 0 (arm state)
> > 	 T = 1 (thumb state)

### Thumb Mode: 16 bit

- Only the reg: `r0-7` are used
- narrow data bus improves perf from memory
- subset of functionality of the ARM instruction set

### Memory System

1. [[U3_Computer_Organization#Endian-ess|Little Endian]]
2. [[U3_Computer_Organization#Endian-ess|Big Endian]]

- 8 bit signed/unsigned
- 16 bit signed/unsigned: aligned on 2 byte memory
- 1 word signed/unsigned. aligned on 4 byte memory
- A word in ARM is **32 bit**

> [!Important]
> - LOAD: memory value -> reg
> - STORE: reg -> memory

> [!warning]
>
> `STORE [R1][R2] This is not allowed`