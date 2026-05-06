# Unit 4: Cloud Controller — Performance, Scalability and Security

## 1. Context of Cloud Control

### What is a Cloud Controller?

The Cloud Controller is the **control plane** of a cloud environment. While previous units focused on data paths (programming models, virtualization, storage), the cloud controller manages the **operational path** — how customer requests are admitted, resources allocated, and services maintained.

### Eucalyptus — Illustrative Example

> **Eucalyptus** is an open-source private/hybrid cloud suite compatible with AWS EC2 and S3 APIs.

| Component                      | Role                                                                                  |
| ------------------------------ | ------------------------------------------------------------------------------------- |
| **UFS (User Facing Services)** | Implements AWS-compatible APIs; handles CLI/GUI requests                              |
| **Cloud Controller (CLC)**     | High-level resource tracking and management; **only one per cloud**                   |
| **Cluster Controller (CC)**    | Manages Node Controllers; deploys and manages VM instances                            |
| **Node Controller (NC)**       | Runs on each physical host; interacts with OS and hypervisor to maintain VM lifecycle |
| **Storage Controller**         | Interfaces with storage systems                                                       |

**System Resource State (SRS):**

- CLC maintains an SRS populated from CC and NC reports
- Incoming user requests are checked against SRS for admission control
- Resources reserved in SRS → request sent to CC and NC → on success, committed in SRS; on failure, rolled back

### OpenStack Architecture

OpenStack follows a similar layered control model:

- **Nova** — Compute service (VM lifecycle)
- **Neutron** — Networking
- **Swift/Cinder** — Object/Block Storage
- **Keystone** — Authentication and authorization
- **Horizon** — Web dashboard

---

## 2. Distributed Systems Architecture (Cloud Infrastructure Models)

### What is a Distributed System?

> A distributed system is a system with **multiple components on different machines** that communicate and coordinate to appear as a **single coherent system** to the end user.

### Architectural Classification

#### Peer-to-Peer (P2P) Architecture

- Every node acts as **both client and server** (symmetric roles)
- Nodes are autonomous; system is **self-organizing**
- No global view at any single node; **no central coordinator**
- Load distributed across all peers

**Advantages:**

- Scalable — add more peers freely
- Resilient — few critical elements; high replication
- No single point of failure

**Disadvantages:**

- Hard to manage effectively
- Security is challenging (each peer holds its own data)
- Decision making is harder

**Real-world example:** Amazon Aurora multi-master clusters (multi-master = unconventional P2P with read/write capacity)

#### Client-Server / Master-Slave Architecture

- Roles are **asymmetric** — servers provide services, clients consume
- Master assigns and monitors work to/from slaves
- Common pattern due to ease of monitoring and reduced consistency issues

**Advantages:**

- Decision making easy (centralized coordinator)
- Simple to monitor and manage

**Disadvantages:**

- Vulnerable to **Single Point of Failure (SPOF)** at master
- Cannot scale out indefinitely (master becomes a bottleneck)

**Real-world example:** Hadoop MapReduce — single master assigns tasks to workers; monitors jobs; redistributes on worker failure

#### P2P vs Master-Slave Summary

| Feature         | P2P                      | Master-Slave      |
| --------------- | ------------------------ | ----------------- |
| Roles           | Symmetric                | Asymmetric        |
| SPOF            | No                       | Yes (master)      |
| Decision making | Harder                   | Easy (central)    |
| Scalability     | Unlimited (in principle) | Limited by master |
| Security        | Harder                   | Easier            |

---

## 3. Unreliable Communication — Trouble with Distributed Systems

> In a distributed cloud environment, **partial failures** are non-deterministic and unpredictable. Some parts may work while others are broken, and you may not know which.

### Why Communication Fails

When a client sends a request and waits for a response, many things can go wrong:

1. **Request lost** — network cable unplugged
2. **Request waiting in queue** — network or recipient is overloaded
3. **Remote node crashed** — powered down or failed
4. **Remote node temporarily stopped** — will respond later (GC pause, etc.)
5. **Response lost on network** — request processed but response dropped
6. **Response delayed** — will arrive later than timeout

### Reliability

> Reliability is the **probability** that a system will meet performance standards and yield correct output for a specific time under stated conditions.

**MTBF (Mean Time Between Failures):** `Total Uptime / Number of Breakdowns`

### Fault Classification

| Fault Type       | Description                                                |
| ---------------- | ---------------------------------------------------------- |
| **Transient**    | Appears once, then disappears                              |
| **Intermittent** | Occurs, vanishes, reappears — no real pattern (worst kind) |
| **Permanent**    | Only replacement/repair resolves it                        |

### Fault Models (Designer Perspective)

| Class | Description |
|---|---|
| **Crash-stop** | Node suddenly stops responding and never comes back |
| **Crash-recovery** | Node crashes but may restart and recover from log |
| **Omission** | Node fails to send or receive messages |
| **Arbitrary (Byzantine)** | Node behaves in any way — even maliciously incorrect |
| **Timing** | Node sends messages outside expected time bounds |

### Timeouts and Unbounded Delays

- In **synchronous** systems: maximum message delivery time `d` and processing time `r` → expect response within `2d + r`
- In **asynchronous** networks (Internet, cloud): **no upper bound on delivery time**
- Choose timeouts experimentally by measuring network round-trip distributions
- Better: **adaptive timeouts** — dynamically adjust based on observed jitter

### Network Congestion and Queueing

