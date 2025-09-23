# Unit 1 - Introduction to Software Engineering and Requirements Engineering

## Introduction and Context Setting

Software is the driving force behind modern systems, consisting of programs, associated documentation, and configuration data. Complex systems like MRI scanners, ATMs, and Uber rely heavily on software.

A Boeing 787 has 6.5 million lines of code (LOC) for avionics and support systems. Facebook runs on 62 million LOC (minus backend). Downtime can be extremely costly; for instance, a 90-minute outage at Amazon resulted in an estimated **$2.8 million revenue loss** and customer attrition.

To build high-quality software, necessary elements include: interaction with customers, clear understanding of end-users, domain experts, good planning, teamwork, and ability to scale and support.

## What is Software Engineering (SE)

**Engineering** is the application of science and mathematics to solve problems; engineers innovate by applying scientific discoveries to the real world.

**Software** is defined comprehensively as not just the programs, but also the associated documentation and configuration data needed to ensure those programs operate correctly. A **software system** usually consists of multiple separate programs, configuration files, system documentation (describing structure), user documentation (explaining usage), and websites for product information.

**Software Engineering** is defined in two key ways:
1.  The application of a **systematic, disciplined, quantifiable approach** to the development, operation, and maintenance of software, and the study of these approaches.
2.  A **systematic approach** to the analysis, design, assessment, implementation, testing, maintenance, and reengineering of software.

SE principles guide the usage of appropriate tools and techniques based on the problem, while considering available resources and constraints. The focus is on developing and maintaining software that is correct from its inception.

### SE vs. Computer Science (CS)

*   **Computer Science** is the study of computation, automation, and information, spanning theoretical (algorithms) and practical (hardware/software design) disciplines.
*   **Software Engineering** typically deals with the engineering principles required for building, designing, and testing software products.

## Motivation for SE

The term "Software Engineering" first appeared at the **1968 NATO Software Engineering Conference**. It was meant to address the perceived **"Software Crisis,"** which described the difficulty of writing computer programs that were correct, understandable, and verifiable, driven by rapid increases in computer complexity and complexity of problems being tackled.

The crisis manifested in several ways:

*   Projects running **over-budget and over-time**.
*   Software being inefficient and of **low quality**.
*   Software often **did not meet requirements**.
*   Projects were unmanageable, and code was difficult to maintain.
*   Software was never delivered.

Modern statistics show that **only one in three software projects are truly successful**, and 66% of technology projects end in partial or total failure. A project is deemed a failure if the software did not satisfy customer requirements, the release was later than scheduled, or the software had too many bugs.

### Fundamental Drivers of Software Engineering

Key factors driving SE include:

*   **Industrial Strength Software:** Must be operational, maintainable, capable of being moved (portable), have elaborate documentation, have minimal bugs, and be impactful to the business.
*   **Expense:** Good software engineers are expensive, and maintenance and rework cost money.
*   **Criticality:** Life-critical and mission-critical software can influence life or death, or make or break organizations.
*   **Technical Challenges:** Heterogeneity (distributed systems), Security and trust (software should be trustworthy and secure), Diversity (different software systems), and Scale (software should be scalable).
*   **Change:** Need the ability to change existing software and develop new software as organizations become global.
*   **Quality:** Measured by **FLURPS** (Functionality, Localizability, Usability, Reliability, Performance, Security), Portability, and Efficiency/Maintainability.
*   **Consistency and repeatability**.
*   **Late Delivery:** Typically 35% of computer-based projects are runaway.

## Case Study – Crowdstrike

The CrowdStrike incident highlights critical failures in development and release processes.

### Summary of the Incident

On July 18, 2024, CrowdStrike released a routine Falcon software update without adequate testing, embedding a corrupted library that triggered system crashes. The next morning, **over 8.5 million Windows endpoints worldwide abruptly failed**. Critical services were disrupted, including banking, healthcare, airlines, and 911 call centers. **Delta Air Lines canceled over 7,000 flights**, estimating $550 million in losses, with recovery prolonged due to outdated infrastructure. Insurers face an estimated $1.5 billion in cyber-interruption claims.

### What Went Wrong

