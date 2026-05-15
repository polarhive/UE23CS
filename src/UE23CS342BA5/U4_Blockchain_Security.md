# Unit 4 — Blockchain Security & Use Cases

---

## 1. Blockchain Risks Overview

Blockchain is not inherently immune to threats. Its widespread adoption across finance, healthcare, and government increases exposure to various risks:

| Risk Category    | Examples                                            |
| ---------------- | --------------------------------------------------- |
| Security Risks   | 51% attacks, Sybil attacks, smart contract exploits |
| Legal/Regulatory | Ambiguity across jurisdictions                      |
| Human Error      | Mismanaging private keys; deploying buggy contracts |
| Scalability      | Transaction speed and cost limitations              |
| Privacy          | Pseudonymity doesn't guarantee anonymity            |
|                  |                                                     |

**Blockchain Attack Surface:**

1. Blockchain Network (P2P layer)
2. Application/API Layer
3. Smart Contract Layer
4. Transaction Verification Mechanism
5. Storage Layer
6. Mining Pool

**Financial Scale of Attacks:**

| Year | Funds Stolen |
|------|-------------|
| 2022 | ~$3.7 billion |
| 2023 | ~$1.7 billion (−54.3% — but more incidents: 231) |
| 2024 | ~$2.2 billion (+21% — 303 incidents) |

---

## 2. Blockchain Operation Mechanism Risks

### 2.1 51% Attack

**What it is:** When a single entity (or group) gains control of **more than 50% of the network's total hashing power**, giving them decisive power over the blockchain.

**What the Attacker CAN Do:**

- **Double Spending** — Reverse transactions on the honest chain; reuse tokens on the malicious chain.
- **Block New Transactions** — Prevent new transactions from being confirmed (freeze network).
- **Disrupt Confidence** — Shatter trust in the network's immutability.

**What the Attacker CANNOT Do:**

- Create coins from nothing.
- Change block reward rules.
- Steal others' coins directly.

**Mitigation Strategies:**

| Strategy | Description |
|----------|-------------|
| Higher Network Hashrate | Makes it computationally and economically infeasible to gain 51% |
| Checkpointing / Finality Rules | Blocks after a certain depth cannot be changed |
| Switching to PoS | Reduces centralisation of power (as Ethereum 2.0 did) |
| Monitoring Mining Pools | Enforce policies preventing a pool from exceeding 50% hash power |

---

### 2.2 Private Key Security

**The Core Risk:** Ownership of blockchain assets = control of private key.

- No username or password — just cryptographic keys.
- If private key is **lost or stolen** → assets are gone forever (no recovery).

**Attack Scenario:**

1. Hacker steals Alice's private key.
2. Attacker signs fraudulent transactions on Alice's behalf.
3. Network treats fraudulent messages as legitimate (public key still matches).
4. Funds stolen; irreversible loss.

**Best Practices:**

| Practice | Description |
|----------|-------------|
| Hardware Wallets | Store keys offline; away from hackers |
| Multi-Sig Wallets | Require multiple keys to approve a transaction |
| No Plaintext Storage | Avoid screenshots, cloud storage, emails |
| Strong Passwords + 2FA | Even for wallets and exchange accounts |
| Encrypted Backups | Multiple physical/encrypted locations |

---

### 2.3 Criminal Activities in Blockchain

Blockchain enables fast, borderless, pseudonymous transactions — attractive for illegitimate uses:

- Ransomware attacks
- Dark web / underground market trades
- Money laundering

Privacy-enhancing tools (mixers, dark wallets, Monero, Zcash) make tracing harder.

**Countermeasures:**

| Tool/Method | Description |
|------------|-------------|
| Chain Analytics (Chainalysis, CipherTrace) | Track suspicious activity; trace fund flows |
| KYC/AML Compliance on Exchanges | Verify user identity; reduce anonymous off-ramps |
| Regulation of Privacy Coins | Legal restrictions on Monero, Zcash in some jurisdictions |

---

### 2.4 Double Spending in Blockchain

**Definition:** Spending the same cryptocurrency more than once. Fundamental threat to digital currency integrity.

**Step-by-Step Attack:**

