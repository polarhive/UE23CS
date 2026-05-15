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

# Unit 2 — The Structure of the Network & Consensus Algorithms

---

## 1. Bitcoin — The First Working Blockchain

### 1.1 Introduction

Bitcoin is the first decentralised digital currency based on blockchain technology. Created by **Satoshi Nakamoto** in 2008 and launched in 2009.

**Key Features:**

- Peer-to-Peer (P2P) transactions — no intermediaries like banks
- Secured using cryptography + consensus mechanism (PoW)
- Every transaction publicly recorded on an immutable ledger

### 1.2 The Genesis Block

- Mined on **3 January 2009** — called **Block 0**.
- Embedded text: *"The Times 03/Jan/2009 Chancellor on brink of second bailout for banks"* — timestamping proof and a philosophical statement about traditional finance.

### 1.3 The Double-Spending Problem (Bitcoin's Core Innovation)

Before Bitcoin, digital money could be copied and spent multiple times (like copying a file). Bitcoin solved this via:

- A **decentralised immutable ledger** that records every spend.
- **Proof of Work** makes retroactive tampering computationally infeasible.
- **Confirmation mechanism** — merchants advised to wait for 6 confirmations (~1 hour) for large transactions.

### 1.4 Terminology: Balances

- The blockchain is a **shared public ledger**.
- All confirmed transactions are included.
- Bitcoin wallets calculate spendable balance from this ledger.
- The **integrity and chronological order** of the chain are enforced by cryptography.

### 1.5 Transactions and Private Keys

- A Bitcoin transaction = transfer of value between wallets, included in the blockchain.
- Wallets store a **private key (seed)** used to sign transactions.
- The signature provides mathematical proof of ownership.
- Once issued, signatures prevent transactions from being altered.
- Transactions broadcast to the network → confirmed in ~10–20 minutes via **mining**.

### 1.6 Step-by-Step Bitcoin Transaction Flow

```
1. Sender Initiates → Signs with private key + specifies recipient address + amount
2. Transaction Broadcast → Propagated to all nodes in the network
3. Validation by Nodes → Check balance; verify signature; place in mempool
4. Mining Process → Miners pick TXs from mempool; solve PoW puzzle; find valid hash
5. Block Verification & Addition → Other nodes verify; block added to chain (immutable)
6. Wallet Update → Sender's wallet deducted; receiver's wallet credited
```

**Sending Payments Example (Alice → Bob):**

1. Bob sends his address to Alice.
2. Alice adds Bob's address + amount to a "transaction" message.
3. Alice signs the transaction with her private key; announces her public key.
4. Alice broadcasts the transaction. Anyone can validate with Alice's public key.

### 1.7 Bitcoin Network Mining

- **Mining** = distributed consensus system to confirm pending transactions.
- Enforces chronological order; protects neutrality of the network.
- Transactions packed in blocks that must satisfy strict cryptographic rules.
- Previous blocks **cannot be modified** — doing so would invalidate all subsequent blocks.
- Mining creates a **competitive lottery** — prevents any individual from easily adding consecutive blocks.

**Miner's Reward (Two types):**

1. **Fixed Block Reward** — Currently **6.25 BTC** per block (halves every ~4 years, ~210,000 blocks).
2. **Transaction Fees** — Miners collect fees from all transactions in their block.

> Note: It's the total fee value that matters, not transaction count. A miner prefers 100 high-fee transactions over 1,000 micro-fee transactions.

### 1.8 Bitcoin Anonymity

Bitcoin offers **pseudonymity**, NOT true anonymity.

- Bitcoin addresses are not directly tied to identities.
- BUT all transactions are recorded on the **public blockchain** → traceable.
- No account setup required; wallets generate public/private keys freely.
- The **bitcoin address** is used for transactions, not user identity.

**Implications:**

- **Advantages:** Financial privacy vs. traditional banking; protects users in restrictive regimes.
- **Challenges:** Pseudonymity can be exploited; transactions traceable via chain analytics.
- **Balance needed:** Privacy vs. KYC/AML regulation to combat money laundering.

### 1.9 Bitcoin Blockchain Structure

```
Block Header:
  - Previous block hash
  - Merkle Root (commitment to transactions)
  - Timestamp
  - Nonce (used for Proof of Work)

Block Body:
  - List of transactions

Chain: Each block linked via previous block hash
```

### 1.10 Block Limits

**Bitcoin:**

- No fixed number of transactions.
- Limited by **block weight** (after SegWit): max **4,000,000 weight units (WU)**.
- Typical range: ~2,000–4,000 transactions per block.
- **SegWit (Segregated Witness):** Protocol upgrade that separates signature data from transaction data, fixing transaction malleability.

**Ethereum:**

- Limited by **gas limit** per block (post-Merge typical: ~30 million gas).
- Gas measures computation, not bytes.
- Simple transfer: ~21,000 gas → ~1,400 simple transfers per block.

### 1.11 Full Block Verification by Nodes

When a miner proposes a block, other nodes perform **full verification** (not just header check):

**Step 1 — Header Verification:**

- **Proof of Work:** Hash(block header) ≤ network difficulty target (starts with leading zeros).
- **Linkage:** Previous block hash matches the last block in their chain.
- **Timestamp:** Block produced within acceptable time range.

**Step 2 — Full Transaction Verification:**

- **Double-Spending Check:** No coins spent twice.
- **Digital Signature Verification:** Sender genuinely authorised the transfer.
- **Input vs. Output Validation:** Total spent ≤ sender's available balance.
- **Merkle Root Verification:** Recompute Merkle Root from all transactions → must match block header's Merkle Root.

> A single invalid transaction causes the **entire block to be rejected**. The miner loses their reward.

### 1.12 Mining Scenarios

**(a) Two or More Correct Miners (Honest Fork):**

- Two honest miners find valid blocks for the same height almost simultaneously.
- Network temporarily splits → **fork**.
- Resolution: **Longest chain rule** (most cumulative proof-of-work wins).
- The shorter chain's block becomes **orphaned (stale)**.

**(b) Simultaneous Mining:**

- Mining is random (hash puzzle); many miners work in parallel.
- Thousands of miners increase the probability of two solving simultaneously.
- Leads to temporary forks, stale blocks, wasted energy.

**(c) Dishonest Mining:**

- **Selfish Mining:** Miner withholds a found block; mines privately to stay ahead; strategically releases chain to orphan honest miners' work. Gains disproportionate rewards.
- **51% Attack:** Attacker controls >50% of hash power → can reorganise blocks, double-spend, censor transactions. Cannot create coins from nothing or steal others' coins directly.

### 1.13 Popular Cryptocurrencies

| Coin | Launch | Consensus | Key Feature |
|------|--------|-----------|-------------|
| Bitcoin (BTC) | 2009 | PoW (SHA-256) | First; digital gold |
| Ethereum (ETH) | 2015 | PoW → PoS (ETH 2.0) | Smart contracts, dApps |
| Litecoin (LTC) | 2011 | PoW (Scrypt) | Faster than Bitcoin |
| Dogecoin (DOGE) | 2013 | PoW | Low-fee payments; meme coin |
| Monero (XMR) | 2014 | PoW | Privacy and anonymity |
| Dash | 2014 | PoW + Masternodes | InstantSend, PrivateSend |

