# The Internet: A Nuts and Bolts View

> *The idea of networking is to transfer arbitrary data between two or more computers over the internet/LAN.

- **Host**: Named end-systems running apps at the internet's edge
- **Packet Switching**: Forwards packets over routers and switches
- **Communication lines**: Media. i.e. Radio, LTE, Fiber
- **Internet**: A network of networks via interconnected ISPs
- **Protocols**: control the sending and receiving of messages.
- **Internet Standards**: RFCs, IETF
- **Infra**: provides services to applications, web streaming, email, gaming

> [!Important]
> Protocols define the format, order, of messages Tx and Rx among network entities, and actions taken on message transmission, receipt.

---

# OSI model

| #   | Layer        | Ex           |
| --- | ------------ | ------------ |
| 7   | Application  | HTTP         |
| 6   | Presentation | SSL/TLS      |
| 5   | Session      | Sockets, TCP |
| 4   | Transport    | TCP, UDP     |
| 3   | Network      | IPv{4,6}     |
| 2   | Data link    | Ethernet     |
| 1   | Physical     | DSL          |

---

# Network Edge

- **Hosts**: clients, servers
	- Servers in data centers
- **Access networks**, physical media
	- wired and wireless network links
- **Network Core**:
	- interconnected routers
	- network of networks

---

## DSL

![[Pasted image 20250109215403.png]]

- Uses existing telephone line to central office DSLAM
	- data over DSL phone line goes to Internet
	- voice over DSL phone line goes to telephone net

> [!info]
> - A high-speed downstream channel, in the 50 kHz to 1 MHz band
> - A medium-speed upstream channel, in the 4 kHz to 50 kHz band
> - An ordinary two-way telephone channel, in the 0 to 4 kHz band
> - 24-52 Mbps – DL transmission rate
> - 3.5-16 Mbps – UL transmission rate
> - Asymmetric access

## Wired Cable

![[Pasted image 20250109215349.png]]

Frequency division multiplexing (FDM): different channels transmitted in different frequency bands.

> [!Info]
> - HFC: hybrid fiber coax
> - Asymmetric: up to 40 Mbps – 1.2 Gbs downstream transmission rate, 30-100 Mbps upstream transmission rate
> - Network of cable, fiber attaches homes to ISP router
> - homes share access network to cable headend.

## Home Networks

![[Pasted image 20250109215557.png]]

## Enterprise Networks

![[Pasted image 20250109215607.png]]

Deployed at companies, universities, etc.

> [!Note]
>
> - Mix of wired, wireless link technologies, connecting a mix of switches and routers (we’ll cover differences shortly)
> - Ethernet: wired access at 100Mbps, 1Gbps, 10Gbps
> - WiFi: wireless access points at 11, 54, 450 Mbps

## Wireless Networks

Shared wireless access network connects end system to router via base station aka “access point”.

- Wireless local area networks (WLANs)
	- Typically within or around building (~100ft)
	- 802.11b/g/n (WiFi): 11, 54, 450 Mbps transmission rate to Internet
- Wide-area cellular access networks: provided by mobile, cellular network operator (10’s km).
	- Throughput ~10 Mbps
	- 4G cellular networks (5G coming)

# Physical Media

- bit: propagates between transmitter/receiver pairs
- physical link: what lies between transmitter & receiver
- guided media: signals propagate in solid media > copper, fiber, coax
- unguided media: signals propagate freely > radio
- Twisted pair (TP)
	- two insulated copper wires (STP & UTP)
	- Category 5: 100 Mbps, 1 Gbps Ethernet
	- Category 6: 10Gbps Ethernet
- Coaxial cable:
	- two concentric copper conductors
	- concentric rather than parallel
	- bidirectional
	- broadband:
		- multiple frequency channels oncable
		- 100’s Mbps per channel
- Fiber optic cable:
	- glass fiber carrying light pulses, each pulse a bit
	- high-speed point-to-point transmission (10’s-100’s Gbps)
	- low error rate:
		- repeaters spaced far apart
		- immune to electromagnetic noise
