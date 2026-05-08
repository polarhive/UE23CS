# Unit 3: Design Principles

---

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