---

## 2. Consensus — The Core Problem

### 2.1 What Is Consensus?

**Consensus** = a general agreement has been reached by all participants.

In Ethereum: reaching consensus means **at least 66%** of the nodes agree on the global state.

**Why Consensus?**

Imagine thousands of servers at a company (like Google or Facebook). Actions recorded in some databases but not others → **inconsistent state**. Distributed consensus protocols solve this fundamental problem.

### 2.2 Three Pillars of Blockchain

```
         Blockchain
        /    |     \
  Distributed  Crypto  Economic
  Systems            Models
```

### 2.3 Consensus in Bitcoin: The Core Problem

```
Node 1    Node 2    Node 3
  [Tx pool]  [Tx pool]  [Tx pool]
     ↓           ↓           ↓
  Which block do we add next?
  Challenge: Miners don't know each other!
```

**Key Observation 1:** Any valid block proposed by a single miner can be accepted.

**Key Observation 2:** The protocol works in rounds — broadcast accepted block; collect next transactions.

**Note:** Communication is asynchronous — no global clock!

### 2.4 Why Consensus Is Hard

| Challenge | Description |
|-----------|-------------|
| Node crashes | Nodes may crash during consensus |
| Malicious nodes | Nodes may behave maliciously |
| Imperfect network | Not all pairs of nodes are connected; faults and latency |
| Asynchrony | No global clock; nodes see blocks in different orders |
| Anonymity | Open network; anyone can propose |
| Monopoly prevention | No single user/group should gain control |
| No fixed TX ordering | Transactions arrive in different orders |
| No fixed TX count per block | Varying number of transactions per block |
| Block size limit | Fixed upper bound on block size |

### 2.5 Distributed Consensus Properties

| Property | Definition |
|----------|-----------|
| **Termination** | Every correct node eventually decides some value |
| **Validity** | If all nodes propose the same value, all correct nodes decide that value |
| **Integrity** | Each correct node decides at most one value; it must have been proposed by some node |
| **Agreement** | Every correct node agrees on the same value |

### 2.6 Safety vs. Liveness

| Property | Meaning |
|----------|---------|
| **Safety** | Nothing bad happens — correct nodes don't agree on wrong value |
| **Liveness** | Something good eventually happens — correct values are eventually accepted |

**In Blockchain:**

- **Safety-1:** The next block must be "correct" (valid transactions, correct hash/nonce)
- **Safety-2:** All miners agree on a single block
- **Liveness:** Add a block as long as it contains valid transactions and moves the chain forward

### 2.7 FLP Impossibility Theorem (1985)

**Fischer, Lynch, Paterson** proved:

> Consensus is **impossible** in a fully asynchronous system even with a **single crash fault**.

Cannot ensure both **Safety** and **Liveness** simultaneously in an asynchronous system.

Nakamoto's PoW prioritises **Liveness** over **Safety** — participants may temporarily agree on a non-final transaction but eventually converge on the correct chain.

### 2.8 Types of Faults

| Fault Type | Description |
|-----------|-------------|
| **Crash Fault** | A node suddenly crashes or becomes unavailable |
| **Network/Partition Fault** | Network gets partitioned; nodes can't communicate |
| **Byzantine Fault** | A node starts behaving maliciously |

---

## 3. Proof of Work (PoW)

### 3.1 History

| Year | Event |
|------|-------|
| 1993 | Cynthia Dwork and Moni Naor introduce PoW concept to deter spam/DoS |
| 1997 | Adam Back develops **Hashcash** (proof-of-work for email spam) |
| 1998 | Wei Dai's b-money; Nick Szabo's Bit Gold propose PoW for currencies |
| 1999 | Term "proof of work" coined by Jakobsson & Juels |
| 2008–2009 | Satoshi Nakamoto implements PoW in Bitcoin using SHA-256 |

### 3.2 What Is PoW?

A software algorithm used to ensure blocks are only valid if they require a certain amount of computational power to produce. Miners commit computer resources to solve complex mathematical problems — creating a **barrier to entry** and **discouraging manipulation**.

**It is a lottery system:** More mining power = higher probability of winning the reward.

### 3.3 The Cryptographic Puzzle

**Given data A, find a number x such that H(A || x) < Target (starts with N leading zeros)**

```
H(Block Data || Previous Hash || Nonce) < Difficulty Target
e.g., 0000000....234...
```

- **Iteration 1:** H(Block, PrevHash, Nonce=1) → No
- **Iteration 2:** H(Block, PrevHash, Nonce=2) → No
- ...
- **Iteration 2,000,007:** H(Block, PrevHash, Nonce=2000007) → YES!
- Other nodes verify using nonce=2000007 (verification is trivial; solving is hard).

**Difficulty Adjustment:**

- Bitcoin recalibrates difficulty every **2,016 blocks** (~2 weeks).
- Target: always ~**10 minutes** average block time.
- As computers get faster, difficulty increases to maintain this target.

### 3.4 How PoW Works (Step by Step)

**Step 1 — Transaction Pool:**

- Transactions submitted by users accumulate in the **mempool**.
- Miners select transactions to create a candidate block.

**Step 2 — Cryptographic Puzzle:**

- Miners race to find a **nonce** such that SHA-256(block data + nonce) produces a hash with enough leading zeros.
- Computationally intensive trial-and-error.

**Step 3 — Proof Submission:**

- First miner to solve broadcasts solution + newly mined block.
- Other nodes verify the solution and check block validity.

**Step 4 — Longest Chain Rule:**

- Valid block is added to the chain.
- If multiple miners solve simultaneously → each works on whichever chain they receive first → chain with most cumulative work wins.

**Step 4b — Mining Rewards:**

- Fixed block reward (currently 6.25 BTC) + transaction fees.
- Incentivises honesty — cheating wastes resources.

**Step 5 — Difficulty Adjustment:**

- Network periodically adjusts the target difficulty.
- Higher difficulty = fewer valid hashes = more computation needed.

### 3.5 Hashcash (PoW Precursor)

Designed to combat email spam. Header contains:

```
X-Hashcash: 1:20:1303030600:adam@cypherspace.org::McMybZIhxKXu57jd:ckvi
Fields: version : bits : date : resource : ext : rand : counter
```

- **bits:** Number of leading zero bits required in the hash
- Requires real computation per email → spammers can't send 10,000 fakes cheaply

### 3.6 PoW Characteristics

| Property | Description |
|----------|-------------|
| Energy-intensive | Significant computational power; environmental concerns |
| Difficulty adjustment | Recalibrates to maintain consistent block time |
| Incentivised honesty | Miners have no incentive to cheat (reward forfeited) |
| Sybil-resistant | Creating fake nodes is expensive |
| Immutability | Altering history requires re-mining all subsequent blocks |

