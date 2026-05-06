# Unit 1: Cloud Programming Models

## 1. Introduction to Cloud Computing

### Definition

> Cloud computing is a model for enabling **ubiquitous, convenient, on-demand** network access to a shared pool of configurable computing resources (networks, servers, storage, applications, and services) that can be rapidly provisioned and released with minimal management effort.

- **Data centers** house physical compute, storage, and networking infrastructure — these are called *Cloud Data Centers* when they host resources and enable cloud computing.
- Large clouds often have functions distributed over **multiple geographic locations**; a server close to the user is called an **edge server**.

### Essential Characteristics (NIST)

| Characteristic | Description |
|---|---|
| **On-demand self-service** | Resources auto-provisioned with minimal configuration |
| **Broad network access** | Access from desktops, laptops, and mobile devices |
| **Resource pooling** | Resources shared between many concurrent users |
| **Rapid elasticity** | Quickly increase or decrease computing resources |
| **Measured service** | Pay-as-you-go; consumers pay only for what is used |

### Benefits

- **Agility** – Spin up resources in minutes
- **Elasticity** – Scale up/down as business demands change
- **Cost savings** – Trade capital expense for variable operational expense
- **Global deployment** – Expand to new regions in minutes

---

## 2. Genesis and Evolution of Cloud Computing

- **60 years** of computing evolution: from centralized mainframes → parallel computing → distributed computing → cloud
- **High Performance Computing (HPC):** Processes data at high speed for short bursts (hours/days)
- **High Throughput Computing (HTC):** Handles large amounts of computing continuously; needed for web-scale applications
- Since 1990s: proliferation of HPC and HTC hidden in clusters, grids, and clouds

### Parallel Computing

- Uses multiple processors simultaneously to solve computational problems
- Types: **SIMD** (Single Instruction Multiple Data), **MIMD** (Multiple Instruction Multiple Data)
- Key in scientific computing, simulations

### Grid Computing

- Connects distributed, heterogeneous computers across organizations
- Uses middleware to coordinate resources
- **Example:** SETI@home, Large Hadron Collider data processing
- Predecessor to cloud computing in concept

---

## 3. Cloud Service Models

### IaaS – Infrastructure as a Service

- User manages: **OS, runtime, applications, data**
- Provider manages: physical hardware, networking, storage
- **Examples:** AWS EC2, Azure VMs, Google Compute Engine

### PaaS – Platform as a Service

- User manages: **only application code and data**
- Provider manages: OS, runtime, middleware, hardware
- **Examples:** Google App Engine, AWS Elastic Beanstalk, Heroku
- Key programming model: **REST APIs, message queues**

### SaaS – Software as a Service

- User manages: **nothing except usage**
- **Examples:** Gmail, Google Docs, Microsoft 365, Zoom, Salesforce CRM

```
                IaaS        PaaS        SaaS
Hardware        Provider    Provider    Provider
OS              User        Provider    Provider
Runtime         User        Provider    Provider
Application     User        User        Provider
Data            User        User        Provider
```

---

## 4. Cloud Deployment Models

### Public Cloud

- Resources owned and operated by a third-party cloud provider
- Delivered over the Internet
- **Pro:** Low cost, high scalability, no maintenance
- **Con:** Security concerns, less control, data sovereignty issues

### Private Cloud

- Cloud infrastructure operated solely for one organization
- Can be managed internally or by a third party; on-premises or off
- **Pro:** Enhanced security, greater control
- **Con:** Higher cost, limited scalability

### Hybrid Cloud

- Combination of public and private clouds
- Data and applications can move between them
- **Use case:** Cloud bursting — extend to public cloud when private capacity is exceeded
- **Pro:** Flexibility, cost optimization

### Multi-Cloud

- Using services from **multiple cloud providers** simultaneously
- Avoids vendor lock-in
- Combines best-of-breed services from different providers
- **Challenge:** Integration complexity, governance

---

## 5. Technology Challenges in Cloud/Distributed Computing

### Major Challenges

1. **Security** – Data is not under the user's physical control; verification is difficult
2. **Scalability** – Applications must handle rapidly growing user bases
3. **Latency** – Network delays impact application performance
4. **Reliability** – Must handle node/network failures gracefully
5. **Data consistency** – Keeping data in sync across distributed nodes
6. **Vendor lock-in** – Proprietary APIs make migration difficult
7. **Compliance** – Legal/regulatory requirements vary by region

---

## 6. IaaS Programming Model & Cloud Architecture

### Cloud Architecture Layers

```
  Applications
  ─────────────────────
  Platform / Middleware
  ─────────────────────
  Infrastructure (VMs, Storage, Networking)
  ─────────────────────
  Physical Hardware (Data Center)
```

### Key IaaS Concepts

- **Virtualization** is the core technology enabling IaaS (covered in Unit 2)
- **Auto-scaling:** Dynamically add/remove VMs based on load
- **Load Balancing:** Distribute traffic across multiple VM instances
- **Elastic IP / Virtual Networks:** Networking abstractions for VMs

---

## 7. Web Services and REST

### Web Services

