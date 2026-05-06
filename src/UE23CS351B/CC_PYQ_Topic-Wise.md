# Cloud Computing — Master PYQ Bank (Topic-Wise)

**Course:** UE23CS351B / UE21CS351B / UE20CS351 / UE19CS352 / UE18CS352 / UE17CS352

**University:** PES University, Bengaluru

**Sources:** 21 ESA Question Papers (2013 – 2024)

> Questions are deduplicated, merged where near-identical, and tagged with marks and paper source.

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

**Q1.1** List and explain the Features/Characteristics of Cloud Computing. *(6M — May 2023 UE17CS352)*

**Q1.2** Explain any five characteristics of Cloud Computing. *(5M — May 2023 UE18CS352)*

**Q1.3** Explain the following terms with respect to Cloud Computing:

(a) Elasticity (b) Rapid provisioning (c) Measured Service (d) Resource Pooling *(4M — May/Dec 2023, July 2023 — multiple papers)*

**Q1.4** Explain the following terms with respect to Cloud Computing:

(1) On-demand service (2) Rapid provisioning (3) Measured Service (4) Resource Pooling (5) Availability (6) Broad Network Access *(6M — July 2023 UE20CS351)*

**Q1.5** List and explain the benefits of moving applications to the cloud. *(4M — multiple papers)*

**Q1.6** What is Cloud Computing? Define any 4 features. Mention any 4 advantages. *(10M — Dec 2021 UE18CS521)*

**Q1.7** What are Data Centers? Mention 4 types. Explain any 4 challenges in Data Centres. *(10M — Dec 2021 UE18CS521)*

**Q1.8** Discuss the most common technology challenges that occur in cloud computing. *(8M — Jan-May 2024 UE20CS351)*

**Q1.9** Explain any 4 key design considerations used to build a cloud-ready application for private or public clouds. Also explain how Elasticity plays an important role. *(8M — Dec 2023 UE20CS351)*

**Q1.10** Explain in detail Cloud Architecture with a diagram. *(8M — May 2023 UE18CS352)*

---

<a name="2"></a>

## 2. Service Models — IaaS, PaaS, SaaS

---

**Q2.1** Describe with the help of examples the various service models and deployment models of cloud computing. *(7–8M — multiple papers)*

**Q2.2** Describe briefly 3 service models and 3 deployment models of cloud computing. *(6M — multiple papers)*

**Q2.3** List and explain briefly the relative merits and demerits of SaaS, IaaS and PaaS models of cloud deployment. *(6M — May 2023 UE19CS352)*

**Q2.4** Discuss the three cloud service models with suitable examples. *(5M — Jan-May 2024 UE21CS351B)*

**Q2.5** Classify the following into IaaS, PaaS and SaaS models with proper justification:

(1) AWS EC2 (2) Google App Engine (3) Office 360 (4) AWS RDS (5) Shopify (6) AWS S3 *(6M — July 2023 UE19CS352)*

**Q2.6** Three applications are developed on the cloud:

- App1 is accessed using a browser on the cloud
- App2 is installed on a virtual machine
- App3 is built using a cloud-based database service
Classify them into IaaS, PaaS and SaaS with justification. Give a real-life example of each. *(5M — Dec 2020)*

**Q2.7** Mention any 6 differences between IaaS and PaaS. *(10M — Dec 2021 UE18CS521)*

**Q2.8** What are the 3 main types of Storages used in OpenStack? Highlight key differences. Explain your choice of storage for: (1) Databases (2) Unstructured data like music/video (3) Large Data Sets (4) RAID Volumes. *(— Dec 2021 UE17CS352)*

---

<a name="3"></a>

## 3. Deployment Models — Public, Private, Hybrid

---

**Q3.1** Explain the different deployment models of cloud computing. Give a real-time usage scenario for each. *(7M — July 2023 UE17CS352)*

**Q3.2** What are private, public, and hybrid clouds? Explain each. Discuss the relative advantages and disadvantages. *(10M — July 2023 UE20CS351)*

**Q3.3** Discuss the relative advantages and disadvantages of private and public clouds. *(6M — multiple papers)*

**Q3.4** Compare and contrast private and public clouds clearly describing the advantages and disadvantages provided by each. *(6M — Dec 2023 UE20CS351)*

**Q3.5** Discuss the relative advantages and disadvantages of private and public clouds. Mention tools/technologies that illustrate private and public cloud features. *(10M — Jan-May 2024 UE21CS351B)*

**Q3.6** "Private cloud does not need to address the challenge of elasticity" — State whether this is True/False and justify. *(Part of Q3.5 — Jan-May 2024 UE21CS351B)*

---

<a name="4"></a>

## 4. Scalability, Elasticity and Parallelism

---

**Q4.1** What is elasticity? How is it different from scalability? Give an example each to clearly distinguish these concepts. *(4–6M — multiple papers)*

