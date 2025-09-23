# Unit 2 - Software Project Management and Software Architecture, Design and Quality

## Project Setup and Daily Practices

### Tools setup continued, Version control and git

Software Configuration Management (SCM) best practices are crucial for improving reliability. Version control must be used for all changes.

A critical finding from the CrowdStrike incident was the absence of an enforced branching strategy and semantic versioning. To avoid this, organizations should:

- **Enforce SCM Best Practices**, including adopting **semantic versioning** and maintaining separate release branches.
- Configuration updates should be managed with the same rigor as code changes.
- Conduct **Code Reviews** for all changes.

**Common Anti-Patterns** in version control that lead to technical debt include:

- Everyone committing directly to the main branch.
- Maintaining **long-lived feature branches**.
- Submitting **huge Pull Requests (PRs)**.

### Project standup meetings

Project standup meetings, typically referred to as **Daily Standups** in the Scrum methodology, are frequent, short meetings designed to coordinate team efforts.

- **Duration and Frequency:** Daily, lasting 15 minutes.
- **Purpose:** Team members address three key questions:
    1. What did I accomplish yesterday?
    2. What am I planning to work on today?
    3. Are there any **blockers** that are preventing me from making progress?

## Software Project Management

### Project management: Introduction, PM Role, Quality of Project, lifecycle, Agile PM

#### Introduction to Project Management (PM)

A **project** is a temporary effort to create value through a unique product, service, or result. All projects have a defined beginning and end, a team, a budget, a schedule, and a set of expectations to meet. **Project management** is the application of specific knowledge, skills, tools, and techniques to deliver value. **Software project management** is the sub-discipline concerned with the art and science of planning, leading, monitoring, and controlling software projects.

#### The Project Manager (PM) Role

The PM is the **linchpin** responsible for keeping all moving parts in sync. The PM ensures the project stays on track, meets its objectives, and delivers value to stakeholders.

The PM fulfills several roles:

- **Leader:** Leads the team toward success, provides direction, explains the roles of each member, and builds a team with diverse skills.
- **Liaison:** Acts as a link between clients, the team, and supervisors, coordinating and transferring information, and monitoring project progress.
- **Mentor:** Guides the team, provides advice, and ensures team cohesion.

#### Quality of Project (The Triple Constraints)

The main objective of project management is to achieve project goals while keeping in mind the balance between **scope, time, quality, and cost**.

- The relationship between these factors is visualized by the **project management triangle** (or **triple constraints**).
- No single variable (scope, cost, time) can be changed without requiring **trade-offs** with the other two points of the triangle to maintain a high-quality final product.

#### Project Lifecycle

A project goes through several stages:

1. **Initiation:** Defining the project and obtaining necessary approvals.
2. **Planning:** Mapping out how goals will be achieved.
3. **Execution:** The real work happens, and plans are brought to life.
4. **Monitoring and Control:** Progress is tracked, and necessary adjustments are made.
5. **Closure:** Tying up loose ends and reflecting on success.

#### Agile Project Management (Agile PM)

Agile methods are iterative approaches where software is developed and delivered in increments. Unlike plan-driven approaches, functionality is not planned fully upfront but is decided during development, depending on progress and customer priorities.

Agile Planning is typically divided into two levels:

1. **Release Planning:** Looks ahead for several months and decides on features for a system release.
2. **Iteration Planning:** Shorter-term, focusing on planning the next increment, typically 2-4 weeks of work.

**Story-based Planning:** The **Planning Game** (developed in XP) uses **user stories** to measure progress. Stories are ranked based on implementation time and assigned **'effort points'**. Measuring the implemented effort points per day gives the team's **'velocity,'** which is used to estimate the total effort required for the system.

### Time estimation, scheduling

#### Estimation Approaches (WBS and CoCoMo)

A **Work Breakdown Structure (WBS)** is a description of the work that will be performed for a project.

**CoCoMo (Constructive Cost Model)** is a regression model based on Lines of Code (LoC) used to reliably predict parameters like size, effort, cost, time, and quality. Key outputs include:

- **Effort:** The labor required, measured in person-months.
- **Schedule:** The time required for completion, proportional to effort, measured in weeks or months.