1. Attacker initiates **TX_a** — sends coins to a legitimate vendor.
2. Vendor sees TX_a; assumes payment received.
3. Attacker simultaneously creates **TX_b** — sends same coins to their own controlled address.
4. Attacker ensures TX_b gets mined (via higher hash power or colluding mining pool).
5. TX_b confirmed on blockchain → TX_a becomes invalid.
6. Attacker keeps both goods AND money; vendor is unpaid.

**Countermeasures:**

- Wait for confirmations before delivering goods (6 confirmations for large transactions).
- Use real-time payment gateways with fraud detection.
- Employ double-spending detection tools.
- Never accept zero-confirmation payments for valuable goods.

---

### 2.5 Transaction Privacy Leakage

**Reality:** Bitcoin/Ethereum are **pseudonymous**, not truly anonymous. All transactions are public and traceable.

**Privacy Leakage Occurs When:**

- An observer analyses transaction patterns, linkages, or metadata.
- Blockchain analytics tools are used to de-anonymise users.
- Multiple transactions from the same address reveal patterns.

**Implications:**

- De-anonymisation of users.
- Surveillance risks by governments or hostile actors.
- Reduced financial privacy for activists, journalists, corporate users.

**Mitigation Techniques:**

| Technique | Description |
|-----------|-------------|
| Privacy coins | Monero (ring signatures), Zcash (zk-SNARKs) |
| Avoid address reuse | Use fresh address for each transaction |
| Coin mixers/tumblers | Legally grey; obscures transaction trail |
| Tor/VPN | Protect network-level identity |
| Wallet hygiene | Manage UTXOs carefully |

---

## 3. Network Attacks on Blockchain

### 3.1 Distributed Denial of Service (DDoS)

**What it is:** Overwhelm blockchain nodes, smart contracts, or consensus mechanisms with massive traffic/fake transactions.

**Targets:**

| Target | Attack Type | Impact |
|--------|------------|--------|
| Full Nodes | Network flooding | Saturate bandwidth/memory |
| Smart Contracts | Logic bombs/looping | Exploit expensive operations |
| Mining/Validator Pools | Consensus disruption | Delay validation |
| Mempool | Transaction spamming | Clog with low-fee transactions |
| Oracles | Data query floods | Overload oracles |

**Types of DDoS on Blockchain:**

| Type | Description |
|------|-------------|
| Network Layer | UDP flood, ICMP flood — overwhelm node bandwidth |
| Application Layer | HTTP flood, Smart Contract flood — target dApps |
| Resource Exhaustion | Memory/CPU exhaustion — crash nodes |
| Consensus Mechanism | Mining Pool flood, Validator flood — delay block production |
| Transaction Spam | Low-value spam fills mempool; high-fee spam jumps queue |
| Sybil Attack Variants | Fake node flood; influence consensus with fake identities |

**How Blockchain Mitigates DDoS:**

| Mechanism | Description |
|-----------|-------------|
| Gas Fees (Economic Deterrent) | Spamming becomes financially expensive |
| Mempool Filtering | Reject low-fee/duplicate transactions; prioritise by gas price |
| Rate Limiting | Control request volume from single sources |
| Load Balancing | Distribute traffic across multiple nodes |
| CDN | Cache content across multiple servers |
| Network Monitoring | Detect unusual traffic patterns |

---

### 3.2 Transaction Malleability Attack

**What it is:** Ability to alter a transaction's unique identifier (hash/TXID) **without changing the actual effect** of the transaction.

**How it Works:**

1. Attacker tweaks a pending transaction slightly (e.g., modifies the signature encoding).
2. Transaction still valid but gets a different TXID.
3. Wallets/exchanges tracking by TXID think the original transaction failed.
4. Sender resends → double-spend or unexpected fund loss.

**Historical Example:** The Mt. Gox Bitcoin exchange collapse was partly attributed to this attack.

**Mitigation:**

- **SegWit (Segregated Witness)** — Bitcoin upgrade adopted in 2017.
- Separates signature (witness data) from the transaction data used to compute the TXID.
- SegWit TXIDs are **non-malleable**.

---

### 3.3 Time Jacking

**What it is:** An attacker manipulates the network time perceived by a node by sending intentionally incorrect timestamps via Sybil nodes.

**How it Works:**

