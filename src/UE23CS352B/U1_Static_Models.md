# Unit 1: Advanced OO — Object-Oriented Analysis and Static Models & Diagrams

---

## 1. Requirement Engineering

Requirement Engineering (RE) is typically the first step in any software-intensive development lifecycle, irrespective of model.

### Why RE is Critical

- Usually difficult, error-prone, and costly
- Errors introduced during requirements phase propagate into subsequent phases
- Requirement errors are expensive to fix at a later stage
- Unnecessary, late, or invalid requirements can make the system cumbersome

### Definition

> A process of working proactively with all stakeholders — gathering their needs, articulating their problem, identifying and negotiating potential conflicts, thereby establishing a clear scope and boundary for a project.

### A Requirement is

- A property which must be exhibited by software to solve a particular problem
- Should specify externally visible **what** behavior (not **how**)
- Can be individual requirements or a set of requirements

### Requirement Analysis Process

1. **Understand** requirements in depth — both product and process perspective
2. **Classify and Organize** into coherent clusters:
   - Functional, Non-Functional, and Domain requirements
   - System and User Requirements
3. **Model** the requirements
4. **Analyze** using fishbone diagram if necessary
5. **Recognize and Resolve** conflicts (e.g., functionality vs. cost vs. timeliness)
6. **Negotiate** Requirements
7. **Prioritize** — MoSCoW (Must have, Should have, Could have, Won't have)
8. **Identify Risks**
9. **Decide** on Build or Buy (COTS — Commercial Off-The-Shelf Solution)

---

## 2. What is UML?

**Unified Modeling Language (UML)** — a language to express different types of models.

### UML defines

- **Syntax** — symbols and rules for using them
- **Semantics** — what these symbols represent

### UML can be used to

- **Visualize** — Graphical Notation
- **Specify** — Complete and Unambiguous
- **Construct** — Code Generation
- **Document** — Design, Architecture, etc.

### Conceptual Models of UML

UML is made up of three conceptual elements:

| Element | Description |
|---|---|
| **Building Blocks** | Things (Structural, Behavioral, Grouping, Annotate), Relations (Dependency, Association, Generalization, Realization), Diagrams |
| **Rules** | Name, Scope, Visibility |
| **Common Mechanisms** | Applied throughout UML |

### UML Structural Things (Nouns)

Class, Interface, Active Class, Component, Node

### UML Behavioral Things (Verbs)

Interaction, State Machine, Use Case, Collaboration

### Views of a Solution System

| View | Description |
|---|---|
| **Use Case View** | Describes behavior as seen by end users, analysts, and testers |
| **Design View** | Classes, Interfaces, and Collaborations for the problem and solution |
| **Interaction View** | Flow of control among parts; addresses performance and scalability |
| **Implementation View** | Artifacts used to assemble and release the physical system |
| **Deployment View** | Distribution, delivery, and installation of system parts |

---

## 3. Use Case Modeling

### What is Use Case Modeling?

- Describes the interaction of users and the system
- Describes what functionality a system provides to its users
- Has two important elements: **Actors** and **Use Cases**

### Actor

- Represents a set of roles that users play when interacting with use cases
- Can be human or automated systems
- Triggers a use case; has responsibilities (inputs) and expectations (outputs)
- **Not** a part of the system

### Use Case

- A description of a set of sequences of actions a system performs to yield an observable result of value to an actor
- Name starts with a **verb**
- Set of all use cases defines the entire functionality of the system

### Use Case Diagram

- Incorporates actors, use cases, and their relationships in graphical form
- Used to visualize, specify, construct, and document the intended behavior of the system
- Serves as basis for testing

### Use Case Description Components

| Component | Description |
|---|---|
| Title | Meaningful name |
| Author/Date | Creation info |
| Purpose | Goal to be achieved |
| Actors | Participating agents |
| Pre Conditions | Must be true before execution |
| Post Conditions | Will be set on normal completion |
| Normal flow | Regular flow of activities |
| Alternative flow | Other flow of activities |
| Exceptional flow | Unusual situations |

### Relationships Between Use Cases

**1. Generalization**

- Child use case inherits behavior and meaning of parent
- Child may add to or override parent behavior

```
register student
   ├── register non-graduate student
   └── register graduate student
```

**2. Include (`<<include>>`)**

- Base use case explicitly incorporates another use case at a specified location
- Included use case never stands alone
- Used to avoid describing the same flow of events several times

```
Process Sale ──<<include>>──► Handle Credit Card Payment
```

**3. Extend (`<<extend>>`)**

- Base use case implicitly incorporates behavior at extension points
- Base use case may stand alone; behavior is extended under certain conditions
- Used to model optional behavior or branching under conditions

```
Request Exam Copy ──<<extend>>──► Appeal Exam Grade
```

### How to Create Use Case Diagrams

1. List main system functions (use cases) in a column
2. Draw ovals around the function labels
3. Draw system boundary
4. Draw actors and connect them with use cases
5. Specify include and extend relationships between use cases

### Identifying Use Cases

**Actor-based method:** For each actor, identify the processes they initiate or participate in.

**Event-based method:** Identify external events → relate to actors and use cases.

---

## 4. Class Modeling — UML Class Diagrams

### What is Class Modeling?

- A class model captures the **static structure** of a system
- Characterizes objects, relationships between objects, attributes, and operations
- Supports architectural design; shows structure rather than behavior

### Class

> A description of a set of objects that share the same attributes, operations, relationships, and semantics.

```
ClassName
──────────────
attributes
──────────────
operations
```

### Attributes

- Named properties of a class that describe the object being modeled
- Each attribute has a type: `attributeName : Type`
- **Derived attribute** — computed from others, designated with `/`: `/ age : int`

### Operations (Methods)

- Describe class behavior
- Signature: `methodName(paramName: ParamType): ReturnType`

### Visibility Modifiers

| Symbol | Visibility |
|---|---|
| `+` | Public — any class can use |
| `#` | Protected — any descendant can use |
| `-` | Private — only the class itself |

---

## 5. Approaches for Identifying Classes

### 1. Noun Phrase Approach

- Read the requirements document and identify noun phrases
- Nouns → candidate classes; Verbs → methods
- Divide nouns into: Relevant, Fuzzy, and Irrelevant classes

| Class Type | Description | Action |
|---|---|---|
| Relevant | Core domain concepts with clear responsibilities | Keep in model |
| Fuzzy | Tentative or ambiguous concepts | Review and refine |
| Irrelevant | Outside problem domain or technical/UI | Remove |

### 2. Common Class Patterns Approach (Shlaer and Mellor)

- **Concept Class** — Account, Customer (abstract but used to organize business activities)
- **Event Class** — Transaction, Withdrawal, Deposit (points in time that must be recorded)
- **Organization Class** — Bank, Branch (collection of people, resources, facilities)
- **People Class** — Users, Beneficiaries
- **Place Class** — Buildings, stores, offices
- **Tangible Things / Device Class** — Car, Pressure sensor

### 3. CRC (Class-Responsibility-Collaborators) Cards

- A tool used for brainstorming in OO design and agile methodologies
- Each card represents one class

| Component | Description |
|---|---|
| **Class** | OO class name (including super/sub-class info) |
| **Responsibility** | What information the class stores; what it does |
| **Collaboration** | Relationship to other classes; which other classes it uses |

**CRC Process:**

1. Conduct a session to identify objects involved in the use case
2. Allocate each object to a team member
3. Act out the use case
4. Identify and record missing or redundant objects

---

## 6. OO Relationships in Class Diagrams

### 1. Generalization (Inheritance)

- "Is-a" or "is a kind of" relationship
- Child classes inherit common functionality (attributes and methods)
- Shown as a line with a **hollow triangle arrowhead** pointing to the super class
- UML permits multiple inheritance, though Java does not

```
Vehicle
 ├── Car
 └── Truck
```

### 2. Abstraction

- Abstract class name shown in *italics* or with `{abstract}` stereotype
- Abstract method has no implementation (shown in italics)

### 3. Realization (Interfaces)

- A class guarantees to implement the operations specified in an interface
- Shown as a **dashed directed line** with an open arrowhead pointing to the interface
- `{interface}` stereotype is mentioned before its name

### 4. Dependency

- "One class uses the other"
- A change in one class may affect the dependent class (not necessarily the reverse)
- Often used to show that a method has an object of a class as parameter
- Shown as a **dashed arrow**

### 5. Association

- Two classes need to communicate — there must be a link between them
- Types: **Unidirectional** (one class knows the relationship) and **Bidirectional**

**Multiplicity adornments:**

| Notation | Meaning |
|---|---|
| `1` | Exactly one |
| `0..1` | Zero or one |
| `*` | Zero or more |
| `1..*` | One or more |
| `2..5` | Between 2 and 5 |

**Association can also have:**

- Role names (describe the role played by the class at the opposite end)
- Association names
- Self associations (a class associated with itself)

### 6. Aggregation

- "Has-a" relationship — whole-part relationship
- Part can **exist independently** from the aggregate
- Denoted by a **hollow diamond** adornment on the association

```
Car ◇── Engine
    ◇── Transmission
```

### 7. Composition

- Strong "has-a" relationship — coincident lifetime (parts live and die with the whole)
- Denoted by a **filled diamond** adornment on the association

```
Window ◆── Scrollbar
       ◆── Titlebar
       ◆── Menu
```

> **Key distinction:** If the movie theater goes away, so does the box office (composition) but movies may still exist (aggregation).

### 8. Other Notations

- **Association Class (Link Class)** — An association that is itself an object (connected with a dotted line)
- **Enumeration** — User-defined data type with `<<enumeration>>` stereotype
- **Exception** — Modeled with `<<exception>>` stereotype

---

## 7. Component Diagrams

### What is a Component?

- A replaceable and executable piece of a system whose implementation details are hidden
- Provides a set of interfaces (provided and required)
- A **modular part** of a system that encapsulates its contents
- Similar to a black box — external behavior defined by provided and required interfaces

### Components vs. Nodes

- **Components** — Things that participate in the execution of a system
- **Nodes** — Things that execute components

### Interfaces in Component Diagrams

- **Provided Interface** — The interface implemented by a component
- **Required Interface** — Any use of an interface by a component

| Connection Type | Description |
|---|---|
| Assembly Connector | Connects provided and required interfaces |
| Usage Dependency | `<<use>>` — one element requires another for its full implementation |

### Port

- An interaction point between a classifier and an external environment
- Groups semantically cohesive set of provided and required interfaces
- Public port: drawn over the boundary of the classifier
- Protected/Private port: drawn inside the classifier

### Internal vs. External Views

- **Internal View (White Box)** — Realizing classes/components nested within the component shape
- **External View (Black Box)** — Shows publicly visible properties and operations

### Steps to Draw a Component Diagram

1. Know all components within the system and their working
2. Explore each component — understand connections to other physical artifacts
3. Identify relationships among artifacts, libraries, and files

---

## 8. Deployment Diagrams

### Introduction

- Maps software architecture to the physical system architecture
- Shows how components described in component diagrams are deployed on hardware
- In distributed systems, models the distribution of software across physical nodes

### Deployment Diagram Elements

| Element | Description |
|---|---|
| **Node** | Computational resource upon which component artifacts are deployed for execution |
| **Artifact** | Concrete elements (executable files, libraries, archives, database schemas, configuration files) |
| **Component with Artifacts** | Represents the concrete real-world entity related to software development |
| **Association** | Communication path between nodes |

### Uses of Deployment Diagrams

- Controls performance, scalability, maintainability, portability, and understandability
- Important for visualizing embedded, client/server, and distributed systems
- Managing executable systems through forward and reverse engineering

### Steps to Draw a Deployment Diagram

1. Identify the purpose — identify nodes and devices
2. Figure out the relationships between nodes and devices
3. Identify other elements (components, active objects)
4. Add dependencies between components and objects

---

## 9. Activity Diagrams

### What is an Activity Diagram?

- Visually presents a series of actions or flow of control in a system (similar to a flowchart)
- Often used in business process modeling; can describe steps in a use case
- Activities can be sequential and concurrent; has a beginning (initial state) and an end (final state)

### Activity Diagram Notation

| Symbol | Meaning |
|---|---|
| Filled circle | Initial state / Start |
| Circle inside circle | Final state / End |
| Rounded rectangle | Activity / Action State |
| Arrow | Action Flow (transitions) |
| Diamond | Decision (branching), also Merge |
| Thick bar | Fork (split into concurrent flows) / Join (rejoin concurrent flows) |
| Hourglass | Time Event |
| Lightning bolt arrow | Interrupting Edge |

### Guards

- Boolean conditions written next to a decision diamond that must be true before moving forward

### Swimlanes

- Groups related activities into one column (identifies who is responsible)
- Dotted arrow = Object flow (creation and modification of objects)

### Key Rules

- Use **Decision box (diamond)** when user/system must choose ONE option (Mutual Exclusion)
- Use **Fork (Thick Bar)** when ALL actions must happen in parallel (Concurrency)
- Use **Merge (Diamond)** when flows are mutually exclusive (OR) to proceed
- Use **Join** when ALL parallel activities must finish (AND) to proceed

### Steps to Construct an Activity Diagram

1. Figure out the action steps from the use case
2. Identify the actors involved
3. Find a flow among the activities (identify conditions, branches, parallel actions)
4. Add swimlanes

---

## 10. Sequence Diagrams

### What is a Sequence Diagram?

- A structured representation of behavior as a series of sequential steps over time
- Used to depict workflow, message passing, and cooperation over time
- Captures flow of information and responsibility throughout the system
- Messages between elements eventually become method calls in the class model

### Construction

- **Horizontal Axis** — Objects are arranged horizontally
- **Vertical Axis** — Time flows downward
- **Lifeline** — Dashed stem representing existence of each element

### Notation

| Notation | Description |
|---|---|
| Actor | User of the system (human, machine, or another system) |
| Lifeline | Vertical dashed line representing individual participants |
| Activation Bar | Rectangle on lifeline — indicates the period an object is active |
| Synchronous Message | Solid line with filled arrowhead |
| Asynchronous Message | Solid line with open arrowhead |
| Return Message | Dotted line with open arrowhead |
| Create Message | Solid line with `«create»` stereotype |
| Destroy Message | X-shaped arrowed line |
| Self Message | Loop arrowed line (object sends message to itself) |
| Found Message | Arrowed line with open circle (unknown source) |

### Sequence Fragments (Combined Fragments)

| Operator | Fragment Type |
|---|---|
| `alt` | Alternative — only the fragment whose condition is true executes |
| `opt` | Optional — executes only if condition is true |
| `par` | Parallel — each fragment runs in parallel |
| `loop` | Loop — may execute multiple times |
| `region` | Critical region — only one thread executing at once |
| `neg` | Negative — shows invalid interaction |
| `ref` | Reference — refers to interaction defined on another diagram |
| `sd` | Sequence Diagram — surrounds entire sequence diagram |

### Steps to Construct a Sequence Diagram

1. Identify the Use Case
2. Identify Objects/Participants
3. Draw Lifelines
4. Arrange Lifelines in temporal order
5. Determine the Order of Execution
6. Draw Messages (arrows)
7. Label Messages with method name, parameters, and return values
8. Include Create and Destroy Messages if necessary
9. Add Conditions and Loops (Combined Fragments) if needed

---

## 11. State Diagrams

### What is a State Diagram?

- Used to describe **state-dependent behavior** for an object
- An object responds differently to the same event depending on what state it is in
- The state model is a reductionist view of behaviour that examines each object individually

### State Diagram vs. Flowchart

- A **flowchart** illustrates processes that are executed in the system that change the state of objects
- A **state diagram** shows the actual changes in state, not the processes that created those changes

### State Diagram Notation

| Symbol | Description |
|---|---|
| Filled circle → | Initial state |
| Circle inside circle | Final state |
| Rounded rectangle | State |
| Solid arrow | Transition |
| Thick bar (fork) | Synchronization — split into concurrent transitions |
| Thick bar (join) | Synchronization — concurrent transitions merge |

### Trigger, Guard, and Action

- **Trigger** — An event that initiates a transition from one state to another
- **Guard condition** — A Boolean condition that must be satisfied for a transition to occur
- **Effect/Action** — What happens when a transition occurs

### Types of Events (Triggers)

- **Call Event** — Receipt of a request to invoke an operation
- **Change Event** — A Boolean condition changes from false to true
- **Time Event** — Passage of a defined period or absolute time
- **Signal Event** — A specific message received by an object

### Composite States

- A state that encapsulates a more complex internal structure (nested states)
- Contains substates and transitions, forming a hierarchical structure
- Has entry, do, and exit points

### Orthogonal States

- Multiple independent sets of substates that exist concurrently
- Substates operate independently — don't affect transitions in other regions

---

## 12. Advanced State Modeling

### Problems with Flat State Models

- Conventional state diagrams are sufficient for simple systems
- Large problems need additional power: nested state diagrams, signal generalization, and concurrency

### Features of Advanced State Diagrams

- **Nested State Diagram** — States within states (super/substates)
- **Signal Concurrency** — Handling multiple user and system-generated signals concurrently
- **Aggregation Concurrency** — Objects working together with some shared constraints
- **Concurrency within an Object** — Objects are autonomous; state changes may be independent or interdependent

### Concurrency Types

1. **Aggregation Concurrency** — Multiple objects work together, sharing some constraints on state changes
2. **Concurrency within an object** — An object with parallel regions in its state machine
