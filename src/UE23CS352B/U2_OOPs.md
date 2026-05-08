# Unit 2: Object-Oriented Programming and Architecture Design

---

## 1. Introduction to Java and OOP

### Java Features

| Feature | Description |
|---|---|
| Simple | No header files, pointer arithmetic, structures, unions, operator overloading |
| Object-Oriented | Data (objects) and interfaces to objects are the focus |
| Distributed | Extensive library for TCP/IP protocols (HTTP, FTP) |
| Robust | Inbuilt exception handling and memory management |
| Secure | Enables virus-free, tamper-free systems |
| Portable | No "implementation-dependent" aspects; fixed sizes for primitive data types |
| Interpreted | Bytecode executed by JVM; line-by-line interpretation |
| High-Performance | JIT (Just-In-Time) compiler translates bytecode to machine code at runtime |

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

### First Java Program

```java
public class Test {
    public static void main(String[] args) {
        System.out.println("My Java First Program");
    }
}
// Save as: Test.java
// Compile: javac Test.java
// Run: java Test
```

---

## 2. OOP Core Concepts

### 1. Abstraction

- Representing essential features without including background details
- In Java: achieved using **abstract classes** and **interfaces**
- Interfaces allow **100% abstraction** (complete abstraction)
- Classes using data abstraction are called **Abstract Data Types (ADT)**

```java
abstract class Animal {
    public abstract void animalSound(); // Abstract method
    public void sleep() {
        System.out.println("Zzz");      // Concrete method
    }
}
class Dog extends Animal {
    @Override
    public void animalSound() {
        System.out.println("The dog says: bow bow");
    }
}
```

**Abstract Class rules:**

- Declared with `abstract` keyword
- Cannot be instantiated
- Can have both abstract and concrete methods
- Must declare as abstract if it contains at least one abstract method
- Can have constructors, static methods, and final methods

### 2. Encapsulation

- Wrapping up of data and functions into a single unit (class)
- Data is not accessible to the outside world — only wrapped functions can access it
- This insulation is called **data hiding** or **information hiding**

**Advantages:**

- Data Hiding (restricts direct access)
- Increased Flexibility (read-only or write-only variables)
- Reusability
- Easy to test (unit testing)
- Freedom for implementation details

```java
class Person {
    private String name; // private = restricted access
    public String getName() { return name; }       // Getter
    public void setName(String newName) { this.name = newName; } // Setter
}
```

### 3. Composition

- Design technique to implement the **"has-a"** relationship
- An object contains a composed object, and the composed object cannot exist without the other
- "Favor Composition over Inheritance"

```java
class Engine {
    void start() { System.out.println("Engine started"); }
}
class Car {
    private Engine engine = new Engine(); // Engine created inside Car — strong ownership
    void drive() {
        engine.start();
        System.out.println("Car is moving");
    }
}
```

**Benefits of Composition:**

- Code reuse
- Multiple inheritance via composition
- Better testability
- Allows replacing composed class implementation at runtime

---

## 3. Classes and Objects in Java

### Class

- A blueprint or template for creating objects
- Defines what an object will **have** (attributes) and **do** (methods)

```java
class Student {
    int rollNo;           // attribute
    String name;          // attribute
    void display() {      // method
        System.out.println(rollNo + " " + name);
    }
}
```

### Object

- A real-world entity created from a class
- Represents a specific instance of a class occupying memory
- Created with the `new` keyword; accessed via the dot (`.`) operator

**An Object has three things:**

- **Identity** — Unique reference (e.g., `s1`)
- **State** — Values of attributes (e.g., `rollNo`, `name`)
- **Behavior** — Methods it can perform (e.g., `display()`)