- Busy network links cause packets to queue → variable delays
- Switch queue full → packets dropped → must be retransmitted
- **Multi-tenant virtualized environments** add overhead via virtualization layers
- **Noisy neighbors** in shared clouds cause unpredictable latency
- Batch workloads (MapReduce) can saturate links

---

## 4. Fault Tolerance

### System Availability

> Availability = time system is up / total time
> Expressed as a percentage: **99.999% = "five nines"** ≈ 5.26 minutes downtime/year

| Nines   | Downtime/Year |
| ------- | ------------- |
| 99%     | ~3.65 days    |
| 99.9%   | ~8.76 hours   |
| 99.99%  | ~52.6 minutes |
| 99.999% | ~5.26 minutes |

### What is Fault Tolerance?

> The system's ability to **continue operating uninterrupted** despite the failure of one or more components.

**Two modes:**

- **Fail-Safe tolerance:** Given safety state is preserved but performance may drop (e.g., traffic lights turn red in both directions on failure)
- **Graceful degradation:** Application continues in a degraded mode

### Approaches for Building Fault Tolerance

1. **Redundancy** — Eliminate SPOFs: multiple power supplies, processors, disks, network paths
2. **Reliability** — Dependability of components; tracked via MTTF (Mean Time to Failure)
3. **Recoverability** — Overcome momentary failures:
   - Error control coding (parity bit, Hamming code, CRC)
   - Checkpointing and rollbacks

### Practical Fault-Tolerance Techniques (Distributed Systems)

| Technique                  | Description                                                                          |
| -------------------------- | ------------------------------------------------------------------------------------ |
| **Retries**                | Retry failed requests (use exponential backoff to avoid flooding)                    |
| **Timeouts**               | Abandon long-running requests; free up resources                                     |
| **Circuit Breaker**        | Stop calling a failing service after threshold of failures; try again after cooldown |
| **Bulkheads**              | Isolate thread/process pools per function; failure in one doesn't affect others      |
| **Cache**                  | Serve cached data when a remote service is down                                      |
| **Queue**                  | Buffer requests until dependency recovers                                            |
| **Asynchronous messaging** | Decouple services via message queues; avoid long synchronous call chains             |

---

## 5. Consensus in Distributed Systems

### The Consensus Problem

> A group of N processes must **agree on a single value**. Each process proposes a value; they must all decide on the same final value.

This is fundamental because distributed systems must replicate state across nodes that may fail at any time.

**Formal Properties:**

- **Agreement:** All non-faulty nodes decide on the **same** output
- **Termination:** All non-faulty nodes **eventually** decide on some value
- **Validity:** The decided value must have been proposed by some node
- **Integrity:** A node decides at most once
- **Non-triviality:** Both 0 and 1 are possible outcomes

### Consensus Algorithm Steps

1. **Elect:** Processes elect a leader to propose the next valid value
2. **Vote:** Non-faulty processes validate and vote on the leader's proposal
3. **Decide:** If a threshold quorum agrees, the value is decided; else restart

### Problems Equivalent to Consensus

- **Reliable multicast:** All servers receive the same updates in the same order
- **Leader election:** Elect exactly one leader known to all alive nodes
- **Membership/failure detection:** All nodes agree on who is alive
- **Mutual exclusion:** Coordinated access to critical shared resources

### Consensus in Synchronous vs Asynchronous Systems

| System Type  | Consensus Possible?                                                                                                                                         |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Synchronous  | Yes — maximum message delay known; use timeouts                                                                                                             |
| Asynchronous | No guarantee — **FLP Impossibility** (Fischer-Lynch-Paterson): no deterministic algorithm can always reach consensus in async systems with even one failure |

### Paxos Consensus Algorithm

> Paxos is a family of distributed algorithms used to reach consensus, used by Google (Chubby, Spanner) and Amazon.

**Three Roles:**

- **Proposer** (Leader/Coordinator): proposes a value
- **Acceptor:** listens to proposals, responds with votes
- **Learner:** learns the final decided value

**Paxos Variables:**

- `n` = proposal number
- `v` = proposed value
- `nv` = highest proposal number previously accepted
- `v'` = value of that previously accepted proposal

**Paxos Steps:**

1. Proposer sends `prepare(n, v)` to all acceptors
2. Each acceptor responds with `ack(nv, v')` if `n > nv` (promises not to accept lower proposals)
3. Proposer waits for majority `ack` — then sends `accept(n, max(v, v'))` to all acceptors
4. Acceptors accept if `n ≥ nv`; a **majority** accepting the same value → that value is decided
5. Learners are notified of the decided value

**Key property:** A value only needs a **majority (quorum)** of acceptors to be decided, tolerating minority failures.

---

## 6. Leader Election

### Why Leader Election?

- Many algorithms require a single coordinator/leader
- Leaders are a potential SPOF → if the leader dies, the rest may stall
- When a leader fails, a **new leader must be elected** automatically

**When to elect:**

- At system startup
- When the current leader fails (no response after timeout)

**Election Goal:**

- Elect exactly one non-faulty process as leader
- All non-faulty processes agree on who the leader is

**Liveness:** Every node eventually enters an "elected" or "not elected" state

**Safety:** Only one node enters the "elected" state

---

### 6.1 Ring Election Algorithm

**Setup:** N processes arranged in a **logical ring**; messages travel clockwise

**Steps:**

1. When a process `pi` detects leader failure, it sends an `election` message with its own `id:attr`
2. Each receiving process `pj` compares the message's `attr` with its own:
   - If message `attr > pj.attr` → forward the message unchanged
   - If message `attr < pj.attr` and `pj` hasn't sent its own → overwrite with `pj.attr` and forward
   - If message `attr == pj.attr` → `pj` has the highest attr; **`pj` becomes the new leader**
