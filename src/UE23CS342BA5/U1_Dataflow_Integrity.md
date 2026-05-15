# Unit 1 — Introduction, Data Flow & Data Integrity

---

## 1. Distributed vs. Centralised Systems

### 1.1 Centralised Systems

A centralised system has a single authority (server, institution) that controls all data and decision-making.

- **Single point of failure (SPOF):** If the central node fails, the whole system goes down.
- **Trust bottleneck:** All participants must trust the central authority (e.g., a bank, land-record department, UIDAI).
- **Example:** Traditional banking — the bank verifies, records, and authorises every transaction.

### 1.2 Distributed / Peer-to-Peer Systems

Peer-to-peer (P2P) systems are distributed software systems where individual computers (nodes) make their computational resources (processing power, storage, bandwidth) directly available to each other without a central coordinator.

**Key properties:**

- Every node has equal rights and responsibilities.
- Nodes act simultaneously as both clients and servers.
- Resilient by design — no SPOF, reduced DoS risk.
- Data is replicated across all nodes.

**Applications:** File sharing, content distribution, privacy protection, cryptocurrency.

> **Historical context:** Napster (1999) disrupted the music industry using P2P principles, demonstrating the transformative power of decentralised sharing.

### 1.3 Link Between P2P and Blockchain

Blockchain is a tool for achieving and maintaining **integrity** in purely distributed peer-to-peer systems. It leverages P2P network technology to provide a decentralised ledger for one or more digital assets. Blockchain nodes collectively validate and store records without relying on any single entity.

---

## 2. What Is Blockchain?

### 2.1 Abstract Definition

> A blockchain provides **coordination between many parties when there is no single trusted party.**

### 2.2 Formal Definition

> The blockchain is a purely distributed peer-to-peer system of ledgers that utilises a software unit consisting of an algorithm which negotiates the informational content of ordered and connected blocks of data together with cryptographic and security technologies in order to achieve and maintain its integrity.

### 2.3 Technical Definition (Three Pillars)

A technology that:

1. **Permits** transactions to be gathered into blocks and recorded.
2. **Cryptographically chains** blocks in chronological order.
3. **Allows** the resulting ledger to be accessed by all servers/nodes.

### 2.4 What Blockchain Is NOT

