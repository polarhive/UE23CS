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

---

# Unit 2: Object-Oriented Programming and Architecture Design

## 1. OO Development Process & Methodology

### What is the OO Development Process?

- The essence is the **identification and organization of application concepts** rather than their final representation in a programming language
- Encourages developers to work and think in terms of the application throughout the software lifecycle
- A conceptual process independent of the programming language until the final stage
- Greatest benefit: helps developers and customers express abstract concepts clearly and communicate them to each other; OO concepts also provide documentation

### OO Methodology

- Emphasizes how to go about developing a system or application
- Facilitates re-use of software components; employs the international standard **UML** from the Object Management Group (OMG)
- Enables component-based development — facilitates effective re-use of existing components
- Key questions asked: What are the objects? What responsibilities and relationships does each object have? How do they behave over time?

### Stages of OO Methodology

| Stage | Description |
|---|---|
| **System Conception** | Business analysis or users conceive an application and formulate tentative requirements |
| **Analysis** | Analyst understands the problem (problem statements are rarely complete or correct). The analysis model is a precise abstraction of **what** the system must do, not **how**. Must figure out the big picture — for whom, what problems, workflow |
| **System Design** | Development team devises a high-level strategy called the **system architecture** for solving the application problem |
| **Class Design** | Class designer adds details to the analysis model in accordance with the system design strategy. Focus on data structures and algorithms needed to implement each class |
| **Implementation** | Translate classes and relationships into programming language, database, or hardware; follow good software engineering practice for traceability and flexibility |

---

## 2. Introduction to Java and OOP

### Java Features

| Feature | Description |
|---|---|
| Simple | No header files, pointer arithmetic, structures, unions, operator overloading |
| Object-Oriented | Data (objects) and interfaces to objects are the focus — 4 pillars: Abstraction, Encapsulation, Inheritance, Polymorphism |
| Distributed | Extensive library for TCP/IP protocols (HTTP, FTP) |
| Robust | Inbuilt exception handling, memory management, strong type-checking at compile-time |
| Secure | Enables virus-free, tamper-free systems |
| Portable | Bytecode runs on any platform with a JVM — WORA (Write Once, Run Anywhere) |
| Interpreted | Bytecode executed by JVM line-by-line |
| High-Performance | JIT (Just-In-Time) compiler translates bytecode to machine code at runtime |
| Multithreaded | Concurrent execution of multiple threads; synchronized methods and blocks |
| Dynamic flexibility | Add classes, new methods, create new classes through sub-classes at runtime |

### Java Platform Editions

- **Java SE** — Standard Edition (desktop/standalone applications)
- **Java EE** — Enterprise Edition (large-scale distributed systems)
- **Java ME** — Micro Edition (embedded/mobile devices)

### JVM, JDK, JRE

| Term | Description |
|---|---|
| **JVM (Java Virtual Machine)** | Platform-dependent environment that converts Java bytecode (.class file) to machine language and executes it |
| **JDK (Java Development Kit)** | Complete development kit — compiler, JRE, debuggers, docs |
| **JRE (Java Runtime Environment)** | Allows Java programs to run (cannot compile) — includes browser, JVM, applet support |

### Java Program Execution

```
Source Code (.java) → Compiler (javac) → Bytecode (.class) → JVM → Machine Code
```

Each OS has a different JVM, but the output of executed bytecode is the same.

### First Java Program

```java
public class Test {
    public static void main(String[] args) {
        System.out.println("My Java First Program");
    }
}
// Save as: Test.java  |  Compile: javac Test.java  |  Run: java Test
```

---

## 3. OOP Core Concepts

### 1. Abstraction

- Representing essential features without including background details
- In Java: achieved using **abstract classes** and **interfaces**; interfaces allow 100% abstraction
- Classes using data abstraction are called **Abstract Data Types (ADT)**

```java
abstract class Animal {
    public abstract void animalSound(); // Abstract method — no body
    public void sleep() { System.out.println("Zzz"); } // Concrete method
}
class Dog extends Animal {
    @Override
    public void animalSound() { System.out.println("The dog says: bow bow"); }
}
```

**Abstract Class rules:**

- Declared with `abstract` keyword; cannot be instantiated
- Can have both abstract and concrete methods
- Must be declared `abstract` if it contains at least one abstract method
- Can have constructors, static methods, and final methods
- **Cannot be declared `final`** — abstract classes are used only by extending
- A class can extend only **one** abstract class

### Abstraction vs Interface — Comparison Table

| Feature | Abstract Class | Interface |
|---|---|---|
| Keyword | `abstract class` | `interface` |
| Object Creation | Cannot create object | Cannot create object |
| Methods | Abstract + concrete methods | Abstract by default; default & static methods from Java 8 |
| Variables | Can have instance variables | Only `public static final` (constants) |
| Constructors | ✅ Allowed | ❌ Not allowed |
| Access Modifiers | Any (private, protected, public) | Methods are public by default |
| Multiple Inheritance | ❌ Not supported (for classes) | ✅ A class can implement multiple interfaces |
| Purpose | Partial abstraction | Full abstraction (possible) |

### 2. Encapsulation

- Wrapping up of data and functions into a single unit (class)
- Data is not accessible to the outside world — only wrapped functions can access it
- This insulation is called **data hiding** or **information hiding**

```java
class Person {
    private String name;                                      // restricted access
    public String getName() { return name; }                  // Getter
    public void setName(String newName) { this.name = newName; } // Setter
}
```

**Advantages:** Data Hiding, Increased Flexibility, Reusability, Easy Unit Testing, Freedom for implementation details

### 3. Composition

- Design technique to implement the **"has-a"** relationship; "Favor Composition over Inheritance"
- The composed object cannot exist without the container

```java
class Engine {
    void start() { System.out.println("Engine started"); }
}
class Car {
    private Engine engine = new Engine(); // Engine created inside Car — strong ownership
    void drive() { engine.start(); System.out.println("Car is moving"); }
}
```

**Benefits:** Code reuse, multiple inheritance via composition, better testability, dynamic runtime behavior changes

---

## 4. Classes and Objects in Java

### Class

- A blueprint or template used to create objects
- Defines what an object will **have** (attributes) and **do** (methods)

```java
class Student {
    int rollNo;       // instance attribute
    String name;      // instance attribute
    void display() {  // method
        System.out.println(rollNo + " " + name);
    }
}
```

### Object

- A real-world entity created from a class; a specific instance occupying memory
- Created with the `new` keyword; accessed via the dot (`.`) operator

**Three characteristics of an object:**

- **Identity** — Unique reference (e.g., `s1`)
- **State** — Values of attributes (e.g., `rollNo`, `name`)
- **Behavior** — Methods it can perform (e.g., `display()`)

```java
Student s1 = new Student(); // Object creation
s1.rollNo = 1;
s1.name = "John";
s1.display();
```

### Access Modifiers

| Modifier | Same Class | Same Package | Subclass (diff pkg) | Everywhere |
|---|---|---|---|---|
| `public` | ✔ | ✔ | ✔ | ✔ |
| `protected` | ✔ | ✔ | ✔ | ✗ |
| `default` | ✔ | ✔ | ✗ | ✗ |
| `private` | ✔ | ✗ | ✗ | ✗ |

---

## 5. Instance vs Static Members

### Method Types

**Instance Methods** — Require an object to be created before calling; by default, all methods are instance methods.

**Static Methods** — Can be called without creating an object; referenced by the class name itself. Cannot use `this` keyword; cannot directly access instance variables.

### Attribute Types

**Instance Variables** — Each object has its own copy; require an object to access.

**Static Variables (Class Variables)** — Shared by all instances; associated with the class, not any object; one fixed location in memory.

| Feature | Static Attribute | Instance Attribute |
|---|---|---|
| Belongs to | Class | Object |
| Copies in memory | One | One per object |
| Accessed using | Class name | Object |
| Value shared | Yes | No |
| `this` keyword | ❌ Not allowed | ✅ Allowed |

| Feature | Static Method | Instance Method |
|---|---|---|
| Belongs to | Class | Object |
| Called using | Class name | Object |
| Object required | ❌ No | ✅ Yes |
| Access instance variables | ❌ No | ✅ Yes |
| Access static variables | ✅ Yes | ✅ Yes |
| `this` keyword | ❌ Not allowed | ✅ Allowed |

### Static Block

- Initializes static data members
- Executed before the main method at the time of **class loading**; executed exactly **once**

```java
class A2 {
    static { System.out.println("static block is invoked"); }
    public static void main(String args[]) { System.out.println("Hello main"); }
}
// Output: static block is invoked
//         Hello main
```

---

## 6. Parameter Passing

### Types of Parameters

- **Formal Parameter** — the parameter in the method definition
- **Actual Parameter** — the argument passed when calling the method

### Pass by Value (Value Types / Primitives)

- A **copy** of the value is passed to the formal parameter
- Changes made to the formal parameter do **not** get transmitted back to the caller
- Java's primitive types (`int`, `double`, `boolean`, etc.) are passed by value

```java
void f1(int x, int y) { x = 40; y = 50; } // Changes do NOT affect caller
```

### Pass by Reference (Reference Types / Non-Primitives)

- Non-primitive type variables store **references** (memory addresses) to objects on the heap
- Changes to the **object's data** are reflected back to the caller
- Reassigning the reference variable itself does **not** affect the caller's variable

```java
class A {
    int x;
    void f1(A obj) { obj.x = 20; } // Changes obj.x — IS reflected in caller
}
```

**Reference vs Object:**

| Term | Meaning |
|---|---|
| Object | Actual data in heap memory |
| Reference | Memory address of the object |
| Variable | Stores the reference value |

```
Student s = new Student();
(variable s on stack) ──► (reference) ──► Student object (on heap)
```

**Trick 1:** If we reassign the reference variable inside a method to a new object, changes are NOT reflected back.

**Trick 2:** If we modify the object's fields (without reassigning the reference), changes ARE reflected back.