3. New leader sends `elected` message around the ring; each process records the new leader

**Complexity:**

- Worst case (highest-attr node is counter-clockwise neighbor of initiator):
  - `N-1` messages to reach coordinator candidate
  - `N` messages to confirm
  - `N` messages for `elected` broadcast
  - **Total: 3(N-1) messages**

**Limitation:** Does not handle failures that occur *during* the election run

---

### 6.2 Modified Ring Election Algorithm

- Processes append (not overwrite) their `id:attr` to the message as it passes
- Initiator receives the complete list → elects process with best attribute
- More resilient to failures during election

---

### 6.3 Bully Algorithm

**Setup:** Every process knows all other processes and their IDs; any process can message any other

**Why "Bully":** The process with the next-highest ID after the failed leader simply declares itself coordinator and "bullies" lower-ID processes.

**Steps:**

1. Process `pi` detects leader failure and knows its `id`:
   - If `pi.id` is highest: send `Coordinator` to all lower-ID processes → election done
   - Else: send `Election` to all higher-ID processes; wait for timeout
     - No reply within timeout → `pi` wins; sends `Coordinator` to all lower-ID processes
     - If reply received → higher process exists; wait for `Coordinator` message
     - If no `Coordinator` after another timeout → start a new election

2. A process receiving `Election` sends `Disagree` and starts its own election (if not already done)

**Key difference from Ring:** No ring topology required; any process can talk to any other. The highest available process always wins, "bullying" others into accepting it.

---

## 7. Resource Management and Scheduling

### What is Scheduling?

> **Scheduling** determines how to allocate resources (CPU, memory, storage, network) between users and tasks.

It involves:

- **Policies:** Principles guiding decisions
- **Mechanisms:** The means to implement policies

### Cloud Resource Management (CRM) Policies

1. **Admission Control:** Prevent accepting workloads that violate system policies
2. **Capacity Allocation:** Provision resources of appropriate sizes
3. **Load Balancing:** Distribute workload evenly across servers
4. **Energy Optimization:** Minimize power consumption
5. **QoS Guarantees:** Meet Service Level Agreements (SLAs)
6. **Locale-based:** Legal compliance, data sovereignty, performance locality
7. **Cost-based:** Pay-per-use, auction-based resource allocation

### Mechanisms for Resource Management

| Mechanism            | Description                                                                    |
| -------------------- | ------------------------------------------------------------------------------ |
| **Control Theory**   | Feedback-based allocation (latency, utilization) to guarantee system stability |
| **Utility-based**    | Performance model correlated with cost; SLA penalties/rewards drive allocation |
| **Machine Learning** | Historic data used to predict and pre-provision resources                      |
| **Market/Economic**  | Combinatorial auctions; users pay for resources (spot instances)               |

### Cloud Scheduling Objectives

- **Batch systems:** Maximize throughput, minimize turnaround time
- **Real-time systems:** Meet deadlines, be predictable
- **Best-effort:** Batch analytics

**Common Scheduling Algorithms:**

- **Round-Robin (RR):** Each task gets equal time slices in rotation
- **First-Come-First-Serve (FCFS):** Tasks served in arrival order
- **Shortest-Job-First (SJF):** Shortest task runs first (minimizes average wait time)
- **Priority:** Tasks with higher priority run first

### Deadline-Based Scheduling

| Type               | Description                                                        |
| ------------------ | ------------------------------------------------------------------ |
| **Hard deadlines** | Strict; missing deadline has penalties; expressed in ms/seconds    |
| **Soft deadlines** | Guidelines; can be missed by fractions; expressed in minutes/hours |

### Workload Partition Rules

- **Optimal Partitioning Rule (OPR):** Partition workload so all workers finish at the **same time** (earliest completion)
- **Equal Partitioning Rule (EPR):** Assign **equal workload** to each worker node

### OpenStack Nova Scheduler (Illustration)

- `nova-scheduler` determines which physical host a VM instance launches on
- Uses **filters** (eliminate unsuitable hosts) then **weights** (rank remaining hosts)
- Scheduler selects a new host when an instance is migrated

---

## 8. Distributed Locking

> **Distributed locks** are mutual exclusion locks with **global presence** across a cluster — preventing concurrent processes on different machines from accessing shared resources simultaneously.

**Why use locks?**

1. **Efficiency:** Avoid redundant work (e.g., trigger a task only once)
2. **Correctness:** Prevent data corruption from concurrent writes
3. Locks avoid "stepping on each other's toes" in shared state

### Lock Types

| Type            | Description                                                                                |
| --------------- | ------------------------------------------------------------------------------------------ |
| **Optimistic**  | Continue without blocking; check for conflict before commit; rollback if conflict detected |
| **Pessimistic** | Take exclusive lock before operating; release only after operation completes               |

### Features of Distributed Locks

- **Mutual Exclusion:** Only one client holds the lock globally at a time
- **Deadlock-free:** Use lease-based locking (auto-expire after timeout) to prevent eternal lock holding after crash
- **Consistency:** After failover, lock state is preserved across replicas

### Implementing Distributed Locking with Fencing

> **Problem:** A paused client (e.g., long GC pause) may believe it holds a lock, but the lease has expired and another client has acquired it.

**Solution — Fencing Tokens:**

- Lock server issues a **monotonically increasing fencing token** with each lock grant
- Client includes its token in every write request to the storage service
- Storage service rejects requests with tokens **lower than** the highest seen