CoCoMo categorizes projects based on complexity and experience required:

- **Organic:** Small team, problem well understood, nominal team experience (e.g., Inventory Management system).
- **Semi-detached:** Characteristics fall between organic and embedded (e.g., developing an OS or DBMS).
- **Embedded:** Highest complexity, large team, highly experienced developers required (e.g., software for an ATM).

#### Project Scheduling

Scheduling distributes the estimated effort across the planned project duration by allocating effort to specific tasks.

- A high-level **macroscopic schedule** (major activities) is refined into a **detailed schedule** (specific tasks/actions) as the project progresses.
- **Basic Principles** include: Compartmentalization, Interdependency, Time allocation, Effort validation, Defined responsibilities, Defined outcomes, and Defined milestones.

### Risk management

**Risk management** involves identifying risks and creating plans to minimize their negative effect on a project. It is essential due to the inherent uncertainties in software development, such as loosely defined requirements, changes in customer needs, and difficulties in estimating resources.

#### Risk Classification

Risks are classified by what they affect:

- **Project risks:** Affect the project schedule or resources (e.g., staff turnover, hardware unavailability).
- **Product risks:** Affect the quality or performance of the software (e.g., requirements change, size underestimate).
- **Business risks:** Affect the organization developing or procuring the software (e.g., technology change, product competition).

#### The Risk Management Process

The process consists of four main activities:

1. **Risk Identification:** Identify project, product, and business risks.
2. **Risk Analysis:** Assess the likelihood and consequences of these risks.
3. **Risk Planning:** Draw up plans to avoid or minimize the effects of the risk.
4. **Risk Monitoring:** Monitor the risks throughout the project.

### Project monitoring and control

**Project Monitoring and Control** involves observing project execution to identify potential problems early and take necessary corrective action. Control activities adjust dimensions like time, cost, organizational structure, and scope.

Key activities include:

- Monitoring and controlling work, collecting performance information, and assessing trends.
- Periodically performing **Critical Path Analysis**.
- Ensuring change controls are meticulously followed.
- Controlling the **Quality triangle** (scope, cost, quality).

### Gantt chart

A **Gantt chart** is a visual tool used in project management to show activities (tasks or events) displayed against time.

- Activities are listed on the left, and time is displayed along the top scale.
- Each activity is a bar reflecting its start date, duration, and end date, showing overlaps and the start/end date of the whole project.

**Critical Path:** The "critical path" refers to the longest sequence of dependent or floating tasks that must be completed for the project to finish on time. Activities with zero total slack time are on this path.

### Teamwork

Most software engineering is a **group activity** because non-trivial projects cannot be completed by one person.

- **Group Cohesiveness:** In a cohesive group, members value the group above any individual. Advantages include: development of group quality standards, knowledge sharing, maintenance of continuity if a member leaves, and the encouragement of refactoring and continual improvement through collective effort.
- **Team Effectiveness:** Depends on:
    1. **The people in the group:** Needs a mix of people suited for diverse activities (negotiating, programming, testing).
    2. **The group organization:** Structured so individuals contribute to the best of their abilities.
    3. **Technical and managerial communications:** Good communication within the team and with stakeholders is essential.
- **Task Allocation:** During iteration planning, developers break stories into tasks (ideally taking **4–16 hours**) and **sign up for specific tasks**. This gives them ownership and motivation.

## Software Architecture, Design and Quality

### Software Architecture: Views and abstraction, Case study, Motivation and need for SW architecture, Architecture and Design, design pattern

#### Abstraction and Views

**Software Architecture** is the **top-level decomposition** of the system into major components and characterizes how these components interact.

- It is described from many different **views**.
- **Abstracted views** focus on conveying specific information by showing only necessary details and abstracting away unnecessary details, often using legends/annotations.

**Levels of Abstraction**:

1. **Requirements:** High-level “what” needs to be done.
2. **Architecture (High-level Design):** High-level “how,” mid-level “what”.
3. **Design (Low-level Design):** Mid-level “how,” low-level “what”.
4. **Code:** Low-level “how”.

