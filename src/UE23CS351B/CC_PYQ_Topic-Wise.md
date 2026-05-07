# Cloud Computing — Master PYQ Bank with Answers (Topic-Wise)

**Course:** UE23CS351B / UE21CS351B / UE20CS351 / UE19CS352 / UE18CS352 / UE17CS352

**University:** PES University, Bengaluru

**Sources:** 21 ESA Question Papers (2013 – 2024)

> All questions answered. Answers are exam-ready: concise, structured, and match expected depth per mark allocation.

---

## TABLE OF CONTENTS

1. [Cloud Fundamentals — Definitions, Characteristics, Benefits](#1)
2. [Service Models — IaaS, PaaS, SaaS](#2)
3. [Deployment Models — Public, Private, Hybrid](#3)
4. [Scalability, Elasticity and Parallelism](#4)
5. [Cloud Application Architecture & Design](#5)
6. [REST, SOA and Microservices](#6)
7. [Serverless Computing](#7)
8. [DevOps and CI/CD](#8)
9. [Hypervisors and Virtualization Types](#9)
10. [Popek-Goldberg & Sensitive Instructions](#10)
11. [Shadow Page Tables & Extended Page Tables](#11)
12. [VM vs Containers — Docker & Namespaces](#12)
13. [Kubernetes Orchestration](#13)
14. [VM Migration — Hot, Cold, Pre-copy, Post-copy](#14)
15. [Distributed Storage — Object, Block, File Storage](#15)
16. [Lustre and GlusterFS File Systems](#16)
17. [Consistency Models](#17)
18. [CAP Theorem](#18)
19. [Replication — Leader-based, Multi-leader, Leaderless](#19)
20. [Partitioning, Sharding and Rebalancing](#20)
21. [Request Routing](#21)
22. [Transactions, 2PC and ACID](#22)
23. [Multitenancy and Multitenant Databases](#23)
24. [Leader Election Algorithms](#24)
25. [Distributed Locking and Fencing](#25)
26. [Apache ZooKeeper](#26)
27. [Fault Tolerance — MTBF, MTTR, Fault Models](#27)
28. [Resource Management and Scheduling](#28)
29. [Scalability Strategies, Cloud Bursting and Hybrid Cloud](#29)
30. [Reverse Proxy](#30)
31. [Cloud Security — DoS, DDoS, EDoS](#31)
32. [Authentication in Cloud — Keystone](#32)
33. [Security Design Patterns](#33)
34. [Miscellaneous / Advanced Topics](#34)

---

<a name="1"></a>

## 1. Cloud Fundamentals — Definitions, Characteristics, Benefits

---

**Q1.1** List and explain the Features/Characteristics of Cloud Computing. *(6M)*

> **Answer:**
> 1. **On-demand self-service:** Users can provision resources (servers, storage) automatically without human intervention from the provider.
> 2. **Broad network access:** Resources are accessible over the network via standard mechanisms — desktops, laptops, phones.
> 3. **Resource pooling:** Provider's resources are pooled to serve multiple consumers using a multi-tenant model. Physical and virtual resources are dynamically assigned per demand.
> 4. **Rapid elasticity:** Resources can be scaled up or down quickly (often automatically) to match workload demands.
> 5. **Measured service:** Cloud systems automatically control and optimize resource usage. Usage can be monitored, controlled, and reported — enabling pay-as-you-go billing.
> 6. **Reliability/High Availability:** Data is replicated across multiple sites; failures are automatically handled.

---

**Q1.2** Explain any five characteristics of Cloud Computing. *(5M)*

> **Answer:** *(Same as Q1.1 — any five of the six above.)*

---

**Q1.3** Explain the following terms:

(a) Elasticity (b) Rapid provisioning (c) Measured Service (d) Resource Pooling *(4M)*

> **Answer:**
> - **(a) Elasticity:** The ability to dynamically scale resources up (scale-out) or down (scale-in) in response to workload changes. E.g., adding more servers during a flash sale and removing them after.
> - **(b) Rapid provisioning:** New resources can be provisioned instantly (within minutes) without manual intervention. No need to buy and install physical hardware.
> - **(c) Measured Service:** Cloud usage is metered (CPU hours, GB storage, network GB). Users pay only for what they use — like a utility bill.
> - **(d) Resource Pooling:** Provider pools physical resources (compute, storage, network) and dynamically allocates them across multiple tenants. No single user owns a fixed physical resource.

---

**Q1.4** Explain: (1) On-demand service (2) Rapid provisioning (3) Measured Service (4) Resource Pooling (5) Availability (6) Broad Network Access *(6M)*

> **Answer:**
> 1. **On-demand service:** Compute capabilities (VMs, storage) are available automatically without provider interaction.
> 2. **Rapid provisioning:** Resources are deployed in minutes via self-service portals or APIs.
> 3. **Measured Service:** Metered usage (per GB, per CPU-hour); users see usage reports; billed accordingly.
> 4. **Resource Pooling:** Multi-tenant shared infrastructure; physical location abstracted from user.
> 5. **Availability:** Cloud services run 24/7 with built-in redundancy — hardware failure doesn't take down service.
> 6. **Broad Network Access:** Services accessible from any device (laptop, phone, tablet) over standard internet.

---

**Q1.5** List and explain the benefits of moving applications to the cloud. *(4M)*

> **Answer:**
> 1. **Cost savings:** Replace capital expenditure (CAPEX) with operational expenditure (OPEX). Pay only for what you use.
> 2. **Scalability:** Instantly scale resources based on demand — no over-provisioning needed.
> 3. **Agility:** Spin up environments in minutes; faster time-to-market for new features.
> 4. **Global reach:** Deploy applications in multiple geographic regions easily.
> 5. **Reliability:** Built-in redundancy, automatic failover, and disaster recovery.
> 6. **Maintenance-free:** Provider manages hardware, OS patches, and infrastructure.

---

**Q1.6** What is Cloud Computing? Define any 4 features. Mention any 4 advantages. *(10M)*

> **Answer:**
> **Definition:** Cloud computing is a model for enabling ubiquitous, on-demand network access to a shared pool of configurable computing resources that can be rapidly provisioned and released with minimal management effort.
>
> **4 Features:** On-demand self-service, Broad network access, Resource pooling, Rapid elasticity *(see Q1.1 for explanations).*
>
> **4 Advantages:**
> 1. **Cost reduction:** No upfront hardware investment; pay-as-you-go.
> 2. **Flexibility:** Employees can work from anywhere with internet access.
> 3. **Disaster recovery:** Cloud providers replicate data across regions automatically.
> 4. **Competitive edge:** Small businesses get access to enterprise-grade infrastructure instantly.

---

**Q1.7** What are Data Centers? Mention 4 types. Explain any 4 challenges. *(10M)*

> **Answer:**
> **Data Centers:** Facilities housing IT infrastructure (servers, storage, networking) to host applications and data. Cloud data centers enable multi-tenant shared computing.
>
> **4 Types:**
> 1. **Enterprise/Corporate DC:** Owned and operated by a single organization for internal use.
> 2. **Colocation DC:** Third-party facility where businesses rent physical space for their own hardware.
> 3. **Managed Hosting DC:** Provider hosts and manages infrastructure on behalf of customers.
> 4. **Cloud DC:** Owned by cloud providers (AWS, Azure, GCP); shared multi-tenant infrastructure.
>
> **4 Challenges:**
> 1. **Power consumption:** DCs consume enormous electricity for compute and cooling.
> 2. **Cooling:** Heat generated by servers requires sophisticated HVAC systems.
> 3. **Security:** Physical security (access control) and cyber security must both be ensured.
> 4. **Scalability:** Expanding physical infrastructure to meet growing demand is costly and slow.

---

**Q1.8** Discuss the most common technology challenges in cloud computing. *(8M)*

> **Answer:**
> 1. **Security and Privacy:** Data outside physical control; risk of breaches, unauthorized access.
> 2. **Latency:** Network delays affect real-time applications; distance to data center matters.
> 3. **Vendor Lock-in:** Proprietary APIs make migrating between providers difficult.
> 4. **Reliability and Downtime:** Despite SLAs, outages occur; applications must handle failures.
> 5. **Data Consistency:** Keeping data in sync across distributed nodes (CAP theorem trade-offs).
> 6. **Compliance and Legal:** Data sovereignty laws vary by country; GDPR, HIPAA requirements.
> 7. **Cost Management:** Pay-per-use can become expensive without monitoring (EDoS attacks exploit this).
> 8. **Multitenancy Issues:** Noisy neighbors; isolation of one tenant's data from another.

---

**Q1.9** Explain 4 key design considerations for building a cloud-ready application. How does Elasticity play an important role? *(8M)*

> **Answer:**
> **4 Design Considerations:**
> 1. **Statelessness:** Design services to hold no local session state — all state in shared DB/cache. Enables horizontal scaling.
> 2. **Loose coupling:** Use APIs and message queues; services don't directly depend on each other's uptime.
> 3. **Failure tolerance:** Expect failures; implement retries, circuit breakers, and health checks.
> 4. **Automation:** Infrastructure-as-code (Terraform), CI/CD pipelines for consistent deployments.
>
> **Elasticity's Role:** Elasticity allows the cloud app to automatically acquire more resources when load spikes (e.g., during a product launch) and release them when load drops — ensuring performance without over-provisioning. Stateless, loosely-coupled designs enable this without data loss.

---

**Q1.10** Explain Cloud Architecture with a diagram. *(8M)*

> **Answer:**
> Cloud architecture layers from bottom to top:
> ```
> ┌───────────────────────────────────┐
> │         SaaS Applications         │  ← End users access via browser
> ├───────────────────────────────────┤
> │       PaaS (Platform Layer)       │  ← Dev tools, runtime, middleware
> ├───────────────────────────────────┤
> │     IaaS (Infrastructure Layer)   │  ← VMs, virtual storage, networks
> ├───────────────────────────────────┤
> │    Virtualization / Hypervisor    │  ← Abstracts physical hardware
> ├───────────────────────────────────┤
> │     Physical Hardware (DC)        │  ← Servers, switches, disks
> └───────────────────────────────────┘
> ```
> - **IaaS Layer:** Provides VMs, virtual storage (EBS), virtual networks. User controls OS and above.
> - **PaaS Layer:** Runtime environment; dev frameworks (App Engine); user deploys code only.
> - **SaaS Layer:** Fully managed apps (Gmail, Salesforce); user just logs in and uses.
> - A **Cloud Controller** sits across layers managing resource allocation, scheduling, and billing.

---

<a name="2"></a>

## 2. Service Models — IaaS, PaaS, SaaS

---

**Q2.1 / Q2.2** Describe the 3 service models and 3 deployment models. *(6–8M)*

> **Answer:**
> **Service Models:**
>
> | Model | User manages | Provider manages | Example |
> |---|---|---|---|
> | **IaaS** | OS, runtime, apps, data | Hardware, networking, virtualization | AWS EC2, Azure VMs |
> | **PaaS** | Application code + data | OS, runtime, middleware, hardware | Google App Engine, Heroku |
> | **SaaS** | Nothing (just usage) | Everything | Gmail, Salesforce, Zoom |
>
> **Deployment Models:**
> - **Public Cloud:** Infrastructure owned by 3rd-party provider; shared over internet. E.g., AWS, Azure.
> - **Private Cloud:** Dedicated to one organization; more control and security. E.g., OpenStack on-prem.
> - **Hybrid Cloud:** Mix of public and private; data/apps move between them. E.g., run normal load on-prem, burst to AWS for peaks.

---

**Q2.3** Merits and demerits of SaaS, IaaS and PaaS. *(6M)*

> **Answer:**
>
> | Model | Merits | Demerits |
> |---|---|---|
> | **IaaS** | Full control over OS and stack; flexible; run any workload | Requires admin skills; user responsible for patches |
> | **PaaS** | No infra management; faster dev; auto-scaling built-in | Vendor lock-in; limited control over runtime |
> | **SaaS** | Zero maintenance; accessible from anywhere; subscription cost | No customization; data in provider's hands |

---

**Q2.5** Classify into IaaS, PaaS or SaaS: AWS EC2, Google App Engine, Office 360, AWS RDS, Shopify, AWS S3. *(6M)*

> **Answer:**
>
> | Service | Model | Justification |
> |---|---|---|
> | AWS EC2 | **IaaS** | Provides virtual machines; user installs and manages OS |
> | Google App Engine | **PaaS** | Manages runtime; user deploys application code only |
> | Office 360 | **SaaS** | Fully managed productivity suite; user just uses it |
> | AWS RDS | **PaaS** | Managed database service; user provides data/queries, not DB server management |
> | Shopify | **SaaS** | Fully hosted e-commerce platform; no infrastructure needed |
> | AWS S3 | **IaaS** | Raw object storage service; user manages data organization |

---

**Q2.6** Classify App1 (browser-based), App2 (on VM), App3 (cloud DB service). *(5M)*

> **Answer:**
> - **App1 (browser-based):** **SaaS** — fully delivered over internet, user just uses a browser.
> - **App2 (installed on VM):** **IaaS** — user provisions a VM and installs/manages the application.
> - **App3 (cloud DB service):** **PaaS** — managed database; user writes queries, provider manages DB engine and scaling.
>
> Real-life examples: IaaS = AWS EC2, PaaS = Google Cloud SQL, SaaS = Gmail.

---

<a name="3"></a>

## 3. Deployment Models — Public, Private, Hybrid

---

**Q3.1** Explain the different deployment models with real-time usage scenarios. *(7M)*

> **Answer:**
> 1. **Public Cloud:** Infrastructure owned by cloud provider, shared among many customers over internet. *Scenario:* A startup hosts its web app on AWS to avoid upfront hardware costs.
> 2. **Private Cloud:** Cloud infrastructure operated solely for one organization, on-premises or hosted privately. *Scenario:* A bank runs its core banking applications on an OpenStack private cloud for regulatory compliance.
> 3. **Hybrid Cloud:** Combination of public and private clouds; workloads can move between them. *Scenario:* A retailer runs normal operations on a private cloud but bursts to AWS during holiday sales peaks.
> 4. **Multi-Cloud:** Using services from multiple cloud providers simultaneously. *Scenario:* A company uses AWS for compute, Google Cloud for ML, and Azure for Office 365 integration.

---

**Q3.2 / Q3.3 / Q3.4** Advantages and disadvantages of private vs public clouds. *(6–10M)*

> **Answer:**
>
> | Aspect | Public Cloud | Private Cloud |
> |---|---|---|
> | **Cost** | Low upfront (OPEX); pay-per-use | High upfront (CAPEX); ongoing maintenance |
> | **Scalability** | Near-unlimited, on-demand | Limited by owned hardware |
> | **Security** | Shared; provider-managed | Higher; dedicated hardware, internal control |
> | **Control** | Limited; provider's policies | Full control over hardware and software |
> | **Compliance** | Harder; data leaves premises | Easier; data stays on-prem |
> | **Maintenance** | Provider handles it | In-house team responsible |
> | **Examples** | AWS, Azure, GCP | OpenStack, VMware vSphere on-prem |

---

**Q3.6** "Private cloud does not need to address elasticity" — True/False? Justify. *(part Q)*

> **Answer:** **False.** Private clouds also need elasticity to handle variable workloads efficiently. If an organization's private cloud runs a university application, student usage peaks at exam time and drops in holidays. Without elasticity, resources are either over-provisioned (wasteful) or under-provisioned (poor performance). Private clouds implement elasticity using virtualization and orchestration (e.g., OpenStack auto-scaling). The key difference is only that elasticity in private clouds is bounded by the physical hardware owned — unlike public clouds where elasticity is theoretically unlimited.

---

<a name="4"></a>

## 4. Scalability, Elasticity and Parallelism

---

**Q4.1** What is elasticity? How is it different from scalability? Give an example for each. *(4–6M)*

> **Answer:**
> - **Scalability:** The ability of a system to handle increasing workload by adding resources — planned, longer-term growth. *Example:* Adding 10 more servers to a cluster to handle 3x the user base over 6 months.
> - **Elasticity:** The ability to automatically and rapidly scale resources up AND down based on real-time demand. *Example:* An e-commerce site auto-scales from 5 to 50 servers during a flash sale, then back to 5 when it ends.
>
> **Key difference:** Scalability is about capacity ceiling; elasticity is about dynamic right-sizing in real time. Scalability is a property; elasticity is an operation enabled by that property.

---

**Q4.4** What is Cloud Scalability? Mention 4 benefits. *(part Q)*

> **Answer:**
> **Cloud Scalability:** The ability to increase or decrease IT resources (compute, storage, networking) as demand changes, quickly and with minimal disruption.
>
> **4 Benefits:**
> 1. **Cost savings:** Only pay for what you use; no idle over-provisioned hardware.
> 2. **Performance:** Always have enough resources to meet demand; no degradation under load.
> 3. **Disaster recovery:** Redundant infrastructure without a secondary data center.
> 4. **Flexibility:** Respond quickly to unexpected traffic spikes or business changes.

---

**Q4.5 / Q4.6** Explain different degrees of parallelism with an example. *(6M)*

> **Answer:**
> 1. **Bit-level parallelism:** Increase processor word size so more bits are processed per cycle. *Example:* Upgrading from 8-bit to 32-bit processor doubles arithmetic throughput.
> 2. **Instruction-level parallelism (ILP):** Multiple instructions executed simultaneously via pipelining or superscalar execution. *Example:* Modern CPUs execute fetch, decode, and execute stages of different instructions simultaneously in a pipeline.
> 3. **Data parallelism:** Same operation applied to multiple data elements simultaneously. *Example:* GPU processing all pixels of an image simultaneously.
> 4. **Task-level parallelism:** Different tasks (programs/threads) run simultaneously on multiple processors. *Example:* A web server handling 100 user requests simultaneously on 4 CPU cores — each core handles a different request.

---

**Q4.7** Scale-up vs scale-out — which to use for 100 users? *(5M)*

> **Answer:**
> - **Scale-up (Vertical):** Add more CPU/RAM/disk to existing server. Simple but limited by hardware ceiling and creates SPOF.
> - **Scale-out (Horizontal):** Add more servers and distribute load. No single point of failure; unlimited in principle.
>
> **For 100 users:** Use **scale-out**. At 100 users, the existing machine is overwhelmed. Scale-out adds a new server behind a load balancer, distributing requests. This also removes the single point of failure and makes future growth (1000 users) easy by just adding more nodes. Scale-up is a short-term fix with a hard ceiling.

---

**Q4.9** Compute available minutes/year for 0.99998 availability. *(5M)*

> **Answer:**
> Total minutes in a year = 365 × 24 × 60 = **525,600 minutes**
>
> Available minutes = 525,600 × 0.99998 = **525,589.49 ≈ 525,589 minutes**
>
> Downtime = 525,600 − 525,589 = **~10.5 minutes/year** (approximately 5 nines)

---

<a name="5"></a>

## 5. Cloud Application Architecture & Design

---

**Q5.1** How to design and build a cloud-ready application? Explain 5 key steps. *(10M)*

> **Answer:**
> 1. **Define the architecture:** Choose service model (IaaS/PaaS/SaaS), deployment model, and cloud provider. Design for stateless, loosely-coupled services.
> 2. **Design for failure:** Assume any component can fail. Add redundancy, health checks, retries, and circuit breakers.
> 3. **Plan for scalability:** Use horizontal scaling with load balancers; externalize session state to Redis/DB so any instance can serve any request.
> 4. **Secure the application:** Implement IAM, encrypt data in transit (TLS) and at rest, least-privilege access.
> 5. **Automate deployment:** Use CI/CD pipelines (Jenkins, GitHub Actions) and Infrastructure-as-Code (Terraform) so deployments are repeatable, fast, and consistent.

---

**Q5.2** Steps required to start a VM in an IaaS platform. *(5M)*

> **Answer:**
> 1. **Choose image:** Select base OS image (e.g., Ubuntu 22.04 AMI on AWS).
> 2. **Select instance type:** Choose CPU/memory configuration (e.g., t2.micro = 1 vCPU, 1GB RAM).
> 3. **Configure network:** Assign to a VPC/subnet; allocate public IP or Elastic IP if needed.
> 4. **Set security groups:** Define firewall rules (e.g., allow port 22 for SSH, port 80 for HTTP).
> 5. **Attach storage:** Configure root volume size; attach additional EBS volumes if needed.
> 6. **Launch:** Hypervisor allocates physical resources; VM boots the selected OS image and is ready.

---

<a name="6"></a>

## 6. REST, SOA and Microservices

---

**Q6.1** Explain the REST architectural style with four principles. *(6M)*

> **Answer:**
> REST (REpresentational State Transfer) is an architectural style for designing networked APIs. Key principles:
> 1. **Client-Server:** UI and data storage are separated. Client handles the interface; server handles data. Improves portability and scalability.
> 2. **Stateless:** Each request from client to server must contain ALL information needed. No session state stored on server. Makes scaling easy (any server can handle any request).
> 3. **Cacheable:** Responses must declare themselves cacheable or non-cacheable. Caching reduces latency and server load.
> 4. **Uniform Interface:** Consistent API interface — resources identified via URIs; manipulation via HTTP methods (GET, POST, PUT, DELETE); self-descriptive messages.
> 5. **Layered System:** Client cannot tell if it's connected to end server or intermediary (load balancer, CDN). Enables scalable infrastructure.
> 6. **Code on demand (optional):** Server can send executable code (JavaScript) to client.

---

**Q6.2** Difference between SOA and Microservices. What are REST APIs? *(4M)*

> **Answer:**
>
> | Aspect | SOA | Microservices |
> |---|---|---|
> | Communication | Enterprise Service Bus (ESB) | Lightweight REST/HTTP, message queues |
> | Data | Often shared database | Each service owns its own database |
> | Scope | Business-level reuse | Bounded context, domain-driven |
> | Deployment | Groups of services | Individually deployable |
>
> **REST APIs:** APIs conforming to REST constraints — using HTTP methods (GET/POST/PUT/DELETE) on resources identified by URIs, with responses in JSON/XML. In SOA/microservices, REST APIs serve as the "contract" between services, enabling language-agnostic, loosely coupled communication.

---

**Q6.3** Differences between monolithic and microservices. Challenges of migrating monolithic. *(6M)*

> **Answer:**
>
> | Aspect | Monolithic | Microservices |
> |---|---|---|
> | Codebase | Single deployable unit | Many independent services |
> | Deployment | Entire app redeployed for any change | Individual services deployed independently |
> | Scaling | Must scale entire app | Scale individual services |
> | Technology | One stack | Each service can use different language/DB |
> | Failure | One bug can crash everything | Failure isolated to one service |
>
> **Migration challenges:**
> 1. **Identifying service boundaries:** Decomposing a monolith into correct microservices is hard.
> 2. **Data decomposition:** Each microservice needs its own DB — splitting a shared monolithic DB is complex.
> 3. **Distributed transactions:** Replacing ACID transactions with sagas adds complexity.
> 4. **Testing:** Integration and end-to-end testing becomes significantly harder.
> 5. **Operational overhead:** Need service discovery, distributed logging, container orchestration.

---

**Q6.6** Challenges with Microservices Architecture. *(5M)*

> **Answer:**
> 1. **Operational complexity:** Managing 100s of services, containers, and deployments requires robust tooling (Kubernetes, Istio).
> 2. **Distributed tracing:** Debugging a failed request that spans 10 services is very hard without centralized logging (ELK, Jaeger).
> 3. **Network latency:** Inter-service calls over HTTP add latency compared to in-process calls in monoliths.
> 4. **Data consistency:** Each service has its own DB — maintaining consistency across services requires sagas or event sourcing.
> 5. **Service discovery:** Services must find each other dynamically (solved with service meshes or ZooKeeper/Consul).
> 6. **Testing overhead:** Integration and contract testing across many independent APIs is expensive.

---

**Q6.7** Explain the 4 core concepts of the Pub/Sub model. *(6M)*

> **Answer:**
> 1. **Publisher:** Sends messages to a named topic. Does not know who the subscribers are.
> 2. **Topic:** A named channel that receives messages from publishers. Acts as the intermediary.
> 3. **Subscriber:** Registers interest in a topic and receives all messages published to it.
> 4. **Message Broker:** Manages topics, stores messages durably, and delivers them to subscribers.
>
> **Purposes:** Event-driven architectures, real-time notifications, log aggregation, fan-out processing, decoupling producers and consumers for async workflows. *Examples:* AWS SNS, Google Pub/Sub, Apache Kafka.

---

**Q6.9** REST API Versioning Strategies — any three. *(6M)*

> **Answer:**
> 1. **URI Versioning:** Version in the URL path. `GET /api/v1/users` vs `GET /api/v2/users`. Simple and explicit; most common.
> 2. **Query Parameter Versioning:** `GET /api/users?version=2`. Easy to implement but less "clean" URLs.
> 3. **Header Versioning:** Version passed in HTTP header: `Accept: application/vnd.myapp.v2+json`. Keeps URLs clean but less visible/testable.
> 4. **Content Negotiation:** Uses `Accept` header with custom media types to select API version. Most RESTful but most complex.

---

**Q6.10** What is a Service Mesh and what are its main features? *(6M)*

> **Answer:**
> A **Service Mesh** is a dedicated infrastructure layer for managing service-to-service communication in microservices — typically implemented as a sidecar proxy (e.g., Envoy) deployed alongside each service.
>
> **Main features:**
> 1. **Traffic management:** Load balancing, retries, timeouts, and circuit breaking between services.
> 2. **Observability:** Automatic distributed tracing, metrics, and access logs for all service calls.
> 3. **Security (mTLS):** Mutual TLS encryption between all services automatically; zero-trust networking.
> 4. **Service discovery:** Services find each other via the mesh without hardcoded addresses.
> 5. **Policy enforcement:** Rate limiting, access control policies centrally managed.
>
> *Examples:* Istio, Linkerd, Consul Connect.

---

<a name="7"></a>

## 7. Serverless Computing

---

**Q7.1 / Q7.2** What is serverless computing? List advantages. Give an example. *(4M)*

> **Answer:**
> **Serverless computing:** A cloud execution model where the cloud provider dynamically manages server allocation. Developers deploy code (functions) and pay only per invocation — no server provisioning or management needed. Sometimes called "Function as a Service (FaaS)."
>
> **Advantages:**
> 1. **No server management:** Provider handles OS, patching, scaling automatically.
> 2. **True pay-per-use:** Charged only when code runs (per millisecond), not for idle time.
> 3. **Automatic scaling:** Functions scale from 0 to thousands of instances instantly.
> 4. **Faster time-to-market:** Focus on code logic, not infrastructure.
> 5. **High availability:** Built into the platform by default.
>
> **Example:** AWS Lambda — runs Python/Node code in response to S3 events, API calls, or schedules. Used for image resizing triggered when a photo is uploaded.

---

**Q7.4** Explain Serverless Architecture with block diagram. Indicate 8 types of serverless systems and match them. *(8M)*

> **Answer:**
> ```
> Client → API Gateway → Lambda Functions → DynamoDB/S3/SNS
>                     ↘ Step Functions (state machines)
>                     ↘ SQS (message queue)
> ```
>
> **8 Common Serverless System Types and Use Cases:**
>
> | Type | Use Case from Question |
> |---|---|
> | **FaaS (Function as a Service)** | Run code on-demand or on-schedule |
> | **MaaS (Messaging as a Service)** | Queuing service required |
> | **DaaS (Data processing streams)** | Real-time processing of data packages |
> | **BaaS (API Gateway / Backend as a Service)** | Two systems communicate with REST API |
> | **DBaaS** | Managed database with no server |
> | **Storage-as-a-Service** | Object storage (S3) |
> | **Auth-as-a-Service** | Authentication (Cognito) |
> | **Workflow Orchestration** | Step Functions for multi-step processes |

---

**Q7.6** What is a State Machine and how is it used with Step Functions? *(5M)*

> **Answer:**
> A **State Machine** is a computation model consisting of a set of **states**, **transitions** between states triggered by events, and **actions** taken on transitions. At any time, the system is in exactly one state.
>
> **AWS Step Functions** use state machines to coordinate multiple Lambda functions into workflows. Each state represents a Lambda invocation or a wait/choice/parallel step.
>
> ```
> [Start] → [Validate Order] → [Process Payment] → [Ship Order] → [End]
>                                      ↓ (failure)
>                              [Refund and Cancel]
> ```
> Benefits: Visual workflow editor, automatic retry logic, error handling, and long-running workflow support without timeouts.

---

<a name="8"></a>

## 8. DevOps and CI/CD

---

**Q8.1 / Q8.2** Why is DevOps needed? How is it different from traditional approaches? *(4–6M)*

> **Answer:**
> **DevOps** is needed because traditional software development had a hard wall between development (writes code) and operations (deploys/maintains), causing slow releases, blame culture, and fragile deployments.
>
> **Differences:**
>
> | Aspect | Traditional | DevOps |
> |---|---|---|
> | Teams | Siloed Dev and Ops | Unified cross-functional teams |
> | Release cycle | Months | Hours/days (continuous) |
> | Deployment | Manual, error-prone | Automated CI/CD pipelines |
> | Infrastructure | Manual provisioning | Infrastructure as Code (Terraform) |
> | Feedback | Post-release (slow) | Real-time monitoring and alerts |
>
> **Benefits:** Faster time-to-market, fewer deployment failures, faster recovery from failures, better collaboration, and consistent environments.

---

**Q8.3** Four techniques that make DevOps successful. *(4M)*

> **Answer:**
> 1. **Continuous Integration (CI):** Developers frequently merge code; automated tests run on every commit (e.g., via Jenkins, GitHub Actions).
> 2. **Continuous Deployment (CD):** Passing builds are automatically deployed to staging or production.
> 3. **Infrastructure as Code (IaC):** Environments defined in code (Terraform, Ansible); reproducible and version-controlled.
> 4. **Automated Testing:** Unit, integration, and regression tests run automatically in the pipeline — catch bugs early.
> 5. **Monitoring and Alerting:** Tools like Prometheus/Grafana/ELK give real-time visibility into production health.

---

<a name="9"></a>

## 9. Hypervisors and Virtualization Types

---

**Q9.1** Explain Type 2 Hypervisor (Hosted Hypervisor). *(6M)*

> **Answer:**
> A **Type 2 (Hosted) Hypervisor** runs as an application on top of an existing host operating system.
> ```
> ┌──────┬──────┐
> │ VM1  │ VM2  │
> ├──────┴──────┤
> │  Type 2 VMM │  ← runs as an application
> ├─────────────┤
> │   Host OS   │  ← full OS (Windows/Linux)
> ├─────────────┤
> │  Hardware   │
> └─────────────┘
> ```
> - The host OS mediates hardware access for the hypervisor.
> - Guest VMs run within the hypervisor as processes.
> - **Higher overhead** than Type 1 due to extra OS layer.
> - **Use case:** Developer workstations, testing environments.
> - **Examples:** Oracle VirtualBox, VMware Workstation, Parallels Desktop.

---

**Q9.2** Difference between hosted and bare-metal hypervisors. Give examples. *(4–5M)*

> **Answer:**
>
> | Feature | Type 1 (Bare Metal) | Type 2 (Hosted) |
> |---|---|---|
> | Runs on | Directly on hardware | On top of host OS |
> | Performance | High (no OS overhead) | Lower (extra OS layer) |
> | Security | Better isolated | Depends on host OS security |
> | Use case | Production servers, data centers | Dev/test environments |
> | Examples | VMware ESXi, Hyper-V, Xen, KVM | VirtualBox, VMware Workstation |

---

**Q9.5 / Q9.6** How are paravirtualization and full virtualization used to virtualize x86? *(5–10M)*

> **Answer:**
> **Problem with x86:** x86 does not meet Popek-Goldberg requirements — it has ~17 sensitive but non-privileged instructions (e.g., SGDT, PUSHF) that silently fail without trapping.
>
> **Full Virtualization (Binary Translation):**
> - Guest OS runs unmodified.
> - VMware scans guest binary at runtime, replaces non-trappable sensitive instructions with safe equivalents that trap to VMM.
> - Guest OS is unaware it's virtualized.
> - Performance cost from scanning/rewriting.
>
> **Paravirtualization:**
> - Guest OS **is modified** to replace sensitive instructions with explicit **hypercalls** to the VMM.
> - Guest OS knows it's running in a VM and cooperates.
> - Better performance than binary translation.
> - Cannot run unmodified proprietary OSes (e.g., unmodified Windows).
> - *Example:* Xen paravirtualization.
>
> **Modern solution:** Intel VT-x / AMD-V hardware extensions add new CPU modes that intercept all sensitive instructions automatically, enabling efficient unmodified guest OS virtualization.

---

**Q9.7** Match virtualization type to each requirement. *(8M)*

> **Answer:**
>
> | Requirement | Virtualization Type | Justification |
> |---|---|---|
> | (i) Dedicated apps on VMs from guest OS + other apps on host OS directly | **Type 2 / Hosted Hypervisor** | Host OS runs natively; VMs run via hosted hypervisor on same host |
> | (ii) Special APIs requiring substantial OS modifications | **Paravirtualization** | Guest OS is modified; hypercalls replace sensitive instructions |
> | (iii) Non-critical instructions on hardware directly; critical instructions replaced with traps into VMM | **Full Virtualization / Binary Translation** | Non-privileged run natively; VMM intercepts/emulates critical ones |
> | (iv) Install virtualization software directly on hardware | **Type 1 / Bare Metal Hypervisor** | VMM runs directly on hardware with no host OS |

---

**Q9.9** Is x86 architecture virtualizable? *(4M)*

> **Answer:**
> **No, x86 is not natively virtualizable** by Popek-Goldberg standards. Popek-Goldberg require that all sensitive instructions be a subset of privileged instructions (so they trap to the VMM in user mode). x86 has ~17 sensitive but non-privileged instructions (e.g., `SGDT`, `SIDT`, `SLDT`, `PUSHF`, `POPF`) that execute silently in user mode without trapping — a VMM cannot intercept them.
>
> **Solutions:** VMware uses binary translation; Xen uses paravirtualization; Intel VT-x / AMD-V add hardware support to make all sensitive instructions trap correctly.

---

<a name="10"></a>

## 10. Popek-Goldberg & Sensitive Instructions

---

**Q10.1** State the 3 Theorems of Popek and Goldberg. What are control-sensitive and behaviour-sensitive instructions? *(10M)*

> **Answer:**
> **Definitions:**
> - **Behaviour-sensitive instruction:** Behaves differently depending on the processor mode (user vs kernel) or hardware configuration. *Example:* `PUSHF` on x86 — in user mode, reads interrupt flag differently.
> - **Control-sensitive instruction:** Attempts to change the processor mode or system configuration. *Example:* `STI/CLI` — set/clear interrupt flag.
>
> **Three Theorems:**
> 1. **Theorem 1 (Sufficient condition for virtualizability):** A VMM can be constructed for a machine if the set of sensitive instructions is a **subset** of privileged instructions. (All sensitive instructions trap to VMM when executed in user/guest mode.)
> 2. **Theorem 2 (Recursive virtualizability):** A machine is recursively virtualizable if it is virtualizable AND a VMM without timing dependencies can be constructed for it. (VM inside a VM inside a VM is possible.)
> 3. **Theorem 3 (Hybrid VMM):** A hybrid VMM may be constructed if user-sensitive instructions are a subset of privileged instructions. (Allows some native execution without full emulation.)

---

**Q10.2 / Q10.3** Mark `popf` and I/O instruction as sensitive. Can you build trap-and-emulate? *(exam scenario Q)*

> **Answer:**
>
> | Instruction | Sensitive? | Type |
> |---|---|---|
> | `popf` (moves to privilege mode / generates int) | **Yes** | **Behaviour-sensitive** — behaves differently based on mode (privilege mode: generates interrupt; user mode: silently fails or behaves differently) |
> | I/O instruction (fails without error in user mode; turns off interrupts in privilege mode) | **Yes** | **Control-sensitive** — changes system control state (interrupt flags) |
>
> **Can we build trap-and-emulate?**
> - For a trap-and-emulate VMM, ALL sensitive instructions must be privileged (must trap when run in guest/user mode).
> - If `popf` is sensitive but **not** privileged (executes in user mode without trapping), a trap-and-emulate VMM **cannot be built** for this architecture.
> - If BOTH instructions are privileged (trap in user mode), then Theorem 1 is satisfied — a trap-and-emulate VMM **can** be built.

---

<a name="11"></a>

## 11. Shadow Page Tables & Extended Page Tables

---

**Q11.1** Explain Shadow Page Table with diagram. What are the challenges? *(8M)*

> **Answer:**
> **Purpose:** The hypervisor must translate Guest Virtual Address (gVA) → Guest Physical Address (gPA) → Host Physical Address (hPA). The hardware MMU only does one level of translation, so the hypervisor maintains a **Shadow Page Table (sPT)** that directly maps gVA → hPA.
>
> ```
> Guest sees:  gVA → [Guest PT] → gPA
> VMM creates: gVA → [Shadow PT] → hPA  ← hardware MMU uses this
> ```
>
> **How it works:**
> - Guest page tables are **write-protected**.
> - When guest tries to modify its PT → **page fault** → VMM intercepts → VMM updates shadow PT to reflect the change → resume guest.
> - Hardware MMU walks the shadow PT directly.
>
> **Challenges:**
> 1. **High overhead:** Every guest page table modification causes a page fault → VMM intervention → expensive.
> 2. **Memory overhead:** VMM must maintain a shadow copy of EVERY guest page table.
> 3. **TLB flush on world switch:** Every VM entry/exit requires flushing the TLB — very expensive.
> 4. **Complexity:** Keeping shadow and guest page tables in sync is complex.

---

**Q11.2** How does Extended/Nested Page Table overcome shadow paging overheads? *(6M)*

> **Answer:**
> **EPT (Extended Page Tables, Intel) / NPT (Nested Page Tables, AMD)** add hardware support for two-level page table walk.
>
> ```
> gVA → [Guest PT (CR3)] → gPA → [EPT (EPTP)] → hPA
>        ↑ Guest controls          ↑ VMM controls
> ```
>
> - **Guest manages its own page tables freely** — no write protection, no page fault traps.
> - Hardware MMU automatically walks both the guest PT and the EPT on each TLB miss.
> - VMM only needs to maintain EPT (gPA → hPA mapping), not shadow copies of all guest PTs.
>
> **Advantages over Shadow PT:**
> - Eliminates VM exits for guest page table modifications.
> - Eliminates shadow PT memory overhead.
> - Significant performance improvement (especially for memory-intensive workloads).
> - Much simpler VMM implementation.

---

<a name="12"></a>

## 12. VM vs Containers — Docker & Namespaces

---

**Q12.1 / Q12.2** Similarities and differences between Docker container and VM. *(4M)*

> **Answer:**
> **Similarities:**
> 1. Both provide isolated environments for running applications.
> 2. Both can run multiple instances on the same physical host.
>
> **Differences:**
>
> | Feature | Virtual Machine | Container |
> |---|---|---|
> | OS | Each VM has its own OS | Shares host OS kernel |
> | Size | GBs | MBs |
> | Boot time | Minutes | Seconds |
> | Isolation | Full hardware isolation | Process-level (namespace) isolation |
> | Performance | More overhead | Near-native |
> | Portability | Bulky (full OS image) | Lightweight, portable |
> | Use case | Different OS needed; strong isolation | Microservices, rapid deployment |

---

**Q12.6 / Q12.7** Explain Docker architecture with a neat diagram. *(8M)*

> **Answer:**
> Docker follows a **client-server architecture:**
>
> ```
> Docker CLI (Client)
>       │  REST API
>       ▼
> Docker Daemon (dockerd)   ←→   Docker Registry (Docker Hub)
>       │
>       ├─── Images (read-only templates)
>       └─── Containers (running instances)
>               └── Layered FS (UnionFS/OverlayFS)
> ```
>
> - **Docker Client:** CLI tool (`docker build`, `docker run`). Sends commands to daemon via REST API over UNIX socket.
> - **Docker Daemon (`dockerd`):** Listens for API requests. Manages containers, images, networks, and volumes.
> - **Images:** Read-only layered templates built from a Dockerfile. Each instruction = one layer. Layers are cached.
> - **Containers:** Running instance of an image. Adds a writable layer on top. Isolated via Linux namespaces + cgroups.
> - **Registry:** Stores images. Docker Hub is public; private registries also supported.
>
> **Docker vs VM:** Docker shares host OS kernel (lightweight, fast). VM has full guest OS (heavy, slower, stronger isolation).

---

**Q12.8 / Q12.9** What are namespaces? Explain PID and UTS. *(3–5M)*

> **Answer:**
> **Namespaces** are a Linux kernel feature that partition kernel resources — each process (container) gets its own isolated view of specific system resources.
>
> | Namespace | Isolates |
> |---|---|
> | **PID** | Process IDs — container thinks its init process is PID 1; can't see host processes |
> | **UTS** | Hostname and domain name — each container has its own hostname |
> | **NET** | Network interfaces, IP addresses, ports |
> | **MNT** | Filesystem mount points |
> | **IPC** | Inter-process communication (shared memory segments) |
> | **USR** | User and group IDs |
>
> **PID namespace:** Container's first process gets PID 1 from its own perspective. Kill PID 1 inside = stops container. Host sees it as a different PID entirely.
>
> **UTS namespace:** Container can set its hostname to "webserver-1" independently of host hostname. Useful for service identification.

---

**Q12.10** Given cgroup definition — what does it enforce? *(5M)*

> **Answer (for:** `Group nginx { cpu {cpu.shares = 300;} memory {memory.limit_in_bytes=1g;} }`)
>
> This cgroup definition for the nginx process enforces:
> 1. **CPU limit (`cpu.shares = 300`):** The nginx group gets 300 CPU shares. CPU shares are relative — if another group has 600 shares, nginx gets 1/3 of CPU time during contention. During idle time, nginx can use more.
> 2. **Memory limit (`memory.limit_in_bytes = 1g`):** The nginx group is capped at 1 GB of RAM. If it tries to allocate more, the kernel will either deny or trigger an OOM kill of the nginx process.
>
> **Purpose:** Prevents nginx from monopolizing system resources and starving other containers/processes.

---

<a name="13"></a>

## 13. Kubernetes Orchestration

---

**Q13.1** What are controller-manager, kubelets and pods? Where do they run? *(7–8M)*

> **Answer:**
> ```
> Control Plane (Master Node):          Worker Nodes:
> ┌────────────────────────┐            ┌─────────────────────────┐
> │ API Server             │            │ kubelet                 │
> │ Scheduler              │  ───────▶  │ kube-proxy              │
> │ Controller Manager     │            │ Container Runtime       │
> │ etcd                   │            │  └── Pods               │
> └────────────────────────┘            │      └── Containers     │
>                                       └─────────────────────────┘
> ```
>
> - **Controller Manager (Master):** Watches the cluster state via API server and works to move current state towards desired state. Contains multiple controllers: Replication Controller (ensures desired replica count), Node Controller (handles node failures), etc.
> - **kubelet (Worker):** An agent running on each worker node. Receives Pod specs from API Server and ensures the containers described in those Pods are running and healthy. Reports node status back to control plane.
> - **Pod (Worker):** The smallest deployable unit in Kubernetes. A Pod wraps one or more containers that share network and storage. Each Pod gets a unique IP within the cluster.

---

**Q13.2** Explain Kubernetes architecture with all key components. *(6M)*

> **Answer:**
> **Control Plane:**
> - **API Server:** Front-end for all cluster operations. All `kubectl` commands go here.
> - **Scheduler:** Assigns newly created Pods to worker nodes based on resource availability and constraints.
> - **Controller Manager:** Ensures cluster state matches desired state (e.g., always 3 replicas running).
> - **etcd:** Distributed key-value store holding all cluster state (configuration, secrets, pod specs).
>
> **Worker Nodes:**
> - **kubelet:** Agent on each node; ensures containers in Pods are running.
> - **kube-proxy:** Manages network rules on nodes; enables Service-to-Pod communication.
> - **Container Runtime:** Actually runs containers (Docker, containerd, CRI-O).
>
> **User-facing objects:** Deployments (manage replica sets), Services (stable network endpoints), ConfigMaps/Secrets (externalized config), Ingress (HTTP routing).

---

<a name="14"></a>

## 14. VM Migration — Hot, Cold, Pre-copy, Post-copy

---

**Q14.1 / Q14.3** Hot vs Cold migration. Pre-copy vs Post-copy. *(6–10M)*

> **Answer:**
> **Cold Migration:**
> - VM is **powered off** before migration.
> - All VM state transferred to destination; VM resumes there.
> - Service downtime during transfer; simple and predictable.
>
> **Hot (Live) Migration:**
> - VM migrates **while running** — no service interruption.
> - Users don't notice; open TCP connections maintained.
> - Requires copying memory, CPU state, devices, MAC addresses.
>
> ---
>
> **Pre-copy Migration (used by KVM, Xen, VMware):**
> 1. Reserve resources at destination.
> 2. **Iteratively copy all memory pages** to destination.
> 3. Re-copy pages that were **dirtied** (modified) since last round.
> 4. Repeat until dirty page set is small enough.
> 5. **Brief stop:** Suspend VM, copy final dirty pages + CPU state.
> 6. Resume VM at destination; redirect network traffic.
> - **Pro:** Very short downtime (just final stop phase).
> - **Con:** Takes long if VM has high memory write rate (many dirty pages).
>
> **Post-copy Migration:**
> 1. Transfer **CPU state only** to destination immediately.
> 2. Resume VM at destination right away.
> 3. Memory pages fetched **on-demand** from source as the VM accesses them (via page faults).
> - **Pro:** VM resumes almost instantly at destination.
> - **Con:** Page faults cause brief pauses; network failure during transfer is catastrophic.

---

<a name="15"></a>

## 15. Distributed Storage — Object, Block, File Storage

---

**Q15.1** Explain Amazon S3 object storage. *(6M)*

> **Answer:**
> **Amazon S3 (Simple Storage Service)** is an object storage service. Core concepts:
> - **Bucket:** Top-level namespace container; globally unique name; region-specific.
> - **Object:** The stored item (file + metadata). Identified by a unique **key** within the bucket.
> - **Key naming:** Slash-separated conventions simulate directory structure: `images/2024/photo.jpg`.
>
> **Features:**
> - Accessed via REST API (HTTP GET/PUT/DELETE). No file system — flat namespace.
> - **Replication:** Default multi-AZ replication across multiple devices; survives 2 simultaneous device failures.
> - **Versioning:** Full history of every object version; deleted objects can be recovered.
> - **Security:** Per-object and per-bucket ACLs; IAM integration; audit logging.
> - **Multi-part uploads:** Large objects split and uploaded in parallel; failed parts retried without re-uploading whole file.

---

**Q15.3** Ephemeral vs persistent disks. Which for swap and database indexes? *(5M)*

> **Answer:**
> - **Ephemeral disk:** Temporary; exists only for the lifetime of the VM instance. Faster (local hardware), but data lost when VM stops/terminates.
> - **Persistent disk:** Independent of VM lifecycle. Data survives VM restart, stop, or termination. Slower (network-attached), but durable.
>
> | Use case | Disk type | Reason |
> |---|---|---|
> | Swap space | **Ephemeral** | Swap is temporary memory overflow; no need to persist |
> | Database indexes | **Persistent** | Indexes are critical; losing them requires expensive rebuild; must survive restarts |

---

**Q15.8** What is sharding? How does it increase join complexity? *(10M)*

> **Answer:**
> **Sharding:** Partitioning a large database table across multiple servers (shards) based on a shard key (e.g., user_id mod N). Each shard holds a subset of rows.
>
> *Example:* Users table sharded by `user_id`. user_id 0–999 on shard 1; 1000–1999 on shard 2.
>
> **Join complexity:** If a query joins Users (sharded by user_id) with Orders (sharded by order_id), the two related rows may live on different shards. The database must:
> 1. Query both shards for matching records.
> 2. Transfer one result set to the other shard.
> 3. Perform the join in memory.
>
> This is a **cross-shard join** — far more expensive than a local join. Solution: denormalize data or co-locate related records on the same shard using compound keys.

---

<a name="16"></a>

## 16. Lustre and GlusterFS File Systems

---

**Q16.1** Explain Lustre file system architecture. *(8M)*

> **Answer:**
> **Lustre** is a high-performance parallel distributed filesystem used in HPC. Architecture:
>
> ```
>      Clients (compute nodes)
>           │  Lustre Protocol
>      ┌────┴────────────────────┐
>      │       MGS               │  ← Management Server (cluster config)
>      ├─────────────────────────┤
>      │       MDS + MDT         │  ← Metadata Server + Metadata Target
>      │  (filenames, dirs,      │    (inodes, permissions, layout)
>      │   permissions, layout)  │
>      ├─────────────────────────┤
>      │  OSS1  │  OSS2  │ OSS3  │  ← Object Storage Servers
>      │  OST1  │  OST2  │ OST3  │  ← Object Storage Targets (actual data)
>      └─────────────────────────┘
> ```
>
> - **MGS (Management Server):** Stores configuration for all Lustre filesystems. Clients contact this first.
> - **MDS (Metadata Server) + MDT:** Manages filenames, directories, permissions, and file layout (which OSTs hold which stripes). One MDS per filesystem.
> - **OSS (Object Storage Server) + OST:** Stores actual file data in stripe chunks. Multiple OSSes for parallelism.
>
> **Operation:** A client opens a file → contacts MDS for metadata/layout → directly contacts OSSes for parallel I/O across multiple OSTs. This enables **very high throughput** by striping one file across many disks simultaneously.
>
> **Used in:** Top 500 supercomputers, scientific computing clusters.

---

**Q16.3 / Q16.4** Explain GlusterFS architecture. How is it different from Lustre? *(8M)*

> **Answer:**
> **GlusterFS** is a distributed network filesystem that aggregates storage across multiple commodity servers. Architecture:
>
> ```
>     Clients
>        │  GlusterFS/FUSE/NFS
>        ▼
>   ┌─────────────────────────────┐
>   │  Gluster Trusted Pool        │
>   │  ┌────────┐  ┌────────┐     │
>   │  │ Node 1 │  │ Node 2 │ ... │
>   │  │ Brick1 │  │ Brick2 │     │
>   │  └────────┘  └────────┘     │
>   └─────────────────────────────┘
> ```
>
> - **Brick:** A directory on a server's local filesystem — the basic storage unit.
> - **Volume:** A logical grouping of bricks with a specific distribution/replication policy.
> - **Volume Types:**
>   - *Distributed:* Files spread across bricks (like RAID 0; no redundancy).
>   - *Replicated:* Files replicated across bricks (like RAID 1; redundancy).
>   - *Striped:* Large files striped across bricks for throughput.
>   - *Distributed-Replicated:* Combination (most common in production).
>
> **GlusterFS vs Lustre:**
>
> | Feature | GlusterFS | Lustre |
> |---|---|---|
> | Architecture | Decentralized (no metadata server) | Centralized MDS |
> | Metadata | Hashing-based (DHT — no dedicated metadata node) | Dedicated MDS/MDT |
> | Use case | General-purpose, scale-out NAS | HPC, max throughput |
> | Ease of setup | Easy | Complex |
> | Scalability | Moderate | Extreme (exabyte scale) |

---

<a name="17"></a>

## 17. Consistency Models

---

**Q17.1** Explain Strict, Sequential, Causal, and PRAM consistency. *(8M)*

> **Answer:**
> 1. **Strict Consistency:** Any read on a data item returns the most recently written value. All operations appear instantaneous and globally ordered. Practically impossible in distributed systems (requires zero latency). Strongest model.
>
> 2. **Sequential Consistency:** Operations appear to execute in some sequential order, and the order of operations of each process is preserved as per the program order. Different processes may see the same global order, but it doesn't have to reflect real time.
> *Example:* P1 writes X=1 then X=2. Any process reads X=1 before X=2. But two processes can see the same interleaved order of all writes.
>
> 3. **Causal Consistency:** Causally related writes must be seen by all processes in the same order. Concurrent (causally unrelated) writes may be seen in different orders by different processes.
> *Example:* P1 posts "Question" → P2 posts "Answer" (causally after). All processes see "Question" before "Answer". But two unrelated posts can appear in any order.
>
> 4. **PRAM (Pipelined RAM) Consistency:** Each process's writes are seen by all other processes in the order in which they were issued by that process. But writes from different processes may be interleaved differently at each receiver.
> Weaker than sequential; easier to implement; used in pipelined memory systems.

---

**Q17.3** Explain Linearizability with compare-and-set. *(part Q)*

> **Answer:**
> **Linearizability** (strong/atomic consistency): Each operation appears to execute instantaneously at some point between its start and end. The system behaves as if there is a single copy of the data.
>
> **Compare-and-Set (CAS):** An atomic operation: "if current value == expected, set to new value."
> ```
> CAS(x, expected=5, new=10):
>   if x == 5: x = 10; return true
>   else: return false
> ```
> In a linearizable system, CAS is atomic — no other operation can execute between the compare and the set. This is used to implement distributed locks: first process to CAS from null to "locked" wins the lock.

---

<a name="18"></a>

## 18. CAP Theorem

---

**Q18.1 / Q18.3** What does the CAP theorem state? How do you choose a database based on it? *(6–8M)*

> **Answer:**
> **CAP Theorem** (Brewer, 2000): In a distributed system, you can only guarantee **two out of three** properties:
> - **C (Consistency):** Every read returns the most recently written value (linearizability).
> - **A (Availability):** Every request receives a response (may not be the latest value).
> - **P (Partition Tolerance):** System continues operating despite network partitions.
>
> **Key insight:** Network partitions are unavoidable in distributed systems. So the real trade-off is **C vs A** during a partition.
>
> **Choosing a database:**
>
> | System Type | Choice | Examples | When to use |
> |---|---|---|---|
> | **CP** (Consistent + Partition Tolerant) | Sacrifice availability; return error during partition | HBase, Zookeeper, MongoDB (default) | Financial transactions; inventory; anything requiring correct data over availability |
> | **AP** (Available + Partition Tolerant) | Sacrifice consistency; return stale data during partition | Cassandra, CouchDB, DynamoDB | Social media feeds; DNS; shopping carts where stale data is acceptable |
> | **CA** | Only possible without partitions | PostgreSQL (single node) | Small, non-distributed systems |
>
> **Example decision:** Building a banking app → CP system (HBase). Building a Twitter-like feed → AP system (Cassandra). Wrong data in a bank is dangerous; slightly stale tweets are fine.

---

**Q18.4** Explain eventual consistency and how it is achieved. *(Aug 2013)*

> **Answer:**
> **Eventual consistency:** Given no new updates, all replicas will eventually converge to the same value. There is no guarantee on *when*, only *eventually*.
>
> **How it is achieved in cloud systems:**
> 1. **Replication with async propagation:** Writes go to one node; changes propagated asynchronously to replicas.
> 2. **Read repair:** When a client reads from multiple replicas and detects stale data on one, it writes the latest value back.
> 3. **Anti-entropy:** Background process continuously compares replicas and syncs differences using techniques like Merkle trees.
> 4. **Gossip protocol:** Nodes randomly exchange state information with neighbors; updates propagate through the cluster like a rumor.
>
> *Example:* DynamoDB, Cassandra, CouchDB all implement eventual consistency with tunable consistency levels (quorum reads/writes).

---

<a name="19"></a>

## 19. Replication — Leader-based, Multi-leader, Leaderless

---

**Q19.1** Explain Leader-based replication. *(5M)*

> **Answer:**
> **Leader-based (Single-Leader) Replication:**
> ```
> Client writes → Leader → replication log → Follower 1
>                                          → Follower 2
> Client reads  → any replica (leader or follower)
> ```
> - One replica is the **leader** (primary). All writes must go through it.
> - Leader writes to local storage → sends **replication log** to followers.
> - **Followers** apply changes in the same order as the leader.
> - Reads can go to any replica (leader for strong consistency; follower for eventual consistency).
> - **Failover:** If leader fails, a follower is promoted (manual or automatic).
> - **Used by:** PostgreSQL, MySQL, Kafka, RabbitMQ.
>
> **Sync vs Async:** Synchronous → follower must confirm before leader ACKs client (durable but slower). Async → leader ACKs immediately (fast but risk of data loss on failover).

---

**Q19.2 / Q19.3** What is replication? Types based on number of leaders? Explain leaderless. *(5–10M)*

> **Answer:**
> **Replication:** Keeping copies of the same data on multiple nodes for: (1) Low latency geo-proximity, (2) Fault tolerance, (3) Read scalability.
>
> **Three types:**
> 1. **Single-Leader:** One leader accepts writes → propagates to followers. Simple, no conflict. (See Q19.1)
> 2. **Multi-Leader:** Multiple nodes accept writes; each also replicates to the others. Used in multi-datacenter setups. Risk of write conflicts.
> 3. **Leaderless:** All nodes are equal — any node accepts reads and writes. Quorum-based.
>
> **Leaderless Replication (Dynamo-style):**
> - Client writes to **W** replicas simultaneously; write succeeds if W nodes ACK.
> - Client reads from **R** replicas simultaneously; takes the most recent value.
> - Quorum condition: **W + R > N** ensures at least one node in any read set has the latest write.
> - **Read repair:** Stale replica detected on read → client writes latest value back.
> - **Anti-entropy:** Background sync process.
> - *Examples:* Amazon DynamoDB, Apache Cassandra, Riak.

---

<a name="20"></a>

## 20. Partitioning, Sharding and Rebalancing

---

**Q20.1** Explain 3 rebalancing techniques: Fixed partitions, Dynamic, Proportional. *(10M)*

> **Answer:**
> **Why rebalance?** As nodes join/leave or dataset grows, partitions must be redistributed to keep load balanced.
>
> **1. Fixed Number of Partitions:**
> - Create many more partitions than nodes at the start (e.g., 100 partitions for 4 nodes → 25 each).
> - When a new node joins, it takes some partitions from existing nodes.
> - Partition count stays fixed; only ownership changes.
> - **Pro:** Simple; data movement is bounded.
> - **Con:** Choosing the right initial count is hard; too few = can't scale; too many = per-partition overhead.
>
> **2. Dynamic Partitioning:**
> - No fixed number; partitions **split** when they grow beyond a threshold (e.g., 10 GB) and **merge** when they shrink.
> - HBase uses this approach.
> - **Pro:** Adapts automatically to dataset size.
> - **Con:** Starts with 1 partition (bottleneck) until first split. Pre-splitting mitigates this.
>
> **3. Partitioning Proportional to Nodes:**
> - Fixed number of partitions **per node** (e.g., 10 partitions per node).
> - When a new node joins, it randomly picks existing partitions to split, takes half of each.
> - Total partition count grows with nodes; partition sizes stay roughly constant.
> - **Pro:** Balanced sizes; grows naturally with cluster. Used in Cassandra.

---

**Q20.4** Hash-based partitioning and leaderless replication. *(10M)*

> **Answer:**
> **Hash-based partitioning:**
> - Apply a hash function to the key → assign partition based on hash range.
> - Distributes keys uniformly, avoids hot spots.
> - *Example:* MD5(user_id) mod N for N partitions.
> - **Limitation:** Cannot do range queries efficiently.
>
> **Consistent Hashing:**
> - Place nodes and keys on a circular hash ring.
> - Key assigned to first node clockwise from it on the ring.
> - Adding/removing node moves only K/N keys.
> - Minimizes rehashing on topology change.
>
> **Leaderless replication:** *(See Q19.2 for full answer.)*

---

<a name="21"></a>

## 21. Request Routing

---

**Q21.1** Explain all 4 types of request routing with diagrams. *(12M)*

> **Answer:**
> When a client wants to read/write key `k`, it must know which node owns the partition for `k`. This is the **service discovery / request routing problem**.
>
> **Type 1 — Client contacts any node (Round-robin):**
> ```
> Client → Node A (doesn't own k) → Node A forwards to Node C (owns k) → response
> ```
> - Client sends to any node; that node forwards if needed.
> - Each node knows the partition-to-node mapping.
>
> **Type 2 — Routing Tier (Load Balancer):**
> ```
> Client → Routing Tier (knows partition map) → correct Node
> ```
> - A dedicated routing tier/load balancer has the full partition map.
> - Client is partition-unaware; routing tier directs to correct node.
>
> **Type 3 — Client-side routing (Partition-aware client):**
> ```
> Client (knows partition map) → directly contacts correct Node
> ```
> - Client library knows partition-to-node mapping and connects directly.
> - Most efficient; requires client to subscribe to routing changes.
>
> **Type 4 — ZooKeeper-based coordination:**
> ```
> Nodes register in ZooKeeper → Routing tier subscribes to ZooKeeper → client → routing tier → correct node
> ```
> - ZooKeeper maintains the authoritative partition-to-node mapping.
> - Routing tier or client subscribes to ZooKeeper for change notifications.
> - Used by HBase, SolrCloud.

---

<a name="22"></a>

## 22. Transactions, 2PC and ACID

---

**Q22.1** Explain Two-Phase Commit Protocol. *(8M)*

> **Answer:**
> **2PC** ensures atomicity across multiple distributed sites — all commit or all abort.
>
> **Participants:** Transaction Coordinator (TC) + Transaction Managers (TM) at each site.
>
> **Phase 1 — Voting (Prepare):**
> 1. TC writes `PREPARE T` to its log.
> 2. TC sends `prepare T` to all participating sites.
> 3. Each TM prepares local transaction:
>    - If ready: writes `Ready T`, sends `Ready T` to TC.
>    - If not ready: writes `Abort T`, sends `Don't Commit T`.
>
> **Phase 2 — Decision (Commit/Abort):**
> - **All voted Ready:** TC writes `Commit T`, sends `commit T` to all. TMs commit, release locks, send `Done`.
> - **Any voted Abort:** TC writes `Abort T`, sends `abort T` to all. TMs roll back, release locks, send `Done`.
>
> ```
> TC ──prepare──▶ TM1, TM2, TM3
> TC ◀── Ready ── TM1, TM2, TM3  (all ready)
> TC ──commit──▶ TM1, TM2, TM3
> TC ◀── Done ──  TM1, TM2, TM3
> ```
>
> **Limitation:** If TC crashes after Phase 1, all TMs are stuck in uncertain state holding locks — **blocking protocol**.

---

**Q22.2** How reliable messaging solves problems of recipient crashing, changing, and recovery. *(exam Q)*

> **Answer:**
> - **(i) Recipient crashing:** HTTP: request lost if recipient is down at time of call. Messaging: message persisted in a **durable queue**; recipient reads it when it comes back up. Queue holds message until ACK'd.
> - **(ii) Recipient changing:** HTTP: hardcoded endpoint; URL change breaks callers. Messaging: consumers subscribe to a **topic/queue name**; producer doesn't know about consumer's location. Consumer can change address/scale without affecting producers.
> - **(iii) Recovery from crash:** HTTP: caller must implement its own retry logic, track state. Messaging: queue ensures **at-least-once delivery**; consumer re-reads unACK'd message after restart. Idempotent handlers ensure no side effects from reprocessing.

---

<a name="23"></a>

## 23. Multitenancy and Multitenant Databases

---

**Q23.1** Explain different types of multitenant architecture for a database. *(6M)*

> **Answer:**
> **Multitenancy:** Single software instance serves multiple customers (tenants).
>
> **Type 1 — Single database, single schema:**
> - All tenants share one DB. Rows tagged with `tenant_id`.
> - Simplest; cheapest; highest resource utilization.
> - Risk: bugs could expose one tenant's data to another.
>
> **Type 2 — Single application, separate databases per tenant:**
> - Same app code; each tenant gets their own DB instance.
> - Stronger isolation; easier per-tenant backup.
> - Higher resource cost; DB sprawl.
>
> **Type 3 — Separate application and database instances per tenant:**
> - Full isolation; easiest compliance; highest cost.
> - Not truly multi-tenant — just dedicated hosting.
>
> **Special patterns:**
> - **Pre-allocated column method:** Shared table with extra columns (col1, col2, …) that each tenant can use for their custom fields.
> - **Name-value pair:** Extension table with (tenant_id, entity_id, attribute_name, attribute_value) for unlimited custom fields.

---

**Q23.5** Design multitenant DB with name-value pairs. *(6M)*

> **Answer:**
> **Name-Value Pair (Extension Table) Method:**
> ```
> Main table:
> ┌───────────┬──────────┬─────────┐
> │ tenant_id │ entity_id│ name    │
> ├───────────┼──────────┼─────────┤
> │   T1      │   001    │  Alice  │
> │   T2      │   101    │  Bob    │
> └───────────┴──────────┴─────────┘
>
> Extension table:
> ┌───────────┬──────────┬──────────────┬─────────────────┐
> │ tenant_id │ entity_id│ attr_name    │ attr_value      │
> ├───────────┼──────────┼──────────────┼─────────────────┤
> │   T1      │   001    │ email        │ alice@t1.com    │
> │   T2      │   101    │ grade        │ A               │
> │   T2      │   101    │ NextAppt     │ 2024-03-15      │
> └───────────┴──────────┴──────────────┴─────────────────┘
> ```
> Each tenant can add unlimited custom fields without schema changes. Queries use JOIN + filter on tenant_id and attr_name.

---

**Q23.6 / Q23.7 / Q23.8** Pre-allocated column method for universities/hospitals. *(5–6M)*

> **Answer (generic template for pre-allocated column method):**
> ```
> SHARED_STUDENTS table:
> ┌────────────┬──────────┬──────────────┬──────────┬────────┬───────────────┐
> │ tenant_id  │ USN      │ name         │ ext_col1 │ ext_col2 │ ext_col3  │
> ├────────────┼──────────┼──────────────┼──────────┼──────────┼───────────┤
> │ ModernUniv │ 1PE21CS01│ Alice        │alice@m.com│  NULL  │   NULL    │
> │ SuperUniv  │ 1PE21CS02│ Bob          │  NULL    │   A+   │   NULL    │
> └────────────┴──────────┴──────────────┴──────────┴──────────┴───────────┘
> ```
> Tenant metadata table defines which ext_col maps to which field per tenant:
> ```
> TENANT_COLUMNS:
> ┌────────────┬──────────┬─────────────┐
> │ tenant_id  │ col_name │ meaning     │
> ├────────────┼──────────┼─────────────┤
> │ ModernUniv │ ext_col1 │ email       │
> │ SuperUniv  │ ext_col2 │ grade       │
> └────────────┴──────────┴─────────────┘
> ```

---

<a name="24"></a>

## 24. Leader Election Algorithms

---

**Q24.1 / Q24.6** Purpose of leader election. Explain Bully Algorithm and Ring election. *(8–10M)*

> **Answer:**
> **Purpose:** Many distributed algorithms need a single coordinator. When the current leader fails (no heartbeat after timeout), a new leader must be elected so the system can continue.
>
> **Ring Election Algorithm:**
> - Nodes arranged in a logical ring; messages go clockwise.
> - When node Pi detects leader failure:
>   1. Pi sends `election(id:attr)` clockwise.
>   2. Each receiving node Pj compares the attr in message with its own:
>      - Message attr > Pj.attr → forward unchanged.
>      - Message attr < Pj.attr, and Pj hasn't sent → overwrite with Pj's attr and forward.
>      - Message attr == Pj.attr → Pj has the best attr; **Pj is the new leader**.
>   3. New leader sends `elected` message around ring.
> - **Worst case:** 3(N-1) messages when highest-attr node is just counter-clockwise of initiator.
>
> **Bully Algorithm:**
> - Every process knows all others and their IDs. Higher ID wins.
> - Process Pi detects leader failure:
>   1. If Pi has the **highest ID** → sends `Coordinator` to all lower-ID processes → done.
>   2. Else: sends `Election` to all higher-ID processes; starts timeout.
>      - No reply → Pi wins; sends `Coordinator` to all lower-ID.
>      - Reply received → higher process exists; wait for `Coordinator`.
>      - No `Coordinator` after second timeout → restart election.
> - Any process receiving `Election` sends `Disagree` and starts its own election.
> - **Result:** Highest available process always wins — it "bullies" others into acceptance.

---

**Q24.3** Ring algorithm worst-case scenario and modified version. *(8M)*

> **Answer:**
> **Ring Election Worst Case:**
> - Worst case occurs when the node with the highest attribute (best candidate) is located **just counter-clockwise** of the initiator.
> - The election message must travel N-1 hops before reaching the best candidate.
> - Then the elected message travels N hops around the full ring.
> - Plus the initial N-1 hops for the election message.
> - **Total: 3(N-1) messages.**
>
> **Problem with Ring Election:**
> - If a node **fails during the election** (while the message is circulating), the election may loop forever or deliver an incorrect result.
>
> **Modified Ring Election Algorithm:**
> - Instead of overwriting the ID, each node **appends** its `id:attr` to the message as it passes.
> - The initiator receives the complete list of all participating nodes and their attributes.
> - The initiator selects the best node from the list and announces the winner.
> - **Advantage:** More resilient to node failures during election; complete view of participating nodes available.

---

**Q24.4** Best and worst case of Bully Algorithm. *(6M)*

> **Answer:**
> **Best Case:**
> - The process with the **second-highest ID** detects the failure and initiates the election.
> - It sends `Election` to only the one higher-ID process (the failed one — no reply).
> - After timeout, it broadcasts `Coordinator` to all N-2 lower-ID processes.
> - **Messages: N-1 total.** Very fast.
>
> **Worst Case:**
> - The process with the **lowest ID** detects the failure and initiates the election.
> - It sends `Election` to N-1 higher-ID processes.
> - Each of those sends `Election` to the processes above it.
> - Eventually the highest-ID alive process wins and sends `Coordinator` to N-1 processes.
> - **Messages: O(N²).** Potentially very slow in large clusters.

---

<a name="25"></a>

## 25. Distributed Locking and Fencing

---

**Q25.1** What is the problem with the distributed lock diagram? How is it solved? *(6M)*

> **Answer:**
> **The Problem (Stale Lock / Split-Brain):**
> ```
> Client 1 acquires lock (lease = 30s)
> Client 1 pauses (GC pause for 40s) → lease expires
> Client 2 acquires the same lock (lease = 30s)
> Client 1 resumes → thinks it still holds lock
> Client 1 and Client 2 both write to shared storage simultaneously → DATA CORRUPTION
> ```
> The problem: a process can hold a lock lease that has expired but not know it (due to GC pauses, network delays, slow execution).
>
> **Solution — Fencing Tokens:**
> ```
> Lock service issues monotonically increasing fencing token on every lock grant:
> Client 1 acquires lock → token = 33
> [Client 1 pauses; lock expires]
> Client 2 acquires lock → token = 34
> Client 2 writes with token 34 → storage accepts (34 > last seen 0)
> Client 1 resumes; writes with token 33 → storage REJECTS (33 < last seen 34)
> ```
> - Storage service tracks the highest fencing token seen.
> - Any write with a token lower than the highest seen is rejected.
> - Stale lock holders are automatically invalidated without coordination.
> - Requires storage service to be token-aware (check and update max token on each write).

---

<a name="26"></a>

## 26. Apache ZooKeeper

---

**Q26.1 / Q26.4** Explain how ZooKeeper works. Key benefits and common services. *(10M)*

> **Answer:**
> **ZooKeeper** is a distributed coordination service providing a hierarchical namespace (like a filesystem) with strong consistency guarantees.
>
> **Architecture:**
> - **Ensemble:** A cluster of ZooKeeper servers (typically 3 or 5 for quorum).
> - **Leader:** Elected at startup; handles all write requests; coordinates consensus via Zab protocol.
> - **Followers:** Serve read requests locally; forward writes to leader.
> - **Client:** Connects to one ZooKeeper server; creates a **session** (heartbeat-based).
>
> **Data Model — znodes:**
> - `/app1/config`, `/app1/lock` — hierarchical paths.
> - **Persistent znodes:** Survive session end; must be explicitly deleted.
> - **Ephemeral znodes:** Deleted automatically when creating client's session ends (used for presence detection).
> - **Sequential znodes:** Path gets a monotonically increasing number appended (e.g., `/lock/req-0001`).
>
> **Watches:** Clients register a watch on a znode — get notified when it changes/disappears.
>
> **Key Benefits:**
> 1. **Wait-free:** Slow clients don't block fast ones.
> 2. **High throughput:** Read-optimized; data in memory.
> 3. **Strong ordering:** All updates totally ordered by zxid.
> 4. **Session management:** Ephemeral nodes auto-cleanup on crash.
>
> **Common Services (Recipes):**
> 1. **Leader election:** Nodes create ephemeral-sequential znodes; smallest ID = leader; watchers detect failure and trigger new election.
> 2. **Distributed locks:** N clients create sequential znodes; smallest holds lock; next watches previous.
> 3. **Configuration management:** Centralized config in znodes; all nodes watch for changes.
> 4. **Naming service:** Maps service names to IP:port; nodes register ephemeral znodes when they start.
> 5. **Group membership / failure detection:** Each node registers ephemeral znode; ZooKeeper deletes it on failure.
>
> **Used by:** Apache Kafka, HBase, Storm, Yahoo!, LinkedIn.

---

<a name="27"></a>

## 27. Fault Tolerance — MTBF, MTTR, Fault Models

---

**Q27.1** Fault-tolerant system? Types of faults? MTBF/MTTR if unavailable for 30 min in 75 hrs due to 9 failures. *(5M)*

> **Answer:**
> **Fault-tolerant system:** A system designed to continue operating correctly even when some of its components fail.
>
> **Types of faults:**
> - **Transient:** Occurs once and disappears. (e.g., cosmic ray bit flip)
> - **Intermittent:** Appears, disappears, reappears randomly. (hardest to debug)
> - **Permanent:** Persists until repaired/replaced. (disk failure)
>
> **Calculation:**
> - Total time = 75 hours
> - Total downtime = 30 minutes = 0.5 hours
> - Total uptime = 75 - 0.5 = 74.5 hours
> - Number of failures = 9
>
> **MTBF (Mean Time Between Failures)** = Total uptime / Number of failures
> = 74.5 / 9 = **8.28 hours**
>
> **MTTR (Mean Time To Repair)** = Total downtime / Number of failures
> = 0.5 / 9 = **0.056 hours ≈ 3.33 minutes**

---

**Q27.2** Same but: unavailable for 60 min in 75 hrs due to 6 failures. *(5M)*

> **Answer:**
> - Total time = 75 hours; Downtime = 60 min = 1 hour; Uptime = 74 hours; Failures = 6
>
> **MTBF** = 74 / 6 = **12.33 hours**
>
> **MTTR** = 1 / 6 = **0.167 hours = 10 minutes**

---

**Q27.3** Explain: EDoS attack, Heartbeat and Probing, Failover Strategy, Types of faults. *(exam Q)*

> **Answer:**
> - **EDoS (Economic DoS):** Attacker sends enough traffic to trigger cloud auto-scaling, causing the victim's bill to skyrocket without actually causing a service outage. Goal is financial damage, not disruption.
> - **Heartbeat and Probing:** Heartbeat = periodic "I'm alive" signal sent between nodes; if missed N times → node declared dead. Probing = active query sent to a node to check if it's responsive.
> - **Failover Strategy:** When a primary component fails, traffic/load automatically switches to a pre-configured backup (standby replica, secondary server). Active-passive: standby takes over. Active-active: load already balanced; remaining nodes absorb failed node's share.
> - **Types of faults:** Transient, Intermittent, Permanent (see Q27.1). Also by model: crash-stop, crash-recovery, omission, timing, Byzantine.

---

<a name="28"></a>

## 28. Resource Management and Scheduling

---

**Q28.2** Soft and hard constraints in Nova scheduler. Examples. *(exam Q)*

> **Answer:**
> Nova (`nova-scheduler`) places VM instances on physical hosts using filters and weights.
>
> - **Hard constraints (Filters):** Must be satisfied; host is eliminated if it fails. Examples:
>   - `RamFilter`: Host must have enough free RAM for the requested instance.
>   - `CoreFilter`: Host must have enough vCPUs.
>   - `AvailabilityZoneFilter`: Host must be in the requested AZ.
>   - `ImagePropertiesFilter`: Host's hypervisor must support the image's required capabilities.
>
> - **Soft constraints (Weights):** Preferences; hosts are ranked. Host with highest weight wins. Examples:
>   - `RAMWeigher`: Prefer host with most free RAM (spread VMs evenly).
>   - `ServerGroupAffinityFilter`: Prefer hosts where a group's VMs are co-located.
>   - `ServerGroupAntiAffinityFilter`: Prefer hosts that don't already have group VMs (spread for HA).

---

**Q28.4** Explain distributed system model with an example. *(part Q)*

> **Answer:**
> A **distributed system** consists of multiple independent components on different networked machines that communicate and coordinate to appear as a single coherent system to users.
>
> **Key characteristics:**
> - Concurrency of components
> - No global clock (clocks can drift; use logical clocks)
> - Independent failures (some parts can fail while others run)
>
> **Example — P2P vs Client-Server:**
> - **Client-Server (e.g., Hadoop MapReduce):** Master assigns tasks to worker nodes; monitors progress; re-assigns failed tasks. Single master = clear coordination but SPOF.
> - **P2P (e.g., BitTorrent):** Each peer is both client and server. No central coordinator; peers exchange file chunks directly. Resilient; scales well.

---

<a name="29"></a>

## 29. Scalability Strategies, Cloud Bursting and Hybrid Cloud

---

**Q29.1** What is Cloud Bursting? How is it beneficial? *(6M)*

> **Answer:**
> **Cloud Bursting:** A hybrid cloud configuration where an organization runs normal workloads on its private cloud but automatically **overflows/bursts** to a public cloud when private cloud capacity is fully utilized (100%).
>
> ```
> Normal load → Private Cloud
> Peak load   → Private Cloud (at capacity) + Public Cloud (burst)
> ```
>
> **Benefits:**
> 1. **Cost efficiency:** Pay for public cloud resources only during burst periods — no wasted idle capacity in private cloud.
> 2. **Performance:** Users don't experience degradation during sudden spikes; public cloud absorbs overflow.
> 3. **Flexibility:** Handles unpredictable spikes (viral content, seasonal sales, emergency processing) without over-provisioning private hardware.
> 4. **Data control:** Sensitive data stays in private cloud; only general compute workloads burst.
>
> *Example:* A university's learning portal runs on-prem. During exams, student load spikes 10x. Cloud bursting provisions extra VMs on AWS to handle the peak, then terminates them after.

---

**Q29.2** Load Balancer — note and operation. *(10M)*

> **Answer:**
> **Load Balancer:** A device (hardware or software) that distributes incoming network traffic across multiple backend servers.
>
> ```
>         ┌────────────┐
> Client →│    Load    │→ Server 1
> Client →│  Balancer  │→ Server 2
> Client →│            │→ Server 3
>         └────────────┘
> ```
>
> **Algorithms:**
> - **Round Robin:** Requests distributed in rotation (1→2→3→1→2→3…).
> - **Least Connections:** New request goes to server with fewest active connections.
> - **IP Hash:** Client IP hash determines which server handles all requests from that client (session affinity).
> - **Weighted Round Robin:** Servers with higher capacity receive proportionally more requests.
>
> **Features:** Health checks (removes unhealthy servers), SSL termination (HTTPS handled at LB; backend uses HTTP), session persistence, and request/response compression.
>
> *Examples:* AWS Elastic Load Balancer (ELB), Nginx, HAProxy.

---

<a name="30"></a>

## 30. Reverse Proxy

---

**Q30.1** What is a reverse proxy? Benefits? How is it different from forward proxy? *(6M)*

> **Answer:**
> **Reverse Proxy:** Sits in front of backend servers. Clients send requests to the proxy; proxy forwards to appropriate backend. Clients never directly access backend servers.
>
> **Benefits:**
> 1. **Security:** Hides backend server IPs; blocks malicious requests; WAF (Web App Firewall) integration.
> 2. **Load balancing:** Distributes traffic across multiple backend servers.
> 3. **Caching:** Serves cached static content (images, CSS) without hitting backend.
> 4. **SSL termination:** Handles HTTPS at proxy; backends communicate via HTTP internally.
> 5. **Compression:** Compresses responses before sending to clients.
> 6. **Identity branding:** Can hide that payments go to Stripe, etc.
>
> **Forward vs Reverse Proxy:**
>
> | Feature | Forward Proxy | Reverse Proxy |
> |---|---|---|
> | Sits in front of | Clients | Servers |
> | Configured by | Client / organization | Server / web service |
> | Hides | Client identity from server | Server identity from client |
> | Use cases | Corporate internet filtering, VPN, anonymity | Load balancing, caching, security |
>
> *Examples:* Forward proxy = corporate web filter, Squid. Reverse proxy = Nginx, HAProxy, AWS ALB.

---

<a name="31"></a>

## 31. Cloud Security — DoS, DDoS, EDoS

---

**Q31.1 / Q31.2** Cloud security terms: Cloud Time Service, Identity Management, Access Management, Break-Glass, Key Management. *(exam Q)*

> **Answer:**
> 1. **Cloud Time Service:** Synchronized time across all cloud nodes. Critical for log correlation, token expiry, and distributed transactions. Uses NTP (Network Time Protocol) or PTP (Precision Time Protocol).
> 2. **Identity Management:** Managing who users are — creating, storing, and verifying user identities (authentication). Includes directory services (LDAP), SSO (Single Sign-On), federated identity.
> 3. **Access Management:** Controlling what authenticated users can do (authorization). Implemented via RBAC (Role-Based Access Control) or ABAC (Attribute-Based). Enforces least-privilege principle.
> 4. **Break-Glass Procedures:** Emergency access procedures that bypass normal access controls when authorized personnel cannot gain access through normal channels (e.g., forgotten credentials during an outage). Audited and time-limited.
> 5. **Key Management:** Managing the lifecycle of cryptographic keys — generation, distribution, rotation, revocation, and storage. Services: AWS KMS, HashiCorp Vault.

---

**Q31.4** What is a DoS attack? How is it different from DDoS? Distinguish EDoS. *(6M)*

> **Answer:**
> **DoS (Denial of Service):**
> - Attack from a **single source** flooding a target with requests to overwhelm it.
> - Two types: (1) Buffer overflow — crash the server. (2) Flood attack — saturate bandwidth/CPU.
> - Easier to block (block one source IP).
>
> **DDoS (Distributed Denial of Service):**
> - Attack from **many sources** (botnet of thousands of compromised machines) simultaneously.
> - Each bot sends seemingly legitimate traffic → hard to distinguish from real users.
> - Much harder to defend against; requires traffic scrubbing, anycast, rate limiting.
>
> **EDoS (Economic Denial of Sustainability):**
> - Does NOT aim to take down the service.
> - Attacker sends just enough traffic to **trigger cloud auto-scaling**.
> - Victim's cloud bill skyrockets as platform auto-provisions expensive resources.
> - Attack is sustained and low-rate → looks like organic growth.
> - Harder to detect than DDoS; purely financial damage.
>
> | | DoS | DDoS | EDoS |
> |---|---|---|---|
> | Source | Single | Many (botnet) | Single or many |
> | Goal | Disrupt service | Disrupt service | Financial damage |
> | Intensity | High burst | Very high burst | Low, sustained |
> | Detection | Easy | Harder | Very hard |

---

<a name="32"></a>

## 32. Authentication in Cloud — Keystone

---

**Q32.1** Explain Keystone concepts: Roles, Assignment, Targets, Tokens, Catalog. *(10M)*

> **Answer:**
> OpenStack Keystone is the identity service providing authentication, authorization, and service discovery.
>
> | Concept | Explanation |
> |---|---|
> | **Project** | Container that groups and isolates resources (VMs, images). Users get access via role assignments on a project. |
> | **Domain** | A collection of users, groups, and projects belonging to one organization. Enables multi-org isolation. |
> | **User** | An individual with credentials. Can belong to multiple projects via role assignments. |
> | **Group** | A collection of users. Assign a role to a group → all members get that role. |
> | **Role** | Defines what actions are permitted. Examples: `admin`, `member`, `reader`. Roles are arbitrary strings; enforcement via `policy.json`. |
> | **Assignment** | Ternary tuple: (Actor=User/Group) + (Target=Project/Domain) + (Role). Grants Actor the Role on Target. |
> | **Target** | The Project or Domain on which a role is granted. |
> | **Token** | Proof of successful authentication. Scoped to a Project. Contains user info, roles, expiry, and catalog. Passed in `X-Auth-Token` header with all API calls. |
> | **Catalog** | Service catalog embedded in token — lists endpoints (URLs) for all OpenStack services (Nova, Swift, Neutron, etc.). Clients use this to know where to make API calls. |

---

**Q32.3** Domain in Keystone, Token in Keystone, DoS Attack, Honeypot Design Pattern. *(8M)*

> **Answer:**
> - **Domain in Keystone:** A high-level namespace containing users, groups, and projects for one organization. Enables Keystone to serve multiple organizations (multi-tenancy at org level). Admins of one domain cannot see resources of another domain.
> - **Token in Keystone:** A cryptographically signed proof of identity issued after successful authentication. Contains user identity, assigned roles, project scope, and service catalog. Has an expiry time. Revocable. Passed as `X-Auth-Token` header in all API requests.
> - **DoS Attack:** *(See Q31.4 above.)*
> - **Honeypot Design Pattern:** A decoy system or resource that mimics a real target to attract and trap attackers. Attackers interacting with the honeypot reveal their methods and tools without accessing real data. Used for threat intelligence and early intrusion detection.

---

<a name="33"></a>

## 33. Security Design Patterns

---

**Q33.1** Explain CMDB and Defense in Depth. *(exam Q)*

> **Answer:**
> - **CMDB (Configuration Management Database):** A repository storing information about all IT assets (servers, VMs, software, network devices) and their relationships. Used to track infrastructure changes, audit compliance, and support incident response. In cloud: auto-populated via discovery tools scanning running resources.
> - **Defense in Depth:** A layered security strategy where multiple independent security controls protect a system. If one layer is breached, others still defend. Layers include: physical security → network security (firewalls) → host security (OS hardening) → application security (WAF, input validation) → data security (encryption). Based on the principle that no single control is perfect.

---

**Q33.2** Defense in Depth, Honeypots, Sandboxes, Network Patterns. *(8M)*

> **Answer:**
> 1. **Defense in Depth:** *(See Q33.1 above.)*
> 2. **Honeypots:** Decoy resources (fake servers, databases) designed to attract attackers. When an attacker interacts with a honeypot, security teams are alerted. Honeypots have no legitimate traffic — any access is suspicious.
> 3. **Sandboxes:** Isolated execution environments where untrusted code can run safely without affecting the host system. Used to analyze malware, test browser code, or run untrusted user uploads. *Examples:* Docker containers, browser tabs (V8 sandbox), AWS Lambda execution environments.
> 4. **Network Patterns:** Security patterns applied at the network level:
>    - *Perimeter defense:* Firewalls at network boundary.
>    - *Network segmentation:* VLANs/subnets isolate different trust zones (e.g., web tier, app tier, DB tier).
>    - *Zero-trust networking:* Never trust; always verify — even internal traffic requires authentication.

---

<a name="34"></a>

## 34. Miscellaneous / Advanced and Older Topics

---

**Q34.1** Would you use Windows Azure to port a legacy Cobol application? *(3M)*

> **Answer:**
> **Not directly.** Windows Azure (now Microsoft Azure) supports .NET, Java, Python, and Node.js runtimes natively. Cobol is not natively supported. However, there are options:
> 1. Use an Azure VM (IaaS) and install a Cobol compiler/runtime (Micro Focus COBOL, GnuCOBOL) on it — highest control but most maintenance.
> 2. Wrap the Cobol logic in a container and deploy on Azure Container Instances.
> 3. Re-write the application in a supported language first (recommended for long-term cloud-native benefit).
>
> **Conclusion:** Azure can host Cobol via IaaS, but it's not the ideal path — porting to a modern language would be better for cloud-native features.

---

**Q34.2** Azure clusters, fault domains, upgrade domains. *(3M)*

> **Answer:**
> - **Cluster:** A group of physical servers (nodes) in the same Azure data center that share a network fabric. VMs within a cluster have low latency communication.
> - **Fault Domain:** A logical group of hardware sharing a common power source and network switch. VMs in different fault domains are protected from single hardware failures (power failure, switch failure). Azure places VMs in different fault domains when you use Availability Sets.
> - **Upgrade Domain:** A logical group of VMs that Azure upgrades/reboots together during planned maintenance. VMs in different upgrade domains are never rebooted simultaneously, ensuring at least some VMs stay available.

---

**Q34.3** Azure Table Service for users and music — partition/row keys. *(4M)*

> **Answer:**
> Azure Table Service is a key-value NoSQL store. Each entity has a **PartitionKey** (for distribution/grouping) and **RowKey** (unique within partition).
>
> **Schema design:**
> ```
> Table: UserMusic
> PartitionKey = userid  (e.g., "user123")
> RowKey       = albumid (e.g., "album456")
> Properties:
>   - name = "Abbey Road"
>   - userid = "user123"  (redundant but for queries)
>
> Example rows:
> ┌────────────┬──────────┬─────────────┐
> │PartitionKey│  RowKey  │    name     │
> ├────────────┼──────────┼─────────────┤
> │  user123   │ album001 │ Abbey Road  │
> │  user123   │ album002 │ Dark Side   │
> │  user456   │ album001 │ Thriller    │
> └────────────┴──────────┴─────────────┘
> ```
> Using `userid` as PartitionKey co-locates all of a user's music on the same partition → fast queries for "get all albums for user123". RowKey uniquely identifies each album within a user's partition.

---

**Q34.5** How can Garbage Collection lead to partitions? *(May 2019)*

> **Answer:**
> During a **stop-the-world GC pause**, a process (e.g., a ZooKeeper node or leader) completely stops executing — including sending heartbeats — for potentially hundreds of milliseconds to several seconds.
>
> From other nodes' perspective: the paused node has stopped responding → it looks like a network partition or node failure. Other nodes may:
> 1. Declare the paused node dead.
> 2. Elect a new leader.
> 3. The original node resumes after GC, thinks it is still the leader — now there are two leaders (split-brain).
>
> This is why lock leases and fencing tokens are critical: even if a GC-paused process thinks it holds the lock, the fencing token will reject its writes.

---

**Q34.7 / Q34.8** Chat system node failures and recovery. P2P vs client-server. *(May 2019)*

> **Answer:**
> **Types of node failures in a distributed chat system:**
> 1. **Crash-stop:** A chat node suddenly stops and never comes back.
> 2. **Crash-recovery:** A node crashes but comes back after restart.
> 3. **Omission:** Node is up but drops some messages.
> 4. **Network partition:** Nodes can't reach each other but both are running.
>
> **Recovery:**
> - **Coordinator failure:** Trigger leader election (Ring or Bully algorithm) among remaining nodes.
> - **Regular node failure:** Other nodes stop routing messages to it; connected users are reconnected to another node.
> - **Message loss:** Use message queues with persistence; undelivered messages retried.
>
> **Is the diagram a P2P system?** Yes, if each node (P1-P6) both receives from users and forwards to other nodes.
>
> **One function simpler in client-server:** **Read receipts / message ordering** — a central server can trivially assign sequence numbers to all messages. In P2P, achieving a globally agreed message order requires distributed consensus which is complex.

---

**Q34.9** What should Server1 do to provide iSCSI storage to Server2 and Server3? *(exam Q)*

> **Answer:**
> On Server1, configure it as an **iSCSI Target**:
> 1. Install `targetcli` or `tgt` (iSCSI target daemon).
> 2. Create a **backstore** (block device, file, or RAID volume to export).
> 3. Create an **IQN (iSCSI Qualified Name)** for the target.
> 4. Create a **LUN (Logical Unit Number)** mapped to the backstore.
> 5. Configure **ACLs** allowing Server2 and Server3's IQNs to connect.
> 6. Bind to the network interface and start the service.
>
> Server2 and Server3 run iSCSI **initiator** software (`iscsiadm`) to discover and connect to Server1's target, which appears as a local block device they can format and mount.

---

**Q34.10** What is genuinely unique about Cinder? Capacity planning approach. *(Dec 2021)*

> **Answer:**
> **Cinder (OpenStack Block Storage):** What is unique and disruptive is that Cinder provides **persistent block storage as a service** — volumes that outlive individual VM instances and can be attached/detached from VMs on demand. Before Cinder, cloud storage was ephemeral (lost when VM terminated). Cinder enables stateful workloads (databases) in a cloud-native way, making persistent storage as flexible as compute.
>
> **Capacity planning approach for Cinder:**
> 1. **Forecast demand:** Analyze current volume usage, growth rate, and peak usage patterns.
> 2. **Thin provisioning:** Allocate logically more storage than physically available (volumes are sparse); physical capacity added as actually used.
> 3. **Storage tiering:** Use SSDs for high-IOPS volumes (databases), HDDs for cold storage.
> 4. **Monitor utilization:** Alert when pool reaches 70-80% utilization to trigger expansion before running out.
> 5. **Replication factor:** Account for replication overhead (2x or 3x physical capacity needed for replicated volumes).

---

## High-Frequency Topics Summary

> Topics appearing in **3+ papers** — highest exam probability.

| Rank | Topic | Papers |
|---|---|---|
| ⭐⭐⭐ | Hypervisors (Type 1/2, Bare Metal/Hosted) | 12+ |
| ⭐⭐⭐ | Virtualization types + scenario Q | 10+ |
| ⭐⭐⭐ | VM Migration (Hot/Cold, Pre-copy/Post-copy) | 9+ |
| ⭐⭐⭐ | Leader Election (Ring + Bully) | 10+ |
| ⭐⭐⭐ | ZooKeeper | 8+ |
| ⭐⭐⭐ | CAP Theorem + database selection | 10+ |
| ⭐⭐⭐ | Cloud characteristics / features | 8+ |
| ⭐⭐⭐ | Service models + deployment models | 10+ |
| ⭐⭐⭐ | Elasticity vs Scalability | 9+ |
| ⭐⭐⭐ | Kubernetes (controller-manager, kubelets, pods) | 7+ |
| ⭐⭐⭐ | Replication (Leader + Leaderless) | 8+ |
| ⭐⭐⭐ | Partitioning / Rebalancing | 8+ |
| ⭐⭐⭐ | Lustre FS architecture | 7+ |
| ⭐⭐⭐ | GlusterFS architecture | 6+ |
| ⭐⭐⭐ | Docker architecture vs VM | 7+ |
| ⭐⭐⭐ | MTBF / MTTR numerical problems | 5+ |
| ⭐⭐⭐ | Distributed Locking / Fencing Tokens | 4+ |
| ⭐⭐⭐ | Multitenancy + pre-allocated column DB design | 6+ |
| ⭐⭐⭐ | Shadow Page Tables / Extended Page Tables | 5+ |
| ⭐⭐⭐ | DoS / DDoS / EDoS attacks | 5+ |
| ⭐⭐⭐ | Keystone Authentication concepts | 5+ |
| ⭐⭐⭐ | Consistency Models (Strict, Sequential, Causal, PRAM) | 5+ |
| ⭐⭐ | Serverless Computing + AWS Lambda | 4+ |
| ⭐⭐ | REST principles / API design | 5+ |
| ⭐⭐ | Microservices vs Monolithic | 5+ |
| ⭐⭐ | DevOps | 5+ |
| ⭐⭐ | Parallelism types (Bit, Instruction, Task) | 5+ |
| ⭐⭐ | Cloud Bursting | 3+ |
| ⭐⭐ | Security design patterns (Defense in Depth, Honeypot) | 4+ |
| ⭐⭐ | Namespaces and cgroups | 4+ |
| ⭐⭐ | Linux rings / privilege levels | 3+ |
| ⭐ | Reverse Proxy | 2+ |
| ⭐ | Request Routing (4 types) | 2+ |
| ⭐ | Popek-Goldberg Theorems | 3+ |
| ⭐ | Pub/Sub model | 2+ |

---

*Compiled from: PYQP (1)–(21), ESA papers Aug 2013 – Oct 2024, PES University.*