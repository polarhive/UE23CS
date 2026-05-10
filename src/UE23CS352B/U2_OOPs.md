# Unit 2: Object-Oriented Programming and Architecture Design

---

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

