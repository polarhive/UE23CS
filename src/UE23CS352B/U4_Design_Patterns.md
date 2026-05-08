# Unit 4: OO Design Patterns & Anti-Patterns

---

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