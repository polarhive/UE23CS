# Computer Organization

> [!Types of Computers]
> 
> 1. **Embedded computers**: integrated into a larger device or system in order to automatically monitor and control a physical process / environment. They are used for a **specific purpose** rather than for general processing tasks.
> 2. **PC**s: desktops, laptops, et-al
> 3. **Servers and Enterprise**: large computers that are meant to be shared by a large number of users who access them from some form of personal computer over a VPN.
> 4. **Supercomputers**: Grid computers with the highest performance computations needed in weather forecasting, engineering design and simulation, and scientific work. Grid computers provide a more cost-effective alternative. They combine a large number of personal computers and disk storage units in a physically distributed high-speed network, called a grid.
> 

---

# Funcitonal Units

A computer consists of **five** functionally independent main parts: input, memory, arithmetic and logic, output, and control units.

![[Pasted image 20241106084309.png]]

> [!NOTE]
> We refer to the arithmetic and logic circuits, with the main control circuits, as the **processor** and the input and output hardware as the **I/O** units.
> 

A program is a list of instructions which performs a task. Programs are stored in the memory. It is convenient to categorize this information as either instructions or data. Instructions, or machine instructions, are explicit commands that:

- Govern the **transfer of information** within a computer as well as **between** the computer and its **I/O** devices.
- Specify the **arithmetic and logic** operations to be performed.

> [!warning]
> 
> The computer is controlled by the stored program, except for possible external interruption by an operator or by I/O devices connected to it.
> 

## Input Unit

Whenever a key is pressed, the corresponding letter or digit is automatically translated into its corresponding binary code and transmitted to the processor. 

## Memory Unit

The function of the memory unit is to store programs and data. There are two classes of
storage, called primary and secondary.

## Primary Memory

Main memory, is a fast memory that operates at electronic speeds. Programs must be stored in this memory while they are being executed. 

The memory consists of a large number of semiconductor storage cells, each capable of storing **one bit** of information. These cells are rarely read or written individually. Instead, they are handled in groups of *fixed size called **words***. The memory is **organized** so that one word can be stored or retrieved in one basic operation. The number of bits in each word is referred to as the word length of the computer, typically 16, 32, or 64 bits.

To provide easy access to any word in the memory, a **distinct address** is associated with each word location. Addresses are **consecutive** numbers, starting from 0, that identify successive locations. A particular word is accessed by specifying its address and issuing a
**control command** to the memory that starts the storage or retrieval process. Instructions and data can be written into or read from the memory under the control of the processor. The time required to access one word is called the memory access time. 

**Cache** Memory: smaller, faster RAM unit, called a cache, is used to hold sections of a program that are **currently** being executed, along with any associated data. The cache is tightly coupled with the processor and is usually contained on the **same integrated-circuit** chip. The purpose of the cache is to facilitate high instruction execution rates.

At the start of program execution, the cache is empty. All program instructions and
any required data are stored in the main memory. As execution proceeds, instructions
are fetched into the processor chip, and a **copy** of each is placed in the cache. The data is fetched and copies are also placed in the cache.

If the same data locations are accessed repeatedly while copies of their contents are available in the cache, they can be fetched quickly.

### Secondary Storage

Additional, less expensive, permanent secondary storage is used when large amounts of data and many programs have to be stored, particularly for information that is accessed infrequently. Access times for secondary storage are longer than for primary memory. A wide selection of secondary storage devices is available,

## Arithmetic and Logic Unit

Math: `+-*/`, comparison of numbers is initiated by bringing the required operands into the
processor, where the operation is performed by the ALU. 

The sum may then be stored in the memory or retained in the processor for immediate use.
When operands are brought into the processor, they are stored in high-speed storage
elements called **registers**. Each register can store ***one word*** of data. Access times to registers are even shorter than access times to the cache unit on the processor chip.
## Output Unit

Touchscreens: the dual role of such units is the reason for using the single name input/output (I/O) unit in many cases.
## Control Unit

The memory, arithmetic and logic, and I/O units store and process information and perform
input and output operations. The operation of these units must be coordinated in some way.
This is the responsibility of the control unit. It sends control signals to other units and senses their states. 

I/O transfers, consisting of input and output operations, are controlled by program instructions that identify the devices involved and the information to be transferred. 