---

## 7. Constructors and Garbage Collection

### Constructors in Java

- Initializes an object when it is created
- Same name as the class; **no explicit return type**
- Java automatically provides a default constructor if none is defined; once you define your own, the default is no longer added
- **Private constructor** prevents object creation from outside the class (used in Singleton pattern)

**Types:**

**1. Default Constructor** — No parameters; provides default values (0, false, null)

```java
class Rect {
    int a, b;
    Rect() { System.out.println("this is constructor"); }
}
// Output: this is constructor
//         0 (default int)
//         0
```

**2. Parameterized Constructor** — Accepts parameters; uses `this` to avoid name conflict with fields

```java
class Student {
    int id; String name;
    Student(int id, String name) { this.id = id; this.name = name; }
    void display() { System.out.println(id + " " + name); }
}
```

**3. Copy Constructor** — Creates a copy of an existing object; prevents unwanted reference sharing

```java
class Student {
    int id; String name;
    Student(Student s) {
        this.id = s.id;
        this.name = new String(s.name); // new String prevents reference sharing
    }
}
```

### Constructor and Inheritance

- When a subclass object is created, the subclass constructor by default invokes the **default constructor of the super class** — objects are constructed top-down
- The `super` keyword explicitly calls the parent constructor and must be the **first statement** in the constructor

### Garbage Collector

- Java automatically identifies and removes unreferenced objects from memory
- GC program runs in the background, finds objects not referenced by any part of the program, deletes them, and reclaims space

### `finalize()` Method

```java
protected void finalize() {
    // specify actions to perform before an object is destroyed
    // e.g., close database connections, release network resources
}
```

- Java runtime calls this method whenever it is about to recycle an object
- `protected` keyword prevents access from outside the class hierarchy
- Called just prior to garbage collection; NOT called when an object goes out of scope
- **Execution is not guaranteed; deprecated since Java 9**

**Better alternatives:** try-with-resources, AutoCloseable interface, Explicit cleanup methods

---

## 8. Method Overloading

### Definition

- A feature that allows a class to have **more than one method with the same name** if their argument lists are different
- Also known as: **Compile-Time Polymorphism, Static Polymorphism, Early Binding**
- Compiler decides which method to call based on the **method signature** (method name + parameter list — number, type, order)

### Three Ways to Overload

1. Changing the **number** of parameters
2. Changing the **data type** of parameters
3. Changing the **order** of parameters

### Benefits

1. Increases readability of the program
2. Provides flexibility — same method name for different types of data
3. Makes code look clean
4. Reduces execution time (binding done at compile time)
5. Minimises complexity of the code
6. Code reuse, saving memory

```java
class Calculator {
    int add(int a, int b) { return a + b; }           // 2 int params
    int add(int a, int b, int c) { return a + b + c; } // 3 int params
    double add(double a, double b) { return a + b; }   // double params

    public static void main(String[] args) {
        Calculator calc = new Calculator();
        System.out.println(calc.add(10, 20));      // Output: 30
        System.out.println(calc.add(10, 20, 30));  // Output: 60
        System.out.println(calc.add(5.5, 2.5));    // Output: 8.0
    }
}
```

> **Cannot** overload by return type alone. **Cannot** overload two methods if they differ only by the `static` keyword.

---

## 9. Inheritance

### Definition

- The mechanism by which one class is allowed to inherit the features (fields and methods) of another class
- Represents **IS-A relationship** (also known as parent-child relationship)
- Syntax: `class subclass-name extends superclass-name { ... }`
- Cannot inherit from more than one super class (no multiple class inheritance in Java)

### Advantages

- **Reusability** — saves time, avoid rewriting code
- **Enhances Readability**
- **Overriding** — meaningful implementation of base class methods in derived classes

### Types of Inheritance

| Type | Description | Java Support |
|---|---|---|
| **Single Level** | One child inherits from one parent | ✅ Yes |
| **Multilevel** | Chain: A → B → C | ✅ Yes |
| **Hierarchical** | One parent, multiple children | ✅ Yes |
| **Multiple** | One child, multiple parents | ❌ No (use interfaces) |
| **Hybrid** | Combination: e.g. hierarchical + multiple | Partially (via interfaces) |

**`instanceof` keyword** — checks if a reference variable contains a given type of object reference; returns boolean.

### Multiple Inheritance via Interface (Java)

```java
interface A { void show(); }
interface B { void display(); }
class C implements A, B {
    public void show() { /* implementation */ }
    public void display() { /* implementation */ }
}
```

### Hybrid Inheritance

- Two or more types of inheritance combined (e.g., hierarchical + multiple) to create a complex class hierarchy
- Java achieves it using interfaces since classes do not support multiple inheritance

### Method Overriding

- If subclass has the same method as declared in the parent class, it is **method overriding**
- Provides specific implementation of a method already provided by its superclass
- Supports **runtime polymorphism**

**Rules:**

1. Method must have the same **name** as in the parent class
2. Method must have the same **parameters** as in the parent class
3. There must be an **IS-A relationship** (inheritance)

```java
class Bank { int getRateOfInterest() { return 0; } }
class SBI extends Bank { @Override int getRateOfInterest() { return 8; } }
class ICICI extends Bank { @Override int getRateOfInterest() { return 7; } }
class AXIS extends Bank { @Override int getRateOfInterest() { return 9; } }
```

---

## 10. Abstract Classes

### Introduction

- Provides **implementation reuse** — provides default implementation
- Creates a super class that defines a generalized form shared by all subclasses
- Abstract methods are **subclasser responsibility** — no implementation in the superclass; no method body

### Abstract Class Example

```java
abstract class Figure {
    double dim1, dim2;
    Figure(double a, double b) { dim1 = a; dim2 = b; }
    abstract double findArea(); // Must be implemented by subclasses
}
class Rectangle extends Figure {
    Rectangle(double height, double width) { super(height, width); }
    double findArea() { return dim1 * dim2; }
}
class Triangle extends Figure {
    Triangle(double base, double height) { super(base, height); }
    double findArea() { return 0.5 * dim1 * dim2; }
}
```

---

## 11. Single-Rooted Hierarchy and Object Class

### Single-Rooted Hierarchy

- In Java, **all objects inherit from the same base class: `Object`**
- Provides a common interface; enables easy memory management; simplifies argument passing (generic handling of different object types)
- Implementation of Garbage Collector is easier since the required implementation is in the base class
- Java was created from scratch — no backward compatibility issues with existing languages

### Object Class

- Defined in `java.lang` package; super class of all other classes
- Every class has Object as a superclass; all objects including arrays implement its methods
- A reference variable of type `Object` can refer to an object of **any class**

### Object Class Key Methods

**`getClass()`** — Returns the runtime class of the Object

**`hashCode()`** — Returns a hash code value for the object; same object always returns same integer; supports hash tables like `HashMap`

**`equals(Object obj)`** — Indicates whether another object is "equal to" this one

- Default behavior: compares memory reference (same as `==`)
- Often overridden for content comparison

```java
class Box {
    int width, height, depth;
    Box(int l, int m, int n) { this.width = l; this.height = m; this.depth = n; }
    @Override
    public boolean equals(Object o) {
        Box b2 = (Box) o;
        return this.width == b2.width && this.height == b2.height && this.depth == b2.depth;
    }
}
// box1 == box2     → false (different references)
// box1.equals(box2) → true  (same content)
```

| | `==` Operator | `equals()` Method |
|---|---|---|
| Compares | Memory address (reference) | Content (logical equality) |

**`toString()`** — Returns a string representation of the object

- Default: `ClassName@hashcode` (unsigned hexadecimal)
- Should be overridden in all subclasses

```java
@Override
public String toString() { return width + " " + height + " " + depth; }
```

---

## 12. Collections Framework — Arrays, List, Stack

### Collections Introduction

- A collection is an object that represents a group of objects
- The Collections Framework provides high-performance implementations of common data structures

### Arrays in Java

- Fixed-size, index-based data structure

```java
// 1D Array — Declaration and Instantiation
dataType[] arr;            // Declaration
arr = new dataType[size];  // Instantiation
int[] arr = {1, 2, 3, 4, 5}; // Combined

// 2D Array
int[][] matrix = new int[3][3];
```

**`Arrays` class** (`java.util`): `sort()`, `copyOf()`, `fill()`, `binarySearch()`, `equals()`

### List Interface

- Found in `java.util` package; inherits Collection interface
- Provides **index-based access**; allows duplicate elements; maintains insertion order
- Declaration: `public interface List<E> extends Collection<E>`
- Implementation classes: **ArrayList**, **LinkedList**, **Stack**, **Vector**

### ArrayList

```java
ArrayList<Integer> al = new ArrayList<Integer>(); // Generic type required (not primitive)
al.add(10); al.add(20);
```

- Uses a dynamic array; can have duplicate elements; maintains insertion order
- Note: `ArrayList<int>` does not work — must use wrapper type `Integer`

### Stack Class

- Models and implements a Stack data structure (LIFO — Last In First Out)
- Part of the Java Collection Framework

| Method | Description |
|---|---|
| `empty()` | Tests if stack is empty |
| `push(E item)` | Pushes item onto top of stack |
| `pop()` | Removes and returns the top object |
| `peek()` | Looks at top object without removing it |
| `search(Object o)` | Returns 1-based position of object on stack |

---

## 13. System Design and Frameworks

### System Design

- First design stage for devising the basic approach to solve the problem
- Makes decisions about how the problem will be solved — from high level to detailed

### System Architecture Decisions

1. Estimating performance — "back of the envelope" calculation
2. Making a Reuse plan
3. Breaking system into sub-systems
4. Identifying Concurrency
5. Allocation of Sub-Systems to hardware
6. Managing data storage
7. Handling global resources
8. Choosing a software control strategy
9. Handling boundary conditions
10. Setting trade-off priorities
11. Selecting an architectural style

### Reuse Plan — Libraries