- Wireless radio:
	- signal carried in electromagnetic spectrum
	- no physical “wire”
	- broadcast and “half-duplex” (sender to receiver)
	- propagation environment effects:
		- reflection
		- obstruction by objects
		- interference
- Radio link types:
	- terrestrial microwave: up to 45 Mbps channels
	- Wireless LAN (WiFi): Up to 100’s Mbps
	- wide-area (e.g., cellular): 4G cellular: ~ 10’s Mbps
	- satellite:
		- up to 45 Mbps per channel
		- 280 msec end-end delay
		- geosynchronous vs. low-earth-orbit

---

# Circuit Switching

End-end resources allocated to, reserved for “call” between source and destination (eg: telephone)

- dedicated resources: no sharing
- circuit-like (guaranteed) performance
- circuit segment idle if not used by call (no sharing)
- commonly used in traditional telephone networks

---

# Packet Switching

- Hosts send pkts of data
- Takes application message
- Breaks into smaller chunks, known as **packets**, of length **L** bits
- Transmits packet into access network at transmission rate **R**
- Link transmission rate, aka **link capacity**, aka link **bandwidth**

> [!Important]
> Packet Transmission Delay is:
> The time needed to transmit an L-bit packet into link = $\frac{L \, \text{(bits)}}{R \, \text{(bits/s)}}$

> Great for “bursty” data – sometimes has data to send, but at other times not

- resource sharing
- simpler, no call setup
- excessive congestion possible: packet delay and loss due to buffer overflow
- protocols needed for reliable data transfer, congestion control
- Q: How to provide circuit-like behavior?
- bandwidth guarantees traditionally used for audio/video applications

---

## Example Problem

How long does it take to send a file of 640,000 bits (1 byte = 8 bits) from host A to host B over a circuit-switched network?

- All links are 1.536 Mbps
-  Each link uses TDM with 24 slots/sec
-  500 msec to establish end-to-end circuit

> Solution:

- Each circuit has a transmission rate of (1.536 Mbps)/24 = 64 kbps
- It takes (640,000 bits)/(64 kbps) = 10 seconds to transmit the file
- To this 10 seconds we add the circuit establishment time, giving 10.5 seconds to send the file

---

# Store & Forward

- Transmission delay: takes L/R seconds to transmit (push out) L-bit packet into link at R bps.
- Store and forward: entire packet must arrive at router before it can be transmitted on next link.
- End-end delay: 2L/R (above), assuming zero propagation delay (more on delay shortly)

> One-hop numerical example:

-  L = 10 Kbits
-  R = 100 Mbps

Therefore, one-hop transmission delay = 0.1 msec

# Queuing delay, loss

![[Pasted image 20250110002058.png]]

> If arrival rate (in bps) to link exceeds transmission rate (bps) of link for a period of time:

- packets will queue, waiting to be transmitted on output link
- packets can be dropped (lost) if memory (buffer) in router fills up

# Routing & Forwarding

- Forwarding: local action: move arriving packets from router’s input link to appropriate router output link
- Routing: global action: determine source-destination paths taken by packets

![[Pasted image 20250110002257.png]]

# Multiplexing in Circuit Switched Networks

## Frequency Division Multiplexing

- optical, electromagnetic frequencies divided into (narrow) frequency bands
- each call allocated its own band, can transmit at max rate of that narrow band

 ![[Pasted image 20250110002944.png]]

## Time Division Multiplexing

- time divided into frames -> slots
- each call allocated periodic slot(s), can transmit at maximum rate of (wider) frequency band, but only during its time slot(s)

![[Pasted image 20250110003009.png]]

---

## Internet Structure: "network of networks"

> End systems connect to Internet via access ISPs (Internet Service Providers)

- Residential, company and university ISPs
- Access ISPs in turn must be interconnected.
- So that any two hosts can send packets to each other
- Resulting network of networks is very complex
- Evolution was driven by economics and national policies

> [!Question] Given millions of access ISPs, how to connect them together?
> Connecting each access ISP to each other directly doesn’t scale: $O(N^2)$ connections.