#### Motivation and Need for SW Architecture

Architecture is crucial because it:

- Facilitates internal and external communication.
- Serves as a **blueprint** for the system and project.
- Is used for negotiation and balancing **functional and quality goals**.
- Constrains implementation and relates to organizational structure.
- **Permits or precludes achieving non-functional requirements**.
- Helps to control complexity and manage change.

#### Architecture vs. Design

Architecture deals with high-level structure and coordination, while design deals with detailed implementation.

- **Architectural Questions** often ask _How to extend the app with a plugin?_ or _What threads exist and how do they coordinate?_.
- **Design Questions** often ask _How do I add a menu item?_ or _What lock protects this data?_.

#### Case Study: Therac-25

The Therac-25, a computer-controlled radiation therapy machine, caused multiple injuries and deaths due to architectural failures.

- **Architectural Failures:** Included **tight coupling** (UI, control logic, and machine control shared global memory), **race conditions** (unsafe state transitions when operators acted quickly), and reliance on **reused legacy code** that assumed physical safety interlocks (which had been removed in the Therac-25).
- **Violations:** The design lacked separation of concerns, defensive programming, and redundancy, ignoring safety-critical coding standards.

### Architecture and Design, design pattern, Common SW Architecture types

An **Architectural Pattern** is a general, reusable solution to a commonly occurring problem in software architecture. An **Architectural Style** is a specific method of construction defining a family of systems in terms of structural organization.

#### Common Software Architecture Types

- **Pipes and Filters Architecture:** Data flows sequentially through processing components (**filters**) connected by **pipes**. Filters must compute local transformations and must not share state.
- **Object-Oriented Organization:** System organized as interacting objects with state and behavior, promoting encapsulation and code reuse.
- **Event-Driven Architecture:** Components communicate via events (e.g., publish/subscribe), suitable for asynchronous and reactive systems, promoting loose coupling.
- **Blackboard Architecture:** Multiple subsystems interact via a common knowledge base (the blackboard), requiring a control component to manage interactions.
- **Layered Systems Architecture:** System organized into hierarchical layers, where each layer interacts only with adjacent layers, making individual layers easy to swap or upgrade.
- **Client-Server Architecture:** System divided into clients (send requests) and servers (process and respond), providing centralized control.
- **Model View Controller (MVC):** Divides a system into **Model** (app data and core functionality), **View** (presents data/user interface), and **Controller** (handles control flow/mediates).

#### Architectural Principles (High Cohesion and Loose Coupling)

- **Cohesion:** Measures how closely the operations in a module are related. **High cohesion** means a component has a clear purpose, strong internal relationships, and good abstraction. **Functional cohesion** (all elements contribute to one single function) is the strongest type.
- **Coupling:** Measures the level of interconnection between components. **Loose coupling** is desirable because it makes components easier to work with independently (development, testing, debugging).

### Agile architecture

In Extreme Programming (XP), the core practice of **Simple Design** means avoiding complex or big architecture/designs upfront. Instead, the design is allowed to **emerge and evolve** over a period of iterations. Code is frequently refactored to remain maintainable and free of technical debt. XP teams may conduct a small proof-of-concept called a **spike** to gauge complexity and validate hypotheses before committing to an estimate.

### Security architecture

Security architecture embeds security principles into architectural decisions to mitigate design-level vulnerabilities.

- **Key Goals:** Reduce attack surface, ensure separation of concerns, support **defense-in-depth** strategies, and align with threat models.
- **Techniques:** Use Security by Design Patterns (e.g., input validation layers, secure communication using TLS/mTLS). The system should be divided into subsystems and **trust boundaries** defined. Components within the same trust boundary are considered mutually trusted.
- **Review Checkpoints:** Architects should verify that sensitive components are isolated, APIs are authenticated/rate-limited/validated, encryption is used (data in transit/rest), and default configurations are secure.

### Microservices

**Microservices** are a set of services that act together to make a whole application operate, using APIs to pass information.

#### Motivation

Reasons to transition from a monolithic application include:

- Faster deployment and ability to update certain components more frequently.
- The need for different scale requirements or different technologies for certain components.
- The codebase becoming too big and complex.
- Better scalability and alignment with organizational structure.