1. Bitcoin node maintains **adjusted network time** based on median timestamps from connected peers.
2. Attacker floods victim node with malicious peers sending wrong timestamps.
3. Victim node shifts internal clock:
   - Too far ahead → rejects valid blocks as "too old".
   - Too far behind → mines invalid blocks; creates forks.

**Goals:**

| Goal | Impact |
|------|--------|
| Desynchronise node | Accept outdated/invalid blocks |
| Force forks | Exploit differences in chain view |
| Censorship | Delay confirmation of valid transactions |
| DoS | Cause node to become stuck/disconnected |

**Countermeasures:**

- Bitcoin Core: Time sanity bounds of ±70 minutes from system clock.
- Rely more on system time than peer timestamps.
- Improved median filtering (trusted/diverse subset of peers).
- NTP integration to verify time against trusted NTP servers.

---

### 3.4 Routing Attacks

**What it is:** Attacker manipulates internet traffic by exploiting routing protocols (BGP, DNS) that blockchain nodes depend on.

**Types:**

| Attack Type | Description |
|------------|-------------|
| **Partitioning Attack** | Split blockchain network into disjoint segments; each segment mines unaware of the others → forks, stale blocks |
| **Delay Attack** | Intercept and slow traffic between nodes → nodes receive outdated information |
| **Hijack Attack** | Mislead nodes into routing through malicious networks (BGP hijack) → monitor, modify, or discard data |
| **Eclipse Attack (related)** | Isolate node by controlling all connections → made easier by routing control |

**Mitigation:**

- Multiple ISPs or network paths.
- Encrypted communications (VPN, Tor).
- Network monitoring for anomalies.
- Diversify peer connections across geographies and networks.
- Route Origin Validation (ROV) to prevent BGP hijacks.

---

### 3.5 Sybil Attacks

**What it is:** A malicious actor creates **multiple fake identities (nodes)** to gain disproportionate control over the network.

**How it Works:**

1. Attacker creates hundreds of fake nodes.
2. Victim's network connections are surrounded by fake nodes.
3. All transactions from victim are routed through attacker-controlled nodes.
4. Victim becomes open to double-spending and other attacks.

**Difficulty:** Hard to detect and prevent.

**Prevention Measures:**

| Measure | Description |
|---------|-------------|
| Increase identity creation cost | PoW makes fake nodes expensive |
| Require some trust to join | PoS requires staked funds |
| Reputation-based power | Node power based on built reputation over time |
| Identity verification | Permissioned blockchains require verifiable identity (PoA) |
| Transaction fees | High fees discourage spamming with fake identities |

---

### 3.6 Eclipse Attacks

**What it is:** A malicious actor controls **all peer connections** of a victim node, cutting it off from honest nodes. The victim becomes dependent on the attacker's (potentially false or delayed) information.

**How Eclipse Attacks Work:**

1. **Peer Table Flooding:** Attacker floods victim's peer table with malicious IPs, crowding out real peers.
2. **Restart Exploits:** Malicious IPs stored as preferred peers → victim reconnects to attackers after reboot.
3. **Full Connection Control:** All inbound and outbound connections controlled by attacker.
   - Send only old blocks (delay sync).
   - Hide transactions from mempool.
   - Feed fake blockchain forks.

**Mitigation:**

| Measure | Description |
|---------|-------------|
| Diversify Connections | Don't allow all connections from single IP/subnet; use multiple ASNs |
| Peer Management Hardening | Avoid static/limited peer lists; use whitelists for critical nodes |
| Rate-Limiting + Peer Rotation | Limit how fast new peers are added; periodically refresh connections |

---

### 3.7 Long-Range Attacks on PoS Networks

**What it is:** Attacker reconstructs an alternative blockchain history from a point far back (often genesis block) using **old private keys** of former validators.

**Why PoS Is Vulnerable:**

- PoW requires re-doing all computational work to rewrite history (physically infeasible).
- PoS only requires old private keys (which validators may have discarded or leaked).
- Old keys can be obtained/purchased cheaply after validators exit the network.

**How it Works:**

1. Attacker acquires old private keys of validators who had high stake in the past.
2. Uses keys to create a valid alternative chain from a distant checkpoint.
3. New or offline nodes syncing to the network might adopt the malicious chain if it appears valid and is longer.

