# Exploring UDP with Sockets - Wireshark

**UE23CS252B: Lab_3.2**

> Name: Nathan Matthew Paul
> SRN: PES2UG23CS368
> Section: 4F

> [!Question]
> To implement and observe a bi-directional chat application using UDP sockets.
> The goal is to understand how UDP communication works, analyze its
> characteristics using Wireshark, and explore the differences between UDP and
> TCP.

---

# Steps

## IP addr

![[ip.png]]

## Python UDP Chat Tool

![[tk.png]]

### Wireshark

![[me.png]]

![[friend.png]]

![[unreach.png]]

 <div style="page-break-after: always;"></div>

## HW Qs

### Packet Analysis

Re-doing same experiment with Hotspot as the common network we observe the following

![[ip-h.png]]

![[tk-h.png]]

![[ws-1.png]]

![[ws-2.png]]

| Trial # | WiFi               | Hotspot            |
| ------- | ------------------ | ------------------ |
| 1.      | 121.317160519      | 30.572895773       |
| 2.      | 132.22945658       | 34.152093500       |
| diff    | 10.912296061000006 | 3.5791977270000004 |

### Write a short report of how UDP pkts are transmitted

- The UDP packets were sent without prior connection establishment.
- The packets contained application data with minimal overhead.
- The transmission was faster compared to TCP but lacked reliability mechanisms like acknowledgments or retransmissions.

> How UDP Packets Are Transmitted

1. **Data Encapsulation:** The application data is encapsulated within a UDP datagram.
2. **Packet Forwarding:** The UDP packet is sent to the destination without a handshake process.
3. **Reception at the Destination:** The receiving system reads the UDP packet and processes it accordingly.
4. **No Retransmission:** If a packet is lost, it is not automatically retransmitted.

### Network Behavior Report

1. **Wi-Fi Slower Than Mobile Hotspot**

    - The data showed that the Wi-Fi network had **higher latency** compared to the mobile hotspot.
    - UDP packets experienced **greater jitter** and **packet loss** on Wi-Fi.

2. **Possible Reasons for Differences in Performance**

    - **Interference on Wi-Fi:** Wi-Fi operates on **2.4 GHz or 5 GHz**, which can be congested due to multiple connected devices, and neighboring networks.
    - **Distance from Router:** Performance is affected by **distance and obstacles** like walls and tables, leading to slower transmission.
    - **Network Congestion:** More devices typically share a Wi-Fi connection, causing **higher latency**.
    - **Mobile Hotspot Efficiency:** Mobiles are optimized for **lower congestion** and **better bandwidth allocation**, making UDP transmission more stable.

Unlike TCP, UDP is connectionless, meaning it does not establish a handshake or guarantee packet delivery. While this makes it ideal for real-time applications like VoIP, online gaming, and streaming, it also introduces significant security vulnerabilities. Attackers exploit UDP for spoofing, flooding, and amplification attacks. This report explores common UDP threats and effective mitigation strategies.

## Security Considerations

### 1. UDP **Spoofing** (IP Spoofing Attack)

Attackers forge the source IP address in UDP packets, making them appear as if they originate from a trusted source. This enables them to inject malicious data, evade security measures, and participate in larger Distributed Denial-of-Service (DDoS) attacks.

### 2. UDP **Flood** (Denial-of-Service-DoS Attack)

In a UDP **flood** attack, attackers send an overwhelming number of UDP packets to a target, exhausting system resources and making services unavailable. Since UDP does not require connection establishment, the system must process each request, increasing vulnerability to these attacks.

### 3. UDP **Amplification** Attack

This type of DDoS attack leverages UDP-based services like DNS, NTP, and SNMP to amplify attack traffic. Attackers send small requests with a spoofed source IP, triggering large responses that overwhelm the victim’s network. Such attacks can generate traffic up to **100 times larger** than the initial request.

### 4. UDP-Based Malware and Data Exfiltration

Attackers often use UDP to establish covert channels for malware communication. UDP’s lack of session tracking makes it harder to detect unauthorized data transfers and botnet activity.

### Mitigation Strategies

### 1. Implement Firewalls and Traffic Filtering

- Configure **stateful firewalls** to monitor and block suspicious UDP traffic.
- Restrict UDP-based services to trusted IP ranges.

### 2. Deploy Rate Limiting and Deep Packet Inspection (DPI)

- Apply **rate-limiting** on UDP services to prevent amplification attacks.
- Use **DPI** to inspect UDP packets and identify malicious activity.
- Setup a router based firewall.

### 3. Enforce Authentication/IP Verification (BCP 38)

- Implement **ingress filtering** to drop packets with forged IP addresses.
- Use **UDP authentication mechanisms** where possible
- Use VPN

#### 4. Disable Unnecessary UDP Services

- Turn off **unused UDP ports** and services like NTP, SSDP, and SNMP.
- Configure **DNS servers** to minimize UDP amplification risks.