# Internet Applications, UDP

- Data integrity: checksums, web transactions
- Throughput: minimum throughput to remain active
- Security: SSL, TLS
- Timing: QoS and low latency

# HTTP

- A web page consists of objects, each of which can be stored on servers
- Objects can be: HTML, JPG, Audio, etc
- A client, browser displays web objects
- A server, sends objects in response to requests

## Persistent HTTP (HTTP 1.1)

![[Pasted image 20250220014046.png]]

- server leaves connection open after sending response
- subsequent HTTP messages between same client/server sent over open connection
- client sends requests as soon as it encounters a referenced object
- as little as one RTT for all the referenced objects (cutting response time in half)

### Packet Graphs (Comparison)

![[Pasted image 20250220014145.png]]

---

### HTTP states

- HTTP is stateless, uses TCP: no info from past requests
	- Client initiates TCP connection: port `80`
	- Server accepts TCP connection and application layer protocol messages are exhcnaged between the browser and the server.
	- TCP connection is closed

| Non-Persistent HTTP     | Persistent HTTP       |
| ----------------------- | --------------------- |
| TCP conn open           | TCP conn opened       |
| At most one object sent | Multiple objects sent |
| TCP conn closed         | TCP conn closed       |

### Packet Graph

![[Pasted image 20250220013710.png]]

![[Pasted image 20250220013733.png]]

### RTT

> Time for a small packet to travel from client to server and back.

- 1 RTT to initiate
- 1 RTT for HTTP req and bytes to return
- Object transmission time
![[Pasted image 20250220013925.png]]

## HTTP [[WT|methods]]

- POST
- HEAD
- PUT
- GET

## HTTPS

- Uses port `443`
- Based on public key cryptography
- SSL usually issued by a 3rd party CA

## SSL

![[Pasted image 20250220014532.png]]

- Step 1: Browser requests secure pages (HTTPS) from a server.
- Step 2: Server sends its public key with its SSL certificate (digitally signed by a third party – CA).
- Step 3: On receipt of certificate, browser verifies issuer’s digital signature. (green padlock key)
- Step 4: Browser creates a symmetric key (shared key), keeps one and gives a copy to server. Encrypts it using server’s public key.
- Step 5: On receipt of encrypted secret key, decrypts it using its private key and gets browser’s secret key

> [!Tip]
> - Asymmetric and Symmetric key algorithms work together.
> - Asymmetric key algorithm verify identity of the owner & its public key -> Establish trust.
> - Once connection is established, Symmetric key algorithm is used to encrypt and decrypt the traffic.

---

## Cookies

> Cookies carry state, HTTP is stateless on its own!

### Components

1. Cookie header line of response message
2. Header line in next HTTP req message
3. Cookie file kept on user's host managed by the browser
4. Backend db at website

The initial HTTP req creates a unique cookie, and entry for this ID against the db. Subsequent req will allow to identify via this cookie.

---

## Web Caches

To serve requests without involving an origin server.

Browser sends all HTTP req to the the cache. If object in cache, cache returns object to client, else cache req from origin and saves, serves to client. It acts as both client and server in this case.

### Caching Example

![[Pasted image 20250220015016.png]]

![[Pasted image 20250220015026.png]]

![[Pasted image 20250220015035.png]]

![[Pasted image 20250220015046.png]]

### Conditional Get

Don't send if cache has an upto-date cached version.

> TIL: `if-modified-since: date`
> Server contains no object 304 not modified.

---

# DNS

Distributed database implemented in hierarchy of many name servers. Resolves names, address/name translation. Implemented as an application layer protocol.

> A distributed database storing resource records (RR)

![[Pasted image 20250220015335.png]]

- DNS is organized according to zones.
	- A zone groups contiguous domains and subdomains on the domain tree.
- Assign management authority to an entity.
- The tree structure depicts subdomains within example.com domain.
- Multiple DNS zones one for each country. The zone keeps records of who the authority is for each of its subdomains.
- The zone for example.com contains only the DNS records for the hostnames that do not belong to any subdomain like `mail.example.com`

## Inserting records

> [!Example]
> Record Format: `(name, value, type, ttl)`

> Example: new startup “Network Utopia”

- Register name: `networkuptopia.com` at DNS registrar (e.g., Network Solutions)
-  provide names, IP addresses of authoritative name server (primary and secondary)
- registrar inserts NS, A RRs into .com TLD server: (`networkutopia.com`, `dns1.networkutopia.com`, `NS`), (`dns1.networkutopia.com`, `212.212.212.1`, `A`)
- Create authoritative server locally with IP address: `212.212.212.1`
- type A record for `www.networkuptopia.com`
- type MX record for `networkutopia.com`