Good class libraries are: **Coherent, Complete, Consistent, Efficient, Extensible, Generic**

Examples: Network protocols, compression, image manipulation, string utilities, regular expressions

### Reuse Plan — Patterns

- A best practice; time-tested solution to a recurring problem that has proved to work
- There are patterns for analysis, architecture, design, and implementation
- Comes with guidelines on when to use it, and trade-offs on its use

### Reuse Plan — Frameworks

**Framework** — Skeletal structure or ready-made architecture for applications. Must be elaborated by specializing abstract classes with application-specific behavior.

### Frameworks vs Libraries

| Feature | Framework | Library |
|---|---|---|
| Control | Framework calls the developer's code — **"Hollywood Principle": "Don't call us, we'll call you"** | Developer calls library functions |
| Structure | Provides predefined application skeleton | No predefined structure |
| Customization | Subclassing framework classes; composing instances | Flexible — use as needed |
| Emphasis | **Design reuse** over code reuse | Code reuse |
| Examples | Spring, Hibernate, Grails, JSF, GWT, Quarkus | Apache Commons, JUnit, Log4j |

### Frameworks in Java

- **Collections** — Provides interfaces (Set, List, Queue, Deque) and classes (ArrayList, Vector, LinkedList, PriorityQueue, HashSet, LinkedHashSet, TreeSet)
- **Swing** — javax.swing API; GUI components (JButton, JTextField, JCheckbox, JMenu); built on AWT; written entirely in Java
- **AWT (Abstract Window Toolkit)** — java.awt package; Label, Button, TextField components
- **Spring** — Enterprise applications, dependency injection, web apps
- **Hibernate** — ORM (Object-Relational Mapping) for database interactions
- **Grails, Play, JavaServer Faces (JSF), Google Web Toolkit (GWT), Quarkus**

---

## 14. Architectural Patterns

### Introduction

- An architectural pattern is a general, reusable solution to a commonly occurring problem in software architecture
- Helps define basic characteristics and behavior of an application
- Some patterns lend naturally to **highly scalable** applications; others to **highly agile** applications
- Addresses issues such as hardware performance limitations, high availability, and minimization of business risk
- **Types:** Layered, Event-driven, Microkernel, Microservices, Space-based, MVC

---

### 14.1 MVC (Model-View-Controller)

**History:** First introduced by **Trygve Reenskaug**, a Smalltalk developer at **Xerox Palo Alto Research Center in 1979**. Helps to decouple data access and business logic from the manner in which it is displayed to the user.

**Definition:** A way of designing and building applications that **separates application logic from presentation**; divides application into three main logical components: Model, View, Controller.

**Components:**

| Component | Responsibility | Example Tech |
|---|---|---|
| **Model** | Represents data and the rules governing access to and updates of this data; serves as a software approximation of a real-world process; fetches and stores state in the database | MySQL, MongoDB, Spring Boot |
| **View** | Renders contents of the model; specifies exactly how model data should be presented; can use push model (registers with model for change notifications) or pull model (calls model when it needs current data); represents the presentation layer | JSP, HTML, React, Angular, Vue.js |
| **Controller** | Translates user's interactions with the view into actions the model will perform; in web apps these appear as GET and POST HTTP requests; may also select a new view to present; contains all entities/servlets | Servlets, Spring MVC, Express.js |

**MVC Request Flow:**

1. Controller receives a request from the user (directly or via view)
2. Controller puts the model to work
3. Model delivers the data in the right format
4. Controller forwards it to the view
5. View sends the result back to the browser (client)

**MVC Request Flow (Java specifically):**

1. Client (browser) sends a request to the Controller on the server side
2. Controller calls the Model; gathers the requested data
3. Controller transfers retrieved data to the View layer
4. View sends result back to the browser

**Advantages:**

- Faster Development Process
- Model can be reused with multiple views
- Less dependency among components — **loose coupling**
- Modification does not affect the entire model
- Application becomes more understandable
- Not a single massive codebase

**Implementation (Java):**

- `Employee` class → **Model** (business logic + state; fetches/stores from database; applies rules to data)
- `EmployeeView` class → **View** (visualization; sends fetched data to client)
- `EmployeeController` class → **Controller** (gets user requests; processes with validations; acts as interface between Model and View)

---

### 14.2 Layered Architecture (N-Tier)

**Definition:** Also known as n-tier architecture pattern. Structures programs that can be decomposed into groups of subtasks, each at a particular level of abstraction. Each layer provides services to the next higher layer.

**Common Layers:**

| Layer | Responsibility |
|---|---|
| **Presentation Layer (UI)** | Front-end code; all interfaces visible to users; web, desktop, mobile apps |
| **Business Logic Layer** | Business operations, validations, logic; governed by business rules (e.g., "If invoice is printed, send email to customer") |
| **Persistence Layer** | Communicates with database; object-relational mapping; makes changes 'persist' |
| **Database Layer** | Stores all application data; deals with which tables to query |

**Open vs Closed Layers:**

| Feature | Open Layer | Closed Layer |
|---|---|---|
| Interaction | Higher layers can bypass to communicate directly with lower | Strict layer-to-layer; can only communicate with immediate layer below |
| Performance | Faster (less processing overhead) | Slower (strict processing through layers) |
| Flexibility | More flexible | Less flexible |
| Maintainability | Harder (tight coupling) | Easier (loose coupling) |
| Scalability | Difficult | Easier |
| Best for | Performance-critical applications | Large, modular, maintainable systems |

**Advantages:** Simple and straightforward development; easy testing; fewer dependencies

**Disadvantages:** Difficult to scale; must be deployed as a single unit; performance degrades with growth

**When to Use:** Clear separation of concerns needed; ease of maintenance is important

**When NOT to Use:** Performance is critical; simple applications where overhead is overkill

---

### 14.3 Client-Server Architecture

**Definition:** Distributed system model showing how data and processing is distributed across components.

**Key Components:**

- **Client** — Requester; web browsers, desktop apps, mobile apps; initiates communication
- **Server** — Provider; processes requests; web servers, database servers, application servers
- **Network** — Facilitates communication using protocols (HTTP, FTP, SMTP, SQL)
- **Middleware** — Intermediary providing authentication, logging, message queuing, transaction management
- **Database** — Structured collection of data stored on the server
- **Application Logic** — Code and algorithms defining application functionality

**Stateful server** — Maintains a session record of requests from the client.

**Master-Slave Pattern** — Master listens for client requests; creates a slave to process each request; resumes listening.

**Advantages:** Data integrity, Ease of access via UI, Platform independence, Maintainability

**Disadvantages:** Server can be overloaded when too many requests; central server represents a single point of failure

---

### 14.4 Event-Driven Architecture (EDA)

**Definition:** Designed to orchestrate behavior around the production, detection, consumption of, and reaction to events. Enables highly decoupled, scalable, and dynamic interconnections.

**Key Components:**

- **Events** — Significant changes in state (e.g., "Order Placed", "Payment Processed")
- **Event Producers** — Generate events (e.g., user placing an order)
- **Event Consumers** — React to events (e.g., payment service)
- **Event Brokers** — Manage event routing (Apache Kafka, RabbitMQ, AWS SNS/SQS)

**EDA Patterns:**

- **Simple Event Processing** — Events occur independently and trigger immediate actions
- **Complex Event Processing (CEP)** — Multiple events analyzed together to detect patterns (e.g., fraud detection)
- **Event Sourcing** — System stores every state change as an event for audit/rollback

**Topologies:**

- **Mediator Topology** — Central mediator orchestrates multiple steps; 4 components: event queues, event mediator, event channels, event processors
- **Broker Topology** — Events chain together without a central mediator; 2 components: broker and event processors

**Advantages:** Scalability, Flexibility and Agility, Responsiveness

**Disadvantages:** Complex tracking/debugging, Dependency on messaging systems, Event consistency challenges

---

### 14.5 Microkernel Architecture (Plug-in Architecture)

**Definition:** Natural pattern for product-based applications; allows adding additional features as plug-ins to the core application, providing extensibility and feature isolation.

**Two Main Components:**

- **Core System** — Minimal functionality required to make the system operational; basic business logic without custom code for special cases
- **Plug-in Modules** — Stand-alone, independent components with specialized processing, additional features, and custom code; should be independent of each other

**Plug-in Registry** — Contains information about each plug-in (name, data contract, remote access protocol details).

**Contracts** — Input/output data that allows data exchange even when core system and plug-in are different types. Custom contracts need adapter between plug-in contact and standard contract.

**Examples:** Eclipse IDE (base is just an editor; plug-ins make it customizable), Web browsers, Insurance claims processing

**Advantages:** Easy reaction to changes in plug-in modules without modifying core; easier deployment; easier testing; customizable to only include needed features

**Disadvantages:** Not highly scalable; requires thorough design analysis (contract versioning, registries, granularity, connectivity options)

---

### 14.6 Microservices Architecture

**Definition:** Structures an application as a collection of **loosely coupled services**, each focused on performing a specific business function. Services are independently deployable, scalable, and can use different programming languages.

**Key Characteristics:** Each service has its own database; communicate via APIs (REST, gRPC, messaging); independently deployable and scalable.

**Microservices Design Principles:**

1. Scalability
2. Flexibility
3. Independent and autonomous
4. Decentralized governance
5. Resiliency
6. Failure isolation
7. Continuous delivery through DevOps

**Key Patterns:**

- **Database per Microservice** — Ensures independence; changes to one database don't impact others; each can scale independently
- **API Gateway** — Single entry point; acts as reverse proxy; abstracts underlying architecture; handles authentication, SSL termination, caching

**Advantages:** Scalability, Faster Development and Deployment, Fault Isolation, Technology Flexibility, Improved Maintainability

**Disadvantages:** Increased Complexity, Network Latency, Data Consistency Challenges, Security Risks, Higher Infrastructure Costs

**When to Use:** Large complex applications (Netflix, Amazon, Uber), high scalability/fault tolerance, multiple development teams