### 3.7 PoW Advantages vs. Disadvantages

| Advantages | Disadvantages |
|-----------|---------------|
| Tested since 2009; proven security | High energy consumption |
| Prevents Sybil attacks | Expensive mining equipment (ASICs) |
| Decentralised — no trusted third party | Slow confirmation times (~10 min) |
| Trustless transactions | 51% attack risk |
| Spam/DoS protection | Mining centralisation (large pools) |
| Immutability | Scalability challenges |

### 3.8 PoW in Blockchain Security

1. **Immutability** — Complex puzzles make altering past transactions nearly impossible.
2. **Sybil Attack Resistance** — Requires significant computational power; impractical to create fake nodes.
3. **Consensus Mechanism** — Miners solve puzzles to agree on valid transactions.

### 3.9 PoW Cryptocurrencies

Bitcoin, Litecoin, Ethereum (original), Monero, Dogecoin.

---

## 4. Proof of Stake (PoS)

### 4.1 What Is PoS?

A consensus mechanism where **validators** are chosen to create new blocks based on the amount of cryptocurrency they **"stake"** (lock up) in the network. Unlike PoW, no energy-intensive mining.

### 4.2 Key Features

| Feature | Description |
|---------|-------------|
| Energy Efficiency | No intensive mining → more eco-friendly |
| Economic Security | Validators risk losing staked funds for malicious behaviour |
| Decentralisation | No specialised hardware (no ASICs) needed |
| Scalability | Faster transaction processing; higher TPS |

**Impact:** Ethereum's transition from PoW to PoS reduced energy consumption by **99.84%**.

### 4.3 How PoS Works (Step by Step)

**Step 1 — Staking:**

- Participants lock up cryptocurrency in a smart contract.
- These are "stakers" or validators.

**Step 2 — Validator Selection:**

- Pseudo-random selection based on:
  - Size of stake
  - Duration of staking (some implementations)
  - Randomisation for fairness

**Step 3–4 — Validation and Block Creation:**

- Selected validator verifies transactions and proposes a new block.
- Stake remains locked until other validators approve ("OK") the block.

**Step 5–6 — Block Addition and Rewards:**

- If majority of validators approve → block added to blockchain.
- **Honest validators** earn staking rewards (new cryptocurrency or transaction fees).
- **Dishonest validators** lose a portion of their stake (**slashing**).

### 4.4 PoW vs. PoS Comparison

| Property | Proof of Stake | Proof of Work |
|----------|---------------|---------------|
| Block creators | Validators | Miners |
| Entry requirement | Own coins/tokens | Buy equipment and energy |
| Energy | Efficient | Not efficient |
| Security | Community control | Expensive upfront cost |
| Rewards | Transaction fees | Block rewards + fees |

### 4.5 Nothing-at-Stake Problem

**Problem:** In PoS, validating a block is cheap. Validators may sign multiple conflicting chains (forks) simultaneously because there's no penalty for doing so → weakens consensus.

**Consequences:**

- Multiple forks
- Susceptibility to double-spending attacks
- Reduced trust

**Solutions:**

1. **Slashing Mechanisms** — Validators lose stake for validating conflicting blocks.
2. **Finality Protocols** — Lock blocks (e.g., Ethereum 2.0); prevent forks.
3. **Economic Incentives** — Rewards only on the correct chain.

### 4.6 Examples of PoS Blockchains

| Blockchain | PoS Protocol | Notes |
|-----------|-------------|-------|
| Ethereum 2.0 | Standard PoS | Transitioned from PoW |
| Cardano | Ouroboros (unique PoS) | Formally verified |
| Polkadot | Nominated PoS (NPoS) | Staking + governance |
| Solana | PoS + PoH | High-speed transactions |

---

## 5. Delegated Proof of Stake (DPoS)

### 5.1 What Is DPoS?

Builds on PoS by introducing **delegated governance**. Token holders vote for a small group of **delegates** (validators/witnesses) who validate transactions and maintain the network.

### 5.2 How DPoS Works

1. **Token Holder Voting** — Voting power proportional to cryptocurrency held.
2. **Delegate Selection** — Fixed number of delegates chosen (e.g., 21 in EOS).
3. **Validation** — Delegates take turns producing blocks in round-robin fashion.
4. **Rewards** — Delegates earn rewards; may share with voters who supported them.
5. **Accountability** — Delegates can be voted out for poor performance or malicious behaviour.

### 5.3 Benefits and Challenges

| Benefits | Challenges |
|---------|-----------|
| High scalability (fewer validators) | Centralisation risk (small delegate group) |
| Energy efficient | Voter apathy (low participation → collusion) |
| Decentralised governance | Delegate collusion to maintain control |

---

## 6. Other Consensus Mechanisms

### 6.1 Proof of Authority (PoA)

**Definition:** A consensus algorithm where a small set of **trusted, pre-approved validators** (authorities) create blocks. Relies on the identity and reputation of validators rather than computational effort or stake.

**Coined by Gavin Wood (Ethereum co-founder) in 2017.**

**How It Works:**

1. Validators chosen based on trustworthiness (known entities).
2. Validators take turns proposing and validating blocks.
3. Identities are public → validators held accountable.
4. Operates in **permissioned blockchains**.

**Key Features:**

| Feature | Description |
|---------|-------------|
| Identity-Based Trust | Pre-approved, verifiable validators |
| Energy Efficiency | No intensive tasks |
| High Throughput | Fewer validators → faster block production |
| Centralised Decentralisation | More centralised than PoW/PoS |

**Limitations:**

- Not preferred for public/permissionless blockchains.
- Less decentralised.
- Susceptible to corruption and manipulation.
- Account balances are predictable → less secure in public settings.

**Use Cases:**

