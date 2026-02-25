# Unit 1: Cloud Programming Models

## 1. Evolution of Computing Paradigms

### Parallel Computing

- **Definition**: A single system containing multiple processors that execute multiple, smaller calculations simultaneously to solve a complex problem.
- **Degrees of Parallelism**:
    - **Bit Level Parallelism**: Based on increasing processor word size; an 8-bit processor requires multiple instructions for 16-bit operations, whereas a 16-bit processor can do it in one.
    - **Instruction Level Parallelism (ILP)**: Re-ordering and grouping instructions for concurrent execution without affecting the program result, often utilizing pipelining.
    - **Task Level Parallelism**: Different processors executing different tasks on the same or different data.
    - **Data Parallelism**: Concurrent execution of the same task on multiple computing cores across different data segments (e.g., splitting array summation between two cores).
- **Coupling Models**: Processors can be **tightly coupled** (shared centralized memory) or **loosely coupled** (distributed memory), communicating via shared variables or message passing.

### Grid Computing

- **Definition**: Coordinated resource sharing and problem-solving in dynamic, multi-institutional **Virtual Organizations (VO)**.
- **Key Differences from Clusters**: Unlike clusters, grid nodes often perform different tasks, are **geographically dispersed**, and are heterogeneous (different OS/Hardware).
- **Types of Grids**:
    - **Computational Grid**: Provides dependable, pervasive, and inexpensive access to high-end computational capabilities.
    - **Data Grid**: Deals with the controlled sharing and management of large-scale datasets.

### Distributed Systems vs. Cloud

- **Distributed Systems**: Multiple autonomous computers with private memory communicating via message passing through HTTP, RPC, or message queues.
- **High Throughput Computing (HTC)**: Focuses on the ability to handle large amounts of computing over months or years, as opposed to **High Performance Computing (HPC)** which processes data at high speeds for short bursts.
- **Cloud Evolution**: Cloud computing delivers internet-scale resources on-demand, applying both parallel and distributed computing over centralized or distributed data centers.

---

## 2. Cloud Service and Deployment Models

### Cloud Service Models (The SPI Stack)

1. **Infrastructure as a Service (IaaS)**:
    - Abstracts physical hardware (servers, disks, networks) into virtual resources.
    - **Management**: The provider manages the physical data center, networking, and virtualization; the **user is responsible for the OS, runtime, and application**.
    - **Providers**: Amazon EC2, Azure VMs, Google Compute Engine.
2. **Platform as a Service (PaaS)**:
    - Provides a complete development and deployment environment, including middleware, database management, and development tools.
    - **Management**: The provider manages everything up to the runtime; the **user only manages application code and data**.
    - **Examples**: AWS Elastic Beanstalk, Google App Engine, and **Google Colab** (which uses an interactive Jupyter notebook format for prototyping).
3. **Software as a Service (SaaS)**:
    - Delivers applications over the internet via a browser (thin client), removing the need for local installation or hardware management.
    - **Management**: The provider manages the entire stack; the **user is only responsible for usage**.
    - **Differentiator**: Business logic is frequently implemented as **microservices** on the backend.

### Cloud Deployment Models

- **Public Cloud**: Resources are available to the general public over the internet via a pay-per-use model.
- **Private Cloud**: A proprietary environment dedicated to a single business entity, offering higher control and security.
- **Hybrid Cloud**: Combines public and private clouds, typically using the private cloud for critical activities and the public cloud for non-critical scaling.
- **Community Cloud**: Shared by multiple organizations with common concerns (e.g., compliance or security).
- **Multi-Cloud**: Utilizing services from multiple providers (AWS, Azure, GCP) to avoid vendor lock-in and optimize costs.

---

## 3. Technology Challenges and Design Objectives

### Cloud Design Objectives

- **Efficiency**: Measured by resource utilization (parallelism in HPC) or job throughput and power efficiency (in HTC).
- **Dependability**: Ensuring reliability and self-management with **QoS assurance** even during failures.
- **Adaptation**: The ability to support billions of job requests across massive data sets.

### Technical Challenges

- **Scalability**: Handling high traffic while maintaining response times (e.g., Facebook adds ~1TB of data daily).
- **Elasticity**: The dynamic allocation of resources; failures to scale quickly impact either QoS (if under-provisioned) or Cost (if over-provisioned).
- **Availability & Failure Detection**:
    - **Heartbeats**: Application instances periodically signal a monitoring service; silence triggers a failure declaration.
    - **Probes**: The monitoring service sends lightweight requests; failure to respond confirms a crash.