## Root name servers

- official, contact-of-last-resort by name servers that can not resolve name
- DNSSEC – provides security (authentication and message integrity)
- ICANN (Internet Corporation for Assigned Names and Numbers) manages root DNS domain

## Authoritative DNS servers

- organization’s own DNS server(s), providing authoritative hostname to IP mappings for organization’s named hosts
- can be maintained by organization or service provider

## Local DNS Name Servers

- does not strictly belong to hierarchy
- each ISP (residential ISP, company, university) has one
- also called “default name server”
- when host makes DNS query, query is sent to its local DNS server
- has local cache of recent name-to-address translation pairs (but may be out of date!)
- acts as proxy, forwards query into hierarchy

## Caching and Updating DNS

Once (any) name server learns mapping, it caches mapping

- cache entries timeout (disappear) after some time (TTL)
- TLD servers typically cached in local name servers
- thus root name servers not often visited

## DNS protocol messages

DNS query and reply messages, both have same format.

![[Pasted image 20250220015915.png]]

![[Pasted image 20250220015930.png]]

---

# P2P architecture

> no always-on server

- arbitrary end systems directly communicate
- peers request service from other peers, provide service in return to other peers
- self scalability – new peers bring new service capacity, and new service demands
- peers are intermittently connected and change IP addresses (complex management)

---

## Bittorrent

### Requesting chunks

- at any given time, different peers have different subsets of file chunks
- periodically, Alice asks each peer for list of chunks that they have
- Alice requests missing chunks from peers, rarest first

### Sending chunks: tit-for-tat

- Alice sends chunks to those four peers currently sending her chunks at highest rate
- other peers are choked by Alice (do not receive chunks from her)
- re-evaluate top 4 every 10 secs
- every 30 secs: randomly select another peer, starts sending chunks
- “optimistically unchoke” this peer
- newly chosen peer may join top 4

---

## Problems

![[Pasted image 20250220020159.png]]

![[Pasted image 20250220020216.png]]

![[Pasted image 20250220020227.png]]

![[Pasted image 20250220020242.png]]

![[Pasted image 20250220020251.png]]

![[Pasted image 20250220020303.png]]

---

# Socket Programing

> socket: door between application process and end-end-transport protocol

Two socket types for two transport services:

- UDP: unreliable datagram
- TCP: reliable, byte stream-oriented

## Application Example

> client reads a line of characters (data) from its keyboard and sends data to server

1. server receives the data and converts characters to uppercase
2. server sends modified data to client
3. client receives modified data and displays line on its screen

## Socket programming with TCP

### Client

- server process must first be running
- server must have created socket (door) that welcomes client’s contact

### Server

- Creating TCP socket, specifying IP address, port number of server process
- when client creates socket: client TCP establishes connection to server TCP
- when contacted by client, server TCP creates new socket for server process to communicate with that particular client
- allows server to talk with multiple clients
- source port numbers used to distinguish clients

![[Pasted image 20250220020940.png]]

![[Pasted image 20250220020952.png]]

![[Pasted image 20250220020959.png]]

![[Pasted image 20250220021008.png]]

---

## Socket Programming with UDP

> no "connection" between client & server

- no handshaking before sending data
- sender explicitly attaches IP destination address and port # to each packet
- receiver extracts sender IP address and `port#` from received packet
- UDP: transmitted data may be lost or received out-of-order
-  UDP provides unreliable transfer of groups of bytes ("datagrams") between client and server

### Server

![[Pasted image 20250220020750.png]]

### Client

![[Pasted image 20250220020809.png]]

![[Pasted image 20250220020801.png]]

# FTP

- Exchange files over TCP, allows Delete, Rename, Move and Copy file at a server
- Runs over port `20`
- Control port `21`

# SMTP

- Secured using SSL
- Messages are stored and then forwarded to the destination (relay)
- SMTP uses the port: `25` (TCP)

# DHCP

- Assign IP, using DHCP leases
- Port number: `67` for server
- client: `68`
- Includes subnet mask, DNS server and default gateway

# SNMP

> Exchanges management information between network devices

- SNMP manager
- Managed Devices
- SNMP Agents
- MIB (Management Information Base)

![[Pasted image 20250220022206.png]]

## SSH, Telnet

- Allows remote control, used to remotely access and manage devices
- Telnet: `23`: client / server
- SSH: `22` uses public key encryption

## Table of Ports