**When NOT to Use:** Small applications/MVPs, simplicity and fast development are priorities, team lacks DevOps/Kubernetes experience

---

# Unit 3: Design Principles

## 1. Why Design Principles Matter

### Aspects of Bad Design

- **Rigidity** — Every change causes a cascade of changes in dependent modules; costs become unpredictable
- **Fragility** — Software tends to break in many places on every change; breaks in unrelated areas
- **Immobility** — Impossible to reuse interesting parts; too many dependencies; cost of rewriting < cost of separation
- **Viscosity** — A hack is cheaper than the correct solution; it's easier to do the wrong thing

### Good Design Goals

- **High Cohesion** — Strongly related and focused responsibilities within a class
- **Low Coupling** — Minimal dependencies between classes/modules

---

## 2. GRASP Design Principles

**GRASP = General Responsibility Assignment Software Patterns**

- Consists of guidelines for assigning responsibility to classes and objects in OO design
- First published by Craig Larman (1997)
- 9 fundamental principles in object design and responsibility

### What is Responsibility?

> A contract or obligation that a class/module/component must accomplish.

**Types of Responsibility:**

- **Doing:** Creating an object, doing a calculation, initiating action in other objects, controlling/coordinating activities
- **Knowing:** Knowing about private encapsulated data, knowing about related objects, knowing things it can derive or calculate

### RDD — Responsibility Driven Design

An abstraction of what objects do; assigned to classes during object design.

---

### GRASP Principle 1: Creator

**Problem:** Who should create a new instance of some class?

**Solution:** Assign the responsibility of creating instances of a class to the class that has the **most knowledge** about when and how to create them — the "container" creates "contained" objects.

**Guidelines:**

- Assign B to create A if B contains or aggregates A
- Assign B to create A if B records A
- Assign B to create A if B closely uses A
- Assign B to create A if B has initializing data for A

**Example:** In a POS system, since a `Sale` contains `SalesLineItem` objects, `Sale` should be responsible for creating them.

```java
public class OrderService {
    private final OrderRepository orderRepository;
    
    public void createOrder(Customer customer, List<Product> products) {
        Order order = new Order(customer, products); // Creator creates Order
        orderRepository.saveOrder(order);
    }
}
```

> **Note:** For complex creation situations, use the **Factory Pattern** instead.

---

### GRASP Principle 2: Information Expert

**Problem:** What is a basic principle by which to assign responsibilities to objects?

**Solution:** Assign a responsibility to the class that **has the information needed to fulfill it**. "Objects do things related to the information they have."

**Key Insight:** Information necessary may be spread across several classes, so objects interact via messages.

**Example (POS System):** Who should know the grand total of a sale?

- `Sale` — knows sale total
- `SalesLineItem` — knows line-item subtotal
- `ProductDescription` — knows product price

```java
public class ShoppingCart {
    private List<Item> items = new ArrayList<>();
    
    public double calculateTotalPrice() { // ShoppingCart is the Information Expert for total price
        double totalPrice = 0;
        for (Item item : items) {
            totalPrice += item.getPrice();
        }
        return totalPrice;
    }
}
```

---

### GRASP Principle 3: Low Coupling

**Problem:** How to support low dependency, low change impact, and increased reuse?

**Solution:** Assign responsibilities so that **coupling remains low**.

**Coupling** — Degree of dependency between classes or modules.

| Type | Description | Problem |
|---|---|---|
| **Tight Coupling** | High dependency; one class creates instance of another and directly accesses its methods/fields | Changes in one class require changes in coupled class |
| **Loose Coupling** | Low dependency; interact through well-defined interfaces | Changes have less impact |

**Low Coupling evaluative guidelines:**

- Lower dependency between classes
- Lower change impact on other classes
- Higher reuse potential

**Causes of coupling in Java:**

- TypeX has an attribute of TypeY
- TypeX calls services of a TypeY object
- TypeX has a method referencing TypeY
- TypeX is a subclass of TypeY
- TypeY is an interface and TypeX implements it

> Note: Subclassing leads to high coupling.

**Techniques to achieve Low Coupling:**

- Use interfaces, abstract classes, or dependency injection
- Inversion of Control (IoC) / Dependency Injection (DI)

```java
interface Vehicle { void move(); }
class Car implements Vehicle { @Override public void move() { ... } }
class Bike implements Vehicle { @Override public void move() { ... } }

class Traveler {
    private Vehicle v;
    public void setV(Vehicle v) { this.v = v; } // Inject dependency
    public void startJourney() { v.move(); }
}
```

---

### GRASP Principle 4: Controller

**Problem:** Who should be responsible for handling a system event? What object receives and coordinates a system operation?

**Solution:** Assign responsibility for receiving/handling a system event to one of:

1. **Façade Controller** — An object that represents the overall system, device, or subsystem
2. **Use Case Controller** — An object that represents a use case scenario

**Controller guidelines:**