- **Security**: Concerns involve third-party data processing, location unawareness, and confidentiality violations.
- **Interoperability & Portability**: The difficulty in migrating applications between different cloud providers due to unique standard languages and APIs.

---

## 4. Web Services and REST Architecture

### Service Oriented Architecture (SOA)

- A methodology to make software components reusable via service interfaces that use common communication standards.
- Services are **loosely coupled**, meaning they can be called with little knowledge of the underlying implementation.

### REST (Representational State Transfer)

REST is an architectural style for networked applications based on specific mandatory constraints:

1. **Client-Server**: Separation of concerns allows clients and servers to evolve independently.
2. **Stateless**: No client context is stored on the server; every request must contain all necessary information.
3. **Cacheable**: Responses must be marked as cacheable to improve network efficiency.
4. **Uniform Interface**: Provides a generic interface to interact with resources via **URIs**.
5. **Layered System**: Clients cannot see beyond the immediate layer (e.g., if they are talking to a proxy or a load balancer).

### REST Operations (HTTP Verbs)

- **GET**: Retrieves a resource; it is **Safe** (does not modify resources) and **Idempotent** (multiple calls have the same effect).
- **PUT**: Creates or replaces a resource; it is **Idempotent** but not safe.
- **POST**: Creates or partially updates a resource; it is **neither safe nor idempotent**.
- **DELETE**: Removes a resource; it is **Idempotent**.

---

## 5. Communication and Messaging Models

### Interaction Styles

- **Synchronous**: Source system blocks (waits) for an immediate response from the target; usually involves timeouts to prevent resource wastage.
- **Asynchronous**: Client does not block; supports high data flow and handles intermittent downtime through failure isolation.

### Messaging Patterns

- **Message Queues**: Lightweight buffers storing requests temporarily; producers add messages and consumers retrieve them.
- **Publish-Subscribe (Pub-Sub)**:
    - **Publisher**: Sends messages to a **Topic** without knowing the subscribers.
    - **Subscriber**: Registers with a topic to receive messages.
    - **Benefits**: Eliminates the need for polling and allows dynamic targeting.

### Comparison: RabbitMQ vs. Kafka

|Aspect|RabbitMQ|Apache Kafka|
|:--|:--|:--|
|**Primary Use**|Task-based communication|Distributed event-streaming|
|**Architecture**|Logically centralized broker|Distributed cluster of brokers|
|**Throughput**|Moderate|Very High|
|**Message Lifetime**|Short-lived|Long-lived (persistent)|
|**Replay Data**|No|Yes|

---

## 6. Monolithic vs. Microservices

### Application Architectures

- **Monolithic**: Features are in a **single codebase** with a **single database**; simple to develop initially but difficult to scale or change.
- **Microservices**: A suite of small, independent services communicating via lightweight mechanisms (REST); each has its own logic and database.

### Migration Strategies (The 6Rs)

Enterprises use these frameworks to move to the cloud:

1. **Re-host**: "Lift-and-shift" to the cloud with minimal changes; quick but lacks cloud nativity.
2. **Re-platform**: "Lift-tinker-and-shift"; slight optimizations like moving to a managed database (e.g., Amazon RDS).
3. **Re-architecting**: Extensive modification of the codebase to be cloud-native (e.g., Monolith to Microservices).
4. **Re-purchase**: Moving to a SaaS model (e.g., CRM to Salesforce).
5. **Retire**: Removing non-essential features post-migration.
6. **Retain**: Keeping critical features exactly as they are.

### Challenges in Database Decomposition

Moving from one monolithic database to a "database per service" requires addressing:

- **Reference Tables**: Solved by using **Data as an API** or **Replication/Projections**.
- **Shared Mutable Data**: Domain realities shared for convenience must be modeled into separate services.
- **Shared Tables**: Tables catering to multiple modules must be split into individual entities within a specific **bounded context**.

### Distributed Transactions: Saga Pattern

- **Problem**: Microservices cannot use traditional ACID locks across multiple databases.
- **Solution**: **Saga Transactions** use a sequence of local transactions; if one fails, **compensating transactions** are executed to undo the preceding steps.