**Q4.2** How is scalability different from elasticity in the cloud? What type of scalability is present in cloud? Discuss the type you chose. *(10M — Jan-May 2024 UE21CS351B)*

**Q4.3** What is meant by elasticity in cloud computing? Suggest two simple techniques to handle elasticity. *(5M — Dec 2020)*

**Q4.4** What is Cloud Scalability? Mention any 4 benefits of Cloud Scalability. *(— Dec 2021 UE18CS521)*

**Q4.5** Explain different degrees of parallelism with an example each. *(6M — multiple papers)*

**Q4.6** Explain briefly Bit-Level parallelism, Instruction-Level parallelism and Task-Level parallelism. *(6M — Dec 2023 UE20CS351)*

**Q4.7** What is the difference between scale-up and scale-out? Which strategy will you use when the number of users increases to ~100 and you are unable to handle requests on the current machine, and why? *(5M — Dec 2020)*

**Q4.8** To implement a scalability solution, identify the type of database scaling for the following scenarios:

A. (i) Buy a bigger car but don't use existing one (ii) Buy another car and use both

B. (iii) Upgrade existing system (iv) Buy a new system with same specs  *(— Dec 2021 UE17CS352)*

**Q4.9** Compute the number of minutes a system must be available in a year if it is designed for 0.99998 availability. *(5M — Dec 2020)*

---

<a name="5"></a>

## 5. Cloud Application Architecture & Design

---

**Q5.1** If you are required to build a Cloud-Ready Application, how will you go about designing and building a cloud application architecture for private or public clouds? Explain 5 key steps. *(— Dec 2021 UE17CS352/UE18CS352)*

**Q5.2** Enumerate the steps required for starting a VM in an IaaS platform. *(5M — Dec 2020)*

**Q5.3** You have initially built an IaaS-based solution T20PremierLeague deployed on a single Linux VM on AWS. As more requests come in, you need to add additional VMs. Draw an architectural diagram of your scalable solution demonstrating connection between the client and the VMs and any new component(s) needed for multiple VMs. *(— May 2019 UE16CS352)*

**Q5.4** You build a PaaS-based solution T20PremierLeague. Draw an architecture diagram showing which APIs require backend (WorkerRole) and what requires front-end processing (WebRole). How will web and worker roles communicate? *(— May 2019 UE16CS352)*

**Q5.5** With more customers wanting to use this software, you decide to move your solution to a SaaS-based solution. What additional design changes do you need to make in terms of API and GUI? *(— May 2019 UE16CS352)*

**Q5.6** Briefly explain the major concepts of REST (any 3) with an example. *(5M — Dec 2020)*

---

<a name="6"></a>

## 6. REST, SOA and Microservices

---

**Q6.1** List and explain the REST architectural style with four principles. *(6M — May 2023 UE17CS352)*

**Q6.2** What is the difference between SOA and microservices? What are REST APIs? What role do they play in implementing SOA/microservices? *(4M — May 2023 UE19CS352)*

**Q6.3** What are the differences between monolithic and microservices applications? What are the challenges associated with migrating monolithic operations? *(6M — July 2023 UE19CS352)*

**Q6.4** What is a microservice application and how is it different from a regular monolithic application? How is REST related to the microservice programming model? Discuss REST in brief. *(10M — Jan-May 2024 UE21CS351B)*

**Q6.5** What is a microservice application and how is it different from a regular monolithic application? *(— Dec 2020)*

**Q6.6** Discuss the challenges with a Microservices Architecture. *(5M — Oct 2024 UE23CS644BB1)*

**Q6.7** Explain the pub/sub model: explain the four core concepts and different purposes for which it can be used. *(6M — Jan-May 2024 UE20CS351)*

**Q6.8** Let's say you are designing a network application. List the REST operations for:

(i) Get all devices (ii) Create a new device (iii) Update the device ID of the existing device. *(— Dec 2021 UE17CS352/UE18CS352)*

**Q6.9** Discuss REST API Versioning Strategies — any three ways. *(6M — Oct 2024 UE23CS644BB1)*

**Q6.10** What is a Service Mesh and what are its main features? *(6M — Oct 2024 UE23CS644BB1)*

**Q6.11** Explain any four principles of Cloud-Native Architecture. *(8M — Oct 2024 UE23CS644BB1)*

---

<a name="7"></a>

## 7. Serverless Computing

---

**Q7.1** What is serverless computing? List the advantages of serverless computing. Give a real-world cloud service that employs serverless computing. *(4M — May 2023 UE19CS352)*

**Q7.2** What is serverless computing? Give one example. What are the benefits? *(4M — July 2023 UE19CS352)*

**Q7.3** What is Serverless Computing and what makes it attractive? *(6M — Oct 2024 UE23CS644BB1)*

**Q7.4** Explain Serverless Architecture with a block diagram. Indicate which type of serverless system (among 8 common types) is used for each of:

- Run code on-demand or on-schedule
- Queuing service
- Real-time processing of data packages
- Two systems communicating with REST API  *(8M — Oct 2024 UE23CS644BB1)*

**Q7.5** Explain with a diagram how AWS Lambda works for Stream Processing. *(6M — Oct 2024 UE23CS644BB1)*

**Q7.6** What is a State machine and how is it used with Step Functions? *(5M — Oct 2024 UE23CS644BB1)*

---

<a name="8"></a>

## 8. DevOps and CI/CD

---

**Q8.1** Why is DevOps needed? How is DevOps different from traditional software development and operations processes? *(6M — multiple papers)*

**Q8.2** What is DevOps? What are the benefits? How is it different from traditional software development? *(4M — July 2023 UE20CS351)*

**Q8.3** Explain any four techniques that make DevOps a successful methodology to develop and deliver software. *(— multiple papers)*

**Q8.4** Explain what CI/CD pipelines are and the benefits they bring in a microservices context. *(— general)*

---

<a name="9"></a>

## 9. Hypervisors and Virtualization Types

---

**Q9.1** Explain Type 2 Hypervisor (Hosted Hypervisor). *(6M — May 2023 UE17CS352)*

**Q9.2** What is the difference between a hosted hypervisor and a bare-metal hypervisor? Give an example of each. *(4–5M — multiple papers)*

**Q9.3** Explain in detail Bare Metal virtualization and Host-based virtualization with a diagram. *(10M — May 2023 UE18CS352)*

**Q9.4** Highlight the key differences between Type 1 Hypervisor and Type 2 Hypervisor. *(6M — Jan-May 2024 UE20CS351)*

**Q9.5** Discuss different types of hypervisors. Give an example of each. How are paravirtualization and full virtualization techniques used to virtualize x86? *(10M — Jan-May 2024 UE21CS351B)*

**Q9.6** How are paravirtualization and full virtualization techniques used to virtualize x86? *(5M — multiple papers)*

**Q9.7** Consider a situation where you are required to apply the appropriate virtualization type for each requirement. Justify your answer:

(i) Run dedicated apps on VMs created on guest OS while other apps run on host OS directly → **Type 2 / Hosted**

(ii) Run special APIs requiring substantial OS modifications in a VM → **Para-virtualization**

(iii) Non-critical instructions run on hardware directly; critical instructions are discovered and replaced with traps into VMM → **Full Virtualization / Binary Translation**

(iv) Install virtualization software directly on hardware → **Type 1 / Bare Metal**

*(8M — multiple papers: Dec 2021, Dec 2023, July 2023)*

**Q9.8** What is Virtualization? Explain Type 1 and Type 2 Virtual Machines diagrammatically. Compare them based on scalability, speed, performance, security. *(10M — Dec 2021 UE18CS521)*

**Q9.9** Is x86 architecture virtualizable? Explain your answer. *(4M — Aug 2013)*

**Q9.10** Explain how Xen I/O virtualization is an example of paravirtualization. What is dom0? *(6M — Aug 2013)*

**Q9.11** Name two sources of overhead in processor virtualization and how these are avoided by Intel VT-x. *(6M — Aug 2013)*

**Q9.12** What is the difference between Paravirtualization and Transparent (Full) Virtualization? Give an example of each. *(— May 2019 UE16CS352)*

---

<a name="10"></a>

## 10. Popek-Goldberg & Sensitive Instructions

---

**Q10.1** State the 3 Theorems of Popek and Goldberg. What are control-sensitive instructions and behaviour-sensitive instructions? Give examples. *(10M — Dec 2021 UE18CS521)*

**Q10.2** Consider an architecture which supports the following instructions:

| Instruction | User Mode Behaviour | Privilege Mode Behaviour |
|---|---|---|
| `popf` | Generate software/hardware int after moving to privilege mode | Not permitted |
| (I/O instruction) | Will fail but generate no error | Turn off all interrupts before doing I/O |

(i) Mark each instruction as sensitive and whether it is behaviour-sensitive or control-sensitive.

(ii) Based on this data, will you be able to design a trap-and-emulate hypervisor? Justify.

*(— Dec 2021 UE17CS352/UE18CS352)*

**Q10.3** Consider an architecture which supports the following instructions. (i) Mark each instruction as sensitive and if so whether behaviour or control sensitive. (ii) Based on this, will you be able to design a trap-and-emulate hypervisor? Justify. *(10M — Jan-May 2024 UE21CS351B)*

**Q10.4** Explain what are rings. Explain the instruction executions depicted in the privilege ring diagram. *(8M — July 2023 UE20CS351)*

**Q10.5** What does the following diagram of rings represent? Explain what are rings and what the arrows represent. *(5M — Dec 2020)*

---

<a name="11"></a>

## 11. Shadow Page Tables & Extended Page Tables

---

