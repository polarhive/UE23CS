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

# System Architecture

- Most systems use a single general-purpose processor
- Most systems have other special-purpose processors as well.
- Device specific processors like disk, keyboard, graphic controller
- Special-purpose processors run a limited number of instructions
- Special-purpose processors are low-level components built into the hardware
- It is managed by OS.
- OS monitors the status.

> [!Example] Example Disk controller microprocessor
>
> - Receives sequence of requests from CPU.
> - Implements its own disk queue and scheduling algorithm
> - Relieves the main CPU of the overhead of disk scheduling.

## Multiprocessor

- Also known as **parallel systems**, tightly-coupled systems
- Advantages include:
	- Increased **throughput**
	- Economy of **scale**
	- Increased **reliability**: graceful degradation or fault tolerance

![[Pasted image 20250115122751.png]]

1. **Asymmetric** Multiprocessing – each processor is assigned a **specific** task.
2. **Symmetric** Multiprocessing – each processor performs **all** tasks

## ASMP

There exists many processors but they are assigned specific tasks by the master processor such as background processing or handling interrupts. Ex. Mtorola 68000 based systems.

## SMP: Symmetric Multiprocessing Architecture

![[Pasted image 20250115122858.png]]

> In SMP all processors are **peers**; no boss–worker relationship exists between processors.

- Each processor is capable of executing processes independently and in parallel, these are scaleble which means more processors can be added to increase computational power.
- Each processor has its own set of registers, as well as a private or local cache.
- All processors **share** physical memory.

## Multi-Core Design

- A recent trend in CPU design is to include multiple computing cores on a single chip. Such multiprocessor systems are termed multicore.
- More efficient than multiple chips with single cores because on-chip communication is faster than between-chip communication.
- One chip with multiple cores uses significantly less power than multiple single-core chips.

## Blade Server

In which multiple processor boards, I/O boards, and networking boards are placed in the same chassis.

- blade-processor board boots independently and runs its own operating system.
- Some blade-server boards are multiprocessor as well, which blurs the lines between types of computers.
- In essence, these servers consists of multiple independent multiprocessor systems.

## Clustered Systems

Like multiprocessor systems, but multiple systems working together

- Usually sharing storage via a storage-area network (**SAN**)
- Provides a **high-availability** service which survives failures:
	- Asymmetric clustering has **one** machine in hot-standby mode: Apache HTTP server
	- Symmetric clustering has **multiple** nodes running applications, monitoring each other: Hadoop.
