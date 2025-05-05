# Memory

## Main Memory

- Memory consists of a large array of bytes, each with its own address.
- Execution of an instruction:
	- Fetch an Instruction from memory
	- Decode the instruction, operands are fetched(from memory or registers)
	- After the instruction is executed, results are stored back.
- The memory unit(MU) sees the stream of addresses.
- Memory unit does not know how these [[addresses]] are generated.

### Basic Hardware

- Memory must be brought from hardware for it to be run, placed within a ready-queue.
- Main memory and registers are only storage, CPU can access directly.
- The data required for the CPU must be available in these registers.
- Can cause stalls
- [[Protection]] of memory must to ensure correct operation.

## Virtual Memory