| #         | Protocol | Description                                                |
| --------- | -------- | ---------------------------------------------------------- |
| 20        | FTP      | File Transfer Protocol - Data                              |
| 21        | FTP      | File Transfer Protocol - Control                           |
| 22        | SSH      | Secure Shell for secure login                              |
| 23        | Telnet   | Unencrypted login                                          |
| 25        | SMTP     | Simple Mail Transfer Protocol (Sending Email)              |
| 53        | DNS      | Domain Name System (Name Resolution)                       |
| 67/68     | DHCP     | Dynamic Host Configuration Protocol (Assigning IPs)        |
| 69        | TFTP     | Trivial File Transfer Protocol (Simple File Transfer)      |
| 80        | HTTP     | HyperText Transfer Protocol (Web Browsing)                 |
| 110       | POP3     | Post Office Protocol v3 (Retrieving Email)                 |
| 123       | NTP      | Network Time Protocol (Time Sync)                          |
| 143       | IMAP     | Internet Message Access Protocol (Email Retrieval)         |
| 161/162   | SNMP     | Simple Network Management Protocol (Monitoring)            |
| 389       | LDAP     | Lightweight Directory Access Protocol (Directory Services) |
| 443       | HTTPS    | Secure HTTP with SSL/TLS                                   |
| 465       | SMTPS    | SMTP Secure over SSL                                       |
| 514       | Syslog   | System Logging                                             |
| 520       | RIP      | Routing Information Protocol                               |
| 546/547   | DHCPv6   | IPv6 Version of DHCP                                       |
| 563       | NNTP SSL | Network News Transfer Protocol Secure                      |
| 587       | SMTP     | Message Submission                                         |
| 636       | LDAPS    | Secure LDAP                                                |
| 989/990   | FTPS     | FTP Secure over SSL/TLS                                    |
| 993       | IMAPS    | IMAP Secure over SSL                                       |
| 995       | POP3S    | POP3 Secure over SSL                                       |

![[Pasted image 20250220022316.png]]

---

# Transport Services and Protocols

> Provides a logical communication between application processes running on different hosts.

 - Sender: breaks application messages into segments, passes to network layer
 - Receiver: reassembles segments into messages, passes to application layer

![[Pasted image 20250220030027.png]]

- Network layer: logical communication between **hosts**.
- Transport layer: logical communication between processes, relies on, enhances network layer services.

# Transport Layer Actions

![[Pasted image 20250220022649.png]]

![[Pasted image 20250220022710.png]]

# Multiplexing

At sender: handle data from multiple sockets, add transport header (used later for demultiplexing)

At receiver: use header info to deliver received segments to correct sockets

![[Pasted image 20250220022848.png]]

## Demultiplexing

![[Pasted image 20250220022910.png]]

## Connectionless demultiplexing

- When creating a socket, must specify a  host-local port no.
- When creating a datagram to send into UDP socket, must specify
	- Dest IP
	- Dest Port no
- When receiving host receives UDP segment
	- checks dest port no in segment
	- directs UDP segment to socket with that port no

> IP/UDP datagrams with same destination, port no but different src IP will be directed to same socket at receiving host.

![[Pasted image 20250220023144.png]]

![[Pasted image 20250220023154.png]]

![[Pasted image 20250220023215.png]]

## Summary

- Multiplexing, demultiplexing: based on segment, datagram header field values
- UDP: demultiplexing using destination port number (only)
- TCP: demultiplexing using 4-tuple: source and destination IP and port no
- Multiplexing / demultiplexing happens at all layers

# UDP: Overview

> *"Best effort" service, UDP segments may be: lost or delivered out-of-order to app*
> `RFC: 768`

- Connectionless
	- No handshaking between UDP sender, receiver
	- Each UDP segment handles independently of other
- No RTT delay.
- No connection state at sender/receiver (buffer, seq, ack, c-c parameters)
- Small header size (8 v/s 20 bytes)
- no congestion control

![[Pasted image 20250220023627.png]]

If reliability needed, use: `HTTP/3` at application layer

# UDP actions

![[Pasted image 20250220023653.png]]

![[Pasted image 20250220023659.png]]

## UDP segment header

![[Pasted image 20250220023714.png]]

# UDP Checksum

> Goal: detect “errors” (e.g., flipped bits) in transmitted segment

Example:

![[Pasted image 20250220023744.png]]

![[Pasted image 20250220023752.png]]

## Example

![[Pasted image 20250220023805.png]]

> Wraparound!

![[Pasted image 20250220023819.png]]

![[Pasted image 20250220023831.png]]
