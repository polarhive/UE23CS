# DHCP

Host dynamically obtains IP address from network server when it “joins” network

- can renew its lease on address in use
- allows reuse of addresses (only hold address while connected/on)
- support for mobile users who join/leave network

## DHCP overview

- host broadcasts DHCP discover msg (optional)
- DHCP server responds with DHCP offer msg (optional)
- host requests IP address: DHCP request msg
- DHCP server sends address: DHCP ack msg

## Discovery

![[Pasted image 20250515234443.png]]

![[Pasted image 20250515234505.png]]

![[Pasted image 20250515234517.png]]

![[Pasted image 20250515234534.png]]

# NAT

![[Pasted image 20250515234609.png]]

![[Pasted image 20250515234626.png]]

![[Pasted image 20250515234633.png]]

![[Pasted image 20250515234643.png]]

![[Pasted image 20250515234654.png]]

# ICMP

![[Pasted image 20250515234740.png]]

![[Pasted image 20250515234750.png]]

---

# IPv4

## IP Datagram Format

![[Pasted image 20250515233245.png]]

![[Pasted image 20250515233253.png]]

![[Pasted image 20250515233301.png]]

![[Pasted image 20250515233314.png]]

---

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

---

# IPv6

![[Pasted image 20250515234943.png]]

![[Pasted image 20250515234810.png]]

## Address Types

![[Pasted image 20250515234909.png]]

### Address Space

![[Pasted image 20250515234930.png]]

### Datagram

![[Pasted image 20250515234959.png]]

## Transition IPv4/6

![[Pasted image 20250515235145.png]]

### Tunneling

![[Pasted image 20250515235158.png]]

![[Pasted image 20250515235211.png]]

# Routing Protocols

![[Pasted image 20250515235229.png]]

![[Pasted image 20250515235238.png]]

## Graph Abstraction

![[Pasted image 20250515235252.png]]

## Classification

![[Pasted image 20250515235305.png]]

## Dijkstra's

![[Pasted image 20250515235317.png]]

![[Pasted image 20250515235427.png]]

![[Pasted image 20250515235438.png]]

![[Pasted image 20250515235447.png]]

![[Pasted image 20250515235452.png]]

## Bellman-Ford

![[Pasted image 20250515235509.png]]

![[Pasted image 20250515235518.png]]

![[Pasted image 20250515235523.png]]

![[Pasted image 20250515235528.png]]

### Timing

![[Pasted image 20250515235543.png]]

![[Pasted image 20250515235600.png]]

![[Pasted image 20250515235605.png]]

![[Pasted image 20250515235612.png]]

![[Pasted image 20250515235616.png]]

![[Pasted image 20250515235620.png]]

![[Pasted image 20250515235626.png]]

### Computation

![[Pasted image 20250515235638.png]]

![[Pasted image 20250515235650.png]]

![[Pasted image 20250515235658.png]]

![[Pasted image 20250515235705.png]]

![[Pasted image 20250515235710.png]]

### State information Diffusion

![[Pasted image 20250515235730.png]]

### Link Cost Changes

![[Pasted image 20250515235742.png]]

![[Pasted image 20250515235758.png]]

## Differences

![[Pasted image 20250515235808.png]]

![[Pasted image 20250515235823.png]]

---

# Link Layer

![[Pasted image 20250515235848.png]]

![[Pasted image 20250515235853.png]]

![[Pasted image 20250515235902.png]]

## Error Detection

![[Pasted image 20250515235910.png]]

### 2D Parity

![[Pasted image 20250515235929.png]]

### Parity Checking

![[Pasted image 20250515235919.png]]

### Internet Checksum

![[Pasted image 20250515235937.png]]

### CRC

![[Pasted image 20250516000001.png]]

#### Generator

![[Pasted image 20250516000113.png]]

![[Pasted image 20250516000122.png]]

![[Pasted image 20250516000132.png]]

![[Pasted image 20250516000143.png]]

---

![[Pasted image 20250516000202.png]]

#### Sender

![[Pasted image 20250516000047.png]]

#### Receiver

![[Pasted image 20250516000059.png]]

## Types of Links

![[Pasted image 20250516000237.png]]

## MAP

![[Pasted image 20250516000249.png]]

![[Pasted image 20250516000300.png]]

## MAC Protocols

![[Pasted image 20250516000317.png]]

## CSMA

![[Pasted image 20250516000334.png]]

![[Pasted image 20250516000345.png]]

### Ethernet CSMA/CD

![[Pasted image 20250516000355.png]]

![[Pasted image 20250516000411.png]]

---

## MAC Addresses

![[Pasted image 20250516000430.png]]

![[Pasted image 20250516000446.png]]

## ARP

### How to MAC?

![[Pasted image 20250516000513.png]]

![[Pasted image 20250516000523.png]]

![[Pasted image 20250516000531.png]]

![[Pasted image 20250516000538.png]]

### Diff Subnet?

![[Pasted image 20250516000600.png]]

![[Pasted image 20250516000608.png]]

![[Pasted image 20250516000612.png]]

![[Pasted image 20250516000620.png]]

![[Pasted image 20250516000632.png]]

![[Pasted image 20250516000641.png]]

## Ethernet

### Structure

![[Pasted image 20250516000723.png]]

### Address

![[Pasted image 20250516000749.png]]

![[Pasted image 20250516000758.png]]

## Switch

![[Pasted image 20250516000831.png]]

### Multi Transmission

![[Pasted image 20250516000900.png]]

![[Pasted image 20250516000912.png]]

### Forwarding Table

![[Pasted image 20250516000930.png]]

### Filtering

![[Pasted image 20250516001028.png]]

### Forwarding

![[Pasted image 20250516001054.png]]

### Self Learning

![[Pasted image 20250516000946.png]]

![[Pasted image 20250516001117.png]]
---

# Day in the Life of Web Request

![[Pasted image 20250516001143.png]]

![[Pasted image 20250516001155.png]]

![[Pasted image 20250516001205.png]]

![[Pasted image 20250516001213.png]]

![[Pasted image 20250516001218.png]]

![[Pasted image 20250516001222.png]]

# Physical Layer

![[Pasted image 20250516001233.png]]

![[Pasted image 20250516001246.png]]

## Signalling Methods

![[Pasted image 20250516001301.png]]

## Encoding

![[Pasted image 20250516001310.png]]

## Wireless

![[Pasted image 20250516001332.png]]

### Ad-hoc

![[Pasted image 20250516001345.png]]

### Taxonomy

![[Pasted image 20250516001356.png]]

### Base Station

![[Pasted image 20250516001427.png]]

---

### WiFi

![[Pasted image 20250516001407.png]]

#### Channels, Association

![[Pasted image 20250516001444.png]]

#### Active/Passive Scanning

![[Pasted image 20250516001526.png]]

## CSMA/CA

![[Pasted image 20250516001635.png]]

### Avoid Collision

![[Pasted image 20250516001749.png]]

### RTS/CTS

![[Pasted image 20250516001804.png]]

## Multi-Access

![[Pasted image 20250516001544.png]]

---

## Frame Addressing

![[Pasted image 20250516001835.png]]

![[Pasted image 20250516001845.png]]

![[Pasted image 20250516001848.png]]

# Mobility Within Subnet

![[Pasted image 20250516001904.png]]
