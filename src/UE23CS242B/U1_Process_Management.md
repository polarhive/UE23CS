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