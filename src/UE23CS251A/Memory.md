# Memory

> Set of cells that each store a group of bits. Usually 1 byte, 8 bits per cell.

- Unique cell address assigned to each cell to reference the value at that location.
- Data and instructions are both stored in memory and are always represented as a string of 1's and 0's.

![[Pasted image 20241029114810.png]]

---
# Read / Writes

### Memories perform 2 operations 

- Read: retrieves data value in a  particular location (specified using  the address) 
- Write: changes data in a location to a new value 

 To perform these operations a  set of address, data, and control wires are used to talk to the  memory using a [[bus]].
  
We say that memories have  an address, data, and control bus. 

## Memory vs. I/O Access

Processor performs reads and writes to communicate with memory and I/O devices. I/O devices have memory locations that contain data that the processor can access.

![[Pasted image 20241029120435.png]]

All memory locations (be it RAM or I/O) have unique addresses which are used to identify them. The assignment of memory addresses is known as the physical [[memory map]]

## Address Space and View

> Most computers are byte-addressable. Each unique address corresponds to 1-byte of  memory (so we can access char variables).

Address width determines max amount of  memory. Every byte of data has a unique address 
- 32-bit addresses -> 4 GB address space 
- 36-bit address bus -> 64 GB address space 
## Data Bus & Data Sizes

> [[Moore's Law]] meant we could build systems with  more transistors. More transistors meant greater bit-widths.

Just like more physical space allows for wider roads/freeways, more transistors allowed us to move  to 16, 32, and 64-bit circuitry inside the processor. To support smaller variable sizes (char = 1 byte) we still need to access only 1-byte of memory per access, but to support `int` and `long` ints we  want to access 4 or 8-byte chunks of memory per access. 

## x86-64 Memory Organization 

Because each byte of memory has its own address we can picture memory as one column of bytes (Fig. 2). But, 64-bit logical data bus allows us to  access up to 8-bytes of data at a time. We will usually show memory arranged in rows of 4-bytes (Fig. 3) or 8-bytes, still with separate addresses for each byte.

![[Pasted image 20241029121132.png]]

![[Pasted image 20241029121148.png]]

![[Pasted image 20241029121205.png]]

## Word Sizes

To refer to a chunk of memory we must provide: 
- The starting address.
- The size:  `B, W, D, L`
- There are rules for valid starting  addresses
- A valid starting address must be a multiple of the data size
- Words (2-byte chunks) must start on an even (divisible by 2) address
- Double words (4-byte chunks) must start on an address that is a multiple of  (divisible by) 4 
- Quad words (8-byte chunks) must start on  an address that is a multiple of (divisible by) 8 

![[Pasted image 20241029121421.png]]

# [[Endianness]]

Endian-ness refers to the two alternate methods of ordering the bytes in a larger unit (word, DWORD,  etc.) 
