# Unit 3: Distributed Storage

## 1. Types of Cloud Storage

### Block Storage

- Stores data as fixed-size blocks, each with a unique address
- No metadata beyond the address; OS manages the filesystem on top
- **High performance, low latency** — ideal for databases, VMs
- Examples: AWS EBS (Elastic Block Store), Azure Disk Storage
- Behaves like a raw hard drive attached to a server

### Object Storage

- Stores data as objects — each object has **data + metadata + unique ID**
- Flat namespace (no directories/hierarchy — but paths can be simulated via key conventions)
- Accessed via REST APIs (HTTP GET/PUT/DELETE)
- Designed for **massive scale, unstructured data**
- Examples: **Amazon S3**, Google Cloud Storage, OpenStack Swift
- Use cases: backup, media, logs, ML datasets

### File Storage (NAS)

- Hierarchical filesystem accessible over a network
- Multiple clients can share the same filesystem
- Examples: Amazon EFS, Azure Files, NFS, GlusterFS

---

## 2. Amazon S3 (Simple Storage Service)

### Core Concepts

- **Bucket:** Top-level container for objects; region-specific; globally unique name
- **Object:** Actual data (files). Each object has a **key** (unique name within bucket)
- **Key convention:** Slash-separated paths simulate directory structure (e.g., `images/2024/photo.jpg`)

### Data Protection

1. **Replication:** By default, S3 replicates across multiple storage devices; survives 2 replica failures. RRS (Reduced Redundancy Storage) for non-critical data (1 replica failure tolerance)
2. **Regions:** Store data in specific geographic regions for performance, compliance, or availability
3. **Versioning:** Stores full history of every object version; deletes can be undone

### Security

- **Access control:** Permissions for who can access objects (via AWS Management Console / IAM policies)
- **Audit logs:** S3 access logging stores complete access logs in a different bucket

### Large Objects

- **Multi-part uploads:** Split large objects into parts, upload in parallel; if a part fails, only retry that part

---

## 3. OpenStack Swift (Object Storage)

- **Accounts:** Logical user-space within the system; multiple users/apps access simultaneously
- **Containers:** Groupings of objects (like directories/namespaces); created under accounts
- **Objects:** Actual data stored on disk
- **Ring:** Maps partitions (logical storage locations) to physical disk locations — acts like an index/encyclopedia using hash for lookup
- Partitions are distributed across nodes; adding a node triggers reassignment of partitions

---

## 4. Partitioning

> **Partitioning** is the intentional breaking of a large dataset into smaller partitions, each stored on one or more nodes, enabling parallel query/IO operations.

- **Goal:** Spread data and query load **evenly** across nodes
- Each record belongs to **exactly one partition** (but can be replicated)
- **Skew:** When some partitions have more data/load than others
- **Hot spot:** A partition with disproportionately high load

### 4.1 Vertical Partitioning

- Split by **columns** — different sets of columns go to different stores
- No two critical columns stored together → improves performance

### 4.2 Workload-Driven Partitioning

- Analyze data access patterns → form partitions aligned with workload
- Improves scalability of transactions

### 4.3 Partitioning by Random Assignment

- Randomly assign records to nodes → even distribution
- **Disadvantage:** To read a specific item, must query all nodes in parallel

### 4.4 Horizontal Partitioning

#### 4.4.1 Partitioning by Key Range

- Assign a continuous range of keys to each partition
- Keys sorted within each partition → supports range scans
- **Disadvantage:** Monotonic keys (e.g., timestamps) cause hot spots — all writes go to the latest partition
- Fix: Use a non-timestamp attribute as first key element

#### 4.4.2 Schema-Based Partitioning

- Minimize distributed transactions by keeping related rows in the same partition

#### 4.4.3 Graph Partitioning

- Workload-based static partitioning by analyzing data access patterns
- No repartitioning after initial split

#### 4.4.4 Partitioning by Hash of Key

- Apply hash function to key → assign partition based on hash range
- Avoids hot spots and skew; even distribution
- **Disadvantage:** Loses ability to do efficient range queries
- **Compound key trick:** Use `(user_id, timestamp)` — hash on user_id, range-sort within partition by timestamp

---

## 5. Consistent Hashing

### Problem: Simple Hash-Modulo Rebalancing

- With `N` nodes, key assigned to `hash(key) mod N`
- If a node is added or removed → almost **all keys** need to be remapped → expensive rehashing

### Solution: Consistent Hashing

> **Consistent Hashing** maps both keys and nodes onto a circular ring (hash ring). Each key is assigned to the nearest node in the clockwise direction. Adding/removing a node only affects keys nearest to it.

**How it works:**