**Q11.1** Explain Shadow Page Table using a neat diagram. What are the challenges usually faced in shadow page tables? *(8M — May 2023 UE17CS352)*

**Q11.2** What are the challenges of shadow page tables in a VMM? How does Nested/Extended Page Table overcome the software overheads of shadow paging? *(6M — Jan-May 2024 UE20CS351)*

**Q11.3** For the T20PremierLeague application with virtual address ranges given below, consider specific addresses. Which are Guest Virtual Addresses and which are Host Virtual Addresses? Show corresponding entries in both the guest page table and the shadow page table. *(— May 2019 UE16CS352)*

**Q11.4** Explain (i) advantages and (ii) disadvantages of UnionFS. *(— Dec 2021 UE18CS352)*

---

<a name="12"></a>

## 12. VM vs Containers — Docker & Namespaces

---

**Q12.1** List any 2 similarities and any 2 differences between a Docker container and a VM. *(4M — multiple papers)*

**Q12.2** List any four differences between a VM and a Container. *(4M — multiple papers)*

**Q12.3** List at least four similarities and differences between Containers and VMs. *(4M — July 2023 UE20CS351)*

**Q12.4** Mention any 8 differences between containers and VMs. *(8M — Dec 2021 UE18CS521)*

**Q12.5** How do you differentiate between containers and Virtual Machines? Mention example tools/technologies for each. *(5M — Jan-May 2024 UE21CS351B)*

**Q12.6** Explain Docker architecture with a neat diagram. *(8M — multiple papers)*

**Q12.7** Explain Docker architecture with a neat diagram (5M). How does a Docker container differ from a VM? (3M). *(8M — Jan-May 2024 UE20CS351)*

**Q12.8** What are namespaces with respect to containers? Explain PID and UTS namespaces in Linux. *(3M — May 2023 UE19CS352)*

**Q12.9** What are namespaces with respect to containers? Give an example of types of namespaces in Linux. *(5M — Dec 2020)*

**Q12.10** Given the following cgroups definition for an nginx application — what does this enforce?

`Group nginx { cpu {cpu.shares = 300;} memory {memory.limit_in_bytes=1g;} }` *(5M — Dec 2020)*

**Q12.11** What does the `cpuset` cgroup allow you to do? *(— May 2019 UE16CS352)*

---

<a name="13"></a>

## 13. Kubernetes Orchestration

---

**Q13.1** What are controller-manager, kubelets and pods in Kubernetes? Explain with a diagram where each of them executes — on master or worker? *(7–8M — multiple papers)*

**Q13.2** Explain Kubernetes architecture with a neat diagram clearly showing all the key components of both master and worker nodes. *(6M — multiple papers)*

**Q13.3** What is Kubernetes? Mention any four features of Kubernetes. *(6M — Dec 2021 UE18CS521)*

**Q13.4** What are scheduler, kubelets and pods in Kubernetes? Explain with a diagram where each executes — on master or worker? *(— Dec 2020)*

**Q13.5** Consider 5–6 microservices for a single application, all inside containers. Explain with a block diagram how you will make sure containers communicate with each other using Orchestration. *(— Dec 2021 UE17CS352)*

---

<a name="14"></a>

## 14. VM Migration — Hot, Cold, Pre-copy, Post-copy

---

**Q14.1** What is the difference between hot migration and cold migration? Explain pre-copy and post-copy techniques of hot migration. *(6M — multiple papers)*

**Q14.2** What is VM Migration? What are the different types? State the difference between them. Explain pre-copy and post-copy techniques. *(7M — July 2023 UE19CS352)*

**Q14.3** Bring out the comparison between hot migration and cold migration. Explain the different copy techniques of hot migration. *(10M — Jan-May 2024 UE21CS351B)*

**Q14.4** Explain Live migration process of a VM from one host to another. *(6M — May 2023 UE17CS352)*

---

<a name="15"></a>

## 15. Distributed Storage — Object, Block, File Storage

---

**Q15.1** Illustrate the working of Amazon Simple Storage Service with respect to object storage. *(6M — July 2023 UE17CS352)*

**Q15.2** Name any two object storage services and two database services. *(4M — May 2023 UE19CS352)*

**Q15.3** What is the difference between ephemeral and persistent disks? For (i) swap space of the OS and (ii) database indexes — which will you use? *(5M — Dec 2020)*

**Q15.4** Given the following OpenStack object name, identify the account, container and object name:

`/v1/pesuacademy/cloudcomputing/slides/unit3/slide4.pptx` *(— Dec 2020)*

**Q15.5** Consider a cloud-based storage for a social media app — User Profile Pictures (10M entries, updated daily, viewed by many) and Transactions (10M entries/day, many updates). What types of data decomposition scheme will you use? *(— Dec 2020)*

**Q15.6** You are asked to design cloud storage for course information, syllabus, slides and notes. Will you use a NoSQL or SQL database? Justify. *(— Dec 2020)*

