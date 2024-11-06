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