**Mitigation:**

| Strategy | Description |
|----------|-------------|
| Checkpointing | Nodes ignore chains before a known good checkpoint; hardcoded trusted blocks |
| Weak Subjectivity | New nodes obtain trusted state snapshot from reliable sources |
| Slashing Conditions | Validators who sign conflicting chains are penalised |
| Key Expiry & Rotation | Validators retire old keys; reduces risk of misuse |

---

## 4. Smart Contract Attacks

### 4.1 Overview

Smart contracts are immutable once deployed — bugs cannot be fixed without complex upgrades. Hackers exploit vulnerabilities for devastating financial losses.

**Top 5 Smart Contract Attack Vectors (OWASP):**

1. Reentrancy Attack
2. Integer Overflow/Underflow
3. Front-Running (Transaction Ordering Dependency)
4. DoS with Block Gas Limit / Block Stuffing
5. Unchecked External Calls

---

### 4.2 Reentrancy Attack

**What it is:** Exploiting coding vulnerabilities that allow external contracts to **re-enter a function before the original function updates its state**.

**How it Works:**

1. Smart contract A sends ETH to Contract B (external call).
2. Contract B's fallback function is triggered.
3. Fallback function calls back into Contract A's `withdraw()` **before** A updates the balance.
4. Contract A still shows the old (higher) balance → allows repeated withdrawal.
5. Funds drained until Contract A is empty.

**Famous Example:** The DAO Hack (2016) — $60 million drained from Ethereum DAO.

**Why It's Dangerous:**

- Breaks expected flow of execution.
- Devs often forget that `call()` can trigger user-controlled code.

**Mitigation:**

1. **Checks-Effects-Interactions Pattern** — Update state BEFORE making external calls.
2. **Reentrancy Guard (Mutex)** — Modifier preventing function re-entry while executing.
3. **Avoid `call()`** unless absolutely necessary.
4. **Pull over Push Pattern** — Users pull funds rather than contract pushing.

---

### 4.3 Integer Overflow/Underflow

**What it is:** Fixed-size integers in Solidity have maximum/minimum values. When a calculation exceeds these limits, it wraps around silently (in older Solidity versions).

**Ranges:**

- `uint8`: 0 to 255
- `uint256`: 0 to 2²⁵⁶ - 1

**Overflow Example:**

```
uint8 value = 255;
value += 1;  // → wraps to 0 (not 256!)
```

**Underflow Example:**

```
uint8 value = 0;
value -= 1;  // → wraps to 255 (not -1!)
```

**Exploitation:** Attackers manipulate token balances, bypass transfer limits, or create tokens from nothing.

**Prevention:**

1. **Use Solidity ≥ 0.8.0** — Overflow/underflow checks are **built-in** (revert on overflow).
2. **Use SafeMath library** for older Solidity versions.
3. Always validate arithmetic manually if unsure.

---

### 4.4 Front-Running (Transaction Ordering Dependency)

**What it is:** Someone observes a pending transaction in the **mempool** and submits their own similar transaction with a **higher gas fee**, causing their transaction to be mined first.

**In Traditional Finance:** Front-running is illegal (brokers acting on client trades).

**In DeFi:** A technical consequence of how public blockchains work.

**How It Happens:**

1. All transactions are broadcast publicly to the mempool before mining.
2. Miners/validators pick transactions based on gas price (highest first).
3. Anyone can watch the mempool and react with more gas.

**Attack Flow (Sandwich Attack Example):**

1. Alice submits a buy order for Token X on Uniswap.
2. Bob (attacker/bot) sees it in mempool; knows it will push price up.
3. Bob submits same buy with higher gas price → mined first.
4. Alice's trade mined next → Bob's earlier buy has pushed price up.
5. Bob immediately sells at the higher price → profit at Alice's expense.

**Mitigation:**

| Method | Description |
|--------|-------------|
| **Commit-Reveal Scheme** | Step 1: Commit a hash of input; Step 2: Reveal actual data later |
| **Randomised/Delayed Execution** | Batch transactions; execute in random order |
| **Private Transaction Relays** | Flashbots — submit transactions privately to miners without broadcasting to mempool |