- Software systems designed to support **interoperable machine-to-machine** interaction over a network
- Use standard protocols: HTTP, XML, JSON

### REST – REpresentational State Transfer

> REST is an **architectural style** for designing networked applications. It defines a set of constraints that make a web service **stateless, scalable, and easy to use**.

**An API adhering to REST constraints is called RESTful.**

#### REST Design Principles (Constraints)

| Principle | Description |
|---|---|
| **Client-Server** | Separation of UI from data storage; improves portability |
| **Stateless** | Each request contains all information needed; no session state on server |
| **Cacheable** | Responses must define themselves as cacheable or non-cacheable |
| **Uniform Interface** | Consistent API interface simplifies client-server interaction |
| **Layered System** | Client cannot tell whether it's connected to end server or intermediary |
| **Code on Demand** (optional) | Server can send executable code (e.g., JavaScript) to the client |

#### REST Key Elements

- **Resource:** The key abstraction — anything that can be named (user, order, product)
- **URI (Uniform Resource Identifier):** Identifies a resource
  - Example: `GET /users/123/orders`
- **Representation:** The form of the resource (JSON, XML, HTML)

#### HTTP Methods in REST

| Method | Operation | Idempotent? |
|---|---|---|
| `GET` | Read/retrieve a resource | Yes |
| `POST` | Create a new resource | No |
| `PUT` | Update/replace a resource | Yes |
| `PATCH` | Partial update | No |
| `DELETE` | Remove a resource | Yes |

#### REST vs SOAP

| Feature | REST | SOAP |
|---|---|---|
| Protocol | Uses HTTP | Protocol itself |
| Format | JSON, XML, HTML | XML only |
| Statefulness | Stateless | Can be stateful |
| Complexity | Simple | Complex |
| Performance | Better | Slower (more overhead) |
| WSDL Required? | No | Yes |
| Standards | Informal/guidelines | Strict WS-* standards |

> **Note:** HTTP can be used in non-RESTful ways (e.g., SOAP over HTTP). RESTful APIs are loosely based on HTTP methods.

---

## 8. PaaS Programming Model

### Message Queues and Pub-Sub Model

#### Message Queues

- A component of PaaS that enables **asynchronous communication** between services
- Producer pushes messages; Consumer pulls messages
- **Examples:** AWS SQS, RabbitMQ, ActiveMQ
- Decouples producers and consumers; handles varying loads

#### Publish-Subscribe (Pub/Sub) Model

- Publishers send messages to a **topic** (not directly to subscribers)
- Subscribers register interest in topics; receive all matching messages
- **Fan-out:** One message can be delivered to many subscribers
- **Examples:** AWS SNS, Google Pub/Sub, Apache Kafka
- Use case: Event-driven architectures, real-time notifications

```
Publisher → [Topic] → Subscriber 1
                    → Subscriber 2
                    → Subscriber 3
```

---

## 9. SaaS Programming Model: Microservices

### Monolithic Architecture

> A **monolithic application** is built as a single, indivisible unit — client-side UI, business logic, and data access layer all bundled together in one codebase with a single database.

#### Strengths of Monolithic Architecture

1. Simple development — one codebase
2. Simple testing — launch and test end-to-end
3. Simple deployment — copy packaged application to server
4. Simple horizontal scaling (initially)

#### Challenges of Monolithic Architecture

- Changes require full system rebuild
- Scalability becomes difficult as the application grows
- Difficult to adopt new technologies
- Reliability concerns — a single failure can bring down the whole system
- Long release cycles, large teams needed

---

### Microservices Architecture

> **Microservices** are small, independent services that work together, each running its own process and communicating via lightweight mechanisms (usually HTTP/REST APIs). Each service is built around a specific **business capability**.
> — Martin Fowler

#### Key Characteristics

- Distributed and loosely coupled
- Each service has its **own database**
- Independently deployable via automated pipelines
- Can be written in **different programming languages**
- Minimal centralized management

#### API Gateway

- Acts as the **single entry point** for all client requests
- Routes requests to the appropriate microservice
- Provides: security, load balancing, rate limiting, authentication
- Clients never call microservices directly

#### Benefits of Microservices

| Benefit | Description |
|---|---|
| **Flexibility** | Each service can use different tech stacks |
| **Reliability** | Failure of one service doesn't bring down others |
| **Development Speed** | Small codebases → faster dev cycles |
| **Dynamic Scalability** | Scale individual services independently |
| **Continuous Deployment** | Update and redeploy only affected service |
| **Technology Independence** | Adopt new technologies incrementally |

#### Principles of Microservices

1. **Single Responsibility Principle** – Each service does one thing
2. **Modelled around business domain** – Aligned with bounded contexts (DDD)
3. **Isolate Failure** – Failures don't cascade
4. **Infrastructure Automation** – Scripted environments, CI/CD
5. **Deploy Independently** – Platform-agnostic deployment

#### Limitations of Microservices

- **Building:** Upfront effort to identify dependencies
- **Testing:** Integration and end-to-end testing becomes complex
- **Versioning:** Breaking backward compatibility is risky
- **Deployment:** Requires automation; complex rollout ordering
- **Logging:** Distributed log management needed
- **Monitoring:** Centralized view required for troubleshooting
- **Debugging:** Remote debugging not easy
- **Connectivity:** Service discovery must be managed