```
Client 1 acquires lock → token=33 → [GC pause, lease expires]
Client 2 acquires lock → token=34 → writes with token 34 → ACCEPTED
Client 1 resumes → writes with token 33 → REJECTED (storage has seen 34)
```

### Distributed Lock Manager (DLM)

- Runs on every node; maintains an identical copy of the cluster-wide lock database
- Synchronizes access to shared resources across the cluster
- **Implementations:**
  - **Google Chubby** — lock service for loosely-coupled distributed systems
  - **Apache ZooKeeper** — open-source coordination with distributed lock recipes
  - **Redis Redlock** — Redis-based distributed lock algorithm

---

## 9. Apache ZooKeeper

> **ZooKeeper** is an open-source, high-performance coordination service for distributed applications. It provides a centralized service for configuration management, distributed locks/synchronization, naming, and group services.

**Design goals:** Simple, Robust, High Availability, High Throughput, Low Latency

**Optimized for:** Read-heavy workloads

**Guarantee:** Wait-free — a slow/failed client does not interfere with fast clients

### ZooKeeper Architecture

| Role                  | Description                                                                            |
| --------------------- | -------------------------------------------------------------------------------------- |
| **Server (Ensemble)** | Group of ZooKeeper servers; stores data tree in memory; sends ACK when client connects |
| **Leader**            | Elected at startup; handles all write requests; triggers recovery on node failure      |
| **Follower**          | Follows leader instructions; handles read requests locally                             |
| **Client**            | Sends requests to a single ZooKeeper server; redirects on server failure               |

**Reads:** Served locally by the connected server

**Writes:** Forwarded to the leader → consensus via Zab protocol → response sent

### ZooKeeper Data Model — znodes

- Hierarchical namespace (like a file system): `/app1/config`, `/app2/status`
- Every **znode** (data node) holds: data + metadata (version, timestamps)
- znode paths are absolute, slash-separated

**Types of znodes:**

| Type           | Description                                                                         |
| -------------- | ----------------------------------------------------------------------------------- |
| **Persistent** | Permanent; must be explicitly deleted; survives session end                         |
| **Ephemeral**  | Temporary; deleted when the creating client's session ends; cannot have children    |
| **Sequence**   | Append monotonically increasing counter to path; applies to persistent or ephemeral |

### ZooKeeper Operations

```
create(path, data)      – create a znode
delete(path, version)   – delete a znode
exists(path)            – check if znode exists
getData(path)           – read data from a znode
setData(path, data, version) – write data to a znode
getChildren(path)       – list children of a znode
sync(path)              – wait for data propagation
```

### ZooKeeper Watches

- A **watch** on a znode = "monitor this path for changes"
- When a znode is modified or deleted → ZooKeeper notifies all watching clients
- Used to detect: node failure (ephemeral znode deleted), configuration changes, leader changes

### ZooKeeper Recipes (Use Cases)

| Recipe                       | Description                                                                                    |
| ---------------------------- | ---------------------------------------------------------------------------------------------- |
| **Naming Service**           | Maps names to information; track which services are up by name                                 |
| **Leader Election**          | Nodes create ephemeral-sequential znodes; smallest ID = leader; watchers detect failure        |
| **Distributed Locks**        | N clients create ephemeral-sequential znodes; smallest ID acquires lock; others watch previous |
| **Configuration Management** | Centralized config stored in znodes; new nodes pull config at startup                          |
| **Message Queue**            | znodes under a queue path; producers add children, consumers get and delete them               |
| **Data Synchronization**     | Barriers, producer-consumer queues using watches                                               |

### ZooKeeper Consistency Guarantees

- All updates are **totally ordered** with a **zxid (ZooKeeper Transaction ID)**
- Writes go to leader → majority commit → followers apply in order
- Only transaction logs and snapshots are persisted; data tree held in memory → high throughput

### ZooKeeper Users

- **Apache Kafka** (configuration management)
- **Apache HBase** (distributed coordination)
- **Apache Storm** (cluster coordination)
- **Yahoo!, LinkedIn, Netflix, Zynga, Rackspace**

### ZooKeeper Limitations

- No built-in service discovery with health checks (Consul does this better)
- Ephemeral node lifecycle tied to TCP connection (TCP up ≠ process healthy)
- Complex to operate at scale

---

## 10. Reverse Proxies

### What is a Reverse Proxy?

> A **reverse proxy** sits in front of web servers and forwards client requests to those servers. The client sees only the proxy; the backend servers are hidden.

- Owned/managed by the web service; clients access it from the public internet
- Implemented in: **Nginx, Apache, Caddy, HAProxy**

**How it works:**

1. Client request arrives at reverse proxy
2. Proxy validates the request
3. If cached → serve cached response
4. If not cached → proxy fetches from backend server, caches it, returns to client

### Benefits of Reverse Proxy

| Benefit               | Description                                                                  |
| --------------------- | ---------------------------------------------------------------------------- |
| **Security**          | Hides backend server identities; blocks malicious IPs; protects against DDoS |
| **Load Balancing**    | Distributes traffic across multiple backend servers                          |
| **Caching**           | Caches static content (images, videos); reduces load on backends             |
| **SSL Offload**       | Terminates HTTPS at the proxy; backends communicate via HTTP                 |
| **Web Acceleration**  | Compression, deduplication → faster response times                           |
| **Identity Branding** | Conceal external service URLs (e.g., payment provider) from users            |

### Reverse Proxy vs Forward Proxy