Control circuits are responsible for generating the **timing** signals that govern the transfers and determine when a given action is to take place. Data transfers between the processor and the memory are also managed by the control unit through timing signals. It is reasonable to think of a control unit as a well-defined, physically separate unit that interacts with other parts of the computer. 

---

# Basic Operational Concepts

> A typical instruction might be: `Load R2, LOC`

This instruction reads the contents of a memory location whose address is represented
symbolically by the label `LOC` and loads them into processor register `R2`. The original
contents of location LOC are preserved, whereas those of ***register R2 are overwritten***.

Execution of this instruction requires several steps. First, the instruction is fetched from
the memory into the processor. Next, the operation to be performed is determined by the
control unit. The operand at `LOC` is then fetched from the memory into the processor. Finally, the operand is stored in register `R2`. After operands have been loaded from memory into ***processor registers***, arithmetic or logic operations can be performed on them. 

> For example, the instruction. `Add R4, R2, R3`

After completing the desired operations, the results are in processor registers. They
can be transferred to the memory using instructions such as: `Store R4, LOC`

Notice how the notation is inverted: For Load and Store instructions, transfers between the memory and the processor are initiated by sending the address of the desired memory location to the memory unit and asserting the appropriate control signals.

> [!The processor contains a number of registers]
> 
> The ***instruction register*** (IR) holds the instruction that is currently being executed. Its output is available to the control circuits, which generate the timing signals that control the various processing elements involved in executing the instruction.
> 
> ***The program counter*** (PC) is another specialized register. It contains the memory address of the next instruction to be fetched and executed. During the execution of an instruction, the contents of the PC are updated to correspond to the address of the next instruction to be executed. PC points to the next instruction that is to be fetched from the memory.

Then, there are general-purpose registers R0 through Rn−1 , often called processor registers. They serve a variety of functions, including holding operands that have been loaded from the memory for processing.

![[Pasted image 20241106093039.png]]

If a word is to be read from the memory, the interface sends the address of that word to the memory along with a Read control signal. The interface waits for the word to be retrieved, then transfers it to the appropriate processor register. If a word is to be written into memory, the interface ***transfers both the address and the word*** to the memory along with a Write control signal.

## Program Flow

Execution of the program begins when the PC is set to point to the first instruction of the program. The contents of the PC are transferred to the memory along with a Read control signal. When the addressed word (in this case, the first instruction of the program) has been fetched from the memory it is loaded into register IR. At this point, the instruction is ready to be interpreted and executed.

Instructions such as Load, Store, and Add perform data transfer and arithmetic opera-
tions. If an operand that resides in the memory is required for an instruction, it is fetched
by **sending its address** to the memory and initiating a Read operation. When the operand has been fetched from the memory, it is transferred to a processor register. 

After operands have been fetched in this way, the ALU can perform a desired arithmetic operation, such as Add, on the values in processor registers. The result is sent to a processor register. If the result is to be written into the memory with a Store instruction, it is transferred from the processor register to the memory, along with the **address of the location** where the result is to be stored, then a Write operation is initiated.

The contents of the PC are incremented so that the PC points to the next instruction to be executed. Thus, as soon as the execution of the current instruction is completed, the processor is ready to fetch a new instruction.

## Interrupts

In order to respond immediately, execution of the current program must be suspended. To cause this, the device raises an interrupt signal, which is a request for service by the processor. The processor provides the requested service by executing a program called an ***interrupt-service*** routine.

Such diversions may alter the internal state of the processor, its state must be saved in the memory before servicing the interrupt request. Normally, the information that is saved includes the **contents** of the PC, the contents of the **general-purpose registers**, and some control information. When the interrupt-service routine is completed, the state of the processor is **restored from the memory** so that the interrupted program may continue.

---

# Number Representation

We need to represent both positive and negative numbers. Three systems are used for
representing such numbers:

- Sign-and-magnitude
- 1’s-complement
- 2’s-complement

> In all three systems, the leftmost bit is 0 for positive numbers and 1 for negative numbers. 

In the sign-and-magnitude system, negative values are represented by changing the most bit from 0->1.

In 1’s-complement representation, negative values are obtained by complementing each
bit of the corresponding positive number. Thus, the representation for -3 is obtained
by complementing each bit `0011` -> `1100`. Converting either way is referred to as forming the 1’s-complement of a given number.