*   **Inadequate Staging & Testing:** Minimal pre-production validation meant a simple sandbox test could have flagged the buggy library.
*   **Monolithic Update Deployment:** All customers received the update simultaneously, eliminating opportunities for phased rollouts or canary testing.
*   **Poor Change Management:** Absence of a formal Change Control Board (CCB) and impact-analysis workflow.
*   **Over-Reliance on Upstream Vendor:** Relying on a single code library without verifying integrity introduced a single point of failure.
*   **Insufficient Monitoring & Alerting:** Telemetry failed to trigger a rapid rollback when error rates spiked.

### Possible Explanations and How to Avoid

| What Went Wrong | Possible Explanation | How to Avoid/Improve Reliability |
| :--- | :--- | :--- |
| Monolithic Deployment | No canary or blue-green deployment model. | **Implement Phased Rollouts** using feature flags and canary releases. |
| Inadequate Testing | Lack of automated unit/integration tests. Missing “release-readiness” criteria. | **Automate Testing & Rollbacks** (regression, fault-injection, security testing integrated in CI/CD). **Establish “Release-Readiness” Gates** (define clear QA criteria like test coverage). |
| Poor Change Management | Configuration updates treated differently than code changes. | Classify changes based on **risk and impact**, not type. Use a **CCB-driven impact analysis**. **Automated rollback plans** for all changes. |
| Version Control Issues | No branching strategy or semantic versioning enforced. | **Enforce SCM Best Practices** (semantic versioning, separate release branches). |
| Over-reliance on Vendor | No formal risk register for third-party library failures. | **Diversify Dependencies** (mirror critical libraries, verify checksums/signatures). |
| Insufficient Monitoring | Telemetry failed to trigger rapid rollback. | **Strengthen Monitoring & Incident Response** (real-time telemetry with automated alerts). |

## Team Formation and Project Allocation

The organizational context of a project involves the **4 Ps**: **People, Process, Product, and Project Environment**.

### People

People are the backbone of any project. Key roles include:

*   **The Project Team:** Diverse individuals bringing unique skills; they are the builders and problem-solvers.
*   **Stakeholders:** Individuals or groups with a vested interest (sponsors, clients, end-users, vendors). Their needs influence the project goals.
*   **The Project Manager:** The linchpin responsible for planning, coordinating, communicating, and leading the team to ensure objectives are met and value is delivered.

Collaboration, open communication, and leadership are essential for success.

### Task Allocation (Agile context)

During **iteration planning** in Agile methodologies, developers break down user stories into specific **development tasks**.

*   A development task should typically take **4–16 hours**.
*   The individual developers then **sign up for the specific tasks** they will implement.
*   This approach provides the team with an overview of work and gives developers a sense of ownership, motivating them to complete the tasks.

## Software Development Life Cycles (SDLCs)

The SDLC provides a structured model for project conception to delivery. It helps establish order, forces consideration of the "big picture," organizes and coordinates teamwork, and allows for tracking risks and progress.

### Waterfall Model

This is a **top-down, sequential** model where activities are non-overlapping. Each step is signed off and then frozen, typically resulting in a final document.

| Advantages (Waterfall) | Disadvantages (Waterfall) |
| :--- | :--- |
| Simple | Assumes requirements are frozen |
| Clear identified phases | Difficult to change & sequential |
| Easy to manage due to rigidity | Poor model for long projects |
| Each phase has specific deliverables + reviews | Big Bang approach |
| Easy to departmentalize and control | High risk + Uncertainty |

**Usage:** The pure form is best for short projects where requirements are well known, the product definition is stable, technology is understood, or regulatory requirements dictate a sequential approach.

### V Model

Similar in usage to the Waterfall model.

*   **Pro:** Test development activities can happen before the formal testing cycle, increasing success probability and resource effectiveness.
*   **Con:** Similar limitations to Waterfall; no early prototypes, and changing the process requires changing test documentation.

### Iterative vs. Incremental Models

| Iterative Model | Incremental Model |
| :--- | :--- |
| Revisit and refine everything | No need to go back and change delivered things |
| Focus on details of things | Focus on things not implemented yet |
| Leverage on learnings | Does not leverage on experience or knowledge |

