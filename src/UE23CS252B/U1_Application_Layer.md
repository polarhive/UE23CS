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

## Network Edge

- Hosts: clients, servers
	Servers in data centers

- Access networks, physical media
	wired and wireless network links

- Network Core:
	- interconnected routers
	- network of networks