```java
Student s1 = new Student();
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

## 4. Constructors and Destructors

### Constructors in Java

- Initializes an object when it is created
- Same name as the class; no explicit return type
- All classes have a default constructor automatically if none is defined

**Types:**

1. **Default Constructor** — No parameters; provides default values (0, false, null)
2. **Parameterized Constructor** — Accepts parameters to initialize fields
3. **Copy Constructor** — Creates a copy of an object

```java
class Student {
    Student() { /* default constructor */ }
    Student(String name) { /* parameterized */ }
}
Student obj = new Student();
```

### Destructors in Java

- No explicit "destructor" in Java (unlike C++)
- Java uses **automatic garbage collection**
- `finalize()` method — called by garbage collector before an object is reclaimed (deprecated after Java 9)
- **Better alternatives:** try-with-resources, AutoCloseable interface, Explicit cleanup methods

### Destructors in C++

- Destructor name is `~ClassName()`
- Called automatically when object goes out of scope
- Critical for managing resources (memory, file handles, network sockets)

```cpp
class MyClass {
    int* ptr;
public:
    MyClass(int value) { ptr = new int(value); }
    ~MyClass() { delete ptr; } // Freeing memory
};
```

---

## 5. Inheritance

### Definition

- One of the core features of OOP
- New classes (derived/child/subclass) are created from existing classes (base/parent/superclass)
- Type of relationship: **Is-a relationship**
- Key Concept: Write common code once in a Parent Class; extend in Child Classes

### Types of Inheritance

| Type | Description |
|---|---|
| **Single Inheritance** | One parent, one child |
| **Multiple Inheritance** | One child, multiple parents (Not supported in Java with classes; use interfaces) |
| **Multilevel Inheritance** | A chain: A → B → C |
| **Hierarchical Inheritance** | One parent, multiple children |
| **Hybrid Inheritance** | Combination of types |

### Single Inheritance Example (Java)

```java
class Engineer {
    String name;
    int yearsOfExperience;
    void work() { /* ... */ }
}
class SoftwareEngineer extends Engineer {
    String programmingLanguage;
    void code() { /* ... */ }
}
```

### `super` Keyword

- Used to refer to the immediate parent class
- Invokes the constructor of the parent class

### Diamond Problem (Multiple Inheritance)

- Ambiguity when a class inherits from two classes that both derive from a common base class
- **Java solution:** Avoids diamond problem by not allowing multiple inheritance with classes; uses **interfaces** instead
- **C++ solution:** Uses **virtual inheritance**

### Advantages of Inheritance

- Code Reusability
- Code Organization
- Simplifies Modifications
- Extensibility
- Data Hiding
- Method Overriding

### Java vs. C++ Inheritance

| Aspect | Java | C++ |
|---|---|---|
| Syntax | `class Child extends Parent` | `class Child : public Parent` |
| Multiple Inheritance | Via interfaces only | Directly with classes |
| Diamond Problem | Avoided through interfaces | Handled through virtual inheritance |
| Constructor Call | `super()` | Initializer list |

---

## 6. Polymorphism

### Definition

> Polymorphism = "many forms" — the ability of an object or function to take on multiple forms.

### Types of Polymorphism

| Type | Also Known As | Achieved By | Binding |
|---|---|---|---|
| **Compile-Time** | Static Binding | Method Overloading, Operator Overloading | Early (compile time) |
| **Run-Time** | Dynamic Binding | Method Overriding, Virtual Functions | Late (runtime) |

### Method Overloading (Static/Compile-Time Polymorphism)

- Multiple methods with the same name but different parameter lists (number, type, or order)
- **Cannot** overload by return type alone

```java
class Calculator {
    int add(int a, int b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
    double add(double a, double b) { return a + b; }
}
```

### Method Overriding (Dynamic/Run-Time Polymorphism)

- A subclass provides a specific implementation of a method defined in its parent class
- Method in subclass must have the **same name, return type, and parameters** as parent
- `@Override` annotation (Java) — ensures correctness; catches errors at compile-time
- `virtual` keyword (C++) — marks method as one that can be overridden

```java
class Animal {
    void sound() { System.out.println("Animal makes a sound"); }
}
class Dog extends Animal {
    @Override
    void sound() { System.out.println("Dog barks"); }
}
```

### GRASP Types of Polymorphism

1. **Ad-hoc (Overloading)** — same name, different types
2. **Parametric (Early Binding / Generics)** — same code for different types
3. **Inclusion (Subtyping)** — derived class used through base class reference (Runtime polymorphism)
4. **Coercion (Casting)** — object or primitive cast into another type (implicit widening / explicit cast)

---

## 7. Interfaces

### Definition

- An interface defines a **contract** that classes must adhere to
- Contains method declarations (signatures) without implementations
- Classes implementing the interface must provide implementations

### Java Interfaces

| Feature | Interface | Abstract Class |
|---|---|---|
| Instantiation | Cannot be instantiated | Cannot be instantiated |
| Methods | Only abstract (Java 8+: default, static, private) | Abstract + concrete methods |
| Constructors | None | Can have |
| Fields | Only `public static final` constants | Can have instance variables |
| Inheritance | `implements` (class), `extends` (interface) | `extends` |
| Multiple inheritance | Supported (implement multiple) | Not directly |
| Purpose | Specifies contract of behavior | Base class with partial implementation |

```java
interface Animal {
    void makeSound();         // abstract by default
    default void breathe() {  // default method (Java 8+)
        System.out.println("Breathing");
    }
}
class Dog implements Animal {
    @Override
    public void makeSound() { System.out.println("Woof"); }
}
```

### C++ Interfaces

- C++ does not have built-in support for interfaces
- Simulated using **abstract classes** with only **pure virtual functions**

```cpp
class IAnimal {
public:
    virtual void makeSound() = 0; // Pure virtual function
};
class Dog : public IAnimal {
public:
    void makeSound() override { cout << "Woof" << endl; }
};
```

### `final` Keyword (Java)

| Applied to | Effect |
|---|---|
| Variable | Value cannot be changed (constant) |
| Method | Cannot be overridden by subclass |
| Class | Cannot be extended (e.g., Integer, Float) |

---

## 8. OO Development Process

### Phases

1. **OO Analysis (OOA)** — Identify system requirements & objects; Use Case Diagrams & Class Diagrams
2. **OO Design (OOD)** — Define structure & relationships; Sequence Diagrams; Class Diagrams
3. **OO Implementation (OOI)** — Code using OOP languages (Java, C++, Python)
4. **OO Testing (OOT)** — Unit, Integration, and System Testing
5. **OO Maintenance (OOM)** — Fix bugs, improve performance, extend features

### Benefits of OOD Process

- **Modularity** — Objects are independent and reusable
- **Reusability** — Classes and components can be reused
- **Scalability** — Easy to add new features
- **Maintainability** — Code is easier to update and debug

---

## 9. System Design and Frameworks

### System Architecture Activities

1. Estimating performance ("back of the envelope" calculations)
2. Making a Reuse plan
3. Breaking system into sub-systems
4. Identifying Concurrency
5. Allocation of Sub Systems to hardware
6. Managing data storage
7. Handling global resources
8. Choosing a software control strategy
9. Handling boundary conditions
10. Setting trade-off priorities
11. Selecting an architectural style

### Reuse Plan

- **Patterns** — Best practice, timetested solution to a recurring problem
- **Libraries** — Collection of classes useful in many contexts
- **Frameworks** — Skeletal structure/ready-made architecture for applications

### Library vs. Framework

| Feature | Framework | Library |
|---|---|---|
| Control | Framework calls developer's code | Developer calls library functions |
| Structure | Provides predefined application skeleton | No predefined structure |
| Customization | Requires subclassing, follows structure | Flexible — use as needed |
| Examples | Spring Boot, Hibernate, Qt | Apache Commons, JUnit, Boost |

---

## 10. Architectural Patterns

### What are Architectural Patterns?

- Reusable solution to commonly occurring problems in software architecture
- Provide structured framework to design software systems
- Ensure scalability, maintainability, and efficiency

---

### 10.1 MVC (Model-View-Controller)

**Components:**

| Component | Responsibility | Example Technologies |
|---|---|---|
| **Model** | Manages data and business logic | MySQL, Spring Boot |
| **View** | Handles UI and presentation | React, Angular, JSP |
| **Controller** | Manages user inputs, updates Model and View | Spring MVC, Servlets |

**MVC Workflow:**

1. User interacts with the View
2. View sends user input to Controller
3. Controller processes input and interacts with Model
4. Model retrieves/updates data
5. Model notifies View when data changes
6. View updates UI with latest data

**Advantages:** Separation of concerns, Scalability, Reusability, Parallel Development, Better Testing

**Challenges:** Complexity for small apps, Steep learning curve, Performance overhead

---

### 10.2 Layered Architecture (N-Tier)

**Structure:** Each layer provides services to the next higher layer.

| Layer | Responsibility |
|---|---|
| **Presentation Layer (UI)** | User interfaces; what users access directly |
| **Business Logic Layer** | Business operations, validations, and logic |
| **Persistence Layer** | Communicates with database; ORM mapping |
| **Database Layer** | Stores all application data |

**Open Layer** — Allows higher layers to bypass it (performance gain, but tight coupling)

**Closed Layer** — Enforces strict layer-to-layer interaction (maintainability, loose coupling)

**Advantages:** Simple development, Easy testing, Fewer dependencies

**Disadvantages:** Difficult to scale, Single unit deployment, Performance degrades with growth

---

### 10.3 Client-Server Architecture

**Components:**

- **Client** — Requester; user-facing application that makes requests
- **Server** — Provider; processes requests and sends responses
- **Network** — Facilitates communication using protocols (HTTP, FTP, SMTP, SQL)
- **Middleware** — Intermediary providing authentication, logging, message queuing

**Communication:**

- **Stateful server** — Maintains a record (session) of requests from the client
- **Master-Slave Pattern** — Master listens, creates a slave to process each request

**Advantages:** Data integrity, Ease of access via UI, Platform independence, Maintainability

**Disadvantages:** Server overload risk, Single point of failure

---

### 10.4 Event-Driven Architecture (EDA)

**Definition:** Designed to orchestrate behavior around the production, detection, consumption of, and reaction to events.

**Key Components:**

- **Events** — Significant changes in state (e.g., "Order Placed", "Payment Processed")
- **Event Producers** — Components that generate events
- **Event Consumers** — Components that react to events
- **Event Brokers** — Manages event routing (Apache Kafka, RabbitMQ)

**EDA Patterns:**

- **Simple Event Processing** — Events occur independently and trigger immediate actions
- **Complex Event Processing (CEP)** — Multiple events analyzed together to detect patterns
- **Event Sourcing** — System stores every state change as an event

**Topologies:**

- **Mediator Topology** — Central mediator orchestrates multiple steps within an event
- **Broker Topology** — Events chain together without a central mediator

**Advantages:** Scalability, Flexibility and Agility, Responsiveness

**Disadvantages:** Complex tracking/debugging, Dependency on messaging systems, Event consistency challenges

---

### 10.5 Microkernel Architecture (Plug-in Architecture)

**Definition:** Natural pattern for implementing product-based applications; allows adding features as plug-ins to a core system.

**Two main components:**

- **Core System** — Minimal functionality required to make the system operational; basic business logic without custom code for special cases
- **Plug-in Modules** — Stand-alone, independent components with specialized processing, additional features, and custom code

**Registry** — Contains information about each plug-in module (name, data contract, remote access protocol)

**Examples:** Eclipse IDE, Web Browsers

**Advantages:** Easy reaction to changes in plug-in modules, Easier deployment, Easier testing, Good performance (only needed features)

**Disadvantages:** Not highly scalable, Requires thorough design analysis

---

### 10.6 Microservices Architecture

**Definition:** Breaks down complex applications into smaller, independently deployable services.

**Key Characteristics:**

- Each service has its own database
- Services communicate via APIs (REST, gRPC, messaging)
- Each service independently deployable and scalable
- Can use different programming languages per service

**Microservices Design Principles:**

1. Scalability
2. Flexibility
3. Independent and autonomous
4. Decentralized governance
5. Resiliency
6. Failure isolation
7. Continuous delivery through DevOps

**Patterns:**

- **Database per Microservice** — Ensures independence
- **API Gateway** — Single entry point; acts as reverse proxy

**Advantages:** Scalability, Faster Development, Fault Isolation, Technology Flexibility, Improved Maintainability

**Disadvantages:** Increased Complexity, Network Latency, Data Consistency Challenges, Security Risks, Higher Infrastructure Costs

**When to Use:** Large complex applications (Netflix, Amazon, Uber), High scalability needs, Multiple development teams

**When NOT to Use:** Small applications/MVPs, Simple fast development needed, Team lacks DevOps expertise
