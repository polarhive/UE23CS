# UE23CS351B: Cloud Computing

> The cloud computing course introduces not only the various technologies that go into building acloud native application, but also how cloud systems are designed. The student is introduced tovarious tools and design techniques/trade-offs. It also gives a flavour for the businessrelevance/ethics of using cloud computing. This course requires the student to have a desirableknowledge of [[CN|Computer Networks]] and [[OS|Operating System]].

## Course Objectives

- Introduce the rationale behind the cloud computing revolution and cloud native application Architecture
- Explore the concepts of Virtualization and Containerization.
- Explore the concepts of Distributed storage and its various techniques
- Design distributed systems for scalability and expose the student to various trade-offs in designing cloud architectures

## Course Outcomes

- Comprehend the technical and business rationale behind cloud computing.
- Decide the model of cloud computing to use for solving a particular problem.
- Implement Micro service architecture through Containers and Orchestration tools. Analyse virtual machines and containers.
- Experiment with cloud storage Models such as object stores, key value stores.
- Apply the critical constraints such as Performance, scalability and security to the designed distributed system

# Course Content

> **U1**: [[U1_Cloud_Programming_Models|Cloud Programming Models]]

Parallel computing, Grid computing, Introduction to Cloud Programming Models and service Models, Introduction to technology challenges with Distributed & Cloud computing, Business Drivers - deployment models, Multi-cloud, Cloud architecture and IaaS programming model, Web Services and REST, PaaS Programming Model, Communication using Message queues- Pub Sub model, SaaS Programming model – Microservices and differences with the traditional monolithic model; challenges of migrating monolithic applications. Microservice transactions with Saga pattern

> **U2**: [[U2_Virtualization|Virtualization]]

Types: Para virtualization and Transparent virtualization, Software - Trap and Emulate virtualization, Software - Binary translation, Goldberg Popek principles for Virtualization, Hardware - AMDv/Intel, Memory - Shadow page tables, Memory - Nested page tables, IO, VM Migration, Lightweight Virtualization - Containers and Namespaces, Deployment of cloud native applications through Docker – Unionfs, Orchestration and Kubernetes, DevOps, Jenkins pipeline

> **U3**: [[U3_Distributed_Storage|Distributed Storage]]

Distributed Storage Types of Cloud storage - Block, Object stores, Replication, lag, multileader replication, Leaderless replication, Partitioning - key-value data, Consistent hashing, Partitioning - rebalancing partitions, Request routing, Consistency Models, CAP Theorem, Transactions, Two-phase commit.

> **U4**: [[U4_Master_Slave_P2P|Master-slave v/s p2p models]]

Resource allocation, Scheduling algorithms, Cluster coordination – consensus, Fault Tolerance - faults and partial failures, Failure detection - checkpointing and application recovery, Unreliable communication, Cluster coordination - leader election, distributed locking, Case Study: Zookeeper/Raft - distributed consensus infrastructure. Edge Computing and Fog Computing – principles and paradigms Scaling computation - reverse proxies, Scaling computation - hybrid cloud and cloud bursting, Multitenancy, Multitenant databases, Cloud security requirements - physical/virtual security, security design patterns, Container security features to work with Docker and Kubernetes, Authentication in the cloud: Keystone/IAM, Cloud Threats – DoS, Economic Denial of Sustainability.

---

prerequisites: [[OS|UE23CS242B]], [[CN|UE23CS252B]], [[BD|UE23CS343AB2]]