1. Map hash output range onto a circle (0° to 360°)
2. Hash both keys and server names → place both on the circle
3. Each key is owned by the **first server clockwise** from it
4. Adding a server: only keys between it and its predecessor clockwise must move
5. Removing a server: only its keys move to the next server clockwise

**Benefit:** Only `K/N` keys need to move (K = total keys, N = nodes) — far less than naive rehashing

---

## 6. Partitioning with Secondary Indexes

### Primary Key Routing

- If records are accessed only by primary key → route directly to partition owning that key

### Secondary Indexes

- Don't identify records uniquely; used to find records by attribute values (e.g., "find all red cars")
- Two approaches:

#### 6.1 Document-Based Partitioning (Local Index)

- Each partition maintains its own secondary index — only covers documents in that partition
- **Reads:** Must query **all** partitions (scatter/gather) → expensive
- Prone to **tail latency amplification**

#### 6.2 Term-Based Partitioning (Global Index)

- A single global index covering all partitions, partitioned separately by term (or hash of term)
- **Reads:** Client queries only the partition holding the required term → efficient
- **Writes:** A single write may affect multiple index partitions → slower, more complex
- Often updated **asynchronously** → index may be briefly stale after writes

---

## 7. Rebalancing Partitions

> Rebalancing = moving data/load from one node to another when the cluster changes.

**Triggers for rebalancing:** Increased load, dataset growth, node failures, new nodes joining

**Minimum requirements:**

- Load shared fairly after rebalancing
- Database continues accepting reads/writes during rebalancing
- Minimal data movement (reduce network/disk I/O)

### Strategies

#### Fixed Number of Partitions

- Create many more partitions than nodes (e.g., 20 partitions for 4 nodes)
- New node steals partitions from existing nodes until balanced
- Simple; good when dataset size is stable
- Choosing the right partition count is hard for variable datasets

#### Dynamic Partitioning

- Partition splits when it exceeds a size threshold → one half can move to another node
- Partition merges when it shrinks below a threshold
- Adapts to total data volume
- **Issue:** Starts with a single partition (bottleneck) until first split

#### Partitioning Proportional to Nodes

- Fixed number of partitions **per node**
- New node randomly picks existing partitions to split; takes ownership of half
- Partition sizes stay stable as cluster grows

---

## 8. Request Routing

**Service Discovery Problem:** When partitions move across nodes, how does a client know which node handles a given key?

### Approaches

| Approach | Description |
|---|---|
| **Client → Any Node** | Round-robin; node forwards if it doesn't own the partition |
| **Routing Tier** | Clients hit a dedicated load balancer that knows partition-to-node mapping |
| **Client-side Routing** | Client is partition-aware; connects directly to the right node |
| **ZooKeeper** | Authoritative mapping stored in ZooKeeper; routing tiers subscribe to updates |

**ZooKeeper-based Request Routing:**

- Each node registers itself in ZooKeeper
- ZooKeeper maintains authoritative partition-to-node mapping
- Routing tier or clients subscribe to ZooKeeper for updates
- Used by: HBase, SolrCloud; Cassandra/Riak use gossip protocol instead

---

## 9. Replication

> **Replication** = keeping a copy of the same data on multiple machines connected via a network.

**Reasons for Replication:**

1. Keep data geographically close to users (reduce latency)
2. System continues if some parts fail (increase availability)
3. Scale read throughput across multiple machines

**Each node holding a copy = replica**

### 9.1 Leader-Based (Single-Leader) Replication

- One replica is designated **Leader** (also called primary/master)
- All **writes** must go to the leader
- Leader writes to local storage → sends **replication log** to **followers** (read replicas)
- Followers apply writes in the same order as leader
- **Reads** can go to any replica (leader or followers)
- Used by: PostgreSQL, MySQL, Kafka, RabbitMQ

#### Synchronous vs Asynchronous Replication

| Type | Behavior | Tradeoff |
|---|---|---|
| **Synchronous** | Leader waits for follower confirmation before reporting success | Strong durability; but follower downtime blocks writes |
| **Asynchronous** | Leader sends to follower but doesn't wait | Higher availability; risk of data loss on leader failure |
| **Semi-sync** | One sync + rest async (common practice) | Balance of durability and availability |

#### Implementation of Replication Logs

1. **Statement-based:** Log every write SQL statement and replay on followers (fragile for non-deterministic functions)
2. **Write-Ahead Log (WAL) shipping:** Send the raw byte-level log file to followers
3. **Logical log (CDC):** Row-level changes (change data capture); allows different storage engines
4. **Trigger-based:** Application-layer replication using DB triggers

#### Handling Failures

- **Follower failure:** Follower replays its local log from last known good transaction → catchup recovery
- **Leader failure (Failover):** A follower is promoted to leader; clients reconfigured; other followers point to new leader