| Feature        | Forward Proxy                  | Reverse Proxy                    |
| -------------- | ------------------------------ | -------------------------------- |
| Position       | In front of **clients**        | In front of **servers**          |
| Used by        | Clients (anonymity, filtering) | Servers (load balance, security) |
| Who configures | Client-side (org)              | Server-side (web service)        |
| Examples       | Corporate web filter, VPN      | Nginx, HAProxy                   |

**Forward proxy good for:** Content filtering, email security, NAT, compliance reporting

**Reverse proxy good for:** Load balancing, SSL offload, caching, authentication, application firewall

---

### Nginx

> **Nginx** is an open-source web server and reverse proxy known for maximum performance and stability.

**Architecture:** Master-slave model with **event-driven, asynchronous, non-blocking** I/O

- **Master process:** Receives client requests; assigns to workers; doesn't wait for worker response
- **Worker processes:** Each handles **1000+ connections simultaneously** in single-threaded fashion (saves RAM vs multi-threaded)
- **Cache:** Pages stored on first request; served from cache on subsequent requests

**Key features:**

- Handles **10,000+ simultaneous connections** with low CPU/memory
- Supports HTTP, HTTPS, HTTP/2, gRPC, TCP, UDP
- Centralized logging for all backend requests
- TLS/SSL termination

---

## 11. Performance and Scalability

### Cloud Scalability

> The ability to **increase or decrease IT resources** (compute, storage, networking) as demand changes, quickly and with minimal disruption.

### Scalability vs Elasticity

| Feature | Scalability                                        | Elasticity                                |
| ------- | -------------------------------------------------- | ----------------------------------------- |
| Nature  | Pre-planned, longer-term growth                    | Real-time, reactive to demand spikes      |
| Trigger | Business growth decisions                          | Sudden traffic spikes, variable workloads |
| Example | Adding more servers to handle 2x users in 6 months | Auto-scaling on sudden viral traffic      |

### Scaling Strategies

#### Vertical Scaling (Scale Up)

- Add more CPU, memory, or I/O to an **existing server** (bigger instance)
- AWS: change EC2 instance type; Azure: resize VM
- **Limit:** Physical hardware ceiling; single point of failure remains

#### Horizontal Scaling (Scale Out)

- Add **more servers**; distribute workload across them
- More resilient — no single point of failure
- Cloud: add more EC2 instances behind a load balancer
- **Limit:** Application must be stateless or state must be externalized

### Benefits of Cloud Scalability

- **Cost savings:** Pay for what you use; no upfront CAPEX
- **Disaster recovery:** Redundant infrastructure without secondary data centers
- **Flexibility:** Respond quickly to unexpected demand spikes
- **Convenience:** Provision in minutes, not weeks

---

## 12. Hybrid Cloud and Cloud Bursting

### Hybrid Cloud

> A combination of **private and public clouds** that enables seamless extension of local infrastructure to commercial cloud infrastructure on demand.

**Benefits:**

- Leverage existing private infrastructure for steady-state workloads
- Add public cloud resources for peak demand or specific workloads
- Separate sensitive data (private cloud) from general workloads (public cloud)
- Most cost-effective: pay for public cloud only when needed

**Use cases:**

- Dynamic/seasonal workloads (holiday shopping, election campaigns)
- Big data processing (burst to public cloud for large analytics jobs)
- Dev/test environments (CI/CD pipelines in public cloud)
- Incremental cloud migration

### Cloud Bursting

> **Cloud bursting** is a hybrid cloud configuration where an organization uses its private cloud for normal workloads, and **automatically overflows to public cloud** when private capacity is 100% utilized.

**Triggers:**

- Influx of user traffic (product launches, marketing campaigns)
- Expensive one-off computations (ML model training, 3D rendering)
- Seasonal peaks (eCommerce, financial quarter-end)

**Cost model:** Pay only for public cloud resources during burst periods — no wasted idle capacity

### OpenNebula with Cloud Bursting

- OpenNebula orchestrates VMs in both private (OpenNebula) and public (AWS EC2) clouds
- Nginx reverse proxy distributes load across servers in both clouds
- EC2 also has its own Nginx load balancer

---

## 13. Multitenancy

> **Multitenancy** is an architecture in which a **single instance of a software application serves multiple customers (tenants)**. Resources are shared across tenants.

### Benefits

- **Better resource utilization:** One machine shared → higher utilization
- **Lower costs:** Shared infrastructure → provider can offer services cheaply

### Multi-Tenant Architecture Types

#### Type 1: Single Multi-Tenant Database

- Single app instance + single DB instance for all tenants
- Each row/record tagged with a `tenant_id`
- **Pro:** Simple, highly scalable, low cost
- **Con:** High operational complexity; data isolation depends on application logic

#### Type 2: Multiple Databases, Single Application

- One app instance, but **separate databases per tenant**
- Stronger isolation; easier per-tenant backup and restore
- **Con:** More resource consumption; DB sprawl

#### Type 3: Multiple Application and Database Instances

- Separate app and DB instances per tenant
- Maximum isolation; easiest compliance
- **Con:** Highest cost; not truly multi-tenant

### Multitenancy Authentication

- Each tenant must be authenticated separately
- Role-based access control (RBAC) per tenant
- Keystone (OpenStack) implements multi-tenant authentication with Domains, Projects, Users, and Roles

---

## 14. Authentication in Cloud — Keystone (OpenStack)

> **Keystone** is the OpenStack Identity Service providing **API client authentication, service discovery, and multi-tenant authorization** via the OpenStack Identity API.

### Core Concepts

