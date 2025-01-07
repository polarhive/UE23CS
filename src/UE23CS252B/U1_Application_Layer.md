# Application Layer

> *The idea of networking is to transfer arbitrary data between two or more computers over the internet/LAN.*

The 7 layers according to the OSI model:

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

## "The Internet"

> A Nuts and Bolts View

- Host: Named end-systems running apps at the internet's edge
- Packet Switching: Forwards packets over routers and switches
- Communication lines: Media. i.e. Radio, LTE, Fiber
- Internet: A network of networks via interconnected ISPs
- Protocols: control the sending and receiving of messages.
- Internet Standards: RFCs, IETF
- Infra: provides services to applications, web streaming, email, gaming

## What's a protocol?

> [!Important]
> Protocols define the format, order, of messages Tx and Rx among network entities, and actions taken on message transmission, receipt.

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

## Hosts: Send pkts of data

- Takes application message
- Breaks into smaller chunks, known as **packets**, of length **L** bits
- Transmits packet into access network at transmission rate **R**
- Link transmission rate, aka **link capacity**, aka link **bandwidth**

> [!Important]
> Packet Transmission Delay is:
> The time needed to transmit an L-bit packet into link = $\frac{L \, \text{(bits)}}{R \, \text{(bits/s)}}$

### DSL

![[Pasted image 20250109215403.png]]

- It uses existing telephone line to central office DSLAM
	- data over DSL phone line goes to Internet
	- voice over DSL phone line goes to telephone net

> [!info]
> - A high-speed downstream channel, in the 50 kHz to 1 MHz band
> - A medium-speed upstream channel, in the 4 kHz to 50 kHz band
> - An ordinary two-way telephone channel, in the 0 to 4 kHz band
> - 24-52 Mbps – DL transmission rate
> - 3.5-16 Mbps – UL transmission rate
> - Asymmetric access

### Wired Cable

![[Pasted image 20250109215349.png]]

Frequency division multiplexing (FDM): different channels transmitted in different frequency bands.

> [!Info]
> - HFC: hybrid fiber coax
> - Asymmetric: up to 40 Mbps – 1.2 Gbs downstream transmission rate, 30-100 Mbps upstream transmission rate
> - Network of cable, fiber attaches homes to ISP router
> - homes share access network to cable headend.

### Home Networks

![[Pasted image 20250109215557.png]]

### Enterprise Networks

![[Pasted image 20250109215607.png]]

Deployed at companies, universities, etc.

> [!Note]
>
> - Mix of wired, wireless link technologies, connecting a mix of switches and routers (we’ll cover differences shortly)
> - Ethernet: wired access at 100Mbps, 1Gbps, 10Gbps
> - WiFi: wireless access points at 11, 54, 450 Mbps

### Wireless Networks

Shared wireless access network connects end system to router via base station aka “access point”.

- Wireless local area networks (WLANs)
	- Typically within or around building (~100ft)
	- 802.11b/g/n (WiFi): 11, 54, 450 Mbps transmission rate to Internet
- Wide-area cellular access networks: provided by mobile, cellular network operator (10’s km).
	- Throughput ~10 Mbps
	- 4G cellular networks (5G coming)

## Physical Media

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