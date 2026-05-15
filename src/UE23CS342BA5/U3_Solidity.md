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