**Q15.7** Discuss some of the practical implications of the CAP Theorem (in the context of storage choice). *(— Dec 2021 UE17CS352)*

**Q15.8** What is sharding? Explain with an example. How does sharding increase join complexity? *(10M — Aug 2013)*

---

<a name="16"></a>

## 16. Lustre and GlusterFS File Systems

---

**Q16.1** Explain Lustre file system architecture with a neat diagram. *(7–8M — multiple papers)*

**Q16.2** Explain Lustre Architecture with a neat sketch and describe its functioning. How does this differ from Gluster? *(8M — May 2023 UE19CS352)*

**Q16.3** Explain GlusterFS file system architecture with a neat diagram. *(8M — multiple papers)*

**Q16.4** Explain what Gluster and Lustre are. Explain the Gluster architecture. How is it different from Lustre? *(5M — July 2023 UE20CS351)*

**Q16.5** Explain the resource allocation algorithm for storage. *(Part of Q — July 2023 UE17CS352)*

---

<a name="17"></a>

## 17. Consistency Models

---

**Q17.1** Explain the following consistency models:

(a) Strict Consistency (b) Sequential Consistency (c) Causal Consistency (d) Pipelined Random Access Memory (PRAM) Consistency *(8M — May 2023 UE19CS352, July 2023 UE20CS351)*

**Q17.2** What is a consistency model? Explain briefly any 4 types. *(5M — Dec 2023 UE19CS352)*

**Q17.3** Explain Linearizability with the compare-and-set operation. *(Part of Q — May 2023 UE18CS352)*

**Q17.4** What is eventual consistency? How can it be achieved in a cloud system? *(— Aug 2013)*

---

<a name="18"></a>

## 18. CAP Theorem

---

**Q18.1** What does the CAP theorem state? Briefly explain. Explain how you would choose a database for your application based on the CAP theorem. *(8M — multiple papers)*

**Q18.2** Briefly explain CAP theorem (2M). Explain how you would choose a database based on CAP theorem (3M). *(5M — multiple papers)*

**Q18.3** Discuss 3 important properties of the CAP theorem and its practical implications while choosing a database. *(6M — multiple papers)*

**Q18.4** Explain the CAP theorem. *(— Aug 2013)*

**Q18.5** Discuss some of the practical implications of the CAP Theorem. *(— Dec 2021 UE17CS352)*

---

<a name="19"></a>

## 19. Replication — Leader-based, Multi-leader, Leaderless

---

**Q19.1** Explain Leader-based replication technique. *(5M — May 2023 UE18CS352, Dec 2021 UE18CS352)*

**Q19.2** What is replication in a distributed environment? Explain leaderless replication. *(5M — multiple papers)*

**Q19.3** What is replication in distributed systems, why is it needed? What are different types based on number of leaders? Explain each. *(10M — July 2023 UE19CS352)*

**Q19.4** Which of the following statements are True about partitioning by hash key?

1. Many distributed datastores use a hash function to determine partition for a given key
2. A good hash function takes skewed data and makes it uniformly distributed
3. Each partition is assigned a range of hashes rather than a range of keys
*(— Dec 2021 UE18CS352)*

---

<a name="20"></a>

## 20. Partitioning, Sharding and Rebalancing

---

**Q20.1** What is meant by the rebalancing of partitions? What aspects need to be considered while rebalancing is in progress? Explain:

(1) Fixed Number of Partitions

(2) Dynamic Partitioning

(3) Partitioning proportional to the nodes *(10M — July 2023 UE19CS352)*

**Q20.2** What is rebalancing of partitions? Why is it necessary to rebalance partitions? *(2–3M — multiple papers)*

**Q20.3** What is the purpose of rebalancing of partitions? (2M) Explain Dynamic Partitioning and Partitioning proportionally to the nodes (4M). *(6M — multiple papers)*

**Q20.4** Discuss the rebalancing of partitions in cloud storage. Bring out any hash-based partitioning method. Discuss leaderless replication. *(10M — Jan-May 2024 UE21CS351B)*

**Q20.5** Explain Ring Election Algorithm with neat sketches. Clearly state the worst-case scenario and messages required. (6M) What are the changes made in Modified Ring Election Algorithm? (2M) *(8M — Jan-May 2024 UE20CS351, Dec 2023 UE20CS351)*

**Q20.6** How is consistent hashing used in partitioning? *(— general)*

---

<a name="21"></a>

## 21. Request Routing

---

**Q21.1** Explain all 4 types of request routing with a diagram. *(12M — May 2023 UE17CS352)*

---

<a name="22"></a>

## 22. Transactions, 2PC and ACID

---

**Q22.1** Explain the Two-Phase Commit Protocol. *(— general, covered in ESA PDF slides)*