#### Replication Lag

- Followers may be behind the leader in asynchronous setups
- **Eventual consistency:** Followers will eventually catch up if writes stop
- **Replication lag:** Time between write on leader and its reflection on followers
- **Solutions:** Read from leader for critical data; monotonic reads (same replica per user); consistent prefix reads

---

### 9.2 Multi-Leader Replication

- More than one node accepts writes
- Each leader acts as a follower to the other leaders
- Also called **master-master** or **active-active** replication

**Use cases:**

- Multi-datacenter: one leader per datacenter
- Clients with offline operation (each device is its own leader locally)
- Collaborative editing (e.g., Google Docs)

**Challenges — Write Conflicts:**

- Two leaders may accept conflicting writes to the same data
- Solutions:
  1. **Conflict avoidance:** Route all writes for a record through the same leader
  2. **Last-write-wins (LWW):** Use unique ID (timestamp/UUID); highest ID wins
  3. **Custom conflict resolution logic:** Application code handles conflicts on write or read

**Topologies:**

- **Circular:** Each node receives from one neighbor, forwards to next
- **Star:** One root node forwards to all
- **All-to-all:** Every node communicates with every other (most fault-tolerant)

**Single-Leader vs Multi-Leader:**

| Factor | Single-Leader | Multi-Leader |
|---|---|---|
| Write latency | Higher (writes go to one DC) | Lower (local DC processes) |
| Datacenter outage | Failover needed | Others continue operating |
| Network partition | Very sensitive | More tolerant |
| Conflict risk | None | Possible write conflicts |

---

### 9.3 Leaderless Replication

- All nodes are **peers** — all accept reads AND writes
- No bottleneck of a single leader
- A write is successful when acknowledged by **quorum** of at least `k` out of `n` replicas

**Write:** Client broadcasts to all replicas; waits for `k` ACKs (write quorum)

**Read:** Client queries all replicas; accepts value when `k` out of `n` agree (read quorum)

**Handling stale reads:**

- **Read repair:** Client detects stale value from a replica → writes newer value back
- **Anti-entropy:** Background process constantly checks for differences across replicas

**Potential issue:** A node that was down when a write happened may serve stale data when it comes back online

**Solution:** Read from multiple nodes; use version numbers to determine newest value

---

## 10. Consistency Models

### Eventual Consistency

- Replicas will eventually converge to the same value if writes stop
- Common in leaderless and async multi-leader setups

### Read-Your-Writes (Read-after-Write Consistency)

- A user always sees their own latest writes when re-reading data

### Monotonic Reads

- A user never sees data "going back in time" — if they see version X, they always see ≥ X on future reads
- Implementation: Always route the same user to the same replica

### Consistent Prefix Reads

- If a sequence of writes happens in order A → B → C, readers see them in the same order

### Strong (Linearizable) Consistency

- Reads always return the most recently written value
- Expensive: all reads must go to the leader

---

## 11. CAP Theorem

> In a distributed system, you can only guarantee **two out of three** of: **Consistency, Availability, Partition Tolerance**. — Eric Brewer, 2000

| Property | Meaning |
|---|---|
| **Consistency (C)** | All nodes see the same data at the same time (linearizability) |
| **Availability (A)** | Every request receives a response (not guaranteed to be the most recent) |
| **Partition Tolerance (P)** | System continues operating despite network partitions |

> **Key insight:** Network partitions are unavoidable in distributed systems. So the real choice is between **C and A** during a partition.

### CAP Trade-offs

| Choice | Behavior |
|---|---|
| **CP (Consistent + Partition Tolerant)** | System may reject requests during a partition to stay consistent. E.g., HBase, Zookeeper |
| **AP (Available + Partition Tolerant)** | System returns (possibly stale) data during a partition. E.g., Cassandra, CouchDB |
| **CA (Consistent + Available)** | Only possible without partitions — impractical for distributed systems |

### Criticisms of CAP

- CAP ignores latency — in practice, timeouts act as partitions
- CAP suggests a binary choice; in reality, it's a continuum with multiple consistency levels
- Eventual consistency ≠ "any consistency" — there are gradations (Read-your-writes, monotonic reads, causal consistency)

### CAP in Practice

- **PostgreSQL (CA):** Used in single-node or tightly coupled setups; sacrifice partition tolerance
- **Cassandra (AP):** Best for high availability; accepts eventual consistency
- **HBase, Zookeeper (CP):** Prioritize consistency; may reject requests during partitions

---

## 12. Transactions

### What is a Transaction?

- A set of operations that must **all succeed or all fail together**
- If any step fails → **abort** and revert to state before transaction started