- Coordinates activity but **delegates work** to other objects (doesn't do work itself)
- Use the same controller class for all system events of one use case (to maintain state)
- Avoid **Bloated Controllers** — a single class receiving all system events; controller performing many tasks

**Benefits:** Reusable controller class; can maintain use case state; can control sequence of activities

**Example (Monopoly):** GameController receives requests from UI → delegates to appropriate domain objects.

---

### GRASP Principle 5: High Cohesion

**Problem:** How to keep complexity manageable, understandable, and support low coupling?

**Solution:** Assign responsibilities so that **cohesion remains high**.

**Cohesion** — A measure of how strongly related and focused the responsibilities of an element are.

**Problems from Low Cohesion:**

- Hard to understand/comprehend
- Hard to reuse
- Hard to maintain
- Brittle — easily affected by change

**High Cohesion:** A class should have a single, well-focused purpose. Related things should be together; unrelated things should be separate.

---

### GRASP Principle 6: Polymorphism

**Problem:** How to handle alternatives based on type? How can you replace one server component with another without affecting the client?

**Solution:** When related alternatives or behaviors vary by type, assign responsibility using **polymorphic operations** to the types for which the behavior varies.

**Types (GRASP context):**

- **Ad-hoc** — Overloading
- **Parametric** — Early binding / Generics
- **Inclusion** — Subtyping (Runtime polymorphism)
- **Coercion** — Casting

**Example:** `getArea()` varies by the type of shape; assign that responsibility to the subclasses.

```java
abstract class Shape {
    abstract double getArea();
}
class Circle extends Shape {
    double radius;
    @Override
    double getArea() { return Math.PI * radius * radius; }
}
class Triangle extends Shape {
    double base, height;
    @Override
    double getArea() { return 0.5 * base * height; }
}
```

---

### GRASP Principle 7: Indirection

**Problem:** How to assign responsibilities to avoid direct coupling between two components and keep ability for reuse?

**Solution:** Assign responsibility to an **intermediate class** for providing linking between objects, not linking them directly.

**Related Design Patterns:** Adapter, Bridge, Mediator

**How to Implement Indirection:**

1. Identify mediating responsibilities (routing, translation between interfaces)
2. Introduce Intermediate Objects
3. Encapsulate Mediating Logic
4. Promote Loose Coupling
5. Facilitate Evolution and Extension

**Example:** `Salary` serves as the intermediary between the caller and `Employee` to obtain salary details.

---

### GRASP Principle 8: Pure Fabrication

**Problem:** What object should have responsibility when assigning to domain layer classes leads to poor cohesion or coupling?

**Solution:** Assign a highly cohesive set of responsibilities to an **artificial or convenience class that does not represent a domain concept** — "Pure Fabrication."

**When to use:** When solutions offered by Information Expert are not appropriate (would violate High Cohesion and Low Coupling).

**Examples:** Utility classes, Service classes, Helper classes (data validation, formatting, error handling)

**Example (Monopoly):** Use a `Cup` to hold the dice, roll them, and know their total — `Cup` is a pure fabrication that can be reused in many dice-related applications.

---

### GRASP Principle 9: Protected Variation (Controlled Variation)

**Problem:** How to design objects, subsystems, and systems so that variations or instability in these elements do not have an undesirable impact on other elements?

**Solution:** Identify points of predicted variation or instability; assign responsibilities to create a **stable interface** around them.

**Variation Points:**

- **Variation point** — Branching point in existing system or requirements
- **Evolution point** — Supposed branching point that might occur in the future but not in current requirements

**Similar to:** Open-Closed Principle

```java
interface Account { double calculateInterest(); }

class SavingsAccount implements Account {
    @Override
    public double calculateInterest() { return balance * 0.04; }
}
class FixedDepositAccount implements Account {
    @Override
    public double calculateInterest() { return balance * 0.07; }
}
// BankSystem uses Account interface — protected from variations in account types
```

---

## 3. Introduction to SOLID Principles

**SOLID** — An acronym for 5 important design principles introduced by Robert C. Martin ("Uncle Bob"), acronym identified by Michael Feathers.

**SOLID goals:**

- More flexible and stable software architecture
- Easier to maintain and extend
- Reduced dependencies — changes in one part don't impact others
- Achieves **Low Coupling and High Cohesion**

---

### SOLID Principle 1: Single Responsibility Principle (SRP)

> "A class should have one, and only one, reason to change." — Robert C. Martin

**States:** Every module or class should have responsibility over a **single part** of the functionality.

**Violation:**

```java
class Book {
    String title;
    String author;
    String getTitle() { return title; }
    String getAuthor() { return author; }
    void searchBook() { ... } // VIOLATES SRP — Book has 2 responsibilities
}
```

**Solution — separate concerns:**

```java
class Book {
    String title;
    String author;
    String getTitle() { return title; }
    String getAuthor() { return author; }
}
class InventoryView {
    Book book;
    void searchBook() { ... } // Separate class for search
}
```

**Advantages:**

- Fewer test cases (class with one responsibility)
- Lower coupling — less functionality means fewer dependencies
- Organization — smaller, well-organized classes

**Guideline:** Identify things that change for different reasons → group together things that change for the same reason → decouple the responsibilities.

---

### SOLID Principle 2: Open-Closed Principle (OCP)

> Classes, modules, microservices, and other code units should be **open for extension but closed for modification**. — Bertrand Meyer

**States:** A software entity must be easily extensible with new features without modifying its existing code.

**Technique:** Use OOP features like **inheritance** via subclasses and **interfaces**.

**Violation:**

```java
class DiscountManager {
    void processCookbookDiscount(CookbookDiscount discount) { ... }
    void processBiographyDiscount(BiographyDiscount discount) { ... } // Must MODIFY class each time
}
```

**Solution — introduce abstraction:**

```java
public interface BookDiscount {
    String getBookDiscount();
}
class CookbookDiscount implements BookDiscount { ... }
class BiographyDiscount implements BookDiscount { ... }

class DiscountManager {
    void processBookDiscount(BookDiscount discount) { ... } // Extend via interface, not modify
}
```

**Why OCP?** Without it:

- Must test entire functionality on any change
- Breaks SRP as well
- Increases maintenance overhead

---

### SOLID Principle 3: Liskov Substitution Principle (LSP)

> "Let S be a subtype of T, then for each object o1 of type S there is an object o2 of type T such that for all programs P defined in terms of T, the behaviour of P is unchanged when o1 is substituted for o2." — Barbara Liskov (1987)

**States:** An object of a superclass should be **replaceable by objects of its subclasses** without causing issues. A child class should never change the characteristics of its parent class.

**Applies to:** Inheritance (is-a relationship) hierarchies; avoids overuse/misuse

**Key Points:**

- Derived types must be completely substitutable for their base types
- Derived classes should never do **less** than their base class

**Violation Example:**

```java
class BookDelivery {
    void getDeliveryLocations() { ... }
}
class AudiobookDelivery extends BookDelivery {
    @Override
    void getDeliveryLocations() { /* Can't be implemented — audiobooks have no physical location */ }
    // VIOLATES LSP — substituting AudiobookDelivery breaks the program
}
```

**Solution — better hierarchy:**

```java
class BookDelivery { /* shared data */ }
class OfflineDelivery extends BookDelivery {
    void getDeliveryLocations() { ... }
}
class OnlineDelivery extends BookDelivery {
    void getSoftwareOptions() { ... }
}
class HardcoverDelivery extends OfflineDelivery { /* properly overrides */ }
class AudiobookDelivery extends OnlineDelivery { /* properly overrides */ }
```

---

### SOLID Principle 4: Interface Segregation Principle (ISP)

> "Make fine-grained interfaces that are client-specific. Clients should not be forced to implement interfaces they do not use."

**States:** Many client-specific interfaces are better than one general-purpose (fat) interface.

**Guideline:** Break fat interfaces that have too many methods into smaller, more specific ones.

**Violation:**

```java
public interface BookAction {
    void seeReviews();
    void searchSecondhand();  // HardcoverUI doesn't need listenSample
    void listenSample();       // AudiobookUI doesn't need searchSecondhand
}
class HardcoverUI implements BookAction { /* forced to implement listenSample */ }
class AudiobookUI implements BookAction { /* forced to implement searchSecondhand */ }
```

**Solution — split into smaller interfaces:**

```java
public interface BookAction { void seeReviews(); }
public interface HardcoverAction extends BookAction { void searchSecondhand(); }
public interface AudioAction extends BookAction { void listenSample(); }

class HardcoverUI implements HardcoverAction { /* only relevant methods */ }
class AudiobookUI implements AudioAction { /* only relevant methods */ }
```

**Historical context:** First used by Robert C. Martin while consulting for Xerox — one large Job class was segregated into multiple interfaces.

**Failure to comply:** Creates dependencies on methods that we don't need but are obliged to define.

---

### SOLID Principle 5: Dependency Inversion Principle (DIP)

> "Program to the interface, not the implementation."

**States:**

1. **High-level modules should not depend on low-level modules** — both should depend on abstractions
2. **Abstractions should not depend on details** — details should depend on abstractions

**Goal:** Avoid tightly coupled code; decouple high-level and low-level classes through abstract interaction.

**Violation:**

```java
class Shelf {
    Book book; // Directly depends on concrete class Book
    void addBook(Book book) { ... }
}
// Adding DVD requires modifying Shelf — violates OCP and DIP
```

**Solution — depend on abstractions:**

```java
public interface Product {
    void seeReviews();
    void getSample();
}
class Book implements Product { ... }
class DVD implements Product { ... }

class Shelf {
    Product p; // Depends on abstraction, not concrete classes
    void addProduct(Product product) { ... }
}
```

**Techniques:** Dependency Injection (DI) — objects are given their dependencies at creation time by a third party (Spring DI, Java EE CDI).

**DIP combines:** Open-Closed Principle + Liskov Substitution Principle

---

## 4. SOLID Applied — Online Food Ordering Case Study

### SRP: Single Responsibility

Split the `Order` class into separate concerns:

- `Order` — manages order details only
- `PaymentProcessor` — handles payment logic
- `NotificationService` — sends confirmations

### OCP: Open-Closed

Add new payment methods (PayPal, UPI) without modifying `PaymentProcessor`:

```java
interface PaymentMethod { void pay(double amount); }
class CreditCardPayment implements PaymentMethod { ... }
class PayPalPayment implements PaymentMethod { ... }
class PaymentProcessor {
    void processPayment(PaymentMethod method, double amount) { method.pay(amount); }
}
```

### LSP: Liskov Substitution

Instead of `DroneDelivery extends DeliveryPerson` (drones don't need `assignVehicle()`), use a common interface:

```java
interface DeliveryService { void deliverOrder(Order order); }
class DeliveryPerson implements DeliveryService { ... }
class DroneDelivery implements DeliveryService { ... }
```

### ISP: Interface Segregation

Small restaurant doesn't need `generateMonthlyReport()` — split the interface:

```java
interface MenuManagement { void addMenuItem(Item item); void updateStock(Item item, int quantity); }
interface Reporting { void generateMonthlyReport(); }
class SmallRestaurant implements MenuManagement { ... } // Only what it needs
```

### DIP: Dependency Inversion

`OrderService` shouldn't depend directly on `MySQLDatabase`:

```java
interface Database { void saveOrder(Order order); }
class MySQLDatabase implements Database { ... }
class MongoDBDatabase implements Database { ... }
class OrderService {
    private Database database;
    public OrderService(Database database) { this.database = database; } // Injected dependency
}
```

---

## 5. Introduction to Design Patterns

### The Beginning of Patterns

Christopher Alexander (architect) introduced the concept:

> "Each pattern describes a problem which occurs over and over again in our environment, and then describes the core of the solution to that problem."

### Gang of Four (GoF) Book

"Design Patterns: Elements of Reusable Object-Oriented Software" — Addison-Wesley, 1994

Authors: Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides

**23 patterns in three categories:**

| Category | Focus | Examples |
|---|---|---|
| **Creational** | Object creation process | Singleton, Factory, Builder, Prototype, Abstract Factory |
| **Structural** | Static composition and structure | Adapter, Facade, Proxy, Flyweight, Composite, Bridge, Decorator |
| **Behavioral** | Dynamic interaction among classes/objects | Chain of Responsibility, Command, Iterator, Observer, Strategy, Template Method, etc. |

### What is a Design Pattern?

- A general reusable solution to a commonly occurring problem in software design
- **Not** a finished design that can be transferred directly into code — it's a template
- Shows relationships and interactions between classes/objects, not specifying final classes
- **Language independent**

### Four Essential Elements of a Design Pattern

1. **Pattern Name** — A handle to describe the design problem in a word or two
2. **The Problem** — When to apply the pattern; explains problem and its context
3. **The Solution** — Elements making up the design, their relationships, responsibilities, and collaborations
4. **Consequences** — Results and trade-offs of applying the pattern

### Why Learn Patterns?

- **Common vocabulary** — Abstract problems and discuss abstractions in isolation
- **Capture design expertise** — Promote design reuse; avoid mistakes
- **Improve documentation and understandability**
- **Improve time to solution** — Templates as foundations for good design
- **Improve reuse through composition**

### Cons of Design Patterns

- Some come with negative consequences (object proliferation, performance hits)
- Subject to different interpretations and misinterpretations
- Can be overused and abused → **Anti-Patterns**

### Architecture Patterns vs. Design Patterns

|          | Architecture Patterns              | Design Patterns                 |
| -------- | ---------------------------------- | ------------------------------- |
| Scope    | System-wide structure              | Class/object level              |
| Examples | MVC, Layered, Microservices        | Singleton, Factory, Observer    |
| Purpose  | Define overall system organization | Solve recurring design problems |

---

# Unit 4: OO Design Patterns & Anti-Patterns

## 1. CREATIONAL DESIGN PATTERNS

Creational design patterns provide various object creation mechanisms, which increase flexibility and reuse of existing code.

**Recurring themes:**

- Encapsulate knowledge about which concrete classes the system uses (so we can change them easily later)
- Hide how instances of these classes are created and put together

**Why creational patterns?** Direct use of `new` keyword scatters objects all over the application, leading to tight coupling.

**Types:**

| Pattern | Scope | Purpose |
|---|---|---|
| **Singleton** | Object | Ensure a class has only one instance; provide global access |
| **Factory Method** | Class/Object | Defer object creation to subclasses |
| **Abstract Factory** | Object | Create families of related objects |
| **Builder** | Object | Separate construction of a complex object from its representation |
| **Prototype** | Object | Create objects by cloning existing instances |

---

### 1.1 Singleton Pattern

**Intent:** Ensure a class has only **one instance**, and provide a **global point of access** to it.

**Real-World Analogy:** The government — a country can have only one official government.

**When to Use:**

- There must be exactly one instance of a class accessible to clients from a well-known access point
- When the sole instance should be extensible by subclassing

**Two Steps in All Singleton Implementations:**

1. Make the default constructor **private** (prevent others from using `new`)
2. Create a **static creation method** that acts as a constructor — calls private constructor to create an object, saves it in a static field

**Structure:**

```
Singleton
─────────────────────────
- instance: Singleton  (static)
─────────────────────────
- Singleton()          (private constructor)
+ getInstance(): Singleton (static method)
```

**Implementation Variants:**

**Method 1 — Lazy Instantiation:**

```java
class Singleton {
    private static Singleton obj;
    private Singleton() {} // Private constructor
    public static Singleton getInstance() {
        if (obj == null)
            obj = new Singleton();
        return obj;
    }
}
// Problem: Not thread-safe!
```

**Method 2 — Synchronized:**

```java
public static synchronized Singleton getInstance() {
    if (obj == null)
        obj = new Singleton();
    return obj;
}
// Disadvantage: Expensive — synchronized on every call
```

**Method 3 — Eager Instantiation:**

```java
private static Singleton obj = new Singleton(); // Created at class loading
public static Singleton getInstance() { return obj; }
// Thread-safe but creates even if not needed
```

**Method 4 — Double-Checked Locking (Best):**

```java
private static volatile Singleton obj = null;
public static Singleton getInstance() {
    if (obj == null) {
        synchronized (Singleton.class) {
            if (obj == null)
                obj = new Singleton();
        }
    }
    return obj;
}
// volatile ensures correct visibility; lock acquired only once
```

**Consequences:**

- ✅ Controlled access to sole instance
- ✅ Reduced name space (avoids global variables)
- ✅ Permits variable number of instances
- ❌ Violates Single Responsibility Principle
- ❌ Difficult to unit test
- ❌ Requires special treatment in multithreaded environments

**Relations with Other Patterns:** Facade objects are often Singletons; Abstract Factories, Builders, and Prototypes can be implemented as Singletons.

---

### 1.2 Factory Method Pattern

**Also Known As:** Virtual Constructor

**Intent:** Define an interface for creating an object, but let subclasses decide which class to instantiate. The Factory Method lets a class **defer instantiation to subclasses**.

**GoF Definition:** "Defines an interface for creating an object, but lets subclasses decide which class to instantiate."

**When to Use:**

- A class can't anticipate the class of objects it must create
- A class wants its subclasses to specify the objects it creates
- Classes delegate responsibility to one of several helper subclasses

**Participants:**

| Participant | Role |
|---|---|
| **Product** | Defines the interface of objects the factory method creates |
| **ConcreteProduct** | Implements the Product interface |
| **Creator** | Declares the factory method, returning an object of type Product |
| **ConcreteCreator** | Overrides the factory method to return an instance of ConcreteProduct |

**Structure:**

```
Creator                      Product
───────────────             ─────────────
+ factoryMethod(): Product  (interface)
+ operation()               
        △                        △
        │                        │
ConcreteCreator         ConcreteProduct
───────────────         ──────────────
+ factoryMethod()       
   creates ConcreteProduct
```

**Example:**

```java
// Product interface
interface Car { void service(); void clean(); void fuelUp(); }

// Factory (Creator)
abstract class CarFactory {
    abstract Car retrieveCar(String grade); // Factory Method — abstract
    public Car create(String grade) {        // Template method
        Car car = retrieveCar(grade);
        car.service();
        car.clean();
        car.fuelUp();
        return car;
    }
}

// ConcreteCreators
class CompanyContractFactory extends CarFactory {
    @Override
    Car retrieveCar(String grade) {
        return grade.equals("A") ? new Tesla() : new Audi();
    }
}
```

**Consequences:**

- ✅ Provides hooks for subclasses
- ✅ Connects parallel class hierarchies
- ✅ More flexible than creating objects directly
- ❌ Might require subclassing Creator just to create a particular ConcreteProduct

---

### 1.3 Builder Pattern

**Intent:** Separate the **construction of a complex object** from its representation so that the same construction process can create different representations.

**Analogy:** A car factory — a Boss (Director) tells workers (Builders) to build each part.

**When to Use:**

- Algorithm for creating a complex object should be independent of the parts and assembly
- Construction process must allow different representations
- You want to get rid of a "telescoping constructor" (many optional parameters)

**Participants:**

| Participant | Role |
|---|---|
| **Builder** | Abstract interface for creating parts of a Product |
| **ConcreteBuilder** | Constructs and assembles parts; keeps track of its representation; provides interface for retrieving product |
| **Director** | Constructs an object using the Builder interface |
| **Product** | Represents the complex object under construction |

**Collaboration:**

1. Client creates Director object and configures it with a Builder
2. Director notifies Builder to build each part of the product
3. Builder handles requests from Director and adds parts to the product
4. Client retrieves product from Builder

**Example (Burger Restaurant):**

```java
// Builder abstract class
abstract class BurgerBuilder {
    Burger burger = new Burger();
    abstract void setBun();
    abstract void setMeat();
    abstract void setSauce();
    Burger getBurger() { return burger; }
}

// ConcreteBuilders
class CheeseBurgerBuilder extends BurgerBuilder {
    void setBun() { burger.setBun("White Bread"); }
    void setMeat() { burger.setMeat("Beef"); }
    void setSauce() { burger.setSauce("Secret Sauce"); }
}

// Director
class Chef {
    void buildBurger(BurgerBuilder builder) {
        builder.setBun();
        builder.setMeat();
        builder.setSauce();
    }
}
```

**Consequences:**

- ✅ Lets you vary a product's internal representation
- ✅ Isolates code for construction and representation
- ✅ Gives finer-grain control over the construction process
- ✅ Step-by-step construction; can defer or run steps recursively
- ❌ Overall complexity of code increases (multiple new classes required)

---

### 1.4 Prototype Pattern

**Intent:** Specify the kind of objects to create using a **prototypical instance**, and create new objects by **copying (cloning) this prototype**.

**Key Aspect:** Client code can make new instances without knowing which specific class is being instantiated.

**In Java:** Uses the `clone()` method or deserialization; needs `Cloneable` interface.

**When to Use:**

- A system should be independent of how its products are created, composed, and represented
- When classes to instantiate are specified at run-time (dynamic loading)
- To avoid building a class hierarchy of factories parallel to product hierarchy
- When instances have one of only a few different combinations of state

**Participants:**

| Participant | Role |
|---|---|
| **Prototype** | Declares an interface for cloning itself |
| **ConcretePrototype** | Implements the cloning operation |
| **Client** | Creates a new object by asking a prototype to clone itself |

**Structure:**

```java
abstract class Shape {
    abstract Shape clone();
}
class Circle extends Shape {
    int radius;
    Circle(Circle source) { this.radius = source.radius; } // Copy constructor
    @Override
    Circle clone() { return new Circle(this); }
}
```

**Prototype Registry:** A centralized registry of pre-defined prototype objects — clients retrieve new objects from the factory by passing a name or parameters.

**Issues to Consider:**

- **Clone operation implementation** — Tricky with circular references
- **Initializing clones** — May need multiple initialization parameters varying by class

**Consequences:**

- ✅ Adding and removing products at run-time
- ✅ Specifying new objects by varying values
- ✅ Specifying new objects by varying structure
- ✅ Reduced subclassing
- ✅ Configuring an application with classes dynamically

---

## 2. STRUCTURAL DESIGN PATTERNS

Structural design patterns deal with how classes and objects can be **composed to form larger structures**.

They simplify structure by identifying relationships, focusing on how classes inherit from each other and how they are composed.

**Types:**

| Pattern | Scope | Purpose |
|---|---|---|
| **Adapter** | Class/Object | Convert incompatible interfaces |
| **Facade** | Object | Simplified interface to subsystem |
| **Proxy** | Object | Placeholder/surrogate for another object |
| **Flyweight** | Object | Share fine-grained objects efficiently |
| **Composite** | Object | Treat objects and compositions uniformly |
| **Bridge** | Object | Separate abstraction from implementation |
| **Decorator** | Object | Attach additional responsibilities to objects |

---

### 2.1 Adapter Pattern

**Also Known As:** Wrapper

**Intent:** Convert the interface of a class into another interface that a client wants. Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.

**Real-World Analogy:** Power adapters, camera memory card adapters

**Advantages:**

- Allows two or more previously incompatible objects to interact
- Allows reusability of existing functionality

**Participants:**

| Participant | Role |
|---|---|
| **Target** | Defines the domain-specific interface that Client uses |
| **Adapter** | Adapts the Adapted to the Target interface |
| **Adapted** | Defines an existing interface that needs adapting |
| **Client** | Collaborates with objects conforming to the Target interface |

**Two Types:**

**Object Adapter (Delegation):**

- Uses composition; holds an instance of Adapted
- Can adapt Adapted and ALL its subclasses
- More code (delegation) but more flexible

**Class Adapter (Inheritance):**

- Uses multiple inheritance (extends both Target and Adapted)
- Only for languages supporting multiple inheritance (not pure Java/C#)
- Less code but adapts only the specific Adapted class

**Example:**

```java
// Adaptee
class AdvancedMediaPlayer {
    void playVlc(String fileName) { ... }
    void playMp4(String fileName) { ... }
}

// Adapter
class MediaAdapter implements MediaPlayer {
    AdvancedMediaPlayer advancedPlayer = new AdvancedMediaPlayer();
    @Override
    public void play(String audioType, String fileName) {
        if (audioType.equalsIgnoreCase("vlc"))
            advancedPlayer.playVlc(fileName);
        else if (audioType.equalsIgnoreCase("mp4"))
            advancedPlayer.playMp4(fileName);
    }
}
```

**When to Use:**

- You want to use an existing class whose interface does not match what you need
- You want to create a reusable class that cooperates with unrelated or unforeseen classes

---

### 2.2 Facade Pattern

**Intent:** Provide a **unified interface to a set of interfaces** in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.

**Meaning:** The principal front of a building that faces the street — an outward appearance.

**Why Facade?**

- Structuring a system into subsystems helps reduce complexity
- A common goal is to minimize communication and dependencies between subsystems

**Applicability:**

- To provide a simple interface to a complex subsystem
- To decouple the subsystem from clients (promoting independence and portability)
- To define an entry point to each subsystem level
- To simplify dependencies between subsystems (communicate only through their facades)

**Advantages:**

- Shields clients from subsystem components (fewer objects to deal with)
- Promotes weak coupling between subsystem and clients
- Can eliminate complex or circular dependencies
- Reduces compilation dependencies

**Example:**

```java
// Complex subsystem classes
class DVDPlayer { void on(){} void play(String movie){} }
class Amplifier { void on(){} void setVolume(int level){} }
class Projector { void on(){} void setInput(DVDPlayer player){} }

// Facade — simplified interface
class HomeTheaterFacade {
    DVDPlayer dvd; Amplifier amp; Projector projector;
    
    void watchMovie(String movie) {
        projector.on();
        projector.setInput(dvd);
        amp.on();
        amp.setVolume(5);
        dvd.on();
        dvd.play(movie);
    }
}
```

**Note:** A Facade class can often be transformed into a **Singleton** (only one facade object needed).

---

### 2.3 Proxy Pattern

**Intent:** Provide a **surrogate or placeholder** for another object to control access to it.

**How it works:** Client does not directly talk to the original object; delegates calls to the proxy object which calls methods of the original object. The **client does not know about the proxy**.

**Three Main Variations:**

| Type | Purpose |
|---|---|
| **Remote Proxy** | Provides a local representative for an object in a different address space |
| **Virtual Proxy** | Creates expensive objects on demand (lazy initialization) |
| **Protection Proxy** | Controls access to the original object; useful when objects should have different access rights |
| **Cache Proxy** | Caches request results to improve responsiveness |

**Participants:**

| Participant | Role |
|---|---|
| **Subject** | Interface that exposes functionality to clients |
| **Real Subject** | Concrete implementation that needs to be hidden behind a proxy |
| **Proxy** | Hides the real object; clients communicate through this; usually created by frameworks |

**Real-World Example:** Corporate network proxy — checks requests for allowed websites; blocks suspicious ones.

```java
interface Image { void display(); }

class RealImage implements Image {
    private String filename;
    RealImage(String filename) {
        this.filename = filename;
        loadFromDisk(); // Expensive operation
    }
    private void loadFromDisk() { System.out.println("Loading: " + filename); }
    public void display() { System.out.println("Displaying: " + filename); }
}

class ProxyImage implements Image {
    private RealImage realImage;
    private String filename;
    ProxyImage(String filename) { this.filename = filename; }
    public void display() {
        if (realImage == null)
            realImage = new RealImage(filename); // Lazy loading — creates only when needed
        realImage.display();
    }
}
```

**Advantages:**

- Works even if service object isn't ready or is not available
- Open/Closed Principle — new proxies can be introduced without changing service or clients

**Disadvantages:**

- Introduces additional layer — contributes to code complexity
- Response from service might get delayed

---

### 2.4 Flyweight Pattern

**Intent:** Use sharing to support **large numbers of fine-grained objects efficiently**.

**Goal:** Reduce memory by sharing common parts of state between multiple objects instead of keeping all data in each object.

**Key Concept — Intrinsic vs. Extrinsic State:**

| State | Description |
|---|---|
| **Intrinsic** | Information **independent** of the object's context; **shareable** — stored inside flyweight |
| **Extrinsic** | Information **dependent** on object's context; **not shared** — computed or passed from outside |

**Example (Document Editor):**

- Character objects: Intrinsic = character code; Extrinsic = coordinate position, typographic style

**Participants:**

| Participant | Role |
|---|---|
| **Flyweight** | Declares interface through which flyweights receive and act on extrinsic state |
| **ConcreteFlyweight** | Implements Flyweight; stores intrinsic state; must be shareable |
| **UnsharedConcreteFlyweight** | Not all subclasses need to be shared |
| **FlyweightFactory** | Creates and manages flyweight objects; ensures proper sharing |
| **Client** | Maintains references to flyweights; computes/stores extrinsic state |

```java
import java.util.HashMap;

class CharacterFlyweight { // ConcreteFlyweight
    private char character; // Intrinsic state
    CharacterFlyweight(char c) { this.character = c; }
    void draw(int x, int y, String font) { // x, y, font = extrinsic state
        System.out.println("Drawing '" + character + "' at (" + x + "," + y + ") in " + font);
    }
}

class FlyweightFactory {
    private HashMap<Character, CharacterFlyweight> pool = new HashMap<>();
    public CharacterFlyweight getCharacter(char c) {
        if (!pool.containsKey(c))
            pool.put(c, new CharacterFlyweight(c)); // Create only if not exists
        return pool.get(c);
    }
}
```

**When to Use:**

- Application uses a large number of objects
- Storage costs are high because of quantity of objects
- Most object state can be made extrinsic
- Application doesn't depend on object identity

**Real-World Examples:**

- Java String constant pool (if string with same content exists, return reference to it)
- Browser image caching (load image once, reuse from cache)
- Pen with refill (pen body = intrinsic; refill color = extrinsic)

---

## 3. BEHAVIORAL DESIGN PATTERNS

Behavioral patterns deal with algorithms and the **assignment of responsibilities between objects**. They describe patterns of communication between objects.

**Types:**

| Pattern | Purpose |
|---|---|
| Chain of Responsibility | Pass request along a chain until handled |
| Command | Encapsulate a request as an object |
| Interpreter | Define a language grammar and interpreter |
| Iterator | Sequentially access elements without exposing implementation |
| Mediator | Unified interface to a set of interfaces in a subsystem |
| Memento | Restore an object to a previous state |
| Observer | Notify objects of changes to another object |
| State | Object partially changes type at runtime |
| Strategy | Algorithms selected on the fly |
| Template Method | Define skeleton of an algorithm, deferring some steps |
| Visitor | Separate an algorithm from an object |

---

### 3.1 Chain of Responsibility Pattern

**Intent:** Avoid coupling sender-of-request to its receiver by giving more than one object a chance to handle the request. Chain receiving objects and pass request along until an object handles it.

**Key Idea:** The set of potential handlers and the order in which they form the chain can be decided dynamically at runtime.

**Participants:**

| Participant | Role |
|---|---|
| **Handler** | Receives request; dispatches to chain; has reference only to first handler |
| **ConcreteHandler** | Handles requests it is responsible for; if can't handle, forwards to successor |
| **Client** | Initiates request to a ConcreteHandler object on the chain |

**Example — Transaction Approval:**

```java
abstract class TransactionProcessor {
    private TransactionProcessor successor;
    
    abstract protected Double getApprovalLimit();
    abstract protected String getDesignation();
    
    public void setSuccessor(TransactionProcessor tp) { this.successor = tp; }
    
    public void approve(Transaction t) {
        if (t.getAmount() <= getApprovalLimit())
            System.out.println("Approved by " + getDesignation());
        else if (successor != null)
            successor.approve(t);
        else
            System.out.println("Amount exceeds all limits!");
    }
}

class Manager extends TransactionProcessor {
    protected Double getApprovalLimit() { return 100000.0; }
    protected String getDesignation() { return "manager"; }
}
class VicePresident extends TransactionProcessor {
    protected Double getApprovalLimit() { return 1000000.0; }
    protected String getDesignation() { return "Vice President"; }
}
class CEO extends TransactionProcessor {
    protected Double getApprovalLimit() { return 2500000.0; }
    protected String getDesignation() { return "CEO"; }
}

// Setting up the chain
Manager manager = new Manager();
VicePresident vp = new VicePresident();
CEO ceo = new CEO();
manager.setSuccessor(vp);
vp.setSuccessor(ceo);
manager.approve(new Transaction(50000.0, "general"));
```

**Consequences:**

- ✅ Reduced coupling — objects are free from knowing which object handles the request
- ✅ Added flexibility in assigning responsibilities (can change chain at runtime)
- ❌ Receipt not guaranteed — request could fall off the chain
- ❌ Hard to observe runtime characteristics and debug

**Real Uses:** Windows event handling (mouse clicks, keyboard events); Java exception handling chain

---

### 3.2 Command Pattern

**Intent:** Encapsulate a request in an object, which allows:

- Parameterization of clients with different requests
- Saving requests in a queue
- Support for undo operations

**Participants:**

| Participant | Role |
|---|---|
| **Command** | Interface declaring `execute()` method |
| **ConcreteCommand** | Defines binding between Receiver and action; implements `execute()` |
| **Client** | Creates Command object and sets its Receiver |
| **Invoker** | Asks the Command to carry out a request |
| **Receiver** | Knows how to perform the actual operation |

**Collaborations:**

1. Client creates ConcreteCommand and specifies its Receiver
2. Invoker stores the ConcreteCommand
3. Invoker issues request by calling `execute()` on the command
4. ConcreteCommand invokes operations on its Receiver

**Example — Stock Orders:**

```java
interface Order { void execute(); }

class Stock {
    void buy() { System.out.println("Stock bought"); }
    void sell() { System.out.println("Stock sold"); }
}

class BuyStock implements Order {
    private Stock stock;
    BuyStock(Stock stock) { this.stock = stock; }
    public void execute() { stock.buy(); }
}

class SellStock implements Order {
    private Stock stock;
    SellStock(Stock stock) { this.stock = stock; }
    public void execute() { stock.sell(); }
}

class Broker { // Invoker
    private List<Order> orderList = new ArrayList<>();
    void takeOrder(Order order) { orderList.add(order); }
    void placeOrders() {
        for (Order order : orderList) order.execute();
        orderList.clear();
    }
}
```

**Applicability:**

- Parameterize objects by actions (callback mechanism)
- Specify, queue, and execute requests at different times
- Support undo functionality
- Transaction-based applications

**Consequences:**

- ✅ Decouples invoker from receiver
- ✅ Commands are first-class objects
- ✅ Easy to add new commands
- ✅ Commands can be assembled into composite commands
- ❌ Large number of classes/objects working together
- ❌ Every individual command is a separate ConcreteCommand class

---

### 3.3 Interpreter Pattern

**Intent:** Given a language, define a representation for its grammar along with an interpreter that uses the representation to interpret sentences in the language.

**Motivation:** Define a domain-specific language; provide a way to evaluate sentences in that language.

**Participants:**

| Participant | Role |
|---|---|
| **AbstractExpression** | Declares an interface for executing an operation |
| **TerminalExpression** | Implements Interpret for terminal symbols; one instance per terminal symbol |
| **NonterminalExpression** | One class per rule in the grammar; implements Interpret recursively |
| **Context** | Contains information global to the interpreter |
| **Client** | Builds abstract syntax tree; invokes the Interpret operation |

**Example — Algebraic Expressions:**

```
Expression: (2 + 6) + (1 + 9)
Model as:
AddExpression(
    AddExpression(ConstantExpression(2), ConstantExpression(6)),
    AddExpression(ConstantExpression(1), ConstantExpression(9))
)
```

**Applications:**

- **Regular Expressions** — Parsing and executing regex patterns
- **SQL Queries** — Parsing and executing SQL
- **Mathematical Expressions** — Evaluating formulas
- **Programming Languages** — Script interpreters, run-time code

**Consequences:**

- ✅ Flexibility to implement complex grammars
- ✅ Extensible — easy to add new expressions
- ✅ Separation of parsing and execution logic
- ❌ Complexity — complex grammars lead to complex code
- ❌ Performance — interpreting at run-time is slower than compiling
- ❌ Maintenance difficulty if language/expressions change frequently

---

### 3.4 Iterator Pattern

**Intent:** Provide a way to **access elements of an aggregate object sequentially** without exposing its underlying implementation.

**Motivation:**

- Encapsulation — hides internal details from client code
- Abstraction — provides a uniform way to access elements
- Separation of concerns — separates management of collections from their usage
- Lazy evaluation — elements computed/retrieved only when needed
- Multiple traversal support — traverse a collection multiple times without resetting

**Participants:**

| Participant | Role |
|---|---|
| **Iterator (AbstractIterator)** | Defines interface for accessing and traversing elements |
| **ConcreteIterator** | Implements Iterator; tracks current position in traversal |
| **Aggregate (AbstractCollection)** | Defines interface for creating an Iterator object |
| **ConcreteAggregate (Collection)** | Implements the Iterator creation interface |

**Implementation Steps:**

1. Declare the iterator interface (at minimum: `hasNext()`, `next()`)
2. Declare the collection interface with a method for fetching iterators
3. Implement concrete iterator classes linked with a single collection instance
4. Implement the collection interface in your collection classes
5. Replace all collection traversal code with iterators in client code

**Consequences:**

- ✅ Improved code flexibility
- ✅ Better encapsulation
- ✅ Simplified client code
- ✅ Can iterate over same collection in parallel (each iterator has its own state)
- ❌ Performance overhead for small collections
- ❌ Overkill if app only works with simple collections

**Advantages:**

- **Single Responsibility Principle** — Clean up client code by extracting traversal into separate classes
- **Open/Closed Principle** — Implement new types of collections/iterators without breaking existing code

---

## 4. ANTI-PATTERNS

### What is an Anti-Pattern?

> "An AntiPattern is a literary form that describes a commonly occurring solution to a problem that generates decidedly **negative consequences**."

Anti-patterns are "Negative Solutions" — solutions that present more problems than they address.

### Anti-Patterns vs. Design Patterns

| | Design Pattern | Anti-Pattern |
|---|---|---|
| Nature | General repeatable solution to common problems | Such a solution recognized as a poor way to solve the problem |
| Outcome | Positive | Negative |
| Action | Apply the pattern | Refactor the solution |

### Why Study Anti-Patterns?

- Provide easily identifiable templates for common problems
- Provide real-world experience in recognizing recurring problems
- Provide a common vocabulary for identifying problems and discussing solutions
- Ensure common problems are not continually repeated

### Three Major Viewpoints

| Viewpoint | Focus |
|---|---|
| **Development Anti-Patterns** | Situations encountered by programmer when solving programming problems |
| **Architectural Anti-Patterns** | Common problems in system structure; their consequences and solutions |
| **Management Anti-Patterns** | Common problems due to software organization; affects all roles |

---

### Reference Model

**Root Causes (Seven Deadly Sins of Software Development):**

| Root Cause | Description |
|---|---|
| **Haste** | Tight deadlines lead to neglecting important activities |
| **Apathy** | Attitude of not caring about solving known problems |
| **Narrow-Mindedness** | Refusal of developers to learn proven solutions |
| **Sloth** | Adaptation of the most simple "solution" |
| **Avarice** | Greed in creating a system — very complex, difficult to maintain software |
| **Ignorance** | Lack of motivation to understand things |
| **Pride** | Failure to reuse existing software packages (not invented here) |

**Primal Forces (Key Decision Motivators):**

- Management of Functionality
- Management of Performance
- Management of Complexity
- Management of Change
- Management of IT Resources
- Management of Technology Transfer

---

### 4.1 Project Management Anti-Pattern: Analysis Paralysis

**Problem:** Over-analysis; spending too much time in the analysis phase without making progress to design/implementation.

**Symptoms and Consequences:**

- Multiple project restarts and model rework due to personnel changes
- Design and implementation issues continually reintroduced in analysis phase
- Cost of analysis exceeds expectation without predictable end point
- Analysis no longer involves user interaction — mostly speculative
- Complex analysis models result in intricate, difficult-to-maintain implementations

**Typical Causes:**

- Management assumes waterfall progression (complete all analysis before design)
- More confidence in analyzing than in designing and implementing
- Goals in analysis phase not well defined
- Project vision diffused — analysis goes beyond providing meaningful value
- Unwillingness to make firm decisions about when domain areas are sufficiently described

**Refactored Solution:** Incremental development

- **Internal increment** — Builds software essential to implementation infrastructure (e.g., third-tier database); minimizes rework
- **External increment** — Comprises user-visible functionality
- Virtually all systems are built incrementally even if not acknowledged in the formal process

---

### 4.2 Architecture Anti-Pattern: Vendor Lock-In

**Problem:** A software project adopts a product technology and becomes completely dependent on the vendor's implementation.

**Symptoms and Consequences:**

- Commercial product upgrades drive the application software maintenance cycle
- Promised product features delayed or never delivered
- Product varies significantly from advertised open systems standard
- Missed product upgrades may require repurchase and reintegration

**Typical Causes:**

- Product selected based entirely on marketing/sales information without technical inspection
- No technical approach for isolating application software from direct product dependency
- Application programming requires in-depth product knowledge
- Complexity of product technology greatly exceeds application needs

**Refactored Solution — Isolation Layer:**

- An isolation layer separates software packages and technology
- Applicable when: isolating from infrastructure changes, more convenient programming interface needed, consistent handling needed across systems, multiple infrastructures must be supported

---

### 4.3 Development Anti-Pattern: The Blob

**Problem:** Procedural-style design leads to **one object with a lion's share of the responsibilities**, while most other objects only hold data or execute simple processes.

**Background:** A single complex controller class surrounded by simple data classes; majority of responsibilities allocated to a single class.

**Symptoms and Consequences:**

- Single class with a large number of attributes and operations (60+ is a warning sign)
- Disparate collection of unrelated attributes and operations — lack of cohesiveness
- Too complex for reuse and testing
- May be expensive to load into memory even for simple operations

**Typical Causes:**

- Lack of object-oriented architecture
- Lack of any architecture
- Lack of architecture enforcement
- Specified disaster (incremental growth without restructuring)

**Refactored Solution:**

1. **Step 1:** Identify and categorize related attributes/operations according to contracts (cohesive sets related to a common focus)
2. **Step 2:** Look for "natural homes" for contract-based collections and migrate them there
3. **Step 3:** Remove all "far-coupled" or redundant indirect associations
4. **Step 4:** Migrate associations to derived classes to a common base class
5. **Step 5:** Remove all transient associations, replacing them as appropriate with type specifiers

---

## 5. Summary — Design Pattern Quick Reference

### Creational Patterns

| Pattern | Problem | Solution |
|---|---|---|
| Singleton | Ensure only one instance | Private constructor + static getInstance() |
| Factory Method | Defer object creation | Define interface; subclasses decide which class to instantiate |
| Builder | Complex object construction | Separate construction from representation using Director + Builder |
| Prototype | Create object without knowing class | Clone existing prototype object |

### Structural Patterns

| Pattern | Problem | Solution |
|---|---|---|
| Adapter | Incompatible interfaces | Wrap existing class in adapter to match target interface |
| Facade | Complex subsystem | Provide simple unified interface |
| Proxy | Control access to object | Placeholder that delegates to real object |
| Flyweight | Too many fine-grained objects | Share intrinsic state; pass extrinsic state externally |

### Behavioral Patterns

| Pattern | Problem | Solution |
|---|---|---|
| Chain of Responsibility | Multiple potential handlers | Pass request along chain until handled |
| Command | Decouple invoker from receiver | Encapsulate request as object |
| Interpreter | Domain-specific language | Define grammar and interpreter |
| Iterator | Sequential access to collection | Separate traversal from aggregate |

### Anti-Patterns Summary

| Anti-Pattern       | Category     | Core Problem                       | Solution                              |
| ------------------ | ------------ | ---------------------------------- | ------------------------------------- |
| Analysis Paralysis | Management   | Too much analysis; no progress     | Incremental development               |
| Vendor Lock-In     | Architecture | Dependency on specific vendor      | Isolation layer abstraction           |
| The Blob           | Development  | One class has all responsibilities | Distribute responsibilities; refactor |