- Some clusters are for high-performance computing (HPC)
- Applications must be written to use **parallelization**, each node is actively involved in performing tasks.
- Some have distributed lock manager (**DLM**) to avoid conflicting operations (Ex: when multiple hosts access the same data on shared storage while it's being used).

![[Pasted image 20250115123506.png]]

---

# OS Structure

## Multiprogramming (Batch system)

> Needed for efficiency

- Single user cannot keep CPU and I/O devices busy at all times
- Multiprogramming organizes jobs (code and data) so CPU always has one to execute
- A subset of total jobs in system is kept in memory
- One job selected and run via job scheduling
- When it has to wait (for I/O for example), OS switches to another job

![[Pasted image 20250115124440.png]]

##  Multitasking (Timesharing)

Timesharing is the logical extension in which CPU switches jobs so frequently that users can interact with each job while it is running, creating interactive computing

> Response time should be < 1 second

- Each user has at least one program executing in memory -> process
- If several jobs ready to run at the same time -> CPU scheduling
- If processes don’t fit in memory, swapping moves them in and out to run
- Virtual memory allows execution of processes not completely in memory

> Virtual memory is a memory management technique used by modern OS to give the illusion of a larger amount of RAM than what is physically available on the system, by using combination of physical RAM.

# OS Operations

> Interrupt driven (hardware and software)

- Hardware interrupt by one of the devices
- Software interrupt (exception or trap):
- Software error (e.g., division by zero)
- Request for operating system service
- Other process problems include infinite loop, processes modifying each other or the operating system.

# Dual-Mode and Multimode

> Dual-mode operation allows OS to protect itself and other system components

- **User mode** and **kernel** mode (supervisor mode) of operation.
- Mode bit provided by hardware
- Provides ability to distinguish when system is running user code or kernel code
- Some instructions designated as privileged, only executable in kernel mode
- System call changes mode to kernel, return from call resets it to user

Increasingly CPUs support multi-mode operations:

> i.e. virtual machine manager (VMM) mode for guest VMs

It's responsible for managing and running multiple VMs on a physical machine, it is also called as a hypervisor.

## Transition from user to kernel mode

User mode is the non-privileged mode in which user applications can run, it prevents direct access to hardware. The transition between user/kernel mode is done via a syscall.

When a trap or interrupt occurs, hardware switches from user mode to kernel mode (changes the state of the mode bit to 0). When the request is fulfilled, the system always switches to user mode (by setting the mode bit to 1) before passing control to a user program.

![[Pasted image 20250115125145.png]]

## Timer

- Timer to prevent infinite loop / process hogging resources
- Timer is set to interrupt the computer after a specified period (fixed 1/60 sec or variable 1 msec to 1 sec)
- A variable timer is generally implemented by a fixed-rate clock and a counter.
- Operating system sets the counter (privileged instruction)
- Every time the clock ticks, the counter is decremented.
- When counter reaches zero, an interrupt occurs

> Timer can be used to prevent a user program from running too long (terminate the program)

---

# Kernel Data Structures

## Array

- An array is a simple data structure in which each element can be accessed directly.
- Main Memory constructed with array.
- How the data is accessed?
- Items with multiple bytes are accessed as item number × item size
- But what about storing an item whose size may vary?
- what about removing an item if the relative positions of the remaining items must be preserved?

## Lists

- Standard programming data structures are used extensively in OS Singly linked list
- The items in a list must be accessed in a particular order.
- common method for implementing this structure is a linked list
- In a singly linked list, each item points to its successor.
- In a doubly linked list, a given item can refer either to its predecessor or to its successor.
- In a circularly linked list, the last element in the list refers to the first element, rather than to null.
- Lists are used by the some of the kernel algorithms
- Constructing more powerful data structures such as stacks and queues

### Advantages

- Linked lists accommodate items of varying sizes.
- Allow easy insertion and deletion of items

### Disadvantages

Performance for retrieving a specified item in a list of size n is linear — O(n) , as it requires potentially traversing all n elements in the worst case.

## Stack

> sequentially ordered data structure that uses LIFO principle for adding and removing items

- OS often uses a stack when involving function calls.
- Parameters, local variables and the return address are pushed onto the stack when a function is called
- Return from the function call pops those items off the stack

## Queue

> sequentially ordered data structure that uses FIFO principle for adding and removing items

- Tasks waiting to be run on an available CPU are organized in queues
- Print jobs sent to a printer are printed in the order of submission

## Trees

- Data structure used to represent data hierarchically.
- Data values in a tree structure are linked through parent–child relationships
- Binary search tree
- ordering between 2 children: left <= right
- Search performance is O(n)
- Balanced binary search tree – (a tree containing n items has at most log n levels)
- Search performance is O(log n)
- Used by Linux for selecting which task to run next (CPU-Scheduling algorithm

## Hash Functions/Maps

- Hash functions can result in the same output value for 2 inputs
- Hash function can be used to implement a hash map
- Maps or associates key:value pairs using a hash function
- Search performance is O(1)

## Bitmap

> string of n binary digits representing the status of n items

- Availability of each resource is indicated by the value of a binary digit
- 0 – resource is available
- 1 – resource is unavailable
- Value of the ith position in the bitmap is associated with the ith resource
- Example: bitmap 001011101 shows resources 2, 4, 5, 6, and 8 are unavailable; resources 0, 1, 3, and 7

are available

- Commonly used to represent the availability of a large number of resources (disk block)

# Computing Environments

## Traditional

- Stand-alone general purpose machines
- But blurred as most systems interconnect with others (i.e., the Internet)
- Portals provide web access to internal systems
- Network computers (thin clients) are like Web terminals
- Mobile computers interconnect via wireless networks
- Networking becoming ubiquitous – even home systems use firewalls to protect home computers from Internet attacks

## Mobile

- Handheld smartphones, tablets, etc
- What is the functional difference between them and a “traditional” laptop?
- Extra feature – more OS features (GPS, gyroscope)
- Allows new types of apps like augmented reality
- Use IEEE 802.11 wireless, or cellular data networks for connectivity
- Leaders are Apple iOS and Google Android

## Distributed computing

- Collection of separate, possibly heterogeneous systems networked together
- Network is a communications path, TCP/IP most common
- Local Area Network (LAN)
- Wide Area Network (WAN)
- Metropolitan Area Network (MAN)
- Personal Area Network (PAN)

> Network Operating System provides features between systems across network

- Communication scheme allows systems to exchange messages
- Illusion of a single system

## Client-Server Computing

- Dumb terminals replaced by smart PCs
- Many systems now servers, responding to requests generated by clients
- Compute-server system provides an interface to client to request services (i.e., database)
- File-server system provides interface for clients to store and retrieve files

## Peer-to-Peer

- Another model of distributed system
- P2P does not distinguish clients and servers
- Instead all nodes are considered peers
- May each act as client, server or both
- Node must join P2P network
- Registers its service with central lookup service on network, or
- Broadcast request for service and respond to requests for service via discovery protocol

> Examples include Napster and Gnutella, Voice over IP (VoIP) such as Skype

## Virtualization

-  Allows operating systems to run applications within other OSes
- Emulation used when source CPU type different from target type (i.e. PowerPC to Intel x86)
- Generally slowest method
- When computer language not compiled to native code – Interpretation
- Virtualization – OS natively compiled for CPU, running guest OSes also natively compiled
- Consider VMware running WinXP guests, each running applications, all on native WinXP host OS
- VMM (virtual machine Manager) provides virtualization services. Use cases involve laptops and desktops running multiple OSes for exploration or compatibility
- Apple laptop running Mac OS X host, Windows as a guest
- Developing apps for multiple OSes without having multiple systems
- QA testing applications without having multiple systems
- Executing and managing compute environments within data centers
- VMM can run natively, in which case they are also the host

## Cloud Computing

- Cloud computing environments composed of traditional OSes, plus VMMs, plus cloud management tools
- Internet connectivity requires security like firewalls
- Load balancers spread traffic across multiple applications
- Delivers computing, storage, even apps as a service across a network
- Logical extension of virtualization because it uses virtualization as the base for it functionality.

> Amazon EC2 has thousands of servers, millions of virtual machines, petabytes of storage available across the Internet, pay based on usage

- Public cloud – available via Internet to anyone willing to pay
- Private cloud – run by a company for the company’s own use
- Hybrid cloud – includes both public and private cloud components
- Software as a Service (SaaS) – one or more applications available via the Internet (i.e., word processor)
- Platform as a Service (PaaS) – software stack ready for application use via the Internet (i.e., a database server)
- Infrastructure as a Service (IaaS) – servers or storage available over
Internet (i.e., storage available for backup use)

### Real-Time Embedded Systems

- Real-time embedded systems most prevalent form of computers
- Vary considerable, special purpose, limited purpose OS, real-time OS
- Many other special computing environments as well
- Some have OSes, some perform tasks without an OS
- Real-time OS has well-defined fixed time constraints
- Processing must be done within constraint
- Correct operation only if constraints met

# Operating System Services

- Set of operating-system services provides functions that are helpful to the user:
- User interface - Almost all operating systems have a user interface (UI).
- Command-Line (CLI) - Command interpreters (shells)
- Graphics User Interface (GUI)
- Batch Program execution - The system must be able to load a program into memory and to run that program, end execution, either normally or abnormally (indicating error)
- I/O operations - A running program may require I/O, which may involve a file or an I/O device
- File-system manipulation - The file system is of particular interest. Programs need to read and write files and directories, create and delete them, search them, list file Information, permission management.
- Communications – Processes may exchange information, on the same computer or between computers over a network
- Communications may be via shared memory or through message passing (packets moved by the OS)
- Error detection – OS needs to be constantly aware of possible errors May occur in the CPU and memory hardware, in I/O devices, in user program
- For each type of error, OS should take the appropriate action to ensure correct and consistent computing

> Debugging facilities can greatly enhance the user’s and programmer’s abilities to efficiently use the system

Another set of OS functions exists for ensuring the efficient operation of the system itself via resource sharing

- Resource allocation - When multiple users or multiple jobs running concurrently, resources must be allocated to each of them
- Many types of resources - CPU cycles, main memory, file storage, I/O devices.
- Accounting - To keep track of which users use how much and what kinds of computerresources
- Protection and security - The owners of information stored in a multiuser or networked computer system may want to control use of that information, concurrent processes should not interfere with each other
- Protection involves ensuring that all access to system resources is controlled
- Security of the system from outsiders requires user authentication, extends to defending external I/O devices from invalid access attempts
- System calls provide an interface to the services made available by an operating system.
- These calls are generally available as routines written in a higher level programming language or assembly-language

> Example: Sequence of system calls used for copying contents from one file to another

> [!Important] Types of System calls
> System calls can be grouped roughly into six major categories:
> 1.Process control
> 2.File manipulation
> 3.Device manipulation
> 4.Information maintenance
> 5.Communications
> 6.Protection

> [!Example] a system call
> - A C program invokes the `printf()` statement
> - The C library intercepts this call and invokes the necessary system call write() in the operating system
> - The C library takes the value returned by `write()` and passes it back to the user program

---

# Design goals

- Start the design by defining goals and specifications
- Affected by choice of hardware and the type of system
- Requirements can be categorized as User goals and System goals
- User goals – operating system should be convenient to use, easy to learn, reliable, safe, and fast.
- System goals – operating system should be easy to design, implement, and maintain, as well as flexible, reliable, error-free, and efficient

## Important principle to separate

1. Policy: What will be done?
2. Mechanism: How to do it?

- Mechanisms determine how to do something, policies decide what will be done
- The separation of policy from mechanism is a very important principle, it allows maximum flexibility if policy decisions are to be changed later (example – timer to prevent a user program from running too long)
- Specifying and designing an OS is highly creative task of software engineering

## Implementation

- Much variation
- Early OSes in assembly language
- Then system programming languages like Algol, PL/1 Now C, C++
- Actually usually a mix of languages
- Lowest levels in assembly
- Main body in C
- Systems programs in C, C++, scripting languages like PERL, Python, shell scripts
- More high-level language easier to port to other hardware But slower
- Emulation can allow an OS to run on non-native hardware

---

# Processes

> A program in execution; process execution must progress in sequential fashion

- Batch system: jobs
- Time-shared systems: user programs or tasks
- Program is passive entity stored on disk (executable file), process is active.
- Program becomes process when executable file loaded into memory
- One program can be several processes.

## Structure of a process

- The program code is also known as the `.text` section.
- Includes current activity including **program counter**, processor registers
- **Stack** containing temporary data
	- Function parameters, return addresses, local variables
- `.data` section containing global variables
- **Heap** containing memory dynamically allocated during run time

## States

- **New**: Creation of process
- **Ready**: Waiting to be assigned to a processor
- **Running**: Executing the instructions
- **Waiting**: Waiting for an event to occur
- **Terminating**: Finished executing

## PCB: Process Control Block

> Each process is represented in the operating system by a Process Control Block (also called task control block)

![[Pasted image 20250122130420.png]]

- Process state – running, waiting, etc
- Program counter – location of instruction to next execute
- CPU registers – contents of all process-centric registers
- CPU scheduling information: priorities, scheduling queue pointers
- Memory-management information – memory allocated to the process
- Accounting information – CPU used, clock time elapsed since start, time limits
- I/O status information – I/O devices allocated to process, list of open files

## Process Scheduling

- Maximize CPU use, quickly switch processes onto CPU for time sharing
- Process scheduler selects among available processes for next execution on CPU
- Maintains scheduling queues of processes.
- Job queue – set of all processes in the system
- Ready queue – set of all processes residing in main memory, ready and waiting to execute
- Device queues – set of processes waiting for an I/O device
- Processes migrate among the various queues

## Ready Queue And Various I/O Device

![[Pasted image 20250122130435.png]]

![[Pasted image 20250122130446.png]]

# Schedulers

- **Short**-term scheduler (or CPU scheduler) – selects which process should be executed next and allocates CPU:
	- Sometimes the only scheduler in a system
	- Short-term scheduler is invoked frequently (milliseconds) -> (must be fast)
-  **Long**-term scheduler (or job scheduler) – selects which processes should be brought into the ready queue:
	- Long-term scheduler is invoked infrequently (seconds, minutes) -> (may be slow)
	- The long-term scheduler controls the degree of multi programming.

## Bounding

- I/O-bound process – spends more time doing I/O than computations, many short CPU bursts.
- CPU-bound process – spends more time doing computations; few very long CPU bursts

> Long-term scheduler strives for good process mix

## Representation of Process Scheduling

**Medium**-term scheduler can be added if degree of multiple programming needs to decrease. Remove process from memory, store on disk, bring back in from disk
to continue execution: **swapping**.

![[Pasted image 20250122130841.png]]

### Context Switching

- When CPU switches to another process, the system must save the state of the old process and load the saved state for the new process via a context switch.
- Context of a process represented in the PCB
- Context-switch time is overhead; the system does no useful work while switching
- The more complex the OS and the PCB -> the longer the context switch
- Time dependent on hardware support
- Some hardware provides multiple sets of registers per CPU -> multiple contexts loaded at once.

# Process Creation

- Parent process creates children processes, which in-turn form a tree of processes.
- They are identified by a `pid` process identifier.

## Resource sharing

- Parent and child share all resources
- Children share a subset of resources
- Share no resources

### Execution options

- Execute concurrently
- Parent wait until child terminates
- Using `fork()`

### Address Space

- child is duplicate of parent
- child has a program loaded into it

> [!Tip]
> - `fork()` creates a new process
> - `exec()` used after a fork to replace the process' memory space with new program

### Process Termination

 - Process executes the ==last== statement and then asks the OS to delete it using the `exit()` syscall. It returns the status data from child to parent via `wait()`
 - Process's resources are deallocated by the OS
- Parent may terminate the execution of children process using the `abort()` syscall.
	- Child has exceeded allocated resources
	- Task assigned to child is no longer needed
	- Parent is exiting and the OS doesn't allow a orphaned process
- Cascading termination: all children, grandchildren are terminated.
- The parent may wait for child termination using `wait()` syscall
- The call returns the status information and the pid of the terminated process
- `pid - wait(&status)`
- If no parent waiting: zombie
- If parent is terminated without invoking `exit()` it becomes an orphan

### Process Identifiers

- It tries to guarantee uniqueness

---

# fork

- return value in child: `0`
- return value in parent is the pid of new child: `pid`
- return value err: `-1`
- The child is a copy of the parent, and gets a copy of the parents data space, heap and stack

# exit

- executing a return from main
- calling exit function
- calling the `_exit` or `_Exit` function
- executing a return from the start routing of the last thread in the process
- calling the `pthread_exit` function from the last thread

## Abnormal ways

- calling abort
- when process receives signals
- the last thread responds to a cancellation request

# wait() waitpid()

- Block if all of its children are running
- Return immediately with termination status of the child, if a child has been terminated and is waiting for the termination status to be fetched
- Return immediately with an error if it doesn't have any child process
- `SIGCHILD`, will wait return immediately. But if we call it at any random point in time it can block.

# waitid()

- allows a process ot specify which child to wait for
- two separate arguments are used

# exec()

- process is completely replaced by the new program and the new program starts executing its main function
- the `pid` does not change across an exec, because a new process is not created
- exec merely replaces the current process, its text, data, heap, and stack with a brand new program from disk

# getpid(), getppid()

- `getpid()` returns the `pid` of the calling process
- `getppid()` returns the process id of the parent of the child process, this will either be the id of the process that created this process using fork or if that process has already been terminated, the ID of the process to which this process has been re-parented

# Race condition

- When accessing shared resources / data
- A fork function is a lively breeding ground for race conditions
- A process that wants to wait for a chlid to terminate, a loop could be used
- The problem here is polling, it wastes the CPU time as the caller is awakened every second to test the condition
- A form of signalling is used

---

# CPU Scheduling

Multi-programming is utilized to maximize CPU utilization. Several processes are kept in memory at one time. Every time one process has to wait, another program can take over the CPU.

## CPU / IO bursts

- Consists of a cycle of CPU and IO wait.
- CPU burst followed by IO burst
- CPU burst distribution is the main concern

![[Pasted image 20250220105107.png]]

- An IO bound program typically has many short CPU bursts

### Short term

- Selects from the ready queue and allocated CPU to one of them
- Queue may be ordered in various ways
- FIFO, Priority, Tree, Unordered
- The records in the queue are PCB's of the processes

### Preemptive

CPU scheduling may occur when:

- running to waiting
- running to read
- waiting to ready
- terminates

> These so far are non-preemptive

- Access to shared data
- Preemption in kernel mode
- Interrupts occruing during crucial OS activities

> Unfortunately, pre-emptive scheduling can result in race conditions when data are shared among several processes. Ex: While one process is updating the shared data, it is pre-empted so that the second process can run. The second process then tries to read the data, which are in an inconsistent state.
>
> A pre-emptive kernel requires mechanisms such as mutex locks to prevent race conditions when accessing shared kernel data structures. Most modern operating systems are now fully pre-emptive when running in kernel mode.

# Dispatcher

> Dispatcher module gives control of the CPU to the process selected by the short-term scheduler.

- switching context
- switching to user mode
- jumping to the user-program location to restart the program

> Dispatch latency: time taken to stop one process and start another running

---

# Scheduling criteria

- CPU util: keep as busy as possible
- Throughput: no of processes that complete their execution per unit time
- Turnaround time: time to execute a particular process
- Waiting time: time waiting in in ready queue
- Response time: time taken when a request was submitted until a first response is produced

## FCFS

![[Pasted image 20250220105828.png]]

![[Pasted image 20250220105847.png]]

### Convoy effect

> short process behind long process

- Consider one CPU-bound and many I/O-bound processes
-  FCFS scheduling algorithm is non-preemptive. Once the CPU has been allocated to a process, that process keeps the CPU until it releases the CPU
- FCFS algorithm is thus particularly troublesome for time-sharing systems, where it is important that each process to get a share of the CPU at regular intervals.
- It is not desirable to allow one process to keep the CPU for an extended period

## SJF Scheduling

> Shortest wait time job gets executed first.

![[Pasted image 20250220110008.png]]

> Associate with each process the length of its next CPU burst

Use these lengths to schedule the process with the shortest time

- SJF is optimal – gives minimum average waiting time for a given set of processes
- The difficulty is knowing the length of the next CPU request
- Compute an approximation of the length of the next CPU burst

### Determining Length of Next CPU Burst

![[Pasted image 20250220110032.png]]

![[Pasted image 20250220110048.png]]

![[Pasted image 20250220110106.png]]

![[Pasted image 20250220110118.png]]

![[Pasted image 20250220110129.png]]

![[Pasted image 20250220110146.png]]

## Priority Scheduling

- A priority number (integer) is associated with each process
- The CPU is allocated to the process with the highest priority (smallest integer ~ highest priority)
	- Preemptive
	- Nonpreemptive
- SFJ is priority scheduling where priority is the inverse of predicted next CPU burst time
- Problem ~ Starvation (low priority may never execute)
- Solution ~ Aging (increase priority as time progresses)

![[Pasted image 20250220110722.png]]

## Round Robin

- For timesharing systems
- Similar to FCFS, but preemption is added to let it switch between to processes
- A small unit of time, called a time quantum or time slice is defined
- 10-100 ms
- The ready queue is treated as a circular queue
- The CPU scheduler goes around the ready queue, allocating the CPU to each process for a time interval up upto 1 time quantum.
![[Pasted image 20250220111633.png]]

> If there are n processes in the ready queue and the time quantum is q, then each process gets 1/n of the CPU time in chunks of at most q time units.

- Each process must wait no longer than (n − 1) × q time units until its next time quantum.

> For example, with five processes and a time quantum of 20 milliseconds, each process will get up to 20 milliseconds every 100 milliseconds.

- Performance of the RR algorithm depends heavily on the size of the time quantum
- If the time quantum is extremely large, the RR policy is the same as the FCFS policy
- If the time quantum is extremely small, the RR approach can result in a large number of context switches
![[Pasted image 20250220111730.png]]

### Turnaround time varies with time quantum

![[Pasted image 20250220111747.png]]

> 80% of the CPU bursts should be shorter than the time quantum

## Multilevel Queue

- Ready queue is partitioned into separate queues
	- foreground (interactive)
	- background (batch)
 - Process permanently assigned to a queue
 - Each queue has its own algorithm
	 - foreground: RR
	 - background: FCFS
- In addition, scheduling must be done between the queues
- Fixed priority scheduling (serve all from foreground then from background) (possibility of starvation)
- Time slice: each queue gets a certain amount of CPU time which it can schedule among its processes.
- Each queue has absolute priority over lower priority queues
- No process in the batch queue, could run unless the queues for the system, processes, interactive processes, and interactive editing processes were all empty.
- If an interactive editing process entered the ready queue while a batch process was running, the batch process would be prempted
- A process can move between the various queues, aging can be implemented this way.

### Parameters

- Number of queues
- Scheduling algorithms for each queue
- Method used to determine when to upgrade a process
- Method used to determine when to demote a process
- Method used to determine which queue a process will enter when that process needs service
![[Pasted image 20250220112423.png]]

![[Pasted image 20250220112431.png]]

## Multiple Processor Scheduling

1. Asymmetric Scheduling (master-server) all other just execute code
2. SMP (Processors are self-scheduling)

### Affinity

- The process populate cache of the processor.
- Successive memory accesses invalidate the cache of the other
	- **Soft**: OS will attempt to keep a process on a single processor, but it's possible for a process to migrate
	- **Hard**: OS provides syscalls for process to specify a subset of processors on which it may run.

### Load Balancing

Keeps the workload evenly distributed across SMP systems

1. **Push migration**: periodically checks the load on each processor and finds if there's an imbalance and evenly distributes the load by moving/pushing from overloaded to idle processors.
2. **Pull migration**: When an idle processor pulls a waiting task from a busy processor. Push and pull may not be mutually exclusive.

# Case Study

## < Linux 2.5

- Did not support SMP
- Variation of the UNIX scheduling algorithm

## Linux 2.5

- Kernel moved to constant $O(1)$ scheduling time
- Supported SMP
- Poor response times for interactive processes that are common on the desktop

## Linux 2.6+

- Completely Fair Scheduler (CFS)
	- Each class is assigned a specific priority
	- Using different scheduling classes, the kernel can accommodate different scheduling algorithms
	- Scheduler picks the highest priority task
		- 1. A scheduling class with CFS
		- 2. Real time scheduling class
	- Calculates target latency: (time task runs at least once)
	- Proportion calculated based on nice value which ranges from: -20 to +19
		- A numerically lower nice value indicates a higher realtive priority
		- Tasks with lower nice value receive a higher proportion of CPU time than tasks with higher nice values
	- Target latency can increase if number of active tasks increase
	- The CFS doesn't directly assign priorities
	- Maintains a per-task virtual time run `vruntime`
		- Associated with decay factor based on priority of the task: lower priority is higher decay rate
		- Normal default priority yields virtual run time = actual run time
	- To decide next task it picks the task with the lowest virtual run time.
	- Each runnable task is placed in a balanced binary search tree whose key is based on the value of vruntime
	- When a task becomes runnable, it is added to the tree
	- When a task is not runnable, it is deleted from the tree
	- Navigating the tree to discover the task to run (leftmost node) will require $O(log N)$ operations (where N is the number of nodes in the tree).
	- Assume that two tasks have the same nice values.
	- One task is I/O-bound and the other is CPU-bound
	- The value of vruntime will be lower for the I/O-bound task than for the CPU-bound task, giving the I/O-bound task higher priority than the CPU-bound task.
	- If the CPU-bound task is executing when the I/O-bound task becomes eligible to run the IO bound task will prempt the CPU bound task.

![[Pasted image 20250220120700.png]]

## Windows Scheduling

- Used priority based pre-emptive scheduling algorithm
- Scheduler ensures that the highest-priority thread will always run
- Windows kernel that handles scheduling is called the dispatcher
- Thread selected by the dispatchers is preempted by a higher priority thread or until it terminates or until its time quantum ends or it calls a blocking syscall.
- Dispatcher uses a 32-level priority scheme
	- Variable class is 1-15, real time is 16-31
	- Priority 0 is memory management thread
- Queue for each priority class
- If no runable thread, runs idle thread.

> Windows API identifies several priority classes to which a process can belong

- `REALTIME_PRIORITY_CLASS, HIGH_PRIORITY_CLASS, ABOVE_NORMAL_PRIORITY_CLASS,NORMAL_PRIORITY_CLASS, BELOW_NORMAL_PRIORITY_CLASS, IDLE_PRIORITY_CLASS`
- All are variable except REALTIME
-  A thread within a given priority class has a relative priority
- `TIME_CRITICAL, HIGHEST, ABOVE_NORMAL, NORMAL, BELOW_NORMAL, LOWEST, IDLE`
- Priority class and relative priority combine to give numeric priority
- Base priority is NORMAL within the class
- If quantum expires, priority lowered, but never below base.

![[Pasted image 20250220121609.png]]

- If wait occurs, priority boosted depending on what was waited for
- Windows distinguishes between foreground process and background processes
- Foreground processes given 3x priority boost
- This priority boost gives the foreground process three times longer to run before a time-sharing preemption occurs.

---

# Shell

> Instructions entered in response to the shell prompt have the following syntax:
> `command [arg1] [arg2] .. [argn]`

- The brackets `[]` indicate that the arguments are optional. Many commands can be executed with or without arguments
- The shell parses the words or tokens `(commandname , options, filenames[s])` and gets the kernel to execute the commands assuming the syntax is correct.
- Typically, the shell processes the complete line after a carriage return (`cr`) (carriage return) is entered and finds the program that the command line wants executing.
- The shell looks for the command to execute either in the specified directory if given `(./mycommand)` or it searches through a list of directories depending on your `$PATH `variable.

## Common env variables

## Control flow

```sh
if cmd; then
	cmd
[elif cmd; then
	cmds ...]
fi
```

```sh
for i in {1..5}
do
	echo "i = $i"
done
```

# cron jobs

![[Pasted image 20250220122117.png]]