---

### 4.5 DoS with Block Gas Limit / Block Stuffing

**What it is:** An attacker fills blocks with high-gas transactions, preventing legitimate transactions from being included. Or a single transaction hits the block gas limit, causing failure.

**Types:**

1. **Block Stuffing:** Flood the network with expensive transactions to fill blocks.
2. **Unbounded Loops:** Contract with loop that has no gas limit → block gas limit exhausted.
3. **External Contract DoS:** Contract depends on an external contract that is made to fail.

**Mitigation:**

- Avoid unbounded loops in smart contracts.
- Be careful with loops over arrays that can grow unboundedly.
- Use pull payment patterns to avoid gas-heavy operations.

---

### 4.6 Unchecked External Calls

**What it is:** When a smart contract calls another contract/address and does NOT properly check whether the call succeeded.

**Types of External Calls in Solidity:**

- `address.call()` — Low-level; returns bool; can trigger arbitrary code
- `address.send()` — Limited gas (2300); returns bool
- `address.transfer()` — Limited gas; reverts on failure
- `externalContract.someFunction()` — High-level call

**Risks:**

- The called contract might fail silently → contract thinks it succeeded.
- Re-entry possible if state not updated first.
- Gas consumption unpredictable.
- External contract might intentionally throw to break logic.

**Mitigation:**

1. **Always check return values** of `call()` and `send()`.
2. **Avoid calling unknown contracts** directly.
3. Use **pull over push** for sending funds.
4. Use **limited gas forwarding** to prevent complex re-entry.

---

### 4.7 Key Best Practices for Smart Contract Security

| Practice | Description |
|----------|-------------|
| Use Solidity ≥ 0.8.0 | Built-in overflow/underflow protection |
| Checks-Effects-Interactions | Update state before external calls |
| OpenZeppelin Libraries | Battle-tested security patterns |
| Rigorous Testing | Unit tests, integration tests, fuzzing |
| Formal Auditing | Professional security audits |
| Tools | Slither (static analysis), MythX (symbolic execution), Foundry (fuzzing) |
| Avoid External Calls or Check Them Rigorously | Never assume external call succeeds |

---

## 5. Blockchain & the CIA Triad

### 5.1 CIA Triad Overview

The foundational concept in information security:

| Property | Meaning |
|----------|---------|
| **Confidentiality** | Only authorised individuals can access information |
| **Integrity** | Information is not altered by unauthorised individuals; non-repudiation ensured |
| **Availability** | Timely and reliable access to information |

### 5.2 How Blockchain Impacts the CIA Triad

**Confidentiality — Mixed Impact:**

- **Public blockchains** (Bitcoin, Ethereum) are **NOT confidential by design** — all transactions are public.
- Even pseudonymous addresses can be de-anonymised once linked to identity.
- **Private/permissioned blockchains** (Hyperledger) can enforce confidentiality via access controls and encryption.

**Achieving Confidentiality with Hyperledger Fabric:**

- Channels restrict data to specific participants.
- Private data collections allow subset-only data sharing.
- Encryption at rest and in transit.

**Integrity — Strong Positive Impact:**

- Blockchain's core strength — **immutable ledger**.
- Once confirmed, transaction cannot be altered without redoing network's entire work (practically impossible).
- **SHA-256 hashing** ensures no tampering.
- **Distributed consensus** validates data correctness before storage.
- Automatic **audit trails and timestamps**.

**Availability — Generally Strong (with caveats):**

- **Decentralisation** eliminates single point of failure.
- As long as the network has live nodes, data is accessible.
- Resistant to DDoS attacks (no central target).
- Full ledger replicated across all nodes (no central dependency).
- **Caveat:** Node downtime, network congestion, or smart contract bugs can affect availability.

---

## 6. Blockchain's Impact on Cybersecurity

### 6.1 Key Security Benefits

| Benefit | Description |
|---------|-------------|
| **Decentralisation** | No SPOF; tampering one node doesn't affect the network |
| **Data Integrity & Immutability** | Transactions verifiable and traceable; unauthorised modifications prevented |
| **Enhanced Authentication** | Public/private key cryptography for identity; smart contracts for automated access control |
| **Secure Transactions** | End-to-end encryption; fraud/chargebacks reduced; transparent; irreversible |
| **Improved Audit Trails** | Permanent, transparent record of all transactions; regulatory compliance; accountability |