In the 2’s-complement system, forming the 2’s-complement of an n-bit number is done by subtracting the number from 2n . Hence, the 2’s-complement of a number is obtained by adding 1 to the 1’s-complement of that number.

### Addition and subtraction of n-bit using the 2’s

- To add two numbers, add their n-bit representations, ignoring the carry-out bit from the (MSB). The sum will be the algebraically correct value in 2’s-complement representation if the actual result is in the range `−2n−1` through `+2n−1 − 1`.

- To subtract two numbers X and Y , that is, to perform `X − Y` , form the 2’s-complement of Y, then add it to X using the add rule. Again, the result will be the algebraically correct value in 2’s-complement representation if the actual result is in the range `−2n−1` through `+2n−1 − 1`.

## Sign Extension

We often need to represent a value given in a certain number of bits by using a larger
number of bits. For a positive number, this is achieved by adding 0s to the left. For a negative number in 2’s-complement representation, the leftmost bit, which indicates the
sign of the number, is a 1. A longer number with the same value is obtained by replicating
the sign bit to the left as many times as needed.

### Floating Point

- a sign for the number
- some significant bits
- a signed scale factor exponent for an implied base of 2

---
# Instruction Set Architecture

> The way programs are executed in a computer from the machine instruction set viewpoint. 

 A complete instruction set, including operand addressing methods, is often referred to as the instruction set architecture (ISA) of a processor.

## Memory Locations and Addresses

Because a single bit represents a very small amount of information, bits are never handled individually. The usual approach is to deal with them in groups of fixed size. The memory of a computer can be schematically represented as a collection of words.

![[Pasted image 20241106093855.png]]

If word length of a computer is 32 bits, a single word can store a 32-bit signed number or four ASCII-encoded characters, each occupying 8 bits. Machine instructions may require one or more words for their representation.

![[Pasted image 20241106093916.png]]

## Byte Addressability

 A byte is always 8 bits, but the word length typically ranges from 16 to 64 bits. It is impractical to assign distinct addresses to individual bit locations in the memory. 
## Big-Endian and Little-Endian

There are two ways that byte addresses can be assigned across words.

> [!Important]
> The name big-endian is used when lower byte addresses are used for the more significant bytes (the leftmost bytes) of the word.
> 
> The name little-endian is used for the opposite ordering, where the lower byte addresses are used for the less significant bytes (the rightmost
> bytes) of the word.

![[Pasted image 20241106094124.png]]

In addition to specifying the address ordering of bytes within a word, it is also necessary to specify the labeling of bits within a byte or a word. The most common convention, is the most natural ordering for the encoding of numerical data.

## Word Alignment

In the case of a 32-bit word length, natural word boundaries occur at addresses `0, 4, 8..` We say that the word locations have aligned addresses if they begin at a byte address that is a multiple of the number of bytes in a word. 

Hence, if the word length is 16 (2 bytes), aligned words begin at byte addresses
`0, 2, 4..` and for a word length of 64 (23 bytes), aligned words begin at byte addresses `0, 8, 16, ..`

There is no reason you can't have unaligned words, at an arbitrary word address.

---
# Memory Operations

Both program instructions and data operands are stored in the memory. To execute an instruction, the processor control circuits must cause the word (or words) containing the instruction to be **transferred** from the memory to the processor. 

Operands and results must also be moved between the memory and the processor. Thus, two basic operations involving the memory are needed, namely, Read and Write. 

> [!READ]
> The Read operation transfers a copy of the contents of a specific memory location to the processor. The memory contents remain unchanged. To start a Read operation, the processor sends the address of the desired location to the memory and requests that its contents be read. The memory reads the data stored at that address and sends them to the processor.

> [!WRITE]
> The Write operation transfers an item of information from the processor to a specific memory location, overwriting the former contents of that location. To initiate a Write operation, the processor sends the address of the desired location to the memory, together with the data to be written into that location. 

---

# Instructions and Instruction Sequencing

The tasks carried out by a computer program consist of a sequence of small steps, such as adding two numbers, testing for a particular condition, reading a character from the keyboard, or sending a character to be displayed on a display screen. A computer must have instructions capable of performing four types of operations:

- Data transfers between the memory and the processor registers
- Arithmetic and logic operations on data
- Program sequencing and control
- I/O transfers

