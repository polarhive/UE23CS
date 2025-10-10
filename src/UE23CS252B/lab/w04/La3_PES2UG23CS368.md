# DNS Analysis (dig) & (netcat)

**UE23CS252B: Lab_3.1**

> Name: Nathan Matthew Paul
> SRN: PES2UG23CS368
> Section: 4F

---

# `dig` tool

## 1. Observe DNS Caching

![[Screenshot from 2025-02-11 21-03-09.png]]

> We can observe, the second query is cached and the response time is faster.

 <div style="page-break-after: always;"></div>

## 2. Other Record types

IPv6: `AAAA`

![[Pasted image 20250211210638.png]]

SMTP: `MX`

![[Pasted image 20250211210722.png]]

 <div style="page-break-after: always;"></div>

## 3. Changing DNS servers

![[Pasted image 20250211210837.png]]

> We can observe Cloudflare's `1.1.1.1`  is faster than the local system DNS resolver.

 <div style="page-break-after: always;"></div>

## 4. DNS over `TCP`

![[Pasted image 20250211211541.png]]

### On comparing with `UDP`

![[Pasted image 20250211214737.png]]

> DNS over `UDP` has one `req` and one `response`

 <div style="page-break-after: always;"></div>

# `nc` tool

## 1. UDP server using netcat on port `54321`

![[Pasted image 20250211213758.png]]

## 2. Three distinct messages from a client

![[Pasted image 20250211213910.png]]

![[Pasted image 20250211214530.png]]

 <div style="page-break-after: always;"></div>

## Observations About UDP Traffic in Wireshark

- **Padding**: We can observe the UDP packets length is padded `+1` the length of the ASCII message: `hi` length is 3.
- **High Speed and Low Overhead**: UDP packets are small, with minimal headers (8 bytes), making them lightweight.
- **No Handshake or Acknowledgments**: Unlike TCP, there are no `SYN`/`ACK` flags or retransmission mechanisms.
- **DNS Queries and Responses**: In a DNS lookup, a small request packet is sent, followed by a response containing the resolved IP address.

## How does UDP differ from TCP

| Property         | UDP                    | TCP                              |
| ---------------- | ---------------------- | -------------------------------- |
| Type             | Connectionless         | Connection-oriented              |
| Reliability      | No guarantee           | Reliable delivery                |
| Speed & Overhead | Faster, lower overhead | Slower, higher overhead          |
| Order of Data    | No order guarantee     | Maintains packet order (inorder) |
| Use Cases        | Streaming, VoIP, DNS   | Browsing, Email, File transfers  |

## Why UDP is Suitable for DNS

- **Low Latency**: UDP is faster because it does not require connection setup, reducing query response times.
- **Small Data Size**: Most DNS queries and responses are small (typically under 512 bytes), fitting within a single UDP packet.
- **Efficiency**: UDP avoids establishing and maintaining connections, making it more efficient for high-volume, short-lived DNS transactions.
- **Support for Broadcast and Multicast**: UDP allows DNS services like mDNS (multicast DNS) to work effectively.

