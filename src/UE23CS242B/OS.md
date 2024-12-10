# UE23CS242B: Operating Systems

> This course focuses on fundamental operating systems concepts including various algorithms and trade-offs for efficient management of resources such as CPU, Memory, Storage and I/O.

## Course Objectives

- Learn the fundamental Operating System concepts and various algorithms for process management.
- Demonstrate various algorithms and associated trade-offs for efficient resource management such as inter-process communication, threads, process synchronization, deadlocks.
- Provide an understanding and apply various memory management techniques.
- Understand file system and secondary storage structures.

## Course Outcomes

- Understand the design of various algorithms for scheduling and their relative performance.
- Understand and apply Inter Process Communication, threads, process synchronization and deadlocks
- Apply various memory management techniques.
- Understand file system, its implementation and the various secondary storage structures.

# Course Contents

> **U1**: [[U1_Process_Management|Introduction and Process Management]]

**What Operating Systems Do**: Operating-System Structure & Operations, Kernel Data Structures, Operating-System Services, Operating System Design and Implementation.**Shell programming**: Overview of bash shell programming – variables, control flow Processes: process concept, Process Scheduling, Operations on Processes, System calls for process management: `fork()`, cron. `vfork()`, `wait()` and `exec()`**CPU Scheduling**: Basic Concepts, Scheduling Criteria, Scheduling Algorithms. Case Study: Linux Scheduling Policies.

> **U2**: [[U2_IPC_Threads_Concurrency|IPC, Threads and Concurrency]]

**IPC**: Introduction, Shared Memory systems, Message Passing, Communication in Client–Server Systems- Pipes, Ordinary pipes and named pipes, system calls for shared memory, pipes and FIFO’s. **Threads**: Overview, Multicore Programming, Multithreading Models, Thread Libraries, Thread Scheduling. **Process Synchronization**: Background, The Critical-Section Problem, Peterson’s Solution, Synchronization Hardware, Mutex Locks, Semaphores, Classic Problems of Synchronization- The Bounded-Buffer Problem, The Readers–Writers Problem, The Dining-Philosophers Problem, Synchronization Examples- Synchronization in Linux. System calls for threads creation and synchronization-POSIX Threads. **Deadlocks**: System Model, Deadlock Characterization, Deadlock avoidance, Banker’s Algorithm, Deadlock Detection, Deadlock Recovery.

> **U3**: [[U3_Memory_Management|Memory Management]]

**Main Memory**: Background- Basic Hardware, Address Binding, Logical Versus Physical Address Space, Dynamic Loading, Dynamic Linking and Shared Libraries, Swapping, Contiguous Memory Allocation, Segmentation, Paging, Structure of the Page Table. **Virtual Memory**: Background, Demand Paging, Copy-on-Write, Page Replacement Algorithms-FIFO, LRU, Optimal, Allocation of Frames, Thrashing.

> **U4**: [[U4_Filesystem_Storage_Management|File and Storage Management]]

**File-System Interface**: File Concept, system calls for file operations-open(), `read()`,`write()`, `lseek()`, `close()` and system call to retrieve file attributes and file types: `stat()`, `lstat()`, Access Methods, Directory and Disk Structure, system calls for reading directories, system calls to create hard links `link()` and symbolic links `symlink()`. **File-System Implementation**: Filesystem Structure, File-System Implementation, Directory Implementation, Allocation Methods, File Sharing, Protection. **Storage management**: Overview of Mass-Storage Structure, Disk Scheduling, Swap-Space Management, RAID
Structure. **System Protection**: Goals, Principles and Domain of Protection, Access Matrix, Implementation of the Access Matrix, Access Control; System Security. **Shell programming**: awk, sed

---

prerequisites: [[DSA|UE23CS251B]]