To do this, we need a kind of notation!

## Register Transfer Notation

Possible locations that may be involved in such transfers are memory locations, processor registers, or registers in the I/O subsystem. Most of the time, we identify such locations symbolically with convenient names. For example, names that represent the addresses of memory locations may be `LOC`, `PLACE`, `A`, or `VAR2`. Predefined names for the processor registers may be `R0` or `R5`. 
 
Registers in the I/O subsystem may be identified by names such as `DATAIN` or `OUTSTATUS`. This `R2 ← [LOC]` means: the contents of memory location `LOC` are transferred into processor register `R2`.

> [!RTN Notation]
> This type of notation is known as ***Register Transfer Notation (RTN)***. Note that the right hand side of an RTN expression always denotes a value, and the left-hand side is the name of a location where the value is to be placed, overwriting the old contents of that location.

## Assembly-Language Notation

We need another type of notation to represent machine instructions and programs. For this, we use assembly language. For example, a generic instruction that causes the transfer described above, from memory location `LOC` to processor register `R2`, is specified by the statement `Load R2, LOC`

The contents of `LOC` are unchanged by the execution of this instruction, but the old contents of register `R2` are overwritten. 

> The name Load is appropriate for this instruction, because the contents read from a memory location are loaded into a processor register. 
> 
> The second example of adding two numbers contained in processor registers `R2` and `R3` and placing their sum in `R4` can be specified by the assembly-language statement `Add R4, R2, R3` In this case, registers `R2` and `R3` hold the source operands, while `R4` is the destination.

## RISC and CISC Instruction Sets

> [!Info]
> There are two fundamentally different approaches in the design of instruction sets for modern computers. One popular approach is based on the premise that higher performance can be achieved if each instruction occupies exactly **one word in memory**, and all operands needed to execute a given arithmetic or logic operation specified by an instruction **are already in processor registers**. 
> 
> This approach is conducive to an implementation of the processing unit in which the various operations needed to process a sequence of instructions are performed in “***pipelined***” fashion to overlap activity and reduce total execution time of a program. The restriction that each instruction must fit into a single word reduces the complexity and the number of different types of instructions that may be included in the instruction set of a computer.

An alternative to the RISC approach is to make use of more complex instructions
which may span more than one word of memory, and which may specify more complicated operations. This approach was prevalent prior to the introduction of the RISC approach.

> Two key characteristics of RISC instruction sets are:
- Each instruction fits in a single word.
- A load/store architecture is used, in which
	- Memory operands are accessed only using Load and Store instructions.
	- All operands involved in an arithmetic or logic operation must either be in processor registers, or one of the operands may be given explicitly within the instruction word.
	
At the start of execution of a program, all instructions and data used in the program are stored in the memory of a computer. Processor registers do not contain valid operands at that time. If operands are expected to be in processor registers before they can be used by an instruction, then it is necessary to first bring these operands into the registers. 

> This task is done by Load instructions which copy the contents of a memory location into a processor register. Load instructions are of the form `Load processor_register, memory_location`


To carry out this action, `C ← [A] + [B]` the contents of memory locations A
and B are fetched from the memory and transferred into the processor where their sum is computed. This result is then sent back to the memory and stored in location C.

The required action can be accomplished by a sequence of simple machine instructions. We choose to use registers R2, R3, and R4 to perform the task with four instructions:

```
Load R2, A
Load R3, B
Add R4, R2, R3
Store R4, C
```

> [!Important]
> 
> Observe that in the Store instruction the source and destination are specified in the reverse order from the Load instruction; this is a commonly used convention.

We can accomplish the desired addition by using only two registers, R2 and R3, if one of the source registers is also used as the destination for the result. In this case the addition would be performed as `Add R3, R2, R3` and `Store R3, C`

> Let us consider how this program is executed.

![[Pasted image 20241106100155.png]]

To begin executing a program, the address of its first instruction (i in our example) must be placed into the PC. Then, the processor control circuits use the information in the PC to fetch and execute instructions, one at a time, in the order of increasing addresses. 

This is called straight-line sequencing. During the execution of each instruction, the PC is incremented by 4 to point to the next instruction. Thus, after the Store instruction at location `i + 12` is executed, the PC contains the value `i + 16`, which is the address of the first instruction of the next program segment.