### 6.2 Conclusion

> Blockchain technology has the potential to revolutionise cybersecurity by providing a **secure, transparent, and decentralised framework** for data management and transactions.

Organisations can:

- Enhance security posture.
- Reduce risk of cyber threats.
- Build greater trust with stakeholders.

---

## 7. Blockchain-Based DNS Security Platform

### 7.1 Traditional DNS Problems

**DNS (Domain Name System)** maps domain names (e.g., google.com) to IP addresses. Traditionally relies on **centralised DNS servers** managed by companies or governments.

**Key Vulnerabilities:**

| Vulnerability | Description |
|--------------|-------------|
| **DNS Spoofing/Poisoning** | Attacker sends fake DNS responses → users routed to malicious sites |
| **Single Point of Failure** | If DNS server is down/hacked, domains become unreachable |
| **Censorship** | Governments/ISPs can block or manipulate domain names |
| **Lack of Transparency** | No public record of who changed a DNS entry and when |

### 7.2 How Blockchain Fixes DNS Security

A **blockchain-based DNS system** replaces central DNS registries with a decentralised ledger where:

- Domain ownership is recorded as blockchain transactions.
- Changes are made via smart contracts.
- All entries are transparent, immutable, and censorship-resistant.

**How It Works:**

1. **Register a Domain** — User sends transaction to smart contract; ownership tied to wallet address.
2. **Resolve a Domain** — Blockchain-based resolver fetches domain-to-IP mapping.
3. **Update DNS Record** — Owner submits transaction; all changes stored on-chain with timestamp and signature.

### 7.3 Key Benefits

| Benefit | Description |
|---------|-------------|
| Tamper-proof entries | Can't be altered without private keys |
| Public verifiability | Every change verifiable on-chain |
| No central authority | No single body controls access/revocation |
| Smart contract enforcement | Automated renewals, transfers, rules |
| Decentralised resilience | No single point of failure |

### 7.4 Real-World Examples

| Platform | Description |
|---------|-------------|
| **Ethereum Name Service (ENS)** | Maps `.eth` domains to Ethereum wallets or IPFS sites |
| **Handshake (HNS)** | Decentralised root DNS zone; competes with ICANN; auction-based TLD registration |
| **Unstoppable Domains** | `.crypto`, `.wallet`, `.x` domains; one-time payment; no renewal fees |

---

## 8. Selfish Mining

### 8.1 What Is Selfish Mining?

> **Selfish mining** is a strategy where a miner (or pool) solves a hash, opens a new block, and **withholds** it from the public blockchain — creating a private fork to gain mining advantage.

**Why it works:** Most blockchains follow the **longest chain rule**. Honest miners waste resources on blocks that get orphaned.

### 8.2 The Process

1. **Block Found Privately:** Selfish miner finds valid block; withholds it.
2. **Private Chain Extension:** Continues mining secretly on private chain.
3. **Public Catch-Up:** Honest miners find a competing block.
4. **Strategic Release:** Selfish miner releases private chain before honest chain gets too long.
5. **Longest Chain Wins:** Network adopts selfish miner's chain; orphans honest blocks.
6. **Unfair Reward:** Selfish miner earns more rewards than fair share of hash power.

### 8.3 Impact on Blockchain

| Impact | Description |
|--------|-------------|
| Centralisation Risk | Encourages formation of large mining pools |
| Security Degradation | Reduces trust in PoW consensus |
| Lower Network Efficiency | More orphaned blocks; wasted resources |
| Fairness Violation | Honest miners penalised |

### 8.4 Mitigation Techniques

- Modify consensus rules to penalise block withholding.
- **Uncle blocks** / orphan rewards (like in Ethereum) — reduce incentives for selfish mining.
- Statistical/game-theoretic models to detect abnormal chain behaviours.

> No known real-world selfish mining attacks as of end of 2021, but remains a theoretical vulnerability.

---

## 9. Blockchain Security Use Cases

### 9.1 Blockchain-Based DDoS Protection

Traditional DDoS attacks exploit centralised bottlenecks. Blockchain enables decentralised DDoS protection:

**Traditional DDoS:**

- Attacker infects millions of computers with malware → botnet of "bots".
- Botnet floods a target server with requests → system crashes/slows.
- First major DDoS: University of Minnesota (1999) — 220+ systems down for several days.

**Blockchain-Based DDoS Mitigation:**

| Strategy | Description |
|----------|-------------|
| **Rate Limiting** | Control requests per source per time period |
| **Traffic Filtering** | Block malicious traffic; allow legitimate traffic |
| **Load Balancing** | Distribute traffic across multiple nodes |
| **CDN** | Offload traffic by caching content across servers |
| **Network Monitoring** | Detect unusual traffic patterns |
| **Cloud-Based DDoS Protection** | Absorb/mitigate large-scale attacks |

**Best Practices for Blockchain:**

1. Strong access controls and authentication for blockchain nodes.
2. Regular updates and patching.
3. Rate limiting at node level.
4. Deploy DDoS protection services.
5. Monitor traffic patterns continuously.
6. Optimise consensus algorithms for the use case.
7. Geographic distribution of nodes.

---

## 10. Summary — Key Attack Vectors & Defences

| Attack | Layer | Key Defence |
|--------|-------|------------|
| 51% Attack | Network/Consensus | Higher hashrate; PoS; checkpointing |
| Sybil Attack | Network | PoW cost; identity verification; reputation |
| Eclipse Attack | Network | Peer diversification; rotation; rate limiting |
| DDoS | Network/Application | Gas fees; rate limiting; traffic filtering |
| Transaction Malleability | Transaction | SegWit |
| Time Jacking | Network | Time sanity bounds; NTP integration |
| Routing Attack | Network | Multiple ISPs; encrypted comms; ROV |
| Long-Range Attack (PoS) | Consensus | Checkpointing; weak subjectivity; slashing |
| Selfish Mining | Consensus | Uncle rewards; protocol changes |
| Reentrancy | Smart Contract | Checks-Effects-Interactions; reentrancy guard |
| Integer Overflow | Smart Contract | Solidity ≥ 0.8.0; SafeMath |
| Front-Running | Smart Contract | Commit-reveal; Flashbots |
| Unchecked Calls | Smart Contract | Always check return values; pull pattern |
| Private Key Theft | User/Wallet | Hardware wallets; multi-sig; cold storage |
| Double Spending | Transaction | Wait for confirmations; PoW immutability |
| Privacy Leakage | Transaction | Privacy coins; address rotation; mixers |

---

## Quick Reference

| Term | Definition |
|------|-----------|
| 51% Attack | Controlling majority hash power to rewrite blockchain history |
| Selfish Mining | Withholding found blocks to gain disproportionate mining rewards |
| Reentrancy | Attack where external contract re-enters function before state is updated |
| Front-Running | Submitting higher-gas transaction to cut in front of victim's pending transaction |
| Integer Overflow | Fixed-size integer exceeds maximum; wraps around to minimum |
| Sybil Attack | Creating multiple fake identities to gain disproportionate network influence |
| Eclipse Attack | Isolating a node by controlling all its peer connections |
| Time Jacking | Manipulating network time via fake peer timestamps |
| SegWit | Bitcoin protocol upgrade separating signature from transaction data |
| CIA Triad | Confidentiality, Integrity, Availability — three pillars of information security |
| ENS | Ethereum Name Service; blockchain-based DNS using .eth domains |
| PBFT | Practical Byzantine Fault Tolerance — consensus algorithm for permissioned blockchains |
| Slashing | Penalty for PoS validators who behave dishonestly |
| Mempool | Pool of unconfirmed pending transactions |
| Gas | Unit of computation cost in Ethereum; economic deterrent against spam |
| Commit-Reveal | Two-step scheme to prevent front-running; commit hash first, reveal value later |
| KYC/AML | Know Your Customer / Anti-Money Laundering — regulatory compliance on exchanges |
| DDoS | Distributed Denial of Service — overwhelm system with massive traffic |
| BGP Hijack | Manipulating internet routing protocols to intercept or redirect traffic |
| Checkpointing | Hardcoded trusted blocks to prevent long-range attacks on PoS chains |