**Basic Transaction Primitives:**

- `BEGIN TRANSACTION`
- `END TRANSACTION` (try to commit)
- `ABORT TRANSACTION` (rollback)

### ACID Properties

| Property | Description |
|---|---|
| **Atomic** | All or nothing — no partial results visible to others |
| **Consistent** | System invariants hold before and after (e.g., total money in all accounts unchanged) |
| **Isolated (Serializable)** | Concurrent transactions yield the same result as serial execution |
| **Durable** | Committed results are permanent; no failure will revert them |

### Nested Transactions

- Top-level transaction spawns sub-transactions
- Sub-transaction commits are provisional until parent commits
- Solution: **Private workspace** — each sub-transaction works on a copy; on commit, copy replaces parent's data

### Distributed Transactions

- Operations span two or more data stores across different systems
- Challenge: machine, software, and network failures while preserving ACID
- Two outcomes: all operations commit, or none commit (no partial completion)

---

## 13. Two-Phase Commit Protocol (2PC)

> 2PC ensures **atomicity** across multiple sites in a distributed transaction.

**Participants:**

- **Transaction Coordinator (TC):** Orchestrates the commit/abort decision
- **Transaction Managers (TMs):** One per site; manage local execution

### Phase 1 – Voting (Prepare)

1. Coordinator writes `PREPARE T` to its log
2. Coordinator sends `prepare T` to all sites
3. Each site prepares its local component:
   - If **ready:** enters pre-committed state, writes `Ready T` to log, sends `Ready T` to coordinator
   - If **not ready:** writes `Don't Commit T`, sends `Don't Commit T`
4. Coordinator waits for all responses

### Phase 2 – Commit/Abort (Decision)

**If all sites send Ready T:**

- Coordinator writes `Commit T`, sends `commit T` to all sites
- Each site commits, releases locks, writes `Commit T`, sends `Done`

**If any site sends Don't Commit T:**

- Coordinator writes `Abort T`, sends `abort T` to all sites
- Each site rolls back, releases locks, writes `Abort T`, sends `Done`

**Coordinator cleanup:** After receiving all `Done` messages, clears transaction state

```
Phase 1:                          Phase 2:
Coordinator → prepare T →         Coordinator → commit T (or abort T) →
All sites → Ready T or            All sites → Done
           Don't Commit T →
Coordinator
```

### Limitations of 2PC

- **Blocking:** Coordinator failure after Phase 1 leaves participants stuck in "uncertain" state holding locks
- **Performance:** All participants must respond before commit; slow participants block the transaction

---

## Summary Diagram

```
Cloud Storage Types:
├── Block Storage (low-level, high-perf, e.g. EBS)
├── Object Storage (REST API, massive scale, e.g. S3)
└── File Storage (shared filesystem, e.g. EFS)

Partitioning:
├── Key Range → range scans, risk of hot spots
├── Hash → even distribution, no range scans
├── Consistent Hashing → minimal remapping on topology change
└── Secondary Indexes → local (scatter/gather) vs global (term-partitioned)

Replication:
├── Single Leader → writes to leader, reads from any
├── Multi-Leader → multiple DCs, write conflicts possible
└── Leaderless (Dynamo-style) → quorum reads/writes

Consistency:
├── Eventual → replicas converge eventually
├── Monotonic Reads → no time-travel reads
├── Read-Your-Writes → user sees own latest writes
└── Strong / Linearizable → always latest value

CAP Theorem: Pick 2 (during a partition, pick C or A)
ACID: Atomic, Consistent, Isolated, Durable
2PC: Phase 1 (vote) + Phase 2 (commit/abort)
```

---

## Key Terms

| Term | Definition |
|---|---|
| Partition | Division of a large dataset across multiple nodes |
| Consistent Hashing | Hash ring technique minimizing key remapping on topology changes |
| Hot Spot | Partition with disproportionately high load |
| Skew | Uneven distribution of data or load across partitions |
| Replica | A copy of data on a different node |
| Leader | Node in leader-based replication that accepts all writes |
| Follower | Read replica that receives changes via replication log |
| Replication Lag | Delay between a write on the leader and its reflection on a follower |
| Eventual Consistency | Replicas will converge if writes stop |
| Quorum | Minimum number of replicas that must agree for a read/write to succeed |
| CAP Theorem | Consistency, Availability, Partition Tolerance — choose 2 |
| ACID | Atomic, Consistent, Isolated, Durable — properties of transactions |
| 2PC | Two-Phase Commit — distributed atomicity protocol |
| Scatter/Gather | Read from all partitions and combine results (used with local secondary indexes) |
| WAL | Write-Ahead Log — technique for replication log shipping |

---