#### Migration Patterns

1. **Strangler Pattern:** New services are implemented as microservices. A facade or gateway routes user requests to the correct application, gradually replacing the monolithic application until it is "strangled" and retired.
2. **Anticorruption Layer (ACL) Pattern:** Used when new services need to access the legacy application. The ACL acts as an adapter, translating concepts from the existing app to the new service (and vice versa) so that the new systems are not "corrupted" by concepts from the old domain.

#### Challenges

Microservices introduce complexity, including:

- **Increased Operational Complexity:** Managing and deploying multiple independent services.
- **Inter-Service Communication:** Ensuring reliable communication (e.g., handling timeouts; improper retries can cause a "retry storm").
- **Data Consistency and Integrity:** Managing transactions across distributed services (e.g., using the Saga pattern with compensating transactions).
- **Testing and Debugging:** End-to-end testing becomes complex due to service dependencies.
- **Versioning and Backward Compatibility:** Difficult management of breaking changes across services, even with versioned APIs.
- **Security and Compliance:** Securing communication and enforcing compliance standards (like HIPAA) across numerous services.

### Design techniques, Design flow diagrams

Design involves post-architecture decomposition, description of component behavior, realization of interfaces (algorithms/data structures), and implementation of the user interface.

**Design Techniques:**

- **Abstraction:** Focusing on essential properties.
- **Modularity:** The degree to which a large module can be decomposed.
- **Information Hiding:** Hiding design decisions via **Encapsulation** (hiding data, allowing access only via specific functions) and **Separation of interface and implementation** (defining a public interface separate from realization details).
- **Limiting Complexity:** Complexity (intra-modular or inter-modular) must be limited, as higher complexity means higher effort.

**Design Flow Diagrams:**

- **Data Flow Diagrams (DFD):** Graphical representations that illustrate the flow of data within a system, used during Structured Analysis (logical design).
- **UML Sequence Diagrams:** Part of UML, these diagrams model the interactions between actors and objects in a system. They show the sequence of interactions that occur during a specific use case.

### Modularity at design level - API and ABI development

Modularity is achieved when components are easy to work with independently. **APIs** and **ABIs** are key contracts that enable modularity by defining how components interact and communicate.

#### Application Programming Interface (API)

An API is a **formal contract** specifying how software components interact, defining functions, inputs, outputs, and protocols.

- **Role:** APIs act as boundaries, hiding complexity (encapsulation) and enabling parallel development.
- **API Design Principles:** Must ensure **Clarity** (descriptive names), **Simplicity** (minimal surface area), **Standardized Error Handling**, and a robust **Versioning Strategy** (e.g., semantic versioning).
- **Modularity via APIs:** Achieved through loose coupling (depending on abstract interfaces), high cohesion (grouping related functionality), and information hiding.
- **Synchronous vs. Asynchronous:** Synchronous APIs block the caller until completion (suitable for short, internal operations). Asynchronous APIs allow the caller to continue execution immediately, handling responses later via callbacks or event loops (suitable for high-latency or I/O-bound systems like network APIs).

#### Application Binary Interface (ABI)

An **ABI** defines low-level details—calling conventions, data type sizes, and symbol names—necessary for **independently compiled binaries to interoperate**.

- **Impact:** ABIs cannot change without breaking binary compatibility, forcing client applications to recompile. ABI breakage can cause runtime failures (unresolved symbol errors), memory corruption, and high maintenance burdens.

### Forward and backward compatibility

These concepts are vital for managing system evolution via versioning:

- **Backward Compatibility:** Newer API versions must accept requests from older clients without breaking existing functionality (e.g., keeping default behaviors unchanged or adding optional fields).
- **Forward Compatibility:** Older API versions should be able to ignore unknown fields sent by newer clients.
- **Semantic Versioning (MAJOR.MINOR.PATCH)** guides changes: MAJOR for incompatible changes, MINOR for backwards-compatible additions, and PATCH for bug fixes.

### Error handling and management

**Error handling** is the process of anticipating, detecting, and responding to runtime errors to maintain software stability and security.

