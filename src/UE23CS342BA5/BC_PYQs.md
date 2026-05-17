# Blockchain — Previous Year Questions (PYQ) Master File

| Paper     | Course Code | Date                |
| --------- | ----------- | ------------------- |
| qp1       | UE20CS335   | ESA May 2023        |
| qp2       | UE18CS324   | ESA Dec 2021        |
| qp3       | UE18CS324   | ESA Dec 2020        |
| qp4       | UE17CS414   | ESA Dec 2020        |
| qp5       | UE18CS324   | ISA Test-1 Oct 2020 |
| qp6       | UE20CS335   | ESA Jul 2023        |
| UE19CS335 | UE19CS335   | ESA Jan–May 2022    |

---

## Table of Contents

1. [Blockchain Fundamentals & Introduction](#1-blockchain-fundamentals--introduction)
2. [Cryptography — Hash Functions, RSA, Digital Signatures, Merkle Trees](#2-cryptography)
3. [Consensus Algorithms](#3-consensus-algorithms)
4. [Smart Contracts, dApps & DAOs](#4-smart-contracts-dapps--daos)
5. [Hyperledger Fabric](#5-hyperledger-fabric)
6. [Blockchain Security](#6-blockchain-security)

---

# 1. Blockchain Fundamentals & Introduction

---

## Q1.1 — What is blockchain? What is the need for blockchain technology? Explain its working with a neat diagram. *(qp6, qp2, qp5)*

**Answer:**

**Definition:** A blockchain is a decentralised, distributed digital ledger that records transactions across many computers in such a way that the registered transactions cannot be altered retroactively. It is a chain of blocks, each containing data, linked together using cryptographic hashes.

**Three-part technical definition:**

1. Permits transactions to be gathered into blocks and recorded.
2. Cryptographically chains blocks in chronological order.
3. Allows the resulting ledger to be accessed by all nodes in the network.

**Need for Blockchain:**

- Eliminates the need for a trusted central authority (banks, governments).
- Solves the double-spending problem for digital assets.
- Provides immutability — records cannot be tampered with.
- Enables transparent, auditable transactions.
- Reduces operational costs by removing intermediaries.
- Enables trust between unknown parties.

**Working of Blockchain:**

```
Step 1: User initiates a transaction (e.g., Alice sends 1 BTC to Bob)
         ↓
Step 2: Transaction is broadcast to all nodes in the P2P network
         ↓
Step 3: Network of nodes validates the transaction using cryptographic algorithms
         ↓
Step 4: Verified transaction is combined with other transactions to form a new block
         ↓
Step 5: New block is added to the existing chain (after PoW/PoS)
         ↓
Step 6: Transaction is complete and permanently recorded
```

```
[Block 0 - Genesis]  ←  [Block 1]  ←  [Block 2]  ←  [Block N]
|  PrevHash: 000  |     |PrevHash  |   |PrevHash  |   |PrevHash  |
|  MerkleRoot     |     |MerkleRoot|   |MerkleRoot|   |MerkleRoot|
|  Nonce          |     |Nonce     |   |Nonce     |   |Nonce     |
|  Transactions   |     |Tx data   |   |Tx data   |   |Tx data   |
```

---

## Q1.2 — Can blockchain be used for any application? Give some myths common with respect to blockchain. *(UE19CS335)*

**Answer:**

**Can blockchain be used for any application?**

No. Blockchain is NOT a universal solution. It is best suited for scenarios where:

- Multiple parties need to share data without a trusted central authority.
- Immutability of records is critical.
- Transactions require transparency and auditability.
- There is a need to eliminate intermediaries.

Blockchain is **NOT needed** when:

- A single party controls all data (centralised DB is cheaper and faster).
- Data does not need to be shared across organisations.
- High transaction speed is critical (blockchain is slower than traditional databases).
- Privacy of all data is required (public blockchain is transparent).

**Common Myths:**

| Myth | Reality |
|------|---------|
| Blockchain is only about Bitcoin | Blockchain has hundreds of use cases beyond cryptocurrency |
| Blockchain is not ready for business | Hyperledger Fabric and Ethereum are production-ready |
| Blockchain solves every problem | It's a tool with specific strengths; not universally the best solution |
| All blockchains are public | Private, consortium, and hybrid types also exist |
| Blockchain is a cloud database | It's a distributed ledger with specific cryptographic and consensus properties |
| Blockchain is completely anonymous | Bitcoin is pseudonymous; all transactions are publicly traceable |
| Blockchain data cannot be deleted | In private blockchains, data can sometimes be modified with consensus |

---

## Q1.3 — Give the difference between: (i) Full nodes and lightweight nodes; (ii) Transparency and immutability; (iii) Decentralised and distributed system; (iv) Private and consortium blockchain; (v) Token and coin. *(UE19CS335, qp1)*

**Answer:**

**(i) Full Nodes vs Lightweight Nodes:**

| Property | Full Node | Lightweight (Light) Node |
|----------|-----------|--------------------------|
| Data stored | Entire blockchain history | Only block headers |
| Verification | Independently verifies ALL transactions | Uses SPV (Simplified Payment Verification) |
| Resource requirement | High CPU, storage, bandwidth | Low — suitable for mobile devices |
| Security | Maximum — fully autonomous | Relies on full nodes for verification |
| Example | Bitcoin Core | Mobile Bitcoin wallets |

**(ii) Transparency vs Immutability:**

| Property | Transparency | Immutability |
|----------|-------------|--------------|
| Meaning | All transactions visible to network participants | Once recorded, data cannot be altered |
| Enables | Auditability and accountability | Trust and tamper-proof records |
| In blockchain | Public blockchains expose all transactions | Cryptographic chaining makes retroactive changes infeasible |

**(iii) Decentralised vs Distributed System:**

| Property | Decentralised | Distributed |
|----------|--------------|-------------|
| Control | No single entity controls the network | Workload distributed across multiple nodes |
| Decision making | Collective/consensus-based | May still have central coordination |
| Failure tolerance | Highly resilient — no single point of failure | Varies by design |
| Example | Bitcoin, Ethereum | Content Delivery Networks (CDN) |

**(iv) Private vs Consortium Blockchain:**

| Property | Private Blockchain | Consortium Blockchain |
|----------|-------------------|-----------------------|
| Control | Single organisation | Multiple organisations jointly |
| Access | Invitation only | Pre-selected group of nodes |
| Transparency | Limited | Partially transparent |
| Decentralisation | Low | Moderate |
| Example | Hyperledger Fabric (single org) | R3 Corda, Quorum |

**(v) Token vs Coin:**

| Property | Coin | Token |
|----------|------|-------|
| Blockchain | Has its own native blockchain | Built on an existing blockchain |
| Creation | Created with the blockchain (mining/staking) | Created via smart contracts |
| Use | Digital money, gas fees | Utility, governance, NFTs, etc. |
| Examples | Bitcoin (BTC), Ether (ETH) | USDT (ERC-20), UNI, DAI |

---

## Q1.4 — What are tokens? Discuss any four different types of tokens. *(qp6, qp1)*

**Answer:**

**Definition:** Tokens are digital assets created and managed on a blockchain, representing value, rights, or utility. Unlike coins, they do not have their own blockchain and are built on existing platforms (e.g., ERC-20 on Ethereum).

**Four Types of Tokens:**

**1. Utility Tokens:**

- Provide access to a product or service within a specific blockchain ecosystem.
- Not primarily investment instruments.
- Example: Basic Attention Token (BAT) grants access to Brave browser advertising services; Filecoin (FIL) for decentralised storage.

**2. Governance Tokens:**

- Grant holders voting rights over protocol decisions (e.g., fee changes, upgrades).
- Represent ownership in decentralised protocols.
- Example: Uniswap (UNI) — holders vote on protocol upgrades; Maker (MKR) governs MakerDAO.

**3. Non-Fungible Tokens (NFTs):**

- Unique, indivisible, non-interchangeable digital assets.
- Each token has a unique identifier and metadata.
- Example: Digital art (CryptoPunks), in-game items (Axie Infinity), certifications.

**4. Security Tokens:**

- Represent ownership in a real-world asset (equity, bonds, real estate).
- Subject to securities regulations.
- Example: tokenised shares of a company or fractional real estate ownership.

**5. Stablecoins (bonus):**

- Pegged to stable assets (USD, gold) to reduce price volatility.
- Example: USDC (backed 1:1 by USD), DAI (algorithmic collateral-backed).

---

## Q1.5 — What is the difference between Utility and Governance tokens? *(qp1)*

**Answer:**

| Property | Utility Token | Governance Token |
|----------|--------------|-----------------|
| Purpose | Access to services/features within a dApp | Voting rights over protocol decisions |
| Value driver | Demand for the underlying service | Importance of governance participation |
| Example | BAT (Brave), Filecoin (FIL) | Uniswap UNI, Compound COMP, Maker MKR |
| Can they overlap? | Yes — some tokens serve both purposes | Yes (e.g., UNI provides governance AND utility) |

---

## Q1.6 — What do you mean by Reward Halving in Bitcoin? How is Bitcoin's and Ethereum's rewarding system different? *(qp1)*

**Answer:**

**Reward Halving in Bitcoin:**

- Bitcoin's block reward (given to miners who successfully mine a block) is halved every **210,000 blocks** (approximately every 4 years).
- This is hard-coded into Bitcoin's protocol.
- Timeline: 50 BTC (2009) → 25 BTC (2012) → 12.5 BTC (2016) → 6.25 BTC (2020) → 3.125 BTC (2024).
- Purpose: Controls Bitcoin's total supply (capped at 21 million BTC), creating a deflationary monetary policy.
- After all Bitcoin is mined (~2140), miners will only earn transaction fees.

**Bitcoin vs Ethereum Rewarding System:**

| Property | Bitcoin | Ethereum |
|----------|---------|---------|
| Consensus | Proof of Work (PoW) | Proof of Stake (PoS) — since The Merge (2022) |
| Miners/Validators | Miners (computational work) | Validators (staked ETH) |
| Block reward | Fixed + halves every 4 years | No fixed "block reward" for validators; they earn transaction fees + MEV |
| Supply cap | Hard cap: 21 million BTC | No hard cap — but issuance is controlled + ETH is burned (EIP-1559) |
| Halving | Yes — predictable schedule | No halving — issuance adjusts with protocol |
| Transaction fees | Go entirely to miners | Burned (base fee) + tips go to validators (EIP-1559) |

---

## Q1.7 — How can you identify a block in blockchain? Explain with the structure and content of each block. / Explain blockchain construction with cryptographic functions and structure of a block. *(qp3, qp4, qp5)*

**Answer:**

**Identifying a Block:**

A block is uniquely identified by its **block hash**, which is computed as:

`Block Hash = SHA256(SHA256(Block Header))`

The block header contains the nonce, timestamp, previous block hash, and Merkle root — so even a tiny change in any transaction would produce a completely different block hash.

**Block Structure:**

```
┌─────────────────────────────────────────┐
│              BLOCK HEADER               │
│  Block Height (unique sequential number)│
│  Timestamp (Unix time)                  │
│  Previous Block Hash (links to chain)   │
│  Merkle Root (commitment to all TXs)    │
│  Nonce (used for Proof of Work)         │
│  Difficulty Target                      │
├─────────────────────────────────────────┤
│               BLOCK BODY               │
│  Transaction 1 (Tx1)                    │
│  Transaction 2 (Tx2)                    │
│  ...                                    │
│  Transaction N (TxN)                    │
└─────────────────────────────────────────┘
```

**Cryptographic Functions in Blockchain:**

- **SHA-256**: Hashes each block header to produce the unique block hash.
- **Merkle Root**: SHA-256 applied recursively to all transaction hashes in the block body — any change to any transaction changes the Merkle root and therefore the block hash.
- **ECDSA (Elliptic Curve Digital Signature Algorithm)**: Used to sign and verify transactions.
- **Previous Block Hash**: Cryptographic chaining — change one block and all subsequent hashes become invalid.

---

## Q1.8 — How is a blockchain distributed ledger different from a traditional ledger? *(qp3)*

**Answer:**

| Property | Traditional Ledger | Blockchain Distributed Ledger |
|----------|-------------------|-------------------------------|
| Storage | Centralised — one entity holds the record | Distributed — every node holds a copy |
| Control | Single authority (bank, government) | No central authority — consensus-based |
| Trust | Trust the central authority | Trust the protocol and cryptography |
| Transparency | Typically private/opaque | Transparent — all participants see all records |
| Tampering | Possible by the central authority | Computationally infeasible (cryptographic chaining) |
| Availability | Single point of failure | No SPOF — resilient P2P network |
| Reconciliation | Expensive — parties maintain separate books | No reconciliation needed — shared single truth |
| Audit | Difficult without access | Built-in audit trail — permanent and timestamped |

---

## Q1.9 — What do you mean by soft forks? Given a blockchain, when block Bx has to be inserted, where will it get inserted? What are orphaned blocks? *(UE19CS335)*

**Answer:**

**Soft Fork:**

A soft fork is a backward-compatible change to the blockchain protocol. New rules introduced by the fork are a subset of the old rules — nodes running old software can still validate blocks from upgraded nodes. Example: Bitcoin's SegWit upgrade.

Contrast with **Hard Fork**: Not backward-compatible — creates a permanent chain split (e.g., Bitcoin Cash from Bitcoin).

**Where Bx Gets Inserted:**

In the longest chain rule (Nakamoto consensus), a new block Bx is always appended to the **tip of the longest chain** — i.e., the chain with the most cumulative Proof of Work. When two chains are of equal length, the miner appends to whichever chain they received first; once one becomes longer, all miners switch to it.

**Orphaned Blocks:**

When two miners simultaneously find valid blocks, the network temporarily has two competing chain tips. As new blocks are added, one chain becomes longer and becomes the canonical chain. The blocks on the shorter chain are called **orphaned blocks** (or stale blocks). They are valid blocks but are not part of the main chain — the miner who produced them does not receive the block reward.

---

## Q1.10 — Blockchain application: Hospital replacing traditional system / GST collection / Asset transfer. *(qp2, qp3, qp4, qp5)*

**Answer:**

**Hospital Blockchain Use Case:**

A hospital blockchain replaces centralised EMR (Electronic Medical Record) systems.

**Benefits:**

1. **Data Integrity** — Patient records cannot be tampered with.
2. **Interoperability** — Multiple hospitals, insurers, and pharmacies share verified records.
3. **Privacy Control** — Patients control who accesses their data (smart contracts define access rules).
4. **Fraud Reduction** — Prescription fraud reduced through verified, immutable records.
5. **Audit Trails** — Complete history of record access and modifications.
6. **No SPOF** — Decentralised storage prevents data loss from server failures.

**Recommended Type:** Consortium/Private blockchain (e.g., Hyperledger Fabric) — access restricted to authorised medical institutions.

**GST Collection Blockchain:**

- **Advantages:** (1) Immutable tax records prevent fraud, (2) Real-time visibility to tax authorities, (3) Automated compliance via smart contracts, (4) Reduces human error and manipulation.
- **Disadvantage:** Scalability — tax transactions are extremely high-volume; blockchain performance needs to match traditional databases.

**Asset Transfer (Bank A to Bank D):**

The best model is a **consortium blockchain** (e.g., R3 Corda, Quorum) where participating banks are nodes. The asset transfer path is visible and auditable on-chain, with smart contracts automating settlement. This eliminates intermediary reconciliation costs and provides real-time settlement.

---

## Q1.11 — What is the role of the public ledger and P2P network in blockchain? What is the nonce and how is it used in mining? *(UE19CS335, qp5)*

**Answer:**

**Public Ledger:**

- A shared, decentralised record of all transactions ever made on the blockchain.
- Every confirmed transaction is included and visible to all network participants.
- Ensures there is a single source of truth without a central authority.
- Enables verification of balances and ownership without trust in any party.

**P2P Network:**

- Every node acts simultaneously as both client and server.
- Transactions are broadcast to all nodes — no central routing server.
- Nodes validate, store, and relay blocks and transactions.
- Provides resilience — no SPOF; even if many nodes go offline, the network continues.

**Nonce:**

A nonce ("number used once") is a 32-bit integer field in the block header that miners incrementally adjust when trying to find a valid block hash.

**How used in mining:**

1. Miner assembles a candidate block (transactions + header).
2. Sets nonce = 0, computes SHA256(SHA256(block header)).
3. Checks if result has enough leading zeros (meets difficulty target).
4. If not, increments nonce by 1 and repeats.
5. When a valid hash is found, the block is broadcast to the network.
6. Other nodes verify trivially by computing the hash once with the given nonce.

This trial-and-error process is the Proof of Work computation.

---

# 2. Cryptography

---

## Q2.1 — What is the difference between symmetric and asymmetric key cryptography? Why can't symmetric key cryptography be used in blockchain? *(UE19CS335)*

**Answer:**

**Symmetric Key Cryptography:**

- A single shared secret key is used for both encryption and decryption.
- Both sender and receiver must possess the same key.
- Fast and efficient but requires a secure key exchange mechanism.
- Examples: AES, DES, 3DES.

**Asymmetric Key Cryptography (Public Key Cryptography):**

- Uses a mathematically related pair: **public key** (shared openly) and **private key** (kept secret).
- Data encrypted with the public key can only be decrypted with the private key, and vice versa.
- Eliminates the key exchange problem.
- Examples: RSA, ECDSA, ElGamal.

| Property | Symmetric | Asymmetric |
|----------|-----------|------------|
| Keys | Single shared key | Key pair (public + private) |
| Speed | Fast | Slower |
| Key distribution | Difficult (secure channel needed) | Public key freely shared |
| Authentication | Does not provide | Provides via digital signatures |
| Use | Bulk data encryption | Key exchange, digital signatures |

**Why symmetric key crypto CANNOT be used in blockchain:**

1. **Key Distribution Problem:** In a blockchain with thousands of anonymous nodes, there is no secure channel to share a secret key. Every node would need a shared key with every other node — O(n²) keys for n nodes.
2. **No Authentication:** Symmetric crypto cannot prove who sent a transaction. In blockchain, we need to prove that the private key holder authorised a transaction — this requires asymmetric digital signatures.
3. **No Non-Repudiation:** Symmetric keys cannot provide non-repudiation since either party holds the same key — anyone with the key could forge a message.
4. **Open Network:** Blockchain is a public, permissionless network. Symmetric keys require trust in all participants, which contradicts blockchain's trustless model.

---

## Q2.2 — RSA Encryption — Step-by-step algorithm, key generation, encryption, and decryption. *(qp1, qp2, qp3, qp4, qp5, qp6)*

**Answer — RSA Algorithm Steps:**

1. Choose two large prime numbers **p** and **q**.
2. Compute **n = p × q** (modulus — part of both keys).
3. Compute **φ(n) = (p-1)(q-1)** (Euler's totient function).
4. Choose **e** such that: 1 < e < φ(n) and gcd(e, φ(n)) = 1 (e is coprime to φ(n)).
5. Find **d** such that: **(e × d) ≡ 1 (mod φ(n))** — d is the modular inverse of e.
6. **Public Key = (e, n)** — share this openly.
7. **Private Key = (d, n)** — keep this secret.
8. **Encrypt:** C = M^e mod n
9. **Decrypt:** M = C^d mod n

---

**Worked Example 1 — qp1 (p=11, q=3, M=14):**

- n = 11 × 3 = **33**
- φ(n) = (11-1)(3-1) = 10 × 2 = **20**
- Choose e = 7 (gcd(7,20) = 1 ✓)
- Find d: 7d ≡ 1 (mod 20) → d = 3 (7×3 = 21 ≡ 1 mod 20) → **d = 3**
- **Public Key = (7, 33)**, **Private Key = (3, 33)**
- Encrypt M=14: C = 14^7 mod 33
  - 14^2 = 196; 196 mod 33 = 196 - 5×33 = 196 - 165 = 31
  - 14^4 = 31^2 = 961; 961 mod 33 = 961 - 29×33 = 961 - 957 = 4
  - 14^7 = 14^4 × 14^2 × 14^1 = 4 × 31 × 14 mod 33
  - 4 × 31 = 124; 124 mod 33 = 124 - 3×33 = 124-99 = 25
  - 25 × 14 = 350; 350 mod 33 = 350 - 10×33 = 350-330 = **20**
  - **Ciphertext C = 20**
- Decrypt C=20 at Alice: M = 20^3 mod 33
  - 20^2 = 400; 400 mod 33 = 400 - 12×33 = 400-396 = 4
  - 20^3 = 4 × 20 = 80; 80 mod 33 = 80-2×33 = 80-66 = **14** ✓

---

**Worked Example 2 — qp2/qp3 (p=3, q=11, e=7, M=20):**

- n = 3 × 11 = **33**
- φ(n) = (3-1)(11-1) = 2 × 10 = **20**
- e = 7; Find d: 7d ≡ 1 (mod 20) → **d = 3** (same as above)
- **Public Key = (7, 33)**, **Private Key = (3, 33)**
- Encrypt M=20: C = 20^7 mod 33
  - 20^2 = 400 mod 33 = 4
  - 20^4 = 4^2 = 16
  - 20^7 = 20^4 × 20^2 × 20^1 = 16 × 4 × 20 mod 33
  - 16 × 4 = 64; 64 mod 33 = 64-33 = 31
  - 31 × 20 = 620; 620 mod 33 = 620 - 18×33 = 620-594 = **26**
  - **Ciphertext C = 26**

---

**Worked Example 3 — qp4/qp5 (p=23, q=19, e=283, find d):**

- n = 23 × 19 = **437**
- φ(n) = (23-1)(19-1) = 22 × 18 = **396**
- Find d: 283 × d ≡ 1 (mod 396)
- Using extended Euclidean algorithm:
  - 396 = 1 × 283 + 113
  - 283 = 2 × 113 + 57
  - 113 = 1 × 57 + 56
  - 57 = 1 × 56 + 1
  - Back-substituting: 1 = 57 - 1×56 = 57 - (113-57) = 2×57 - 113 = 2(283-2×113)-113 = 2×283 - 5×113 = 2×283 - 5(396-283) = 7×283 - 5×396
  - So d = 7 (mod 396) → **d = 7**
  - Verify: 283 × 7 = 1981; 1981 / 396 = 5 remainder 1 ✓

---

**Worked Example 4 — qp6 (p=7, q=11, m=9):**

- n = 7 × 11 = **77**
- φ(n) = (7-1)(11-1) = 6 × 10 = **60**
- Need to choose e coprime to 60. Standard choice: e = 7 (gcd(7,60)=1 ✓) or e = 13, or e = 17.
  *(If e not specified, use e = 7)*
- Find d: 7d ≡ 1 (mod 60). Extended Euclidean:
  - 60 = 8×7 + 4; 7 = 1×4 + 3; 4 = 1×3 + 1 → back-sub: d = 43
  - Verify: 7 × 43 = 301; 301 mod 60 = 301 - 5×60 = 1 ✓ → **d = 43**
- **Public Key = (7, 77)**, **Private Key = (43, 77)**
- Encrypt m=9: C = 9^7 mod 77
  - 9^2 = 81; 81 mod 77 = 4
  - 9^4 = 4^2 = 16
  - 9^7 = 9^4 × 9^2 × 9 = 16 × 4 × 9 mod 77
  - 16 × 4 = 64; 64 × 9 = 576; 576 mod 77 = 576 - 7×77 = 576 - 539 = **37**
  - **Ciphertext C = 37**

---

## Q2.3 — Can the concept of digital signature be included in RSA? How? *(qp1)*

**Answer:**

Yes. Digital signatures are a natural extension of RSA's asymmetric key structure.

**How Digital Signatures Work with RSA:**

**Signing (by Sender Alice):**

1. Alice computes the hash of her message M: `h = SHA256(M)`
2. Alice encrypts the hash with her **private key**: `Signature S = h^d mod n`
3. Alice sends `(M, S)` to Bob.

**Verification (by Receiver Bob):**

1. Bob receives `(M, S)`.
2. Bob decrypts the signature using Alice's **public key**: `h' = S^e mod n`
3. Bob independently computes the hash of the received message: `h = SHA256(M)`
4. If `h' == h` → signature is valid; Alice sent the message and it wasn't tampered with.

**Properties Achieved:**

- **Authenticity** — only Alice (holding private key d) could have produced S.
- **Integrity** — if M was altered, SHA256(M) would differ.
- **Non-Repudiation** — Alice cannot deny signing since only her private key produces valid signatures.

---

## Q2.4 — What is hashing in blockchain? Give the characteristics of a good hashing technique. / Explain hash function properties with a 256-bit hash function. *(qp1, qp2, qp3, qp4, qp5, qp6, UE19CS335)*

**Answer:**

**Hashing in Blockchain:**

Hashing converts variable-length input data (a transaction, a block, or any data) into a fixed-length output (the hash/digest). It is the cryptographic "fingerprint" of data. Blockchain uses SHA-256 to hash every block header, transaction, and address.

**Uses in Blockchain:**

- Linking blocks (previous block hash → chain)
- Merkle root (commits to all transactions in a block)
- Address generation (public key → hashed → wallet address)
- Proof of Work (find nonce so that hash < target)
- Transaction IDs (TXID = SHA256(SHA256(transaction data)))

**Characteristics of a Good Hash Function:**

| Property | Description | Example |
|----------|-------------|---------|
| **Deterministic** | Same input always produces same output | SHA256("hello") always gives the same 64-char hex |
| **Pre-image Resistant** (One-way) | Cannot reverse-engineer input from output | Cannot find M given only H(M) |
| **Second Pre-image Resistant** | Given input M, cannot find M' ≠ M with H(M) = H(M') | Cannot find another transaction that hashes to the same value |
| **Collision Resistant** | Computationally infeasible to find any two inputs with the same hash | 2^256 possible outputs — brute force infeasible |
| **Avalanche Effect** | Tiny change in input → completely different output | "hello" vs "hello!" → entirely different hashes |
| **Fixed Output Size** | Output length is always the same regardless of input | SHA-256 → always 256 bits (64 hex chars) |
| **Puzzle-Friendly** | Difficult to find input that gives a hash below a given target | Basis of Proof of Work |

---

## Q2.5 — What is a Merkle Tree? What is the need for the Merkle tree in blockchain? Give the post-order traversal for 10 data points (10 to 1). *(qp1, qp2, qp3, UE19CS335)*

**Answer:**

**Definition:** A Merkle Tree is a binary hash tree where each leaf node contains the hash of a data block (transaction), and each non-leaf node contains the hash of the concatenation of its children's hashes. The root is called the **Merkle Root**.

**Need in Blockchain:**

1. **Data Integrity** — Any change to any transaction changes the Merkle root, which is stored in the block header, making tampering immediately detectable.
2. **Efficient Verification (SPV)** — Lightweight nodes can verify a transaction is in a block by only checking O(log N) hashes (Merkle proof), not downloading all N transactions.
3. **Compact Commitment** — A single 32-byte root commits to all transactions in the block.
4. **Scalability** — Efficiently handles thousands of transactions per block.

**Post-Order Traversal for 10 data points (10 down to 1):**

First, build the Merkle Tree. With 10 leaves, we need to pad to 16 (next power of 2), or build iteratively.

Leaf nodes (from left to right): 10, 9, 8, 7, 6, 5, 4, 3, 2, 1

Post-order traversal visits: Left → Right → Root

```
Level 0 (leaves):  10, 9, 8, 7, 6, 5, 4, 3, 2, 1
Level 1 combos:    (10,9)→H(10,9), (8,7)→H(8,7), (6,5)→H(6,5), (4,3)→H(4,3), (2,1)→H(2,1)
                   [last node paired with itself: H(2,1) doubled]
Level 2 combos:    H(H(10,9),H(8,7)), H(H(6,5),H(4,3)), H(H(2,1),H(2,1))
```

**Post-Order Traversal Result (using notation where 43 = hash of 4 and 3):**

```
10, 9, (10,9), 8, 7, (8,7), (10,9,8,7),
6, 5, (6,5), 4, 3, (4,3), (6,5,4,3),
2, 1, (2,1), (2,1), (2,1,2,1),
(10,9,8,7,6,5,4,3),
ROOT
```

Simplified post-order sequence:

**10 → 9 → 109 → 8 → 7 → 87 → 10987 → 6 → 5 → 65 → 4 → 3 → 43 → 6543 → 109876543 → 2 → 1 → 21 → 21 (duplicate) → 2121 → ROOT**

---

## Q2.6 — How is a digital signature created and verified? Explain with a scenario. / Alice sends 10 bitcoins to Bob — step-by-step with keys. *(qp3, UE19CS335)*

**Answer:**

**Digital Signature Creation and Verification (General):**

**Scenario: Alice sends a signed document to Bob**

**Step 1 — Creation (Alice):**

- Alice writes message M.
- Alice computes `h = SHA256(M)` (message digest).
- Alice encrypts h with her **private key PrA**: `S = encrypt(h, PrA)` (this is the digital signature).
- Alice sends `{M, S, PuA}` to Bob (message + signature + public key).

**Step 2 — Verification (Bob):**

- Bob decrypts S using Alice's **public key PuA**: `h' = decrypt(S, PuA)`
- Bob independently computes `h = SHA256(M)`.
- If `h' == h` → signature is valid → message is authentic and unaltered.

```
Alice:  M → SHA256 → h → [Encrypt with PrA] → Signature S
                                            send(M + S + PuA) →
Bob:    M → SHA256 → h
        S → [Decrypt with PuA] → h'
        h == h' ? → Valid
```

**Bitcoin Transaction — Alice (20 BTC) sends 10 BTC to Bob:**

1. Alice creates a transaction: `TX = {Sender: PuA, Receiver: PuB, Amount: 10 BTC, InputUTXO: ref}`
2. Alice hashes the transaction: `h = SHA256(TX)`
3. Alice signs: `S = encrypt(h, PrA)` using her private key.
4. Alice broadcasts `{TX, S, PuA}` to the network.
5. Network nodes verify:
   - Decrypt S with PuA → get h'. Compute SHA256(TX) → compare with h'. (Authentication + Integrity)
   - Check Alice's UTXO balance ≥ 10 BTC. (No double-spend)
6. Miner includes TX in next block; block mined (PoW) and added to chain.
7. Result: Alice = 10 BTC, Bob = 20 BTC.

**Representation in terms of keys:**

- `TX_signed = {PuA → PuB : 10 BTC, signed with PrA}`
- Verification: `decrypt(signature, PuA) == SHA256(transaction_data)`

---

## Q2.7 — How to prevent double spending in a decentralised network? *(qp6)*

**Answer:**

**Double Spending Problem:** A digital asset (unlike physical cash) can be copied. Without controls, the same digital coin could be spent twice.

**Bitcoin's Solution — Multi-layered approach:**

**1. The Blockchain Ledger:**

- Every transaction is recorded on a public, immutable, distributed ledger.
- Once a coin is spent in a confirmed transaction, all subsequent attempts to spend it are rejected by nodes (they check the UTXO set).

**2. Transaction Broadcasting:**

- When Alice spends coins, the transaction is immediately broadcast to ALL nodes.
- Nodes place it in their mempool and check it against their copy of the UTXO set.
- A conflicting transaction (double-spend attempt) is rejected by honest nodes.

**3. Mining/Confirmation:**

- A transaction is not final until included in a mined block.
- The longer the chain, the more confirmations, the harder to reverse.
- Standard: 6 confirmations (~1 hour) for high-value Bitcoin transactions before accepting.

**4. Longest Chain Rule:**

- If an attacker creates a fork to double-spend, the honest chain (with more mining power) eventually becomes longer and is accepted by all nodes.
- Reversing N confirmed blocks requires the attacker to redo N × full Proof of Work, which is economically infeasible without 51% of hash power.

**5. Timestamp + Mempool Ordering:**

- Nodes timestamp transactions when first seen.
- In case of conflicting transactions arriving simultaneously, nodes typically keep the first-seen transaction.

---

# 3. Consensus Algorithms

---

## Q3.1 — What do you mean by distributed consensus? What is the limitation of distributed consensus with respect to blockchain? *(UE19CS335)*

**Answer:**

**Distributed Consensus:**

Distributed consensus is the process by which all nodes in a decentralised network agree on a single value or state — specifically, the valid next block to be added to the blockchain — without any central coordinator.

In Ethereum, consensus is achieved when at least **66% of nodes** agree on the global state.

**Properties of Distributed Consensus:**

- **Termination:** Every correct node eventually decides on a value.
- **Validity:** If all nodes propose the same value, all decide that value.
- **Integrity:** Each correct node decides at most once on a value that was proposed.
- **Agreement:** All correct nodes agree on the same value.

**Limitations with respect to Blockchain:**

1. **FLP Impossibility Theorem (Fischer, Lynch, Paterson, 1985):** In a fully asynchronous system, consensus is impossible even with a single crash fault. Blockchain systems accept probabilistic (not absolute) finality to work around this.
2. **Scalability:** As the number of nodes increases, communication overhead for consensus grows (O(n²) for PBFT — impractical for thousands of nodes).
3. **Open/Anonymous Network:** Traditional consensus assumes known participants. Bitcoin's open network cannot use direct message-passing consensus because anyone can join.
4. **Sybil Attacks:** Without identity verification, a single entity can create multiple fake nodes to influence consensus.
5. **51% Attack:** PoW consensus can be manipulated by an entity controlling >50% of hash power.
6. **Network Asynchrony:** Messages can be delayed, reordered, or lost — there is no global clock.
7. **Safety vs Liveness Trade-off:** Nakamoto consensus (Bitcoin) prioritises liveness (always making progress) over absolute safety (temporary forks can occur).

---

## Q3.2 — Compare Proof of Work vs Proof of Stake. How is PoW better than PoS? *(UE19CS335)*

**Answer:**

| Property | Proof of Work (PoW) | Proof of Stake (PoS) |
|----------|--------------------|--------------------|
| Block creators | Miners (computational work) | Validators (staked cryptocurrency) |
| Entry requirement | Expensive hardware + energy | Own and stake cryptocurrency |
| Energy consumption | Very high | Very low (~99.84% less) |
| Security mechanism | Computational cost | Economic cost (slashing) |
| Sybil resistance | Cost of mining hardware | Cost of staking |
| Attack cost | Need 51% of hash power | Need 51% of staked crypto |
| Decentralisation | High (but mining pools) | High (but staking pools) |
| Finality | Probabilistic | Faster/deterministic (some PoS) |
| Rewards | Block reward + transaction fees | Transaction fees + staking rewards |
| Used in | Bitcoin, Litecoin, Dogecoin | Ethereum 2.0, Cardano, Solana |

**Arguments for PoW over PoS (as "ABC organisation"):**

1. **Proven Security:** PoW has secured Bitcoin since 2009 with no successful 51% attack on Bitcoin itself. PoS is newer and less battle-tested.
2. **Physical Cost = Real Security:** To attack PoW, an attacker must acquire physical hardware and electricity — a real-world constraint. In PoS, an attacker needs only to acquire tokens, which can be done on open markets.
3. **Nothing-at-Stake Problem:** In naive PoS, validators can sign multiple forks simultaneously at no cost. PoW miners must commit to one chain (their energy commitment is exclusive).
4. **Immutability:** Re-mining historical blocks under PoW requires redoing all subsequent Proof of Work — physically infeasible. Under PoS, old private keys can enable long-range attacks.
5. **Objective Fork Choice:** PoW's longest chain is objectively measurable (total work). PoS requires more complex, subjective fork choice rules.

**Fault Tolerance:** Both are Byzantine Fault Tolerant up to a threshold (51% for PoW, 33% for most PoS BFT variants). Neither is crash-fault tolerant in the traditional distributed systems sense.

---

## Q3.3 — Give the difference between Proof of Authority and Proof of Elapsed Time. *(UE19CS335)*

**Answer:**

| Property | Proof of Authority (PoA) | Proof of Elapsed Time (PoET) |
|----------|--------------------------|------------------------------|
| Selection basis | Identity and reputation of pre-approved validators | Random wait time from trusted hardware |
| Hardware required | Standard — no special hardware | Intel SGX (trusted execution environment) |
| Energy efficiency | Very efficient | Very efficient |
| Decentralisation | Low — validators are known, vetted | Moderate — any node with SGX can participate |
| Trust model | Trust the identities of validators | Trust the hardware (Intel SGX) |
| Network type | Permissioned private/consortium | Permissioned (Hyperledger Sawtooth) |
| Sybil resistance | Vetted identities prevent fake nodes | Hardware attestation prevents time manipulation |
| Transparency | Validator identities are public | Wait times verifiable via SGX attestation |
| Coin minting | No mining — validators take turns | Block leader = node with shortest wait time |
| Failure risk | Validator corruption/collusion | Hardware vulnerability in Intel SGX |

---

## Q3.4 — Difference between: (i) PoS vs DPoS; (ii) PoB vs PoSpace; (iii) PAXOS vs RAFT. *(qp1)*

**Answer:**

**(i) Proof of Stake vs Delegated Proof of Stake:**

| Property | Proof of Stake (PoS) | Delegated Proof of Stake (DPoS) |
|----------|---------------------|--------------------------------|
| Validator selection | Proportional to stake (pseudo-random) | Token holders vote for a fixed set of delegates |
| Number of validators | Can be large | Small fixed number (e.g., 21 in EOS) |
| Decentralisation | Higher | Lower (centralised around delegates) |
| Speed | Moderate | Very fast (fewer validators) |
| Governance | Indirect | Direct democratic voting |
| Example | Ethereum 2.0 | EOS, TRON |

**(ii) Proof of Burn vs Proof of Space:**

| Property | Proof of Burn (PoB) | Proof of Space (PoSpace/PoC) |
|----------|--------------------|-----------------------------|
| Resource committed | Cryptocurrency permanently destroyed | Unused disk storage allocated |
| Energy | Minimal | Minimal (after initial plotting) |
| Initial setup | Buy and burn tokens | "Plot" hard drive with cryptographic data |
| Ongoing cost | None after burning | Storage space |
| Fairness | Wealthy can burn more | Large storage = more chance |
| Example | Slimcoin | Chia Network |

**(iii) PAXOS vs RAFT:**

| Property | PAXOS | RAFT |
|----------|-------|------|
| Design goal | First distributed consensus algorithm | Designed to be understandable |
| Roles | Proposers, Acceptors, Learners | Leader, Followers, Candidates |
| Leader | No explicit leader (any proposer can propose) | Single explicit leader |
| Fault type handled | Crash faults | Crash faults (not Byzantine) |
| Complexity | Difficult to understand and implement correctly | Simpler to understand and implement |
| Livelock risk | Yes — dueling proposers | No — leader election resolves this |
| Log replication | Not specified | Core feature — leader replicates log to followers |
| Fault tolerance | Majority needed (>N/2 nodes) | Majority needed (>N/2 nodes) |
| Used in | Research; some databases | etcd, Consul, Hyperledger |

---

## Q3.5 — Explain the pros and cons of: (i) Proof of Stake; (ii) Proof of Capacity; (iii) Proof of Elapsed Time; (iv) Proof of Burn. *(qp2)*

**Answer:**

**(i) Proof of Stake:**

| Pros | Cons |
|------|------|
| Energy efficient (~99.84% less than PoW) | Nothing-at-stake problem (validators sign multiple forks) |
| Higher TPS possible | Requires large initial stake to participate |
| Lower barrier (no mining hardware) | Wealthy validators can dominate |
| Reduced centralisation risk vs PoW pools | Long-range attack vulnerability |
| Slashing disincentivises dishonesty | Complex to implement correctly |

**(ii) Proof of Capacity (PoSpace):**

| Pros | Cons |
|------|------|
| Energy efficient | Storage centralisation risk (large farms) |
| Uses commodity hardware (hard drives) | Computationally intensive initial plotting phase |
| Eco-friendly | Wear and tear on storage hardware |
| Decentralised access | Parasite mining possible |

**(iii) Proof of Elapsed Time:**

| Pros | Cons |
|------|------|
| Very energy efficient | Dependent on Intel SGX — hardware centralisation |
| Fair — random wait times | SGX vulnerabilities compromise security |
| Easy to verify | Permissioned only — not suitable for public blockchains |
| Low barrier to entry | Relies on trusting Intel |

**(iv) Proof of Burn:**

| Pros | Cons |
|------|------|
| No ongoing energy cost | Perceived economic waste |
| Reduces token supply → deflationary | Wealthy burn more → centralisation |
| Demonstrates long-term commitment | Irreversibility (risk if burned by mistake) |
| Low barrier vs PoW | Market manipulation if large players burn |

---

## Q3.6 — Prove of Authority — can it be used in public blockchains? Justify. *(qp1)*

**Answer:**

**No, PoA is generally NOT suitable for public, permissionless blockchains.**

**Justification:**

1. **Identity Requirement:** PoA requires validators to have verified, known identities (KYC). Public blockchains are designed to be pseudonymous and permissionless — anyone should be able to participate without revealing their identity.
2. **Centralisation:** PoA uses a small set of pre-approved validators. This contradicts the decentralisation principle of public blockchains. If validators collude (or are compromised by regulatory authorities), the entire network can be controlled.
3. **Censorship Risk:** Known validators can be pressured by governments or legal bodies to censor transactions, defeating blockchain's censorship-resistance value proposition.
4. **Trust Model:** PoA relies on trusting the validators' identities and reputations rather than cryptographic/economic mechanisms. Public blockchains are designed to be trustless.
5. **Sybil Attacks:** In a public blockchain, without identity verification, PoA is useless — anyone can fake a reputable identity.

**Where PoA IS appropriate:**

- Private or consortium blockchains (e.g., enterprise supply chains).
- Blockchain testnets (Ethereum's Kovan, Rinkeby testnets used PoA).
- Scenarios where all participants are known, accountable organisations.

---

## Q3.7 — PAXOS Consensus — What happens if: Proposer 1 crashes, Proposer 2 crashes, Both crash, Acceptor 2 crashes, Learner crashes? *(UE19CS335)*

**Answer:**

PAXOS has three roles: **Proposers** (propose values), **Acceptors** (form quorum to accept), **Learners** (learn the decided value).

Standard setup assumed: 2 Proposers (P1, P2), 3 Acceptors (A1, A2, A3), 1 Learner.

**(I) Proposer 1 crashes:**

- **During Phase 1 (Prepare):** If P1 crashes after sending Prepare but before receiving quorum of responses, P2 can start a new round with a higher proposal number. Consensus continues.
- **During Phase 2 (Accept):** If P1 crashes after sending Accept but before learner learns the value — P2 can take over with a higher-numbered proposal. The acceptors will respond with the highest-numbered value they already accepted, ensuring the same value is proposed.
- **Outcome:** No permanent harm. Liveness is temporarily affected but PAXOS continues.

**(II) Proposer 2 crashes:**

- Same as above but P1 continues. Consensus progresses normally.

**(III) Both Proposer 1 and 2 crash:**

- **If neither has submitted an Accept message yet:** No consensus is reached. The system is live-locked until a new proposer is elected (PAXOS itself can be used for leader election).
- **If one has submitted Accept and a quorum of acceptors accepted it:** The learner may already have learned the value. If not, the value is stored in acceptors and a recovered/new proposer can re-run the protocol and will discover the already-accepted value.
- **Outcome:** System halts until a new proposer becomes available.

**(IV) Acceptor 2 crashes:**

- With 3 acceptors, a majority quorum requires 2. If A2 crashes, A1 and A3 still form a majority.
- **Outcome:** Consensus proceeds normally using A1 and A3.

**(V) Learner crashes:**

- Learners are passive — they only observe. A learner crash does NOT affect consensus.
- When the learner recovers, it can query the acceptors for the decided value.
- **Outcome:** No impact on consensus. Learner catches up on recovery.

---

## Q3.8 — RAFT Consensus Algorithm — Explain election scenarios with given node logs. *(qp1 (indirect), qp3, qp4, qp5)*

**Answer:**

**RAFT overview:** Manages replicated logs. Roles: Leader (manages log), Followers, Candidates (during election). Election triggered by leader failure (heartbeat timeout).

**Scenario: 6 nodes (A–F), term=21, A and B simultaneously send RequestVote:**

Node logs (1.2 = 2nd log entry from term 1):

```
A: 1.1, 2.1        B: 1.1, 3.1, 3.2
C: 1.1, 1.2        D: 1.1
E: 1.1, 3.1        F: 1.1, 2.1, 3.1
```

**Which mechanism resolves the tie?**

RAFT resolves simultaneous candidates via:

1. **Random election timeout** — A and B will eventually have different timeouts; whoever times out first becomes candidate first in the next term.
2. **Vote splitting** — If both receive some votes and neither reaches majority (4/6), neither wins term 21. Both increment to term 22 and restart with new random timeouts.
3. **Log currency check** — RAFT grants votes only to candidates whose logs are at least as up-to-date as the voter's (checked by term number, then log length).

**Who wins the election?**

The candidate with the most up-to-date log gets votes. B has logs up to term 3 (3.1, 3.2), which is more current than A (only up to term 2). So B is likely to win votes from F (3.1 matches) and E (3.1 matches). However, A can win votes from D (1.1 — A's log 2.1 is more current). Ultimately the node whose log covers the most committed entries wins.

**Can transaction 1.2 (log entry 2 from term 1) ever be committed?**

Yes — if a future leader has this log entry and successfully replicates it to a majority (4+ nodes). Nodes C has 1.2, so a leader that includes C's logs can commit 1.2. However, if no leader includes this entry, it may be overwritten.

**Among these nodes, if 3 nodes behave maliciously:**

RAFT is NOT Byzantine Fault Tolerant — it only handles crash faults. With 3 malicious nodes out of 6, RAFT's safety guarantees break down because malicious nodes can vote for multiple candidates or send fake heartbeats. In this case, **PBFT** (which requires 3f+1 nodes for f faults, so 3×3+1=10 nodes to tolerate 3 Byzantine faults) would be needed.

**If the leader is identified as Byzantine:**

RAFT cannot natively handle Byzantine leaders. The system would need to: (1) remove the leader via timeout if it stops sending heartbeats, or (2) implement PBFT/Tendermint which includes Byzantine fault detection and view change protocols.

---

## Q3.9 — Explain Byzantine Fault Tolerance (BFT). Illustrate the Byzantine Generals Problem. *(qp2, qp3)*

**Answer:**

**Byzantine Fault Tolerance (BFT):**

A system is Byzantine Fault Tolerant if it can continue operating correctly even when some nodes behave maliciously (arbitrarily — not just crash). A system of N nodes can tolerate f Byzantine faults if **N ≥ 3f + 1**.

**Byzantine Generals Problem:**

A group of Byzantine army generals surrounding an enemy city must decide unanimously whether to Attack or Retreat. Messages are relayed via messengers (some generals or messengers may be traitors).

**Challenge:** Loyal generals must reach a consensus despite traitors sending conflicting messages.

**Example with 4 generals, 1 traitor (Commander + 3 Lieutenants):**

```
Commander (Loyal) → sends "Attack" to all 3 lieutenants

L1 (Loyal):  receives Attack from Cmdr, forwards "Attack" to L2, L3
L2 (Loyal):  receives Attack from Cmdr, forwards "Attack" to L1, L3
L3 (Traitor): receives Attack from Cmdr, tells L1 "Attack", tells L2 "Retreat"

L1's view: {Cmdr:Attack, L2:Attack, L3:Attack} → majority Attack ✓
L2's view: {Cmdr:Attack, L1:Attack, L3:Retreat} → majority Attack ✓
```

With 4 generals and 1 traitor (3f+1 = 4 ✓), loyal generals can reach consensus.

**With 3 generals and 1 traitor:** No solution is possible (3 < 3×1+1 = 4).

**Application in Blockchain:**

- PBFT tolerates f Byzantine nodes with N ≥ 3f+1 total nodes.
- Ethereum 2.0's BFT finality requires 2/3 supermajority of validators.
- When 2/3+ of the network agrees on a state, the system is considered Byzantine Fault Tolerant.

---

## Q3.10 — What is the "Nothing at Stake" problem? Explain with an example. *(qp6)*

**Answer:**

**Nothing at Stake Problem:**

In naive Proof of Stake, validators have no computational cost associated with voting/validating on a block. When a blockchain forks (two competing chains exist), a rational validator should validate BOTH forks simultaneously — they have nothing to lose (no wasted energy like in PoW) and potentially gain rewards on whichever chain wins.

**Example:**

```
Main chain: A → B → C
Fork occurs at C: 
    Chain 1: A → B → C → D1
    Chain 2: A → B → C → D2
```

- In PoW: A miner can only work on ONE chain at a time (computational resources are exclusive). Working on both wastes half your hash power.
- In naive PoS: Validator Eve can validate BOTH D1 and D2 simultaneously. It costs her nothing (no energy). If D1 wins, she gets rewards. If D2 wins, she also gets rewards. She always benefits — there is "nothing at stake."

**Consequences:**

- Consensus weakens — many validators sign both chains.
- Double spending becomes easier — attacker creates a fork and all validators sign both.
- Chain finality is undermined.

**Solutions:**

1. **Slashing:** Validators who sign blocks on multiple competing forks at the same height have their staked cryptocurrency automatically destroyed (slashed).
2. **Finality:** Ethereum 2.0's Casper uses checkpoints; once a checkpoint is finalised (2/3 supermajority), validators are slashed for signing an alternative chain.
3. **Long-range attack prevention:** Checkpointing prevents validators from building alternative histories from the genesis block.

---

## Q3.11 — Explain the Lamport-Shostak-Pease Algorithm. / If there are 24 faulty crash-fault nodes, how many lieutenant nodes are needed? *(qp6, qp1)*

**Answer:**

**Lamport-Shostak-Pease (LSP) Algorithm:**

**Problem:** N generals, at most f are traitors (Byzantine). Loyal generals must agree on a common decision.

**Key rule:** N ≥ 3f + 1 for the algorithm to work.

**Algorithm — `BroadcastMessage(m, v, f)`:**

```
Base Case (f = 0):
  - Commander sends value v to all lieutenants.
  - Each lieutenant uses the value they received.

Recursive Case (f > 0):
  1. Commander sends value v to each lieutenant i.
  2. Each lieutenant i acts as commander and calls BroadcastMessage(i, v_i, f-1)
     (re-broadcasts to all other lieutenants with fault tolerance reduced by 1)
  3. Each lieutenant takes the MAJORITY of all values received.
```

**Example with 4 generals, 1 traitor:**

- Commander (loyal) sends "Attack" to L1, L2, L3.
- L3 (traitor) sends "Attack" to L1 and "Retreat" to L2.
- L1 receives: {Attack(Cmdr), Attack(L2), Attack(L3)} → majority = Attack.
- L2 receives: {Attack(Cmdr), Attack(L1), Retreat(L3)} → majority = Attack.
- Result: All loyal lieutenants agree on Attack. ✓

**For 24 crash-fault nodes — minimum lieutenant nodes:**

For crash faults in a **synchronous network**, consensus requires the majority principle:

- A synchronous system can tolerate up to **f crash faults** with **N ≥ 2f + 1** nodes.
- With f = 24 faulty nodes: N ≥ 2×24 + 1 = 49 total nodes.
- Lieutenants = 49 - 1 (commander) = **48 lieutenant nodes**.

*(Note: For Byzantine faults, the formula is N ≥ 3f+1: 3×24+1 = 73 total, 72 lieutenants.)*

---

## Q3.12 — PBFT Scenario: Client → Primary → Backups. Which consensus? If primary is Byzantine, how does it work? *(qp4, qp5)*

**Answer:**

**The described system is Practical Byzantine Fault Tolerance (PBFT).**

**Identifying the Protocol:**

- Client sends request to a **primary** (not broadcast to all).
- Primary **multicasts** to all backups.
- Backups **execute and reply directly to client**.
- Client waits for **f+1 identical replies** from different replicas.
This is the exact PBFT model.

**PBFT Protocol Phases:**

1. **Pre-Prepare:** Primary receives client request; assigns sequence number; multicasts `<PRE-PREPARE, view, seq, digest>` to all backups.
2. **Prepare:** Each backup verifies and multicasts `<PREPARE, view, seq, digest>` to all others.
3. **Commit:** When a replica receives 2f+1 Prepare messages, it multicasts `<COMMIT, view, seq, digest>`.
4. **Reply:** After 2f+1 Commit messages, replica executes the request and sends reply to client.
5. Client accepts when it receives **f+1 identical replies**.

**If the Primary (Leader) is Byzantine:**

If the primary is faulty, it may send different messages to different backups, or not send anything:

- Backups detect the faulty primary when they receive inconsistent Pre-Prepare messages.
- Backups trigger a **View Change** protocol:
  - Each backup broadcasts `<VIEW-CHANGE, v+1, n, C, P>` to switch to the next view (and next primary).
  - The new primary (determined by round-robin: `v mod N`) collects 2f+1 View-Change messages.
  - New primary broadcasts `<NEW-VIEW>` message to confirm the change.
  - Consensus resumes with the new primary.

**Difference from Standard BFT:**

- Standard BFT (Lamport-Shostak-Pease) is a theoretical algorithm assuming a synchronous network.
- PBFT is designed for **asynchronous networks** (realistic internet conditions).
- PBFT is optimised for practical performance with O(n²) message complexity per request.
- PBFT provides **safety** in asynchronous networks but only **liveness** assumptions under partial synchrony.

---

## Q3.13 — PAXOS with 3 proposers, 5 acceptors, 1 learner — if 3 acceptors failed, what is true? / PoET with Hyperledger Sawtooth. *(qp3)*

**Answer:**

**PAXOS with 3 Acceptors Failed:**

- 5 acceptors total. A majority quorum = ⌊5/2⌋ + 1 = **3 acceptors** required.
- If 3 acceptors have failed, only 2 remain.
- 2 < 3 (required majority) → **the system CANNOT reach consensus.**
- **True statement: The system is halted. No new values can be accepted. No consensus is possible until at least one acceptor recovers.**
- The system is "stuck" — existing committed values remain accessible but no new proposals can be decided.

**Proof of Elapsed Time (PoET) in Hyperledger Sawtooth:**

**Definition:** PoET is a consensus mechanism designed for permissioned blockchains (Hyperledger Sawtooth) that uses **Intel SGX** trusted hardware to ensure fair, random leader election without energy-intensive computation.

**How it Ensures Legitimacy:**

1. Each node requests a **randomly assigned wait time** from the Intel SGX enclave.
2. The SGX generates a timer and a **signed certificate** proving the wait time was genuinely generated by trusted hardware (cannot be faked or shortened).
3. The node with the **shortest wait time** broadcasts its block first.
4. Other nodes verify the **SGX attestation certificate** — proving the block leader genuinely waited their assigned time and didn't cheat.
5. If the certificate is valid, the block is accepted.

**Example:**

- Node A: wait = 2.3 seconds (SGX certified)
- Node B: wait = 1.1 seconds (SGX certified)
- Node C: wait = 3.7 seconds (SGX certified)
- Node B waits 1.1s, publishes block first with SGX certificate.
- Other nodes verify certificate → accept B's block.

**Key insight:** The SGX hardware is the trusted third party — it cannot be manipulated by software, so the random wait time cannot be shortened by an attacker.

---

## Q3.14 — What is the difference between PoW and PoET? *(qp5)*

**Answer:**

| Property | Proof of Work (PoW) | Proof of Elapsed Time (PoET) |
|----------|--------------------|-----------------------------|
| Resource | Computational power (CPU/GPU/ASIC) | Trusted hardware (Intel SGX) |
| Energy consumption | Very high | Very low |
| Permissioning | Permissionless (public blockchain) | Permissioned only |
| Random element | Hash puzzle solution | Random wait time from SGX |
| Verification | Check if hash meets difficulty target | Verify SGX attestation certificate |
| Fairness | Proportional to hash power (not equal) | Fair random wait time to all nodes |
| Attack vector | 51% hash power attack | SGX hardware vulnerability |
| Decentralisation | High | Moderate (depends on Intel SGX) |

---

# 4. Smart Contracts, dApps & DAOs

---

## Q4.1 — What are the benefits of using smart contracts? Give an example with respect to any application. *(UE19CS335, qp6, qp4)*

**Answer:**

**Definition:** Smart contracts are self-executing programs stored on a blockchain that automatically execute when predetermined terms and conditions are met. They eliminate the need for intermediaries.

**Benefits:**

| Benefit | Description |
|---------|-------------|
| **Cost-Effective** | Removes intermediaries (lawyers, banks, notaries) — reduces transaction costs |
| **Speed** | Automates processes that previously took days — executes in seconds |
| **Security** | Cryptographically secured; immutable once deployed; tamper-proof |
| **Transparency** | Code is public — all parties see the exact execution logic |
| **Accuracy** | Eliminates human error; conditions are precisely coded |
| **Trustless** | No need to trust the counterparty — trust the code |
| **Automation** | Self-executing — no manual intervention required |

**Example — Insurance Claim Processing:**

Traditional insurance: Customer files claim → Manual review (weeks) → Possible fraud → Settlement (more weeks).

Smart Contract Insurance:

```
Trigger: Flight delay > 3 hours (data from verified oracle)
    ↓
Smart contract checks: PolicyHolder's flight TK456 delayed by 4 hours (verified)
    ↓
Condition met: Amount > 0 AND PolicyHolder's premium is paid AND within policy period
    ↓
Automatically: Transfer $200 compensation to PolicyHolder's wallet
    ↓
Done: No paperwork, no call center, no adjuster — minutes vs weeks
```

**Example — Alice and Bob Property Rental (Smart Contract):**

1. Bob deposits rent into contract escrow.
2. Alice provides apartment code/address in contract.
3. IF Bob confirms code is correct → Alice receives rent.
4. IF code is wrong → Bob's deposit refunded.
5. IF Bob doesn't show up by deadline → Alice receives liquidated damages.

---

## Q4.2 — What do you mean by composability in smart contracts? Difference between deterministic and non-deterministic smart contracts. Write a Solidity module for insurance. *(qp1)*

**Answer:**

**Composability in Smart Contracts:**

Composability (also called "Money Legos") means smart contracts can be combined and built upon each other, similar to how Lego pieces fit together. A smart contract can call functions of other contracts, creating complex financial products from simple building blocks.

Example: A DeFi lending protocol (Aave) can interact with a DEX (Uniswap) and a stablecoin protocol (MakerDAO) — all via smart contract calls — to create leveraged positions.

**Deterministic vs Non-Deterministic Smart Contracts:**

| Property | Deterministic | Non-Deterministic |
|----------|--------------|-------------------|
| Data source | Only uses on-chain blockchain data | Requires external real-world data (oracles) |
| Execution | Always produces the same result given the same blockchain state | Outcome depends on off-chain data that may vary |
| Trust | Fully trustless — no external dependencies | Requires trust in the oracle data source |
| Example | Token transfer (only needs balances) | Flight insurance (needs actual flight delay data from airline API) |
| Oracle needed? | No | Yes (Chainlink, Band Protocol) |

**Solidity Module — Insurance Smart Contract:**

```solidity
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract InsuranceClaim {
    address public insurer;
    
    // Module 1: Policy management
    struct Policy {
        address holder;
        uint256 premium;
        uint256 coverageAmount;
        uint256 expiryDate;
        bool isActive;
        bool isClaimed;
    }
    mapping(address => Policy) public policies;
    
    // Module 2: Claim management
    struct Claim {
        address claimant;
        string description;
        uint256 amount;
        bool isApproved;
        bool isPaid;
    }
    mapping(uint256 => Claim) public claims;
    uint256 public claimCount;
    
    constructor() { insurer = msg.sender; }
    
    // Module 3: Enroll a policy
    function enrollPolicy(uint256 _coverage, uint256 _duration)
        public payable
    {
        require(msg.value > 0, "Premium required");
        require(!policies[msg.sender].isActive, "Policy already active");
        policies[msg.sender] = Policy(
            msg.sender, msg.value, _coverage,
            block.timestamp + _duration, true, false
        );
    }
    
    // Module 4: Submit a claim
    function submitClaim(string memory _desc, uint256 _amount) public {
        Policy storage p = policies[msg.sender];
        require(p.isActive, "No active policy");
        require(!p.isClaimed, "Already claimed");
        require(block.timestamp < p.expiryDate, "Policy expired");
        require(_amount <= p.coverageAmount, "Exceeds coverage");
        claims[claimCount] = Claim(msg.sender, _desc, _amount, false, false);
        claimCount++;
    }
    
    // Module 5: Approve and pay claim (insurer only)
    function approveClaim(uint256 _claimId) public {
        require(msg.sender == insurer, "Not insurer");
        Claim storage c = claims[_claimId];
        require(!c.isApproved, "Already approved");
        c.isApproved = true;
        c.isPaid = true;
        policies[c.claimant].isClaimed = true;
        payable(c.claimant).transfer(c.amount);  // auto-pay on approval
    }
}
```

---

## Q4.3 — What is the difference between DAPPs and DAOs? Give an example of each. *(qp1, qp4, qp6)*

**Answer:**

| Property | DApp (Decentralised Application) | DAO (Decentralised Autonomous Organisation) |
|----------|----------------------------------|---------------------------------------------|
| Definition | Software application running on a blockchain | A collectively-owned organisation governed by smart contracts |
| Primary purpose | Provide a service or functionality | Collective governance and decision-making |
| Users | Interact with the application | Are members with voting rights |
| Decision making | Protocol rules set at deployment | Members vote on decisions |
| Governance token | Not always required | Usually required (voting rights) |
| Autonomy | High — smart contracts govern logic | High — no CEO or central authority |
| Examples | Uniswap, Aave, CryptoKitties | MakerDAO, Compound governance, ConstitutionDAO |

**DApp Example — Uniswap:**

- A decentralised exchange (DEX) where users swap tokens directly via smart contracts.
- No company holds user funds. The protocol's automated market maker (AMM) sets prices algorithmically.
- Anyone can provide liquidity and earn fees.

**DAO Example — MakerDAO:**

- Governs the DAI stablecoin protocol.
- MKR token holders vote on: collateral types, stability fees, debt ceilings.
- If a vote passes, the smart contract automatically implements the change.
- No board of directors — the code executes the community's decisions.

---

## Q4.4 — Explain different types of DApps. Give an example of each. *(UE19CS335)*

**Answer:**

**Classification by Blockchain Protocol Type:**

| Type | Description | Example |
|------|-------------|---------|
| **Type 1 DApps** | Have their own blockchain | Bitcoin (BTC), Ethereum |
| **Type 2 DApps** | Use Type 1 blockchain as foundation; have their own tokens | Omni Layer (built on Bitcoin for token issuance) |
| **Type 3 DApps** | Use Type 2 protocol; most complex | SAFE Network (uses Omni Layer) |

**Classification by Application Domain:**

| Domain | Example | Description |
|--------|---------|-------------|
| **DeFi (Finance)** | Uniswap, Aave, Compound | Decentralised trading, lending, borrowing |
| **Gaming** | CryptoKitties, Axie Infinity | Blockchain-based games with tradeable NFT assets |
| **NFT Marketplaces** | OpenSea, Rarible | Buy/sell/trade unique digital assets |
| **Social** | Steemit, Mirror | Decentralised content platforms with token rewards |
| **Gambling** | WINk (TRON) | Transparent, verifiable gambling |
| **Storage** | IPFS-based apps | Decentralised file storage |
| **Identity** | Civic, uPort | Self-sovereign identity management |
| **Prediction** | Augur | Decentralised prediction markets |

---

## Q4.5 — How does a Decentralised Application (DApp) fit in the real world? *(qp4)*

**Answer:**

**Components of a Real-World DApp:**

1. **Frontend (User Interface):**
   - Standard web technologies (HTML, CSS, JavaScript/React).
   - Web3.js or Ethers.js library connects the UI to the blockchain.
   - MetaMask or WalletConnect for wallet integration and transaction signing.

2. **Smart Contract (Backend Logic):**
   - Deployed on Ethereum/EVM-compatible blockchain.
   - Contains all business logic — immutable and trustless.
   - Handles state changes, token transfers, access control.

3. **Blockchain (Data Layer):**
   - Stores transaction history, smart contract state, token balances.
   - Immutable and decentralised.

4. **Off-Chain Storage (Optional):**
   - IPFS for decentralised file storage (images, documents).
   - The IPFS hash is stored on-chain for integrity verification.

**Real-World Example — Supply Chain DApp:**

- A pharmaceutical company tracks drug batches from manufacturer → distributor → pharmacy.
- Each step: a smart contract transaction is created, recording batch ID, timestamp, location, and handler.
- Pharmacist can verify authenticity by looking up the batch on the blockchain.
- No central database — no tampering possible.
- Regulators have real-time, permissioned visibility.

---

## Q4.6 — Write short notes on DApps and DAO. *(qp6)*

**Answer:**

**DApps (Decentralised Applications):**

DApps are software programs that run on a blockchain or P2P network instead of a single computer. They are characterised by: (1) open-source code, (2) all data stored on a decentralised blockchain, (3) tokens as incentives for participation, (4) following a standardised consensus protocol.

DApps cannot be controlled or shut down by any single entity. They are resistant to censorship and single-point failures. Examples: Uniswap (DEX), CryptoKitties (game), Aave (lending).

Challenges: Gas fees, scalability, complex user experience (wallet management), immutability (bugs cannot be patched easily).

**DAOs (Decentralised Autonomous Organisations):**

DAOs are collectively-owned organisations where governance rules are encoded in smart contracts. No CEO or board — the code IS the organisation.

Members holding governance tokens vote on proposals. If a proposal passes a quorum, the smart contract automatically executes it (transfers funds, changes protocol parameters, etc.).

Key characteristics: Transparent (all votes on-chain), borderless (anyone can join), democratic (proportional voting), autonomous (self-executing smart contracts).

Examples: MakerDAO (governs DAI stablecoin), Compound (governs COMP lending protocol), ConstitutionDAO (raised $47M to bid on a copy of the US Constitution).

Challenges: Voter apathy (low participation), legal ambiguity, smart contract bugs can have catastrophic consequences (The DAO hack, 2016 — $60M drained).

---

# 5. Hyperledger Fabric

---

## Q5.1 — What do you mean by channel in Hyperledger Fabric? Explain the different steps of making a transaction in Hyperledger Fabric. *(UE19CS335, qp3, qp6)*

**Answer:**

**Channels in Hyperledger Fabric:**

A channel is a private "subnet" of communication between a specific set of network members. It provides data privacy — organisations can transact privately without every transaction being visible to all network participants.

Key properties:

- Each channel has its own **ledger** — separate from the ledger of other channels.
- Each channel has its own **chaincode** (smart contracts).
- A peer can be a member of multiple channels simultaneously.
- Channels are defined in a **channel configuration block** that specifies members, policies, and ordering service settings.

**Hyperledger Fabric Transaction Flow (7 Steps):**

**Step 1 — Propose Transaction:**

- Client application creates a **transaction proposal** and sends it to required **endorsing peers** as specified by the endorsement policy (e.g., "Org1 AND Org2 must endorse").

**Step 2 — Execute Proposed Transaction (Simulation):**

- Each endorsing peer **simulates** the transaction by executing the chaincode against its current ledger state.
- The ledger is NOT updated during simulation.
- Each endorser generates a **Read-Write (RW) Set** — what was read and what would be written.

**Step 3 — Proposal Response:**

- Each endorsing peer signs the RW Set with its certificate and returns the signed response to the client.
- The client collects endorsements asynchronously.

**Step 4 — Order Transaction:**

- Client verifies all endorsements are consistent and match the endorsement policy.
- Client submits the transaction (with all endorsements and RW sets) to the **Ordering Service**.

**Step 5 — Deliver Transaction (in Block):**

- The Ordering Service creates blocks of transactions and delivers them to all committing peers.
- Ordering algorithms used: **SOLO** (development) or **Kafka/RAFT** (production).

**Step 6 — Validate and Commit:**

- Every committing peer validates:
  - **Endorsement policy check** — correct organisations signed.
  - **MVCC Check** — RW Set is still valid against current world state (no conflicting writes since simulation).
- Valid transactions → applied to world state AND written to immutable ledger.
- Invalid transactions → marked as invalid on ledger but NOT applied to world state.

**Step 7 — Notify:**

- Committing peers send events to subscribed client applications notifying of success or failure.

---

## Q5.2 — Describe the three-phase / multiple-step process in Hyperledger Fabric that ensures all peers keep ledgers consistent. / Explain Hyperledger Fabric V1 Architecture. *(qp2, qp3, qp6)*

**Answer:**

**Hyperledger Fabric — Three Core Operations:**

**Phase 1 — Execute (Simulate):**

- Endorsing peers execute the proposed transaction against chaincode.
- The execution is speculative — produces a Read-Write set without updating the ledger.
- Captures what state would change (write set) and what state was read (read set).
- Multiple endorsers execute independently for consistency checking.

**Phase 2 — Order:**

- Ordering service receives endorsed transaction proposals.
- Sorts transactions into a deterministic, total order.
- Groups them into blocks.
- Broadcasts blocks to all peers on the channel.
- This phase separates ordering from execution — enabling high throughput.

**Phase 3 — Validate and Commit:**

- All peers (committing peers) receive the block from the ordering service.
- Each peer independently validates:
  - All required endorsements are present.
  - No conflicting reads/writes between transaction simulation and current state (MVCC check).
- Valid transactions update the world state. All transactions (valid or not) are written to the ledger for audit purposes.

**Why this ensures consistency:**

- Execute → ensures deterministic output (MVCC eliminates non-determinism).
- Order → ensures all peers see transactions in the same sequence.
- Validate → ensures each peer applies only valid, consistently ordered transactions.

**Architecture Components:**

```
┌─────────────────────────────────────────────────────┐
│                  Client Application                 │
│              (SDK: Node.js, Java, Go)               │
└─────────────────────┬───────────────────────────────┘
                      │ Transaction Proposal
          ┌───────────▼──────────────┐
          │    Endorsing Peers       │  ← Execute chaincode
          │  (Org1 Peer, Org2 Peer)  │    Generate RW Sets
          └───────────┬──────────────┘
                      │ Endorsed Transaction
          ┌───────────▼──────────────┐
          │    Ordering Service      │  ← SOLO / Kafka / RAFT
          │  (creates ordered blocks)│
          └───────────┬──────────────┘
                      │ Block
    ┌─────────────────▼──────────────────────┐
    │        All Committing Peers            │
    │  Validate → Update World State + Ledger│
    └────────────────────────────────────────┘
```

---

## Q5.3 — What type of blockchain network does the Hyperledger Fabric figure support? What can be gathered from the figure? How does a new user enrol? *(qp1)*

**Answer:**

**Type of Blockchain Network:**

Hyperledger Fabric supports a **permissioned consortium/private blockchain network**. Evidence:

- Certificate Authorities (CA) control who can join.
- Membership Service Providers (MSP) manage identities.
- Not open to anonymous participants — each organisation has a verified identity.
- Multiple organisations collaborate under shared governance.

**Information from the Architecture Figure:**

1. Multiple organisations (e.g., Org1, Org2) each have their own peers.
2. Ordering service handles transaction sequencing (SOLO or Kafka/RAFT).
3. Certificate Authority (Fabric-CA) manages digital certificates for each org.
4. Channel configuration defines which peers participate in which channel.
5. Smart contracts (chaincode) are installed on peers and instantiated per channel.
6. Ledger is replicated across committing peers within each channel.

**Steps for a New User to Enrol:**

1. **Identity Registration:** New user's organisation admin registers the user with the **Fabric-CA** (Certificate Authority).
2. **Enrollment:** User enrolls by requesting an **ECert** (Enrollment Certificate) from Fabric-CA, providing proof of their registered identity. ECert = long-term identity certificate.
3. **Wallet Configuration:** The ECert and private key are stored in the user's **wallet** (credential store).
4. **Gateway Connection:** User's application connects to the network via a **gateway** using their wallet credentials.
5. **Channel Membership:** The user's MSP (Membership Service Provider) validates the user's certificate for transactions on specific channels.
6. **Transaction Submission:** User can now submit transaction proposals — their identity is verified via MSP on every transaction.

---

# 6. Blockchain Security

---

## Q6.1 — Explain any three smart contract attacks. / List security issues and attack vectors on smart contracts. *(UE19CS335, qp2, qp3, qp4, qp6)*

**Answer:**

**Smart Contract Attack Vectors:**

**1. Reentrancy Attack:**

**How it works:**

1. Victim contract has a `withdraw()` function that sends ETH before updating the balance.
2. Attacker deploys a malicious contract with a `receive()` fallback that re-calls `withdraw()`.
3. When victim sends ETH to attacker, the fallback triggers before the victim's balance is zeroed.
4. `withdraw()` is called again with the old (non-zero) balance → repeated drain.

**Real example:** The DAO hack (2016) — $60 million drained.

**Vulnerable Code:**

```solidity
function withdraw() public {
    uint amount = balances[msg.sender];
    (bool ok,) = msg.sender.call{value: amount}("");  // sends ETH → triggers attacker fallback
    balances[msg.sender] = 0;  // ← too late! re-entered before this runs
}
```

**Fix:** Update state BEFORE external call (Checks-Effects-Interactions pattern).

---

**2. Integer Overflow / Underflow:**

**How it works:**

- Solidity integers have fixed sizes. `uint8` max = 255. Adding 1 to 255 wraps to 0 (overflow).
- `uint8` min = 0. Subtracting 1 from 0 wraps to 255 (underflow).
- Attackers exploit this to bypass balance checks, mint tokens, or gain unauthorized access.

**Example:**

```
uint8 balance = 0;
balance -= 1;  // → 255 (!) attacker now has maximum balance
```

**Fix:** Use Solidity ≥ 0.8.0 (built-in checks) or SafeMath library.

---

**3. Front-Running (Transaction Ordering Dependency):**

**How it works:**

- All transactions are publicly visible in the mempool before mining.
- An attacker (bot/miner) sees a profitable pending transaction (e.g., large DEX trade).
- Attacker submits the same or related transaction with a higher gas fee to get mined first.

**Sandwich Attack example:**

1. Alice submits: buy 100 ETH worth of Token X (in mempool).
2. Bot sees this → submits buy order for Token X with higher gas → mined first → price rises.
3. Alice's buy executes at higher price.
4. Bot immediately sells → profits from Alice's price impact.

**Fix:** Commit-reveal schemes; private transaction relays (Flashbots).

---

**4. DoS with Block Gas Limit / Block Stuffing:**

**How it works:**

- Every Ethereum block has a gas limit.
- An attacker floods the network with high-gas transactions filling every block.
- Legitimate transactions are excluded from blocks — DoS on the network.
- Alternatively, a contract with an unbounded loop can hit the block gas limit, reverting and blocking progress.

**Example:** A contract that loops over an unbounded array:

```solidity
function processAll() public {
    for(uint i = 0; i < users.length; i++) { ... }  // ← fails if users grows too large
}
```

**Fix:** Avoid unbounded loops; use pagination; separate refunds from logic.

---

**5. Unchecked External Calls:**

**How it works:**

- `address.call()` and `address.send()` return a boolean indicating success/failure.
- If the return value is not checked, the contract proceeds as if the call succeeded even when it failed.

**Fix:** Always check return values; use `require(success)`.

---

## Q6.2 — Give any two DDoS attacks targeting server resources. / How does DDoS work? List types and explain one in detail. *(UE19CS335, qp6)*

**Answer:**

**DDoS (Distributed Denial of Service):** An attacker marshals thousands of compromised computers (botnet) to simultaneously flood a target with requests, exhausting its resources and making it unavailable to legitimate users.

**Two DDoS Attacks Targeting Server Resources:**

**1. Resource Exhaustion Attack (HTTP Flood):**

- Attacker sends millions of legitimate-looking HTTP GET/POST requests to a web server.
- Server CPU and memory are consumed processing each request.
- Legitimate users' requests are queued indefinitely or rejected.
- **In Blockchain context:** Flood smart contract with computationally expensive function calls → deplete node resources.
- **Mitigation:** Rate limiting, WAF (Web Application Firewall), CDN offloading.

**2. Transaction Spam (Mempool Flooding):**

- Attacker submits thousands of low-fee or computationally expensive transactions to the blockchain.
- Mempool fills up → legitimate transactions cannot get included in blocks.
- Network congestion → gas prices spike → effectively DDoS on users.
- **Real example:** CryptoKitties clogged Ethereum in 2017 — transaction backlog grew to 30,000+.
- **Mitigation:** Minimum fee requirements; mempool eviction policies; gas price prioritisation.

**Types of DDoS Attacks:**

1. **Network Layer (Volumetric):** UDP flood, ICMP flood — overwhelm bandwidth.
2. **Protocol Attacks:** SYN flood — exploit TCP handshake; exhausts connection state tables.
3. **Application Layer:** HTTP flood, Smart Contract flood.
4. **Resource Exhaustion:** Exhaust CPU/memory/storage.
5. **Consensus Mechanism DoS:** Mining pool flooding, validator flooding.
6. **Sybil-based DoS:** Create thousands of fake nodes to overwhelm the P2P layer.

**Blockchain DDoS Mitigation:**

- **Gas fees** serve as economic deterrents (spamming costs money).
- **Mempool filtering** — reject below-minimum-fee transactions.
- **Rate limiting per IP/node.**
- **Geographic distribution** of nodes eliminates single-target vulnerability.
- **CDN** for DApp frontends.

---

## Q6.3 — What do you mean by selfish mining? Explain with an example. *(UE19CS335, qp6)*

**Answer:**

**Selfish Mining:**

Selfish mining is a strategy where a miner (or pool) finds a valid block but intentionally **withholds it** from the public blockchain, creating a private fork. The selfish miner continues mining on this private chain, gaining a lead over honest miners. It then strategically releases its chain to orphan honest miners' work and claim disproportionate rewards.

**The Process:**

1. **Private Block Found:** Selfish miner finds valid block B1; does NOT broadcast it.
2. **Private Chain Extension:** Continues mining secretly: B1 → B2 (private).
3. **Honest Miners Catch Up:** Honest miners find their own block B1' (broadcasted).
4. **Strategic Release:** Selfish miner immediately releases B1 (if honest chain is at B1') or waits until honest chain is about to surpass the private chain.
5. **Network Adopts Longer Chain:** If selfish miner releases B1→B2 when honest chain is at B1', the selfish chain wins (2 blocks > 1 block). Honest B1' becomes orphaned.
6. **Disproportionate Reward:** Selfish miner earns rewards for B1 and B2; honest miners wasted resources on orphaned B1'.

**Example:**

```
Network state: ... → Block N
Selfish miner finds Block N+1 → withholds it (private chain)
Honest miner finds Block N+1' → broadcasts it (network adopts)

Selfish miner now has: N → N+1 (private, 2 blocks lead)
Honest network has:    N → N+1' (1 block)

Selfish miner releases N+1 → N+2 (private)
Network sees two chains: N+1' (length 1) vs N+1→N+2 (length 2)
Network switches to longer chain → N+1' is ORPHANED

Selfish miner earned: 2 block rewards
Honest miners earned: 0 (their N+1' was orphaned)
```

**Impact:**

- Selfish miner earns MORE than their fair share of hash power.
- As more miners adopt selfish mining (rational), mining centralises.
- Undermines the security model of PoW.

**Mitigation:**

- Modify protocol to penalise withheld blocks.
- Ethereum's "uncle rewards" — orphaned blocks earn partial rewards, reducing selfish mining incentive.
- Statistical monitoring to detect abnormal orphan rates in large pools.

---

## Q6.4 — Explain: Sybil and DDoS attacks; Transaction Malleability attack and Time Jacking. *(qp1)*

**Answer:**

**1. Sybil Attack:**

An attacker creates a large number of fake identities (nodes) to gain disproportionate influence over the P2P network.

**Mechanism:**

1. Attacker creates 1,000 fake node identities.
2. Victim's peer connections are filled with attacker-controlled nodes.
3. All transactions from the victim are routed through attacker nodes.
4. Attacker can: relay false information, censor transactions, enable double-spending.

**Prevention:** PoW makes fake nodes expensive (computational cost); PoS requires real staked funds; PoA requires verified identities.

**2. DDoS Attack:** (See Q6.2 above)

**3. Transaction Malleability Attack:**

An attacker modifies a transaction's identifier (TXID/hash) WITHOUT changing the transaction's actual effect.

**Mechanism:**

1. Transaction T is broadcast (signed by Alice) with TXID = hash(T).
2. Attacker slightly modifies the signature encoding (still valid) → creates T' with different TXID.
3. Both T and T' have the same effect (Alice sends Bob 1 BTC).
4. T' gets mined. Exchange/wallet tracking by TXID thinks T "failed" (since TXID of T doesn't appear on-chain).
5. Alice resends T → double-spend (or exchange mistakenly processes twice).

**Historical example:** Mt. Gox exchange collapse partially attributed to this attack.

**Fix:** SegWit (Segregated Witness) — separates signature data from the data used to compute TXID, making TXIDs non-malleable.

**4. Time Jacking:**

An attacker manipulates the network time perceived by a victim node by surrounding it with Sybil nodes that report incorrect timestamps.

**Mechanism:**

1. Bitcoin nodes maintain "adjusted network time" based on median of peer timestamps.
2. Attacker connects many fake peers reporting wrong times.
3. Victim's internal clock shifts.
4. Too far ahead → victim rejects valid blocks as "too old."
5. Too far behind → victim mines on an old chain, creating forks.
6. Attacker exploits the desynchronised node for double-spending or censorship.

**Prevention:** Bitcoin Core limits clock adjustment to ±70 minutes from system clock; relies more on system time than peer timestamps.

---

## Q6.5 — What do you mean by reentrancy attack? / Explain DoS with block gas limit with an example. *(qp1)*

**Answer:**

**Reentrancy Attack:** (See Q6.1 — detailed above)

**Example with code:**

```solidity
// Attacker Contract
receive() external payable {
    if (address(victim).balance > 0) {
        victim.withdraw();  // re-enters victim before balance zeroed
    }
}
```

**DoS with Block Gas Limit:**

**Background:** Every Ethereum block has a maximum gas limit (~30 million gas post-Merge). Every computation costs gas. If a transaction requires more gas than the block limit, it reverts.

**Attack Type 1 — Unbounded Loop DoS:**

```solidity
address[] public users;

function refundAll() public {
    for (uint i = 0; i < users.length; i++) {
        payable(users[i]).transfer(amounts[i]);  // ← if users.length is 10,000, this hits gas limit
    }
}
```

- If `users` grows large enough, `refundAll()` can never be called successfully.
- Contract funds are permanently locked — **stuck state DoS**.

**Attack Type 2 — Block Stuffing:**

- Attacker submits transactions that fill entire blocks with high gas fees.
- Legitimate transactions cannot be included — effectively a DoS on the network.
- Used to prevent time-sensitive liquidations in DeFi (e.g., during market crashes).

**Fix:**

- Use **pagination** — process users in batches.
- Use **pull payment pattern** — users individually claim refunds (one transaction per user).
- Set gas limits per function call.
- Avoid unbounded loops over state arrays.

---

## Q6.6 — What are five common attacks encountered on blockchain? / List any five attack surfaces and discuss five attacks. *(qp2, qp4)*

**Answer:**

**Five Common Blockchain Attacks:**

**1. 51% Attack (Majority Attack):**

- Attacker controls >50% of network's hash power (PoW) or stake (PoS).
- Can double-spend, reorganise the chain, and censor transactions.
- Cannot create new coins or steal from wallets directly.
- Example: Ethereum Classic (ETC) suffered a 51% attack in 2020 — 3,693 blocks reorganised, ~5.6M USD double-spent.

**2. Sybil Attack:** (See Q6.4 above)

**3. Eclipse Attack:**

- Attacker controls ALL of a victim node's peer connections.
- Victim sees only attacker-controlled nodes — isolated from the honest network.
- Attacker feeds victim old/false blockchain data.
- Enables double-spending targeting the isolated node.
- **Mitigation:** Diversify peer connections across different ASNs; rate-limit new peer connections.

**4. Routing Attack (BGP Hijack):**

- Attacker manipulates internet routing protocols (BGP) to intercept traffic between blockchain nodes.
- Can partition the network (split into disjoint groups), delay propagation, or modify data in transit.
- **Mitigation:** Encrypted connections (VPN, Tor); multiple ISPs; Route Origin Validation (ROV).

**5. Smart Contract Reentrancy / Overflow:** (See Q6.1 above)

**Five Blockchain Attack Surfaces:**

1. **P2P Network Layer** — Sybil, Eclipse, Routing attacks.
2. **Consensus Mechanism** — 51% attack, Selfish mining, Nothing-at-stake.
3. **Smart Contract Layer** — Reentrancy, Overflow, Front-running.
4. **Wallet/Key Layer** — Private key theft, phishing, malware.
5. **Transaction Layer** — Double-spending, Transaction malleability, Time jacking.

---

## Q6.7 — What is CIA Triad? How does blockchain impact the CIA Triad? *(qp2, qp4)*

**Answer:**

**CIA Triad:**

| Property | Meaning |
|----------|---------|
| **Confidentiality** | Only authorised individuals can access information |
| **Integrity** | Information is not altered by unauthorised individuals; non-repudiation ensured |
| **Availability** | Timely and reliable access to information for authorised users |

**Blockchain's Impact:**

**Confidentiality:**

- **Public Blockchains (Bitcoin, Ethereum):** WEAK confidentiality by design. All transactions are public and traceable. Pseudonymous addresses can be de-anonymised through chain analysis.
- **Private/Permissioned Blockchains (Hyperledger):** STRONG confidentiality — channels restrict data visibility; only authorised organisations see specific transactions.
- **Enhancement tools:** zk-SNARKs (Zcash), Pedersen Commitments (Monero), private channels (Hyperledger).

**Integrity:**

- **STRONG POSITIVE IMPACT** — Blockchain's primary strength.
- Immutable ledger: cryptographic hash chaining means any data modification is immediately detectable.
- Distributed consensus: multiple nodes validate each block — no single party can forge records.
- Digital signatures: every transaction is signed with the sender's private key — authenticity verified.
- Automatic audit trails: complete, timestamped history of all changes.

**Availability:**

- **STRONG** — Decentralisation eliminates single points of failure.
- Data replicated across all nodes — even if 90% of nodes fail, the blockchain persists.
- No central server to DDoS (though individual nodes can be targeted).
- **Caveat:** Smart contract bugs or network congestion can reduce availability.
- **Risk:** Block gas limits can delay transaction processing during peak demand.

**Summary:** Blockchain provides near-perfect Integrity, moderate-to-strong Availability, and variable Confidentiality depending on the blockchain type.

---

## Q6.8 — How can blockchain transform DDoS protection? *(qp2)*

**Answer:**

Traditional DDoS protection relies on centralised services (Cloudflare, Akamai) — themselves potential targets. Blockchain enables a fundamentally decentralised approach:

**1. Decentralised DNS:**

- Traditional DNS: centralised DNS servers can be overwhelmed or manipulated.
- Blockchain DNS (Ethereum Name Service, Handshake): Domain records stored on-chain — no central DNS server to DDoS.
- Attackers cannot flood or corrupt decentralised DNS records.

**2. Distributed Content Delivery:**

- IPFS + blockchain: content stored across thousands of nodes.
- Attacker must attack all nodes simultaneously — computationally infeasible.
- Content is retrieved from the nearest available node — inherently load-balanced.

**3. Economic Deterrent via Micro-transactions:**

- Smart contracts can require a small payment (stake) to send requests.
- Legitimate users are refunded. Attackers making thousands of fake requests lose their stake.
- Makes large-scale DDoS economically unprofitable.

**4. Distributed Firewall via Token-Based Access:**

- Only authenticated token holders can access services.
- Removes anonymous flood traffic — each request must be signed by a valid key.

**5. Anomaly Detection via Blockchain Logging:**

- All request attempts recorded immutably on-chain.
- Machine learning models analyse patterns to identify and pre-emptively block attack traffic.

**6. Reputation-Based Peer Selection:**

- P2P networks can use blockchain to track node reputation.
- Nodes that participate in DDoS attacks lose reputation tokens → automatically excluded from the network.

---

## Q6.9 — Ethereum-based real estate rental challenges and solutions. *(qp1)*

**Answer:**

**Challenges in Ethereum-Based Property Rental:**

| Challenge | Description |
|-----------|-------------|
| **Scalability** | Ethereum processes ~15-30 TPS. High-volume rental platforms need much higher throughput |
| **Gas Fees** | Ethereum gas fees can make small rental transactions (deposits, weekly payments) economically unviable |
| **Smart Contract Immutability** | Bugs in the rental contract cannot be fixed without complex proxy upgrades |
| **Legal Enforceability** | Smart contracts may not be legally recognised as binding contracts in all jurisdictions |
| **Oracle Dependency** | Real-world events (property condition, identity verification) require trusted oracles |
| **Privacy** | All transactions visible on public Ethereum — rental payment history exposed |
| **Key Management** | Tenants must manage private keys — loss = no access to funds or property records |
| **Dispute Resolution** | Smart contracts cannot handle nuanced disputes (e.g., damage claims) without human arbitration |
| **KYC/AML** | Regulatory requirements for identity verification conflict with pseudonymity |

**Solutions:**

| Challenge | Solution |
|-----------|---------|
| Scalability | Layer 2 solutions (Polygon, Optimistic Rollups, zk-Rollups) — process transactions off-chain, settle on Ethereum |
| Gas Fees | Deploy on L2 networks (Polygon: ~$0.001 per TX vs $5+ on mainnet) |
| Smart Contract Bugs | Upgradeable proxy patterns (OpenZeppelin Transparent Proxy); formal verification; rigorous audits |
| Legal | Work with legal counsel to make contracts legally binding; use e-signature layer alongside smart contract |
| Oracle Dependency | Chainlink oracles for reliable off-chain data; decentralised oracle networks |
| Privacy | Confidential transactions (zk-proofs); private Ethereum networks |
| Key Management | Account abstraction (EIP-4337) — social recovery wallets; multi-sig |
| Disputes | Decentralised arbitration (Kleros, Aragon Court) — encoded as fallback in smart contract |
| KYC/AML | Self-sovereign identity (SSI) solutions; Civic, uPort — verify identity off-chain, prove on-chain with ZK proof |

---

## Q6.10 — Challenges with current DNS and blockchain-based DNS frameworks. *(qp3)*

**Answer:**

**Current DNS Challenges:**

| Challenge | Description |
|-----------|-------------|
| **Centralisation** | DNS controlled by ICANN and registrars — single points of failure and censorship |
| **DNS Spoofing/Poisoning** | Attacker injects fake DNS records → users routed to malicious sites |
| **Censorship** | Governments can force domain seizures or DNS blocking |
| **Lack of Transparency** | DNS record changes not publicly auditable |
| **DDoS Vulnerability** | Central DNS servers can be overwhelmed (e.g., 2016 Dyn DDoS attack took down Twitter, Netflix) |
| **Slow Propagation** | DNS changes can take 24-48 hours to propagate globally |

**Blockchain DNS Frameworks:**

**1. Ethereum Name Service (ENS):**

- Maps `.eth` domains to Ethereum addresses, IPFS hashes, or websites.
- Ownership = NFT stored in smart contract — censorship resistant.
- Transfer, renew, or point to new address via on-chain transaction.
- No central authority can seize a .eth domain.

**2. Handshake (HNS):**

- Decentralises the DNS root zone (currently controlled by ICANN).
- Top-level domains (TLDs) auctioned on-chain — anyone can own a TLD.
- Compatible with standard DNS — Handshake-aware resolvers needed.

**3. Unstoppable Domains:**

- `.crypto`, `.wallet`, `.x`, `.nft` domains.
- One-time purchase — no annual renewal fees.
- Records stored on blockchain — cannot be removed by a registrar.
- Wallets can be addressed by human-readable names.

**How blockchain solves DNS problems:**

- Immutable records → no DNS poisoning possible without private key.
- No central authority → no censorship or seizure.
- Public ledger → all record changes auditable.
- Decentralised → no single DDoS target.

---

## Q6.11 — How will you achieve confidentiality, integrity, and availability with blockchain? / Explain cyber kill chain stages. *(qp4)*

**Answer:**

**Achieving CIA with Blockchain:**

**Confidentiality:**

- Private blockchains / permissioned channels (Hyperledger Fabric channels).
- Encryption of sensitive data off-chain; only hash stored on-chain.
- Zero-knowledge proofs (zk-SNARKs) — prove transaction validity without revealing amounts.
- Access control via smart contracts — only authorised addresses can read data.

**Integrity:**

- SHA-256 cryptographic hashing — any data change detectable.
- Digital signatures — every transaction signed with private key.
- Immutable ledger — cannot alter historical records.
- Merkle trees — efficient integrity verification of any transaction.
- Distributed consensus — no single node can corrupt the truth.

**Availability:**

- Decentralisation — no SPOF; thousands of nodes worldwide.
- Data replication — every node holds a full copy.
- P2P architecture — no central server to DDoS.
- Open participation — any node can join and serve data.
- Layer 2 solutions — improve throughput to prevent congestion-based availability issues.

**Cyber Kill Chain Stages (Lockheed Martin):**

| Stage | Description | Blockchain-specific defence |
|-------|-------------|----------------------------|
| **1. Reconnaissance** | Attacker gathers info about the target blockchain | Limit public node info; use VPN for node connections |
| **2. Weaponisation** | Develop exploit (e.g., smart contract vulnerability scanner) | Formal contract verification; professional audits |
| **3. Delivery** | Deploy malicious smart contract or phishing | Code review; multi-sig for contract deployment |
| **4. Exploitation** | Exploit reentrancy, overflow, etc. | Checks-Effects-Interactions; SafeMath; audits |
| **5. Installation** | Persist malicious code on blockchain (immutable!) | Upgradeable proxies with governance delays |
| **6. Command & Control** | Attacker controls drained funds | Multi-sig wallet; time-locks on large transfers |
| **7. Actions on Objectives** | Double-spend, drain funds, censor txs | Slashing mechanisms; insurance protocols; monitoring |

---

# Quick Reference — Frequently Tested Topics

| Topic | Frequency | Key Papers |
|-------|-----------|-----------|
| RSA Calculation | ⭐⭐⭐⭐⭐ | qp1, qp2, qp3, qp4, qp5, qp6 |
| RAFT Consensus with Log Scenarios | ⭐⭐⭐⭐⭐ | qp3, qp4, qp5 |
| Reentrancy Attack | ⭐⭐⭐⭐ | qp1, qp2, UE19CS335, qp6 |
| PoW vs PoS | ⭐⭐⭐⭐ | qp1, UE19CS335, qp2 |
| Merkle Tree | ⭐⭐⭐⭐ | qp1, qp2, qp3, qp4, qp5 |
| Selfish Mining | ⭐⭐⭐⭐ | UE19CS335, qp6 |
| DDoS Attacks | ⭐⭐⭐⭐ | UE19CS335, qp2, qp6 |
| Hyperledger Fabric Transaction Flow | ⭐⭐⭐⭐ | UE19CS335, qp3, qp6 |
| Smart Contract Types/Benefits | ⭐⭐⭐ | qp1, UE19CS335, qp4, qp6 |
| Nothing at Stake | ⭐⭐⭐ | qp6, qp1 |
| PAXOS Scenarios | ⭐⭐⭐ | UE19CS335, qp1, qp3 |
| PBFT | ⭐⭐⭐ | qp4, qp5 |
| Token Types | ⭐⭐⭐ | qp1, qp6 |
| DApp vs DAO | ⭐⭐⭐ | qp1, qp4, qp6, UE19CS335 |
| CIA Triad + Blockchain | ⭐⭐ | qp2, qp4 |
| Transaction Malleability / Time Jacking | ⭐⭐ | qp1 |