| Concept                       | Description                                                                                        |
| ----------------------------- | -------------------------------------------------------------------------------------------------- |
| **Project**                   | Groups and isolates resources (servers, images); users are given access via Role Assignments       |
| **Domain**                    | Collection of users, groups, and projects for a specific organization; enables multi-org isolation |
| **Users and Groups (Actors)** | Users = individuals; Groups = collections of users; these are assigned roles                       |
| **Role**                      | Conveys authorization (e.g., `admin`, `member`); assigned to an Actor on a Target                  |
| **Assignment**                | Ternary combination: Actor + Target + Role                                                         |
| **Target**                    | Project or Domain on which a role is assigned                                                      |
| **Token**                     | Proof of authentication; carries user identity and authorization; scoped to a project              |
| **Catalog**                   | Service catalog listing URLs/endpoints of all OpenStack services                                   |

### Token Payload Example

```json
{
  "token": {
    "issued_at": "2014-06-10T20:55:16Z",
    "expires_at": "2014-06-10T22:55:16Z",
    "roles": [{"id": "c703057be...", "name": "admin"}],
    "project": {"id": "...", "name": "development"},
    "user": {"id": "...", "name": "bob"}
  }
}
```

### Identity Backends

| Backend                             | Description                                                                             | Pros                                                | Cons                                                           |
| ----------------------------------- | --------------------------------------------------------------------------------------- | --------------------------------------------------- | -------------------------------------------------------------- |
| **SQL**                             | Keystone acts as its own Identity Provider; stores users/groups in MySQL/PostgreSQL/DB2 | Easy setup                                          | Weak password support; not ideal for enterprise; identity silo |
| **LDAP**                            | Keystone queries enterprise LDAP (read-only preferred)                                  | Leverages existing directory; no duplicate accounts | Keystone still sees passwords; service accounts may need SQL   |
| **Multiple Backends**               | One identity source per Domain (e.g., LDAP for employees, SQL for service accounts)     | Supports multi-org environments                     | Slightly more complex; auth must be domain-scoped              |
| **Identity Providers (Federation)** | Federated auth via SAML/OpenID Connect; users ephemeral in Keystone                     | Single Sign-On; Keystone never sees passwords       | Most complex setup                                             |

### Authentication Methods

**Password Authentication:**

- POST to Keystone with `{user, domain, password, scope: {project}}`
- Must include domain info for proper scoping in multi-domain deployments

**Token Authentication:**

- Exchange existing token for a new one (refresh, or scope change)
- POST to Keystone with `{token: {id: "e80b74"}}`

### Access Management — RBAC with policy.json

- Keystone enforces a Role-Based Access Control (RBAC) policy on all API endpoints
- Stored in `policy.json` on each service:

```json
{
  "admin_required": "role:admin or is_admin:1",
  "identity:list_projects": "rule:admin_required",
  "identity:list_user_projects": "rule:admin_or_owner"
}
```

---

## 15. Cloud Security — DoS, DDoS, and EDoS

### What is Cloud Security?

> Cloud security is a set of **control-based safeguards and technology protections** designed to protect cloud resources (infrastructure, applications, data) from leakage, theft, or data loss.

### Basic Cloud Security Layers

1. **Facility security:** Biometric readers, CCTV, motion detection, man-traps in data centers
2. **Network security:** Fault-tolerant firewalls, Intrusion Detection Systems (IDS), vulnerability assessments
3. **Platform security:** SSL/TLS, strict password policies, system trust certification

### VM Security Challenges

- **Hypervisor malware** — attacks targeting the VMM
- **Guest hopping** — breakout from one VM to another (container escape analog)
- **Man-in-the-middle during VM migration**
- **Kernel data manipulation** via active attacks

---

### Denial of Service (DoS) Attack

> A **DoS attack** aims to render a computer or service unavailable to legitimate users by overwhelming it with requests, causing denial of service.

- Launched from a **single source**
- Targets: network bandwidth, CPU, memory, application logic

**Two categories:**

1. **Buffer overflow attacks** — overflow memory/disk/CPU, causing crashes or sluggishness
2. **Flood attacks** — saturate server capacity with more packets than it can handle

**Indicators of DoS:**

- Unusually slow network performance
- Inability to load a specific website
- Sudden loss of connectivity across devices on the same network

---

### Distributed Denial of Service (DDoS) Attack

> A **DDoS attack** uses **multiple compromised machines (botnet)** to flood a target, making the attack traffic harder to distinguish from legitimate traffic.

**Mechanism:**

- Attacker builds a **botnet** — network of infected machines (PCs, IoT devices)
- Commands bots to simultaneously flood target's IP address
- Each bot looks like a legitimate device → hard to filter

**Comparison:** DDoS is like a traffic jam of thousands of cars clogging a highway simultaneously

---

### Economic Denial of Sustainability (EDoS) Attack

> An **EDoS attack** exploits cloud auto-scaling. The attacker deliberately sends just enough traffic to trigger autoscaling — causing the victim's cloud bill to skyrocket without actually causing a service outage.

**Key difference from DDoS:**

- DDoS goal: **cease all services** (short, intense burst)
- EDoS goal: **maximize financial cost** of the victim (gradual, sustained)
- EDoS is more targeted and intelligent; sends fraudulent data at a **lower rate for a longer duration**

**Impact:** Victim pays for autoscaled resources they did not legitimately need → financial damage

### DoS vs DDoS vs EDoS

