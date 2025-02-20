# IPC, Threads, Concurrency

> Processes within a system may be independent or cooperating

## Cooperating processes IPC

- Two models of IPC
	- Shared memory
	- Message passing

## Cooperating

- Independent: can not affect or be affected by the execution of another process
- Co-operating: can affect or be affected by the execution of another process

### Reasons for cooperating processes

- Information sharing
- Computation speedup
- Modularity
- Convenience

![[Pasted image 20250220122419.png]]

---

# Producer-Consumer Problem

> Paradigm for cooperating processes, producer process produces information that is
consumed by a consumer process

 - unbounded-buffer: places no artificial limit
	 - consumer may have to wait for new items but the producer can always produce new items
 - bounded-buffer: assumes that there is a fixed buffer size
	 - consumer must wait if the buffer is empty, producer must wait if the buffer is full

```c
#define BUFFER_SIZE 10
typedef struct {
	...
} item;

item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
```

- Shared buffer is implemented as a circular array with 2 logical pointers: in and out
- Buffer is empty when `in==out`, and buffer is full when `((in+1)%buff size) == out`
- Variable in points to the next free position in the buffer, out points to the first full position in the buffer
- Solution is correct but can only user `BUFFER_SIZE-1` elements

```c
item next_produced;
while (true) {
	/* produce an item in next_produced */
	while (((in + 1) % BUFFER_SIZE) == out)
	; /* do nothing */
	buffer[in] = next_produced;
	in = (in + 1) % BUFFER_SIZE;
}

item next_consumed;
while (true) {
	while (in == out)
	; /* do nothing */
	next_consumed = buffer[out];
	out = (out + 1) % BUFFER_SIZE;
/* consume the item in next_consumed */
}
```

---

# Shared Memory

- The communication is under the control of the users processes not the OS
- Major issue is to provide the mechanism that will allow the user processes to synchronize their actions when they access shared memory
- Shared memory is the fastest form of IPC, because the data does not need to be copied between the client/server.
- The only trick in using shared memory is synchronizing access to a given region among multiple processes.
- If the server is placing data into a shared memory region, the client shouldn't try to access the data until the server is done.
- Often a semaphore is used to synchronize shared memory access (record lock also can be used).

## Message Passing

- Mechanism for process to communicate and synchronize actions
- Message system: processes communicate with each other without resorting to shared variables
- IPC provides two functions
	- send(msg)
	- rec(msg)
- The message size is fixed/variable

### If process P, Q wish to communicate, they need to

- Establish a **communication link**
- Exchange messages via send/receive

### Implementation

- Physical
	- Shared memory
	- Hardware bus
	- Network
- Logical
	- Direct/Indirect
	- Synchronous / asynchronous
	- Automatic or explicit buffering

## Direct Communication

- Processes must name each other explicitly:
	- send (P, msg)
	- rec (Q, msg)

### Properties of communication link

- Links are established automatically
- A link is associated with exactly one pair of communicating processes
- Between each pair there exists exactly one link
- The link may be unidirectional, but is usually bi-directional

## Indirect Communication

- Messages are directed and received from mailboxes (also referred to as ports)
- Each mailbox has a unique id
- Processes can communicate only if they share a mailbox
- Properties of communication link
- Link established only if processes share a common mailbox
- A link may be associated with many processes
- Each pair of processes may share several communication links
- Link may be unidirectional or bi-directional

### operations

- create a new mailbox (port)
- send and receive messages through mailbox
- destroy a mailbox
- Primitives are defined as:
	- send(A, message) – send a message to mailbox A
	- receive(A, message) – receive a message from mailbox A
-  Mailbox sharing
	- P1, P2, and P3 share mailbox A
	- P1 sends; P2 and P3 receive
	- Who gets the message?
-  Solutions
	- Allow a link to be associated with at most two processes
	- Allow only one process at a time to execute a receive operation
	- Allow the system to select arbitrarily the receiver. Sender is notified who the receiver was.

## Synchronization

> May be blocking/non-blocking

- Blocking is synchronous
	- Blocking send: sender is blocked till ACK
	- Blocking receive: receiver is blocked till ACK
- Non-blocking is asynchronous
	- Non Blocking send: sends and continue
	- Non Blocking receive: receives a valid or null message

> Combos are possible, if both are blocking we have a rendezvous between the sender and receiver

> Producer-consumer becomes trivial

```c
message next_produced;
while (true) {
/* produce an item in next_produced */
send(next_produced);
}
message next_consumed;
while (true) {
receive(next_consumed);
/* consume the item in next_consumed */
}
```

---

# Buffering

- Queue of messages attached to the link (direct/indirect), messages reside in temp queue
- Queues can be implemented in one of three ways
	1. Zero capacity – no messages are queued on a link. Sender must wait for receiver (rendezvous)
	2. Bounded capacity – finite length of n messages. Sender must wait if link full
	3. Unbounded capacity – infinite length. Sender never waits
- Zero capacity case is sometimes referred to as a message system with no buffers. Other cases are auto-buffering.

# Pipes