- **API Contracts:** Define errors using **Error Codes & Enums** and ensure network/IPC APIs return **structured responses** (e.g., JSON with code/message). All error codes must be documented with meaning and recovery suggestions.
- **Propagation Patterns:** Methods include checking return codes, using **Exception-Based Flow** (in OO languages), or using **Result/Option Types** (in functional languages) that force callers to handle both success and error explicitly.
- **Logging and Observability:** Use **Structured Logging** (JSON or key-value pairs) with severity levels (INFO, WARN, ERROR, FATAL). **Correlation IDs** should be attached to logs for end-to-end tracing across distributed systems.
- **Best Practices:** **Fail Fast** (detect and report errors as early as possible), implement **Graceful Degradation** (degrade functionality rather than crashing), and use **Automated Tests** including negative test cases for error paths.

### Usability engineering

**Usability engineering** is the systematic process of designing and evaluating software interfaces to ensure they are **easy to learn, efficient to use, and satisfying** for the intended users.

- **Motivation:** Failures are often linked to poor usability (e.g., confusing UI layout or easily bypassable error messages, as seen in the Hawaii missile alert or the Therac-25 incident).
- **Testing Approach:** Must involve testing with **actual users** to measure task completion time, correctness, and needed assistance.
    - **Dogfooding** (internal usage of the product by the development team) is used to catch practical issues before release.
    - **Prototyping** (using wireframes, paper prototypes, or Wizard of Oz techniques) helps validate ideas and identify usability issues before heavy investment.
    - **Lab Study** (controlled setting) and **Shadowing** (observing users in their natural environment) are used to gather data.
- **Aspects of Usability (LESEM):** Usability is measured based on **L**earnability, **E**fficiency, **S**atisfaction, **E**rrors, and **M**emorability. Error handling in usability focuses on making it hard to make mistakes (e.g., unambiguous buttons) and ensuring errors are easy to recover from.

### Software Quality

Software quality is essential because bad quality can lead to serious repercussions (especially for life-critical applications) and long-term unprofitability. Everyone involved in the software process is responsible for quality.

- **Quality Perspectives:** Quality can be viewed as **User-Based** (fitness for use) or **Manufacturing based** (conformance to specifications).
- **Software Product Quality Attributes (FLURPS+):** Includes **F**unctionality, **L**ocalization, **U**sability, **R**eliability (frequency of failure), **P**performance (speed, throughput), and **S**upportability (serviceability, maintainability), plus **Extensibility**.
- **Quality Dimensions:** Product quality spans:
    - **Product Operation:** Correctness, Reliability, Efficiency, Usability.
    - **Product Revision:** Maintainability, Testability, Flexibility.
    - **Product Transition:** Portability, Reusability, Interoperability.
- **Cost of Quality (COQ):** Measures resources used to prevent poor quality. It distinguishes between **Cost of Good Quality (COGQ)** (prevention and appraisal costs) and **Cost of Poor Quality (COPQ)** (internal/external failure costs and technical debt).

### Technical debt

**Technical debt** is defined as design or implementation constructs chosen for short-term expediency that make future changes more costly or impossible. It primarily impacts internal qualities like maintainability and evolvability.

- **Causes:** Tightly-coupled components, poorly-specified requirements, business pressure, lack of process/documentation, lack of automated testing, and delayed refactoring.
- **Management:** Requires continuous effort in recognizing, making visible, deciding when/how to resolve, and learning to live with the debt.

### Test driven development

**Test-Driven Development (TDD)** is an approach where testing and code development are interleaved, with tests written **before** the code. Passing the tests drives the development process.

#### TDD Process Activities

1. Identify a small increment of functionality.
2. Write an automated test for this functionality.
3. Run all existing tests (the new test will fail initially).
4. Implement the minimum required functionality.
5. Re-run all tests. Once successful, move to the next increment.

#### Benefits of TDD

- **Code coverage:** Every code segment written has at least one associated test.
- **Regression testing:** A regression test suite is built incrementally.
- **Simplified debugging:** When a test fails, the problem is usually obvious in the newly written code.
- **System documentation:** The tests serve as documentation describing the code's expected behavior.