### Spiral Model

Proposed by Boehm, it combines waterfall and prototyping, representing the process as a spiral where each loop is a phase. Key activities (Determine objectives, Risk analysis, Develop and test, Plan next delivery) repeat in iterations called spirals. It focuses on phased reduction of risks by addressing high risks early.

*   **Pros:** Allows for changes, provides early indication of unforeseen problems, and risk reduces as costs increase.
*   **Cons:** More complex to run, requires proper risk assessment, and requires more planning and experienced management.

### Limitations of Legacy Lifecycle Models

These methods are often **predictive** and rely on **upfront planning**. They are typically suitable for projects with clear definitions that are not changing too fast. They generally do not facilitate periodic customer interaction.

## Security Development Life Cycle (SecDLC)

The SecDLC incorporates security considerations into every phase of the standard SDLC.

| Phase | Security Activities |
| :--- | :--- |
| **Pre-SDL (Training)** | All members must receive training on Threat Modelling, Secure Coding (e.g., buffer overruns, cross-site scripting), and Privacy. |
| **Phase 1: Requirements** | Identify functional aspects requiring security design reviews or penetration testing. **Perform Threat Modeling and Security Risk Assessment (SRA)** to define product security requirements. |
| **Phase 2: Design** | Design specifications must describe secure implementation, focusing on **Attack Surface Reduction** and **Defense in Depth** (multiple layered defenses). |
| **Phase 3: Implementation** | Publish lists of approved tools. **Prohibit unsafe functions and APIs** (including open source). Perform **Static analysis** of code. |
| **Phase 4: Verification** | Use **Dynamic program analysis** (monitoring memory corruption, privilege issues). Conduct **Fuzz testing** (introducing malformed data). Update threat model and attack surface analysis. |
| **Phase 5: Release** | An **Incident Response Plan** must be in place (contacts, security servicing plans). Conduct a **Final Security Review (FSR)** examining threat models, tool output, and quality gates. |

## Motivation for Agile, Scrum

Agile is an **umbrella term** for methods that encourage continual realignment of development goals with customer needs and expectations. It focuses on **reducing massive planning overhead** to allow fast reactions to change.

Agile is not a process; it is a **set of values or philosophy**. Key characteristics include: **Rapid, Iterative, Cooperative, Quality driven, and Adaptable**.

### Agile Manifesto

Agile values the items on the left more than the items on the right:

*   Individuals and interactions over processes and tools.
*   Working software over comprehensive documentation.
*   Customer collaboration over contract negotiation.
*   Responding to change over following a plan.

### Agile Principles

*   **Customer involvement:** Customers should be closely involved throughout development to prioritize requirements and evaluate system iterations.
*   **Incremental delivery:** Software is developed in increments, with the customer specifying requirements for each increment.
*   **People not process:** Exploit the skills of the team; team members should define their own ways of working without prescriptive processes.
*   **Embrace change:** Expect requirements to change and design the system to accommodate these changes.
*   **Maintain simplicity:** Focus on simplicity in both the software and the development process.

## Advantages/Disadvantages of Agile

**Advantages (Inferred from sources):**
*   **Flexibility and Adaptability:** Prioritizes responding to change over following a plan.
*   **Continuous Value Delivery:** Ensures the team works on features that provide tangible benefits (Valuable principle).
*   **Reduced Complexity:** Focuses on simplicity and small, manageable tasks/stories.
*   **Early Feedback:** Incremental delivery ensures customers can evaluate iterations frequently.

**Disadvantages/Difficulties of Agile Planning:**
*   **Reliance on Customer Availability:** Agile planning is heavily reliant on customer involvement and availability, which can be difficult to arrange if customer representatives have competing priorities.
*   **Cultural Fit:** Some customers may be more familiar with traditional plans and find it difficult to engage in the agile planning process.
*   **Team Size/Distribution:** Works well with small, stable development teams. It is practically impossible when teams are large, geographically distributed, or frequently changing members.
*   **Critical Systems:** Agile methods are problematic for systems that require extensive pre-delivery analysis (e.g., critical systems) or those developed by several teams.