**Q22.2** As compared to HTTP, how does reliable messaging solve the problems of (i) recipient crashing (ii) recipient changing (iii) recovery from recipient crashing? *(— May 2019 UE16CS352)*

---

<a name="23"></a>

## 23. Multitenancy and Multitenant Databases

---

**Q23.1** Explain different types of multitenant architecture for a database. *(6M — July 2023 UE17CS352)*

**Q23.2** What is multi-tenancy in a cloud system? *(— Aug 2013)*

**Q23.3** What is multi-tenancy and mention its benefits in Cloud Computing. *(2M — Dec 2023 UE19CS352)*

**Q23.4** Mention any 4 advantages and 2 disadvantages of Multitenancy. *(6M — Dec 2021 UE18CS521)*

**Q23.5** How do you design a multitenant database with name-value pairs? Explain with example table entries. *(6M — Dec 2023 UE18CS352)*

**Q23.6** Design a multitenant database using the **pre-allocated column method** for two **universities** — ModernUniv and SuperUniv. ModernUniv wants USN, names, email ids; SuperUniv wants USN, names, grades. *(— Dec 2020)*

**Q23.7** Design a multitenant database using the **pre-allocated column method** for two **universities** — HighTechUniv and GlobalUniv. HighTechUniv stores USN, names, email ids; GlobalUniv stores USN, names, grades. *(6M — Dec 2023 UE19CS352)*

**Q23.8** Design a multitenant database using the **pre-allocated column method** for two **hospitals** — BestCare and PatientFriendly. BestCare stores PatientID, names, previous history; PatientFriendly stores PatientID, names, NextAppointment. *(5M — Jan-May 2024 UE21CS351B)*

**Q23.9** Two leagues — CollegeLeague and BollywoodPremierLeague want to deploy T20PremierLeague. CollegeLeague associates college of every player; BollywoodPremierLeague adds latest released movie. Explain: (i) how this is done using the pre-allocated column method (ii) how BollywoodPremierLeague can query total amount collected per team (iii) how the query is translated by the SaaS system. *(6M — May 2019 UE16CS352)*

**Q23.10** In a SaaS system, it is desired to allow users to add their own columns (e.g., type of expense: clothes, business expense). How can this be done while keeping a common database table for all users? *(16M — Aug 2013)*

**Q23.11** What is the difference between tenants and users in a cloud system? *(2M — Aug 2013)*

---

<a name="24"></a>

## 24. Leader Election Algorithms

---

**Q24.1** What is the purpose of Leader Election in Distributed Computing? Explain briefly the Bully Algorithm and Modified Ring election. *(10M — multiple papers)*

**Q24.2** What is the purpose of Leader Election in Distributed computing? Explain the Ring Election Algorithm. What are the problems? Discuss time complexity and worst-case scenario. *(10M — May 2023 UE20CS351)*

**Q24.3** Explain Ring Election Algorithm with neat sketches. Clearly state the worst-case scenario and messages required in the worst case. (6M) What changes are made in Modified Ring Election Algorithm? (2M) *(8M — multiple papers)*

**Q24.4** Analyse the best-case scenario and the worst-case scenario of the Bully Algorithm. *(6M — Jan-May 2024 UE20CS351)*

**Q24.5** Which are the three major leader election algorithms in cloud systems? Discuss the relative merits and demerits of the Ring Algorithm along with details on message latencies. *(— Jan-May 2024 UE21CS351B)*

**Q24.6** What is the purpose of Leader Election? Explain briefly Bully Algorithm and Leader Election in a Ring. *(8M — Dec 2023 UE19CS352, Dec 2021 UE17CS352)*

**Q24.7** Briefly explain leader election in a ring. *(5M — Dec 2020)*

**Q24.8** Practice problem: In the given system, Process 7 fails and Process 3 initiates the election. After Process 3 announces Process 6 as the new leader, Process 6 also fails. Show the flow of events. *(— general)*

---

<a name="25"></a>

## 25. Distributed Locking and Fencing

---

**Q25.1** What is the problem with the implementation of a distributed lock in the given diagram? Explain with a diagram the approach used to overcome the problem (fencing tokens). *(6M — Dec 2023 UE18CS352, Dec 2023 UE19CS352, Dec 2023 UE20CS351)*

---

<a name="26"></a>

## 26. Apache ZooKeeper

---

**Q26.1** Explain how ZooKeeper works. Explain the key benefits and common services offered by ZooKeeper. *(10M — July 2023 UE20CS351)*

**Q26.2** What is ZooKeeper? How does it work? Name at least two contexts where ZooKeeper services may be used. *(6M — Jan-May 2024 UE20CS351, Dec 2023 UE20CS351)*

**Q26.3** How does ZooKeeper work? What are the common services offered by ZooKeeper? *(6M — Dec 2023 UE18CS352, Dec 2023 UE19CS352)*