| Feature   | DoS                | DDoS                   | EDoS                             |
| --------- | ------------------ | ---------------------- | -------------------------------- |
| Sources   | Single             | Multiple (botnet)      | Multiple or single               |
| Goal      | Service disruption | Service disruption     | Financial damage                 |
| Intensity | High, short burst  | Very high, short burst | Low, prolonged                   |
| Target    | Server/network     | Server/network         | Cloud billing/autoscale          |
| Detection | Easier             | Harder                 | Very hard (mimics legit traffic) |

---

## 16. Edge Computing and Fog Computing

### What is Edge Computing?

> Edge computing **places storage and compute resources closer to where data is produced** — on devices, gateways, cloudlets, or micro-Data Centers — so results return in milliseconds rather than travelling to a distant cloud.

**Driven by:**

- Explosion of IoT devices
- Need for real-time processing at the data source
- Cloud limitations: high latency (≥50 ms round-trip), bandwidth costs, privacy concerns

**Data at the edge:** 500 ZB of IoT data produced annually; only ~10 ZB reaches data centers; 45% processed at/near the edge

---

### Why Edge Computing?

#### 1. Ultra-Low Latency

- Cloud round-trip: ≥50 ms → unacceptable for autonomous vehicles, telesurgery, AR/VR
- Edge processing: **single-digit ms** (device → edge node → device; no WAN hops)
- **Last-mile proximity:** Fewer routers → less queuing delay → consistent response time

#### 2. Bandwidth Optimization

- IoT devices generate massive raw data volumes
- Edge nodes **filter, aggregate, compress** before sending to cloud
- Only anomalies/summaries sent upstream → massive bandwidth savings

#### 3. Enhanced Privacy and Security

- Sensitive data (medical records, biometric scans) stays local → less exposure
- Simplifies GDPR/HIPAA compliance
- **Practices:** Local encryption, anonymization, zero-trust edge security, isolated processing enclaves

#### 4. Reliability and Resilience

- Edge nodes operate autonomously when cloud connectivity is lost
- Critical for: industrial control, remote monitoring (oil rigs, ships), emergency response

#### 5. Cost Efficiency

- Reduce data egress (cloud bandwidth billing)
- Pre/post-process at low-cost edge hardware
- Defer cloud scaling by handling local bursts locally

---

### Edge vs Cloud vs Micro Datacenter

| Component            | Description                                                                          |
| -------------------- | ------------------------------------------------------------------------------------ |
| **Cloud**            | Large-scale, centralized; AWS/Azure/GCP; services delivered over internet            |
| **Cloudlet**         | Small-scale cloud at network edge; intermediate tier for mobile users; AR/VR support |
| **Datacenter**       | Large facility with racks, cooling, power                                            |
| **Micro Datacenter** | Compact, self-contained modular unit (compute + storage + cooling in one rack)       |

---

### Fog Computing

> **Fog computing** is a hierarchical resource pooling architecture that extends cloud services to the edge via an intermediate **fog layer** between IoT devices and the cloud.

```
IoT Devices → [Fog Nodes / Gateways] → [Cloudlets / Edge Nodes] → Cloud
```

- Fog nodes aggregate, filter, and process data from IoT devices
- Heavy analytics and long-term storage go to the cloud
- Enables: smart homes, smart cities, intelligent transportation

### Edge Computing Frameworks/Tools

| Tool                 | Description                                                                 |
| -------------------- | --------------------------------------------------------------------------- |
| **Azure IoT Edge**   | Deploys cloud workloads to edge devices via Docker containers               |
| **AWS Greengrass**   | Runs Lambda functions locally on edge devices                               |
| **Google Cloud IoT** | Manages IoT device fleets; edge ML inference                                |
| **EdgeX Foundry**    | Open-source edge microservices framework                                    |
| **OpenStack**        | Edge-ready; trimmed control planes on edge sites with full services in core |

### Challenges in Edge Computing

| Challenge                  | Description                                                                          |
| -------------------------- | ------------------------------------------------------------------------------------ |
| **Resource Heterogeneity** | Phones, MCUs, gateways, micro-servers differ in CPU, memory, ISA                     |
| **Security & Trust**       | Default credentials on gateways; ~49% household Wi-Fi unsecured; raw data inferences |
| **Programming Models**     | Must target heterogeneous, intermittently-connected nodes                            |
| **Data Abstraction**       | Normalize diverse sensor formats (temperature vs camera) into unified schema         |
| **Interoperability**       | Different vendors, protocols, ISAs; no universal standard                            |

---

## 17. Container Security

### Why Container Security Matters

- Containers share the **host OS kernel** → a single kernel exploit compromises all containers on a host
- Traditional VM-level isolation doesn't apply
- Containers are **ephemeral** → traditional forensics tools insufficient

**Key risks:**

- **Shared kernel vulnerability** (e.g., "Dirty Pipe" — privilege escalation via kernel exploit)
- **Lateral movement** — breach in one microservice enables movement to internal databases in flat networks
- **Noisy neighbor DoS** — without strict cgroups, one container can consume 100% CPU/RAM
- **Supply chain attacks** — poisoned third-party base image layers become malware vectors
- **Container escape** — exploiting namespace misconfigurations to access host

### Container Security Layers (L1–L5)

| Layer                              | Contains                                        |
| ---------------------------------- | ----------------------------------------------- |
| **L1: Orchestration**              | Kubernetes API Server, Scheduler, Load Balancer |
| **L2: Application**                | Application code and runtime                    |
| **L3: Container Engine**           | Docker Engine, containerd                       |
| **L4: Host Kernel (Kernel Space)** | Namespaces, cgroups, syscall interface          |
| **L5: Hardware**                   | CPU/BIOS (Spectre, Meltdown attacks here)       |

### Shared Responsibility Model