- Private/consortium blockchains (supply chain, logistics).
- Blockchain testnets (e.g., Ethereum's Kovan testnet).

---

### 6.2 Proof of Elapsed Time (PoET)

Designed for **permissioned blockchain networks**. Assigns block creation rights based on a **random wait time** from trusted hardware.

**How It Works:**

1. Each node requests a randomly assigned wait time from **Intel SGX** (trusted hardware).
2. Node with **shortest wait time** creates the next block.
3. Nodes must remain idle during their wait time.
4. Trusted hardware verifies the authenticity of wait times.
5. Other nodes verify before adding block.

**Key Features:**

- **Fairness** — Randomised wait times; equal opportunity
- **Energy Efficiency** — No resource-intensive computation
- **Security via Trusted Hardware** — Hardware-backed randomness

**Challenges:**

- Relies on specific hardware (Intel SGX) → centralisation risk
- Hardware vulnerabilities could compromise the network
- Permissioned only → limited applicability

---

### 6.3 Proof of Space (PoSpace / PoC)

Participants prove they allocate **unused disk space** instead of computational power.

**How It Works:**

1. Participants pre-store specific cryptographic data on their drives ("plotting").
2. Network sends challenges; miners respond using pre-stored data.
3. Network verifies proof → assigns rewards.

**Advantages:** Energy efficient; lower barrier to entry; eco-friendly.

**Challenges:** Storage optimisation; computationally intensive initial plotting; scalability.

---

### 6.4 Proof of Burn (PoB)

Participants **permanently destroy** (burn) cryptocurrency as proof of commitment to earn mining rights.

**Proposed by Iain Stewart** as a sustainable PoW alternative.

**How It Works:**

1. Send tokens to an irretrievable "burn address" → permanently unusable.
2. Earn mining power proportional to tokens burned.
3. Network verifies the burn transaction.

**Types:**

- Burning native tokens
- Burning cross-chain tokens
- Progressive burn (periodic burning to maintain rights)

**Advantages:**

- Greener than PoW
- Reduces token supply → increased scarcity + value
- Long-term commitment signal
- Low barrier to entry compared to PoW (no hardware needed)

**Disadvantages:**

- Perceived economic waste
- Wealthy participants can burn more → centralisation risk
- Barrier for those without sufficient funds

---

## 7. PAXOS Consensus Algorithm

**First consensus algorithm** proposed by L. Lamport in 1989. Objective: Choose a single value under crash or network faults.

### 7.1 Components

| Role | Function |
|------|---------|
| **Proposer** | Proposes values for consensus |
| **Acceptor** | Forms consensus; accepts/rejects proposals |
| **Learner** | Learns which value was chosen |

### 7.2 Two-Phase Protocol

**Phase 1 — Prepare:**

1. Proposer sends `Prepare(n)` where `n` = proposal number (largest seen + 1).
2. Acceptors compare received number with current known values.
3. Acceptors respond: accept/decline + highest proposal number seen + already-accepted values.

**Phase 2 — Accept:**

1. Proposer receives majority of positive responses → sends `Accept(n, value)`.
2. Acceptors accept the value.
3. Each acceptor notifies learners; learner confirms majority-voted value.

### 7.3 Handling Failures

| Failure | Outcome |
|---------|---------|
| Acceptor fails during prepare | No issue if other acceptors can still form majority |
| >N/2-1 acceptors fail | System halts; no value can be accepted |
| Proposer fails during prepare | Other proposer eventually takes over |
| Proposer fails during accept | Acceptors have already decided accept/reject |
| Dueling Proposers | Use leader election to select one proposer (PAXOS can be used for this!) |

**Limitation:** Can lead to livelock with dueling proposers → use RAFT instead.

---

## 8. RAFT Consensus Algorithm

**Developed by Diego Ongaro and John Ousterhout (Stanford University, 2014)**. Designed as an **understandable** alternative to PAXOS for managing replicated logs in distributed systems.

### 8.1 Key Roles

| Role | Function |
|------|---------|
| **Leader** | Manages log replication; handles client requests |
| **Follower** | Responds to requests from the leader |
| **Candidate** | Initiates leader election when leader is suspected dead |

### 8.2 Leader Election

1. Followers wait for **election timeout** (random duration).
2. First follower to time out becomes a **Candidate**.
3. Candidate votes for itself + sends `RequestVote` messages.
4. If majority votes received → becomes **Leader**.
5. Leader sends **heartbeat messages** to maintain status.
6. If followers don't receive heartbeat within timeout → new election starts.

### 8.3 Log Replication (2-Phase Commit)

1. **Client** sends change to leader.
2. **Leader** appends change to its log.
3. **Leader** sends `AppendEntries` to followers on next heartbeat.
4. **Entry committed** once majority of followers acknowledge → response sent to client.

### 8.4 Handling Multiple Leader Candidates

- Two candidates with same term → one gets majority first.
- Winner sends heartbeat → other candidate drops to follower.
- Old leader recovers → receives heartbeat with greater term → drops to follower.

### 8.5 Phases of RAFT

1. **Leader Election** — Ensures single leader controls the log.
2. **Log Replication** — Propagates log entries to followers.
3. **Commitment** — Confirms log entries once replicated by majority.
4. **Crash Recovery** — Restores system after failures.

### 8.6 Fault Tolerance

- Handles failure of up to **N/2 - 1** nodes.

### 8.7 Advantages vs. Limitations

| Advantages | Limitations |
|-----------|------------|
| Easier to understand than PAXOS | Leader dependency → bottleneck if leader fails frequently |
| Fault tolerant (up to N/2-1 failures) | Performance degrades as node count grows |
| Deterministic; avoids forks | Not Byzantine Fault Tolerant (only crash faults) |
| Efficient for small-medium networks | |

---

## 9. Byzantine Fault Tolerance (BFT)

### 9.1 Byzantine Generals Problem

Classic thought experiment: Byzantine army generals must coordinate attack/retreat. Some generals (messengers) may be traitors sending conflicting messages. How can loyal generals reach consensus despite traitors?

**Key Rules:**

- N generals; at most f faulty.
- Receiver always knows sender's identity.
- Fully connected; reliable communication (synchronous).
- If system has **2f+1 lieutenant nodes + 1 commander**, consensus can be achieved with ≤ f faulty nodes.

**Three Byzantine Generals (1 faulty) → NO solution possible.**

**Four Byzantine Generals (1 faulty) → Majority voting solves it.**

### 9.2 Lamport-Shostak-Pease Algorithm

**General Case:** `Broadcast(N, t)` where t = fault tolerance parameter.

- Commander sends message to all lieutenants.
- Each lieutenant broadcasts received message to all others: `Broadcast(N-1, t-1)`.
- Base case (t=0): Each node decides based on sender matching.

Requires **3f+1 total nodes** to tolerate **f Byzantine faults**.

### 9.3 Byzantine Fault Tolerance Definition

> When two-thirds of the network can agree and the system continues to operate properly, it is said to have **Byzantine Fault Tolerance (BFT)**.

BFT = ability of a distributed system to continue operating correctly even when some nodes behave maliciously (arbitrarily, not just crash).

**BFT in popular protocols:**

- PoW, PoS, PoA all have some BFT characteristics.

---

## 10. Practical Byzantine Fault Tolerance (PBFT)

**Castro and Liskov (1999).** Ensures safety over an asynchronous network (not liveness!).

### 10.1 Model

- Asynchronous distributed system (delayed/out-of-order messages).
- Byzantine failure handling (arbitrary node behaviour).
- Privacy via tamper-proof messages and authentication.
- A **state machine** replicated across different nodes.
- **3f+1 replicas** to tolerate **f faulty replicas**.
- Replicas move through **views** (configurations); one is **primary**, others are **backups**.
- Views change when primary is detected as faulty.

### 10.2 PBFT Protocol Flow

```
1. Client → Request to PRIMARY
2. PRIMARY → Multicasts request to all BACKUPS (Pre-prepare)
3. BACKUPS execute request → send reply to client
4. Client waits for f+1 identical replies from different replicas
```

**Three phases:** Pre-prepare → Prepare → Commit

### 10.3 Limitations of PBFT

| Limitation | Description |
|-----------|------------|
| **Sybil Attacks** | One entity controls many identities → harder to mitigate as network grows |
| **Scalability** | Communication overhead with ALL other nodes at each step → doesn't scale well |

### 10.4 Real Applications of PBFT

- **Tendermint** (Cosmos ecosystem)
- **IBM Openchain**
- **ErisDB**
- **Hyperledger Fabric**

---

## 11. Choosing the Right Consensus Protocol

| Factor | Consideration |
|--------|--------------|
| Block write speed | How fast do blocks need to be added? |
| Network type | Public (permissionless) or private (permissioned)? |
| Number of nodes | More nodes → PoW/PoS; fewer → PBFT/RAFT |
| Finality requirements | How "final" does a block need to be? |
| Trust level | How much do you trust the nodes/operators? |

**Permissioned Blockchains:** PBFT and variants (based on decentralisation needed + participant trust).

**Permissionless Blockchains:** PoW, PoET (open network; anonymous participants; must prevent monopoly).

### Permissionless Consensus Challenges

| Challenge | Description |
|-----------|------------|
| Open network | Anyone can join and initiate transactions |
| Anonymous participants | Cannot use direct message passing |
| Anyone can propose a block | Who gets to add the next block? |
| Asynchronous network | No global clock; nodes see blocks in different orders |
| Prevent monopoly | No single user/group should gain control |

---

## 12. Summary Comparison of Consensus Algorithms

| Mechanism | Energy | Speed | Decentralisation | Used In |
|-----------|--------|-------|-----------------|---------|
| PoW | Very High | Slow | High | Bitcoin, Litecoin |
| PoS | Low | Fast | High | Ethereum 2.0, Cardano |
| DPoS | Low | Very Fast | Medium | EOS, TRON |
| PoA | Very Low | Very Fast | Low | Private chains, testnets |
| PoET | Very Low | Fast | Medium | Hyperledger Sawtooth |
| PoSpace | Low | Fast | High | Chia |
| PoB | Low | Moderate | Medium | Slimcoin |
| RAFT | N/A | Fast | Low | Hyperledger |
| PBFT | N/A | Fast | Low | Hyperledger Fabric |

---

## Quick Reference

| Term | Definition |
|------|-----------|
| Mempool | Pool of unconfirmed transactions waiting to be mined |
| Nonce | Number adjusted by miners to find a valid block hash |
| Orphaned Block | A valid block not included in the main chain (longest chain wins) |
| Selfish Mining | Withholding a found block to gain unfair mining advantage |
| 51% Attack | Controlling >50% of hash power to rewrite blockchain history |
| Slashing | Penalty for validators who behave dishonestly in PoS |
| Gas | Unit measuring computational effort in Ethereum |
| SegWit | Bitcoin upgrade separating signature from transaction data; fixes malleability |
| BFT | Ability to function correctly despite Byzantine (malicious) node failures |
| FLP Impossibility | Consensus impossible in asynchronous systems with even 1 crash fault |

# Unit 3 — Second-Generation Applications of Blockchain Technology

---

## 1. Second-Generation Blockchain

### 1.1 Overview

**Second-generation blockchain** is an evolution of original blockchain technology (which primarily focused on peer-to-peer transactions/currency). It extends first-generation capabilities by introducing **programmability through smart contracts**.

**Key Shift:**

- First generation (Blockchain 1.0) → **Currency** (Bitcoin)
- Second generation (Blockchain 2.0) → **Smart Contracts + Programmable Logic** (Ethereum)

### 1.2 Key Characteristics

| Feature | Description |
|---------|-------------|
| **Programmability** | Built on platforms like Ethereum, BSC, Cardano |
| **Diverse Use Cases** | DApps, NFTs, utility tokens, governance tokens |
| **Interoperability** | Interact with DeFi protocols and other blockchain ecosystems |

---

## 2. Smart Contracts

### 2.1 What Are Smart Contracts?

> **Smart contracts** are digital contracts stored on a blockchain that are automatically executed when predetermined terms and conditions are met.

- Terms of agreement written directly into lines of code.
- Execute and enforce themselves when predefined conditions are met.
- **Eliminate need for intermediaries** → enhanced security, transparency, efficiency.
- Core building blocks of **Web3** → powers dApps.

### 2.2 Core Functions

Two basic operations of every smart contract:

1. **Transfer** of digital assets/cryptocurrency from one entity to another when conditions are met.
2. **Penalise** a party for not following through with predetermined terms.

### 2.3 History of Smart Contracts

| Year | Event |
|------|-------|
| 1994 | Nick Szabo first conceptualises "smart contracts" |
| 2008 | Blockchain technology emerges (Bitcoin) |
| 2015 | Ethereum launches with native smart contract support |
| Present | DeFi, NFTs, DAOs all powered by smart contracts |

### 2.4 Key Features

| Feature | Description |
|---------|-------------|
| **Self-Executing** | Automatically execute when coded conditions are satisfied |
| **Immutable** | Once deployed, code cannot be altered |
| **Transparent** | Contract logic visible to all participants |
| **Decentralised** | Execution managed by the blockchain network; no central authority |

### 2.5 Vending Machine Analogy

Smart contracts work like a vending machine:

- Insert coins (payment) + select item (condition).
- Machine automatically dispenses item (execution) without a cashier.
- No intermediary needed; rules are encoded in the machine.

### 2.6 Types of Smart Contracts

**Based on Information Required:**

| Type | Description |
|------|-------------|
| **Deterministic** | Outcome can be determined solely from the contract's code and blockchain data |
| **Non-Deterministic** | Requires external data (via oracles) to determine outcome |

**Based on Applications:**

| Type | Description |
|------|-------------|
| **Smart Legal Contracts** | Legally binding digital agreements |
| **Decentralised Autonomous Organizations (DAOs)** | Governance and collective decision-making |
| **Application Logic Contracts** | Specific app functionality and business logic |

### 2.7 Example — Alice and Bob Smart Contract (Apartment Rental)

```
Terms set in contract:
1. Independent storage created; both Alice and Bob can deposit but not easily withdraw.
2. Bob deposits rent money into storage.
3. Alice puts apartment address and entry code in storage.
4. Alice gets payment confirmation; Bob receives address and code.
5. IF Bob arrives and Alice's address/code are correct → Alice receives payment.
6. IF Alice's address/code are wrong → Bob gets his money back.
7. IF Bob doesn't arrive → Alice gets liquidated damages; Bob gets remainder.
8. Contract fulfilled → remains stored on blockchain permanently.
```

### 2.8 Real-World Use Cases

| Domain | Application |
|--------|-------------|
| Finance | Automated loan disbursement and repayment |
| Insurance | Automatic claim processing based on verified events |
| Real Estate | Tokenised property transfer |
| Supply Chain | Automated payment release upon delivery confirmation |
| Healthcare | Patient consent and data sharing |
| Voting | Tamper-proof digital voting |

### 2.9 Advantages of Smart Contracts

| Advantage | Description |
|-----------|-------------|
| **Cost-Effective** | Fewer intermediaries needed |
| **Speed** | Automates processes, reducing delays |
| **Security** | Cryptographic protection |
| **Accuracy** | Eliminates human errors |

### 2.10 Challenges of Smart Contracts

| Challenge | Description |
|-----------|-------------|
| **Code Vulnerabilities** | Bugs in code can be exploited |
| **Irreversibility** | Mistakes cannot be undone once deployed |
| **Scalability** | Network congestion issues |
| **Legal Ambiguity** | Not aligned with existing legal frameworks |
| **Oracle Problem** | External data must be trusted |

### 2.11 Smart Contract Programming Languages

| Language | Platform | Notes |
|----------|---------|-------|
| **Solidity** | Ethereum + EVM-compatible | High-level; contract-oriented; similar to JavaScript/C++ |
| **Vyper** | Ethereum | Simpler, more secure; Python-like syntax |
| **Rust** | Solana, Polkadot | High performance; safety features for non-EVM blockchains |

**EVM = Ethereum Virtual Machine**

### 2.12 Platforms Supporting Smart Contracts

| Platform | Notes |
|---------|-------|
| **Ethereum** | Most widely used; native Solidity language |
| **Hyperledger Fabric** | Linux Foundation; enterprise permissioned blockchain |
| **EOS** | High-performance; scalability + low transaction costs |
| **Cardano** | Formal verification for security |
| **Solana** | High throughput; PoS + PoH |

---

## 3. Ethereum & Solidity

### 3.1 What Is Ethereum?

> **Ethereum** is a decentralised, open-source platform based on blockchain, used to run smart contracts — applications that execute exactly as programmed without possibility of fraud, interference, censorship, or downtime.

- Serves as a platform for ~260,000+ different cryptocurrencies.
- **Ether (ETH)** = cryptocurrency generated by Ethereum miners as reward for computations securing the blockchain.

### 3.2 Ethereum Virtual Machine (EVM)

> **EVM** is the runtime environment for executing smart contracts in Ethereum.

- Provides security and execution of untrusted code on an international network of public nodes.
- Specialised to prevent Denial-of-Service attacks.
- Ensures programs cannot access each other's state.
- Ensures communication without interference.

**Smart contracts** are high-level program codes compiled to **EVM bytecode** and deployed to Ethereum for execution. All transactions are trackable and irreversible.

### 3.3 Why Solidity for Smart Contracts?

| Reason | Description |
|--------|-------------|
| Security Focus | Prioritises safety; crucial for handling valuable assets autonomously |
| Blockchain Integration | Tailored for Ethereum; seamlessly interacts with blockchain infrastructure |
| Decentralised Execution | Deterministic; runs identically across the network |
| Smart Contract Features | Specific features for precise logic and interaction handling |

### 3.4 Solidity Basics

**Variable Types:**

| Type | Description |
|------|-------------|
| **State Variables** | Permanently stored in contract storage |
| **Local Variables** | Present only during function execution; temporary |
| **Global Variables** | Predefined; reveal blockchain/transaction data (e.g., `msg.sender`, `block.timestamp`) |

**State Variable Visibility:**

- `public` — Accessible from anywhere; generates getter function automatically
- `private` — Only accessible within the current contract
- `internal` — Accessible within current + derived contracts
- `external` — Only callable from outside the contract

**Common Global Variables:**

| Variable | Type | Description |
|----------|------|-------------|
| `msg.sender` | address | Address of the account sending the transaction |
| `msg.value` | uint | Amount of Ether sent with transaction |
| `block.timestamp` | uint | Timestamp of current block |
| `block.number` | uint | Number of current block |
| `tx.origin` | address | Address of the original transaction creator |
| `tx.gasprice` | uint | Gas price of current transaction |

**Value Types:**

| Type | Range |
|------|-------|
| `int8` | -128 to +127 |
| `uint8` | 0 to 255 |
| `int256 / uint256` | 256-bit signed/unsigned |
| `bool` | true/false |
| `address` | 20-byte blockchain address |
| `bytes` | Fixed-size byte arrays |

**Reference Types:**

- Arrays (fixed-size and dynamic)
- Strings (UTF-8 encoded, dynamic)
- Structs (custom data types grouping related variables)
- Mappings (key-value pairs; like hash tables)

**State Mutability Specifiers:**

| Specifier | Description |
|-----------|-------------|
| `pure` | No state read or write; only uses input arguments |
| `view` | Read-only; cannot modify state |
| `payable` | Allows Ether transfers |
| (none) | Can read and modify state; costs gas |

### 3.5 Solidity Control Flow & Error Handling

**Control Flow:** `if/else if/else`, `switch`, `for`, `while`, `do while`, `break`, `continue`, `return`

**Error Handling:**

| Mechanism | Gas Refund | Use Case |
|-----------|-----------|---------|
| `assert(condition)` | No (consumes all gas) | Internal invariants; should never fail in correct code |
| `require(condition, "msg")` | Yes (refunds unused) | Input validation; enforcing business rules |
| `revert("msg")` | Yes | Complex conditional error handling |
| Custom Errors | Yes | Gas-efficient custom error types |

### 3.6 Key Solidity Constructs

**Constructor:**

```solidity
constructor() <Access Modifier> {
    // Initialise state variables
}
```

- Executed only once at deployment
- Optional function; customises initial state
- Can be internal (abstract) or public

**Fallback Functions:**

```
send Ether → msg.data empty? → receive() exists? → receive()
                                              → fallback()
             msg.data not empty → fallback()
```

- Automatically executed when no matching function found
- Must be `external`; limited to 2300 gas when called via `transfer()`/`send()`
- Cannot return anything; can be `payable` to accept Ether

**Events:**

- Allow logging information to the blockchain (outside smart contract storage).
- Front-end can subscribe to events via `ethers.js`.

```solidity
event NewTransaction(address sender, uint amount);
emit NewTransaction(msg.sender, 100);
```

**Modifiers for Access Control:**

| Modifier Type | Effect |
|--------------|--------|
| `onlyBy(address)` | Only specified caller can execute function |
| `onlyAfter(uint time)` | Function callable only after specified time |
| `costs(uint amount)` | Caller must provide specified value |

**Ether Units:**

| Unit | Value |
|------|-------|
| 1 Wei | 1 |
| 1 Gwei | 1e9 Wei |
| 1 Ether | 1e18 Wei |

### 3.7 Withdrawal Patterns

**Vulnerable Pattern (Push):**

```
withdraw() → transfer funds to user → update balance
↑ Reentrancy attack possible!
```

**Safe Pattern (Pull over Push):**

```
withdraw() → check balance → deduct balance → then transfer funds
↑ Balance updated BEFORE transfer → reentrancy-proof
```

**Types:**

1. **Simple Withdrawal** — Users call a function; funds transferred to their address.
2. **Pull over Push** — Contract avoids pushing funds; users "pull" their funds.

### 3.8 Function Overloading

Solidity allows multiple functions with the same name but different parameter types:

```solidity
function add(uint a, uint b) → ...
function add(uint a, uint b, uint c) → ...
```

Compiler selects based on argument types; error if no match found.

---

## 4. Second-Generation Tokens

### 4.1 Token Categories in Second Generation

| Token Type | Purpose | Examples |
|-----------|---------|---------|
| **Utility Tokens** | Access to services/features in a dApp ecosystem | BAT (Brave), Golem (GLM) |
| **Governance Tokens** | Voting power over protocol decisions | Uniswap UNI, Compound COMP |
| **Non-Fungible Tokens (NFTs)** | Unique digital assets (art, collectibles, in-game items) | CryptoPunks, Axie Infinity (AXS) |
| **Stablecoins** | Pegged to stable assets to reduce volatility | USDC (USD-backed), DAI (algorithmic) |

### 4.2 Use Cases for Second-Generation Tokens

1. **Decentralised Finance (DeFi):** Lending, borrowing, staking, yield farming (e.g., DAI on Aave).
2. **Gaming and Metaverse:** In-game economies, virtual worlds (e.g., Decentraland MANA for virtual real estate).
3. **Supply Chain:** Tokenise real-world assets (e.g., VeChain VET for logistics).
4. **Identity and Authentication:** Token-based identity management (e.g., Civic CVC).

---

## 5. Decentralised Autonomous Organisations (DAOs)

### 5.1 What Are DAOs?

> A **DAO** is a collectively-owned organisation working towards a shared mission. Blockchain-based rules baked into code define how the organisation works and how funds are spent.

- No CEO, no CFO — the code governs everything.
- Members can collaborate globally without trusting any single leader.
- All decisions, transactions, and processes recorded on the blockchain.

### 5.2 Why DAOs?

Traditional collaborative ventures require trusting your partners. With DAOs:

- You only trust the **DAO's code** — 100% transparent and verifiable.
- No trusted intermediary required.
- Opens global collaboration and coordination.

### 5.3 DAO vs. Traditional Organisation

| Feature | DAO | Traditional Organisation |
|---------|-----|--------------------------|
| Structure | Flat; fully democratised | Usually hierarchical |
| Decision Changes | Voting required from all members | Can be demanded by a single party |
| Vote Outcome | Automatically implemented via smart contract | Manually handled; prone to manipulation |
| Services | Automatically, decentrally distributed | Requires human handling/central automation |
| Transparency | All activity public on blockchain | Activity typically private |

### 5.4 Key Aspects of DAOs

| Aspect | Description |
|--------|-------------|
| **Decentralisation** | Power distributed among members |
| **Autonomy** | Predefined smart contracts automate tasks |
| **Transparency** | All decisions/transactions on blockchain |
| **Token-Based Governance** | Tokens grant voting rights |
| **Borderless** | Global; no geographical restrictions |

### 5.5 DAO Membership Models

- **Token-Based Membership** — Own tokens = voting power.
- **Share-Based Membership** — Shares represent ownership and voting rights.

### 5.6 DAO Examples

- **Charity DAO** — Accept donations globally; vote on causes to fund.
- **Collective Ownership DAO** — Purchase physical/digital assets; members vote on use.
- **Venture/Grants DAO** — Pool capital; vote on ventures to back; repaid money redistributed.

### 5.7 Launching a DAO — Key Steps

1. Define the mission and rules in smart contracts.
2. Deploy contracts on a blockchain.
3. Distribute governance tokens to founding members.
4. Open membership to qualified participants.
5. Execute proposals via voting.

### 5.8 Legality of DAOs

- DAO code does **not** absolve individuals from complying with regulations and laws.
- Seek legal counsel before creating a DAO.
- **Malta** created a legal framework classifying DAOs as "technology arrangements".
- Malta's **Digital Innovation Authority (MDIA)** regulates these.

### 5.9 Pros and Cons

| Pros | Cons |
|------|------|
| Decentralisation of power | Smart contracts can have bugs |
| "Skin in the game" for participants | Trust entirely in the code |
| Community-driven | One mistake can fail the system |
| Transparent accounting | Hard to enforce legal accountability |

### 5.10 Key Takeaways

- All DAO transactions are recorded on its blockchain.
- Code acts as the trusted third party.
- Majority of stakeholders must agree on all decisions.
- Voting windows ensure proposals aren't blocked by nonresponsive members.

---

## 6. Decentralised Applications (dApps)

### 6.1 What Are dApps?

> **dApps** are software programs that run on a **blockchain or P2P network** instead of a single computer.

- Core innovation enabled by blockchain.
- Powered by smart contracts.
- Provide enhanced transparency, security, and user autonomy.

### 6.2 Requirements of dApps

| Requirement | Description |
|-------------|-------------|
| **Open Source** | Codebase publicly accessible; community-driven development |
| **Decentralised** | All data and logic on a public decentralised blockchain |
| **Incentive** | Users rewarded with cryptographic tokens for participation |
| **Protocol** | Follows standardised proof-of-value protocol (PoW, PoS, PoContribution) |

### 6.3 dApps vs. Traditional Apps

| Feature | dApps | Traditional Apps |
|---------|-------|-----------------|
| Architecture | Decentralised; runs on blockchain | Centralised; runs on single server |
| Data Storage | Blockchain / IPFS | Centralised servers |
| Control | Smart contracts + decentralised governance | Central authority/organisation |
| Transparency | Code and transactions public and verifiable | Code proprietary |
| Security | Cryptographic; decentralised | Central server security |
| Scalability | Challenges (Layer 2 solutions emerging) | Cloud computing scales well |
| Authentication | Blockchain wallets (e.g., MetaMask) | Traditional login systems |
| Transaction Costs | Gas fees paid by users | Free to users; costs borne by provider |
| Interoperability | Cross-dApp/blockchain interactions | Within own ecosystem |

### 6.4 Types of dApps

**By Blockchain Leverage:**

| Type | Description | Examples |
|------|-------------|---------|
| Type 1 | dApps on their own blockchain | Bitcoin |
| Type 2 | dApps using Type 1 blockchain protocols | Omni (built on Bitcoin) |
| Type 3 | dApps using Type 2 dApp protocols | SAFE Network |

**By Application:**

- Gaming (CryptoKitties, Z Run)
- Gambling (WINk)
- Tracking (ZapperFi)
- Marketplace (Rarible)
- DeFi (liquidity + exchanges)

### 6.5 Core Components of a dApp

| Component | Description |
|-----------|-------------|
| **Smart Contracts** | Business logic on blockchain; self-executing; automation + transparency + security |
| **Frontend/UI** | HTML/CSS/JS (React); communicates with contracts via Web3.js or Ethers.js; wallet connection (MetaMask) |
| **Backend Infrastructure** | Off-chain data storage; API integration for external data |
| **Data Storage** | On-chain (secure; costly) vs. Off-chain (IPFS, databases; cheaper; scalable) |

### 6.6 Popular dApp Platforms

| Platform | Notes |
|---------|-------|
| Ethereum | Pioneer; most dApps built here |
| Solana | High throughput; low fees |
| Binance Smart Chain (BSC) | Balance of scalability and cost |
| Polkadot | Cross-blockchain interoperability |
| Cardano | Security via formal verification |

### 6.7 Popular dApps

| dApp | Platform | Function |
|------|---------|---------|
| CryptoKitties | Ethereum | Buy/breed/sell virtual cats; once 10% of daily ETH transactions |
| OpenSea | Ethereum | NFT marketplace |
| WINk | TRON | Gambling; rewards in WIN tokens |
| IPSE | EOS | Blockchain-based search engine using IPFS |

### 6.8 Advantages of dApps

| Advantage | Description |
|-----------|-------------|
| Transparency | All transactions visible on blockchain |
| Security | Immutable records prevent unauthorised changes |
| User Control | Users retain ownership of data and assets |
| Global Accessibility | Available to anyone with internet + compatible wallet |

### 6.9 Challenges

| Challenge | Description |
|-----------|-------------|
| Performance Overhead | High computational requirements |
| Maintenance | Hard to debug/update; requires network-wide consensus for changes |
| Scalability | Harder to scale than centralised systems |
| User Experience | Complex key management vs. traditional login |
| Centralisation Risk | User-friendly design may inadvertently centralise |
| Network Congestion | Heavy computation can slow the network |

---

## 7. Hyperledger Fabric Architecture

### 7.1 Overview

**Hyperledger Fabric** is an enterprise-grade, permissioned blockchain developed by the Linux Foundation. It's widely used for private blockchain solutions tailored to enterprise use cases.

### 7.2 Nodes and Roles

| Role | Description |
|------|-------------|
| **Committing Peer** | Maintains ledger and state; commits transactions; may hold chaincode |
| **Endorsing Peer** | Specialised committing peer; receives transaction proposals; grants/denies endorsement; must hold chaincode (smart contract) |
| **Ordering Node** | Approves inclusion of transaction blocks into ledger; communicates with committing and endorsing peers; does NOT hold chaincode or ledger |

### 7.3 Fabric Architecture Components

```
Fabric-CA / External-CA (optional)
        ↓
Membership Services
        ↓
Client Application (SDK/HFC)
        ↓
Endorsers → Ordering Service → Committing Peers → Ledger
```

### 7.4 Hyperledger Fabric Transaction Flow (7 Steps)

**Step 1 — Propose Transaction:**

- Client application submits transaction proposal to required endorsers.
- Endorsement policy specifies which peers must sign (e.g., "E0, E1, and E2 must sign").

**Step 2 — Execute Proposed Transaction:**

- Endorsers each execute the proposed transaction (does NOT update ledger).
- Each execution captures **RW sets** (Read-Write sets) showing what was read and written.

**Step 3 — Proposal Response:**

- Endorsers return signed RW sets to application (asynchronously).
- RW sets include version numbers for record validation.

**Step 4 — Order Transaction:**

- Application submits all responses as a transaction to the **Ordering Service**.
- Ordering happens in parallel with other applications.

**Step 5 — Deliver Transaction:**

- Ordering service packages transactions into blocks and distributes to committing peers.
- Ordering algorithms: **SOLO** (single node; development) or **Kafka** (crash fault tolerant).

**Step 6 — Validate Transaction:**

- Every committing peer validates against **endorsement policy**.
- Also checks RW sets are still valid for current world state.
- Valid transactions → applied to world state AND retained on ledger.
- Invalid transactions → retained on ledger BUT do NOT update world state.

**Step 7 — Notify Transaction:**

- Applications registered for events are notified of transaction success/failure.
- Notified by each peer to which they are connected.

### 7.5 Key Benefits of Fabric Transaction Flow

- Better reflects business processes (specifies who endorses).
- Eliminates non-deterministic transactions.
- Scales the number of participants and transaction throughput.

### 7.6 Channels in Hyperledger Fabric

- Channels provide **privacy** between different ledgers.
- Ledgers exist in scope of a channel.
- Channels can be shared or restricted to specific participants.
- Chaincode is installed on peers and instantiated on specific channels.
- Peers can participate in multiple channels.

**Single Channel Network:** All peers use same ledger, same chaincode.

**Multi-Channel Network:** Different peer groups use different channels for privacy.

### 7.7 Fabric Certificate Authority (Fabric-CA)

- Default Certificate Authority within Fabric network.
- Issues **ECerts** (long-term identity certificates).
- Supports clustering for HA (High Availability).
- Supports LDAP for user authentication.
- Supports HSM (Hardware Security Module) for security.
- Can be configured as an intermediate CA.

### 7.8 Modular Architecture

Hyperledger Fabric features a **pluggable modular architecture**:

- Pluggable consensus (SOLO, Kafka, RAFT)
- Pluggable identity management (Fabric-CA or external)
- Pluggable chaincode (Go, Node.js, Java)
- Pluggable state database (LevelDB, CouchDB)

---

## 8. Future Trends in Blockchain Applications

| Trend | Description |
|-------|-------------|
| **IoT Integration** | Smart contracts interact with devices to automate real-time processes |
| **Improved Security Protocols** | Enhanced auditing tools to minimise smart contract risks |
| **Enterprise Adoption** | Companies using smart contracts for streamlined operations |
| **Cross-chain Interoperability** | Different blockchains communicate and share data |
| **Layer 2 Solutions** | Scaling solutions (e.g., Lightning Network, Optimistic Rollups) |
| **DeFi Evolution** | More sophisticated financial instruments on blockchain |
| **NFT Utility** | Beyond digital art → identity, certifications, real-world assets |

---

## Quick Reference

| Term | Definition |
|------|-----------|
| Smart Contract | Self-executing code on blockchain; auto-executes when conditions met |
| Solidity | Main programming language for Ethereum smart contracts |
| EVM | Ethereum Virtual Machine; runtime for executing smart contracts |
| DAO | Collectively-owned organisation governed by smart contract rules |
| dApp | Decentralised application running on blockchain/P2P network |
| NFT | Non-fungible token; unique, indivisible digital asset |
| Stablecoin | Token pegged to stable asset (e.g., USD) to reduce volatility |
| DeFi | Decentralised Finance; financial services without intermediaries |
| Hyperledger Fabric | Enterprise permissioned blockchain by Linux Foundation |
| Chaincode | Smart contract in Hyperledger Fabric terminology |
| Endorsement Policy | Rules specifying which peers must approve a Fabric transaction |
| RW Set | Read-Write set capturing what a transaction read/wrote |
| Gas | Unit measuring computation cost in Ethereum |
| Mempool | Pool of unconfirmed transactions |
| IPFS | InterPlanetary File System; decentralised file storage |
| Reentrancy | Attack exploiting external calls before state is updated |
| Pull over Push | Safer withdrawal pattern where users claim funds rather than receiving pushed funds |

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
