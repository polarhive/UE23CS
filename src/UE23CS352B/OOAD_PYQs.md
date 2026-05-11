# OOAD — Previous Year Questions with Answers

**PES University | UE18CS353 / UE19CS353 / UE20CS352 / UE23CS352B**

> Papers covered: Dec 2023, Jul 2023, May 2023, Jan–May 2024, Jun/Jul 2008, Jun–Jul 2009
> ⚠️ PDFs 4, 6, 8, 9 were image-based — questions from those are not included

---

## TABLE OF CONTENTS

1. [OOP Core Concepts — 4 Pillars](#1-oop-core-concepts)
2. [Constructors, Garbage Collection & Object Class](#2-constructors-garbage-collection--object-class)
3. [Inheritance & Method Overriding](#3-inheritance--method-overriding)
4. [Method Overloading](#4-method-overloading)
5. [Abstract Class & Interface](#5-abstract-class--interface)
6. [Static & Instance Members / Output Tracing](#6-static--instance-members--java-output-tracing)
7. [Generics & Collections](#7-generics--collections)
8. [Java Code Writing Questions](#8-java-code-writing-questions)
9. [Use Case Diagrams](#9-use-case-diagrams)
10. [Class Diagrams — Relationships & Notation](#10-class-diagrams--relationships--notation)
11. [Class Diagrams — Case Study Modeling](#11-class-diagrams--case-study-modeling)
12. [Component Diagrams](#12-component-diagrams)
13. [Deployment Diagrams](#13-deployment-diagrams)
14. [Activity Diagrams](#14-activity-diagrams)
15. [Sequence Diagrams](#15-sequence-diagrams)
16. [State Diagrams](#16-state-diagrams)
17. [Class Identification](#17-class-identification)
18. [GRASP Design Principles](#18-grasp-design-principles)
19. [SOLID Design Principles](#19-solid-design-principles)
20. [Architectural Patterns](#20-architectural-patterns)
21. [Creational Design Patterns](#21-creational-design-patterns)
22. [Structural Design Patterns](#22-structural-design-patterns)
23. [Behavioral Design Patterns](#23-behavioral-design-patterns)
24. [Anti-Patterns](#24-anti-patterns)
25. [SDLC Models & Requirements Engineering](#25-sdlc-models--requirements-engineering)
26. [Software Testing & Quality](#26-software-testing--quality)
27. [Software Maintenance, DevOps & Configuration Management](#27-software-maintenance-devops--configuration-management)
28. [OO Development — Historical / Broad Concepts](#28-oo-development--historical--broad-concepts)
29. [Quick Reference — Topic Frequency](#quick-reference--topic-frequency)

---

## 1. OOP Core Concepts

> **Frequency: Very High** — appears in almost every paper

---

**Q1.** Elucidate the four main pillars — Abstraction, Encapsulation, Inheritance and Polymorphism — of Object Oriented Programming in two to three lines each.

`[8 M | May 2023 | UE19CS353]`

> **Answer:**
>
> **1. Abstraction:** Representing essential features of a real-world entity without including background details or implementation specifics. In Java, achieved using abstract classes and interfaces. Example: A `Car` interface exposes `drive()` without revealing engine internals.
>
> **2. Encapsulation:** Wrapping data (attributes) and methods (behavior) into a single unit (class), and restricting direct access to internal state using access modifiers (`private`, `protected`). External code interacts only through public getter/setter methods — also called **data hiding**. Example: `private String name;` accessed via `getName()` and `setName()`.
>
> **3. Inheritance:** Mechanism by which one class (child/subclass) acquires the properties and behaviors of another class (parent/superclass), establishing an **IS-A relationship** and enabling code reuse. Syntax in Java: `class Dog extends Animal`. Types: Single, Multilevel, Hierarchical, Hybrid (via interfaces).
>
> **4. Polymorphism** ("many forms"): Ability of an object or method to take multiple forms.
> - *Compile-time (Static):* Method Overloading — same name, different parameters.
> - *Runtime (Dynamic):* Method Overriding — subclass redefines parent method; resolved at runtime via dynamic dispatch.

---

**Q2.** Briefly describe Abstraction, Inheritance and Polymorphism concepts of Object Oriented Programming.

`[6 M | Jan–May 2024 | UE19CS353]`

> **Answer:**
>
> **Abstraction:** Hiding implementation details and exposing only the essential interface. In Java, achieved via abstract classes (`abstract class Shape { abstract void draw(); }`) and interfaces. Allows users to work with objects without knowing how they work internally.
>
> **Inheritance:** Enables a new class (subclass) to reuse fields and methods of an existing class (superclass) using `extends`. Promotes code reusability and establishes a parent-child IS-A relationship. E.g., `class Dog extends Animal` — Dog inherits `eat()` from Animal and may override `sound()`.
>
> **Polymorphism:** An object can behave differently in different contexts.
> - *Overloading:* `add(int, int)` and `add(double, double)` — resolved at compile time.
> - *Overriding:* `Animal ref = new Dog(); ref.sound();` prints "Woof" — resolved at runtime.

---

**Q3.** Write briefly about the Analysis and Design phases in the OO Approach. Distinguish OO from Procedure-Oriented approach.

`[6 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> **OO Analysis (OOA):** Identify real-world objects, their attributes, relationships, and interactions from requirements. Produces use case diagrams and class diagrams. Focus: *What* the system must do.
>
> **OO Design (OOD):** Translates analysis model into a blueprint for implementation. Defines class hierarchies, interactions (sequence diagrams), and applies design patterns. Focus: *How* the system will do it.
>
> | Aspect | Procedure-Oriented | Object-Oriented |
> |---|---|---|
> | Primary focus | Functions/procedures | Objects (data + behavior) |
> | Data | Shared globally or passed around | Encapsulated within objects |
> | Access | Data can be accessed by any function | Controlled via access modifiers |
> | Approach | Top-down | Bottom-up |
> | Reuse | Limited (function libraries) | High (inheritance, composition) |
> | Example languages | C, FORTRAN, COBOL | Java, C++, Python |

---

**Q4.** How does OO development differ from traditional software development? List advantages of OO development.

`[10 M | Jun/Jul 2008 | MCA51]`

> **Answer:**
>
> **Differences:**
> - Traditional (Procedure-Oriented): Focuses on functions that operate on data; data and functions are separate; uses top-down decomposition.
> - OO: Focuses on objects that combine data and behavior; uses bottom-up design; models real-world entities directly.
>
> **Advantages of OO Development:**
> 1. **Real-Life Entity Representation** — Directly models real-life entities using objects.
> 2. **Modularity** — Objects are self-contained; each encapsulates its own state and behavior.
> 3. **Reusability** — Classes and components can be reused via inheritance and composition.
> 4. **Scalability** — Easy to add new features (extend classes) without modifying existing code.
> 5. **Maintainability** — Encapsulation limits side-effects; easier to isolate and fix bugs.
> 6. **Improved Software Quality** — Enforces encapsulation and abstraction for cleaner code.
> 7. **Concurrent Development** — Teams can work on different classes simultaneously.
> 8. **Modules Tolerant of Changes** — Encapsulation allows changes without affecting external interfaces.
> 9. **Decreased Software Costs** — Modular and reusable structure reduces maintenance costs.
> 10. **Natural Mapping** — Problem domain concepts map directly to solution domain objects.

---

**Q5.** Discuss object-oriented software development.

`[10 M | Jun/Jul 2008 | MCA51]`

> **Answer:**
>
> OO software development is an approach that models both the problem and solution domains using **objects** — entities that combine state (attributes) and behavior (methods).
>
> **Core Concepts:** Class, Object, Encapsulation, Inheritance, Polymorphism, Abstraction.
>
> **Development Phases:**
> 1. **OO Analysis (OOA):** Identify objects, classes, attributes, operations, and relationships. Tools: Use Case Diagrams, Class Diagrams, CRC Cards.
> 2. **OO Design (OOD):** Define system architecture, class hierarchies, and collaborations. Tools: Sequence Diagrams, Component Diagrams.
> 3. **OO Implementation (OOI):** Code classes in OO language (Java, C++, Python).
> 4. **OO Testing (OOT):** Unit, integration, and system testing.
>
> **Methodology Features:**
> - Uses **UML** (Unified Modeling Language) from OMG as standard notation.
> - Encourages reuse through design patterns and frameworks.
> - Supports iterative and incremental development.
> - Asks: What are the objects? What are their responsibilities and relationships? How do they behave over time?

---

**Q6.** What are the main advantages of object-oriented development?

`[8 M | Jun–Jul 2009 | CS72]`

> **Answer:** (See Q4 — advantages apply here as well.)
>
> Key advantages in brief: Real-world entity mapping, Encapsulation (data hiding), Inheritance (code reuse), Polymorphism (flexibility), Modularity, Scalability, Maintainability, Concurrent team development, Reusable patterns and frameworks, Natural representation of problem domain.

---

**Q7.** With suitable examples explain: i) Object and Identity. ii) Static and dynamic binding of objects.

`[8 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **i) Object and Identity:**
> An **object** is an instance of a class — it has state (attribute values), behavior (methods), and identity.
> **Identity** is what distinguishes one object from another, even if they have identical attribute values. In Java, each object has a unique reference (memory address).
> ```java
> Student s1 = new Student("Alice");
> Student s2 = new Student("Alice");
> System.out.println(s1 == s2); // false — different identity even with same data
> ```
>
> **ii) Static Binding (Early Binding):**
> The method call is resolved at **compile time**. Occurs with overloaded methods, private, static, and final methods.
> ```java
> class Calculator {
>     int add(int a, int b) { return a + b; }
>     double add(double a, double b) { return a + b; }
> }
> // Compiler decides which add() to call based on argument types
> ```
>
> **Dynamic Binding (Late Binding):**
> The method call is resolved at **runtime** based on the actual object type. Occurs with overridden methods (polymorphism).
> ```java
> Animal a = new Dog(); // reference is Animal, object is Dog
> a.sound();            // resolved at runtime → calls Dog's sound(), not Animal's
> ```

---

**Q8.** State the reason why the given code prints **false**. Also change the code so that output is **true**.

`[5 M | Dec 2023 | UE20CS352]`

> **Answer:**
>
> **Reason it prints `false`:** The `equals()` method in the `Object` class (which `Classdemo` inherits) compares **object references (memory addresses)**, not content. `objOne` and `objTwo` are two different objects in memory, so `==` (internally used by default `equals()`) returns `false`.
>
> **Fix — Override `equals()` to compare content:**
> ```java
> public class MainClass {
>     public static void main(String[] args) {
>         Classdemo objOne = new Classdemo(10, 20);
>         Classdemo objTwo = new Classdemo(10, 20);
>         System.out.println(objOne.equals(objTwo)); // now prints true
>     }
> }
> class Classdemo {
>     int a; int b;
>     Classdemo(int a, int b) { this.a = a; this.b = b; }
>
>     @Override
>     public boolean equals(Object obj) {
>         if (this == obj) return true;
>         if (!(obj instanceof Classdemo)) return false;
>         Classdemo other = (Classdemo) obj;
>         return this.a == other.a && this.b == other.b;
>     }
> }
> ```
> `@Override equals()` compares field values `a` and `b`, so two objects with the same values will return `true`.

---

**Q9.** For the code snippet — add required functionalities to `student` class for Line 1 output, and predict Line 2 output.

`[6 M | May 2023 | UE19CS353]`

> **Answer:**
>
> **Line 1** requires a parameterized constructor and an overridden `toString()`:
> ```java
> class student {
>     int srn;
>     String name;
>     student(int srn, String name) { this.srn = srn; this.name = name; }
>
>     @Override
>     public String toString() {
>         return "SRN of the student is " + srn + " and name is " + name;
>     }
> }
> ```
>
> **Line 1 output:** `SRN of the student is 10 and name is pranitha`
> (When an object is passed to `println()`, its `toString()` is called automatically.)
>
> **Line 2 prediction:** `false`
> `s1 == s2` compares **references** (memory addresses). `s1` and `s2` are two different objects with different addresses. Without overriding `equals()`, this always returns `false`.

---

## 2. Constructors, Garbage Collection & Object Class

> **Frequency: Very High**

---

**Q10.** Which are the three types of constructors that can be defined in Java? Give examples for each.

`[6 M | Dec 2023 | UE19CS353]`

> **Answer:**
>
> **1. Default Constructor** — No parameters. Java provides one automatically if no constructor is defined. Sets fields to default values (0, null, false).
> ```java
> class Student {
>     int id; String name;
>     Student() { } // default constructor
> }
> Student s = new Student(); // id=0, name=null
> ```
>
> **2. Parameterized Constructor** — Accepts arguments to initialize fields. Uses `this` to avoid name conflict with parameters.
> ```java
> class Student {
>     int id; String name;
>     Student(int id, String name) { this.id = id; this.name = name; }
> }
> Student s = new Student(1, "Alice");
> ```
>
> **3. Copy Constructor** — Creates a new object by copying another object of the same class. Prevents unwanted reference sharing.
> ```java
> class Student {
>     int id; String name;
>     Student(Student s) { this.id = s.id; this.name = new String(s.name); }
> }
> Student s1 = new Student(1, "Alice");
> Student s2 = new Student(s1); // copy
> ```

---

**Q11.** What is the need for constructors in Java? Explain default and parameterized constructors with an example.

`[6 M | Jan–May 2024 | UE19CS353]`

> **Answer:**
>
> **Need for Constructors:** A constructor initializes an object's fields to valid, meaningful values at the time of creation. Without a constructor, objects might have garbage or null values, leading to runtime errors. Constructors ensure the object is in a **fully formed, usable state** right after creation. They run automatically when `new` is called.
>
> **Default Constructor:**
> ```java
> class Rect {
>     int a, b;
>     Rect() {
>         System.out.println("Default constructor called");
>         // a and b default to 0
>     }
> }
> Rect r = new Rect(); // Output: Default constructor called
> System.out.println(r.a); // 0
> ```
>
> **Parameterized Constructor:**
> ```java
> class Student {
>     int id; String name;
>     Student(int id, String name) {  // 'this' resolves name conflict
>         this.id = id;
>         this.name = name;
>     }
>     void display() { System.out.println(id + " " + name); }
> }
> Student s = new Student(101, "Alice");
> s.display(); // Output: 101 Alice
> ```

---

**Q12.** Briefly describe the need of garbage collector in Java.

`[4 M | Dec 2023 | UE19CS353]`

> **Answer:**
>
> **Need for Garbage Collector (GC):**
> In Java, objects are created dynamically on the heap using `new`. When an object is no longer referenced by any variable, it becomes **unreachable** — it is occupying memory but can never be used again. If such objects are not removed, the heap fills up, causing **OutOfMemoryError**.
>
> The **Garbage Collector** is a background JVM process that:
> 1. Identifies objects not referenced by any active part of the program.
> 2. Automatically deallocates ("frees") their memory.
> 3. Reclaims heap space for new object allocation.
>
> **Key points:**
> - Unlike C/C++, Java developers do not need to manually `free()` or `delete` memory.
> - `System.gc()` can suggest GC, but execution is not guaranteed.
> - `finalize()` method (deprecated since Java 9) was called by GC before reclaiming an object.
>
> **Example:** After `s = null;`, the object previously referenced by `s` becomes eligible for GC.

---

**Q13.** Write the output of the following Java program.

`[4 M | Dec 2023 | UE19CS353]`

> **Answer:**
> ```java
> class A { void show() { System.out.println("show of class A"); } }
> class B extends A {
>     void show() { System.out.println("show of class B"); }
>     void disp() { System.out.println("show of class B disp"); }
> }
> class supertest1 {
>     public static void main(String args[]) {
>         A aobj = new A(); B bobj = new B(); A refa;
>         refa = aobj;  refa.show();  // refa points to A object
>         refa = bobj;  refa.show();  // refa points to B object → runtime polymorphism
>         if (refa instanceof B) { ((B) refa).disp(); }
>     }
> }
> ```
>
> **Output:**
> ```
> show of class A
> show of class B
> show of class B disp
> ```
> **Explanation:**
> - `refa = aobj` → `refa.show()` calls A's `show()`.
> - `refa = bobj` → `refa.show()` calls B's `show()` (dynamic dispatch — runtime polymorphism).
> - `refa instanceof B` → true (refa points to a B object) → cast and call `disp()`.

---

## 3. Inheritance & Method Overriding

> **Frequency: Very High**

---

**Q14.** What is inheritance? Explain different types of inheritance in Java with an example for each.

`[6 M | Dec 2023 | UE19CS353]`

> **Answer:**
>
> **Inheritance:** Mechanism by which a subclass acquires the fields and methods of a superclass. Establishes an **IS-A relationship**. Promotes code reuse. Syntax: `class Child extends Parent`.
>
> **Types:**
>
> **1. Single Inheritance** — One child inherits from one parent.
> ```java
> class Animal { void eat() { System.out.println("eating"); } }
> class Dog extends Animal { void bark() { System.out.println("barking"); } }
> ```
>
> **2. Multilevel Inheritance** — A chain: A → B → C.
> ```java
> class Animal { void eat() {} }
> class Dog extends Animal { void bark() {} }
> class BabyDog extends Dog { void weep() {} }
> // BabyDog inherits eat() and bark()
> ```
>
> **3. Hierarchical Inheritance** — One parent, multiple children.
> ```java
> class Animal { void eat() {} }
> class Dog extends Animal { void bark() {} }
> class Cat extends Animal { void meow() {} }
> ```
>
> **4. Multiple Inheritance (via interfaces)** — Java does not support with classes (diamond problem).
> ```java
> interface A { void show(); }
> interface B { void display(); }
> class C implements A, B { public void show(){} public void display(){} }
> ```
>
> **5. Hybrid Inheritance** — Combination. Achieved partially via interfaces in Java.

---

**Q15.** Explain any two different types of inheritance in Java with an example for each.

`[4 M | Jan–May 2024 | UE19CS353]`

> **Answer:** (Pick two from Q14 — typically Single and Multilevel are asked.)
>
> **Single Inheritance:**
> ```java
> class Employee { float salary = 40000; }
> class Programmer extends Employee {
>     int bonus = 10000;
>     public static void main(String[] args) {
>         Programmer p = new Programmer();
>         System.out.println("Salary: " + p.salary);  // 40000.0
>         System.out.println("Bonus: " + p.bonus);    // 10000
>     }
> }
> ```
>
> **Multilevel Inheritance:**
> ```java
> class A { void methodA() { System.out.println("A"); } }
> class B extends A { void methodB() { System.out.println("B"); } }
> class C extends B { void methodC() { System.out.println("C"); } }
> // C inherits methodA() from A and methodB() from B
> C obj = new C(); obj.methodA(); obj.methodB(); obj.methodC();
> ```

---

**Q16.** State any six differences between abstract class and interface.

`[6 M | Jul 2023 | UE19CS353]`

> **Answer:**
>
> | Feature | Abstract Class | Interface |
> |---|---|---|
> | Keyword | `abstract class` | `interface` |
> | Instantiation | Cannot be instantiated | Cannot be instantiated |
> | Methods | Can have abstract + concrete methods | All abstract by default (default/static from Java 8) |
> | Variables | Can have instance variables | Only `public static final` constants |
> | Constructors | ✅ Can have constructors | ❌ No constructors |
> | Multiple Inheritance | A class can extend only ONE abstract class | A class can implement MULTIPLE interfaces |
> | Access Modifiers | Methods can be any access level | Methods are `public` by default |
> | Purpose | Partial abstraction — provides base with some implementation | Full abstraction — defines a pure contract |
> | `this` keyword | Allowed | Not applicable |
> | Inheritance | Uses `extends` | Class uses `implements`; interface uses `extends` |

---

**Q17.** Briefly describe Abstraction, Inheritance and Polymorphism. *(See Q2)*

`[6 M | Jan–May 2024 | UE19CS353]`

> **Answer:** Refer to Q2.

---

## 4. Method Overloading

> **Frequency: High**

---

**Q18.** State any four differences between Method Overloading and Method Overriding.

`[4 M | Dec 2023 | UE20CS352]`

> **Answer:**
>
> | Feature | Method Overloading | Method Overriding |
> |---|---|---|
> | Definition | Same method name, different parameter lists in the **same class** | Subclass redefines a method from the **parent class** with same name and parameters |
> | Binding | **Compile-time** (static/early binding) | **Runtime** (dynamic/late binding) |
> | Also called | Compile-time polymorphism | Runtime polymorphism |
> | Return type | Can differ (but not used alone to distinguish) | Must be same (or covariant) |
> | Parameters | Must differ (number, type, or order) | Must be exactly the same |
> | Inheritance | Not required | Requires IS-A relationship (inheritance) |
> | `@Override` | Not used | Used (recommended) |
> | Purpose | Increases readability; same operation on different data types | Provides specific implementation; extends/replaces parent behavior |

---

**Q19.** Give examples for Method Overloading and Method Overriding. State the differences.

`[6 M | Jul 2023 | UE19CS353]`

> **Answer:**
>
> **Method Overloading:**
> ```java
> class Calculator {
>     int add(int a, int b) { return a + b; }
>     double add(double a, double b) { return a + b; }
>     int add(int a, int b, int c) { return a + b + c; }
> }
> ```
> Compiler decides which `add()` to call based on argument types — compile-time polymorphism.
>
> **Method Overriding:**
> ```java
> class Bank { int getRateOfInterest() { return 0; } }
> class SBI extends Bank {
>     @Override
>     int getRateOfInterest() { return 8; }
> }
> Bank b = new SBI();
> b.getRateOfInterest(); // returns 8 — runtime polymorphism
> ```
>
> **Differences:** See Q18 table.

---

**Q20.** Write short notes on: Method Overloading, Static and Instance members in a class, Abstract class.

`[8 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> **Method Overloading:** Multiple methods with the same name but different parameter signatures in the same class. Resolved at compile-time. Increases readability and flexibility. Example: `print(int)`, `print(String)`, `print(double)`.
>
> **Static vs Instance Members:**
> - **Instance variables/methods:** Belong to each object; created fresh for each instance; accessed via object reference.
> - **Static variables/methods:** Belong to the class; shared across all instances; one copy in memory; accessed via class name or object.
> ```java
> class Counter {
>     static int count = 0;  // static — shared
>     int id;                 // instance — unique per object
>     Counter() { count++; id = count; }
> }
> ```
>
> **Abstract Class:** A class declared with `abstract` keyword that cannot be instantiated. Contains abstract methods (no body) that must be implemented by subclasses. Provides a common template for a family of classes while allowing each subclass to provide specific implementations. Example: `abstract class Shape { abstract double getArea(); }`.

---

**Q21.** Using method overloading, write a class `NextValue` with a method `getNextValue`.

`[4 M | May 2023 | UE20CS352]`

> **Answer:**
> ```java
> class NextValue {
>     int getNextValue(int n) {
>         return n + 1;
>     }
>     float getNextValue(float n) {
>         return n + 0.01f;
>     }
>     public static void main(String[] args) {
>         NextValue nv = new NextValue();
>         System.out.println(nv.getNextValue(5));     // 6
>         System.out.println(nv.getNextValue(3.14f)); // 3.1500001 (approx)
>         System.out.println(nv.getNextValue(10));    // 11
>         System.out.println(nv.getNextValue(2.5f));  // 2.51
>     }
> }
> ```
> The compiler resolves which `getNextValue()` to call at compile time based on the argument type (`int` or `float`).

---

## 5. Abstract Class & Interface

> **Frequency: High**

---

**Q22.** Elucidate the need for an abstract class and justify with an example.

`[6 M | Dec 2023 | UE20CS352]`

> **Answer:**
>
> **Need for Abstract Class:**
> - Provides a **generalized form/template** for a family of related classes.
> - Defines common attributes and some concrete behavior shared by all subclasses.
> - Declares abstract methods that **each subclass must implement** according to its own behavior.
> - Enforces a **contract** — any concrete subclass must provide implementations for all abstract methods.
> - Cannot be instantiated directly — prevents creating objects of the base "concept" class.
>
> **Example:**
> ```java
> abstract class Shape {
>     String color;
>     Shape(String color) { this.color = color; }
>
>     abstract double getArea();  // Each shape computes area differently — abstract
>
>     void displayColor() {       // Common concrete method shared by all shapes
>         System.out.println("Color: " + color);
>     }
> }
>
> class Circle extends Shape {
>     double radius;
>     Circle(String color, double radius) { super(color); this.radius = radius; }
>     @Override
>     double getArea() { return Math.PI * radius * radius; }
> }
>
> class Rectangle extends Shape {
>     double l, b;
>     Rectangle(String color, double l, double b) { super(color); this.l = l; this.b = b; }
>     @Override
>     double getArea() { return l * b; }
> }
> ```
> A `Shape` object alone makes no sense — you need a specific kind of shape. The abstract class enforces that each shape provides `getArea()`, while sharing `displayColor()`.

---

**Q23.** State any six differences between abstract class and interface. *(See Q16)*

`[6 M | Jul 2023 | UE19CS353]`

> **Answer:** Refer to Q16 table.

---

**Q24.** Write short notes on: Method Overloading, Static and Instance members, Abstract class. *(See Q20)*

`[8 M | Jul 2023 | UE20CS352]`

> **Answer:** Refer to Q20.

---

## 6. Static & Instance Members / Java Output Tracing

> **Frequency: Medium**

---

**Q25.** Give the output of the Java program `StaticDemo`.

`[5 M | Dec 2023 | UE20CS352]`

> **Answer:**
>
> **Output:**
> ```
> Inside static block
> Inside main
> x=5
> a=1
> b=2
> ```
>
> **Explanation (step by step):**
> 1. When the class is loaded, the **static block** executes first (before `main()`). It prints `"Inside static block"` and sets `b = a * 2 = 1 * 2 = 2`.
> 2. `main()` executes: prints `"Inside main"`.
> 3. `display(5)` is called: prints `x=5`, `a=1` (unchanged), `b=2` (set in static block).
>
> **Key rule:** Static blocks run **once** at class loading, before the `main()` method.

---

**Q26.** Write about the three access specifiers — private, protected, public — using one example class.

`[6 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> | Access Modifier | Same Class | Same Package | Subclass (diff pkg) | Everywhere |
> |---|---|---|---|---|
> | `public` | ✔ | ✔ | ✔ | ✔ |
> | `protected` | ✔ | ✔ | ✔ | ✗ |
> | `private` | ✔ | ✗ | ✗ | ✗ |
>
> ```java
> class Person {
>     public  String name;      // accessible everywhere
>     protected int age;        // accessible in same package and subclasses
>     private  String password; // accessible only within this class
>
>     public String getName() { return name; }           // public getter
>     public void setPassword(String p) { password = p; } // controlled write
>     private String getPassword() { return password; }   // private — internal only
> }
> ```
> External code can access `name` directly, access/modify `age` from same package or subclass, but cannot access `password` at all — it must go through `setPassword()`. This is **encapsulation**.

---

**Q27.** Is `Object o = new ArrayList<String>();` valid in Java? Justify.

`[2 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Yes, it is valid.** In Java, all classes inherit from `Object` (single-rooted hierarchy). Since `ArrayList` ultimately extends `Object`, a reference of type `Object` can hold any object reference.
>
> ```java
> Object o = new ArrayList<String>(); // valid — upcasting
> ```
>
> This is **upcasting** — assigning a more specific type (ArrayList) to a more general reference type (Object). The actual object in memory is still an `ArrayList<String>`. However, through reference `o`, you can only call methods defined in `Object` (like `toString()`, `equals()`) — not ArrayList-specific methods — unless you cast back: `((ArrayList<String>) o).add("hello")`.

---

## 7. Generics & Collections

> **Frequency: Medium**

---

**Q28.** What are Generic classes in Java? Write an example program demonstrating a generic class.

`[4–6 M | Dec 2023 | UE19CS353; Jan–May 2024 | UE19CS353]`

> **Answer:**
>
> **Generic Classes:** Classes parameterized by one or more types. Allow you to write a single class that works for different data types while still being type-safe. The type parameter is specified at the time of object creation. Denoted with angle brackets: `class Box<T>`.
>
> **Benefits:** Type safety (compiler catches type errors), Code reusability (one class for all types), Elimination of casting.
>
> ```java
> // Generic class with type parameter T
> class Box<T> {
>     private T value;
>
>     Box(T value) { this.value = value; }
>     T getValue() { return value; }
>
>     @Override
>     public String toString() { return "Box[" + value + "]"; }
> }
>
> public class Main {
>     public static void main(String[] args) {
>         Box<Integer> intBox = new Box<>(42);
>         Box<String>  strBox = new Box<>("Hello");
>         Box<Double>  dblBox = new Box<>(3.14);
>
>         System.out.println(intBox.getValue()); // 42
>         System.out.println(strBox.getValue()); // Hello
>         System.out.println(dblBox.getValue()); // 3.14
>     }
> }
> ```
> Without generics, you would need separate `IntBox`, `StringBox` classes, or use `Object` (requiring unsafe casts).

---

## 8. Java Code Writing Questions

> **Frequency: High**

---

**Q29.** Write code to add required functionality — Employee with two constructors, Manager extends Employee, Manager has a team list.

`[6 M | Jul 2023 | UE20CS352]`

> **Answer:**
> ```java
> class Employee {
>     private String name;
>     private String dept;
>
>     Employee(String name) { this.name = name; this.dept = "Unknown"; }
>     Employee(String name, String dept) { this.name = name; this.dept = dept; }
>
>     public String getName() { return name; }
>     public String getDept() { return dept; }
>
>     @Override
>     public String toString() { return "Employee[" + name + ", " + dept + "]"; }
> }
>
> class Manager extends Employee {
>     private List<Employee> teamMembers = new ArrayList<>();
>
>     Manager(String name, String dept) { super(name, dept); }
>
>     void addTeamMember(Employee e) { teamMembers.add(e); }
>
>     void showDetails() {
>         System.out.println("Manager: " + getName() + " | Dept: " + getDept());
>         System.out.println("Team Members:");
>         for (Employee e : teamMembers) {
>             System.out.println("  " + e);
>         }
>     }
> }
> ```

---

**Q30.** Write Java code for SHIELD/Avengers scenario — Mission with `addAvenger()` and `showMission()`.

`[8 M | May 2023 | UE20CS352]`

> **Answer:**
> ```java
> import java.util.*;
>
> class Avengers {
>     String name, weapon;
>     int strength;
>     Avengers(String name, String weapon, int strength) {
>         this.name = name; this.weapon = weapon; this.strength = strength;
>     }
>     @Override
>     public String toString() { return name + " " + weapon + " " + strength; }
> }
>
> class Mission {
>     String name, location;
>     int strengthReq;
>     List<Avengers> assigned = new ArrayList<>();
>
>     Mission(String name, String location, int strengthReq) {
>         this.name = name; this.location = location; this.strengthReq = strengthReq;
>     }
>
>     void addAvenger(List<Avengers> all) {
>         for (Avengers a : all)
>             if (a.strength >= strengthReq) assigned.add(a);
>     }
>
>     void showMission() {
>         System.out.println(name + " " + location + " " + strengthReq);
>         for (Avengers a : assigned) System.out.println(a);
>     }
> }
> ```
> **Output:**
> ```
> Save the World New York 9
> Iron Man Suit 9
> Thor Hammer 10
> ```

---

## 9. Use Case Diagrams

> **Frequency: Very High**

---

**Q31.** Write a use case diagram for an Online Shopping website.

`[6 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> **Actors:** Customer, Admin, Payment Gateway (Bank)
>
> **Use Cases:**
> - Register/Login
> - Browse Products
> - Search Products
> - Add to Cart
> - Place Order (includes → Make Payment)
> - Make Payment (extended by: Apply Coupon)
> - Track Order
> - Cancel Order
> - Write Review
> - Manage Products (Admin)
> - Manage Orders (Admin)
> - Process Payment (Payment Gateway)
>
> **Relationships:**
> - `Place Order` **<<include>>** `Make Payment` (payment is mandatory for placing order)
> - `Make Payment` **<<extend>>** `Apply Coupon` (optional coupon application)
> - `Register` **<<extend>>** `Login` (new user must register first; existing users just login)
> - Customer **generalizes** into Guest Customer and Registered Customer
>
> **Diagram description:**
> ```
> System boundary: Online Shopping System
> [Customer] ──── Browse Products
>            ──── Search Products
>            ──── Add to Cart
>            ──── Place Order ──<<include>>──► Make Payment
>            ──── Track Order                      │
>            ──── Cancel Order          <<extend>>──► Apply Coupon
>            ──── Write Review
> [Admin]    ──── Manage Products
>            ──── Manage Orders
> [Bank]     ──── Process Payment ◄──── Make Payment
> ```

---

**Q32.** Draw a use case diagram for an e-commerce website.

`[6 M | Dec 2023 | UE19CS353]`

> **Answer:** Same as Q31 — the e-commerce use case diagram covers: Actors (Customer, Admin, Bank), use cases (Browse, Search, Add to Cart, Place Order, Make Payment, Track Order, Cancel Order, Review, Manage Products), and relationships (<<include>> for payment in order, <<extend>> for coupon, generalization for customer types).

---

**Q33.** Draw a use case diagram for a Railway Reservation System.

`[6 M | Dec 2023 | UE20CS352]`

> **Answer:**
>
> **Actors:** Passenger, Bank, System Admin
>
> **Use Cases & Relationships:**
> ```mermaid
> flowchart LR
>  P(("Passenger"))
>  B(("Bank"))
>  A(("Admin"))
>  Login(Login)
>  CAT(Check Available Trains)
>  BT(Book Ticket)
>  SS(Select Seat)
>  MP(Make Payment)
>  VP(Validate Payment)
>  CT(Cancel Ticket)
>  VH(View Booking History)
>  PC(Process Cancellation)
>  UT(Update Train Info)
>  MU(Manage Users)
>  P --> Login & CAT & BT & CT & VH
>  B --> VP
>  A --> PC & UT & MU
>  BT -- "<<include>>" --> MP
>  BT -- "<<extend>>" --> SS
>  MP -- "<<include>>" --> VP
> ```
> **Key relationships:**
> - `Book Ticket` **<<include>>** `Make Payment` (always required)
> - `Book Ticket` **<<extend>>** `Select Seat` (optional seat selection)
> - `Make Payment` **<<include>>** `Validate Payment` (Bank involvement)

---

**Q34.** Draw a use case diagram for railway reservation system similar to IRCTC.

`[6 M | Jul 2023 | UE19CS353]`

> **Answer:** Same as Q33. Add: PNR status check, Tatkal booking (extends Book Ticket), cancellation refund process, Admin can view reports. Actors include: Passenger, Agent, Admin, Bank.

---

**Q35.** Identify use cases and actors for Passport Automation System and depict with a Use Case diagram.

`[8 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> **Actors:** Applicant, Passport Administrator, Regional Administrator (MEA), Police
>
> **Use Cases:**
> 1. Login to System
> 2. Submit Application Details
> 3. Apply for ECNR Status (<<extend>> from Submit Details — optional)
> 4. Verify Application (Passport Administrator)
> 5. Forward to Regional Administrator
> 6. Police Verification
> 7. Approve/Reject Application
> 8. Issue Passport
>
> **Relationships:**
> - `Submit Application` **<<include>>** `Login`
> - `Apply for ECNR` **<<extend>>** `Submit Application` (optional)
> - `Issue Passport` **<<include>>** `Police Verification` and `Verify Application`
> - Generalization: `Passport Administrator` and `Regional Administrator` both specialize `Administrator`
>
> ```mermaid
> flowchart LR
>  Applicant(("Applicant"))
>  PA(("Passport Admin"))
>  RA(("Regional Admin"))
>  Police(("Police"))
>  L(Login)
>  SA(Submit Application)
>  ECNR(Apply for ECNR)
>  VA(Verify Application)
>  PE(Process ECNR)
>  AA(Approve Application)
>  PV(Police Verification)
>  IP(Issue Passport)
>  Applicant --> L & SA
>  ECNR -- "<<extend>>" --> SA
>  PA --> VA & PE
>  RA --> AA
>  Police --> PV
>  IP -- "<<include>>" --> AA
>  IP -- "<<include>>" --> PV
> ```

---

**Q36.** Draw a Use Case diagram for a Movie Ticket Booking System.

`[8 M | May 2023 | UE19CS353]`

> **Answer:**
>
> **Actors:** Customer, Admin, Bank
>
> **Use Cases:**
> ```mermaid
> flowchart LR
>  C(("Customer"))
>  B(("Bank"))
>  A(("Admin"))
>  L(Login) CSM(Check Streaming) CUM(Check Upcoming)
>  BT(Book Ticket) MP(Make Payment) CS(Choose Seat)
>  VP(Validate Payment) CT(Cancel Ticket) PR(Provide Review)
>  PC(Process Cancellation) UM(Update Movie Info)
>  C --> L & CSM & CUM & BT & CT & PR
>  A --> PC & UM
>  B --> VP
>  BT -- "<<include>>" --> MP
>  BT -- "<<extend>>" --> CS
>  MP -- "<<include>>" --> VP
> ```
> - `Book Ticket` **<<include>>** `Make Payment` (mandatory)
> - `Book Ticket` **<<extend>>** `Choose Seat` (optional)
> - `Make Payment` **<<include>>** `Validate Payment` (Bank validates)

---

**Q37.** Draw a use case diagram for ATM machine.

`[6 M | Jan–May 2024 | UE19CS353]`

> **Answer:**
>
> **Actors:** Customer, Bank Server
>
> **Use Cases:**
> ```mermaid
> flowchart LR
>  C(("Customer"))
>  BS(("Bank Server"))
>  Auth(Authenticate)
>  CB(Check Balance)
>  WC(Withdraw Cash)
>  DC(Deposit Cash)
>  TF(Transfer Funds)
>  CP(Change PIN)
>  PMS(Print Mini Statement)
>  VA(Validate Account)
>  AT(Authorize Transaction)
>  UB(Update Balance)
>  C --> CB & WC & DC & TF & CP & PMS
>  BS --> VA & AT & UB
>  WC & DC & TF & CP -- "<<include>>" --> Auth
> ```
> **Relationships:**
> - All transactions **<<include>>** `Authenticate` (PIN entry is always required)
> - `Deposit Cash` **<<extend>>** `Print Receipt` (optional receipt)
> - `Withdraw Cash` **<<extend>>** `Print Receipt` (optional)

---

**Q38.** Consider a library management system. Draw a use case diagram with at least 3 actors and 5 use cases.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Actors:** Student/Member, Librarian, Admin
>
> **Use Cases:**
> 1. Search Book
> 2. Borrow Book (<<include>> → Check Availability)
> 3. Return Book
> 4. Pay Fine (<<extend>> from Return Book — if overdue)
> 5. Reserve Book
> 6. Add New Book (Librarian)
> 7. Remove Book (Admin)
> 8. Generate Reports (Admin/Librarian)
>
> **Significance of <<extend>>:** The `Pay Fine` use case extends `Return Book` — it only occurs if the book is returned after the due date. This models optional/conditional behavior without modifying the base use case.

---

**Q39.** Identity the relationship (include/extend/generalization) between these pairs of use cases.

`[6 M | May 2023 | UE19CS353]`

> **Answer:**
>
> 1. **Create new order ← <<include>> → Validate customer account:** `<<include>>` — validating the customer account is a mandatory step whenever a new order is created.
>
> 2. **Update order ← <<include>> → Validate customer account:** `<<include>>` — validation is also required for updating an order (same mandatory behavior, shared via include).
>
> 3. **Place order ← <<include>> → Login:** `<<include>>` — a customer must always be logged in to place an order (mandatory precondition).
>
> 4. **Login account ← <<extend>> → Change password:** `<<extend>>` — changing password is optional behavior that may occur after login, not every time. It extends login conditionally.
>
> 5. **Choose folder ← <<include>> → Upload document:** `<<include>>` — you must choose a folder before uploading (mandatory step in the process).
>
> 6. **Purchase item ← generalization ← Purchase phone / Purchase accessories:** `Generalization` — `Purchase phone` and `Purchase accessories` are specializations of the more general `Purchase item` use case.

---

**Q40.** What is a use case? Explain UML activity diagram with a neat figure.

`[10 M | Jun/Jul 2008 | MCA51]`

> **Answer:**
>
> **Use Case:** A description of a set of sequences of actions a system performs to yield an observable result of value to an actor. A use case captures the functional requirements of a system from the user's perspective. Name always starts with a verb (e.g., "Place Order", "Withdraw Cash").
>
> **UML Activity Diagram:** A behavioral diagram that visually presents a series of actions or flow of control — similar to a flowchart but with additional concurrency constructs.
>
> **Key notations:**
>
> | Symbol | Meaning |
> |---|---|
> | Filled black circle | Initial state (start) |
> | Circle inside circle | Final state (end) |
> | Rounded rectangle | Activity/Action |
> | Arrow | Control flow (transition) |
> | Diamond | Decision/Merge (branching) |
> | Thick bar | Fork (split parallel) / Join (merge parallel) |
> | Swimlane | Partition by actor/responsibility |
>
> **Example (Online Purchase):**
> ```mermaid
> flowchart LR
>  Start([●]) --> AC["Add to Cart"] --> PO["Place Order"]
>  PO --> D{Payment OK?}
>  D -- Yes --> CO["Confirm Order"] --> Stop1([◎])
>  D -- No --> CN["Cancel Order"] --> Stop2([◎])
> ```
> **Fork/Join (parallel) example:**
> ```mermaid
> flowchart LR
>  Fork(("Fork")) --> PP["Process Payment"]
>  Fork --> NC["Notify Customer"]
>  PP --> Join(("Join"))
>  NC --> Join
>  Join --> SO["Ship Order"]
> ```

---

## 10. Class Diagrams — Relationships & Notation

> **Frequency: Very High**

---

**Q41.** Elucidate qualified association and aggregation relationship w.r.t class diagram with an example for each.

`[6 M | Dec 2023 | UE19CS353]`

> **Answer:**
>
> **Qualified Association:**
> A form of association where a qualifier (key/discriminator) is used to select a specific object from a multivalued association. It reduces the multiplicity of the association by partitioning related objects using a qualifier attribute.
>
> ```
> Bank ─────[accountNo]─────► Account
> (1)                           (0..1)
> ```
> A `Bank` can have many `Account` objects, but with qualifier `accountNo`, one specific account is identified. Without qualifier: `Bank` to `Account` is 1 to *. With qualifier: `Bank` to `Account` is 1 to 0..1.
>
> **Aggregation ("has-a" — weak ownership):**
> A whole-part relationship where the part can **exist independently** of the whole. Shown with a **hollow diamond** on the "whole" side.
>
> ```
> University ◇──── Department
> (whole)          (part — can exist independently)
> ```
> If the University closes, the Department concept can still exist (join another university). A `Car ◇── Engine` — if the car is destroyed, the engine can be reused elsewhere.

---

**Q42.** Define the following w.r.t class diagram: Association, Aggregation, Composition, Multiplicity, Qualifier, Generalization.

`[6 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> **Association:** A structural relationship showing that objects of one class are connected to objects of another class. Can be unidirectional or bidirectional. Shown as a line between classes. E.g., `Student — Course` (a student takes courses).
>
> **Aggregation:** A special "has-a" association representing a whole-part relationship where the part can exist independently of the whole. Hollow diamond on the whole. E.g., `Library ◇── Book` (books can exist without the library).
>
> **Composition:** A strong "has-a" association where the part **cannot exist** without the whole (coincident lifetime). Filled diamond on the whole. E.g., `House ◆── Room` (rooms don't exist without the house).
>
> **Multiplicity:** Specifies how many instances of one class relate to one instance of another class. Notations: `1` (exactly one), `0..1` (zero or one), `*` (zero or many), `1..*` (one or many), `2..5` (between 2 and 5).
>
> **Qualifier:** An attribute used in a qualified association to select/partition a subset of related objects. Reduces multiplicity. Placed in a small box on the association line.
>
> **Generalization:** An inheritance relationship where a child class inherits attributes and operations from a parent class. "Is-a" relationship. Shown as a line with a **hollow triangle arrowhead** pointing to the parent. E.g., `Dog → Animal`.

---

**Q43.** Explain Association, Aggregation, Composition, Qualified Association in a line or two each.

`[4 M | Jan–May 2024 | UE19CS353]`

> **Answer:**
>
> **Association:** A general relationship between two classes meaning objects of one class are connected to objects of another. E.g., `Customer — Order`. Shown as a plain line.
>
> **Aggregation:** "Has-a" relationship; whole and part can exist independently. Hollow diamond on the whole side. E.g., `Team ◇── Player` (players can exist outside the team).
>
> **Composition:** Strong "has-a"; parts cannot exist without the whole; shared lifecycle. Filled diamond on the whole. E.g., `Order ◆── OrderItem` (order items exist only within an order).
>
> **Qualified Association:** An association with a qualifier key that selects one specific object from many. E.g., `Database ──[tableId]──► Table`. Reduces multiplicity by partitioning objects using the qualifier.

---

**Q44.** Differentiate between Aggregation and Composition.

`[4 M | Jul 2023 | UE19CS353]`

> **Answer:**
>
> | Feature | Aggregation | Composition |
> |---|---|---|
> | Relationship | Weak "has-a" | Strong "has-a" |
> | Lifecycle | Part can exist independently | Part cannot exist without the whole |
> | Diamond | Hollow ◇ | Filled ◆ |
> | Destruction | Destroying the whole does NOT destroy parts | Destroying the whole DESTROYS parts |
> | Example | `University ◇── Department` | `House ◆── Room` |
> | Ownership | Shared (part may belong to multiple wholes) | Exclusive (part belongs to one whole) |
> | Java | Whole holds a reference to part (created externally) | Whole creates/owns the part (created internally) |

---

**Q45.** Explain various types of relationships depicted between classes in a class diagram with an example.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **1. Association:** `Student ──── Course` — a student enrolls in courses; a bidirectional structural link.
>
> **2. Aggregation (weak whole-part):** `Department ◇──── Professor` — professors can exist without the department.
>
> **3. Composition (strong whole-part):** `Building ◆──── Floor` — floors cannot exist without the building.
>
> **4. Generalization (Inheritance):** `Animal ←△── Dog` — Dog IS-A Animal; inherits attributes and operations.
>
> **5. Realization (Interface):** `Flyable ←△-- Bird` (dashed) — Bird realizes the Flyable interface; commits to implementing its operations.
>
> **6. Dependency:** `OrderController --→ OrderService` (dashed arrow) — OrderController uses OrderService; a change in OrderService may affect OrderController.
>
> **7. Qualified Association:** `Bank ──[accNo]──► Account` — given an account number, exactly one account is identified.

---

**Q46.** What is an association? How do you identify associations? How to eliminate unnecessary associations?

`[8 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **Association:** A bidirectional semantic connection between two classes. It means instances of one class are related to instances of another. Shown as a solid line with optional role names, multiplicity, and direction.
>
> **Identifying Associations — Guidelines:**
> 1. Look for verbs/verb phrases in requirements: "is logged in by", "owns", "manages", "belongs to".
> 2. Look for physical or conceptual connections between objects.
> 3. Consider all interactions between objects in use cases and scenarios.
> 4. Look for communication paths, data flows, and dependencies.
>
> **Eliminating Unnecessary Associations:**
> 1. Remove associations that are not navigated in any scenario.
> 2. Eliminate redundant associations that can be derived from others (transitive associations).
> 3. Remove implementation-level associations (such as "passed as a parameter" in a method — these become dependencies, not associations).
> 4. Remove associations where multiplicity is always exactly 1:1 and can be folded into attributes.
> 5. Avoid associations between non-communicating classes.

---

**Q47.** Explain UML attribute presentation. Give complete UML class diagram for Via Net Bank system.

`[8 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **UML Attribute Presentation Format:**
> `[visibility] name [: type] [= defaultValue] [{property}]`
> - Visibility: `+` public, `-` private, `#` protected
> - Example: `- balance : double = 0.0`
> - Derived attribute (computed): `/ totalBalance : double`
> - Static attribute: underlined name
>
> **Via Net Bank System — Key Classes and Attributes:**
> ```mermaid
> classDiagram
>  class Customer {
>  -int customerId
>  -String name
>  -String address
>  +login()
>  +viewBalance()
>  +getStatement()
>  }
>  class Account {
>  -int accountNo
>  -double balance
>  -String type
>  +deposit()
>  +withdraw()
>  +getBalance()
>  }
>  class Transaction {
>  -int txnId
>  -double amount
>  -Date date
>  -String type
>  +process()
>  }
>  Customer "1" --> "*" Account : owns
>  Account "1" --> "*" Transaction : has
> ```

---

**Q48.** What are coupling and cohesion of objects or software components?

`[6 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **Coupling:** The degree of dependency between classes or modules. High coupling means changes in one class force changes in others (ripple effect), making the system fragile.
> - **Tight Coupling (Bad):** Class A directly instantiates Class B; accesses B's internals.
> - **Loose Coupling (Good):** Classes interact through well-defined interfaces; changes in one don't affect the other.
>
> **Cohesion:** The degree to which elements within a module/class belong together and serve a single, well-focused purpose.
> - **High Cohesion (Good):** Each class has one clear responsibility; all methods are related to that responsibility. Example: `InvoiceCalculator` only calculates invoice totals.
> - **Low Cohesion (Bad):** A class that handles user input, database operations, and business logic all in one — the "Blob" anti-pattern.
>
> **Goal:** Design for **High Cohesion + Low Coupling** for maintainable, testable, and reusable code.

---

## 11. Class Diagrams — Case Study Modeling

> **Frequency: High**

---

**Q49.** Draw a Class Diagram for a Course and Enrolment Management System.

`[6–8 M | May 2023 | UE20CS352; Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **Classes and Attributes:**
> ```mermaid
> classDiagram
>  class Department { +String name; +String code }
>  class Session { +String name; +Date startDate; +Date endDate }
>  class Semester { +int number; +int year }
>  class Section { +String sectionId }
>  class Student { +String srn; +String name; +Date dob }
>  class Course { +String courseId; +String name; +int credits; +boolean isElective }
>  class Enrolment { +int attendance; +int ISAMarks; +int ESAMarks; +String grade }
>  class Teacher { +String empId; +String name }
>  Department "1" --> "*" Session : manages
>  Session "1" --> "*" Semester : has
>  Semester "1" --> "*" Course : offers
>  Semester "1" --> "*" Section : has
>  Section "1" --> "60..*" Student : has
>  Student "*" --> "5" Course : via Enrolment
>  Enrolment .. Student
>  Enrolment .. Course
>  Teacher "*" --> "1" Section : assignedTo
>  Teacher "0..1" --> "1" Section : classTeacher
> ```
>
> **Key multiplicities:**
> - One Section has minimum 60 students: `Section 1 ──── 60..* Student`
> - Elective courses need min 20 enrolled: captured as constraint `{min 20}` on Enrolment
> - Teacher can be class teacher of at most one section: `0..1` multiplicity

---

**Q50.** Identify at least 6 classes from the Banking Network (ATM) case study.

`[6 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> **Identified Classes (from the case study):**
>
> 1. **Bank** — represents an individual bank in the consortium; attributes: bankId, name, computerAddress
> 2. **Account** — customer's bank account; attributes: accountNumber, balance, accountType
> 3. **Customer** — bank customer holding cash cards; attributes: customerId, name, cashCard
> 4. **ATM** — automatic teller machine; attributes: atmId, location; operations: acceptCard(), dispenseCash(), printReceipt()
> 5. **CashCard** — card used by customer at ATM; attributes: cardNumber, PIN, expiryDate
> 6. **Transaction** — a banking operation; attributes: transactionId, type, amount, date, status
> 7. **CentralComputer** — clears transactions between ATMs and banks; operations: clearTransaction(), validateCard()
> 8. **CashierStation** — human cashier terminal at a bank; operations: enterAccountData(), processTransaction()
>
> **Relationships:**
> - `Bank` aggregates `Account`
> - `Customer` owns `CashCard`
> - `ATM` communicates with `CentralComputer`
> - `CentralComputer` connects to many `Bank` computers
> - `Transaction` is associated with `Account`

---

**Q51.** For the given scenarios, choose appropriate diagram. Draw it.

i) Student–Faculty Advisor scenario. ii) Order–Item with total computation.

`[6 M | Jul 2023 | UE19CS353; Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **Scenario i) — Faculty Advisor:**
> **Chosen diagram: Class Diagram** — because it shows structural relationships (associations with multiplicity) between entities that have attributes and interact over time.
>
> ```mermaid
> classDiagram
>  class FacultyAdvisor {
>  +String empId
>  +String name
>  +String designation
>  }
>  class Student {
>  +String srn
>  +String name
>  +int semester
>  }
>  class Dean
>  class Chairperson
>  FacultyAdvisor <|-- Dean
>  FacultyAdvisor <|-- Chairperson
>  FacultyAdvisor "1" --> "25..*" Student : advises
> ```
> Note: Deans and Chairpersons (subclasses of FacultyAdvisor) have multiplicity 0 on the advises relationship — captured as a constraint or using generalization with an override.
>
> **Scenario ii) — Order–Item:**
> **Chosen diagram: Class Diagram** — shows composition relationship and a derived attribute.
>
> ```mermaid
> classDiagram
>  class Order {
>  +String orderId
>  +double totalAmount
>  }
>  class Item {
>  +String itemId
>  +int quantity
>  +double price
>  +double subTotal
>  }
>  Order "1" *-- "1..*" Item : composition
>  note for Order "totalAmount = Σ(item.quantity × item.price)"
> ```
> Composition (◆) because Items cannot exist without the Order; `/totalAmount` is a derived attribute.

---

**Q52.** In the given class model, which class should be responsible for computing total test marks? Based on which principle?

`[6 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> **Answer: The `Test` class should be responsible for computing total marks.**
>
> **Principle: GRASP — Information Expert**
> The Information Expert principle states: Assign responsibility to the class that has the information necessary to fulfill it. The `Test` class knows about all the `Question` objects it contains and each question's marks — so it is the Information Expert for computing the total.
>
> ```java
> class Question {
>     private int marks;
>     public int getMarks() { return marks; }
> }
>
> class Test {
>     private List<Question> questions;
>
>     public int getTotalMarks() {       // Information Expert — Test knows all questions
>         int total = 0;
>         for (Question q : questions)
>             total += q.getMarks();
>         return total;
>     }
> }
> ```

---

## 12. Component Diagrams

> **Frequency: Medium-High**

---

**Q53.** Describe in a line or two the following elements of component diagram: Port, Dependency, Component, Interface.

`[4 M | Dec 2023 | UE19CS353]`

> **Answer:**
>
> **Component:** A modular, replaceable, and executable part of a system that encapsulates its contents. It provides a set of interfaces and its internal implementation is hidden (black box). Depicted as a rectangle with the `«component»` stereotype or component icon.
>
> **Interface:** A contract that a component provides (provided interface — what it offers) or requires (required interface — what it needs from others). Provided interface shown as a lollipop (circle); required interface shown as a socket (half-circle).
>
> **Port:** An interaction point between a component and its external environment. Groups semantically related provided and required interfaces. Drawn as a small square on the boundary of the component. Public ports are on the boundary; protected/private ports are inside.
>
> **Dependency (Usage Dependency):** A relationship `<<use>>` showing that one component requires another component for its full implementation/operation. Shown as a dashed arrow from the dependent component to the component it depends on.

---

**Q54.** Draw a Component Diagram for ATM Components.

`[8 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> **ATM Component Diagram — Components and Relationships:**
>
> ```mermaid
> flowchart LR
>  subgraph ATM["ATM System"]
>  CR["⬜ CardReader<br/>«component»"]
>  AM["⬜ AuthenticationMgr<br/>«component»"]
>  TM["⬜ TransactionMgr<br/>«component»"]
>  CD["⬜ CashDispenser<br/>«component»"]
>  RP["⬜ ReceiptPrinter<br/>«component»"]
>  NI["⬜ NetworkInterface<br/>«component»"]
>  end
>  BS[("Bank Server")]
>  CR -->|ICardReader| AM
>  AM -->|IAuthenticate| TM
>  TM -->|IDispense| CD
>  TM -->|IPrint| RP
>  NI -->|IBankNetwork| BS
>  TM --> NI
> ```
>
> **Components:** CardReader, AuthenticationManager, TransactionManager, CashDispenser, ReceiptPrinter, NetworkInterface (connects to central bank server)
>
> **Interfaces:** `ICardReader` (provided by CardReader), `IAuthenticate` (provided by AuthMgr, required by TxnMgr), `IDispense` (provided by CashDispenser), `IBankNetwork` (provided by NetworkInterface)

---

**Q55.** Write about the elements in a Component Diagram. Represent in an example.

`[4 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Elements of a Component Diagram:**
>
> 1. **Component** — Modular unit with defined interfaces; encapsulates implementation; shown as rectangle with `<<component>>` stereotype.
> 2. **Provided Interface** — Lollipop notation (circle on a line); what the component offers to others.
> 3. **Required Interface** — Socket notation (half-circle); what the component needs from others.
> 4. **Port** — Entry/exit point for interactions; small square on boundary.
> 5. **Assembly Connector** — Connects a required interface of one component to a provided interface of another.
> 6. **Dependency** — Dashed arrow; `<<use>>` relationship.
> 7. **Node** — Physical hardware that hosts components (in deployment context).
>
> **Example (Web Application):**
> ```mermaid
> flowchart LR
>  Browser["Browser"] -- "<<use>>" --> WS["⬜WebServer - «component»"]
>  WS -- "IDatabase (required)" --> DB["⬜Database - «component»"]
>  WS -. "IHttpRequest (provided)" .- Browser
> ```

---

## 13. Deployment Diagrams

> **Frequency: Medium**

---

**Q56.** What are the different elements in a Deployment Diagram? Write notations in an example diagram.

`[6 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> **Elements of a Deployment Diagram:**
>
> 1. **Node** — A computational resource (server, device, PC, phone) upon which artifacts are deployed. Shown as a 3D box.
> 2. **Artifact** — A concrete physical piece of information used or produced by a software development process. Includes: executable files (.exe, .jar), libraries (.dll, .so), config files, database schemas. Shown as a rectangle with `<<artifact>>` stereotype.
> 3. **Component** — Deployed on nodes; shows which software component runs where.
> 4. **Association** — Communication path between nodes; can be labeled with the protocol used (HTTP, JDBC, TCP/IP).
> 5. **Deployment** — `<<deploy>>` relationship showing an artifact deployed on a node.
>
> **Example (3-tier Web Application):**
> ```mermaid
> flowchart LR
>  subgraph CN["Client Node"]
>  A1["«artifact»<br/>index.html"]
>  end
>  subgraph AS["App Server (Tomcat)"]
>  A2["«artifact»<br/>webapp.war"]
>  A3["«artifact»<br/>api.jar"]
>  end
>  subgraph DB["DB Server (MySQL)"]
>  A4["«artifact»<br/>schema.sql"]
>  end
>  CN -- "HTTP" --> AS
>  AS -- "JDBC" --> DB
> ```

---

## 14. Activity Diagrams

> **Frequency: High**

---

**Q57.** Develop an activity diagram for login of an application. At least 4 activities, all transitions.

`[8 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> **Actors/Swimlanes:** User, System
>
> **Activity Diagram (Login):**
> ```mermaid
> flowchart TD
>  Start([●]) --> Enter["Enter Username & Password"]
>  Enter --> Validate["Validate Credentials"]
>  Validate --> Valid{Credentials Valid?}
>  Valid -- Yes --> Session["Create Session"]
>  Valid -- No --> Attempt["Increment Attempt Count"]
>  Session --> Dashboard["Redirect to Dashboard"]
>  Attempt --> Max{Max Attempts?}
>  Max -- Yes --> Lock["Lock Account"]
>  Max -- No --> Error["Show Error Message"]
>  Error --> Enter
>  Dashboard --> Stop([◎])
>  Lock --> Stop
> ```
>
> **Activities:** Enter Credentials, Validate Credentials, Create Session, Increment Attempt, Lock Account, Redirect to Dashboard, Show Error Message

---

**Q58.** Draw an activity diagram to login and logout for a web-based application.

`[6 M | Jan–May 2024 | UE19CS353]`

> **Answer:**
>
> **Swimlanes: User | System**
>
> ```mermaid
> flowchart TD
>  Start([●]) --> Nav["Navigate to Login Page"]
>  Nav --> Enter["Enter Username & Password"]
>  Enter --> Val{Credentials Valid?}
>  Val -- Yes --> Sess["Create Session"] --> Dash["Display Dashboard"]
>  Val -- No --> Err["Show Error"] --> Enter
>  Dash --> Logout["Click Logout"]
>  Logout --> Inv["Invalidate Session"] --> Nav
>  Inv --> Stop([◎])
> ```
>
> **Key elements:**
> - Guard condition: `[credentials valid]` / `[credentials invalid]`
> - Decision diamond at validation step
> - Swimlanes separate User and System responsibilities
> - Start node (●) and End node (◎)

---

**Q59.** Draw an activity diagram for withdrawal operation in an ATM machine with swimlanes.

`[6 M | Dec 2023 | UE19CS353]`

> **Answer:**
>
> **Swimlanes: Customer | ATM | Bank System**
>
> ```mermaid
> flowchart TD
>  Start([●]) --> IC["Insert Card"]
>  IC --> EP["Enter PIN"]
>  EP --> VP{PIN Valid?}
>  VP -- No --> Err["Show Error / Return Card"] --> Stop1([◎])
>  VP -- Yes --> SW["Select Withdrawal"]
>  SW --> EA["Enter Amount"]
>  EA --> CB["Check Balance"]
>  CB --> SF{Sufficient Funds?}
>  SF -- No --> IF["Show Insufficient Funds"] --> Stop2([◎])
>  SF -- Yes --> DA["Debit Account"]
>  DA --> DC["Dispense Cash"]
>  DC --> PR["Print Receipt"]
>  PR --> RC["Return Card"]
>  RC --> Stop3([◎])
> ```
>
> **Events:** Card inserted, PIN entered, Amount selected, Balance checked, Cash dispensed

---

**Q60.** Draw an activity diagram for ticket purchasing at a ticket vending machine.

`[6 M | Jul 2023 | UE19CS353]`

> **Answer:**
>
> **Swimlanes: Commuter | Ticket Vending Machine | Bank**
>
> ```mermaid
> flowchart TD
>  Start([●]) --> STR["Select Ticket Type & Route"]
>  STR --> CPD["Calculate Payment Due"]
>  CPD --> DPO["Display Payment Options"]
>  DPO --> SPM{Cash or Card?}
>  SPM -- Cash --> IC["Insert Cash"] --> CCh["Calculate Change"] --> Join((""))
>  SPM -- Card --> SIC["Swipe / Insert Card"] --> Auth["Bank: Authorize Payment"]
>  Auth --> Authd{Authorized?}
>  Authd -- No --> Dec["Decline"] --> SIC
>  Authd -- Yes --> Join
>  Join --> IT["Issue Ticket"]
>  IT --> RC["Return Change / Card"]
>  RC --> Stop([◎])
> ```

---

**Q61.** Create an activity diagram for order fulfilment in an e-commerce system with swimlanes, fork and join.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Swimlanes: Customer | Order Department | Warehouse | Delivery**
>
> ```mermaid
> flowchart TD
>  Start([●]) --> PO["Place Order<br/>[Customer]"]
>  PO --> Proc["Process Order<br/>[Order Dept]"]
>  Proc --> Fork(("Fork"))
>  Fork --> Pick["Pick Items<br/>[Warehouse]"]
>  Fork --> Notify["Notify Customer<br/>[Order Dept]"]
>  Pick --> Pack["Pack Order<br/>[Warehouse]"]
>  Pack --> Join(("Join"))
>  Notify --> Join
>  Join --> Disp["Dispatch Order<br/>[Delivery]"]
>  Disp --> Del["Deliver Order<br/>[Delivery]"]
>  Del --> Conf["Confirm Delivery<br/>[Customer]"]
>  Conf --> Stop([◎])
> ```
>
> **Significance:** Swimlanes clarify who is responsible for each activity. Fork models parallelism (Pick Items and Notify Customer happen concurrently). Join synchronizes flows — dispatch only happens after both parallel activities complete.

---

**Q62.** Describe Activity and Object Flow elements of activity diagram with UML notation.

`[4 M | Dec 2023 | UE20CS352]`

> **Answer:**
>
> **Activity (Action State):**
> An action or step in a process representing a single, atomic behavior within the overall flow. Depicted as a **rounded rectangle** containing the activity name. Transitions (arrows) show the flow between activities. Example: `[Validate Login]`, `[Process Payment]`.
>
> **Object Flow:**
> Represents the creation, modification, or consumption of objects during activities. Depicted as a **dotted arrow** between an activity and an object node (rectangle). The object node shows the object and optionally its state (in brackets). Example:
> ```mermaid
> flowchart LR
>  PO["Place Order"] -. "object flow" .-> Ord["Order<br/>{placed}"]
>  Ord -. "object flow" .-> CO["Confirm Order"]
> ```
> Object flow makes explicit what data is being passed between activities, unlike control flow which just shows sequencing.

---

**Q63.** Explain UML activity diagram with different types of modeling.

`[10 M | Jun/Jul 2008 | MCA51]`

> **Answer:** Refer to Q40 and Q57 for activity diagram structure, notation, and example.
>
> **Types of Modeling in UML:**
> - **Structural Modeling** — static structure; Class Diagrams, Component Diagrams, Deployment Diagrams.
> - **Behavioral Modeling** — dynamic behavior; Use Case, Activity, State Diagrams.
> - **Interaction Modeling** — object collaboration; Sequence, Communication Diagrams.
>
> **Activity Diagram** falls under behavioral modeling. It describes the dynamic aspects of a system using the flow of control between activities. It is especially useful for modeling workflow, business processes, and algorithm logic.

---

**Q64.** Explain how an activity diagram aids in developing a use-case, using library member activities as example.

`[10 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **How Activity Diagrams Aid Use-Case Development:**
> 1. **Clarify complex flows** — A use case describes a goal; the activity diagram shows step-by-step how it's achieved.
> 2. **Identify alternate and exception flows** — Decision points in activity diagram highlight alternative paths.
> 3. **Reveal parallelism** — Fork/join constructs show concurrent activities not visible in text.
> 4. **Identify actors/swimlanes** — Swimlanes map activities to actors, helping refine who does what in the use case.
>
> **Example — Library Member: Borrow Book**
>
> ```mermaid
> flowchart TD
>  Start([●]) --> SB["Search for Book"]
>  SB --> RL["Request Loan"]
>  RL --> CA["Check Availability"]
>  CA --> Avail{Available?}
>  Avail -- No --> NU["Notify Unavailable"] --> OR["Offer Reservation"]
>  Avail -- Yes --> Rec["Record Loan"]
>  Rec --> UDB["Update DB"]
>  Rec --> HO["Hand Over Book"]
>  HO --> RB["Receive Book"]
>  RB --> Stop([◎])
> ```
>
> This activity diagram, derived from the "Borrow Book" use case, reveals the roles, decisions, and system interactions — making the use case more precise and testable.

---

## 15. Sequence Diagrams

> **Frequency: Medium-High**

---

**Q65.** Draw a sequence diagram for a phone calling application.

`[6 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> **Participants (Lifelines):** Caller, PhoneApp, Network, Receiver
>
> **Sequence:**
> ```mermaid
> sequenceDiagram
>  participant Caller
>  participant PhoneApp
>  participant Network
>  participant Receiver
>  Caller->>PhoneApp: dial(number)
>  PhoneApp->>Network: connect(number)
>  Network->>Receiver: ring()
>  Receiver-->>Network: answered()
>  Network-->>PhoneApp: answered()
>  PhoneApp-->>Caller: connected()
>  Note over Caller,Receiver: Voice Communication
>  Caller->>Receiver: hangUp()
>  Receiver-->>Network: terminate()
>  Network-->>PhoneApp: callEnded()
>  PhoneApp-->>Caller: callEnded()
> ```
>
> **Message Types:**
> - `dial()`, `connect()` — synchronous (filled arrowhead)
> - `ring()` — asynchronous (open arrowhead)
> - Return messages — dashed lines

---

**Q66.** Write UML sequence and collaboration diagrams for a telephone call.

`[8 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **Sequence Diagram:** See Q65 above.
>
> **Communication (Collaboration) Diagram:**
> Shows the same interactions as a sequence diagram but laid out as a graph with numbered messages.
>
> ```
>   Caller ──1: dial(number)──► PhoneApp
>          ◄──5: connected()──
>
>   PhoneApp ──2: connect(num)──► Network
>            ◄──4: answered()──
>
>   Network ──3: ring()──► Receiver
>           ◄──3.1: pickUp()──
>
>   Caller ──6: hangUp()──► Receiver (through network)
> ```
>
> **Key difference:** Sequence diagrams emphasize **time ordering** (vertical axis). Communication diagrams emphasize **object relationships** (spatial layout with numbered message arrows).

---

**Q67.** Develop sequence and collaboration diagrams for deposit/checking use-case — Via Net ATM.

`[6 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **Sequence Diagram (ATM Deposit):**
> ```mermaid
> sequenceDiagram
>  participant Customer
>  participant ATM
>  participant CentralComputer
>  participant Bank
>  Customer->>ATM: insertCard()
>  Customer->>ATM: enterPIN()
>  ATM->>CentralComputer: validatePIN()
>  CentralComputer->>Bank: verifyAccount()
>  Bank-->>CentralComputer: accValid()
>  CentralComputer-->>ATM: validated()
>  Customer->>ATM: enterAmount()
>  Customer->>ATM: depositCash()
>  ATM->>CentralComputer: recordDeposit()
>  CentralComputer->>Bank: updateBalance()
>  Bank-->>CentralComputer: updated()
>  ATM->>ATM: printReceipt()
>  ATM-->>Customer: receiptPrinted()
> ```

---

## 16. State Diagrams

> **Frequency: High**

---

**Q68.** Draw a state diagram for the book object in a library.

`[8 M | May 2023 | UE19CS353]`

> **Answer:**
>
> **States:** New, Available, OnLoan, Reserved, Overdue, Lost, Disposed
>
> **State Diagram:**
> ```mermaid
> stateDiagram-v2
>  [*] --> Available : catalogued
>  Available --> OnLoan : borrowed
>  OnLoan --> Available : returned (not overdue)
>  OnLoan --> Overdue : returned (overdue)
>  OnLoan --> Lost : 12 months overdue
>  Overdue --> Available : fine paid
>  Lost --> Available : book found
>  Available --> Disposed : damaged or not needed
>  Disposed --> [*]
> ```
>
> **Non-loanable books:** Remain in Available state forever (no borrow transition).

---

**Q69.** Draw a state diagram for the Transmission component of a Car.

`[4 M | Dec 2023 | UE20CS352]`

> **Answer:**
>
> **States:** Park (P), Reverse (R), Neutral (N), Drive (D)
>
> ```mermaid
> stateDiagram-v2
>  [*] --> Park : ignition on
>  Park --> Reverse : shift to R
>  Reverse --> Park : shift to P
>  Reverse --> Neutral : shift to N
>  Neutral --> Park : shift to P
>  Neutral --> Drive : shift to D
>  Drive --> Neutral : shift to N
> ```
> **Guard condition example:** `[shift to R] [vehicle speed == 0]` — can only shift to Reverse when stopped.

---

**Q70.** Write an activity diagram for the Dining Philosophers problem.

`[6 M | May 2023 | UE19CS353]`

> **Answer:**
>
> **Swimlanes: Philosopher_1 ... Philosopher_5**
> *(Show one philosopher's cycle; others are parallel)*
>
> ```mermaid
> flowchart TD
>  Start([●]) --> Think["Thinking"]
>  Think --> Hungry["Hungry — wants to eat"]
>  Hungry --> LC{Left chopstick available?}
>  LC -- No --> Wait1["Wait"] --> Hungry
>  LC -- Yes --> PickL["Pick up left chopstick"]
>  PickL --> RC{Right chopstick available?}
>  RC -- No --> PutL["Put down left chopstick"] --> Wait2["Wait"] --> Hungry
>  RC -- Yes --> PickR["Pick up right chopstick"]
>  PickR --> Eat["Eating"]
>  Eat --> PutBoth["Put down both chopsticks"]
>  PutBoth --> Think
>  PutBoth --> Stop([◎])
> ```
>
> **Key:** Fork/Join at the philosopher level shows concurrency among all 5 philosophers eating/thinking simultaneously.

---

**Q71.** Write short notes on: Order of activities in a state transition, Synchronization and Splitting in concurrent states.

`[4 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Order of Activities in a State Transition:**
> A state transition can have three ordered behaviors: `trigger [guard] / effect`:
> - **Entry action** (`entry/`): Executed when entering the state.
> - **Do activity** (`do/`): Executes while the object is in the state (ongoing activity).
> - **Exit action** (`exit/`): Executed when leaving the state.
>
> Example: ATM `CardVerification` state:
> - `entry/ displayInsertCardMessage()`
> - `do/ waitForCard()`
> - `exit/ readCardData()`
>
> **Synchronization (Fork and Join) — Concurrent States:**
> - **Fork (Splitting):** A thick bar that splits one transition into multiple concurrent sub-states (orthogonal regions). All child states execute simultaneously.
> - **Join (Synchronization):** A thick bar that merges multiple concurrent sub-states back into one. The transition fires only when ALL concurrent regions have completed their current state.
>
> Example: A `Downloading` state that has concurrent regions `[downloading file]` and `[showing progress bar]` — both run simultaneously; both must complete before transitioning to `Done`.

---

**Q72.** With respect to state diagram describe State, Event, Guard condition with an example for each.

`[6 M | Jan–May 2024 | UE19CS353]`

> **Answer:**
>
> **State:** A condition or situation during the life of an object in which it satisfies some condition, performs some activity, or waits for some event. Shown as a rounded rectangle.
> Example: An ATM can be in states: `Idle`, `CardInserted`, `PINVerification`, `TransactionProcessing`.
>
> **Event (Trigger):** An occurrence that may cause an object to transition from one state to another. Can be a signal, method call, time event, or change event.
> Example: `cardInserted` event triggers transition from `Idle` → `CardInserted`.
>
> **Guard Condition:** A Boolean expression that must evaluate to `true` for a transition to occur. Written in square brackets next to the transition.
> Example: `[PIN correct]` — the transition from `PINVerification` to `TransactionProcessing` only fires if the PIN is correct. If false, transitions to `PINError` state instead.
>
> ```mermaid
> stateDiagram-v2
>  [*] --> Idle
>  Idle --> CardInserted : cardInserted
>  CardInserted --> TransactionProcessing : pinEntered [PIN correct]
>  CardInserted --> PINError : pinEntered [PIN incorrect]
>  PINError --> CardInserted : retryPIN
>  TransactionProcessing --> Idle : transactionComplete
> ```

---

**Q73.** Differentiate between guard condition and change event in state modeling.

`[2 M | Dec 2023 | UE19CS353]`

> **Answer:**
>
> | Feature | Guard Condition | Change Event |
> |---|---|---|
> | Definition | A Boolean expression that must be true for a transition to fire | A trigger that fires when a Boolean expression changes from false to true |
> | Syntax | `[condition]` on a transition | `when(expression)` |
> | Evaluation | Evaluated at the moment the trigger event occurs | Continuously monitored; fires when state changes |
> | Example | `[balance >= amount]` on a Withdraw transition | `when(temperature > 100)` triggers OverheatAlert state |
> | Purpose | Filters whether a triggered transition should proceed | Continuously watches for a condition to become true |

---

**Q74.** Draw the UML state chart diagram for different states and events for a process cooperating system.

`[6 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **Process States (OS Process Lifecycle):**
>
> ```mermaid
> stateDiagram-v2
>  [*] --> New
>  New --> Ready : admitted
>  Ready --> Running : scheduler dispatch
>  Running --> Ready : interrupt
>  Running --> Waiting : I/O request
>  Running --> Terminated : exit
>  Waiting --> Ready : I/O complete
>  Terminated --> [*]
> ```
>
> **States:** New, Ready, Running, Waiting/Blocked, Terminated
> **Events:** admitted, dispatch, interrupt, I/O request, I/O complete, exit

---

## 17. Class Identification

> **Frequency: Medium**

---

**Q75.** What are the different approaches for identifying classes? Explain each briefly.

`[10 M | Jun/Jul 2008 | MCA51]`

> **Answer:**
>
> **Approach 1: Noun Phrase Approach**
> Read the requirements specification and identify all **nouns and noun phrases** — these are candidates for classes. Verbs become methods. Then filter:
> - **Relevant classes** — core domain concepts (e.g., Account, Customer, Transaction)
> - **Fuzzy classes** — tentative; need more analysis (e.g., "Record" could be an attribute or class)
> - **Irrelevant classes** — outside the problem domain, implementation-level, or UI concepts (remove these)
>
> **Approach 2: Common Class Patterns (Shlaer & Mellor)**
> Look for recurring patterns in domains:
> - **Concept class** — abstract concept used to organize business (Account, Contract)
> - **Event class** — points in time that must be recorded (Transaction, Withdrawal, Deposit)
> - **Organization class** — groups of people/resources (Bank, Branch, Department)
> - **People class** — users, beneficiaries (Customer, Employee, Admin)
> - **Place class** — physical locations (Branch, Store, Office)
> - **Device/Tangible class** — physical devices (ATM, Sensor, Printer)
>
> **Approach 3: CRC Cards (Class-Responsibility-Collaborators)**
> Brainstorming technique used in agile/OO design:
> - Each card represents one class.
> - **Class:** Name and super/subclass info.
> - **Responsibilities:** What it knows; what it does.
> - **Collaborators:** Which other classes it works with.
> Team members act out use cases using CRC cards, identifying missing or redundant classes.

---

**Q76.** What is object classification? What are the different approaches for identifying classes?

`[5 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **Object Classification:** The process of identifying which objects in the problem domain are important enough to be modeled as classes. Not every noun in the requirements becomes a class — many are attributes, roles, or irrelevant to the scope.
>
> **Approaches:** See Q75 — Noun Phrase Approach, Common Class Patterns (Shlaer & Mellor), CRC Cards.

---

**Q77.** How are classes identified using the common class patterns approach? Explain.

`[6 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> The **Common Class Patterns approach** (Shlaer & Mellor) identifies classes by looking for recognizable pattern categories in the problem domain:
>
> | Pattern | Description | Example |
> |---|---|---|
> | **Concept Class** | Abstract concept organizing business activities | Account, Policy, Contract |
> | **Event Class** | Points in time that must be recorded | Transaction, Enrollment, Reservation |
> | **Organization Class** | Groups of people, resources, or facilities | Bank, Department, Branch |
> | **People Class** | Humans who interact with the system | Customer, Employee, Admin |
> | **Place Class** | Physical locations | Branch, Warehouse, Office |
> | **Device/Tangible Class** | Physical devices or objects | ATM, Sensor, Printer, Car |
>
> **Process:** For each domain entity, ask which pattern it fits. If it fits one, it is a strong candidate for a class. This approach complements the noun phrase approach by providing category-based guidance.

---

**Q78.** List and explain Coad and Yourdon clues for finding candidate classes and objects.

`[4 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **Coad and Yourdon's Clues for Finding Classes:**
>
> 1. **Retained information** — If you need to remember information about a concept (its attributes), it may be a class. E.g., Customer has name, address, contact — it's a class.
> 2. **Needed services** — If a concept performs operations that change state or produce outputs, it's a class candidate.
> 3. **Multiple attributes** — A concept with more than one attribute is usually a class, not an attribute of another class.
> 4. **Common attributes** — If a group of objects all have the same attributes, they form a class.
> 5. **Common operations** — If a group of objects perform the same operations, they belong to the same class.
> 6. **Essential requirements** — If a concept is fundamentally part of the problem domain, it should be a class.
>
> **Filter criteria (things to remove from candidates):**
> - Redundant classes (same class, different name)
> - Irrelevant classes (outside the system boundary)
> - Vague classes (too fuzzy to define clearly)
> - Simple attribute values (not really a class — e.g., "color" is an attribute of Car, not a class)
> - Roles (not always separate classes)
> - Implementation constructs (not part of the domain model)

---

**Q79.** How can associations, attributes, and methods be identified? Give guidelines.

`[10 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **Identifying Associations:**
> - Look for **verbs** and **verb phrases** in requirements ("manages", "owns", "sends to", "works for").
> - Look for physical or conceptual connections between objects.
> - Consider which objects need to communicate in use cases.
> - Rule: If object A needs to send a message to object B, there must be an association.
> - Eliminate: transient associations (only in one method call), derivable associations (can be computed), and very weak associations.
>
> **Identifying Attributes:**
> - Attributes are properties of a class describing its state.
> - Look for **adjectives** and **nouns that describe** a class in requirements.
> - An attribute should be a simple value, not an object with its own identity. If it has multiple properties, it becomes a class.
> - Ask: "Is this information intrinsic to this object, or does it belong to another?"
> - Examples: `Customer.name`, `Account.balance`, `Product.price`.
>
> **Identifying Methods (Operations):**
> - Look for **verbs** that describe what an object must do: "calculate", "validate", "display", "update".
> - Assign an operation to the class that has the information needed to perform it (Information Expert principle).
> - Types: Constructor, Accessor (getter), Mutator (setter), Business operations, Lifecycle operations.
> - Example: `Account.deposit()`, `Order.calculateTotal()`, `Customer.login()`.

## 18. GRASP Design Principles

> **Frequency: Very High** — appears in every UE19/UE20 paper

---

**Q80.** Explain in a line or two the following GRASP principles with an example: i) Creator ii) Low Coupling iii) Controller iv) Polymorphism

`[8 M | Dec 2023 | UE19CS353]`

> **Answer:**
>
> **i) Creator:**
> Assign class B the responsibility to create instances of class A if B contains/aggregates A, records A, closely uses A, or has the initializing data for A.
> ```java
> // Sale contains SalesLineItems → Sale is the Creator
> class Sale {
>     private List<SalesLineItem> items = new ArrayList<>();
>     void addItem(ProductDescription p, int qty) {
>         SalesLineItem item = new SalesLineItem(p, qty); // Sale creates SalesLineItem
>         items.add(item);
>     }
> }
> ```
>
> **ii) Low Coupling:**
> Assign responsibilities so that unnecessary dependencies between classes are minimized. Classes should depend on abstractions (interfaces) rather than concrete implementations.
> ```java
> // HIGH coupling (bad): OrderService directly creates MySQLDB
> // LOW coupling (good): depend on interface
> interface Database { void save(Order o); }
> class OrderService {
>     private Database db;
>     OrderService(Database db) { this.db = db; } // injected — low coupling
> }
> ```
>
> **iii) Controller:**
> Assign the responsibility of handling system events to a class that represents the overall system (Façade Controller) or a use-case scenario (Use-Case Controller). The controller delegates work — it does not do the work itself.
> ```java
> class OrderController {                  // Controller for "Place Order" use case
>     void placeOrder(int productId, int qty) {
>         Order o = orderService.createOrder(productId, qty);  // delegates
>         paymentService.processPayment(o);                    // delegates
>     }
> }
> ```
>
> **iv) Polymorphism:**
> When behavior varies by type, assign responsibility using polymorphic operations (overriding) to the types that exhibit the variation — avoiding `if-else` or `switch` on type.
> ```java
> interface TaxCalculator { double calculate(double amount); }
> class GSTCalculator implements TaxCalculator { public double calculate(double a) { return a * 0.18; } }
> class VATCalculator implements TaxCalculator { public double calculate(double a) { return a * 0.12; } }
> // Client uses TaxCalculator — no type-checking needed
> ```

---

**Q81.** Explain the Creator and Controller GRASP principles with an example along with the corresponding class diagram.

`[8 M | Dec 2023 | UE20CS352; Jul 2023 | UE19CS353]`

> **Answer:**
>
> **Creator Principle:**
> *Problem:* Who should be responsible for creating a new instance of class A?
> *Solution:* Assign class B to create A if B: contains/aggregates A, records A, closely uses A, or has initializing data for A.
>
> **Example — POS System:**
> `Sale` aggregates `SalesLineItem` objects → `Sale` creates `SalesLineItem`.
> ```mermaid
> classDiagram
>  class Sale {
>  +addItem()
>  +makeLineItem()
>  }
>  class SalesLineItem {
>  +SalesLineItem(ProductDesc, qty)
>  }
>  class ProductDescription
>  Sale "1" *-- "*" SalesLineItem : creates (Creator)
>  SalesLineItem --> ProductDescription
> ```
> ```java
> class Sale {
>     List<SalesLineItem> lineItems = new ArrayList<>();
>     void makeLineItem(ProductDescription pd, int qty) {
>         lineItems.add(new SalesLineItem(pd, qty)); // Creator
>     }
> }
> ```
>
> **Controller Principle:**
> *Problem:* What object outside the UI layer should be responsible for handling system operation requests?
> *Solution:* Use a Façade Controller (represents the system) or a Use-Case Controller (one per use case).
>
> **Example — POS System:**
> ```mermaid
> flowchart LR
>  UI["UI Layer"] --> PC["POSController<br/>(Controller)"]
>  PC --> Sale["Sale"]
>  PC --> Cat["ProductCatalog"]
>  PC --> Pay["Payment"]
> ```
> ```java
> class POSController {          // Façade Controller
>     Sale currentSale;
>     void enterItem(int productId, int qty) {
>         ProductDescription pd = catalog.getDescription(productId);
>         currentSale.makeLineItem(pd, qty); // delegates to Sale
>     }
>     void makePayment(double amount) {
>         currentSale.makePayment(amount);   // delegates to Sale
>     }
> }
> ```
> The controller **receives** system events and **delegates** — it does not perform domain logic itself.

---

**Q82.** How does the Creator pattern in GRASP help in assigning responsibilities?

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> The **Creator** pattern provides a principled way to decide *which class should be responsible for creating new objects* — avoiding arbitrary or scattered `new` calls throughout the codebase.
>
> **Guidelines (assign B to create A if):**
> 1. B **contains** or **aggregates** A (composition/aggregation relationship)
> 2. B **records** instances of A (B maintains a collection of A)
> 3. B **closely uses** A (B has strong usage of A)
> 4. B has the **initializing data** for A (B knows what A needs to be created)
>
> **Benefits:**
> - **Low Coupling:** Creator already has a relationship with the created object — no new dependency introduced.
> - **High Cohesion:** Creation logic stays with the class that knows the most about it.
> - **Single Responsibility:** Avoids a separate "ObjectFactory" for simple cases.
> - Supports the **Information Expert** principle — the class with data creates the object.
>
> **When NOT to use Creator:** If creation is complex (many conditional paths, resource pooling, configuration) — use the **Factory Method** or **Abstract Factory** pattern instead.

---

**Q83.** With an appropriate example, explain Controller and High Cohesion principles in GRASP.

`[6 M | May 2023 | UE19CS353]`

> **Answer:**
>
> **Controller:**
> *(See Q80-iii and Q81 for full explanation.)*
> Key: The controller receives UI/system events and delegates work to domain classes. It must not do the work itself (that would make it a Bloated Controller with low cohesion).
>
> **High Cohesion:**
> *Problem:* How to keep objects focused, understandable, and manageable — and support Low Coupling?
> *Solution:* Assign responsibilities so that cohesion remains high. A class should have a single, well-focused purpose.
>
> **Signs of Low Cohesion (bad):**
> - A class has too many unrelated responsibilities.
> - Hard to understand, reuse, or test.
> - Methods in a class deal with 5 different concerns.
>
> **Example:**
> ```java
> // LOW cohesion — BAD: OrderManager does too much
> class OrderManager {
>     void createOrder() { ... }
>     void sendEmail() { ... }      // unrelated to orders
>     void generatePDF() { ... }    // unrelated
>     void connectToDatabase() { } // unrelated
> }
>
> // HIGH cohesion — GOOD: each class has one focus
> class OrderService   { void createOrder() { ... } }
> class EmailService   { void sendEmail() { ... } }
> class ReportService  { void generatePDF() { ... } }
> class DatabaseLayer  { void connect() { ... } }
> ```
> High cohesion is closely related to SRP (Single Responsibility Principle).

---

**Q84.** Match the following GRASP Design Principle names with their definitions.

`[4 M | Dec 2023 | UE19CS353; May 2023 | UE19CS353]`

> **Answer:**
>
> | Principle | Definition |
> |---|---|
> | **Information Expert** | c. Assign responsibility to the class which has the required data |
> | **High Cohesion** | a. Combine related responsibilities into one manageable unit |
> | **Indirection** | d. Introduce an intermediate unit to communicate between other units |
> | **Protected Variation** | b. Provide a well-defined interface so there's no effect on other units |

---

**Q85.** Describe briefly the Pure Fabrication GRASP Design Principle with an example.

`[6 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> **Problem:** What object should have responsibility when assigning to an existing domain class violates High Cohesion or Low Coupling?
>
> **Solution:** Assign a highly cohesive set of responsibilities to an **artificial class** that does not represent a concept in the problem domain. This class is invented purely for software design convenience — a "Pure Fabrication."
>
> **When to use:** When the Information Expert solution (assigning responsibility to the domain class that has the data) would lead to poor cohesion or high coupling.
>
> **Example — Persistence:**
> In a sales system, `Sale` objects need to be saved to a database. Assigning `save()` to `Sale` violates cohesion — `Sale` is a business object, not a database handler.
> Instead, create a `SaleRepository` (Pure Fabrication):
> ```java
> class SaleRepository {        // Pure Fabrication — not in the domain model
>     void save(Sale s) {
>         // database persistence logic
>     }
>     Sale findById(int id) {
>         // database retrieval logic
>     }
> }
> ```
>
> **Other examples of Pure Fabrication:** Utility classes (`StringUtils`, `DateFormatter`), Service classes (`EmailService`, `PaymentGateway`), Helper classes, Data Access Objects (DAOs).
>
> **Key insight:** Pure Fabrications achieve high cohesion (focused on one technical concern) and low coupling (isolated from domain logic). They support reuse across many domain classes.

---

**Q86.** What is wrong in terms of GRASP design principles in the given class model? Show improvement.

`[6 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Typical violation depicted:** A "Blob" class where one class (e.g., `Manager` or `System`) handles all responsibilities — violates **High Cohesion** and **Low Coupling**.
>
> **Identifying the violation:**
> - If a single class has operations for order management, payment, inventory, and notification — that violates **High Cohesion**.
> - If many classes directly depend on this one class — that creates **High Coupling**.
>
> **Refactored solution (applying GRASP):**
> ```
> Before (Bad):
> SystemManager
>   + createOrder()
>   + processPayment()
>   + updateInventory()
>   + sendNotification()
>   + generateReport()
>
> After (Good — High Cohesion, Low Coupling):
> OrderService       { + createOrder() }
> PaymentService     { + processPayment() }
> InventoryService   { + updateInventory() }
> NotificationService{ + sendNotification() }
> ReportService      { + generateReport() }
>
> SystemController (Controller GRASP) coordinates above services.
> ```
> Each class now has a single, focused responsibility — **High Cohesion**. Each service is independently testable and reusable — **Low Coupling**.

---

**Q87.** What are coupling and cohesion of objects or software components? *(See Q48)*

`[6 M | Jun–Jul 2009 | CS72]`

> **Answer:** Refer to Q48.

---

## 19. SOLID Design Principles

> **Frequency: Very High**

---

**Q88.** Explain SOLID design principles. Give an example for any 2 principles.

`[8 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> **SOLID** — five design principles introduced by Robert C. Martin to achieve maintainable, extensible, and testable OO software.
>
> | Letter | Principle | One-liner |
> |---|---|---|
> | **S** | Single Responsibility | A class should have only one reason to change |
> | **O** | Open-Closed | Open for extension, closed for modification |
> | **L** | Liskov Substitution | Subclasses must be substitutable for their base classes |
> | **I** | Interface Segregation | Clients should not be forced to implement unused interfaces |
> | **D** | Dependency Inversion | Depend on abstractions, not concretions |
>
> **Example 1 — SRP:**
> ```java
> // VIOLATION: Invoice handles both logic AND printing
> class Invoice { void calculateTotal(){} void printInvoice(){} void saveToDB(){} }
>
> // FIXED: Separate classes
> class Invoice          { void calculateTotal() {} }
> class InvoicePrinter   { void print(Invoice i) {} }
> class InvoiceRepository{ void save(Invoice i) {} }
> ```
>
> **Example 2 — OCP:**
> ```java
> // VIOLATION: must modify class to add new shape
> class AreaCalculator { double area(Object shape) {
>     if (shape instanceof Circle) return ...;
>     if (shape instanceof Rect) return ...;   // modify for each new type
> }}
>
> // FIXED: extend via interface
> interface Shape { double getArea(); }
> class Circle implements Shape { public double getArea() { return Math.PI*r*r; } }
> class Rectangle implements Shape { public double getArea() { return l*b; } }
> class AreaCalculator { double total(List<Shape> shapes) {
>     return shapes.stream().mapToDouble(Shape::getArea).sum();
> }}
> ```

---

**Q89.** Describe any four SOLID design principles with an example for each.

`[8 M | Jan–May 2024 | UE19CS353]`

> **Answer:** (See Q88 for S and O. Below covers L, I, D.)
>
> **L — Liskov Substitution Principle (LSP):**
> Objects of a subclass must be replaceable for objects of the superclass without breaking the program.
> ```java
> // VIOLATION: Penguin can't fly — substituting breaks the contract
> class Bird  { void fly() { System.out.println("Flying"); } }
> class Penguin extends Bird { void fly() { throw new UnsupportedOperationException(); } }
>
> // FIXED: Proper hierarchy
> abstract class Bird { abstract void eat(); }
> interface Flyable { void fly(); }
> class Sparrow extends Bird implements Flyable { public void fly(){} public void eat(){} }
> class Penguin extends Bird                   { public void eat(){} }
> ```
>
> **I — Interface Segregation Principle (ISP):**
> Do not force classes to implement interfaces they don't use. Split fat interfaces.
> ```java
> // VIOLATION: Robot forced to implement eat()
> interface Worker { void work(); void eat(); }
> class Robot implements Worker { public void work(){} public void eat(){ /*N/A*/ } }
>
> // FIXED: segregated
> interface Workable { void work(); }
> interface Eatable  { void eat(); }
> class Human implements Workable, Eatable { public void work(){} public void eat(){} }
> class Robot implements Workable          { public void work(){} }
> ```
>
> **D — Dependency Inversion Principle (DIP):**
> High-level modules should not depend on low-level modules; both should depend on abstractions.
> ```java
> // VIOLATION: OrderService tightly coupled to MySQLDB
> class OrderService { MySQLDB db = new MySQLDB(); }
>
> // FIXED: depend on interface
> interface Database { void save(Order o); }
> class MySQLDB    implements Database { public void save(Order o){} }
> class OrderService { Database db; OrderService(Database db){ this.db=db; } }
> ```

---

**Q90.** What SOLID design principle is violated in the given design? How can this be modified?

`[8 M | Dec 2023 | UE19CS353]`

> **Answer:**
>
> **Typical scenario:** A class like `Employee` with methods `calculatePay()`, `saveEmployee()`, `generateReport()` — violates **SRP** (three reasons to change). Or a class that extends a base class but throws `UnsupportedOperationException` for inherited methods — violates **LSP**.
>
> **General approach to answer such questions:**
> 1. **Identify the violation:** Name the principle and explain why it is violated ("This class has more than one responsibility — it handles both business logic and persistence").
> 2. **State the consequence:** "This means any change to database logic forces a retest of pay calculation logic."
> 3. **Show the fix:**
> ```
> Before:
> Employee
>   + calculatePay()      ← business logic
>   + saveToDatabase()    ← persistence
>   + generateReport()    ← reporting
>
> After (SRP applied):
> Employee          { + calculatePay() }
> EmployeeDAO       { + saveToDatabase() }
> EmployeeReporter  { + generateReport() }
> ```
> 4. **Draw class diagram** showing separation with arrows indicating dependencies.

---

**Q91.** Describe briefly: 1) Liskov Substitution Principle (LSP) 2) Interface Segregation Principle 3) Open-Closed Principle.

`[6 M | Jul 2023 | UE19CS353]`

> **Answer:**
>
> **1. Liskov Substitution Principle (LSP):**
> "If S is a subtype of T, objects of type T may be replaced by objects of type S without altering the correctness of the program." — Barbara Liskov.
> Subclasses should honor the behavioral contract of the superclass — they should not do *less* than the parent.
> Violation: `Square extends Rectangle` — setting width of a Square (which must keep width==height) breaks the Rectangle contract.
>
> **2. Interface Segregation Principle (ISP):**
> "Clients should not be forced to depend on methods they do not use." — Robert C. Martin.
> Split large ("fat") interfaces into smaller, focused ones. Each class implements only the interfaces relevant to it.
> Example: Instead of one `IWorker` with `work()`, `eat()`, `sleep()`, create `IWorkable`, `IFeedable`, `IRestable` separately.
>
> **3. Open-Closed Principle (OCP):**
> "Software entities should be open for extension but closed for modification." — Bertrand Meyer.
> Add new behavior by *extending* (new subclasses, new implementations) — not by *modifying* existing working code.
> Achieved via: abstract classes, interfaces, strategy pattern, and inheritance.
> Example: `PaymentProcessor` accepting `PaymentMethod` interface — add PayPal by creating a new class, not modifying `PaymentProcessor`.

---

**Q92.** Describe the Liskov Substitution Principle (LSP) and its implications for OO design.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Definition (formal):** Let Φ(x) be a property provable about objects x of type T. Then Φ(y) should be true for objects y of type S where S is a subtype of T.
>
> **In plain terms:** Wherever a parent class object is expected, a child class object should work without the program knowing the difference. The subclass must honor the superclass's *behavioral contract*.
>
> **Implications for OO Design:**
> 1. **Strengthening preconditions is forbidden** — subclass cannot require more from callers than the parent.
> 2. **Weakening postconditions is forbidden** — subclass cannot guarantee less than the parent.
> 3. **Exceptions** — subclass should not throw new exceptions not thrown by the parent.
> 4. Design inheritance hierarchies carefully — prefer composition over inheritance when LSP cannot be satisfied.
>
> **Violation example:**
> ```java
> class Rectangle { int w, h; void setW(int w){this.w=w;} void setH(int h){this.h=h;} int area(){return w*h;} }
> class Square extends Rectangle {
>     void setW(int w){this.w=this.h=w;}  // breaks Rectangle contract
>     void setH(int h){this.w=this.h=h;}
> }
> // Test written for Rectangle fails with Square:
> // r.setW(4); r.setH(5); assert r.area()==20; → FAILS for Square (area = 25)
> ```

---

**Q93.** Explain the Liskov Substitution Principle using an example where LSP is violated and how it can be corrected.

`[4 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Violation:**
> ```java
> class Bird { public void fly() { System.out.println("Flying"); } }
> class Penguin extends Bird {
>     @Override
>     public void fly() { throw new UnsupportedOperationException("Penguins can't fly!"); }
> }
>
> // Client code breaks when Penguin substituted for Bird:
> Bird b = new Penguin();
> b.fly(); // throws exception — LSP violated
> ```
>
> **Correction — Restructure the hierarchy:**
> ```java
> abstract class Bird {
>     abstract void eat();  // all birds eat
>     abstract void move(); // all birds move (some fly, some walk/swim)
> }
> interface Flyable { void fly(); }
>
> class Sparrow extends Bird implements Flyable {
>     public void eat()  { System.out.println("Sparrow eating"); }
>     public void move() { fly(); }
>     public void fly()  { System.out.println("Sparrow flying"); }
> }
> class Penguin extends Bird {
>     public void eat()  { System.out.println("Penguin eating fish"); }
>     public void move() { System.out.println("Penguin swimming"); }
> }
> // Now Penguin is never substituted where Flyable is expected — no violation
> ```

---

**Q94.** State the Interface Segregation Principle. Explain the problem and solution with an example.

`[8 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> **ISP Statement:** "Clients should not be forced to depend on interfaces they do not use." — Robert C. Martin. Many client-specific interfaces are better than one general-purpose ("fat") interface.
>
> **Problem:**
> ```java
> interface MultiFunctionDevice {
>     void print(Document d);
>     void scan(Document d);
>     void fax(Document d);
>     void copy(Document d);
> }
>
> class OldPrinter implements MultiFunctionDevice {
>     public void print(Document d) { /* works */ }
>     public void scan(Document d)  { throw new UnsupportedOperationException(); } // No scanner!
>     public void fax(Document d)   { throw new UnsupportedOperationException(); } // No fax!
>     public void copy(Document d)  { throw new UnsupportedOperationException(); } // No copier!
> }
> ```
> `OldPrinter` is forced to implement methods it doesn't support — fragile, misleading design.
>
> **Solution — Segregated interfaces:**
> ```java
> interface Printable  { void print(Document d); }
> interface Scannable  { void scan(Document d); }
> interface Faxable    { void fax(Document d); }
> interface Copyable   { void copy(Document d); }
>
> class OldPrinter implements Printable {               // only what it supports
>     public void print(Document d) { System.out.println("Printing..."); }
> }
> class ModernPrinter implements Printable, Scannable, Faxable, Copyable {
>     public void print(Document d) {}
>     public void scan(Document d)  {}
>     public void fax(Document d)   {}
>     public void copy(Document d)  {}
> }
> ```
> Now each class only implements relevant interfaces. No unused method stubs.

---

**Q95.** Identify the three SOLID principles violated by a given design. Suggest corrections.

`[6 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Typical violations found in exam diagrams — approach:**
>
> **Violation 1 — SRP:** One class handles multiple concerns (e.g., business logic + database + UI output).
> *Fix:* Split into separate classes, each with one responsibility.
>
> **Violation 2 — OCP:** New functionality requires modifying an existing class (e.g., `if type=="A"... else if type=="B"`).
> *Fix:* Introduce an interface or abstract class; add new classes as implementations without touching existing code.
>
> **Violation 3 — LSP or ISP:** A subclass overrides methods to throw exceptions (LSP) or a class implements an interface with unused methods (ISP).
> *Fix for LSP:* Restructure hierarchy. *Fix for ISP:* Split the interface.
>
> **General answer structure:**
> 1. State which principle is violated and why.
> 2. Show the violating class diagram / code.
> 3. Show the corrected class diagram / code.

---

**Q96.** A software designer for a pizza store has proposed a design. Identify issues and suggest appropriate class diagram.

`[7 M | May 2023 | UE19CS353]`

> **Answer:**
>
> **Likely violations in a pizza store design:**
>
> **OCP Violation:** A `PizzaStore` class with `if (type == "cheese") ... else if (type == "pepperoni")...` — adding a new pizza requires modifying the class.
>
> **Fix — Factory Method + OCP:**
> ```
> <<abstract>> PizzaStore
>     + orderPizza(type): Pizza
>     + createPizza(type): Pizza  ← factory method (abstract)
>
> NYPizzaStore extends PizzaStore
>     + createPizza(type): Pizza  ← creates NY-style pizzas
>
> ChicagoPizzaStore extends PizzaStore
>     + createPizza(type): Pizza  ← creates Chicago-style pizzas
>
> <<abstract>> Pizza
>     + prepare(), bake(), cut(), box()
>
> NYCheesePizza extends Pizza
> ChicagoCheesePizza extends Pizza
> ```
>
> **SRP Violation:** `Pizza` class might handle both recipe logic and pricing.
> *Fix:* Separate `PizzaRecipe` and `PricingStrategy` classes.
>
> **Result:** New pizza types added by extending `Pizza` and registering in the factory — no modification to existing classes.

---

**Q97.** If two-wheeler class implements `IVehicle`, which design principle is violated? Modify the design.

`[8 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **Violated Principle: Interface Segregation Principle (ISP)**
>
> If `IVehicle` contains methods like `openTrunk()`, `activateAirBag()`, `enableAutoParking()` — none of which apply to a two-wheeler — then the two-wheeler is forced to implement inapplicable methods.
>
> **Modified Design (ISP applied):**
> ```java
> interface IVehicle      { void start(); void stop(); void accelerate(); }
> interface IFourWheeler  extends IVehicle { void openTrunk(); void activateAirbag(); }
> interface ITwoWheeler   extends IVehicle { void kickStart(); }
> interface IAutoParking  { void enableAutoParking(); }
>
> class Car         implements IFourWheeler, IAutoParking { /* all methods */ }
> class Motorcycle  implements ITwoWheeler { /* only relevant methods */ }
> class Bicycle     implements ITwoWheeler { /* only relevant methods */ }
> ```
>
> **Class Diagram:**
> ```
>            <<interface>> IVehicle
>            + start(); + stop(); + accelerate()
>                /               \
> <<interface>>              <<interface>>
> IFourWheeler               ITwoWheeler
> + openTrunk()              + kickStart()
> + activateAirbag()
>        |                         |
>       Car                   Motorcycle
> ```

---

**Q98.** Fill in the blanks (SOLID and Patterns).

`[4–6 M | Dec 2023 | UE20CS352; May 2023 | UE19CS353]`

> **Answer:**
>
> i. Violating Dependency Inversion Principle will result in a code with **tight / high** coupling.
>
> ii. Liskov Substitution Principle states that the designer/implementer should be able to replace objects of **superclass (base class)** with the objects of **subclass (derived class)**.
>
> iii. **Open-Closed** Principle states that the design should be extensible however modifying existing design should be avoided.
>
> iv. The pattern that hides the complexity related to creation of objects from the client is **Creational Design Pattern (e.g., Factory Method / Abstract Factory)**.
>
> v. A **pattern** is a best practice, a recipe, a time-tested solution to a recurring problem.

---

## 20. Architectural Patterns

> **Frequency: High**

---

**Q99.** Define MVC architectural pattern. Explain the working of MVC with a neat diagram.

`[6 M | Dec 2023 | UE20CS352]`

> **Answer:**
>
> **Definition:** Model-View-Controller (MVC) is an architectural pattern that separates an application into three components — Model (data/logic), View (UI), Controller (input handling) — to achieve loose coupling and separation of concerns. First introduced by Trygve Reenskaug at Xerox PARC (1979).
>
> **Components:**
>
> | Component | Responsibility |
> |---|---|
> | **Model** | Manages data, business logic, and rules. Interacts with the database. Notifies View of changes. |
> | **View** | Renders data from the Model. Sends user input to the Controller. Multiple views can use the same model. |
> | **Controller** | Receives user input, processes it, updates the Model, selects the appropriate View. |
>
> **Working:**
> ```mermaid
> flowchart LR
>  User(["User"]) -- "1. interacts" --> View["View"]
>  View -- "2. user action" --> Controller["Controller"]
>  Controller -- "3. processes & updates" --> Model["Model"]
>  Model -- "4. notifies" --> View
>  View -- "5. re-renders UI" --> User
> ```
>
> **Java MVC Example:**
> - `Employee.java` → Model (name, dept, salary; get/set methods)
> - `EmployeeView.java` → View (`printEmployeeDetails()`)
> - `EmployeeController.java` → Controller (gets input, calls model, calls view)
>
> **Advantages:** Separation of concerns, parallel development, model reuse across views, easier testing.

---

**Q100.** With a neat flow diagram, explain the working of MVC architecture pattern.

`[4 M | May 2023 | UE20CS352]`

> **Answer:** Refer to Q99 — the flow diagram and explanation covers this answer fully.

---

**Q101.** Contrast Architectural Views, Styles, and Patterns. Give an example for each.

`[6 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> | Term | Definition | Example |
> |---|---|---|
> | **Architectural View** | A representation of the system from a specific stakeholder perspective. Different views address different concerns. | Logical View (class/package structure), Physical View (deployment), Process View (concurrency), Development View (code organization), Scenario View (use cases) |
> | **Architectural Style** | A named collection of architectural decisions, constraints, and principles applicable to a family of systems. | Layered, Pipe-and-Filter, Event-Driven, Microservices, Repository, Client-Server |
> | **Architectural Pattern** | A concrete, named solution to a recurring architectural problem with documented participants, roles, and consequences. | MVC (Model-View-Controller), MVVM, MVP, CQRS, Saga Pattern |
>
> **Key Differences:**
> - Views are *perspectives* for understanding; Styles are *constraints/principles*; Patterns are *reusable solutions*.
> - A style defines what a system *is* (e.g., layered); a pattern defines *how to solve* a problem within that system (e.g., MVC in a web layer).

---

**Q102.** State the difference between Architectural and Design patterns.

`[6 M | Dec 2023 | UE20CS352]`

> **Answer:**
>
> | Feature | Architectural Pattern | Design Pattern |
> |---|---|---|
> | **Scope** | System-wide; defines overall structure and organization | Class/object level; solves specific design problems within a subsystem |
> | **Granularity** | Coarse-grained (affects entire application) | Fine-grained (affects a class or small cluster of classes) |
> | **Focus** | Non-functional concerns: scalability, availability, performance | Functional structure: flexibility, reuse, extensibility |
> | **Examples** | MVC, Layered, Microservices, Event-Driven, Client-Server | Singleton, Factory, Observer, Adapter, Decorator |
> | **Language dependence** | Language-independent; platform/infrastructure level | Language-independent but implementation is code-level |
> | **Impact of change** | Architectural change is costly and risky | Design pattern change is localized |

---

**Q103.** Elaborate on any one architectural design pattern with an illustrative example.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Pattern: Layered Architecture (N-Tier)**
>
> **Intent:** Organizes the system into groups of subtasks at specific levels of abstraction. Each layer provides services to the layer above and uses services from the layer below.
>
> **Layers (4-tier web app):**
> ```mermaid
> flowchart TD
>  P["Presentation Layer - UI<br/>Browser · JSP · React"]
>  B["️Business Logic Layer<br/>Services · Rules · Calculations"]
>  D["Persistence Layer<br/>DAOs · ORM · Hibernate"]
>  DB[("Database Layer - MySQL / PostgreSQL")]
>  P --> B --> D --> DB
> ```
>
> **Illustrative Example (Online Banking):**
> - User clicks "Transfer Funds" → **Presentation Layer** captures input.
> - **Business Logic Layer** validates: sufficient balance, valid account.
> - **Persistence Layer** calls `AccountDAO.debit()` and `AccountDAO.credit()`.
> - **Database Layer** executes SQL transactions.
>
> **Advantages:** Clear separation of concerns, easy testing of each layer, team specialization.
> **Disadvantages:** Performance overhead (request passes through all layers), difficult to scale layers independently.

---

**Q104.** Describe briefly any six approaches to decompose a large system into subsystems or components.

`[6 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> 1. **Layered decomposition:** Divide system into horizontal layers (Presentation, Business Logic, Data Access, Database) — each layer has a specific role and communicates only with adjacent layers.
>
> 2. **Client-Server decomposition:** Separate the system into clients (requesters) and servers (providers). Clients send requests; servers process and respond.
>
> 3. **Microservices decomposition:** Break the system into small, independently deployable services each focused on a single business capability (e.g., Order Service, Payment Service, Inventory Service).
>
> 4. **Domain-driven decomposition:** Divide by business domain or bounded context (e.g., Sales domain, HR domain, Inventory domain) — aligns subsystems with real-world business units.
>
> 5. **Event-driven decomposition:** Decompose around events — producers generate events, consumers react. Subsystems are decoupled via an event bus/broker.
>
> 6. **Model-View-Controller decomposition:** Separate UI (View), application logic (Controller), and data (Model) into distinct subsystems — well-suited for interactive web/desktop applications.

---

**Q105.** Explain with a neat diagram three-tier architecture.

`[10 M | Jun/Jul 2008 | MCA51]`

> **Answer:**
>
> **Three-Tier Architecture** separates an application into three logical and physical tiers:
>
> ```mermaid
> flowchart TD
>  T1["Presentation Tier<br/>Client · Browser · Desktop App<br/>HTML, CSS, JavaScript, JSP"]
>  T2["️ Application Tier<br/>Business Logic Server<br/>Java EE · Spring Boot · Node.js<br/>Validation · Rules · Transactions"]
>  T3[("Data Tier - MySQL / Oracle / MongoDB")]
>  T1 -- "HTTP / Web Service calls" --> T2
>  T2 -- "JDBC / ORM / SQL" --> T3
> ```
>
> **Tier 1 (Presentation):** User interface — runs on the client machine or browser. Only displays data and captures input. Does not contain business logic.
>
> **Tier 2 (Application/Logic):** Core business processing. Receives requests from Tier 1, processes them using business rules, communicates with Tier 3 for data. Can be scaled independently.
>
> **Tier 3 (Data):** Persistent storage. Executes queries from Tier 2. Ensures data integrity and security.
>
> **Advantages:** Scalability (each tier independently scalable), Security (data tier not directly exposed to clients), Maintainability (changes in one tier don't necessarily affect others), Reusability (business logic reused across multiple front-ends).

---

## 21. Creational Design Patterns

> **Frequency: Very High**

---

**Q106.** With an example show how a class can be made Singleton and what are the benefits.

`[4–5 M | Jul 2023 | UE19CS353; May 2023 | UE19CS353]`

> **Answer:**
>
> **Singleton Pattern:** Ensures a class has only one instance and provides a global access point to it.
>
> **Implementation (Double-Checked Locking — thread-safe and efficient):**
> ```java
> public class DatabaseConnection {
>     private static volatile DatabaseConnection instance = null;
>
>     private DatabaseConnection() {
>         System.out.println("DB Connection established");
>     }
>
>     public static DatabaseConnection getInstance() {
>         if (instance == null) {
>             synchronized (DatabaseConnection.class) {
>                 if (instance == null) {
>                     instance = new DatabaseConnection();
>                 }
>             }
>         }
>         return instance;
>     }
>
>     public void query(String sql) { System.out.println("Executing: " + sql); }
> }
>
> // Usage:
> DatabaseConnection c1 = DatabaseConnection.getInstance();
> DatabaseConnection c2 = DatabaseConnection.getInstance();
> System.out.println(c1 == c2); // true — same instance
> ```
>
> **Making a class Singleton — two steps:**
> 1. Make the constructor **private** — prevents external instantiation via `new`.
> 2. Provide a **static factory method** (`getInstance()`) that returns the single instance.
>
> **Benefits:**
> - Controlled access to the sole instance.
> - Reduced memory footprint (only one object, not thousands).
> - Avoids global variables while still providing global access.
> - Useful for shared resources: DB connections, logging, config settings, thread pools, caches.

---

**Q107.** Describe the Singleton creational pattern with a suitable code snippet.

`[6 M | Dec 2023 | UE19CS353]`

> **Answer:** See Q106. Also note the four implementation variants:
>
> **Method 1 — Lazy (not thread-safe):** `if (obj==null) obj = new Singleton();`
> **Method 2 — Synchronized (thread-safe, slow):** `public static synchronized Singleton getInstance()`
> **Method 3 — Eager (thread-safe, always creates):** `private static final Singleton obj = new Singleton();`
> **Method 4 — Double-Checked Locking (best):** See Q106 — uses `volatile` + two null checks.
>
> **UML Structure:**
> ```mermaid
> classDiagram
>  class Singleton {
>  -Singleton instance
>  -Singleton()
>  +getInstance() Singleton
>  +businessMethod()
>  }
>  Singleton --> Singleton : returns
> ```
>
> **Consequences:**
> - ✅ Controlled access, reduced namespace pollution, variable number of instances possible (can generalize to limited pool).
> - ❌ Violates SRP (manages own lifecycle + business logic), hard to unit test, issues in multithreaded environments without care.

---

**Q108.** What is a singleton class? How to make a class singleton?

`[6 M | Jan–May 2024 | UE19CS353]`

> **Answer:** See Q106 and Q107. Key points:
> A **singleton class** is a class that can be instantiated only once — the class itself controls instantiation.
>
> **Steps to make a class Singleton:**
> 1. Declare `private static` instance variable of the same class.
> 2. Make the constructor `private`.
> 3. Provide `public static getInstance()` method.
> 4. Use `volatile` + double-checked locking for thread safety.

---

**Q109.** Describe the Factory Method creational pattern with a suitable example design and code snippet.

`[6 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Intent:** Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method defers instantiation to subclasses.
>
> **Structure:**
> ```mermaid
> classDiagram
>  class Creator {
>  <<abstract>>
>  +factoryMethod() Product
>  +operation()
>  }
>  class ConcreteCreatorA {
>  +factoryMethod() ConcreteProductA
>  }
>  class ConcreteCreatorB {
>  +factoryMethod() ConcreteProductB
>  }
>  class Product {
>  <<interface>>
>  }
>  class ConcreteProductA
>  class ConcreteProductB
>  Creator <|-- ConcreteCreatorA
>  Creator <|-- ConcreteCreatorB
>  Product <|.. ConcreteProductA
>  Product <|.. ConcreteProductB
>  Creator ..> Product : creates
> ```
>
> **Example — Vehicle Factory:**
> ```java
> interface Vehicle { void drive(); }
>
> class Car implements Vehicle {
>     public void drive() { System.out.println("Driving a Car"); }
> }
> class Bike implements Vehicle {
>     public void drive() { System.out.println("Riding a Bike"); }
> }
>
> abstract class VehicleFactory {
>     abstract Vehicle createVehicle();   // Factory Method
>     void startJourney() {
>         Vehicle v = createVehicle();    // calls factory method
>         v.drive();
>     }
> }
>
> class CarFactory extends VehicleFactory {
>     Vehicle createVehicle() { return new Car(); }
> }
> class BikeFactory extends VehicleFactory {
>     Vehicle createVehicle() { return new Bike(); }
> }
>
> // Usage:
> VehicleFactory factory = new CarFactory();
> factory.startJourney(); // "Driving a Car"
> factory = new BikeFactory();
> factory.startJourney(); // "Riding a Bike"
> ```
>
> **Benefits:** Decouples client from concrete product classes. New product types added by creating new ConcreteCreator — existing code untouched (OCP).

---

**Q110.** Specify when to use a Builder pattern. State the difference between Factory and Abstract Factory pattern.

`[4 M | Jul 2023 | UE19CS353]`

> **Answer:**
>
> **When to use Builder Pattern:**
> - Object construction involves many steps or optional parameters ("telescoping constructor" problem).
> - Same construction process must create different representations.
> - You want to construct objects step-by-step.
> - Example: Building a `Pizza` with optional toppings, a `QueryBuilder` constructing SQL.
>
> **Factory Method vs Abstract Factory:**
>
> | Feature | Factory Method | Abstract Factory |
> |---|---|---|
> | Creates | One product | Family of related products |
> | How | Subclasses override factory method | Concrete factory classes for each product family |
> | Level | Class-level (uses inheritance) | Object-level (uses composition) |
> | Example | `CarFactory.createVehicle()` | `GUIFactory` creating `Button + Checkbox + TextField` for Windows vs Mac |
> | Use when | One product whose subtype varies | Multiple related products that must be used together |

---

**Q111.** What are Design Patterns? Describe types and pros/cons.

`[6 M | Dec 2023 | UE19CS353; Jan–May 2024 | UE19CS353]`

> **Answer:**
>
> **Definition:** A design pattern is a general, reusable solution to a commonly occurring problem in a given context in software design. It is not finished code — it is a template or blueprint describing how to solve a problem. Introduced by Gang of Four (GoF): Gamma, Helm, Johnson, Vlissides — "Design Patterns: Elements of Reusable OO Software" (1994).
>
> **Types (GoF — 23 patterns in 3 categories):**
>
> | Category | Focus | Examples |
> |---|---|---|
> | **Creational** | Object creation mechanisms | Singleton, Factory Method, Abstract Factory, Builder, Prototype |
> | **Structural** | Class/object composition into larger structures | Adapter, Facade, Proxy, Composite, Decorator, Bridge, Flyweight |
> | **Behavioral** | Communication and responsibility between objects | Observer, Strategy, Command, Iterator, Chain of Responsibility, Template Method, State |
>
> **Pros:**
> - Provide common vocabulary for design discussions.
> - Capture proven, tested design expertise.
> - Speed up development by providing ready-made solutions.
> - Improve code readability and reusability.
> - Reduce the risk of design flaws.
>
> **Cons:**
> - Can add complexity (unnecessary abstraction layers).
> - May be overused or misapplied (pattern abuse).
> - Can lead to "pattern fever" — using patterns where simpler solutions would suffice.
> - Some patterns add object proliferation or performance overhead.

---

**Q112.** What is a Design Pattern? Describe the essential elements of a design pattern.

`[6 M | Jul 2023 | UE19CS353]`

> **Answer:**
>
> **Four Essential Elements (GoF):**
>
> 1. **Pattern Name:** A handle to describe the design problem, solution, and consequences in one or two words. Creates a vocabulary for communicating about design. E.g., "Singleton", "Observer", "Decorator".
>
> 2. **The Problem:** Describes when to apply the pattern — what problem it solves in what context. May describe specific design problems or class/object structures causing inflexibility. May include preconditions for application.
>
> 3. **The Solution:** Describes the elements that make up the design, their relationships, responsibilities, and collaborations. It is an abstract description — a template applicable in many contexts. NOT a specific concrete implementation.
>
> 4. **The Consequences:** The results and trade-offs of applying the pattern — space/time trade-offs, language/implementation issues, flexibility, extensibility, portability. Helps evaluate whether the pattern fits a particular design context.

---

**Q113.** Define patterns and frameworks. List major differences between patterns and frameworks.

`[6 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **Pattern:** A named, proven solution to a recurring design problem. It is abstract — a description of relationships and collaborations, not executable code. Language-independent.
>
> **Framework:** A skeletal, semi-complete application — a reusable design expressed in concrete classes. It is executable and specific to a domain or technology. Defines the architecture for a category of software.
>
> | Feature | Pattern | Framework |
> |---|---|---|
> | Form | Abstract description (template) | Concrete code (classes, interfaces) |
> | Reuse type | Design reuse | Code reuse |
> | Language | Language-independent | Language/platform-specific |
> | Scale | Micro-level (one class or few classes) | Macro-level (entire application structure) |
> | Customization | Applied by writing code following the template | Extended by subclassing or configuring |
> | Execution | Not executable | Executable (framework calls your code) |
> | Control | Pattern doesn't control flow | Framework controls flow (Hollywood Principle) |
> | Examples | Singleton, Observer, Factory | Spring, Hibernate, Django, Rails |

---

**Q114.** Fill in the blanks.

`[2 M | May 2023 | UE20CS352]`

> **Answer:**
>
> i) **Prototype** pattern refers to creating duplicate objects while keeping performance in mind.
>
> ii) **Adapter** pattern provides the interface according to client requirement while using the services of a class with a different interface.

---

## 22. Structural Design Patterns

> **Frequency: Very High**

---

**Q115.** Give the UML diagram of the Adapter pattern and briefly describe each component.

`[7–8 M | Dec 2023 | UE19CS353; Jan–May 2024 | UE19CS353]`

> **Answer:**
>
> **Adapter Pattern — Also known as Wrapper.**
> **Intent:** Convert the interface of a class into another interface that the client expects. Allows incompatible interfaces to work together.
>
> **UML Diagram (Object Adapter):**
> ```mermaid
> classDiagram
>  class Target {
>  <<interface>>
>  +request() void
>  }
>  class Adapter {
>  -Adaptee adaptee
>  +request() void
>  }
>  class Adaptee {
>  +specificRequest() void
>  }
>  class Client
>  Target <|.. Adapter : implements
>  Adapter --> Adaptee : wraps
>  Client --> Target : uses
> ```
>
> **Participants:**
>
> | Participant | Description |
> |---|---|
> | **Target** | The interface the Client expects to use (`request()`) |
> | **Client** | Uses the Target interface; works only with Target |
> | **Adapted** | Existing class with useful behavior but incompatible interface (`specificRequest()`) |
> | **Adapter** | Wraps the Adapted; implements Target; translates `request()` calls to `specificRequest()` |
>
> **Two Variants:**
> - **Object Adapter:** Uses composition — Adapter holds an instance of Adapted. More flexible; can adapt subclasses of Adapted.
> - **Class Adapter:** Uses multiple inheritance — Adapter extends both Target and Adapted. Only in languages supporting multiple inheritance.
>
> **Example:**
> ```java
> interface MediaPlayer { void play(String type, String file); }
> class AdvancedPlayer { void playVlc(String f){} void playMp4(String f){} }
> class MediaAdapter implements MediaPlayer {
>     AdvancedPlayer player = new AdvancedPlayer();
>     public void play(String type, String file) {
>         if (type.equals("vlc")) player.playVlc(file);
>         else if (type.equals("mp4")) player.playMp4(file);
>     }
> }
> ```

---

**Q116.** AudioPlayer needs to play vlc and mp4 using AdvancedMediaPlayer. Identify design pattern, justify, draw class diagram.

`[6 M | Jul 2023 | UE19CS353; May 2023 | UE19CS353]`

> **Answer:**
>
> **Pattern: Adapter Pattern**
>
> **Justification:** `AudioPlayer` implements `MediaPlayer` and can play mp3 by default. `AdvancedMediaPlayer` has the ability to play vlc and mp4 but has a different interface. To make `AudioPlayer` support other formats without changing its interface or the `AdvancedMediaPlayer` code, an **Adapter** is introduced that translates `play(type, file)` calls into the appropriate `AdvancedMediaPlayer` method calls.
>
> **Class Diagram:**
> ```mermaid
> classDiagram
>  class MediaPlayer {

 <<interface>>

 +play(type, file)

 }

>  class AdvancedMediaPlayer {
 <<interface>>
 +playVlc(file)
 +playMp4(file)
 }
>  class AudioPlayer { +play(type, file) }
>  class MediaAdapter { +play(type, file) }
>  class VlcPlayer { +playVlc(file) }
>  class Mp4Player { +playMp4(file) }
>  MediaPlayer <|.. AudioPlayer
>  MediaPlayer <|.. MediaAdapter
>  AdvancedMediaPlayer <|.. VlcPlayer
>  AdvancedMediaPlayer <|.. Mp4Player
>  MediaAdapter --> AdvancedMediaPlayer : wraps
> ```
>
> ```java
> class MediaAdapter implements MediaPlayer {
>     AdvancedMediaPlayer advPlayer;
>     MediaAdapter(String type) {
>         if (type.equals("vlc")) advPlayer = new VlcPlayer();
>         else if (type.equals("mp4")) advPlayer = new Mp4Player();
>     }
>     public void play(String type, String file) {
>         if (type.equals("vlc")) advPlayer.playVlc(file);
>         else advPlayer.playMp4(file);
>     }
> }
> class AudioPlayer implements MediaPlayer {
>     public void play(String type, String file) {
>         if (type.equals("mp3")) System.out.println("Playing mp3: " + file);
>         else if (type.equals("vlc") || type.equals("mp4")) {
>             MediaAdapter adapter = new MediaAdapter(type);
>             adapter.play(type, file);
>         }
>     }
> }
> ```

---

**Q117.** Write briefly about the Adapter Structural Design Pattern — intent, problem, solution, example.

`[6 M | Jul 2023 | UE20CS352]`

> **Answer:** See Q115 and Q116 for complete answer (intent, participants, diagram, example).

---

**Q118.** What is a Proxy pattern? Which are the three main variations of proxy pattern?

`[6 M | Jul 2023 | UE19CS353]`

> **Answer:**
>
> **Proxy Pattern — Intent:** Provide a surrogate or placeholder for another object to control access to it. The client does not communicate directly with the real object — it talks to the proxy.
>
> **Structure:**
> ```mermaid
> classDiagram
>  class Subject {

 <<interface>>

 +request()

 }

>  class RealSubject { +request() }
>  class Proxy {
>  -RealSubject realSubject
>  +request()
>  }
>  class Client
>  Subject <|.. RealSubject
>  Subject <|.. Proxy
>  Proxy --> RealSubject : delegates to
>  Client --> Subject : uses
> ```
>
> **Three Main Variations:**
>
> **1. Remote Proxy:**
> Represents an object in a different address space (on a remote server). The proxy handles all communication details (serialization, network calls). Client thinks it's talking to a local object.
> *Example:* Java RMI (Remote Method Invocation) stub.
>
> **2. Virtual Proxy (Lazy Initialization):**
> Creates expensive objects on demand. The proxy holds a placeholder and only creates the real object when it is first needed.
> *Example:* Loading large images — proxy shows a placeholder until user clicks/scrolls to it, then loads the real image.
>
> **3. Protection Proxy:**
> Controls access to the real object based on permissions. Checks access rights before forwarding requests.
> *Example:* A `ProxyFile` that checks if a user has read/write permission before calling `RealFile.read()` or `RealFile.write()`.

---

**Q119.** Implement the Library Book scenario using Proxy pattern. Write class diagram and code snippet. State which type.

`[6 M | Dec 2023 | UE20CS352; Jul 2023 | UE20CS352]`

> **Answer:**
>
> **Type: Virtual Proxy** (lazy loading — full details fetched only when needed)
>
> **Class Diagram:**
> ```mermaid
> classDiagram
>  class Book {

 <<interface>>

 +getDetails() String

 +issue()

 +returnBook()

 }

>  class RealBook {
>  -String title
>  -String author
>  -String isbn
>  -String publisher
>  -boolean availability
>  +getDetails() String
>  +issue()
>  +returnBook()
>  }
>  class ProxyBook {
>  -String title
>  -String author
>  -boolean availability
>  -RealBook realBook
>  +getDetails() String
>  +issue()
>  +returnBook()
>  }
>  Book <|.. RealBook
>  Book <|.. ProxyBook
>  ProxyBook --> RealBook : lazy loads
> ```
>
> **Code:**
> ```java
> interface Book {
>     String getDetails();
>     void issue();
>     void returnBook();
> }
>
> class RealBook implements Book {
>     private String title, author, isbn, publisher, description;
>     private boolean available;
>
>     RealBook(String title, String author, boolean available) {
>         this.title = title; this.author = author; this.available = available;
>         loadFromDatabase(); // expensive operation
>     }
>     private void loadFromDatabase() {
>         System.out.println("Loading full details from DB for: " + title);
>         this.isbn = "ISBN-001"; this.publisher = "Pearson";
>         this.description = "Full description loaded...";
>     }
>     public String getDetails() { return title + " | " + author + " | " + isbn; }
>     public void issue() { System.out.println("Book issued: " + title); available = false; }
>     public void returnBook() { System.out.println("Book returned: " + title); available = true; }
> }
>
> class ProxyBook implements Book {
>     private String title, author;
>     private boolean available;
>     private RealBook realBook = null; // not loaded yet
>
>     ProxyBook(String title, String author, boolean available) {
>         this.title = title; this.author = author; this.available = available;
>     }
>     public String getDetails() { return title + " | " + author + " | Available: " + available; }
>     public void issue() {
>         if (realBook == null) realBook = new RealBook(title, author, available); // lazy load
>         realBook.issue();
>     }
>     public void returnBook() {
>         if (realBook == null) realBook = new RealBook(title, author, available);
>         realBook.returnBook();
>     }
> }
> ```
> Listing all books uses `ProxyBook.getDetails()` — no DB load. Selecting a book triggers `issue()` — RealBook is created and full details fetched.

---

**Q120.** Implement the Student grades scenario using Proxy pattern. Write class diagram and code.

`[6 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> **Type: Virtual Proxy** — Student list shows only Name, SRN, Dept. Grades loaded on demand.
>
> ```java
> interface Student {
>     String getSummary();    // lightweight — always available
>     void viewGrades();      // heavyweight — loaded on demand
> }
>
> class RealStudent implements Student {
>     private String name, srn, dept;
>     private Map<String, String> grades;
>
>     RealStudent(String name, String srn, String dept) {
>         this.name = name; this.srn = srn; this.dept = dept;
>         loadGradesFromDB(); // expensive
>     }
>     private void loadGradesFromDB() {
>         grades = new HashMap<>();
>         grades.put("OOAD", "A"); grades.put("OS", "B+"); // simulated load
>         System.out.println("Grades loaded from DB for " + srn);
>     }
>     public String getSummary() { return srn + " | " + name + " | " + dept; }
>     public void viewGrades() { System.out.println("Grades: " + grades); }
> }
>
> class ProxyStudent implements Student {
>     private String name, srn, dept;
>     private RealStudent realStudent = null;
>
>     ProxyStudent(String name, String srn, String dept) {
>         this.name = name; this.srn = srn; this.dept = dept;
>     }
>     public String getSummary() { return srn + " | " + name + " | " + dept; }
>     public void viewGrades() {
>         if (realStudent == null) realStudent = new RealStudent(name, srn, dept);
>         realStudent.viewGrades();
>     }
> }
> ```

---

**Q121.** Implement Music Library scenario using Proxy pattern.

`[6 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Type: Virtual Proxy** — song list shows title, artist, duration. Media stream loaded on play.
>
> ```java
> interface Song {
>     String getSummary();
>     void play();
> }
>
> class RealSong implements Song {
>     private String title, artist; private int durationSecs;
>     private byte[] mediaStream;
>
>     RealSong(String title, String artist, int dur) {
>         this.title = title; this.artist = artist; this.durationSecs = dur;
>         System.out.println("Loading media stream from DB for: " + title);
>         this.mediaStream = new byte[1024]; // simulated stream load
>     }
>     public String getSummary() { return title + " | " + artist + " | " + durationSecs + "s"; }
>     public void play() { System.out.println("Playing: " + title + " by " + artist); }
> }
>
> class ProxySong implements Song {
>     private String title, artist; private int durationSecs;
>     private RealSong realSong = null;
>
>     ProxySong(String t, String a, int d) { title=t; artist=a; durationSecs=d; }
>     public String getSummary() { return title + " | " + artist + " | " + durationSecs + "s"; }
>     public void play() {
>         if (realSong == null) realSong = new RealSong(title, artist, durationSecs);
>         realSong.play();
>     }
> }
> ```

---

**Q122.** Which design pattern is depicted in the HomeManager diagram? Describe it. Give pseudo code.

`[8 M | Dec 2023 | UE19CS353; May 2023 | UE20CS352]`

> **Answer:**
>
> **Pattern: Facade Pattern**
>
> **Description:** Provides a unified, simplified interface to a set of complex subsystem interfaces. Makes the subsystem easier to use by hiding its complexity. The Facade is a higher-level interface.
>
> **Structure:**
> ```mermaid
> classDiagram
>  class HomeManager {
>  -Lights lights
>  -Thermostat thermo
>  -SecuritySystem security
>  -MusicSystem music
>  +arriveHome()
>  +leaveHome()
>  +bedtime()
>  }
>  class Lights { +on(); +off(); +dim(int) }
>  class Thermostat { +setTemp(int) }
>  class SecuritySystem { +arm(); +disarm() }
>  class MusicSystem { +play(String); +stop() }
>  class Client
>  Client --> HomeManager : uses
>  HomeManager --> Lights
>  HomeManager --> Thermostat
>  HomeManager --> SecuritySystem
>  HomeManager --> MusicSystem
> ```
>
> **Pseudo code:**
> ```java
> class Lights { void on(){} void off(){} void dim(int level){} }
> class Thermostat { void setTemp(int t){} }
> class SecuritySystem { void arm(){} void disarm(){} }
> class MusicSystem { void play(String song){} void stop(){} }
>
> class HomeManager {  // FACADE
>     Lights lights = new Lights();
>     Thermostat thermo = new Thermostat();
>     SecuritySystem security = new SecuritySystem();
>     MusicSystem music = new MusicSystem();
>
>     void arriveHome() {
>         security.disarm();
>         lights.on();
>         thermo.setTemp(22);
>         music.play("Welcome playlist");
>     }
>
>     void leaveHome() {
>         lights.off();
>         thermo.setTemp(18);
>         security.arm();
>         music.stop();
>     }
>
>     void bedtime() {
>         lights.dim(10);
>         thermo.setTemp(20);
>         security.arm();
>         music.stop();
>     }
> }
>
> // Client:
> HomeManager home = new HomeManager();
> home.arriveHome(); // one call — internally coordinates 4 subsystems
> ```

---

**Q123.** Identify structural pattern in the HomeManager diagram. Justify. Write code for constructor and methods.

`[6 M | May 2023 | UE20CS352]`

> **Answer:** See Q122 — the pattern is **Facade**. The class diagram and code with constructor and methods are provided there.

---

**Q124.** For the complex subsystem case study, identify the appropriate structural design pattern. Write the class structure.

`[6 M | May 2023 | UE19CS353]`

> **Answer:**
>
> **Pattern: Facade Pattern** (for complex subsystem access) or **Adapter Pattern** (for incompatible interfaces).
>
> **If subsystem has many interdependent classes:** Use **Facade** — one class to simplify access.
>
> **If existing class has wrong interface:** Use **Adapter** — wrap it to match expected interface.
>
> **Facade Class Structure:**
> ```mermaid
> classDiagram
>  class Facade {
>  -SubsystemA a
>  -SubsystemB b
>  -SubsystemC c
>  +operation1()
>  +operation2()
>  }
>  class SubsystemA { +operationA1(); +operationA2() }
>  class SubsystemB { +operationB1(); +operationB2() }
>  class SubsystemC { +operationC() }
>  class Client
>  Client --> Facade : uses
>  Facade --> SubsystemA
>  Facade --> SubsystemB
>  Facade --> SubsystemC
> ```

---

**Q125.** When to use Behavioral patterns? Describe Interpreter and Iterator pattern in a line or two.

`[4 M | Dec 2023 | UE20CS352]`

> **Answer:**
>
> **When to use Behavioral Patterns:** When you need to define how objects communicate, how responsibilities are distributed, and how algorithms are encapsulated. Use when you want to decouple the sender of a request from the receiver, or when you need to vary algorithms independently from clients.
>
> **Interpreter Pattern:** Given a language, define a representation for its grammar along with an interpreter that uses that representation to interpret sentences. Used for: SQL parsers, regular expressions, mathematical expression evaluators, scripting languages.
>
> **Iterator Pattern:** Provides a way to access elements of an aggregate object (collection) sequentially without exposing its underlying representation. Separates traversal logic from the collection. Used in Java's `Iterator<E>` interface with `hasNext()` and `next()` methods.

## 23. Behavioral Design Patterns

> **Frequency: Very High**

---

**Q126.** Explain the Chain of Responsibility behavioral pattern — intent, structure, and benefits.

`[6 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> **Intent:** Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.
>
> **Structure:**
> ```mermaid
> classDiagram
>  class Handler {
>  <<abstract>>
>  -Handler successor
>  +setSuccessor(Handler)
>  +handleRequest(req)*
>  }
>  class ConcreteHandlerA {
>  +handleRequest(req)
>  }
>  class ConcreteHandlerB {
>  +handleRequest(req)
>  }
>  class Client
>  Handler <|-- ConcreteHandlerA
>  Handler <|-- ConcreteHandlerB
>  Handler --> Handler : successor
>  Client --> Handler : sends request to
> ```
>
> **Example:**
> ```java
> abstract class Handler {
>     Handler successor;
>     void setSuccessor(Handler s) { successor = s; }
>     abstract void handleRequest(int amount);
> }
> class Manager extends Handler {
>     void handleRequest(int amount) {
>         if (amount <= 10000) System.out.println("Manager approved: " + amount);
>         else if (successor != null) successor.handleRequest(amount);
>     }
> }
> class Director extends Handler {
>     void handleRequest(int amount) {
>         if (amount <= 50000) System.out.println("Director approved: " + amount);
>         else if (successor != null) successor.handleRequest(amount);
>     }
> }
> // Setting up chain:
> Manager mgr = new Manager(); Director dir = new Director();
> mgr.setSuccessor(dir);
> mgr.handleRequest(8000);  // Manager approved
> mgr.handleRequest(30000); // Director approved
> ```
>
> **Benefits:**
> - Reduced coupling between sender and receiver — sender only knows the first handler.
> - Flexibility in assigning responsibilities — chain can be changed at runtime.
> - Follows Open/Closed Principle — add new handlers without changing existing ones.
> - Request handled at the appropriate level automatically.

---

**Q127.** Describe the Chain of Responsibilities pattern with an example.

`[4 M | May 2023 | UE19CS353]`

> **Answer:** See Q126 for complete description and example.

---

**Q128.** Briefly describe the intent, structure and participants of the Chain of Responsibility design pattern.

`[7 M | Jan–May 2024 | UE19CS353]`

> **Answer:**
>
> **Intent:** Decouple the sender of a request from its handler. Pass the request along a chain of potential handlers until one handles it or the chain ends.
>
> **Participants:**
>
> | Participant | Role |
> |---|---|
> | **Handler** | Defines interface for handling requests; has optional reference to the next handler (successor) |
> | **ConcreteHandler** | Handles requests it is responsible for; if it can't handle, passes to its successor; each knows its successor |
> | **Client** | Initiates the request and sends it to the first handler in the chain |
>
> **Structure:** See Q126 UML diagram.
>
> **Collaboration:** Client sends to first handler → if handled, done; if not, passed to next → continues until handled or chain ends (unhandled request is dropped or raises error).
>
> **Key design decisions:** Whether to allow the chain to end without handling (let it go), or have a default handler at the end. Chain can be configured dynamically.

---

**Q129.** Email handling scenario — identify behavioral pattern, describe it, draw class diagram.

`[10 M | Dec 2023 | UE20CS352; Dec 2023 | UE18CS353]`

> **Answer:**
>
> **Pattern: Chain of Responsibility**
>
> **Justification:** Incoming emails need to pass through multiple handlers (detectors). Each detector checks if it can handle the email type. If yes, it handles it; if not, it passes to the next detector. The chain of detectors is set up at runtime — perfect Chain of Responsibility use case.
>
> **Class Diagram:**
> ```mermaid
> classDiagram
>  class EmailHandler {
>  <<abstract>>
>  -EmailHandler successor
>  +setSuccessor(EmailHandler)
>  +handle(Email)*
>  }
>  class SpamHandler { +handle(Email) }
>  class FanMailHandler { +handle(Email) }
>  class ComplaintHandler { +handle(Email) }
>  class FeatureRequestHandler { +handle(Email) }
>  EmailHandler <|-- SpamHandler
>  EmailHandler <|-- FanMailHandler
>  EmailHandler <|-- ComplaintHandler
>  EmailHandler <|-- FeatureRequestHandler
>  EmailHandler --> EmailHandler : successor
> ```
>
> **Code:**
> ```java
> class Email { String type; String content; Email(String t, String c){type=t;content=c;} }
>
> abstract class EmailHandler {
>     protected EmailHandler successor;
>     void setSuccessor(EmailHandler s) { successor = s; }
>     abstract void handle(Email email);
> }
>
> class SpamHandler extends EmailHandler {
>     void handle(Email e) {
>         if (e.type.equals("Spam")) System.out.println("SpamHandler: Deleting spam");
>         else if (successor != null) successor.handle(e);
>         else System.out.println("Unhandled email: " + e.type);
>     }
> }
> class FanMailHandler extends EmailHandler {
>     void handle(Email e) {
>         if (e.type.equals("FanMail")) System.out.println("FanMailHandler: Archiving fan mail");
>         else if (successor != null) successor.handle(e);
>     }
> }
> class ComplaintHandler extends EmailHandler {
>     void handle(Email e) {
>         if (e.type.equals("Complaint")) System.out.println("ComplaintHandler: Escalating complaint");
>         else if (successor != null) successor.handle(e);
>     }
> }
> class FeatureRequestHandler extends EmailHandler {
>     void handle(Email e) {
>         if (e.type.equals("FeatureRequest")) System.out.println("FeatureRequest: Logged to backlog");
>         else if (successor != null) successor.handle(e);
>     }
> }
>
> // Setup chain: Spam → FanMail → Complaint → FeatureRequest
> SpamHandler spam = new SpamHandler();
> FanMailHandler fan = new FanMailHandler();
> ComplaintHandler complaint = new ComplaintHandler();
> FeatureRequestHandler feature = new FeatureRequestHandler();
> spam.setSuccessor(fan); fan.setSuccessor(complaint); complaint.setSuccessor(feature);
>
> spam.handle(new Email("Complaint","Refund please"));   // ComplaintHandler handles
> spam.handle(new Email("Spam","Win a prize!"));          // SpamHandler handles
> spam.handle(new Email("FeatureRequest","Add dark mode"));// FeatureRequestHandler handles
> ```

---

**Q130.** Stock buy/sell command pattern diagram — identify pattern, describe, give pseudo code.

`[8 M | Dec 2023 | UE19CS353]`

> **Answer:**
>
> **Pattern: Command Pattern**
>
> **Description:** Encapsulates a request as an object, thereby allowing parameterization of clients with requests, queuing, logging, and supporting undoable operations.
>
> **Participants:**
>
> | Participant | Role |
> |---|---|
> | **Command** | Interface declaring `execute()` (and optionally `undo()`) |
> | **ConcreteCommand** | Implements Command; binds receiver to action |
> | **Invoker** | Holds and fires commands (`placeOrders()`) |
> | **Receiver** | Actual business logic (`Stock.buy()`, `Stock.sell()`) |
> | **Client** | Creates ConcreteCommand and sets its Receiver |
>
> **Code:**
> ```java
> interface Order { void execute(); }
>
> class Stock {
>     String name; int quantity;
>     Stock(String n, int q) { name=n; quantity=q; }
>     void buy()  { System.out.println("Bought  " + quantity + " of " + name); }
>     void sell() { System.out.println("Sold    " + quantity + " of " + name); }
> }
>
> class BuyStock implements Order {
>     Stock stock;
>     BuyStock(Stock s) { stock = s; }
>     public void execute() { stock.buy(); }
> }
> class SellStock implements Order {
>     Stock stock;
>     SellStock(Stock s) { stock = s; }
>     public void execute() { stock.sell(); }
> }
>
> class Broker {  // Invoker
>     List<Order> orders = new ArrayList<>();
>     void takeOrder(Order o) { orders.add(o); }
>     void placeOrders() {
>         for (Order o : orders) o.execute();
>         orders.clear();
>     }
> }
>
> // Client:
> Stock s1 = new Stock("APPLE", 10);
> Broker broker = new Broker();
> broker.takeOrder(new BuyStock(s1));
> broker.takeOrder(new SellStock(s1));
> broker.placeOrders();
> // Output: Bought 10 of APPLE
> //         Sold   10 of APPLE
> ```

---

**Q131.** Describe the structure of the solution for the Iterator pattern.

`[4 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Iterator Pattern — Structure:**
>
> ```mermaid
> classDiagram
>  class Iterator~T~ { <<interface>>; +hasNext() boolean; +next() T }
>  class Iterable~T~ { <<interface>>; +iterator() Iterator~T~ }
>  class ConcreteIterator~T~ {
>  -ConcreteCollection collection
>  -int index
>  +hasNext() boolean
>  +next() T
>  }
>  class ConcreteCollection~T~ {
>  -List~T~ items
>  +iterator() Iterator~T~
>  +getItem(int) T
>  +size() int
>  }
>  Iterator <|.. ConcreteIterator
>  Iterable <|.. ConcreteCollection
>  ConcreteCollection --> ConcreteIterator : creates
> ```
>
> **Collaboration:**
> 1. Client calls `collection.iterator()` to get a `ConcreteIterator`.
> 2. Client calls `iterator.hasNext()` — returns true if elements remain.
> 3. Client calls `iterator.next()` — returns current element and advances cursor.
> 4. Collection's internal structure is never exposed to the client.
>
> **Example:**
> ```java
> class NameIterator implements Iterator<String> {
>     String[] names; int index = 0;
>     NameIterator(String[] names) { this.names = names; }
>     public boolean hasNext() { return index < names.length; }
>     public String next() { return names[index++]; }
> }
> ```

---

**Q132.** Implement Logging System scenario using Chain of Responsibility pattern — class diagram and code.

`[6 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Chain setup:** ConsoleLogger → ErrorLogger → DebugLogger
>
> **Class Diagram:**
> ```
> AbstractLogger (abstract)
> + INFO = 1, ERROR = 2, DEBUG = 3 {static constants}
> - level: int
> - nextLogger: AbstractLogger
> + setNextLogger(l)
> + logMessage(level, message)
>   { if this.level <= level: write(message); else nextLogger.logMessage() }
> + write(message)  ← abstract
>         △
>   ────────────────────────
>   │          │            │
> ConsoleLogger ErrorLogger DebugLogger
> + write()     + write()   + write()
> ```
>
> **Code:**
> ```java
> abstract class AbstractLogger {
>     static final int INFO = 1, ERROR = 2, DEBUG = 3;
>     int level;
>     AbstractLogger nextLogger;
>
>     void setNextLogger(AbstractLogger next) { this.nextLogger = next; }
>
>     void logMessage(int level, String message) {
>         if (this.level <= level) write(message);
>         if (nextLogger != null) nextLogger.logMessage(level, message);
>     }
>     abstract protected void write(String message);
> }
>
> class ConsoleLogger extends AbstractLogger {
>     ConsoleLogger(int level) { this.level = level; }
>     protected void write(String msg) { System.out.println("Console: " + msg); }
> }
> class ErrorLogger extends AbstractLogger {
>     ErrorLogger(int level) { this.level = level; }
>     protected void write(String msg) { System.out.println("Error File: " + msg); }
> }
> class DebugLogger extends AbstractLogger {
>     DebugLogger(int level) { this.level = level; }
>     protected void write(String msg) { System.out.println("Debug File: " + msg); }
> }
>
> // Build the chain: Console → Error → Debug
> AbstractLogger console = new ConsoleLogger(AbstractLogger.INFO);
> AbstractLogger error   = new ErrorLogger(AbstractLogger.ERROR);
> AbstractLogger debug   = new DebugLogger(AbstractLogger.DEBUG);
> console.setNextLogger(error);
> error.setNextLogger(debug);
>
> // Usage:
> console.logMessage(AbstractLogger.INFO,  "User logged in");   // Console only
> console.logMessage(AbstractLogger.ERROR, "DB connection fail"); // Console + Error
> console.logMessage(AbstractLogger.DEBUG, "Variable x = 42");   // Console + Error + Debug
> ```

---

## 24. Anti-Patterns

> **Frequency: High** — at least one question in every paper

---

**Q133.** What is an Anti-pattern? Briefly describe the Vendor Lock-in anti-pattern.

`[5–6 M | Dec 2023 | UE19CS353; Dec 2023 | UE20CS352]`

> **Answer:**
>
> **Anti-Pattern Definition:** An AntiPattern is a literary form that describes a commonly occurring solution to a problem that generates decidedly **negative consequences**. It is a "Negative Solution" — recognized as a poor way to solve a problem. Studying anti-patterns helps avoid reinventing bad solutions.
>
> **Vendor Lock-In Anti-Pattern:**
>
> **Problem:** A software project adopts a vendor's product technology (database, framework, OS, cloud provider) and becomes completely dependent on it. The application cannot function without that vendor's specific implementation.
>
> **Symptoms:**
> - Commercial product upgrades drive the application's maintenance cycle.
> - Promised vendor features are delayed or never delivered.
> - The product diverges significantly from advertised open standards.
> - Migrating to another vendor requires a complete rewrite.
> - Application code contains vendor-specific API calls throughout.
>
> **Typical Causes:**
> - Product selected purely on marketing/sales information without technical inspection.
> - No architectural strategy to isolate the application from direct product dependency.
> - Application programming requires in-depth product-specific knowledge.
> - Complexity of vendor technology exceeds actual application needs.
>
> **Refactored Solution — Isolation Layer:**
> Introduce an **abstraction layer** (interface/adapter) between the application and the vendor technology. The application depends only on the abstraction; the vendor-specific code is encapsulated in the isolation layer.
> ```
> Application Code → [Isolation Layer / Interface] → Vendor Product A
>                                                   → Vendor Product B (can switch)
> ```

---

**Q134.** What is the refactored solution to tackle the Vendor Lock-in Anti-pattern?

`[6 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> **Refactored Solution — Isolation Layer:**
>
> The key solution is to introduce an **Isolation Layer** that abstracts away the vendor-specific implementation.
>
> **Applicable when:**
> - Isolating from infrastructure changes (database, messaging, OS, cloud).
> - A more convenient programming interface is needed for the vendor product.
> - Consistent handling is needed across multiple underlying systems.
> - Multiple infrastructure products must be supported.
>
> **Implementation Steps:**
> 1. **Define an abstraction interface** that captures all operations the application needs.
> 2. **Create a concrete adapter** for each vendor product that implements this interface.
> 3. **Configure at startup** which vendor implementation to use (dependency injection).
> 4. **Application code** only depends on the abstraction — never on vendor-specific classes.
>
> **Example:**
> ```java
> // Isolation Layer (abstraction)
> interface DatabaseService {
>     void save(Object entity);
>     Object findById(int id);
>     void delete(int id);
> }
>
> // Vendor A implementation
> class OracleDatabaseService implements DatabaseService { /* Oracle-specific JDBC */ }
> // Vendor B implementation
> class MySQLDatabaseService  implements DatabaseService { /* MySQL-specific JDBC */ }
>
> // Application only uses DatabaseService — can switch vendors by changing config
> class OrderRepository {
>     DatabaseService db;
>     OrderRepository(DatabaseService db) { this.db = db; } // injected
>     void saveOrder(Order o) { db.save(o); }
> }
> ```
> Switching from Oracle to MySQL = change one configuration line, zero application code changes.

---

**Q135.** State the solution for Blob, Lava Flow, Vendor Lock-in, and Analysis Paralysis anti-patterns.

`[4 M | Jul 2023 | UE19CS353]`

> **Answer:**
>
> **Blob — Solution (Refactoring):**
> Redistribute responsibilities across multiple cohesive classes:
> 1. Identify cohesive clusters of attributes/methods in the Blob class.
> 2. Create new classes for each cluster.
> 3. Migrate attributes and methods to appropriate new classes.
> 4. Remove or reduce the Blob class; replace with a thin coordinator.
>
> **Lava Flow — Solution:**
> 1. Create an architectural rule: no new code depends on lava flow code.
> 2. Use static analysis tools to identify all usages.
> 3. Gradually refactor by creating proper replacements and deprecating/removing lava code.
> 4. Establish code review processes to prevent new lava flow from forming.
>
> **Vendor Lock-In — Solution:**
> Introduce an **Isolation Layer** (abstraction interface + adapters). Application depends on the interface, not the vendor. See Q134.
>
> **Analysis Paralysis — Solution:**
> Adopt **incremental development**:
> - Deliver working increments early and frequently.
> - Separate internal increments (infrastructure) from external increments (user-visible features).
> - Timebox analysis activities; set explicit "good enough" criteria.
> - Accept that analysis will never be complete — move forward iteratively.

---

**Q136.** What is an anti-pattern? State the solution for Blob and Vendor Lock-in anti-pattern.

`[4 M | May 2023 | UE19CS353]`

> **Answer:**
>
> **Anti-Pattern:** See Q133 definition.
>
> **Blob Solution:** See Q135 — redistribute responsibilities, create cohesive classes.
>
> **Vendor Lock-In Solution:** See Q134 — introduce Isolation Layer / abstraction interface.

---

**Q137.** Mention symptoms and typical causes for the Blob design anti-pattern.

`[8 M | Jul 2023 | UE20CS352]`

> **Answer:**
>
> **Blob Anti-Pattern:** A design where a single class has a disproportionately large share of responsibilities — a "God Object." Surrounded by simple data classes. Violates High Cohesion, Low Coupling, and Single Responsibility.
>
> **Symptoms and Consequences:**
> 1. Single class with a large number of attributes and operations — 60+ is a warning sign.
> 2. Disparate, unrelated collection of attributes and operations in one class — no cohesive theme.
> 3. Single class with association relationships to many other classes (high degree of coupling).
> 4. The class is difficult to reuse and test — too complex to load and understand.
> 5. May be expensive to load into memory even for simple operations.
> 6. Any change in a small part requires understanding and retesting the whole class.
> 7. Impossible to distribute work among team members — bottleneck.
>
> **Typical Causes:**
> 1. **Lack of OO architecture** — designed procedurally with objects as an afterthought.
> 2. **Lack of any architecture** — system grew without a design plan.
> 3. **Lack of architecture enforcement** — no code review or design standards.
> 4. **Incremental uncontrolled growth** — small additions over time accumulate into a Blob ("specified disaster").
> 5. Single developer syndrome — one person owns all functionality.
> 6. Misuse of the Controller pattern — controller becomes the doer instead of the delegator.

---

**Q138.** Explain with an example the steps for the refactored solution for the Blob Anti-pattern.

`[6 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Scenario:** A `CustomerManager` Blob class that handles customer data, payment, shipping, email notifications, and reporting.
>
> **Step 1: Identify clusters of related responsibilities**
> Group methods/attributes that logically belong together:
> - Cluster A: `name`, `email`, `address`, `getCustomerInfo()`, `updateProfile()` → Customer
> - Cluster B: `cardNumber`, `processPayment()`, `validateCard()` → PaymentService
> - Cluster C: `shipmentAddress`, `trackShipment()`, `calculateShipping()` → ShippingService
> - Cluster D: `sendWelcomeEmail()`, `sendOrderConfirmation()` → EmailService
>
> **Step 2: Identify "natural homes" — create new classes**
> ```mermaid
> flowchart LR
>  subgraph Before["Before (Blob)"]
>  CM["CustomerManager<br/>+ name, email, address<br/>+ cardNumber<br/>+ processPayment()<br/>+ validateCard()<br/>+ trackShipment()<br/>+ sendEmail()<br/>+ generateReport()"]
>  end
>  subgraph After["After (Refactored)"]
>  C2["Customer"]
>  PS["PaymentService"]
>  SS["ShippingService"]
>  ES["EmailService"]
>  RS["ReportService"]
>  CC["CustomerController<br/>(thin coordinator)"]
>  CC --> C2 & PS & SS & ES & RS
>  end
>  Before -- "refactor" --> After
> ```
>
> **Step 3: Remove redundant associations and migrate responsibilities**
> ```java
> class Customer { String name, email; void updateProfile(){} }
> class PaymentService { void processPayment(Customer c, double amount){} }
> class ShippingService { void shipOrder(Customer c, Order o){} }
> class EmailService { void sendConfirmation(Customer c, Order o){} }
>
> class CustomerController {  // thin coordinator
>     void placeOrder(Customer c, Order o) {
>         paymentService.processPayment(c, o.getTotal());
>         shippingService.shipOrder(c, o);
>         emailService.sendConfirmation(c, o);
>     }
> }
> ```
>
> **Step 4: Result** — Each class has one focused responsibility (High Cohesion). Each class is independently testable and reusable (Low Coupling). No more Blob.

---

**Q139.** Mention any two symptoms and any two typical causes for the Analysis Paralysis design anti-pattern.

`[4 M | May 2023 | UE20CS352]`

> **Answer:**
>
> **Analysis Paralysis:** The state of over-analyzing a system to the point where no design or implementation decisions are made — the project is perpetually "in analysis."
>
> **Two Symptoms:**
> 1. Multiple project restarts and model rework due to personnel changes or never-ending refinement — no stable analysis output.
> 2. Cost of analysis exceeds expectations without a predictable endpoint — analysis continues indefinitely without moving to design.
>
> **Two Typical Causes:**
> 1. Management assumes waterfall progression — belief that ALL analysis must be complete before ANY design begins; unwillingness to proceed with incomplete information.
> 2. More confidence in analysis than in design and implementation — team members feel "safer" doing analysis and avoid commitment to design decisions.

---

**Q140.** Differentiate between pattern and anti-pattern.

`[4 M | Jul 2023 | UE19CS353]`

> **Answer:**
>
> | Feature | Design Pattern | Anti-Pattern |
> |---|---|---|
> | Nature | General repeatable solution to a commonly occurring problem | A commonly occurring solution that generates decidedly negative consequences |
> | Outcome | Positive — improves design quality | Negative — introduces technical debt, fragility, complexity |
> | Action to take | Apply the pattern | Recognize and refactor away from it |
> | Purpose | Provides a proven template to follow | Documents what NOT to do; helps identify bad designs |
> | Examples | Singleton, Factory, Observer, Adapter | Blob, Lava Flow, Vendor Lock-In, Analysis Paralysis |
> | Origin | GoF (1994) — collected best practices | Brown et al. (AntiPatterns, 1998) — collected worst practices |
> | Learning value | Shows the right way | Shows what goes wrong and how to fix it |

---

**Q141.** What is an Anti-pattern? Briefly describe the Lava-Flow anti-pattern.

`[5 M | Jan–May 2024 | UE19CS353]`

> **Answer:**
>
> **Anti-Pattern:** See Q133 definition.
>
> **Lava Flow Anti-Pattern:**
>
> **Background/Metaphor:** Like hardened lava that permanently alters the landscape, Lava Flow is dead code or poorly-designed constructs that have "hardened" in the production system — everyone is afraid to remove them.
>
> **Problem:** A codebase contains large amounts of code that is no longer needed, poorly understood, or improperly designed — yet it remains because developers are afraid to remove it (it might break something). Nobody understands what it does or why it's there.
>
> **Symptoms:**
> - Frequent undocumented variables and code fragments scattered throughout the system.
> - Modules or functions with poor, unclear names (e.g., `doStuff()`, `tempFix2()`).
> - Dead code blocks that are commented out but never deleted.
> - Developers say "don't touch that — nobody knows what it does."
> - High percentage of code that was written for experiments or temporary fixes.
>
> **Typical Causes:**
> - Experimental/prototype code was promoted to production without cleanup.
> - Original developer left without documentation.
> - No code review process; code accumulated over many years.
> - Fear of breaking production system prevents removal.
>
> **Solution:**
> - Create architectural rule: no new code depends on lava flow code.
> - Use static analysis to identify all usages.
> - Gradually replace with well-designed alternatives.
> - Establish and enforce code review, documentation, and deprecation standards.

---

**Q142.** What are the significances of Anti-patterns and Generative patterns?

`[6 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **Significance of Anti-Patterns:**
> 1. Provide easily identifiable templates for common problems in development, architecture, and management.
> 2. Document real-world experience with recurring pitfalls — collective memory of what goes wrong.
> 3. Provide a common vocabulary for identifying and discussing problems (e.g., saying "Blob" immediately conveys the problem).
> 4. Help teams recognize warning signs early — before damage is irreversible.
> 5. Each anti-pattern includes a "refactored solution" — not just the problem, but the path out.
> 6. Prevent reinventing "bad solutions" — ensures common mistakes are not repeated.
>
> **Significance of Generative (Design) Patterns:**
> 1. Capture proven, time-tested solutions to recurring design problems.
> 2. Create a shared vocabulary for design discussions — improves team communication.
> 3. Promote design reuse over code reuse — frameworks and systems built on patterns are more flexible.
> 4. Help developers avoid well-known design pitfalls by showing what works.
> 5. Provide documentation and a record of design intent.
> 6. Speed up development by providing ready-to-apply solutions.
> 7. Improve code quality, maintainability, and extensibility.

---

## 25. SDLC Models & Requirements Engineering

> **Frequency: High** — mainly in UE18CS353

---

**Q143.** With a diagram, explain the Software Development Life Cycle (SDLC).

`[8 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> **SDLC** — A structured process/framework that describes the stages involved in developing and maintaining software from inception to retirement.
>
> **Phases:**
> ```mermaid
> flowchart LR
>  P["1. Planning"] --> R["2. Requirements<br/>Analysis"]
>  R --> D["3. System<br/>Design"]
>  D --> I["4. Implementation"]
>  I --> T["5. Testing"]
>  T --> Dep["6. Deployment"]
>  Dep --> M["7. Maintenance"]
>  M -- "change requests" --> R
> ```
>
> | Phase | Activities | Output |
> |---|---|---|
> | **Planning** | Feasibility study, project scope, schedule, budget | Project Plan |
> | **Requirements Analysis** | Gather, analyze, and document user needs | SRS Document |
> | **System Design** | Architecture, component design, data model | Design Document |
> | **Implementation** | Coding, unit testing | Source Code |
> | **Testing** | Integration, system, UAT testing | Test Reports |
> | **Deployment** | Release to production, user training | Live System |
> | **Maintenance** | Bug fixes, enhancements, performance tuning | Updated System |
>
> **Popular SDLC Models:** Waterfall, V-Model, Incremental, Evolutionary, Agile/Scrum, Spiral.

---

**Q144.** Discuss different phases in the development of software.

`[5 M | May 2023 | UE18CS353]`

> **Answer:** Refer to Q143 — the seven phases (Planning, Requirements, Design, Implementation, Testing, Deployment, Maintenance) with brief descriptions of activities and outputs.

---

**Q145.** List 8 activities that are performed during the feasibility study of requirement analysis.

`[8 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> 1. **Technical Feasibility** — Is the proposed solution technically achievable with current technology and expertise?
> 2. **Economic Feasibility** — Are the benefits worth the cost? Cost-benefit analysis; ROI estimation.
> 3. **Operational Feasibility** — Will users accept the system? Can the organization support it operationally?
> 4. **Legal/Ethical Feasibility** — Does the system comply with applicable laws, regulations, and ethical standards?
> 5. **Schedule Feasibility** — Can the project be completed within the required time frame?
> 6. **Resource Feasibility** — Are the required human resources, hardware, and software available?
> 7. **Risk Assessment** — Identify major risks (technical, financial, organizational) and their mitigation strategies.
> 8. **Alternative Analysis** — Evaluate alternative approaches (build vs. buy, COTS solutions, different architectures) to find the most feasible option.

---

**Q146.** Explain the advantages of the waterfall model.

`[4 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> **Waterfall Model:** A sequential, linear SDLC model where each phase must be fully completed before the next begins: Requirements → Design → Implementation → Testing → Deployment → Maintenance.
>
> **Advantages:**
> 1. **Simple and Easy to Understand:** Clear, structured phases with defined deliverables.
> 2. **Well-documented process:** Each phase produces complete documentation before moving on.
> 3. **Easy to Manage:** Rigid structure makes project management simpler — progress is easy to measure.
> 4. **Works well for small, well-understood projects:** When requirements are clear and stable.
> 5. **Testing is done in a structured phase:** Avoids intermixed testing and development.
> 6. **Works well for projects with fixed requirements:** Requirements defined upfront — no scope creep mid-development.
> 7. **Easy to track milestones:** Each phase completion is a clear milestone.

---

**Q147.** Illustrate the advantages and disadvantages of Agile SCRUM model with an example.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Agile SCRUM:** An iterative framework where work is done in short cycles called **Sprints** (1–4 weeks). Key roles: Product Owner, Scrum Master, Development Team. Key artifacts: Product Backlog, Sprint Backlog, Increment.
>
> **Advantages:**
> 1. **Early delivery** — Working software delivered at end of each Sprint.
> 2. **Adaptability** — Requirements can change between sprints — handles uncertainty well.
> 3. **Customer collaboration** — Product Owner continuously prioritizes and gives feedback.
> 4. **Transparency** — Daily standups, sprint reviews keep everyone informed.
> 5. **Team empowerment** — Self-organizing teams; higher morale and productivity.
>
> **Disadvantages:**
> 1. **Scope creep** — Continuous changes can lead to feature bloat if backlog is poorly managed.
> 2. **Hard to predict overall timeline and cost** — No fixed end date in early stages.
> 3. **Requires experienced team** — Less effective with inexperienced developers.
> 4. **Documentation is often minimal** — Future maintenance may suffer.
> 5. **Not suitable for large, complex projects** with many dependencies without scaling frameworks.
>
> **Example:** Building a food delivery app — Sprint 1: Login/Register, Sprint 2: Restaurant listing, Sprint 3: Cart and checkout, Sprint 4: Payment integration, Sprint 5: Order tracking. Customer reviews working app after each sprint and adjusts priorities.

---

**Q148.** Differentiate the Incremental model and Evolutionary Model.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> | Feature | Incremental Model | Evolutionary Model |
> |---|---|---|
> | Requirements | Defined upfront (mostly) | Partially defined; evolve over time |
> | Approach | Build system in increments; each adds functionality | System evolves through cycles; earlier versions are prototypes |
> | Product at each stage | Fully functional partial system | May be prototype or incomplete system that evolves |
> | Change handling | Limited — requirements are mostly fixed | Embraces change; system adapts as requirements clarify |
> | Risk | Lower — each increment is small and testable | Medium — evolving requirements may misdirect early iterations |
> | Customer involvement | After each increment | Continuous — feedback shapes each evolution |
> | Example | Building modules 1, 2, 3 of an ERP system separately | Building a prototype → refining based on feedback → building final system |
> | Models | Phased delivery, staged delivery | Spiral, Agile, Evolutionary prototyping |

---

**Q149.** Discuss the V Model of SDLC — phases, focus, deliverables, compare with waterfall.

`[8 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> **V-Model:** Extension of the Waterfall model. Each development phase has a corresponding testing phase. Testing activities are planned in parallel with development activities. Looks like a "V" shape.
>
> ```mermaid
> flowchart LR
>  RA["Requirements Analysis"] -.-> AT["Acceptance Testing"]
>  SD["System Design"] -.-> ST["System Testing"]
>  AD["Architecture Design"] -.-> IT["Integration Testing"]
>  MD["Module Design"] -.-> UT["Unit Testing"]
>  RA --> SD --> AD --> MD --> Impl["Implementation"] --> UT --> IT --> ST --> AT
> ```
>
> **Phases and Deliverables:**
>
> | Phase (Left — Dev) | Deliverable | Corresponding Test Phase (Right) |
> |---|---|---|
> | Requirements Analysis | SRS | Acceptance Test Plan |
> | System Design | Architecture Doc | System Test Plan |
> | High-Level Design | Module specs | Integration Test Plan |
> | Low-Level Design | Detailed design | Unit Test Cases |
> | Coding | Source code | Unit Testing execution |
>
> **Comparison with Waterfall:**
>
> | Feature | Waterfall | V-Model |
> |---|---|---|
> | Testing | After all development | Planned in parallel with each development phase |
> | Error detection | Late (after coding) | Early (test planning starts at requirements) |
> | Cost of defects | High (found late) | Lower (found earlier) |
> | Documentation | Sequential | Both sides of V documented together |

---

**Q150.** Using a skeletal system block diagram, compare Iterative and Incremental Development Models.

`[6 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **Incremental Model:**
> System is divided into increments; each increment adds new functionality. Requirements are known upfront.
> ```
> [Core Features] → [Add Feature B] → [Add Feature C] → [Full System]
>      ↓                  ↓                  ↓
>   Release 1          Release 2           Release 3
> ```
>
> **Iterative Model:**
> System is built as a complete (but rough) version first, then refined in each iteration. Requirements evolve.
> ```
> [Rough v1] → [Refine v2] → [Improve v3] → [Final System]
>     ↓              ↓              ↓
>  Prototype      Better          Final
> ```
>
> | Feature | Incremental | Iterative |
> |---|---|---|
> | Requirements | Mostly known upfront | May evolve |
> | Each cycle produces | New functionality added | Improved version of same system |
> | Starting point | Core feature set | Complete rough system |
> | Risk management | Low — small additions | Medium — rework may be needed |
> | Example | ERP modules delivered phase by phase | UI redesigned iteratively based on feedback |

---

**Q151.** Briefly explain about the Requirements Engineering Process with a neat diagram.

`[6 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> **Requirements Engineering (RE):** The process of defining, documenting, and maintaining requirements. Involves understanding what stakeholders need, analyzing those needs, and creating a specification.
>
> **RE Process Diagram:**
> ```
> Stakeholder needs
>         ↓
>  [Elicitation]    ← interviews, workshops, observation, questionnaires
>         ↓
>  [Analysis]       ← classify (functional/non-functional), resolve conflicts, prioritize
>         ↓
>  [Specification]  ← document in SRS; use cases, user stories, formal models
>         ↓
>  [Validation]     ← reviews, prototypes, test cases to verify requirements are correct
>         ↓
>  [Management]     ← version control of requirements; change management throughout project
> ```
>
> **Types of Requirements:**
> - **Functional:** What the system does (features, behaviors)
> - **Non-Functional:** How well it does it (performance, security, usability, scalability)
> - **Domain:** Rules from the application domain

---

**Q152.** What is wrong with the requirement statement "SR-4: All pages will load in acceptable amount of time"?

`[6 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **Problems with the requirement:**
>
> 1. **Not Measurable (Vague):** "Acceptable amount of time" is subjective — 1 second? 10 seconds? 30 seconds? There is no specific, testable threshold.
>
> 2. **Not Verifiable:** How do testers confirm this passes? Without a numeric criterion, acceptance testing cannot objectively pass or fail this requirement.
>
> 3. **Not Complete:** It does not specify: under what conditions (normal load? peak load?), from what location (local? international?), or which pages (all pages equally? home page vs. reports page?).
>
> **Quality Attributes Violated:** Measurability, Verifiability, Completeness, Unambiguousness.
>
> **Improved Requirement:**
> "SR-4: All primary pages (Home, Product Listing, Checkout) shall fully load within **3 seconds** under normal load conditions (up to 500 concurrent users) as measured from a client browser on a 10 Mbps internet connection. Under peak load (up to 2000 concurrent users), load time shall not exceed **8 seconds**."
>
> This is SMART: Specific, Measurable, Achievable, Relevant, Testable.

---

**Q153.** Describe what is a risk and the steps involved in managing risks.

`[8 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **Risk:** A potential problem that may or may not occur in the future, characterized by its probability (likelihood) and impact (severity if it occurs). Risks in software: technical risks (new technology fails), project risks (team member leaves), business risks (requirements change), external risks (vendor delays).
>
> **Risk Management Steps:**
>
> 1. **Risk Identification:** Brainstorm and list all potential risks. Use checklists, expert judgment, historical data. Output: Risk Register.
>
> 2. **Risk Analysis (Qualitative/Quantitative):** Assess each risk's probability and impact. Create a risk matrix (Probability × Impact). Prioritize high-probability, high-impact risks.
>
> 3. **Risk Planning (Response Strategy):** For each risk, decide:
>    - **Avoidance:** Change plan to eliminate risk.
>    - **Mitigation:** Reduce probability or impact.
>    - **Transfer:** Shift risk to a third party (insurance, contracts).
>    - **Acceptance:** Accept risk if mitigation cost exceeds impact.
>
> 4. **Risk Monitoring:** Continuously track identified risks; watch for trigger conditions; update the risk register throughout the project.
>
> 5. **Risk Control:** Execute risk response plans when risks materialize; re-assess after each sprint or project phase.

---

**Q154.** Describe the role of version control in a Configuration Management System.

`[4 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Configuration Management (CM):** The process of systematically handling changes to a system to ensure integrity over time. Involves identifying, controlling, and auditing changes to software artifacts.
>
> **Role of Version Control in CM:**
>
> 1. **Change Tracking:** Every change to any file is recorded with author, timestamp, and change description — full audit trail.
>
> 2. **Baseline Management:** A specific, approved set of software configuration items (SCIs) can be "frozen" as a baseline at any point (e.g., Release 1.0).
>
> 3. **Parallel Development:** Branching allows multiple developers to work on different features simultaneously without interfering with each other.
>
> 4. **Rollback Capability:** Any file or the entire system can be reverted to any previous version if a defect is introduced.
>
> 5. **Merging:** Changes from multiple branches can be merged back to the main branch with conflict detection.
>
> 6. **Collaboration:** Multiple developers can work on the same codebase without overwriting each other's changes.
>
> **Tools:** Git, SVN, Mercurial; hosted on GitHub, GitLab, Bitbucket.

---

**Q155.** Define: Sprint Burndown, Team Velocity Metric, Throughput, Cycle Time.

`[4 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> **Sprint Burndown:** A chart showing the amount of work remaining (story points or tasks) in the Sprint vs. time. The ideal line trends from total work at Sprint start to zero at Sprint end. Helps the team see if they are on track to complete the Sprint goal.
>
> **Team Velocity Metric:** The average number of story points completed by a Scrum team per Sprint over multiple sprints. Used to predict how much work can be done in future sprints and to plan releases. E.g., if average velocity is 30 points/sprint, a 150-point backlog requires ~5 sprints.
>
> **Throughput:** The number of user stories (or work items) completed per unit of time (per sprint or per week). Measures the rate of delivery. Higher throughput = more features delivered per sprint.
>
> **Cycle Time:** The elapsed time from when a work item is started to when it is completed (ready to ship). Shorter cycle time = faster delivery of individual items. Different from Lead Time (time from request to delivery, including waiting time).

---

**Q156.** Explain with a neat figure the different quality measures of high quality software.

`[5 M | Jun/Jul 2008 | MCA51]`

> **Answer:**
>
> **Software Quality** can be measured across multiple dimensions (McCall's Quality Factors):
>
> | Quality Factor | Measure |
> |---|---|
> | **Correctness** | Extent to which software meets specifications and fulfills mission objectives |
> | **Reliability** | Probability of failure-free operation for a specified time; MTBF (Mean Time Between Failures) |
> | **Efficiency** | Resource usage (CPU, memory, bandwidth) for a given function |
> | **Integrity** | Control of unauthorized access; data protection |
> | **Usability** | Effort required to learn and operate the system |
> | **Maintainability** | Effort to locate and fix defects; code complexity, documentation quality |
> | **Testability** | Effort required to test software and verify it meets requirements |
> | **Portability** | Effort to transfer software to a different hardware/OS environment |
> | **Reusability** | Extent to which software can be used in other applications |
> | **Interoperability** | Effort required to couple the system with another |

---

**Q157.** Describe the prototyping software development process.

`[5 M | Jun/Jul 2008 | MCA51]`

> **Answer:**
>
> **Prototyping:** A software development approach where a preliminary version (prototype) of the system is built quickly to demonstrate features, validate requirements, and gather feedback before building the full system.
>
> **Process:**
> ```
> [Gather initial requirements] → [Build quick prototype] → [User evaluates prototype]
>                                                                    ↓
>                                          [Refine requirements based on feedback]
>                                                                    ↓
>                                              [Rebuild/Refine prototype] ──► (repeat)
>                                                                    ↓
>                                              [Build final system from agreed prototype]
> ```
>
> **Types of Prototyping:**
> - **Throwaway/Rapid Prototyping:** Prototype is discarded; final system built from scratch using knowledge gained.
> - **Evolutionary Prototyping:** Prototype is continually refined until it becomes the final system.
> - **Incremental Prototyping:** Multiple prototypes built for different subsystems, then integrated.
>
> **Advantages:** Early user feedback, reduced requirement misunderstandings, earlier delivery.
> **Disadvantages:** Users may think prototype IS the final system; poor code quality if prototype is shipped.

---

**Q158.** What is the purpose and need of analysis? Why is analysis a difficult task?

`[6 M | Jun/Jul 2008 | MCA51]`

> **Answer:**
>
> **Purpose and Need of Analysis:**
> - To understand the problem that the software must solve.
> - To produce an accurate, complete, and unambiguous model of the problem domain.
> - To identify what the system must do (not how) — the functional requirements.
> - To ensure all stakeholders have the same understanding of the system.
> - Analysis model serves as the basis for design and implementation.
>
> **Why Analysis is Difficult:**
> 1. **Incomplete problem statements:** Requirements documents are rarely complete or correct initially.
> 2. **Communication gaps:** Customers often can't articulate what they need; analysts must interpret.
> 3. **Conflicting requirements:** Different stakeholders have different, sometimes contradictory needs.
> 4. **Domain complexity:** Analyst must understand a new domain (banking, healthcare) quickly.
> 5. **Evolving requirements:** Requirements change as users learn more about what they need.
> 6. **Implicit requirements:** Users assume "obvious" behaviors that are never stated explicitly.
> 7. **Large scope:** Identifying what's in scope vs. out of scope is non-trivial.

---

**Q159.** Explain with an example Rumbaugh et al.'s Object Modeling Technique (OMT).

`[10 M | Jun/Jul 2008 | MCA51; Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **OMT (Object Modeling Technique)** — developed by Rumbaugh, Blaha, Premerlani, Eddy, and Lorensen (1991). A comprehensive OO analysis and design methodology using three complementary models to describe a system.
>
> **Three Models:**
>
> **1. Object Model (Static Structure):**
> Describes static structure — classes, attributes, operations, relationships (inheritance, association, aggregation). Similar to UML Class Diagram.
> Example: `BankAccount` class with `balance`, `accountNumber`; associated with `Customer`.
>
> **2. Dynamic Model (Behavior Over Time):**
> Describes how objects change state in response to events over time. Uses state diagrams and event diagrams.
> Example: `Order` state diagram: New → Processing → Shipped → Delivered → Closed.
>
> **3. Functional Model (Data Transformation):**
> Describes what computations the system performs — data flow diagrams (DFDs) showing how values are computed from inputs.
> Example: `calculateInterest(principal, rate, years) → interestAmount`.
>
> **OMT Development Process:**
> 1. Analysis → build all three models from requirements.
> 2. System Design → decide overall architecture.
> 3. Object Design → add implementation details to models.
> 4. Implementation → code from detailed models.
>
> **Significance:** OMT was a major influence on UML; its three-model approach became the foundation for UML's class, state, and activity/sequence diagrams.

---

**Q160.** What is a model? Explain the necessity of modeling and its advantages.

`[6 M | Jun/Jul 2008 | MCA51]`

> **Answer:**
>
> **Model:** An abstraction of a system — a simplified representation that captures essential aspects while ignoring irrelevant details. In software, models include class diagrams, use case diagrams, activity diagrams, etc.
>
> **Necessity of Modeling:**
> 1. Real systems are too complex to understand entirely — models reduce complexity.
> 2. Help communicate ideas among team members and with stakeholders.
> 3. Enable analysis of system properties (correctness, completeness) before building.
> 4. Support planning and estimation.
>
> **Advantages:**
> 1. **Communication:** Visual models communicate design intent more clearly than text alone.
> 2. **Early error detection:** Structural and logical errors found in the model are cheaper to fix than in code.
> 3. **Blueprint for implementation:** Models drive code generation and guide developers.
> 4. **Documentation:** Models serve as lasting documentation of system architecture.
> 5. **Abstraction management:** Allows working at different levels of detail simultaneously.
> 6. **Validation:** Can be shown to customers/users for validation before expensive coding begins.

---

## 26. Software Testing & Quality

> **Frequency: High** — mainly in UE18CS353

---

**Q165.** With a diagram, explain the levels of testing.

`[8 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> **Testing Levels (bottom-up):**
> ```mermaid
> flowchart TD
>  UT["Unit Testing<br/>Individual functions, methods, classes<br/>Who: Developers"]
>  IT["Integration Testing<br/>Interfaces between combined modules<br/>Who: Dev/Test team"]
>  ST["System Testing<br/>Complete integrated system vs requirements<br/>Who: Test team"]
>  AT["Acceptance Testing<br/>System meets business needs<br/>Who: Client / End Users"]
>  UT --> IT --> ST --> AT
> ```
>
> | Level | What is tested | Who tests | Example |
> |---|---|---|---|
> | **Unit** | Individual functions, methods, classes | Developers | Test `calculateInterest()` in isolation |
> | **Integration** | Interfaces between combined modules | Dev/Test team | Test Order + Payment + Inventory together |
> | **System** | Complete, integrated system against requirements | Test team | End-to-end test of entire application |
> | **Acceptance** | System meets business requirements and user needs | Client/User | UAT — user validates before go-live |

---

**Q166.** Briefly discuss about different levels of testing.

`[8 M | Jul 2023 | UE18CS353]`

> **Answer:** Refer to Q165 for the complete answer with diagram and table.

---

**Q167.** Write a note on Black box & White box testing.

`[4 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> **Black Box Testing:**
> Tests the system from the user's perspective without knowledge of internal implementation. Input is provided; output is verified against expected results. Focus: functional requirements, specifications.
> - Techniques: Equivalence Partitioning, Boundary Value Analysis, Decision Table Testing.
> - Who: QA testers, end users.
> - Example: Testing a login form — enter valid/invalid credentials and check outcomes.
>
> **White Box Testing (Glass Box / Structural Testing):**
> Tests internal structure, code paths, and logic with knowledge of implementation. Tests every line, branch, and path in the code.
> - Techniques: Statement Coverage, Branch/Decision Coverage, Path Coverage, Mutation Testing.
> - Who: Developers.
> - Example: Ensuring every `if` and `else` branch in `calculateDiscount()` is executed at least once.
>
> | Feature | Black Box | White Box |
> |---|---|---|
> | Knowledge required | No internal knowledge | Full code knowledge |
> | Focus | What the system does | How the system does it |
> | Tester | QA team | Developer |
> | Techniques | Equivalence partitioning | Statement/branch coverage |

---

**Q168.** Differentiate between Static Testing and Dynamic Testing.

`[6 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> | Feature | Static Testing | Dynamic Testing |
> |---|---|---|
> | Definition | Testing without executing the code | Testing by executing the code with test inputs |
> | When | Early — during requirements, design, coding phases | After code is written and executable |
> | Code execution | No | Yes |
> | Techniques | Code review, inspection, walkthrough, static analysis tools | Unit testing, integration testing, system testing |
> | Purpose | Find defects in documents, design, and code early | Find defects in running behavior |
> | Defects found | Syntax errors, design flaws, requirement issues | Logic errors, runtime errors, performance issues |
> | Examples | SonarQube analysis, code review, JSLint | JUnit tests, Selenium automated tests, manual testing |

---

**Q169.** Contrast between Manual and Automation testing.

`[6 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> | Feature | Manual Testing | Automation Testing |
> |---|---|---|
> | Who performs | Human tester | Automated scripts/tools |
> | Speed | Slow | Fast — runs thousands of tests quickly |
> | Cost | Lower initial cost | Higher initial cost (tool + script development) |
> | Accuracy | Prone to human error | Highly accurate and consistent |
> | Maintenance | Low (update test cases in documents) | High (scripts must be maintained as app changes) |
> | Best for | Exploratory testing, UX testing, ad-hoc testing | Regression testing, load testing, repetitive tests |
> | Tools | None (or Excel spreadsheets) | Selenium, JUnit, TestNG, Appium, JMeter |
> | Use case | New features, one-time tests | Continuous integration, large regression suites |

---

**Q170.** With a diagram, explain the process of test execution.

`[6 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> ```mermaid
> flowchart TD
>  TP["Test Plan"] --> TD["Test Design<br/>Create Test Cases · Test Data Prep"]
>  TD --> TE_Setup["Test Environment Setup<br/>Configure hardware, OS, DB, app"]
>  TE_Setup --> TE["Test Execution<br/>Run cases · Log Pass/Fail · Log defects"]
>  TE --> DR["Defect Reporting<br/>Bug report: title, steps, severity, priority"]
>  DR --> DRT["Defect Retesting<br/>Verify fix after developer resolves"]
>  DRT --> RT["Regression Testing<br/>Ensure fix didn't break existing functionality"]
>  RT --> TC["Test Closure<br/>Summary report · Lessons learned · Metrics"]
> ```
>
> **Key metrics tracked during execution:** Total test cases, passed, failed, blocked; defect density; test coverage percentage.

---

**Q171.** Differentiate between VERIFICATION & VALIDATION.

`[6 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> | Feature | Verification | Validation |
> |---|---|---|
> | Question asked | "Are we building the product **right**?" | "Are we building the **right** product?" |
> | Focus | Process conformance — checking artifacts against specifications | Product fitness — checking system meets user needs |
> | When | During development phases (each phase) | At the end (or milestones) with the actual product |
> | Activities | Reviews, inspections, walkthroughs, static analysis | Testing, demonstration, user acceptance |
> | Input | Requirements, design documents, code | The running system |
> | Who | Development team, QA team | Customer, end users, QA team |
> | Goal | Ensure design/code matches requirements | Ensure system satisfies user's actual needs |
> | Example | Code review checks if code implements design correctly | UAT where users confirm system is what they need |

---

**Q172.** Compare and contrast verification and validation with examples.

`[5 M | May 2023 | UE18CS353]`

> **Answer:** Refer to Q171 table, plus examples:
> - **Verification example:** Reviewing a design document to confirm all SRS requirements are addressed. Inspecting code to ensure it matches the detailed design. Running static analysis.
> - **Validation example:** User Acceptance Testing (UAT) where customers run the system with real business scenarios. Demonstrating the system to stakeholders. Beta testing with real users.

---

**Q173.** Describe statement coverage and decision coverage as test techniques. Discuss differences and importance.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Statement Coverage (Line Coverage):**
> Ensures every executable statement in the code is executed at least once by some test case. Metric: (Statements executed / Total statements) × 100%.
>
> **Decision Coverage (Branch Coverage):**
> Ensures every possible outcome (true/false) of every decision point (if, while, for) is executed at least once. More thorough than statement coverage.
>
> **Differences:**
>
> | Feature | Statement Coverage | Decision Coverage |
> |---|---|---|
> | What is covered | Every executable line | Every true/false branch of every decision |
> | Strength | Weaker — can achieve 100% without testing all branches | Stronger — tests both outcomes of every condition |
> | Example | `if(x>0)` executed once (x=5) = 100% stmt | Must test x=5 (true) AND x=-1 (false) = 100% decision |
>
> **Importance:** Statement coverage finds unexecuted dead code. Decision coverage ensures all business logic branches are tested (e.g., if a discount only applies when quantity > 10, must test both cases). 100% decision coverage implies 100% statement coverage.

---

**Q174.** Explain the principles behind mutation testing and fault injection. Discuss advantages and limitations.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Mutation Testing:**
> Artificial defects (mutations) are introduced into the source code (e.g., changing `>` to `>=`, changing `+` to `-`). Test suite is run against mutated code. If tests fail → they "killed the mutant" (good). If tests pass → mutant "survived" → test suite is weak.
> **Mutation Score** = (Killed mutants / Total mutants) × 100%.
>
> **Fault Injection:**
> Deliberately introduces faults into a running system to test how it handles them. Tests resilience and fault tolerance. Types: hardware fault injection, software fault injection (exceptions, null inputs), network fault injection (latency, packet loss).
>
> | Feature | Mutation Testing | Fault Injection |
> |---|---|---|
> | Level | Source code | Running system |
> | Purpose | Evaluate test suite quality | Test system resilience/error handling |
>
> **Advantages:** Both techniques find weaknesses that normal testing misses; improve confidence in system reliability.
>
> **Limitations — Mutation Testing:** Computationally expensive (many mutants), equivalent mutants (mutations that don't change behavior) are hard to detect.
> **Limitations — Fault Injection:** Difficult to inject realistic faults; may cause unrecoverable system states; expensive to set up.

---

**Q175.** Describe the V-model of SDLC and how testing is integrated into each stage.

`[5 M | May 2023 | UE18CS353]`

> **Answer:** Refer to Q149 — the V-model structure, phases, and how each development phase maps to a testing phase (Requirements → Acceptance, System Design → System Testing, Module Design → Unit Testing, Coding at the bottom).

---

**Q176.** Choose appropriate types of testing for: i) Amazon Prime Days, ii) Google Drive collaborative editing, iii) Anti-virus software.

`[6 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **i) Online shopping website with special sale days (Amazon Prime Days):**
> - **Performance/Load Testing** — System must handle massive concurrent traffic spikes (10x normal load).
> - **Stress Testing** — Find the breaking point; ensure graceful degradation.
> - **Scalability Testing** — Verify that adding servers (horizontal scaling) handles the load.
>
> **ii) File management system with collaborative editing (Google Drive):**
> - **Concurrency Testing** — Multiple users editing the same document simultaneously without data loss or corruption.
> - **Integration Testing** — Verify correct interaction between file storage, sync, and real-time collaboration services.
> - **Regression Testing** — Ensure each new feature doesn't break existing collaboration functionality.
>
> **iii) Anti-Virus software requiring frequent updates:**
> - **Regression Testing** — Every update must not break existing detection capabilities.
> - **Security Testing** — Verify it correctly identifies malware and doesn't have exploitable vulnerabilities itself.
> - **Compatibility Testing** — Must work across different OS versions, hardware configurations.
> - **Performance Testing** — Updates must not significantly slow down system performance.

---

**Q177.** What are the 3 perspectives for looking at test-related measures? Give one example for each.

`[6 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **1. Measures of Test Quality (effectiveness of the test suite):**
> How well the tests actually find defects and cover the code.
> - Example: **Code Coverage** — "80% of all statements are executed by the test suite." Or Defect Detection Percentage (DDP) = defects found by testing / total defects.
>
> **2. Measures of Testing Progress (status of testing activity):**
> How far along the testing effort is — management metrics.
> - Example: **Test Case Execution Rate** — "150 out of 200 planned test cases executed (75% complete)." Or defect arrival/closure rates per day showing if defects are being resolved faster than found.
>
> **3. Measures of Product Quality (reliability of the software):**
> Characteristics of the software as observed through testing.
> - Example: **Mean Time Between Failures (MTBF)** — "System runs for an average of 500 hours without failure during soak testing." Or defect density = number of defects per 1000 lines of code.

---

**Q178.** What is SEI CMM? Name two reasons to use it? Enumerate its five levels.

`[8 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **SEI CMM (Capability Maturity Model):** A framework developed by the Software Engineering Institute (SEI) at Carnegie Mellon University for assessing and improving the software development process maturity of organizations.
>
> **Two Reasons to Use CMM:**
> 1. **Identify strengths and weaknesses** in software development processes — provides a roadmap for improvement.
> 2. **Benchmark and certify** software development capability — customers and contracts often require CMM Level 3+ as a quality assurance indicator.
>
> **Five Maturity Levels:**
>
> | Level | Name | Description |
> |---|---|---|
> | **Level 1** | **Initial** | Ad hoc, chaotic processes; success depends on individual heroics; no stable environment |
> | **Level 2** | **Repeatable** | Basic project management; requirements, scheduling, costs are tracked; projects repeat earlier successes |
> | **Level 3** | **Defined** | Standard documented processes; management and engineering are defined and integrated; proactive |
> | **Level 4** | **Managed** | Quantitative quality and process performance measures; predictable, controlled processes; metrics-driven |
> | **Level 5** | **Optimizing** | Continuous process improvement; quantitative feedback; innovative technologies adopted systematically |

---

**Q179.** Explain briefly about code review and code inspection.

`[8 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> **Code Review:**
> An informal or semi-formal practice where developer(s) examine source code for defects, style issues, logic errors, and improvements before or after committing. Typically done as part of pull request (PR) reviews in modern agile teams.
> - **Types:** Peer review, over-the-shoulder review, tool-assisted review (GitHub PR, GitLab MR, Gerrit).
> - **Benefits:** Early defect detection, knowledge sharing, code quality improvement, mentoring.
> - Less formal — no required meeting, no specific roles, no entry/exit criteria.
>
> **Code Inspection (Formal Inspection / Fagan Inspection):**
> A highly structured, formal review process with defined roles, entry/exit criteria, metrics, and mandatory defect logging. Introduced by Michael Fagan at IBM (1976).
> - **Roles:** Moderator (chairs the meeting), Author, Reader (reads code aloud), Inspector (finds defects), Scribe (records defects).
> - **Process:** Planning → Overview → Preparation → Inspection Meeting → Rework → Follow-up.
> - **Benefits:** Very high defect detection rate (60–90%), produces metrics, proven to reduce downstream defect costs.
> - More expensive but more effective than informal reviews.
>
> | Feature | Code Review | Code Inspection |
> |---|---|---|
> | Formality | Informal/semi-formal | Formal with defined process |
> | Roles | Reviewer + Author | Moderator, Author, Readers, Inspectors, Scribe |
> | Metrics | Optional | Mandatory (defect rate, preparation time) |
> | Exit criteria | None | Defined (max defect rate) |

---

**Q180.** Differentiate between Coding Standards and Guidelines with at least 2 examples each.

`[6 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **Coding Standards:** Mandatory rules that ALL code must follow. Enforced — violations are errors.
>
> | Example | Description |
> |---|---|
> | Variable naming: `camelCase` for variables, `PascalCase` for classes | `int studentAge;` not `int StudentAge` or `int STUDENTAGE` |
> | All methods must have Javadoc comments | `/** Returns the account balance. @return double */` above every public method |
>
> **Coding Guidelines:** Recommended best practices — not mandatory, but strongly advised for quality and consistency.
>
> | Example | Description |
> |---|---|
> | Keep methods under 30 lines | Long methods are hard to read and test — break into smaller ones |
> | Avoid deeply nested code (max 3 levels) | Use early return/guard clauses to reduce nesting |
>
> | Feature | Coding Standards | Coding Guidelines |
> |---|---|---|
> | Nature | Mandatory | Recommended |
> | Enforcement | Automated tools, CI checks | Code review, peer judgment |
> | Violation | Build failure / rejected PR | Review comment, suggestion |

---

**Q181.** What is secure programming? List secure programming approaches to overcome software vulnerabilities.

`[6 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **Secure Programming:** The practice of writing software that is resistant to security vulnerabilities, attacks, and exploits. It incorporates security considerations throughout the entire development lifecycle, not just as an afterthought.
>
> **Secure Programming Approaches:**
>
> 1. **Input Validation and Sanitization:** Validate ALL user inputs; reject malformed data. Prevents SQL Injection, XSS, buffer overflows.
>
> 2. **Principle of Least Privilege:** Code and processes should run with the minimum permissions needed. Limit damage if compromised.
>
> 3. **Parameterized Queries / Prepared Statements:** Never concatenate user input into SQL queries. Prevents SQL Injection.
>
> 4. **Secure Password Storage:** Never store plaintext passwords. Use strong hashing (bcrypt, PBKDF2, Argon2) with salting.
>
> 5. **Error Handling and Logging:** Never expose stack traces to users. Log security events; don't log sensitive data (passwords, card numbers).
>
> 6. **Authentication and Authorization:** Enforce strong authentication (MFA); check authorization for every protected resource.
>
> 7. **Dependency Management:** Keep libraries/frameworks up to date; avoid known vulnerable versions; use tools like OWASP Dependency-Check.
>
> 8. **Encryption:** Use TLS/HTTPS for data in transit; encrypt sensitive data at rest.

---

## 27. Software Maintenance, DevOps & Configuration Management

> **Frequency: High** — mainly in UE18CS353

---

**Q182.** Explain the key issues in software maintenance.

`[8 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> **Software Maintenance:** All activities performed after software is delivered to ensure it continues to meet user needs and operates correctly. Accounts for 60–80% of total software lifecycle cost.
>
> **Key Issues:**
>
> 1. **Understanding the existing system:** Poorly documented or overly complex legacy code is hard to understand before changes can be made safely.
>
> 2. **Ripple effects of changes:** A change in one module may unexpectedly break functionality in other modules (tight coupling — high maintenance risk).
>
> 3. **Regression testing burden:** Every change requires testing not just the new code but all existing functionality to ensure nothing is broken.
>
> 4. **Personnel issues:** Original developers may have left. New maintainers lack context and domain knowledge.
>
> 5. **Degrading software quality:** Repeated quick fixes and patches degrade architecture over time ("software rot") making future maintenance harder.
>
> 6. **Configuration management:** Tracking multiple versions, patches, and releases across different customer environments is complex.
>
> 7. **Estimating maintenance costs:** Hard to predict effort for change requests due to complexity and poor documentation.
>
> 8. **Testing difficulties:** Test cases may be outdated or nonexistent for legacy code.

---

**Q183.** Define: Preventive, Perfective, Corrective, Adaptive Maintenance.

`[4 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> | Type | Definition | Example |
> |---|---|---|
> | **Corrective** | Fixing bugs, errors, and failures discovered after delivery | Fixing a payment calculation error that causes wrong totals |
> | **Adaptive** | Modifying software to work in a changed environment (new OS, hardware, regulations) | Updating software to run on Java 17 after Java 8 support ends |
> | **Perfective** | Improving performance, maintainability, or adding new features requested by users | Rewriting a slow database query for better performance; adding a filter feature |
> | **Preventive** | Making changes to prevent future failures; improve reliability | Refactoring complex code before it causes problems; updating dependencies |

---

**Q184.** Explain briefly about the 4 pillars of DevOps.

`[8 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> **DevOps:** A set of practices and culture that combines software Development (Dev) and IT Operations (Ops) to shorten development cycles, increase deployment frequency, and deliver high-quality software reliably.
>
> **4 Pillars of DevOps:**
>
> **1. Culture (Collaboration and Affinity):**
> Breaking down the "wall" between Dev and Ops teams. Shared responsibility for the product — developers care about operations; ops teams care about development speed. High-trust, blameless culture; shared goals and metrics.
>
> **2. Automation:**
> Automating repetitive manual tasks — build, test, deployment, infrastructure provisioning. Tools: Jenkins (CI/CD), Ansible (config management), Terraform (infrastructure as code), Docker, Kubernetes. Reduces human error; accelerates delivery.
>
> **3. Measurement (Metrics):**
> Continuously measuring and monitoring system performance, deployment frequency, failure rates, and recovery times. Key metrics: Deployment Frequency, Mean Time to Recovery (MTTR), Change Failure Rate, Lead Time. Data-driven decisions.
>
> **4. Sharing (Feedback and Transparency):**
> Sharing knowledge, tools, feedback, and lessons learned across teams and the organization. Regular retrospectives, open dashboards, shared documentation. Enables continuous improvement.

---

**Q185.** Enlist the pillars of DevOps and specify a few factors about each pillar.

`[8 M | Jul 2023 | UE18CS353]`

> **Answer:** Refer to Q184 — same four pillars (Culture, Automation, Measurement, Sharing) with detailed factors for each.

---

**Q186.** Describe the term DevOps. Write briefly about the DevOps pipeline.

`[8 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **DevOps:** A philosophy and set of practices that integrates software development (Dev) and IT operations (Ops). Goal: faster, more reliable delivery of software through automation, collaboration, and continuous feedback.
>
> **DevOps Pipeline (CI/CD Pipeline):**
> ```mermaid
> flowchart LR
>  Code["Code - Git / GitHub"] --> Build["Build - Maven / Gradle"]
>  Build --> Test["Test - JUnit / Selenium"]
>  Test --> Release["Release - Docker / Nexus"]
>  Release --> Deploy["Deploy - Jenkins / ArgoCD"]
>  Deploy --> Operate["Operate - Kubernetes"]
>  Operate --> Monitor["Monitor - Prometheus / Grafana"]
>  Monitor -- "feedback" --> Code
> ```
>
> | Stage | Activities | Tools |
> |---|---|---|
> | **Code** | Developers write and commit code | Git, GitHub, GitLab |
> | **Build** | Code compiled, dependencies resolved | Maven, Gradle, npm |
> | **Test** | Automated unit, integration, security tests | JUnit, Selenium, SonarQube |
> | **Release** | Artifact versioned and packaged for deployment | Docker, Nexus |
> | **Deploy** | Automatically deployed to staging/production | Jenkins, GitHub Actions, ArgoCD |
> | **Operate** | System running in production; infrastructure managed | Kubernetes, Ansible, Terraform |
> | **Monitor** | Application and infrastructure performance monitored | Prometheus, Grafana, ELK Stack |
>
> **Key Concepts:** CI (Continuous Integration) — frequent merges + automated builds + tests. CD (Continuous Delivery) — deployable artifact always available. CD (Continuous Deployment) — every passing build automatically deployed to production.

---

**Q187.** Explain how continuous build, integration, and delivery contribute to shorter development cycles.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Continuous Build:** Automatically compiles code on every commit. Catches build-breaking changes immediately — developer knows within minutes, not days. Tool: Jenkins, GitHub Actions.
>
> **Continuous Integration (CI):** Every developer's code change is automatically integrated with others' changes multiple times per day. Automated tests (unit, integration) run on every merge. Benefits: Integration bugs caught early (when fixes are cheap), eliminates "integration hell" at the end of a sprint.
>
> **Continuous Delivery (CD):** Every code change that passes all tests is automatically packaged into a deployable release artifact. A one-click (or zero-click) deployment to production is always available. Benefits: Business can deploy features on demand; reduces deployment risk (small, frequent releases are safer than large, infrequent ones).
>
> **Jenkins Role:** Jenkins orchestrates the entire pipeline — triggered on every Git push: pulls code, runs Maven build, executes JUnit tests, runs SonarQube analysis, builds Docker image, deploys to staging. Failed stages immediately notify the developer.
>
> **Net result:** Features go from code to production in hours/days instead of weeks/months.

---

**Q188.** Discuss the importance of automated build, testing, and deployment in the DevOps workflow.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Automated Build:**
> - Eliminates manual compile errors and environment inconsistencies ("works on my machine").
> - Every commit produces a consistent, reproducible artifact.
> - Enforces that the codebase is always in a buildable state.
>
> **Automated Testing:**
> - Runs hundreds/thousands of tests in minutes — impossible manually.
> - Provides immediate feedback — a broken test shows exactly which commit caused the problem.
> - Regression suite ensures existing functionality is not broken by new changes.
> - Enables developers to refactor with confidence.
>
> **Automated Deployment:**
> - Eliminates manual deployment steps (source of errors and inconsistency).
> - Infrastructure-as-Code (Terraform, Ansible) ensures production matches staging.
> - Blue-green and canary deployments reduce downtime and risk.
> - Rollback is instant if deployment fails.
>
> **Overall Importance:** The combination eliminates large amounts of manual, error-prone work; accelerates feedback loops; reduces the Mean Time to Recovery (MTTR); and enables teams to deploy multiple times per day confidently.

---

**Q189.** Discuss the concept of affinity in DevOps and how it fosters cross-functional cooperation.

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Affinity in DevOps:** Affinity refers to the sense of shared ownership, mutual respect, and collaboration between Development and Operations teams (and QA, Security, and Business). It is one of the cultural pillars of DevOps, sometimes expressed as "You build it, you run it."
>
> **How Affinity Fosters Cross-Functional Cooperation:**
>
> 1. **Shared goals and metrics:** Both Dev and Ops measured by the same KPIs (deployment frequency, MTTR, uptime) instead of conflicting metrics (Dev: speed of feature delivery; Ops: system stability).
>
> 2. **Joint responsibility:** Developers are on-call for production incidents — they understand operational impact of their code choices. Ops engineers participate in planning — operational requirements (monitoring, logging) are built in, not added later.
>
> 3. **Empathy building:** Developers shadow Ops during incidents; Ops engineers participate in sprint planning. Each team understands the other's challenges.
>
> 4. **Blameless post-mortems:** When things go wrong, root cause analysis focuses on process improvement, not individual blame. Creates psychological safety for open communication.
>
> 5. **Cross-functional teams:** Instead of siloed Dev team + Ops team, cross-functional squads include developers, testers, and operations engineers working together on the same product.

---

**Q190.** Explain Software Configuration Management and its benefits.

`[6 M | Dec 2023 | UE18CS353]`

> **Answer:**
>
> **Software Configuration Management (SCM):** A discipline for tracking and controlling changes to software. It identifies, organizes, and controls changes to software throughout the development lifecycle. Ensures that the right version of the right software is delivered.
>
> **Key SCM Activities:**
> 1. **Configuration Identification:** Identify and name all software configuration items (SCIs) — source code, documentation, test cases, build scripts.
> 2. **Change Control:** Formal process to request, evaluate, approve, and implement changes.
> 3. **Version Control:** Track all versions of SCIs — who changed what, when, and why. (Git, SVN)
> 4. **Configuration Audit:** Verify that the software matches its documented specification at a given baseline.
> 5. **Status Accounting:** Record and report the status of all change requests and baselines.
>
> **Benefits:**
> 1. Prevents unauthorized or uncontrolled changes.
> 2. Enables reproducibility — any previous version can be rebuilt exactly.
> 3. Supports parallel development (branching/merging).
> 4. Provides complete audit trail of all changes.
> 5. Reduces integration problems and conflicts.
> 6. Facilitates release management and software distribution.
> 7. Supports disaster recovery — code can be restored from version history.

---

**Q191.** Enlist the benefits of using a Software Configuration System.

`[4 M | Jul 2023 | UE18CS353]`

> **Answer:** See Q190 — the 7 benefits listed there apply directly here.

---

**Q192.** Briefly discuss about ITSM and ITIL.

`[6 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> **ITSM (IT Service Management):** A set of policies, processes, and procedures for managing IT services from a customer-centric perspective. Focuses on aligning IT services with business needs. Goal: deliver IT services efficiently, cost-effectively, and at agreed quality levels.
>
> **ITIL (IT Infrastructure Library):** The most widely adopted framework for ITSM. A set of best practices and guidelines for delivering IT services. Developed by the UK government (CCTA) in the 1980s; current version is ITIL 4 (2019).
>
> **ITIL Service Lifecycle (v3) — 5 Stages:**
> 1. **Service Strategy** — Define what services to offer, to whom, and why.
> 2. **Service Design** — Design new or changed services to meet requirements.
> 3. **Service Transition** — Build, test, and deploy services into production.
> 4. **Service Operation** — Day-to-day management of live services; incident/problem management.
> 5. **Continual Service Improvement** — Measure and improve services continuously.
>
> **ITSM Key Processes:** Incident Management, Problem Management, Change Management, Service Level Management, Configuration Management.

---

**Q193.** Describe the ITIL service lifecycle and its five stages.

`[5 M | May 2023 | UE18CS353]`

> **Answer:** See Q192 — the five ITIL stages (Service Strategy, Design, Transition, Operation, Continual Service Improvement) with purpose and activities.

---

**Q194.** List any six objectives of IT Systems Management (ITSM).

`[6 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> 1. Align IT services with current and future business needs.
> 2. Improve the quality and efficiency of IT service delivery.
> 3. Reduce the cost of IT service provision through process standardization.
> 4. Manage and minimize the risk of IT service failures.
> 5. Improve customer satisfaction by delivering services that meet agreed SLAs.
> 6. Enable continuous improvement of IT services through measurement and feedback.
> 7. Ensure IT service changes are planned, tested, and implemented with minimum disruption.
> 8. Maintain accurate records of IT assets and configurations (CMDB).

---

**Q195.** Name any three challenges of geographical distance in Software Development. How can they be overcome?

`[6 M | Jan–May 2024 | UE18CS353]`

> **Answer:**
>
> **Three Challenges:**
>
> 1. **Communication Barriers:** Time zone differences make real-time collaboration difficult. Language barriers and cultural differences can cause misunderstandings in requirements.
> *Overcome:* Use asynchronous communication tools (Slack, email, recorded video updates). Establish overlapping "core hours." Use clear written documentation. Regular video standups with rotating meeting times.
>
> 2. **Coordination and Synchronization:** Distributed teams working on interdependent modules can create integration problems and version conflicts.
> *Overcome:* Strict use of version control (Git), CI/CD pipelines, shared project management tools (Jira, Confluence). Well-defined APIs and module contracts agreed upfront.
>
> 3. **Trust and Team Cohesion:** Geographically distributed teams may feel disconnected, leading to reduced collaboration, lower morale, and "us vs. them" mentality.
> *Overcome:* Virtual team-building activities, occasional in-person meetings, transparent goal-setting, recognition programs. Using DevOps "affinity" culture to build shared ownership.

---

**Q196.** Discuss Hacking and Software Engineering, and Availability Management.

`[6 M | Jul 2023 | UE18CS353]`

> **Answer:**
>
> **Hacking and Software Engineering:**
> Software engineers must build systems resistant to attacks. Common threats: SQL Injection, XSS, buffer overflows, privilege escalation, CSRF. Secure SDLC integrates security at every phase: threat modeling in design, SAST/DAST in testing, security patches in maintenance. OWASP Top 10 provides the most critical security risks to address.
>
> **Availability Management:**
> An ITIL process ensuring IT services are available when needed, at the required level. Measured by:
> - **Availability (%) = (Agreed service time − Downtime) / Agreed service time × 100**
> - **MTBF (Mean Time Between Failures):** Higher is better.
> - **MTTR (Mean Time To Repair):** Lower is better.
>
> Activities: Define availability requirements (SLAs), monitor uptime, analyze failures, implement redundancy, capacity planning, disaster recovery planning.
> **High Availability techniques:** Load balancing, failover clustering, geographic redundancy, hot standby servers.

---

## 28. OO Development — Historical / Broad Concepts

> **Frequency: Medium** — mainly in older papers

---

**Q197.** What is the importance of prototyping? What are the commonly accepted prototyping approaches?

`[6 M | Jun–Jul 2009 | CS72]`

> **Answer:** See Q157 for the complete answer. Additional prototyping approaches:
>
> **Importance:** Reduces risk of misunderstood requirements; provides early user feedback; helps resolve ambiguities; demonstrates feasibility.
>
> **Common Approaches:**
> 1. **Throwaway (Rapid) Prototyping** — Quick mock built to validate requirements; discarded afterward.
> 2. **Evolutionary Prototyping** — Prototype is refined iteratively until it becomes the final system.
> 3. **Incremental Prototyping** — Multiple prototypes built for different subsystems; merged at end.
> 4. **Extreme Prototyping** — Used in web development: three phases — static HTML prototype → simulated services → fully functional services.
>
> **Strengths:** Early user involvement, reduced specification errors, better final product alignment with user needs.

---

**Q198.** What are the advantages of modeling? What elements must a modeling language include?

`[6 M | Jun–Jul 2009 | CS72]`

> **Answer:** See Q160 for advantages of modeling.
>
> **Elements a Modeling Language Must Include:**
> 1. **Syntax** — Rules that define valid combinations of symbols and constructs in the language.
> 2. **Semantics** — The meaning of each construct — what it represents in the real world or system.
> 3. **Pragmatics** — Guidelines for how the language should be used effectively in practice.
> 4. **Notation** — Visual symbols and diagrams that represent concepts (classes, associations, states).
> 5. **Abstraction mechanisms** — Ways to represent concepts at different levels of detail.
> 6. **Consistency rules** — Rules ensuring different views/diagrams remain consistent with each other.
>
> **UML satisfies all these:** It defines graphical notation (syntax), meaning of each diagram element (semantics), and guidelines for effective use (pragmatics).

---

**Q199.** Write short notes on: Model constraints and comments; Stereotype; UML meta-model.

`[10 M | Jun/Jul 2008 | MCA51]`

> **Answer:**
>
> **Model Constraints and Comments:**
> - **Constraints** are semantic conditions or restrictions on a model element. Written in curly braces `{ }`. Example: `{ordered}` on a collection, `{unique}` on an attribute, `{age > 0}`. Can be expressed in OCL (Object Constraint Language) for precision.
> - **Comments/Notes** are annotations that explain model elements. Drawn as a rectangle with a folded corner, connected to the element by a dashed line. Do not affect system semantics; aid human understanding.
>
> **Stereotype:**
> A mechanism for extending UML to define new types of modeling elements. Extends the vocabulary of UML. Written in guillemets `«name»`. Examples: `«interface»`, `«component»`, `«actor»`, `«service»`, `«entity»`. Allows domain-specific customizations without changing the UML metamodel. Custom icons can be associated with stereotypes.
>
> **UML Meta-Model:**
> The UML meta-model is a model that defines UML itself — it specifies the abstract syntax and semantics of all UML constructs. It is a model of UML modeled in UML (self-referential). The meta-model defines: what is a Class, what is an Association, what is a Dependency, what properties they have, and how they relate to each other. Defined using MOF (Meta Object Facility). The meta-model has four layers: M0 (real-world instances), M1 (UML model), M2 (UML meta-model), M3 (MOF meta-meta-model).

---

**Q200.** Explain clearly the concept of object-relational mapping.

`[10 M | Jun/Jul 2008 | MCA51]`

> **Answer:**
>
> **Object-Relational Mapping (ORM):** A technique for converting data between an OO programming language and a relational database. It creates a "virtual object database" that can be queried from within the OO language.
>
> **The Impedance Mismatch Problem:**
> OO languages use objects with inheritance, polymorphism, and complex relationships. Relational databases store data in flat tables with rows and columns. Converting between these paradigms is called the "object-relational impedance mismatch."
>
> | OO Concept | Relational Concept |
> |---|---|
> | Class | Table |
> | Object instance | Row |
> | Attribute | Column |
> | Object reference | Foreign key |
> | Inheritance | Multiple strategies (single table, joined tables, table per class) |
>
> **ORM Frameworks:** Hibernate (Java), JPA (Java Persistence API), SQLAlchemy (Python), Entity Framework (.NET), ActiveRecord (Ruby).
>
> **Example (Hibernate):**
> ```java
> @Entity
> @Table(name = "students")
> class Student {
>     @Id @GeneratedValue
>     private int id;
>
>     @Column(name = "student_name")
>     private String name;
> }
> // Hibernate auto-generates SQL to map Student objects ↔ students table
> ```
>
> **Benefits:** No manual SQL; database-independent code; relationship handling automated; caching; lazy loading.

---

**Q201.** What are the guidelines for developing effective documentation?

`[5 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> 1. **Know your audience:** Write at the appropriate technical level; developers need different docs than end users.
> 2. **Keep it current:** Documentation that lags behind the code is worse than no documentation — update docs with every significant change.
> 3. **Be concise and clear:** Avoid jargon, ambiguity, and unnecessary detail. Use plain language; prefer active voice.
> 4. **Use visuals:** Diagrams, tables, and examples communicate complex ideas faster than prose.
> 5. **Organize logically:** Use consistent structure, headings, and indexing. Make it searchable.
> 6. **Document the why, not just the what:** Code shows what; comments and docs should explain why a decision was made.
> 7. **Single source of truth:** Avoid duplicate documentation that can get out of sync.
> 8. **Review documentation:** Just like code, documentation should be reviewed for accuracy and clarity.

---

**Q202.** What is OODBMS? Discuss the differences between OODBMS and traditional databases.

`[8 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **OODBMS (Object-Oriented Database Management System):** A database system that stores and retrieves data as objects rather than rows and columns. Designed to work directly with OO programming languages — objects are persisted as-is without transformation.
>
> **Features of OODBMS:** Stores complex objects directly (inheritance, methods, references), supports user-defined types, handles complex relationships naturally, no impedance mismatch.
>
> **Differences:**
>
> | Feature | OODBMS | RDBMS (Traditional) |
> |---|---|---|
> | Data model | Objects with attributes, methods, inheritance | Tables with rows and columns |
> | Query language | OQL (Object Query Language) | SQL |
> | Impedance mismatch | None — stores objects directly | Significant — conversion needed |
> | Complex data types | Native support | Limited (JSON, XML extensions) |
> | Performance | Better for complex, deeply nested objects | Better for simple tabular, ad-hoc queries |
> | Standardization | Less standardized | Highly standardized (SQL:2016) |
> | Maturity | Less mature | Very mature ecosystem |
> | Examples | db4o, ObjectDB, Versant | MySQL, Oracle, PostgreSQL |

---

**Q203.** Discuss the four major activities of designing view layer classes.

`[8 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> **View Layer:** The presentation layer in OO systems — responsible for displaying data to users and capturing input. Classes here implement windows, forms, reports, and other UI components.
>
> **Four Major Activities:**
>
> **1. Identifying View Classes:**
> Map each use case and user interaction to view classes. One window/screen = one view class (or a hierarchy). Identify: main windows, dialog boxes, report views, input forms.
>
> **2. Defining View Class Responsibilities:**
> Each view class should only handle presentation concerns — display data, capture input, trigger controller actions. Must NOT contain business logic (SRP, MVC). Define: what data is displayed, what input is accepted, what events are generated.
>
> **3. Designing View Class Structure:**
> Apply UI design patterns (MVC, MVP, MVVM). Define: properties bound to model data, event handlers (button clicks, form submits), navigation between screens. Use inheritance for common UI components.
>
> **4. Designing Interactions with Controller:**
> View should call controller methods in response to user actions. Controller updates model; model notifies view (Observer pattern or data binding). Design event interfaces: view generates events, controller listens; or view holds reference to controller (passive view).

---

**Q204.** What are the guidelines for designing application windows? Discuss.

`[4 M | Jun–Jul 2009 | CS72]`

> **Answer:**
>
> 1. **One window per use case (where practical):** Each major user task should have a dedicated window.
> 2. **Consistency:** All windows in the application should follow consistent layout, colors, fonts, and button placement.
> 3. **Minimalist design:** Include only what is necessary for the current task — avoid clutter.
> 4. **Clear navigation:** Users should always know where they are and how to get back.
> 5. **Error feedback:** Invalid input should be clearly highlighted with helpful error messages near the field.
> 6. **Default values:** Pre-populate fields with sensible defaults to reduce user effort.
> 7. **Keyboard accessibility:** All functions accessible via keyboard for accessibility compliance.
> 8. **Progressive disclosure:** Show advanced options only when needed — don't overwhelm new users.
> 9. **Undo/redo support:** Users should be able to reverse unintended actions.
> 10. **Responsive to context:** Disable/enable controls based on state (e.g., "Submit" disabled until required fields are filled).

---

**Q205.** How will a software development project be planned using SE Management?

`[5 M | May 2023 | UE18CS353]`

> **Answer:**
>
> **Software Engineering Management** applies management principles to software projects. Project planning is a critical activity.
>
> **SE Project Planning Steps:**
>
> 1. **Define Project Scope:** Understand and document what the project will (and will not) include. Create a project charter.
>
> 2. **Estimate Effort and Cost:** Use estimation techniques (Function Points, COCOMO, expert judgment, story points for Agile) to predict required effort, time, and budget.
>
> 3. **Identify and Schedule Tasks:** Create WBS (Work Breakdown Structure). Assign tasks to team members. Build schedule using Gantt charts or sprint backlogs.
>
> 4. **Resource Planning:** Identify required human resources (roles/skills), hardware, software, and tools. Allocate team members to tasks.
>
> 5. **Risk Planning:** Identify risks; assess probability and impact; define mitigation strategies (see Q153).
>
> 6. **Quality Planning:** Define quality standards, metrics, review processes, and testing strategies.
>
> 7. **Communication Planning:** Define how team communicates — meetings, status reports, escalation paths. Identify stakeholders and their information needs.
>
> 8. **Tracking and Control:** Once execution begins, monitor progress against plan; adjust schedule, resources, or scope as needed.

---

## Quick Reference — Topic Frequency

| Topic | No. of Qs | Frequency |
|---|---|---|
| Use Case Diagrams | 10 | ⭐⭐⭐⭐⭐ |
| SOLID Principles | 11 | ⭐⭐⭐⭐⭐ |
| GRASP Principles | 8 | ⭐⭐⭐⭐⭐ |
| OOP Core Concepts / 4 Pillars | 9 | ⭐⭐⭐⭐⭐ |
| Class Diagrams (relationships) | 8 | ⭐⭐⭐⭐⭐ |
| Constructors & Garbage Collection | 6 | ⭐⭐⭐⭐⭐ |
| Structural Patterns (Adapter, Proxy, Facade) | 11 | ⭐⭐⭐⭐⭐ |
| Behavioral Patterns (CoR, Command, Iterator) | 7 | ⭐⭐⭐⭐⭐ |
| Anti-Patterns | 10 | ⭐⭐⭐⭐⭐ |
| Creational Patterns (Singleton, Factory) | 7 | ⭐⭐⭐⭐ |
| Inheritance | 5 | ⭐⭐⭐⭐ |
| Activity Diagrams | 8 | ⭐⭐⭐⭐ |
| State Diagrams | 7 | ⭐⭐⭐⭐ |
| Architectural Patterns (MVC) | 6 | ⭐⭐⭐⭐ |
| Class Diagrams (case study) | 4 | ⭐⭐⭐⭐ |
| Method Overloading/Overriding | 4 | ⭐⭐⭐ |
| Abstract Class & Interface | 4 | ⭐⭐⭐ |
| Component Diagrams | 4 | ⭐⭐⭐ |
| Sequence Diagrams | 3 | ⭐⭐⭐ |
| Software Testing & Quality | 17 | ⭐⭐⭐ (UE18 only) |
| SDLC Models & Requirements | 14 | ⭐⭐⭐ (UE18 only) |
| DevOps & Config Management | 13 | ⭐⭐⭐ (UE18 only) |
| Static/Instance Members | 3 | ⭐⭐ |
| Generics & Collections | 2 | ⭐⭐ |
| Java Code Writing | 2 | ⭐⭐ |
| Deployment Diagrams | 1 | ⭐ |
| Class Identification | 5 | ⭐⭐ |

---

*Compiled from 13 PYQ papers (PDFs 1–3, 5, 7, 10–17) | OOAD PES University | UE18CS353 · UE19CS353 · UE20CS352 · UE23CS352B*