| Responsibility                                             | Who                          |
| ---------------------------------------------------------- | ---------------------------- |
| Physical infrastructure, data center                       | Cloud Provider               |
| Host OS hardening, Container Engine, Kubernetes API Server | Infrastructure/Platform Team |
| Application code, image scanning, Pod Security Context     | Developer/DevSecOps          |

**Zero-Trust Integration:** Treat every layer as a potential entry point; assume lower layers may already be compromised

### Security Best Practices

- Minimal base images (reduce attack surface)
- Image vulnerability scanning in CI/CD pipeline
- Pod Security Contexts (non-root containers, read-only filesystems)
- Network policies (deny all by default; allow only necessary traffic)
- Secrets management (never hardcode secrets; use Kubernetes Secrets or Vault)
- Runtime security monitoring (Falco, Sysdig)
- Namespace isolation between tenants

---

## Summary Diagram

```
Cloud Controller (Unit 4):
│
├── Distributed System Models
│   ├── P2P (symmetric, no SPOF, scalable)
│   └── Master-Slave (asymmetric, easy management, SPOF)
│
├── Unreliable Communication
│   ├── Partial failures, timeouts, unbounded delays
│   └── Fault models: crash-stop, omission, byzantine
│
├── Fault Tolerance
│   ├── Availability (5 nines = 5.26 min downtime/year)
│   ├── Techniques: retry, timeout, circuit breaker, bulkhead
│   └── MTBF, MTTF, MTTR
│
├── Consensus → Paxos (proposer, acceptor, learner)
│
├── Leader Election
│   ├── Ring Election (messages clockwise, 3(N-1) complexity)
│   └── Bully Algorithm (highest-ID process wins)
│
├── Scheduling
│   ├── Policies: admission, capacity, load balance, energy, QoS
│   └── Algorithms: RR, FCFS, SJF, Priority; OPR vs EPR
│
├── Distributed Locking
│   ├── Optimistic vs Pessimistic locks
│   ├── Fencing tokens (monotonic token rejects stale writes)
│   └── DLM: ZooKeeper, Chubby, Redis Redlock
│
├── ZooKeeper
│   ├── znodes (persistent, ephemeral, sequence)
│   ├── Watches, Leader-Follower, Zab protocol
│   └── Recipes: naming, locks, leader election, config, queue
│
├── Performance & Scalability
│   ├── Vertical Scaling (scale up: bigger machine)
│   ├── Horizontal Scaling (scale out: more machines)
│   ├── Hybrid Cloud + Cloud Bursting (overflow to public cloud)
│   └── Reverse Proxy / Nginx (load balance, cache, SSL, security)
│
├── Multitenancy
│   └── Single DB / Multiple DB / Multiple Instances
│
├── Authentication — Keystone
│   ├── Project, Domain, User, Role, Token, Catalog
│   └── Identity backends: SQL, LDAP, Federation
│
├── Security — DoS / DDoS / EDoS
│   ├── DoS (single source, flood or buffer overflow)
│   ├── DDoS (botnet, massive flood)
│   └── EDoS (exploit autoscaling for financial damage)
│
└── Edge & Fog Computing
    ├── Ultra-low latency, bandwidth savings, privacy, resilience
    ├── Fog layer: IoT → Fog Nodes → Cloud
    └── Tools: Azure IoT Edge, AWS Greengrass, EdgeX Foundry
```

---

## Key Terms

| Term               | Definition                                                                                 |
| ------------------ | ------------------------------------------------------------------------------------------ |
| Cloud Controller   | Control plane managing resource allocation, admission control, and monitoring in a cloud   |
| Consensus          | Agreement among distributed nodes on a single value despite failures                       |
| Paxos              | Distributed consensus algorithm using proposer/acceptor/learner roles                      |
| FLP Impossibility  | No deterministic consensus algorithm exists for async systems with one failure             |
| Leader Election    | Algorithm for choosing one coordinator among distributed nodes                             |
| Bully Algorithm    | Leader election where highest-ID process claims leadership                                 |
| Ring Election      | Leader election on a logical ring; messages propagate clockwise                            |
| Scheduling         | Deciding how to allocate resources between users and tasks                                 |
| Admission Control  | Preventing workloads that violate system policies from entering the system                 |
| Distributed Lock   | Global mutex for serializing access to shared resources across nodes                       |
| Fencing Token      | Monotonically increasing ID used to reject stale lock holder's writes                      |
| ZooKeeper          | Distributed coordination service: config, locks, naming, leader election                   |
| znode              | ZooKeeper data node (persistent, ephemeral, or sequential)                                 |
| Reverse Proxy      | Server forwarding client requests to backend servers; hides backend topology               |
| Nginx              | High-performance async event-driven reverse proxy and web server                           |
| Cloud Bursting     | Extending private cloud to public cloud during capacity peaks                              |
| Multitenancy       | Single app instance serving multiple customer organizations                                |
| Keystone           | OpenStack identity service for authentication, authorization, service catalog              |
| RBAC               | Role-Based Access Control — permissions based on assigned roles                            |
| DoS                | Denial of Service — single-source attack to render service unavailable                     |
| DDoS               | Distributed DoS — multi-source botnet attack                                               |
| EDoS               | Economic DoS — exploit cloud autoscaling to maximize victim's cloud bill                   |
| Edge Computing     | Processing data near the source; sub-10ms latency                                          |
| Fog Computing      | Hierarchical model; fog layer between IoT devices and cloud                                |
| Container Security | Protecting containerized workloads from escape, lateral movement, and supply chain attacks |

---