## Details of Agile Methodology

### Scrum

Scrum is a specific agile methodology.

Key Activities:

1.  **Sprint Planning** (30-60 min, biweekly): Decide what features can be delivered (from product backlog) and what tasks are needed to build the sprint backlog.
2.  **Daily Standup** (15 min, daily): Team members share what they accomplished yesterday, what they plan for today, and any blockers.
3.  **Sprint Review** (30-60 min, biweekly): Demo of working software to the product owner.
4.  **Sprint Retrospective** (30-60 min, biweekly): Reflect on successes/failures and identify actions to improve processes and teamwork.

### User Stories (INVEST)

User stories should follow the INVEST guidelines to ensure they are well-structured for planning and delivery:

| Principle | Definition/Importance |
| :--- | :--- |
| **I**ndependent | Minimal dependencies on other stories. Allows flexibility in prioritization and implementation order. |
| **N**egotiable | Starting points for discussion, not contracts. Encourages collaboration and refining requirements. |
| **V**aluable | Must deliver value to stakeholders or end-users, aligning work with business goals. |
| **E**stimable | The team must be able to estimate the effort required. Vague stories need clarification or breakdown. |
| **S**mall | Concise enough to be completed within a single iteration. Promotes continuous progress. |
| **T**estable | Must have clear acceptance criteria to determine completion, ensuring quality and reliability. |

### eXtreme Programming (XP) Core Practices

XP is an agile methodology built on values, principles, and practices:

*   **Planning Game:** Collaboratively decide requirements and features for a release, and break them into tasks for iteration planning.
*   **Simple Design:** Start with a simple design and let it emerge and evolve. Code is frequently refactored. Use a **spike** (small proof-of-concept workout) to gauge complexity.
*   **Test-Driven Development (TDD):** Developers write unit tests *before* coding. This ensures only the code needed to pass the tests is written.
*   **Pair Programming:** Two programmers operate on the same code on the same system, swapping roles as pilot (coding) and navigator (reviewing). This ensures everyone knows the code.
*   **Collective Code Ownership:** Success or failure is a collective effort; any developer can fix any bug.
*   **Continuous Integration:** Integrate changes made every few hours or daily, executing all tests automatically.
*   **Onsite Customer:** Role similar to Product Owner; responsible for vision, user stories, acceptance criteria, and release planning. They sit with the team to ensure free communication.
*   **Sustainable Pace:** People-centric practice involving downtime/slack time during iterations to deal with uncertainties or pay down technical debt (refactoring, research).

## Requirements Engineering: Introduction, Elicitation, Analysis

**Requirements Engineering (RE)** is the science of eliciting, analyzing, documenting, and maintaining requirements. It is the first step in any software development lifecycle.

A **requirement** is a property that must be exhibited by the software. It should specify the externally visible behavior (**what**), not the implementation (**how**).

### Properties of Requirements

Requirements should be **Concise** (describe a single property), **Clear, Unambiguous, Verifiable, and Measurable**. They must also be **Feasible** and **Traceable**.

### RE Process (Four + One Activities)

1.  **Requirements Elicitation**
2.  **Requirements Analysis**
3.  **Requirements Specification (Documentation)**
4.  **Requirements Management**
5.  **Requirements Validation**

### Requirements Elicitation

This is the process of proactively working with stakeholders to gather their needs, articulate their problem, identify conflicts, and establish a clear scope and boundary.

**Elicitation Techniques:**
*   **Active Techniques** (ongoing interaction): Interviews, facilitated meetings, role-playing, prototypes, ethnography, scenarios.
*   **Passive Techniques** (infrequent interaction): Use cases, business process analysis & modeling, workflows, questionnaires, checklists, documentation.

### Requirements Analysis

Involves understanding requirements in depth and managing them:

*   Classify requirements into coherent clusters (Functional, Non-functional, User, System, Domain).
*   Model the requirements.
*   Recognize and resolve conflicts; negotiate requirements.
*   Prioritize using models like **MoSCoW** (Must have, Should have, Could have, Won’t have).
*   Identify risks and decide on build-or-buy (COTS solutions).

