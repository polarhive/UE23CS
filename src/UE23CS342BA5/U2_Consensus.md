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
