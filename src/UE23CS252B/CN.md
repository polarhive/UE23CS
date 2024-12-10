# UE23CS252B: Computer Networks

> This is a foundation course on Computer Networking which focuses on building blocks of the Internet. We trace the journey of messages sent over the Internet from an application residing on one host machine (source) to another (Destination) using a top-down layered approach. The course contents are organized based on TCP/IP Protocol stack.

## Course Objectives

- To present a broad overview of computer networking, the Internet and network layered architecture.
- To study the conceptual and implementation aspects of network applications, protocols and socket programming.
- To provide an insight of the Internet's connection–oriented and connectionless end–to–end transport service protocols and TCP’s approach to congestion control, to learn exactly how the network layer can provide its host–to–host communication service.
- To study the IPv4 and IPv6 protocols, to explore several important link–layer concepts and technologies, LAN and Wireless LANs.

## Course Outcomes

- Demonstrate in a concise way how the Internet is constructed and functions with respect to TCP/IP or OSI reference models.
- Demonstrate application layer protocols like DNS, HTTP, HTTPS and be able to develop simple client–server applications using socket programming and understand the concept of unreliable data transfer protocols and how UDP implement these concepts.
- Understand the concept of reliable data transfer protocols and how TCP implement these concepts. Implement logical addressing schemes and configure devices using NAT.
- Demonstrate the ability to configure the routers and services such as DHCP, ICMP. Construct and troubleshoot a wired or wireless LAN, and be able to understand wider networking issues.

# Course Content

> **U1**: [[U1_Application_Layer|Computer Networks and the Internet, Application Layer]]

Introduction to Computer Networks, Internet: A Nuts–and–Bolts Description, A Services Description, Protocol, The Network Edge: Access Networks, Physical Media, Introduction to physical layer devices, The Network Core, Packet Switching, Circuit Switching, A Network of Networks, Delay, Loss, and Throughput in Packet–Switched Networks, Overview of Delay in Packet Switched Networks – Queuing Delay and Packet Loss, End–to–End Delay, Throughput in Computer Networks, The OSI Model and the TCP/IP Protocol Suite, Protocol Layers, The OSI Model, TCP/IP Protocol Suite. Network Application Principles: Network Application Architectures, Processes Communication, Transport Services available to Applications, Transport Services provided by Internet.

> **U2**: [[U2_UDP|Application Layer, Transport Layer – UDP]]

The Web, HTTP and HTTPS, Non persistent and persistent connection, HTTP Message Format, User Server Interaction: Cookies, Web Caching. DNS, The Internet’s Directory Service: Services provided by DNS; How DNS works: DNS Records and messages; Peer to peer Applications; Socket Programming with TCP and UDP; Other Application Layer Protocols: FTP, SMTP, SNMP, Telnet, SSH. Introduction to Transport Layer Services: Relationship Between Transport and Network Layer, Overview of the Transport layer in the Internet, Multiplexing and Demultiplexing; Connectionless Transport UDP: UDP Segment Structure, UDP Checksum.

>**U3**: [[U3_TCP|Transport Layer – TCP, Network Layer and Internet Protocol]]

Principles of Reliable Data Transfer: Building a Reliable Data Transfer Protocol, Pipelined Reliable Data Transfer Protocol, Go–Back–N Protocol, Selective–Repeat; Connection Oriented Transport TCP: The TCP Connection, TCP Segment Structure, Flow Control, TCP Connection Management, TCP Congestion Control. Numerical on TCP congestion control mechanisms–TCP Tahoe, Reno. Overview of Network Layer: Forwarding and routing, what’s Inside a Router? The Internet Protocol (IP) IPV4: Datagram Format, Fragmentation, Addressing, NAT.

> **U4**: [[U4_Network_Layer|Network Layer and Internet Protocol, Link Layer and LAN]]

Introduction to Network layer Protocols: DHCP, ICMP; IPv6 Protocol: Packet Format, Transition from IPv4 to IPv6; Introduction to Routing Algorithms: Link State: Dijkstra’s algorithm and Distance Vector: Bellman–Ford Algorithm. Link layer – Error–Detection and Correction techniques, Parity checks, Internet Checksum, Cyclic Redundancy Check, and Multiple Access Protocols: CSMA/CD, CSMA/CA; Switched LAN: Link layer addressing and ARP, Ethernet: Link–layer switches. Retrospective: A Day in the Life of a Web Page Request. Physical Layer – Purpose, Signals to Packets, Transmission media. Wireless LANs: IEEE 802.11 LAN architecture, 802.11 MAC Protocol, IEEE 802.11 Frame.

---

prerequisites: [[Python|UE23CS151A]]