## Functional Requirements (FRs)

FRs are **statements of services** the system should provide, describing the functionality, how the system reacts to particular inputs, and how it behaves in specific situations. FRs may also state what the system should **not** do.

*   **Example:** The system must send a confirmation email whenever an order is placed.
*   **Imprecision:** Ambiguous FRs lead to problems because developers and users may interpret them differently.
*   **Completeness and Consistency:** In principle, requirements should be complete (include all facilities) and consistent (no conflicts/contradictions), though complexity makes achieving this perfectly impossible.

## Non-Functional Requirements (NFRs)

NFRs define system **properties and constraints** (e.g., reliability, response time, storage requirements). Process requirements (like mandating a specific programming language or IDE) can also be specified.

NFRs are often **more critical** than functional requirements; if NFRs are not met, the system may be useless. They typically apply to the system as a whole rather than individual features.

### Non-Functional Classifications

*   **Product requirements:** Specify how the delivered product must behave (e.g., execution speed, reliability).
*   **Organizational requirements:** Consequences of organizational policies and procedures (e.g., process standards used).
*   **External requirements:** Factors external to the system and development process (e.g., legislative requirements, interoperability).

### Metrics for NFRs

NFRs should be measurable:

| Property | Measure Examples |
| :--- | :--- |
| Speed | Processed transactions/second, User/event response time. |
| Reliability | Mean time to failure, Probability of unavailability. |
| Ease of use | Training time, Number of help frames. |
| Portability | Percentage of target dependent statements. |

## Security Requirements (SRs)

SRs are part of the non-functional requirements. The requirements phase establishes the security capabilities a system must provide.

### Security Risk Assessment (SRA)

The SRA is a structured process to identify, quantify, and prioritize security risks.

1.  **Identify Assets and Stakeholders:** An asset holds value (tangible or intangible). A stakeholder is anyone who owns an asset.
2.  **Identify Threats and Attackers:** A weakness that may compromise an asset is a potential threat. An attacker is an actor who exploits an existing adversary for gain.
3.  **Risk Categorization:** Risks are analyzed and categorized based on Cost of weakness to be exploited, Probability of weakness to be exploited, and Damage if exploited. This assigns a severity level (Low, Medium, High).

### Security Objectives (SMART)

High-priority risks are translated into measurable objectives using the **SMART** criteria:

*   **S**pecific: Clearly state the outcome (e.g., encrypt all PII in transit).
*   **M**easurable: Define metrics (e.g., 256-bit AES, TLS v1.2+).
*   **A**chievable: Align with team capabilities.
*   **R**elevant: Directly mitigates an identified threat.
*   **T**ime-bound: Milestone defined (e.g., before design review).

Security requirements are clearly articulated based on SRA output, Threat Models, and Security Objectives, ensuring they are clear, testable, and traceable.

## Software Requirements Specification (SRS)

The SRS document is the final documentation of requirements, reviewed and approved by the customer. It serves as the basis for customers and contractors/suppliers agreeing on what the product will and will not do.

The SRS describes both the functional and nonfunctional requirements.

### Key Contents of an SRS

*   **Functionality:** What the software is supposed to do.
*   **External Interfaces:** How the software interacts with people, hardware, and other software.
*   **Non-Functionality:** Quality criteria such as Performance, Availability, and Portability.
*   **Design Constraints imposed on an implementation:** Required standards, implementation language, policies for database integrity, resource limits, security, and operating environment.

## Requirement Traceability Matrix (RTM)

Requirements are traced across the SDLC using the **Requirement Traceability Matrix (RTM)**. Every phase of the SDLC progressively fills the RTM.

**Tracing includes:**
*   **Forward Tracing:** Linking requirements to downstream artifacts.
*   **Backward Tracing:** Linking downstream artifacts back to requirements.

An RTM typically includes columns such as: Req ID, Architectural Section, Design Section, File/Implementation, Unit Test ID, Functional Test ID, System Test ID, and Acceptance Test ID.

## Requirements Change Management

Requirements change due to better problem understanding, customers internalizing the solution, and evolving technology/environment.

