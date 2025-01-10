# What is an OS?

An Operating System is a program that acts as an **intermediary** between a user of a computer and the computer hardware. It provides a user-friendly environment in which a user may easily develop and execute programs. Otherwise, hardware knowledge would be mandatory for computer programming.

> *"The one program running at all times on the computer"* is the **kernel**

- The common functions of controlling and allocating resources are then brought together into one piece of software: **OS**.
- Everything else is either
	- a system program (ships with the operating system) , or
	- an application program.

## Operating System Goals

- Execute user programs and make solving user problems easier
- Make the computer system convenient to use
- Use the computer hardware in an efficient manner
- Manage resources such as
	-  Memory
	-  Processor(s)
	-  I/O Devices
- Depends on the point of view user and system
	-  Users want convenience, ease of use and good performance -> don’t care about resource utilization
- But shared computer such as mainframe or minicomputer must keep all users happy -> Maximize resource utilization.
- Available CPU time, memory, and I/O are used efficiently and that no individual user takes more than her fair share.

> Users of dedicated systems such as workstations have dedicated resources but frequently use shared resources from servers.

- Resources like file, compute, and print servers are shared.
- Operating system is designed to compromise between individual usability and resource utilization
- Handheld computers are resource poor, optimized for usability and battery life.
- Some computers have little or no user interface, such as embedded computers in devices and automobiles

### Four Components of a Computer System

![[Pasted image 20250109223433.png]]

1. Hardware: provides basic computing resources: CPU, memory, I/O devices
2. Operating system: Controls and coordinates use of hardware among various applications and users
3. Application programs: define the ways in which the system resources are used to solve the computing problems of users. Word processors, compilers, web browsers, database systems, video games
4. Users: People, machines, other computers

---

## System View

- OS is a resource allocator
	- Manages all resources
	- Decides between conflicting requests for efficient and fair resource use
- OS is a control program
	- Controls execution of programs to prevent errors and improper use of the computer

## Computer System Operation

- One or more CPUs, device controllers connect through common bus providing access to shared memory
- The CPU and the device controllers can execute oncurrently, competing for memory cycles.
- Memory controller is provided to synchronize access to the memory.
- I/O devices and the CPU can execute concurrently
	-  Each device controller is in charge of a particular device type
	-  Each device controller has a **local** buffer.
	-  Each device controller has registers for action (like "read character from keyboard") to take.
-  CPU moves data from / to main memory to / from local buffers.
-  I/O is from the device to local buffer of controller
-  Device controller informs CPU that it has finished its operation by causing an **interrupt**

### First Boot

> When the system is booted, the first program that starts running is a Bootstrap.

- It is stored in read-only memory (ROM) or electrically erasable programmable read-only memory (EEPROM).
- Bootstrap is known by the general term **firmware**, within the computer hardware.
- It initializes all aspects of the system, from CPU registers to device controllers to memory contents.
- The bootstrap program must know how to load the operating system and how to start executing that system.
- The **bootstrap program** must locate and load into memory the operating system kernel.
- The first program that is created is **init**, after the OS is booted. It waits for the occurrence of events.

---

## Trap, Exceptions, Interrupts

> Timeline for single running process

![[Pasted image 20250110093447.png]]

- The OS is interrupt driven.
- The interrupt architecture must save the address of the interrupted instruction
- The user can signal a software-generated interrupt, called a trap

| Polling                                                                                                 | Vectored                                                          |
| ------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------- |
| CPU constantly checks a set of devices, predefined locations to determine if an interrupt has occurred. | The interrupting device directly informs the CPU via an interrupt |
| CPU will execute an ISR                                                                                 | An ISR will execute                                               |
| Easy to implement but is less efficient                                                                 | Less memory checks, and allows interrupt passing                  |

| Volatile                                | Non Volatile                             |
| --------------------------------------- | ---------------------------------------- |
| Data is lost when power is switched off | Data persists when power is switched off |
| Cache Memory                            | HDD, Flash, SSD                          |
| Registers                               | ROM, Bootstrap EEPROM                    |

---

## Von neuman Architecture

**Fetch**: The CPU fetches or retrieves the next instruction from the memory. The address of the next instruction is stored in the PC.

**Decode**: Once the instruction is fetched, the CPU decodes it to understand what action is required, this interpretation is done by the [[U3_Computer_Organization#Control Unit|Control Unit]].

**Execute**: Based on the `opcode` and operand. ALU and other functional units are used in this step.

![[Pasted image 20250110093403.png]]

> [[U1_Architecture#Tradeoffs|Fetch, Decode, Execute]]

This cycle is repeated until the program terminates.

---

# Storage Device Hierarchy

> [!Tip]
> **Caching**: copying information into a faster storage system. In relative terms: main memory can be viewed as cache for secondary storage.

 Faster storage (cache) checked first to determine if information is there

- If yes? information is used from that cache
- If no? data is copied to cache and used there

Cache size determines how much size can be stored in the cache. Cache is also really expensive.

## Caching Strategies

- LRU: Least Recently used
- LFU: Least Frequently used
- FIFO: Evicts the oldest data
- Random: Evicts randomly chosen data
- Optimal: Evicts data that will be not be used in the future.

# I/O structure

- A large portion of the OS is dedicated to managing I/O as reliability is a major concern.
- The CPU <-> Device controllers are connected through a common bus.
- A **device-driver** is used for each device for managing I/O. It provides a uniform interface between kernel and the controller.

> **SCSI**: Small Computer-Systems Interface enables to connect more devices

## After I/O starts

Control returns to user program only after I/O completion.

- Wait instruction idles the CPU until the next interrupt
- Wait loop (contention for memory access)
- At most, one I/O request is outstanding at a time, no simultaneous I/O processing

A system call allows a user program to request services from the OS such as waiting for I/O requests to get completed.

 - **System Call**: request to OS to allow user to wait for I/O
 - **Device Status Table**: contains entry for each I/O device including its type, address and state.
 - Os indexes into I/O device table to determine device status and to modify table entries to include the interrupt.

## Direct Memory Access

- Used for high speed I/O devices, close to memory speeds
- Device controller transfers blocks of data from buffer storage directly to main memory without CPU intervention.
- Only one interrupt is generated per block. Rather than one per byte.

---