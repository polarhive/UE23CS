# Dataflow and Integrity

# P2P vs Distributed Systems

> Peer-to-peer networks are a special kind of distributed systems.

-  They consist of individual computers (also called nodes), which make their computational resources (e.g., processing power, storage capacity, data or network band- width) directly available to all other members of the network without having any central point of coordination.
- Peer-to-peer systems have interesting applications such as file sharing, content distribution, and privacy protection.
- Most of these applications utilize a simple but powerful idea: turning the computers of the users into nodes that make up the whole distributed system.

## The Definition of a Peer-to-Peer System

- Peer-to-peer systems are distributed software systems that consist of nodes (individual computers), which make their computational resources (e.g., processing power, storage capacity, or information distribution) directly available to another.
- When joining a peer-to-peer system, users turn their computers into nodes of the system that are equal concerning their rights and roles.
- Although users may differ with respect to the resources they contribute, all the nodes in the system have the same functional capability and responsibility.

## The Link Between Peer-to-Peer Systems and the Blockchain

- The blockchain can be considered a tool for achieving and maintaining integrity in distributed systems.
- Purely distributed peer-to-peer systems may use the blockchain in order to achieve and to maintain system integrity.
- Hence, the link between purely distributed peer-to-peer systems and the blockchain is its usage for achieving and maintaining integrity in purely distributed systems.
- Blockchain leverages the P2P network technology to provide a decentralised ledger for one or more digital assets

## Disambiguating the Term: Blockchain

- Blockchain is an algorithm and distributed data structure for managing electronic cash without a central administrator among people who know nothing about one another.
- Blockchain is a Distributed Ledger Technology (DLT) that was invented to support the Bitcoin cryptocurrency.
- Blockchain is a special instance of Distributed Ledger Technologies (DLTs), almost all of which have emerged in Bitcoin's wake.
- **Generations**:
- *Blockchain 1.0: The Origin of the Modern Blockchain*
- *Blockchain 2.0: Smart Contracts*
- *Blockchain 3.0: Decentralized Enterprise Level Application*

## Blockchain Trust Model

The blockchain trust model refers to the mechanism by which trust is established and maintained in a blockchain system without relying on centralized entities or intermediaries. It leverages cryptographic techniques, consensus algorithms, and distributed ledger technology to enable trust among participants in the network.

## Key Features

- Anonymity
- Immutability
- Transparency
- Peer to peer
-  Distributed and decentralized apps
- Logical computation

## Applications

- Cryptocurrencies
	- Applications: Bitcoin, Ethereum, Litecoin.
	- Use: Digital currency transactions and decentralized financial systems.
- Smart Contracts
- Applications: Ethereum, Cardano, Hyperledger Fabric.
	- Use: Automating agreements and reducing the need for intermediaries.
- Supply Chain Management
- Applications: IBM Food Trust, VeChain.
	- Use: Enhancing transparency, traceability, and reducing fraud in supply chains.
- Healthcare
- Applications: Medicalchain, Patientory.
	- Use: Securely managing and sharing patient data.
- Decentralized Finance (DeFi)
- Applications: Uniswap, Aave, Compound.
- Use: Peer-to-peer financial services like lending, borrowing, and trading.

---

#todo

---

# SHA 256

#todo

## Merkle Trees

The blockchain is a proficient combination of two hash-based data structures

1. **Linked list:** This is the structure of the blockchain itself, which is a linked list of hash pointers. A regular linked list consists of nodes. Each node has 2 parts- data and pointer. The pointer points to the next node. In the blockchain, simply replace the regular pointer with a hash pointer.
2. **Merkle tree:** A Merkle tree is a binary tree formed by hash pointers, and named after its creator, Ralph Merkle

![[Screenshot 2026-01-20 at 09.26.00.png]]

## Merkle Tree

A Merkle tree is a binary tree formed by hash pointers, and named after its creator, Ralph Merkle.

A Merkle Tree is a hierarchical data structure that organizes transactions or data in a tree format. It uses cryptographic hashes to ensure data integrity.

Efficiently verify the integrity and consistency of large data sets in blockchain.

1. Leaf Nodes: Hashes of individual transactions.
2. Intermediate Nodes: Hashes of concatenated child nodes.
3. Merkle Root: Single hash representing the entire data set.

![[Pasted image 20260120092632.png]]

## How a Merkle Tree Works

1. Hash Transactions: Each transaction (T1, T2, etc.) is hashed using SHA-256.
2. Combine and Hash: Pair adjacent hashes, concatenate them, and hash again.
3. Repeat: Continue combining and hashing until a single hash remains: the Merkle Root.

## Proof of Membership

A very interesting feature of the Merkle tree is that it provides proof of membership.

### Merkle proof is used to decide

1. If data belongs to a particular Merkle tree.
2. To prove data belongs to a set without the need to store the whole set.
3. To prove a certain data is included in a larger data set without revealing the larger data set or its subsets.

### Example

> Let us say we need to prove that transaction ‘a’ is part of this Merkle tree.

Everyone in the network will be aware of the hash function used by all Merkle trees.

1. 2. H(a) = Ha as per the diagram.

> The hash of Ha and Hb will be Hab, which will be stored in an upper-level node.

3. Finally hash of Hab and Hcd will give Habcd.

> This is the Merkle root obtained by us.

4. By comparing the obtained Merkle root and the Merkle root already available within the block header, we can verify the presence of transaction ‘a’ in this block.

> Task: prove transaction c is a part of the Merkle tree.

---

## Why are Merkle Trees important