Executing a given instruction is a two-phase procedure. In the first phase, called
instruction fetch, the instruction is fetched from the memory location whose address is in the PC. This instruction is placed in the instruction register (IR) in the processor. At the start of the second phase, called instruction execute, the instruction in IR is examined to determine which operation is to be performed. 

The specified operation is then performed by the processor. This involves a small number of steps such as fetching operands from the memory or from processor registers, performing an arithmetic or logic operation, and
storing the result in the destination location. At some point during this two-phase procedure, the contents of the PC are advanced to point to the next instruction. 

> When the execute phase of an instruction is completed, the PC contains the address of the next instruction, and a new instruction fetch phase can begin.

## Branching

Consider the task of adding a list of n numbers. Separate Load and Add instructions are used to add each number to the contents of register R2. After all the numbers have been added, the result is placed in memory location SUM.
Instead of using a long list of Load and Add instructions, it is possible to implement a program loop in which the instructions read the next number in the list and add it to the current sum. To add all numbers, the loop has to be executed as many times as there are numbers in the list. 

![[Pasted image 20241106100511.png]]

The body of the loop is a straight-line sequence of instructions executed repeatedly. It starts at location LOOP and ends at the instruction Branch_if_`[R2]>0`. During each pass through this loop, the address of the next list entry is determined, and that entry is loaded into R5 and added to R3. The address of an operand can be specified in various ways,

Assume that the number of entries in the list, n, is stored in memory location N, as shown. Register R2 is used as a counter to determine the number of times the loop is executed. Hence, the contents of location N are loaded into register R2 at the beginning of the program. Then, within the body of the loop, the instruction
`Subtract R2, R2, #1` reduces the contents of R2 by 1 each time through the loop. Execution of the loop is repeated as long as the contents of R2 are greater than zero.

We now introduce ***branch instructions***. This type of instruction loads a new address into the program counter. As a result, the processor fetches and executes the instruction at this new address, called the branch target, instead of the instruction at the location that follows the branch instruction in sequential address order. 

> A conditional branch instruction causes a branch only if a specified condition is satisfied. If the condition is not satisfied, the PC is incremented in the normal way, and the next instruction in sequential address order is fetched and executed.

`Branch_if_[R2]>0 LOOP`

![[Pasted image 20241106100710.png]]

---
# Addressing Modes

The compiler generates appropriate sequences of low-level instructions that implement the desired operations. The different ways for specifying the locations of instruction operands are known as addressing modes.

![[Pasted image 20241106100821.png]]

We access an operand by specifying the name of the register or the address of the memory location where the operand is located. 

## The precise definitions of these two modes are: 

- Register mode—The operand is the contents of a processor register; the name of the register is given in the instruction.
- Absolute mode—The operand is in a memory location; the address of this location is given explicitly in the instruction.

> [!info]
> In a RISC-style processor an instruction must fit in a single word, the number of bits that can be used to give an absolute address is limited, typically to 16 bits if the word length is 32 bits. 
> 
> To generate a 32-bit address, the 16-bit value is usually extended to 32 bits by replicating bit `b15` into bit positions `b31−16` (as in sign extension).

`Add R4, R2, R3` uses the Register mode for all three operands. Registers R2 and R3 hold the two source operands, while R4 is the destination.

The Absolute mode can represent global variables in a program. A declaration such as `Integer NUM1, NUM2, SUM;` in a high-level language program will  cause the compiler to allocate a memory location to each of the variables `NUM1, NUM2, and SUM`. 

Whenever they are referenced later in the program, the compiler can generate assembly-language instructions that use the Absolute mode to access these variables. The Absolute mode is used in the instruction `Load R2, NUM1`

For example, the instruction `Add R4, R6, 200immediate` adds the value 200 to the contents of register R6, and places the result into register R4. 

> Using a subscript to denote the Immediate mode is not appropriate in assembly languages.

A common convention is to use the number sign (#) in front of the value to indicate that this value is to be used as an immediate operand. Hence, we write the instruction above in the form `Add R4, R6, #200`

In the addressing modes that follow, the instruction does not give the operand or its address explicitly. Instead, it provides information from which an effective address (EA) can be derived by the processor when the instruction is executed. The effective address is then used to access the operand.

---