Uncontrolled changes can cause a huge adverse impact on the project regarding cost, schedule, quality, and expectations. Therefore, changes must go through a **formal change management process**.

## UML Use Case Diagrams

The **Unified Modeling Language (UML)** is the de-facto standard for building Object-Oriented software, used for visualizing, specifying, constructing, and documenting system artifacts.

A **Use Case Diagram** models the intended behavior of a system, outlining how the proposed system performs a task expected by a role/actor/user.

### Elements of Use Case Modeling

*   **Actors:** One or a set of objects (person, device, or another system) that directly interacts with the system, each having a defined purpose.
*   **Use Case:** A piece of functionality that a system offers to its users. The set of all use cases defines the entire functionality of the system, including error conditions.

### Creating a Use Case Diagram

1.  List main system functions (use cases) and draw ovals around them.
2.  Draw the system boundary.
3.  Draw actors and connect them to use cases.
4.  Specify relationships:
    *   **"Include":** Used when one use case always calls another as part of its behavior (e.g., "Place Order" always includes "Process Payment"). Used for reuse.
    *   **"Extend":** Used when a use case optionally adds behavior to another (e.g., "Make Payment" can be extended by "Apply Discount"). Used for optional or conditional behavior.

## Writing a Use Case

A use case is an example behavior of the system, written from an actor's point of view. It should feature a "main success scenario" (3-9 clear steps) but also describe variation and exception scenarios.

**4 Steps for Writing a Use Case:**
1.  **Identify actors and their goals/trigger**.
2.  **Identify the Main Success Scenario:** This is the preferred "happy path," capturing each actor's intent and responsibility, stating what information passes, and numbering each step.
3.  **List the Variations to the main flow:** Alternate branches from the main path (e.g., options or enhancements the user might expect).
4.  **List the Exceptions (error) flow:** Describe failure-handling for steps that can fail.

When defining alternate flows, it is critical to think about how every step could be enhanced or fail, and provide a plausible system response that either jumps to another step or ends the case. Avoid listing things outside the scope, making unreasonable assumptions, or listing a remedy the system cannot implement.

## Persona and User Scenarios

These techniques are used to specify requirements.

### Personas

A persona is a **fictional yet realistic representation of a user archetype** who might use the system, embodying key characteristics, needs, goals, and pain points of real users.

**Why use Personas?**
They ground the design in real user behavior, help teams empathize with users, and drive user-centered requirements.

### User Scenarios (User Stories)

A user scenario is a **narrative** that describes how a persona might interact with the system in a particular situation.

*   **Structure:** "As a [persona], I want to [goal] so that [benefit]".
*   Scenarios are valuable because they help identify missing flows, UI features, and exception cases.

## Requirements Discovery

Requirements Discovery is the process of gathering information about the required and existing systems and distilling the user and system requirements from stakeholders (managers to external regulators).

### Interviewing

Formal or informal interviews with stakeholders, mixing closed (pre-determined questions) and open (exploring issues) formats.

*   **Effective Interviewing:** Be open-minded, listen, and prompt the interviewee using prototypes or requirements proposals.
*   **Problems:** Not ideal for understanding deep domain requirements because application specialists may use complex language, and some domain knowledge is so familiar it is hard for people to articulate.

### Ethnography

A social scientist spends considerable time **observing and analyzing how people actually work** in their own setting.

*   **Benefits:** People do not have to articulate their work, and social/organizational factors can be observed. Work is often richer and more complex than suggested by simple models.
*   **Example:** Flipkart used ethnographic field observations of delivery drivers to discover real-world challenges (traffic, customer behaviors, driver workarounds) that standard data analytics (GPS tracking) did not explain.

## Testing Intro, Types of Tests

**Software Testing** is the process of examining functionality and behavior through **Verification and Validation (V&V)**.

*   **Verification:** "Are we building the product right?". Checks that software meets specifications. This is **Static Testing** (reviews, inspections), where code is not executed, and bugs are found early in documentation/design.
*   **Validation:** "Are we building the right product?". Checks if the product meets the client's true needs and expectations. This is **Dynamic Testing**, where code is executed.

### Testing Terminology