- **Data Integrity**: Any small change in the data changes the Merkle Root.
- **Efficient Verification**: Allows verification of specific transactions without storing the full dataset.
- **Scalability**: Handles large numbers of transactions efficiently.
- **Proof of Inclusion**: Enables lightweight verification that a transaction exists in a block.

---

# Blockchain Layers

![[Pasted image 20260123115255.png]]

## Consensus Layer

- The Consensus Layer in a blockchain is the mechanism that ensures all nodes in a decentralized network agree on the state of the blockchain. 
- It plays a vital role in maintaining the integrity, security, and consistency of data across the network.

### Key functions

- Agreement on a **Single Truth**: Ensures all nodes agree on the same version of the blockchain despite being distributed.
- **Validation** of Transactions: Confirms that transactions are valid, preventing issues like double-spending.
- **Decentralization**: Removes the need for a central authority to verify or validate data.
- Network **Security**: Provides resistance against malicious actors attempting to manipulate the blockchain.
- Transaction **Proposal**: Nodes propose new blocks with validated transactions to the network.
- **Consensus** Mechanism: Nodes run a specific consensus algorithm to agree on the next block to be added.
- Block **Confirmation**: Once consensus is reached, the new block is added to the chain, and all nodes update their local copies.
- **Propagation**: The updated blockchain state is shared across the network.

## Compute Layer

The Compute Layer in a blockchain refers to the part of the architecture responsible for processing computations, executing smart contracts, and performing complex logic required by decentralized applications (dApps).

> This layer is particularly crucial for blockchains like Ethereum that offer programmability beyond simple transaction recording.

### Key Functions of the Compute Layer

- Smart Contract Execution
- Decentralized Application (dApp) Logic
- State Management
- Gas Measurement and Resource Management
- Validation of Computations

## Application Layers

- The Application Layer in blockchain refers to the topmost layer where end-user applications and services interact with the blockchain network.
- It provides the interface for users, developers, and systems to utilize the functionalities of the blockchain, such as decentralized applications (dApps), wallets, and decentralized finance (DeFi) solutions.

### Key Functions of the Application Layer

- User Interaction
- Smart Contract Interaction
- Access to Blockchain Services
- Data Presentation and Visualization

---

## What is a Sybil Attack in Blockchain?

- A Sybil attack in blockchain occurs when a single malicious actor creates multiple fake identities (nodes) to gain disproportionate control or influence over the network.
- Sybil Attack works like this:
	- Creating Multiple Identities
	- Disrupting Consensus Mechanisms
	- Influencing the Network

### How Blockchains Mitigate Sybil Attacks

- **Proof of Work (PoW**):
	- Miners must perform computationally intensive work to validate blocks.
	- Creating multiple fake nodes is expensive and infeasible due to resource costs.
- **Proof of Stake (PoS)**:
	- Validators are selected based on the amount of cryptocurrency staked.
	- Creating fake identities requires significant financial investment.
- **Proof of Authority (PoA)**
	- Validators are pre-approved and identified, eliminating anonymity.
- **Transaction** Fees
	- High transaction fees discourage spamming the network with fake identities.
- **Reputation** Systems
	- Nodes build a reputation over time, and malicious nodes are identified and removed.
- **Identity** Verification
	- Some permissioned blockchains require verifiable identities to participate

---

## How the Application Layer Works

- **User Request:**
	- A user interacts with the application (e.g., sending a token via a wallet app).
- **Smart Contract Execution:**
	- The application sends the transaction or request to the smart contract deployed on the blockchain network.
- **Consensus and Validation:**
	- The blockchain processes and validates the transaction via its consensus mechanism.
- **Response and Data Display:**
	- The application layer retrieves the result and presents it to the user (e.g., updated token balance or successful transaction).

---

## Block Structure in Blockchain

![[Pasted image 20260123120015.png]]

- Block **Header**
	- The header of the block contains technical information such as block height, timestamp, previous block’s hash, MerkleRoot hash, etc.
	- Every block has this same set of attributes with a unique hash.
	- The header distinguishes a block from other blocks, as it is a must to recognize each block separately on the blockchain.
- The following are the most common fields in blocks:
	- Block **Height**: A sequential number for each block that is added to the blockchain network. No block will have the same height number.
	- **Timestamp**: The stamp of Unix time shows when the block was added to the blockchain.
	- Previous Block’s **Hash**: A hash of the previously added block helps in maintaining the sequence.
	- **Nonce**: It’s a number that block miners adjust to compute the puzzle for adding a new block to the blockchain.
	- **MerkleRoot Hash**: The hash of all transactions included in the block.

## Block Body

- The body of the block includes all the data stored in the form of transactions.
- It could be cryptocurrency transactions or any value that suggests changes to already existing data on the blockchain.
- Block body attains the most block space, which is filled with transactional data.

## How Data is Stored in Blockchain Blocks

- The process of storing data in blocks relies on the blockchain drivers, such as miners, node operators, and validators.
- These are blockchain participants who use specialized hardware devices and high computational power to solve complex mathematical puzzles to produce blocks.
- This procedure ensures that all the information included in the block is legitimate.
- The process of verifying transactions and producing blocks is a crucial aspect of the blockchain network.

---

# The Proof Paradigm

## Commitments

> *Commitments in blockchain refer to cryptographic schemes that allow a participant to "commit" to a value while keeping it hidden but ensuring that the value cannot be changed later. Commitments ensure binding and hiding properties, which are essential for privacy, integrity, and trust in blockchain systems.*

1. Hiding: The value remains hidden until revealed
2. Binding: The value cannot be changed after commitment