- A way to make quick money.
- A way to privately send data (it's public and transparent by default).
- A solution to every global problem.
- Simply a cloud-based database.
- All blockchains are public (there are private and consortium types too).

---

## 3. History & Evolution of Blockchain

| Year | Event |
|------|-------|
| 1991 | Stuart Haber & Scott Stornetta propose cryptographically secured chain of blocks |
| 2008 | Satoshi Nakamoto publishes the Bitcoin whitepaper |
| 2009 | Bitcoin network launches; genesis block mined on 3 Jan 2009 |
| 2011 | Litecoin introduced |
| 2015 | Ethereum network goes live |
| ~2016 | Term "Blockchain" popularised |

### Versions of Blockchain

| Version | Focus | Example |
|---------|-------|---------|
| Blockchain 1.0 | Currency / Cryptocurrency | Bitcoin |
| Blockchain 2.0 | Smart Contracts | Ethereum, Cardano |
| Blockchain 3.0 | Decentralised Enterprise Applications | Hyperledger |

---

## 4. Trust Model in Blockchain

### 4.1 Traditional Trust Problem

In traditional systems we must trust:

- Hardware not to leak cryptographic keys
- OS not to peek into computation memory
- Applications not to be hijacked
- Institutions (banks, government bodies)

The **double-spending attack** is the canonical problem: a digital file (money) can be copied and spent twice.

### 4.2 Blockchain Trust Model

Blockchain establishes trust without centralised entities through:

- **Cryptographic techniques** — public/private key pairs, digital signatures
- **Consensus algorithms** — majority agreement ensures no single actor can cheat
- **Distributed ledger technology** — every participant holds a copy; no hidden manipulation is possible

> Blockchain is recognised as the "fifth evolution of computing" — a new trust layer for the Internet. Previously, trust required certificates from central authorities (e.g., SSL).

### 4.3 How a Blockchain Transaction Works (Flow)

```
User requests transaction
        ↓
Block representing the transaction is created
        ↓
Block is broadcast to ALL nodes in the network
        ↓
All nodes validate the block and transactions
        ↓
Transaction is verified and executed
        ↓
Block is added to the chain (immutable)
```

---

## 5. Core Components of Blockchain

### 5.1 Peer-to-Peer Network

- Decentralised model where each party acts as both client and server.
- Eliminates intermediaries and single points of failure.
- All nodes collaborate to manage and control data.

### 5.2 Nodes

Individual computers within the blockchain network. Each node stores a copy of the entire blockchain.

| Node Type | Description |
|-----------|-------------|
| **Full Node** | Downloads all blocks and transactions; can verify all blocks; fully independent |
| **Lightweight (Light) Node** | Stores only block headers + some transactions; uses SPV (Simplified Payment Verification) |
| **Miner Node** | Full node that also solves the proof-of-work puzzle to propose new blocks (CPU → GPU intensive) |

### 5.3 Distributed Ledger

- An electronic database of all transactions.
- Multiple blocks (each containing ≥1 transaction) linked cryptographically.
- Eliminates the need for a central authority.
- All participants share one copy including all updates.
- Records are only added when stakeholders reach consensus.

### 5.4 Transactions

The basic unit of operation on a blockchain — records the transfer of data, assets, or information. Transactions are **immutable**, **transparent**, and **secured using cryptographic mechanisms**.

**Components of a Transaction:**

| Component | Description |
|-----------|-------------|
| Sender | Participant initiating the transaction; verified via public key + digital signature |
| Receiver | Participant receiving the asset/information |
| Transaction Data | Asset transfer, smart contract execution, or metadata |
| Digital Signature | Sender signs with their private key to prove authenticity |
| Timestamp | Time when the transaction was created |
| Transaction Fee | Small fee paid to miners/validators |
| Transaction Hash | Unique cryptographic hash identifying the transaction |

**Types of Transactions:**

- **Cryptocurrency Transactions** — e.g., Alice sends 2 BTC to Bob
- **Smart Contract Transactions** — deploying or invoking a contract
- **Token Transfers** — moving ERC-20 tokens
- **Data Transactions** — recording supply-chain data, identity info
- **Governance Transactions** — voting in DAOs

### 5.5 Tokens

Digital assets created and managed on a blockchain representing value, rights, or utility.

**Token vs. Coin:**

| Property | Coin | Token |
|----------|------|-------|
| Blockchain | Has its own blockchain | Built on an existing blockchain |
| Creation | Created with the blockchain | Created via smart contracts |
| Use | Digital money, gas fees | Utility, governance, NFTs, etc. |
| Examples | Bitcoin, ETH | USDT, UNI, LINK |

**Token Categories:**

| Type | Description | Examples |
|------|-------------|---------|
| Utility | Access to services/features within a dApp | BAT (Brave), Filecoin (FIL) |
| Security | Represent ownership in real-world assets; subject to regulations | Security token protocols |
| Governance | Voting power over protocol decisions | Uniswap UNI, Maker MKR |
| Transactional | Payments/transfers; low volatility | Stablecoins |
| Platform | Native cryptocurrency of the ecosystem | ETH, SOL, BNB |
| NFT | Unique, non-fungible, indivisible assets | Digital art, certificates, game items |

**Crypto Token Model:**

- Governed by smart contract rules (the "token contract")
- Belongs to a blockchain domain
- Accessible via dedicated wallet + public-private key pair
- Only the holder of the private key is the true owner/custodian

### 5.6 Consensus Mechanisms

A mechanism ensuring all nodes validate and agree on the validity of transactions and their order. Examples:

- **Proof of Work (PoW)** — Solve complex computational puzzles (Bitcoin)
- **Proof of Stake (PoS)** — Validators chosen by staked cryptocurrency
- **Delegated Proof of Stake (DPoS)** — Delegates validate on behalf of voters

### 5.7 Smart Contracts

Self-executing programs on the blockchain. Encode the rules and conditions of an agreement. Automatically execute when predefined conditions are met. Enable trustless, decentralised execution — no intermediaries needed.

---

## 6. Types of Blockchain

### 6.1 Public Blockchain

Open to everyone; fully decentralised, transparent and immutable.

**Features:** Decentralised, open access, immutable, transparent, secured via PoW/PoS.

**Examples:** Bitcoin, Ethereum (Mainnet)

**Demerits:**

- Scalability issues (congestion, slow TPS)
- High energy consumption (PoW)
- Privacy concerns (all transactions visible to public)

### 6.2 Private Blockchain

Restricted network; only authorised participants can join; controlled by a single organisation.

**Features:** Permissioned access, centralised, limited transparency, higher performance.

**Examples:** Hyperledger Fabric

**Demerits:**

- Centralisation concerns (undermines decentralisation principle)
- Limited transparency
- Security depends on trust of participating entities

### 6.3 Hybrid Blockchain

Combines features of public and private blockchains.

**Features:** Controlled access, flexible governance, scalability, interoperability.

**Demerits:**

- Complex implementation
- Reduced decentralisation (private component)
- Trust dependency on managing entities
- Regulatory complexity

### 6.4 Consortium / Federated Blockchain

Multiple organisations share control. More than one central authority grants access to pre-selected nodes for reading, writing, and auditing.

**Features:** Semi-decentralised, permissioned, collaborative governance, efficient consensus.

**Demerits:**

- Complex governance structures
- Interoperability challenges
- Dependency on key member organisations

---

## 7. Cryptography — The Foundation of Data Integrity

### 7.1 What Is Cryptography?

Cryptography uses computer algorithms to safeguard data, ensuring only intended recipients can access content. It transforms information into a secure code via **encryption** that can only be decoded with the correct **decryption key**.

**Key Terminology:**

| Term | Meaning |
|------|---------|
| Plaintext | Message in natural, readable format |
| Ciphertext | Message altered to be unreadable |
| Key | Sequence controlling the cryptographic algorithm |
| Key space | Total number of possible key values |
| Initialization Vector | Random value used to ensure no patterns in encryption |
| Cryptosystem | Combination of algorithm + key + key management |

**Cryptosystem Services (CIA+):**

| Service | Meaning |
|---------|---------|
| Confidentiality | Only authorised entities can view |
| Integrity | Message was not altered unauthorised |
| Authentication | Validates the source/sender identity |
| Non-repudiation | Sender cannot deny sending the message |
| Access Control | Access to data requires correct crypto keys |

### 7.2 Types of Cryptography

**Symmetric Key Cryptography:**

- Single key used for both encryption and decryption.
- Also called **Secret-Key Cryptography**.
- Both sender and receiver must share the same key.

**Asymmetric Key Cryptography:**

- Two mathematically related keys: a **public key** (shared openly) and a **private key** (kept secret).
- Also called **Public-Key Cryptography**.
- Public key encrypts; private key decrypts (or vice-versa for signatures).

### 7.3 Cryptographic Hash Functions

A hash function produces a fixed-length output (digest) from variable-length input. It is the "digital fingerprint" of data.

**Key Properties:**

| Property | Description |
|----------|-------------|
| Collision-free | No two different inputs should produce the same hash |
| Hidden (Pre-image resistance) | Cannot determine input from output |
| Puzzle-friendly | Difficult to find input that gives a predefined output |
| Deterministic | Same input always gives the same output |
| Avalanche effect | A tiny input change drastically changes the output |

**Common Hashing Algorithms:**

- MD4, MD5 (Ron Rivest, 1990/1994) — deprecated
- SHA-0, SHA-1 (NSA, 1993/1995) — deprecated
- RIPEMD-160 (1996)
- SHA-2 family: SHA-224, SHA-256, SHA-384, SHA-512 (2002)
- SHA-3

### 7.4 SHA-256 — Backbone of Blockchain Security

Secure Hash Algorithm 256-bit; developed by NSA.

**Key features:**

- Fixed 256-bit (64-character hex) output
- Deterministic — same input, same output
- Irreversible — cannot reverse-engineer input
- Collision resistant — 2²⁵⁶ possibilities
- Avalanche effect — small change → completely different hash
- **Double SHA-256** used in Bitcoin (hash applied twice)

**SHA-256 Steps:**

1. **Padding Bits** — Append `1` then `0`s until length ≡ 448 (mod 512)
2. **Padding Length** — Append 64-bit representation of original message length
3. **Initialise Buffers** — 8 × 32-bit buffers (H0–H7) from square-root primes
4. **Compression Functions** — 64 rounds of bitwise ops per 512-bit block
5. **Output** — Concatenate final H0–H7 values → 256-bit hash

**Role of SHA-256 in Blockchain:**

- **Data Integrity** — Detects any tampering in transactions
- **Block Hashing** — Each block has a unique hash of its contents
- **Linking Blocks** — Previous block's hash is included in the next block
- **Proof of Work** — Miners find a nonce so that SHA-256(block) < target

### 7.5 Digital Signatures

A digital signature is a mathematical scheme to authenticate the sender of an electronic document, providing **Authenticity + Integrity + Non-repudiation**.

**Process:**

1. Sender hashes the message.
2. Sender encrypts the hash with their **private key** → digital signature.
3. Sender sends: (message + digital signature).
4. Receiver decrypts the signature with sender's **public key** → gets the original hash.
5. Receiver independently hashes the received message.
6. If hashes match → message is authentic and unaltered.

**Importance in Blockchain:**

| Benefit | Description |
|---------|-------------|
| Enhanced Security | Only rightful owner can initiate a transaction |
| Authentication | Verifies data hasn't been tampered with |
| Non-Repudiation | Sender cannot deny involvement; signature is immutable |
| Efficiency | Eliminates need for intermediaries in verification |
| Decentralisation | No centralised authority needed to validate |

---

## 8. Blockchain Data Structures

### 8.1 The Two Core Data Structures

Blockchain is a combination of two hash-based data structures:

1. **Linked List (of Blocks)** — Each block contains a hash pointer to the previous block instead of a regular pointer.
2. **Merkle Tree** — A binary tree of hash pointers inside each block, used to efficiently represent all transactions.

### 8.2 Block Structure

| Field | Description |
|-------|-------------|
| **Block Header** | Technical metadata |
| Block Height | Sequential block number (unique) |
| Timestamp | Unix time when block was added |
| Previous Block Hash | Hash of the previous block (creates the "chain") |
| Nonce | Number miners adjust to solve the PoW puzzle |
| MerkleRoot Hash | Hash of all transactions in the block |
| **Block Body** | All transaction data stored in the block |

**Block Header** distinguishes each block uniquely on the network.

**Block Body** contains the actual transactional data and takes the most space.

### 8.3 Merkle Trees

A Merkle tree is a binary tree formed by hash pointers, named after its creator **Ralph Merkle**. It is a hierarchical data structure that organises transactions in a tree format using cryptographic hashes.

**Components:**

| Component | Description |
|-----------|-------------|
| Leaf Nodes | Hashes of individual transactions (H(Tx1), H(Tx2), ...) |
| Intermediate Nodes | Hash of concatenated child node hashes |
| Merkle Root | Single hash representing the entire dataset |

**How It Works:**

1. Hash each transaction: `H(T1)`, `H(T2)`, `H(T3)`, `H(T4)`
2. Combine adjacent hashes: `H(T1+T2) = H(H(T1) || H(T2))`
3. Repeat until single root hash remains.

```
         [Merkle Root]
              /   \
          [H12]   [H34]
          /  \    /  \
       [H1] [H2] [H3] [H4]
        T1   T2   T3   T4
```

**Proof of Membership (Merkle Proof):**

To prove transaction `T1` is in the block, you only need:

- `H(T2)` and `H(H34)` — a logarithmically small number of hashes.
- Recompute: `H(H(T1) || H(T2))` → `H(that || H34)` → compare with stored Merkle Root.

**Why Merkle Trees Are Important:**

| Property | Benefit |
|----------|---------|
| Data Integrity | Any change in one transaction changes the Merkle Root |
| Efficient Verification | Verify a transaction without downloading entire blockchain |
| Scalability | Handles large numbers of transactions efficiently |
| Proof of Inclusion | Enables lightweight SPV verification |

### 8.4 Commitments in Blockchain

Commitments allow a participant to "commit" to a value while keeping it hidden, but ensuring the value cannot be changed later.

**Key Properties:**

1. **Hiding** — The value remains hidden until revealed.
2. **Binding** — The value cannot be changed after commitment.

**Two Phases:**

1. **Commit Phase:** `C = Commit(x, r)` where `r` is random — publish `C` without revealing `x`
2. **Reveal Phase:** Reveal `x` and `r` — anyone verifies `C = Commit(x, r)`

**Types:**

- **Hash-Based:** `C = Hash(x || r)` using SHA-256
- **Pedersen Commitments (Homomorphic):** Allows arithmetic on commitments (used in Confidential Transactions — Monero, MimbleWimble)

**Use Cases:**

- **Commit-Reveal Schemes** — Fair voting/bidding (prevents cheating)
- **Merkle Trees** — The Merkle Root is a commitment to all transactions
- **Confidential Transactions** — Hide amounts while allowing verification

---

## 9. Blockchain Layers Architecture

```
Layer 3 | User Interface (Web3)
Layer 2 | Application Layer (Solidity, MOVE, RUST, etc.)
Layer 1.5 | Compute Layer
Layer 1 | Consensus Layer
```

### Consensus Layer

Ensures all nodes in the decentralised network agree on the state of the blockchain. Functions:

- **Agreement on a Single Truth** — all nodes agree on the same blockchain version
- **Validation** — confirms transactions are valid; prevents double-spending
- **Decentralisation** — no central authority needed
- **Security** — resists manipulation attempts

### Compute Layer

Responsible for processing computations, executing smart contracts, and performing complex logic for dApps. Particularly crucial for Ethereum. Functions:

- Smart contract execution
- dApp logic processing
- State management
- Gas measurement and resource management
- Validation of computations

### Application Layer

Topmost layer where end-user applications interact with the blockchain. Provides interfaces for wallets, dApps, and DeFi solutions. Functions:

- User interaction
- Smart contract interaction
- Access to blockchain services
- Data presentation and visualisation

---

## 10. Key Features of Blockchain

| Feature | Description |
|---------|-------------|
| **Anonymity** | Addresses instead of identities (pseudonymous) |
| **Immutability** | Records cannot be altered once confirmed |
| **Transparency** | All transactions visible to network participants |
| **Peer to Peer** | Direct interactions without intermediaries |
| **Distributed & Decentralised** | No single point of control or failure |
| **Logical Computation** | Smart contracts automate rule-based operations |

---

## 11. Ownership in Blockchain

Ownership = ability to control and prove access to digital/physical assets recorded on the blockchain. Achieved through **cryptographic mechanisms**.

**Three Elements of Ownership:**

1. Identification of the owner
2. Identification of the object being owned
3. A mapping of the owner to the object

**Key Features:**

| Feature | Description |
|---------|-------------|
| Decentralised Control | No intermediaries; users control assets directly |
| Cryptographic Proof | Private key = proof of ownership; Public key = identity on blockchain |
| Immutability | Ownership records cannot be altered |
| Transparency | Ownership history visible and verifiable |
| Programmability | Smart contracts automate ownership transfers |

---

## 12. Applications of Blockchain

| Domain | Platform | Use |
|--------|----------|-----|
| Cryptocurrencies | Bitcoin, Ethereum, Litecoin | Digital currency transactions |
| Smart Contracts | Ethereum, Cardano, Hyperledger | Automate agreements |
| Supply Chain | IBM Food Trust, VeChain | Transparency, traceability |
| Healthcare | Medicalchain, Patientory | Secure patient data |
| DeFi | Uniswap, Aave, Compound | P2P lending, borrowing, trading |
| Real Estate | Various | Tokenised property ownership |
| IoT | Various | Device identity and data integrity |

**Other Applications:**

- **DApps (Decentralised Applications)** — DeFi, stablecoins, lending, exchanges
- **NFTs (Non-Fungible Tokens)** — Art, game assets, domain names
- **DAOs (Decentralised Autonomous Organisations)** — Investment, governance, charity

---

## 13. Development Platforms

| Platform | Description |
|----------|-------------|
| **Ethereum** | Most widely used; supports smart contracts; Solidity language |
| **Hyperledger Fabric** | Linux Foundation; permissioned; enterprise-grade |
| **IBM Blue Mix** | IBM's blockchain service |
| **Ripple** | Payment-focused; fast cross-border transactions |
| **Multichain** | Creates and deploys private blockchains |

---

## 14. Myths About Blockchain

| Myth | Reality |
|------|---------|
| Blockchain is only about Bitcoin | Blockchain has hundreds of use cases beyond cryptocurrency |
| Blockchain is not ready for business | Hyperledger, Ethereum are production-ready |
| Blockchain solves everything | It's a tool; not universally the best solution |
| Blockchain is a cloud-based database | It's a distributed ledger with specific properties |
| All blockchains are public | Private and consortium types exist |

---

## 15. Why Is Blockchain Expensive?

> "Total computation cost of Bitcoin ecosystem is equivalent to running power in countries like Ireland, New Zealand, or Belgium."

**Root Cause:** To ensure data integrity against malicious entities, massive computational effort (Proof of Work) is required.

- All transactions are recorded and interconnected.
- Everyone in the network gets a copy; each copy is linked to others.
- Solving increasingly difficult math problems ensures immutability.

This is the fundamental trade-off: **security and integrity ↔ computational cost**.

---

## Quick Reference — Key Concepts

| Concept | One-Liner |
|---------|-----------|
| Blockchain | Distributed ledger with cryptographically chained blocks |
| Hash | Fixed-length fingerprint of data; deterministic, one-way |
| Merkle Tree | Binary tree of hashes; enables efficient transaction verification |
| Digital Signature | Cryptographic proof of authenticity and non-repudiation |
| Consensus | Mechanism for all nodes to agree on the ledger state |
| Smart Contract | Self-executing code on blockchain |
| PoW | Miners compete to solve puzzles for the right to add blocks |
| PoS | Validators chosen proportionally by staked cryptocurrency |
| Nonce | Number adjusted by miners to satisfy hash difficulty |
| SPV | Simplified Payment Verification for lightweight nodes |