**Q26.4** Explain the key benefits of ZooKeeper. What are the common services offered by ZooKeeper? *(8M — Dec 2021 UE17CS352)*

**Q26.5** Explain how ZooKeeper works (5M). Explain the key benefits of ZooKeeper and the common services offered (5M). *(10M — Dec 2021 UE18CS352)*

---

<a name="27"></a>

## 27. Fault Tolerance — MTBF, MTTR, Fault Models

---

**Q27.1** What is a "fault-tolerant" system? Name at least two types of failures. If a service was unavailable for **30 minutes** in 75 hours due to **9 failures**, compute the MTBF and MTTR. *(5M — July 2023 UE19CS352)*

**Q27.2** What is a "fault-tolerant" system? Name at least two types of faults. If a service was unavailable for **60 minutes** in 75 hours due to **6 failures**, compute MTBF and MTTR. *(— May 2023 UE20CS351, Dec 2023 UE20CS351)*

**Q27.3** Explain the following: EDoS attack, Heartbeat and Probing, Failover Strategy, Types of faults. *(— May 2023 UE19CS352)*

**Q27.4** Explain any four techniques that make distributed systems fault tolerant (retries, timeouts, circuit breakers, etc.). *(— general)*

**Q27.5** In a cloud system, how will you protect against (i) hard drive failure (ii) loss of a PC connected to cloud? *(— Dec 2020)*

---

<a name="28"></a>

## 28. Resource Management and Scheduling

---

**Q28.1** Explain resource allocation algorithm for storage. *(Part of Q — July 2023 UE17CS352)*

**Q28.2** What are soft and hard constraints in a resource scheduler like Nova? Give examples of both. *(— Dec 2020)*

**Q28.3** Explain how Nova allocates VMs. *(— general, covered in slides)*

**Q28.4** Explain the Distributed System model with an example. *(Part of Q — July 2023 UE17CS352)*

---

<a name="29"></a>

## 29. Scalability Strategies, Cloud Bursting and Hybrid Cloud

---

**Q29.1** What is Cloud Bursting? Explain how Cloud Bursting can be beneficial to cloud users. *(6M — Dec 2023 UE18CS352, Dec 2023 UE19CS352)*

**Q29.2** Write a note on Load Balancer and its operation with a diagram. *(10M — Dec 2021 UE18CS521)*

**Q29.3** You have a web application with two components. F is the front end; B is a database backend. Explain how you would use Web roles and Worker roles to implement this. *(— Aug 2013)*

---

<a name="30"></a>

## 30. Reverse Proxy

---

**Q30.1** What is a reverse proxy and what are its benefits? How is it different from a forward proxy? Provide applications where both are used. *(6M — Dec 2023 UE20CS351)*

---

<a name="31"></a>

## 31. Cloud Security — DoS, DDoS, EDoS

---

**Q31.1** Explain the following from a cloud security perspective:

(1) Cloud Time Service (2) Identity Management (3) Access Management (4) Break-Glass Procedures (5) Key Management *(— Dec 2021 UE18CS352/UE17CS352)*

**Q31.2** Explain the following Cloud Security Requirements: Cloud Time Service, Identity Management, Access Management, Break-Glass Procedures, Key Management. *(— Dec 2021 UE18CS521)*

**Q31.3** Explain the following terms from a cloud security perspective. *(5M — July 2023 UE20CS351)*

**Q31.4** What is a DoS attack? Explain with appropriate sketches how DoS is different from DDoS. Distinguish EDoS from the above. *(6M — Dec 2023 UE20CS351)*

**Q31.5** Explain EDoS attack. How is EDoS different from DDoS? *(Part of Q — May 2023 UE19CS352)*

**Q31.6** List and explain 3 security measures that can be used to protect cloud storage. *(— May 2019 UE16CS352)*

---

<a name="32"></a>

## 32. Authentication in Cloud — Keystone

---

**Q32.1** Explain the following Keystone concepts (2M each): Roles, Assignment, Targets, Tokens, Catalog. *(10M — Dec 2021 UE18CS352)*

**Q32.2** What is Identity service in Keystone? Explain the following Keystone concepts in one or two sentences: Project, Domain, Users and User Groups, Roles, Assignment, Tokens, Catalog. *(— Dec 2021 UE18CS521)*

**Q32.3** Explain the following terms from Cloud Threat and Security Context (2M each):

(1) Domain in Keystone (2) Token in Keystone (3) DoS Attack (4) Honeypot Design Pattern *(8M — Dec 2023 UE18CS352)*

**Q32.4** Explain the following terms used in Cloud Security: Domain in Keystone, Defense in Depth, Honeypot Design Pattern, Network Pattern. *(8M — Dec 2023 UE20CS351)*

**Q32.5** What is Keystone? *(— Dec 2021 UE18CS521)*

---

<a name="33"></a>

## 33. Security Design Patterns

---

**Q33.1** Explain the following types of design patterns:

(1) CMDB (2) Defense in Depth *(— Jan-May 2024 UE20CS351)*

**Q33.2** Explain the following types of design pattern:

(1) Defense in Depth (2) Honeypots (3) Sandboxes (4) Network Patterns *(8M — Dec 2023 UE19CS352)*

**Q33.3** Explain the following terms used in Cloud Security: Domain in Keystone, Defense in Depth, Honeypot Design Pattern, Network Pattern. *(8M — Dec 2023 UE20CS351)*

**Q33.4** Explain any four principles of Cloud-Native Architecture. *(8M — Oct 2024 UE23CS644BB1)*

---

<a name="34"></a>

## 34. Miscellaneous / Advanced and Older Topics

---

**Q34.1** Would you use Windows Azure if you wanted to port a legacy application written in Cobol to the cloud? Explain your answer. *(3M — Aug 2013)*

**Q34.2** Physical nodes in an Azure cloud are divided into (i) clusters (ii) fault domains (iii) upgrade domains. Explain each. *(3M — Aug 2013)*

**Q34.3** Suppose you want to use Azure Table Service to store users and music they own (userid, album id, album name). How can this be stored using partition keys and row keys? *(4M — Aug 2013)*

**Q34.4** Name two reasons for the use of server virtualization in modern data centers. *(4M — Aug 2013)*

**Q34.5** In the Siddhartha Reddy video, he talks about 6 different causes of Partitions. One of them is Garbage Collection. How can Garbage Collection lead to partitions? *(— May 2019 UE16CS352)*

**Q34.6** What does the `cpuset` cgroup allow you to do? *(— May 2019 UE16CS352)*

**Q34.7** Consider a chat system with P1-P6 chat nodes and C1, C2 users. One node is a coordinator. (1) What are the types of node failures? (2) How would you recover from them? *(— May 2019 UE16CS352)*

**Q34.8** Draw an example of a client-server chat system. Is the system described a peer-to-peer chat system? Name one chat function simpler in client-server than in peer-to-peer. *(— May 2019 UE16CS352)*

**Q34.9** You need to ensure that Server1 can provide iSCSI storage for Server2 and Server3. What should you do on Server1? *(— Dec 2021 UE17CS352)*

**Q34.10** What is genuinely unique and disruptive about Cinder in the cloud space? If responsible for capacity planning for volume block storage in OpenStack, what will be your approach? *(— Dec 2021 UE17CS352)*

---

## High-Frequency Topics Summary

> Based on occurrence across all 21 papers — these topics appear in **3 or more papers** and are very likely exam material.

| Rank | Topic | Appearances |
|---|---|---|
| ⭐⭐⭐ | Hypervisors (Type 1/2, Bare Metal/Hosted) | 12+ |
| ⭐⭐⭐ | Virtualization types + scenario Q (Full/Para/BM/Hosted) | 10+ |
| ⭐⭐⭐ | VM Migration (Hot/Cold, Pre-copy/Post-copy) | 9+ |
| ⭐⭐⭐ | Leader Election (Ring + Bully Algorithm) | 10+ |
| ⭐⭐⭐ | ZooKeeper | 8+ |
| ⭐⭐⭐ | CAP Theorem + database selection | 10+ |
| ⭐⭐⭐ | Cloud characteristics / features | 8+ |
| ⭐⭐⭐ | Service models + deployment models | 10+ |
| ⭐⭐⭐ | Elasticity vs Scalability | 9+ |
| ⭐⭐⭐ | Kubernetes (controller-manager, kubelets, pods) | 7+ |
| ⭐⭐⭐ | Replication (Leader-based + Leaderless) | 8+ |
| ⭐⭐⭐ | Partitioning / Rebalancing | 8+ |
| ⭐⭐⭐ | Lustre FS architecture | 7+ |
| ⭐⭐⭐ | GlusterFS architecture | 6+ |
| ⭐⭐⭐ | Docker architecture vs VM | 7+ |
| ⭐⭐⭐ | MTBF / MTTR numerical problems | 5+ |
| ⭐⭐⭐ | Distributed Locking / Fencing Tokens | 4+ |
| ⭐⭐⭐ | Multitenancy + pre-allocated column DB design | 6+ |
| ⭐⭐⭐ | Shadow Page Tables / Extended Page Tables | 5+ |
| ⭐⭐⭐ | DoS / DDoS / EDoS attacks | 5+ |
| ⭐⭐⭐ | Keystone Authentication | 5+ |
| ⭐⭐⭐ | Consistency Models (Strict, Sequential, Causal, PRAM) | 5+ |
| ⭐⭐ | Serverless Computing | 4+ |
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

*Compiled from: PYQP (1)–(21), covering ESA papers from Aug 2013, May 2019, Dec 2020, Dec 2021, May 2023, July 2023, Dec 2023, Jan-May 2024, Oct 2024.*