## Tiered ISP

![[Pasted image 20250114172315.png]]

## CDNs

> The content provider networks (e.g., Google, Facebook): are private network that connects its data centers to Internet, often bypassing tier-1, regional ISPs

---

# Packet Delay

> Performance Metric: Packet Delay – 4 Sources

![[Pasted image 20250114172441.png]]

> dnodal = d proc + queue + trans + prop

- dproc: nodal processing
	-  check bit errors
	- determine output link
	- typically < 1 msec
- dqueue: queueing delay
	- time waiting at output link for transmission
	- depends on congestion level of router
	- microseconds to milliseconds
- dtrans: transmission delay = L/R
	- L: packet length (bits)
	- R: link transmission rate (bps)
- dprop: propagation delay = d/s
	- d: length of physical link
	- s: propagation speed (~2x108 m/sec)

| Transmission Delay                                            | Propagation Delay                                           |
| ------------------------------------------------------------- | ----------------------------------------------------------- |
| Time required for the router to push out the packet           | Time it takes a bit to propagate from one router to another |
| A function of packet length and transmission rate of the link | A function of distance                                      |
| L/R                                                           | d/s                                                         |
| Nothing to do with the distance between the routers           | Nothing to do with packet length or transmission rate       |

---

# Packet Queueing Delay

- R: link bandwidth (bps)
- L: packet length (bits)
	- a: average packet arrival rate (pps)
- La: avg. rate at which bits arrive at the queue
- La/R > 1: more “work” arriving is more than can be serviced - average delay infinite!
- La/R <= 1: nature of arriving traffic
- La/R ~ 0: avg. queueing delay small

![[Pasted image 20250116134749.png]]

## traceroute

> Delay measurement from source to router along end-end Internet path towards destination.

- for all i:
- sends three packets that will reach router i on path towards destination (with time-to-live field value of i)
- router i will return packets to sender
- sender measures time interval between transmission and

![[Pasted image 20250116134815.png]]

## throughput

> rate (bits/time unit) at which bits are being sent from sender to receiver

- instantaneous: rate at given point in time
- average: rate over longer period of time

![[Pasted image 20250116135042.png]]

### bottleneck

> link on end-end path that constrains end-end throughput.

![[Pasted image 20250116135107.png]]

> [!Example]
> Suppose you are downloading an MP3 file of F = 32 million bits.
> - The server has a transmission rate of Rs = 2 Mbps and you have an access link of Rc = 1 Mbps.
> - What is the time needed to transfer the file?

> [!Example] Network Scenario
>
> - per-connection end-end throughput: min(Rc,Rs,R/10)
> - in practice: Rc or Rs is often bottleneck
> - each link is now 500kbps
>
> ![[Pasted image 20250116135157.png]]

---

# Protocol Layers

> Networks are complex, with many “pieces”:

- hosts
- routers
- links of various media
- applications
- protocols
- hardware, software

# Layering

> Each layer implements a service

- via its own internal-layer actions
- relying on services provided by layer below
- explicit structure allows identification, relationship of complex system’s pieces
- layered reference model for discussion
- modularization eases maintenance, updating of system
- change in layer's service implementation: transparent to rest of system
	- e.g., change in gate procedure doesn’t affect rest of system

## Internet Protocol Stack

- **application**: supporting network applications (access to network resources)
	- IMAP, SMTP, HTTP
- **transport**: process-process data transfer (segmentation application & reassembly, sockets, connection, flow and error control)
	- TCP, UDPtransport
- **network**: routing of datagrams from source to destination (addressing, routing)
	- IP, routing protocols
- **link**: data transfer between neighboring network elements (framing, addressing, flow error control)
	- Ethernet, 802.11 (WiFi), PPP
- **physical**: bits "on the wire"

## OSI reference model

- **presentation**: allow applications to interpret meaning of data, (e.g., encryption, compression, machine-specific conventions)
- **session**: synchronization, check pointing, recovery of data exchange
