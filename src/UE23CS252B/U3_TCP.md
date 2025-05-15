# Reliable Data Transfer

![[Pasted image 20250515220424.png]]

## RDT-1.0: over a reliable channel

![[Pasted image 20250515220514.png]]

## RDT-2.0: channel with bit errors

![[Pasted image 20250515220618.png]]

![[Pasted image 20250515220641.png]]

### No Errors

![[Pasted image 20250515220657.png]]

### Corrupted Packet

![[Pasted image 20250515220719.png]]

> [!Warning] Issues
   ![[Pasted image 20250515220735.png]]

## RDT-2.1: Garbled NAK/ACK

![[Pasted image 20250515220748.png]]

![[Pasted image 20250515220758.png]]

![[Pasted image 20250515220810.png]]

## RDT-2.2: NAK Free

![[Pasted image 20250515220831.png]]

![[Pasted image 20250515220844.png]]

![[Pasted image 20250515220852.png]]

## RDT-3.0: Stop and Wait

![[Pasted image 20250515220910.png]]

![[Pasted image 20250515220919.png]]

![[Pasted image 20250515220923.png]]

![[Pasted image 20250515220927.png]]

### Pipelining

![[Pasted image 20250515221058.png]]

![[Pasted image 20250515221106.png]]

---

### perf

![[Pasted image 20250515221005.png]]

![[Pasted image 20250515221012.png]]

![[Pasted image 20250515221040.png]]

### In Action

![[Pasted image 20250515220943.png]]

![[Pasted image 20250515220952.png]]

# Go-Back-N

## Sender

![[Pasted image 20250515221154.png]]

## Recv

![[Pasted image 20250515221137.png]]

> [!example]
> ![[Pasted image 20250515221208.png]]

---

# Selective Repeat

![[Pasted image 20250515221542.png]]

![[Pasted image 20250515221551.png]]

![[Pasted image 20250515221559.png]]

> [!Example] Example
> ![[Pasted image 20250515221619.png]]

## Dilemma

![[Pasted image 20250515221635.png]]

![[Pasted image 20250515221649.png]]

---

# TCP:  An Overview

- point-to-point: one sender, one receiver
- reliable, in-order byte steam: no "message boundaries"
- full duplex data:
	- bi-directional data flow in same connection
	- MSS: maximum segment size
- cumulative ACKs
- pipelining: TCP congestion and flow control set window size
- connection-oriented:
	- handshaking (exchange of control messages) initializes sender, receiver state before data exchange
- flow controlled: sender will not overwhelm receiver

## Segment Structure

![[Pasted image 20250515221945.png]]

## Sequence Numbers, ACKs

![[Pasted image 20250515222016.png]]

> [!example] Simple Telnet
> ![[Pasted image 20250515222040.png]]

## RTT, Timeout

![[Pasted image 20250515222057.png]]

![[Pasted image 20250515222110.png]]

![[Pasted image 20250515222121.png]]

## TCP Sender

![[Pasted image 20250515222139.png]]

## TCP Recv: ACK Gen

![[Pasted image 20250515222158.png]]

## Retransmission Scenarios

![[Pasted image 20250515222216.png]]

![[Pasted image 20250515222223.png]]

---

## Fast Retransmit

![[Pasted image 20250515222250.png]]

## Flow Control

![[Pasted image 20250515222318.png]]

![[Pasted image 20250515222326.png]]

## 3-Way Handshake

![[Pasted image 20250515222343.png]]

![[Pasted image 20250515222352.png]]

## FIN

![[Pasted image 20250515222405.png]]

![[Pasted image 20250515222413.png]]

## Causes of Congestion

![[Pasted image 20250515222433.png]]

![[Pasted image 20250515222442.png]]

![[Pasted image 20250515222452.png]]

![[Pasted image 20250515222459.png]]

![[Pasted image 20250515222607.png]]

![[Pasted image 20250515222618.png]]

![[Pasted image 20250515222624.png]]

![[Pasted image 20250515222645.png]]

![[Pasted image 20250515222654.png]]

![[Pasted image 20250515222707.png]]

---

## Approaches Towards Congestion Control

![[Pasted image 20250515222729.png]]

![[Pasted image 20250515222735.png]]

---

## Determine Sender Rate

![[Pasted image 20250515222748.png]]

![[Pasted image 20250515222807.png]]

---

### AIMD

![[Pasted image 20250515222900.png]]

![[Pasted image 20250515222908.png]]

### Slow Start

![[Pasted image 20250515222929.png]]

### Reacting To LOSS

![[Pasted image 20250515222947.png]]

### Slow Start -> Congestion Avoidance

![[Pasted image 20250515223003.png]]

### Summary

![[Pasted image 20250515223026.png]]

---

# Network Layer Services and Protocol

![[Pasted image 20250515223248.png]]

## Forwarding

![[Pasted image 20250515223321.png]]

![[Pasted image 20250515223330.png]]

---

## Best Effort Service Model

![[Pasted image 20250515232703.png]]

![[Pasted image 20250515232715.png]]

![[Pasted image 20250515232724.png]]

![[Pasted image 20250515232739.png]]

### Destination Based

![[Pasted image 20250515232756.png]]

### Longest Prefix

![[Pasted image 20250515232818.png]]

![[Pasted image 20250515232837.png]]

![[Pasted image 20250515232904.png]]

![[Pasted image 20250515232918.png]]

---

## Switching Fabric

![[Pasted image 20250515232938.png]]

![[Pasted image 20250515232947.png]]

### Memory

![[Pasted image 20250515232957.png]]

### Bus

![[Pasted image 20250515233006.png]]

### Interconnection

![[Pasted image 20250515233021.png]]

## Port Queueing

### Input Port Queueing

![[Pasted image 20250515233042.png]]

### Output Port Queueing

![[Pasted image 20250515233057.png]]

![[Pasted image 20250515233113.png]]

## Buffer Management

![[Pasted image 20250515233122.png]]

![[Pasted image 20250515233139.png]]

---

## IP Datagram Format

![[Pasted image 20250515233245.png]]

![[Pasted image 20250515233253.png]]

![[Pasted image 20250515233301.png]]

![[Pasted image 20250515233314.png]]

---

# IPv4

## Subnet

![[Pasted image 20250515233421.png]]

![[Pasted image 20250515233440.png]]

![[Pasted image 20250515233451.png]]

## CIDR

![[Pasted image 20250515233501.png]]

![[Pasted image 20250515233514.png]]

> [!Question] IP
> ![[Pasted image 20250515233712.png]]

> [!Question] Find Class of Each address
> ![[Pasted image 20250515233747.png]]

## Classful

![[Pasted image 20250515233608.png]]

![[Pasted image 20250515233627.png]]

### Why not Classless?

![[Pasted image 20250515233534.png]]

## Prefix lengths

![[Pasted image 20250515233812.png]]