- Pipes are the oldest form of UNIX System IPC and are provided by all UNIX systems.
- Pipes have **two limitations**
	1. Historically, they have been half duplex (i.e., data flows in only one direction). Some systems now provide full-duplex pipes, but for maximum portability, we should never assume that this is the case.
	2. Pipes can be used only between processes that have a common ancestor. Normally, a pipe is created by a process, that process calls fork, and the pipe is used between the parent and the child.

> A pipe is created by calling the `pipe()` function.

- returns two fd
	- `fd[0]` open for reading
	- `fd[1]` open for writing
	- The output of `fd[1]` is input for `fd[0]`

## Half duplex pipe

![[Pasted image 20250220125503.png]]

- Normally, a process that calls pipe then calls fork, creating an IPC channel from the parent to the child or vice versa.
- For a pipe from the parent to the child, the parent closes the read end of the pipe `(fd[0])` and the child closes the write end `(fd[1]).`
- For a pipe from the child to the parent, the parent closes `fd[1]`, and the child closes `fd[0]`

![[Pasted image 20250220125515.png]]

### popen(), pclose()

 A common operation is to create a pipe to another process to either read its output or send it input, the standard I/O library has historically provided the popen() and pclose() functions

> These two functions handle all the work: creating a pipe, forking a child, closing the unused ends of the pipe, executing a shell to run the command, and waiting for the command to terminate.

- The function popen() does a fork and exec to execute the cmdstring and returns a standard I/O file pointer.
- If type is "r", the file pointer is connected to the standard output of cmdstring .
- If type is "w", the file pointer is connected to the standard input of cmdstring
- The function popen() returns file pointer if OK, NULL on error
- The function pclose() closes the standard I/O stream, waits for the command to terminate, and returns the termination status of the shell or -1 on error

---

# FIFO

> FIFOs are sometimes called named pipes.

![[Pasted image 20250220125743.png]]

- Unnamed pipes can be used only between related processes when a common ancestor has created the pipe.
- With FIFOs, unrelated processes can exchange data
- Creating a FIFO is similar to creating a file
- Functions mkfifo() and mkfifoat() return 0 if OK, −1 on error
- Once a FIFO has been created using mkfifo() or mkfifoat() , it can be opened using open(). Normal file I/O functions (e.g., close, read, write, unlink) all work with FIFOs.

## There are two uses for FIFOs

1. FIFOs are used by shell commands to pass data from one shell pipeline to another without creating intermediate temporary files.
2. FIFOs are used as rendezvous points in client–server applications to pass data between the clients and the servers.

---

# Message Queues

![[Pasted image 20250220125806.png]]

# Semaphore

- A semaphore is a counter used to provide access to a shared data object for multiple processes.
- To obtain a shared resource, a process needs to do the following:
	1. Test the semaphore that controls the resource.
	2. If the value of the semaphore is positive, the process can use the resource. In this case, the process decrements the semaphore value by 1, indicating that it has used one unit of the resource.
	3. Otherwise, if the value of the semaphore is 0, the process goes to sleep until the semaphore value is greater than 0. When the process wakes up, it returns to step 1.
- When a process is done with a shared resource that is controlled by a semaphore, the semaphore value is incremented by 1.
- If any other processes are asleep, waiting for the semaphore, they are awakened.

![[Pasted image 20250220125850.png]]

# Shared Memory

- Shared memory allows two or more processes to share a given region of memory.
- This is the fastest form of IPC, because the data does not need to be copied between the client and the server
- The challenge in using shared memory is synchronizing access to a given region among multiple processes.
- Semaphores and mutexes are used to synchronize shared memory access
- Function `shmget` is used to obtain a shared memory identifier

 ![[Pasted image 20250220130002.png]]

![[Pasted image 20250220130020.png]]

![[Pasted image 20250220130032.png]]

# Threads

- A Thread is a fundamental unit of CPU utilization that forms the basis of multithreaded computer systems.
- It consists of thread ID, Program counter, a register set and stack
- Shares with other threads of same process its code, data,file descriptors, signals
- Most modern applications are multithreaded.

## Multi threaded Server architecture

> Process creation is heavy-weight while thread creation is light-weight

- Process creation if time consuming, resource intensive
- Threads also play a vital role in remote procedure call (RPC) systems
- Can simplify code, increase efficiency
- Kernels are generally multithreaded

![[Pasted image 20250220130140.png]]

## Benefits

- Responsiveness: may allow continued execution if part of process is blocked or performing lengthy operations.
- It is useful in designing user interfaces.
- A multi-threaded Web browser could allow user interaction in one thread while an image was being loaded in another thread.
	- Example: click on the button
- Resource Sharing: threads share resources of process, easier than shared memory or message passing.
	- Programmer needs to specify the techniques for sharing
	- But threads share the memory and other resources
	- Sharing of resources helps in having many threads within the same address space
- Economy – cheaper than process creation, thread switching lower overhead than context switching.
- In Solaris, for example, creating a process is about thirty times slower than creating a thread, and context switching is about five times slower.
- Scalability – process can take advantage of multiprocessor architectures.
- Threads can run on multiple cores parallelly

### Differences between process/thread

![[Pasted image 20250220130253.png]]