---

### Microservices vs Monolithic vs SOA

| Aspect | Monolithic | SOA | Microservices |
|---|---|---|---|
| Architecture | Single unit | Shared services | Independent services |
| Communication | Internal calls | ESB (Enterprise Service Bus) | HTTP/REST, lightweight |
| Data | Single DB | Shared DB common | Each service owns its DB |
| Deployment | Deploy whole app | Deploy service groups | Deploy individual services |
| Governance | Centralized | Centralized + standards | Decentralized |
| Scalability | Whole app scales | Service groups scale | Per-service scaling |
| Focus | Code reuse | Business reuse | Decoupling + bounded context |

---

## 10. Migrating Monolithic Applications to Microservices

### Why Migrate?

- Scalability, Cost reduction, Integration, Access, Security
- Cloud-native applications take full advantage of cloud features

### The 6R Migration Framework

| Strategy | Description |
|---|---|
| **Re-host** (Lift & Shift) | Move to cloud without changes; fastest but least cloud-native |
| **Re-platform** (Lift-Tinker-Shift) | Minor optimizations (e.g., managed DB); keep basic architecture |
| **Re-architect** | Fully redesign to microservices/cloud-native; highest ROI |
| **Re-purchase** | Move to a SaaS product (e.g., migrate CRM to Salesforce) |
| **Retire** | Decommission applications no longer in use |
| **Retain** | Keep critical applications on-premises for now |

### Re-architecting Approaches

- Monolithic → SOA
- Monolithic → Microservices (**cloud-native**)
- SOA → Microservices

> **Microservice architecture is considered "cloud-native"** — it is designed to fully exploit cloud benefits.

---

## 11. Microservice Transactions: Saga Pattern

### The Problem

- In microservices, each service has its own database
- A single business transaction (e.g., place order) may span multiple services
- **ACID transactions across microservices are not feasible** without a distributed coordinator (2PC — complex and slow)

### Saga Pattern

> A **Saga** is a sequence of **local transactions**. Each service publishes an event or message after completing its local transaction, triggering the next local transaction in the chain. If a step fails, **compensating transactions** are executed to undo previous steps.

#### Types of Sagas

**Choreography-based Saga**

- Each service listens for events and publishes events in response
- No central coordinator
- Decentralized; services are more independent
- Con: Hard to track overall state; can cause circular dependencies

```
Order Service → [OrderCreated Event] → Payment Service
                                      → [PaymentProcessed Event] → Inventory Service
```

**Orchestration-based Saga**

- A central **Saga Orchestrator** tells each service what to do and when
- Easier to track and manage
- Con: Orchestrator becomes a point of coupling

```
         ┌─ Saga Orchestrator ─┐
         │                     │
  Order Service        Payment Service        Inventory Service
```

#### Compensating Transactions

- If payment fails after order is created → **Cancel Order** (compensating transaction)
- These are domain-specific rollback actions
- Unlike DB rollback — compensating transactions don't undo at the DB level; they create new corrective records

#### Saga vs 2PC

| Feature | 2-Phase Commit (2PC) | Saga |
|---|---|---|
| Coupling | Tightly coupled | Loosely coupled |
| Availability | Low (blocking) | High (non-blocking) |
| Consistency | Strong/ACID | Eventual |
| Failure Handling | Rollback | Compensating transactions |
| Scalability | Poor | Good |
| Suitable for | Traditional distributed DBs | Microservices |

---

## Summary Diagram

```
Cloud Service Models:
  IaaS → VM-level access; user manages OS+
  PaaS → Platform-level; user manages code+data
  SaaS → Full service; user just uses

Cloud Deployment Models:
  Public → Shared, hosted by provider
  Private → Dedicated for one org
  Hybrid → Mix of both
  Multi-Cloud → Multiple providers

Programming Models:
  REST APIs → Stateless resource-based HTTP APIs
  Pub/Sub → Event-driven async messaging
  Microservices → Independent, domain-driven services
    └── Saga Pattern → Distributed transactions without 2PC
```

---

## Key Terms

| Term | Definition |
|---|---|
| IaaS | Infrastructure as a Service |
| PaaS | Platform as a Service |
| SaaS | Software as a Service |
| REST | REpresentational State Transfer – architectural style for APIs |
| Stateless | No server-side session state; each request is self-contained |
| Microservice | Small, independently deployable service around one business function |
| Saga | Pattern for distributed transactions using local transactions + compensating actions |
| Pub/Sub | Messaging pattern with publishers sending to topics, subscribers receiving |
| Lift & Shift | Re-hosting migration strategy with no code changes |
| API Gateway | Entry point that routes client requests to appropriate microservices |
| SOA | Service Oriented Architecture – predecessor to microservices |
| Cloud Bursting | Extending private cloud to public cloud when capacity is exceeded |

---

*References: T1 – Hwang, Dongarra, Fox. "Distributed and Cloud Computing." | T2 – Kleppmann, "Designing Data-Intensive Applications."*