*   **Error:** A mistake, misconception, or misunderstanding by a software developer (e.g., wrong logic or syntax).
*   **Defect:** A variance between expected and actual results; an error found by a tester.
*   **Bug:** A defect accepted by the development team; a coding error causing the program to malfunction.
*   **Failure:** The inability of the system to perform required functions; occurs when a defect reaches the end customer.
*   **Fault:** An incorrect step, process, or data definition that causes unintended behavior; the result of an error.

### Levels of Testing

1.  **Unit Testing:** Verifies the proper functioning of the individual unit.
2.  **Integration Testing:** Focuses on finding interface errors and bugs not identified during unit testing.
3.  **System Testing:** Assessment of the entire system behavior to discover bugs that cannot be attributed to a single component.
4.  **Acceptance Testing:** Done by system providers/users/customers to determine if the system meets their needs.

## Test Planning

**Software Test Planning** is the process of evolving a test plan that defines **what, when, how much, and how** testing must be done to ensure quality expectations are met. It serves as a blueprint for monitoring and control.

### Test Planning Process Overview

1.  Ensure context and scope are understood.
2.  Establish **test adequacy criteria**.
3.  Evolve a **test strategy**.
4.  Evolving list of deliverables (test specifications, test cases).
5.  Creation of a detailed test schedule.
6.  Planning, identification, and allocation of resources.
7.  Identification of milestones.
8.  **Risk Management**.
9.  Establish measures and metrics.

### Test Adequacy Criteria

This defines **when to stop testing** or consider testing complete for that iteration. Examples include meeting a target percentage of code execution coverage, completing all planned test cases with no critically high-priority issues, or ensuring the total number of severe defects is below a set limit.

### Testing Strategy (Mindsets)

The strategy defines the test approach and includes the testing mindset:

*   **Demonstration:** Focuses on showing the software runs and satisfies specifications.
*   **Preventive:** Prevents faults in early phases through planning and design (e.g., Reviews and TDD).
*   **Destruction:** Tries to make the software fail to find as many faults as possible.
*   **Evaluation:** Detects faults throughout the lifecycle, focusing on analysis and review of documents.

## Security Validation Plan

The Security Validation Plan ensures that security controls and objectives are **measurable, verifiable, and tested** throughout the SDLC. It is critical in the requirements phase as it ensures the testability of security requirements and aligns security teams early.

The plan results in a documented artifact tied to requirements and design.

### Key Elements of a Good Plan

*   **Security Requirements Traceability:** Links which security requirement is being validated.
*   **Validation Objectives:** What must be confirmed (e.g., PII masked, encryption enabled).
*   **Validation Methods:** Which method will be used (Review, penetration test, fuzzing, static analysis) for a specific component/requirement.
*   **Ownership:** Who validates the requirement (QA, security team, external auditor).
*   **Timing:** At which SDLC stage validation will occur.
*   **Tools & Environments:** Specific configurations or tools needed.

## Tools Introductions: git, github, jira-github integration, github action with sonarcloud, tests, build and code review flow

While the sources do not detail specific tool functionality (like git commands or Jira integration), they emphasize the processes and requirements that these tools fulfill:

*   **Version Control (git/github):** It is critical to **use version control for all changes**. Best practices include adopting **semantic versioning** and maintaining separate release branches. Poor practices like everyone committing to the main branch or having long-lived feature branches are considered anti-patterns.
*   **Work Tracking (Jira):** Work items must be tracked, development should be broken into smaller tasks, and all reported bugs must be monitored. **Jira** is a commonly used tool for bug tracking, issue tracking, and project management.
*   **Build/Code Review/Tests (CI/CD, GitHub Actions, SonarCloud):**
    *   **Code Reviews** are essential for improving reliability.
    *   A **DevOps framework** should be employed to push code between developers and operations.
    *   **Continuous Integration (CI)** is a core XP practice where changes are integrated frequently (every few hours/daily), and **all tests are executed automatically**.
    *   Automated security testing should be **integrated into the CI/CD pipeline** throughout the lifecycle.
    *   **Release-Readiness Gates** should enforce clear QA criteria, including performance benchmarks and security scans, before deployment.

