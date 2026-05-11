# OOAD Java Code Reference

# Unit 2: OOP Fundamentals

## Class & Object

A **class** is a blueprint. An **object** is a real instance made from that blueprint using the `new` keyword. Objects have state (attributes) and behaviour (methods), accessed via the dot operator.

``` java
class Car {
    // Attributes (state)
    String brand;
    int speed;

    // Method (behaviour)
    void drive() {
        System.out.println("Car is driving at " + speed + " km/h");
    }
}

public class Main {
    public static void main(String[] args) {
        Car car = new Car();   // create object with 'new'
        car.brand = "Toyota";   // set attribute via dot operator
        car.speed = 80;
        car.drive();           // call method via dot operator
    }
}
```

```
output
Car is driving at 80 km/h
```

A constructor runs automatically when an object is created. There are **three types**: Default (no params), Parameterized (with params), Copy (takes another object of same class). The constructor name must match the class name exactly and has no return type.

Three types of constructors with examples is asked almost every paper. Memorise Default → Parameterised → Copy in this order.

## Default Constructor

``` java
class Rect {
    int a, b;

    // Default constructor — no parameters
    Rect() {
        System.out.println("This is the constructor");
    }

    void disp() {
        System.out.println("disp");
    }
}

public class Demo {
    public static void main(String[] args) {
        Rect r = new Rect();  // constructor is called here
        r.disp();
        System.out.println(r.a);  // 0 — default value
        System.out.println(r.b);  // 0 — default value
    }
}
```

```
output
This is the constructor  
disp  
0  
0
```

## Parameterized Constructor

``` java
class Student {
    int id;
    String name;

    // Parameterized constructor — uses 'this' to avoid name conflict
    Student(int id, String name) {
        this.id = id;       // 'this.id' = field, 'id' = parameter
        this.name = name;
    }

    void display() {
        System.out.println(id + " " + name);
    }

    public static void main(String[] args) {
        Student s = new Student(101, "Alice");
        s.display();
    }
}
```

```
output
101 Alice
```

## Copy Constructor

``` java
class Student {
    int id;
    String name;

    Student(int id, String name) {
        this.id = id;
        this.name = name;
    }

    // Copy constructor — takes another Student as argument
    Student(Student s) {
        this.id = s.id;
        this.name = new String(s.name);  // new String() prevents shared reference
    }

    void display() {
        System.out.println(id + " " + name);
    }

    public static void main(String[] args) {
        Student s1 = new Student(101, "Alice");
        Student s2 = new Student(s1);   // copy s1 into s2
        s1.display();
        s2.display();
    }
}
```

```
output
101 Alice  
101 Alice
```

Data (attributes) are made `private` so they can't be accessed directly from outside. Access is controlled through **getters** (read) and **setters** (write). This is how you hide internal state.

``` java
class Person {
    private String name;  // private — hidden from outside

    // Getter — read the value
    public String getName() {
        return name;
    }

    // Setter — write the value
    public void setName(String newName) {
        this.name = newName;
    }
}

class Main {
    public static void main(String[] args) {
        Person myObj = new Person();
        // myObj.name = "John";          ← ERROR: private access
        myObj.setName("John");          // correct way
        System.out.println(myObj.getName());
    }
}
```

A child class **extends** a parent class to reuse its fields and methods. Three types are commonly tested: **Single-level** (A→B), **Multi-level** (A→B→C), **Hierarchical** (A→B and A→C). Java does NOT support multiple class inheritance — use interfaces instead.

## Single-level Inheritance

``` java
class Teacher {
    String designation = "Teacher";
    String collegeName = "PESU";

    void teach() {
        System.out.println("Teaching");
    }
}

public class JavaTeacher extends Teacher {
    String mainSubject = "Java";

    public static void main(String[] args) {
        JavaTeacher obj = new JavaTeacher();
        System.out.println(obj.collegeName);   // inherited
        System.out.println(obj.designation);   // inherited
        System.out.println(obj.mainSubject);   // own field
        obj.teach();                           // inherited method
    }
}
```

```
output
PESU  
Teacher  
Java  
Teaching
```

## Multi-level Inheritance (A → B → C)

``` java
class Animal {
    void eat()  { System.out.println("eating..."); }
}

class Dog extends Animal {
    void bark() { System.out.println("barking..."); }
}

class BabyDog extends Dog {
    void weep() { System.out.println("weeping..."); }
}

class TestInheritance {
    public static void main(String[] args) {
        BabyDog d = new BabyDog();
        d.weep();   // BabyDog's own method
        d.bark();   // inherited from Dog
        d.eat();    // inherited from Animal
    }
}
```

```
output
weeping...  
barking...  
eating...
```

## Multiple Inheritance via Interfaces (Java's workaround)

``` java
interface A {
    void show();
}

interface B {
    void display();
}

// Class C implements BOTH A and B — this is multiple inheritance in Java
class C implements A, B {
    public void show()    { System.out.println("show from A"); }
    public void display() { System.out.println("display from B"); }

    public static void main(String[] args) {
        C obj = new C();
        obj.show();
        obj.display();
    }
}
```

```
output
show from A  
display from B
```

An **abstract class** can have both abstract methods (no body — subclass must implement) and concrete methods (have a body). You *cannot* create an object of an abstract class directly. Use the `abstract` keyword.

## Example 1 — Animal (from slides)

``` java
abstract class Animal {
    // Abstract method — no body, subclass MUST implement
    public abstract void animalSound();

    // Concrete method — has body, subclass inherits it
    public void sleep() {
        System.out.println("Zzz");
    }
}

class Dog extends Animal {
    @Override
    public void animalSound() {
        System.out.println("The dog says: bow bow");
    }
}

class Main {
    public static void main(String[] args) {
        Dog myDog = new Dog();
        myDog.animalSound();  // Dog's own implementation
        myDog.sleep();        // inherited from Animal
    }
}
```

```
output
The dog says: bow bow  
Zzz
```

## Example 2 — Figure / Rectangle / Triangle (from slides)

``` java
abstract class Figure {
    double dim1, dim2;

    Figure(double a, double b) {
        dim1 = a;
        dim2 = b;
    }

    // Abstract — each shape calculates area differently
    abstract double findArea();
}

class Rectangle extends Figure {
    Rectangle(double height, double width) {
        super(height, width);  // calls Figure's constructor
    }

    @Override
    double findArea() {
        return dim1 * dim2;
    }
}

class Triangle extends Figure {
    Triangle(double base, double height) {
        super(base, height);
    }

    @Override
    double findArea() {
        return 0.5 * dim1 * dim2;
    }
}

class Main {
    public static void main(String[] args) {
        Figure r = new Rectangle(4, 5);
        Figure t = new Triangle(3, 6);
        System.out.println("Rectangle area: " + r.findArea());
        System.out.println("Triangle area: "  + t.findArea());
    }
}
```

```
output
Rectangle area: 20.0  
Triangle area: 9.0
```

## Composition — strong "has-a" relationship

``` java
class Engine {
    void start() {
        System.out.println("Engine started");
    }
}

class Car {
    // Engine is created inside Car — strong ownership (composition)
    private Engine engine = new Engine();

    void drive() {
        engine.start();
        System.out.println("Car is moving");
    }
}

public class Main {
    public static void main(String[] args) {
        Car car = new Car();
        car.drive();
    }
}
```

```
output
Engine started  
Car is moving
```

An interface defines *what* a class must do, not *how*. All methods are `public abstract` by default; all fields are `public static final`. A class can `implement` multiple interfaces — this is Java's way of achieving multiple inheritance.

``` java
interface Bicycle {
    // All methods are public and abstract by default
    void changeCadence(int newValue);
    void changeGear(int newValue);
    void speedUp(int increment);
    void applyBrakes(int decrement);
}

class AAABicycle implements Bicycle {
    int cadence = 0, speed = 0, gear = 1;

    public void changeCadence(int newValue) { cadence = newValue; }
    public void changeGear(int newValue)    { gear = newValue; }
    public void speedUp(int increment)       { speed = speed + increment; }
    public void applyBrakes(int decrement)  { speed = speed - decrement; }

    void printStates() {
        System.out.println("cadence:" + cadence + " speed:" + speed + " gear:" + gear);
    }

    public static void main(String[] args) {
        AAABicycle bike = new AAABicycle();
        bike.changeCadence(50);
        bike.changeGear(2);
        bike.speedUp(10);
        bike.applyBrakes(3);
        bike.printStates();
    }
}
```

**Overloading** — same method name, different parameters, *same class*. Resolved at compile-time. | **Overriding** — same method name and same parameters, in a *subclass*. Resolved at runtime. Use `@Override`.

## Overloading — Calculator (directly from slides)

``` java
class Calculator {
    // Same method name 'add', different parameter types/count
    int add(int a, int b)              { return a + b; }
    int add(int a, int b, int c)       { return a + b + c; }
    double add(double a, double b)    { return a + b; }

    public static void main(String[] args) {
        Calculator calc = new Calculator();
        System.out.println(calc.add(10, 20));       // 30
        System.out.println(calc.add(10, 20, 30));  // 60
        System.out.println(calc.add(5.5, 2.5));    // 8.0
    }
}
```

```
output
30  
60  
8.0
```

## Overriding — Static vs Instance members

``` java
class Employee {
    float salary = 40000;
}

class Programmer extends Employee {
    int bonus = 10000;

    public static void main(String[] args) {
        Programmer p = new Programmer();
        System.out.println("Programmer salary is: " + p.salary);
        System.out.println("Bonus of Programmer is: " + p.bonus);
    }
}
```

```
output
Programmer salary is: 40000.0  
Bonus of Programmer is: 10000
```

**Instance attributes** belong to each object — every object gets its own copy. **Static attributes** belong to the class — shared across all objects, accessed via class name. Static block runs once when the class loads, before `main()`.

## Instance attribute

``` java
class Sample {
    String name = "";  // instance attribute — each object has its own

    public void setName(String s) { name = s; }
}

class Example1 {
    public static void main(String[] args) {
        Sample obj1 = new Sample();  // must create object first
        obj1.setName("Ramu");
        System.out.println(obj1.name);
    }
}
```

```
output
Ramu
```

## Static attribute & method

``` java
class Sample {
    public static String name = "";  // static — shared by all objects

    public static void setName(String s) { name = s; }
}

class Example2 {
    public static void main(String[] args) {
        // Can call via class name directly — no object needed
        Sample.setName("abhiram");
        System.out.println(Sample.name);

        // Can also call via object, but class name is preferred
        Sample obj = new Sample();
        obj.setName("manish");
        System.out.println(obj.name);
    }
}
```

```
output
abhiram  
manish
```

## Static Block

``` java
class A2 {
    // Static block — runs BEFORE main(), exactly once, when class loads
    static {
        System.out.println("static block is invoked");
    }

    public static void main(String[] args) {
        System.out.println("Hello main");
    }
}
```

```
output
static block is invoked  
Hello main
```

By default, `==` and `equals()` both compare *memory addresses*. Override `equals()` to compare *content* instead. Override `toString()` so that `System.out.println(object)` prints something readable instead of `Box@3a4b5c`.

The exam shows code where obj1.equals(obj2) returns false even though both have same values, and asks you to fix it. Answer: add @Override equals() that compares fields.

``` java
class Box {
    int width, height, depth;

    Box(int l, int m, int n) {
        this.width = l;
        this.height = m;
        this.depth = n;
    }

    // Override equals() — compare content, not memory address
    @Override
    public boolean equals(Object o) {
        Box b2 = (Box) o;  // cast Object to Box
        return this.width == b2.width
            && this.height == b2.height
            && this.depth == b2.depth;
    }

    // Override toString() — what to print when you do System.out.println(box)
    @Override
    public String toString() {
        return width + " " + height + " " + depth;
    }
}

public class BoxDemo {
    public static void main(String[] args) {
        Box obj1 = new Box(3, 2, 1);
        Box obj2 = new Box(3, 2, 1);

        System.out.println(obj1 == obj2);         // false — different memory
        System.out.println(obj1.equals(obj2));    // true  — same content
        System.out.println(obj1);                 // calls toString() → "3 2 1"
    }
}
```

# Unit 3: Design Principles & Patterns

## GRASP

**G** eneral **R** esponsibility **A** ssignment **S** oftware **P** atterns — 9 principles by Craig Larman for deciding *which class should own which responsibility*.
The 9: Creator · Information Expert · Low Coupling · Controller · High Cohesion · Polymorphism · Indirection · Pure Fabrication · Protected Variation

### 1. Creator — "Who creates an object?"

Assign creation of B to class A if A **aggregates/contains** B, **records** B, **closely uses** B, or has the **initialisation data** for B. Classic example: Sale contains SalesLineItems → Sale creates SalesLineItems.

## Creator + Controller together is asked in 4 papers. Always accompany your answer with a small class diagram showing the containment relationship

``` java
import java.util.*;

// Order "contains" OrderItem objects → Order is the Creator of OrderItem (GRASP rule)
class OrderItem {
    String productName;
    int    quantity;
    OrderItem(String p, int q) { productName = p; quantity = q; }
}

class Order {
    private List<OrderItem> items = new ArrayList<>();

    // Order CREATES OrderItem — it contains it, so it is responsible
    public void addItem(String product, int qty) {
        items.add(new OrderItem(product, qty));
    }

    public void printOrder() {
        for (OrderItem item : items)
            System.out.println(item.productName + " x" + item.quantity);
    }
}

// OrderService does NOT create OrderItem directly — delegates to Order
class OrderService {
    public void createOrder() {
        Order order = new Order();
        order.addItem("Laptop", 1);
        order.addItem("Mouse",  2);
        order.printOrder();
    }
}

public class Creator {
    public static void main(String[] args) {
        new OrderService().createOrder();
    }
}
```

```
output
Laptop x1  
Mouse x2
```

### 2. Information Expert — "Who has the data should do the work"

Assign a responsibility to the class that already has the information needed to fulfil it. *Who calculates the cart total? ShoppingCart — it owns all the item prices.*

``` java
import java.util.*;

class Item {
    private String name;
    private double price;
    public  Item(String name, double price) { this.name = name; this.price = price; }
    public double getPrice() { return price; }
}

class ShoppingCart {
    private List<Item> items = new ArrayList<>();

    public void addItem(Item item) { items.add(item); }

    // ShoppingCart is the Information Expert — it HAS all the prices
    // so IT calculates the total, not some external CartManager class
    public double calculateTotalPrice() {
        double total = 0;
        for (Item item : items) total += item.getPrice();
        return total;
    }
}

public class InformationExpert {
    public static void main(String[] args) {
        ShoppingCart cart = new ShoppingCart();
        cart.addItem(new Item("Book",   299.0));
        cart.addItem(new Item("Pen",    50.0));
        cart.addItem(new Item("Eraser", 15.0));
        System.out.println("Total: Rs." + cart.calculateTotalPrice());
    }
}
```

```
output
Total: Rs.364.0
```

### 3. Low Coupling — "Minimise dependencies between classes"

Classes should not be tightly wired to each other. Depend on interfaces / use dependency injection. Traveler should work with any Vehicle — not just Car.

``` java
interface Vehicle { void move(); }

class Car  implements Vehicle { public void move() { System.out.println("Car is moving");  } }
class Bike implements Vehicle { public void move() { System.out.println("Bike is moving"); } }

// Traveler depends on Vehicle INTERFACE — loosely coupled
// You can inject any Vehicle without changing Traveler at all
class Traveler {
    private Vehicle v;
    public void setV(Vehicle v)  { this.v = v; }
    public void startJourney()   { v.move(); }
}

public class LowCoupling {
    public static void main(String[] args) {
        Traveler traveler = new Traveler();
        traveler.setV(new Car());     // inject Car
        traveler.startJourney();
        traveler.setV(new Bike());    // swap to Bike — Traveler is unchanged
        traveler.startJourney();
    }
}
```

```
output
Car is moving  
Bike is moving
```

### 4. Controller — "Who handles the system event from the UI?"

A Controller receives events from the UI and *delegates* work to domain objects — it never does business logic itself. Two types: **Façade Controller** (one class for whole system) and **Use Case Controller** (one per use case).

## Controller + Creator together is the most-asked GRASP pair (4 papers). Key rule: Controller DELEGATES, never executes business logic directly

``` java
// Domain objects — these do the actual work
class OrderProcessor {
    void processOrder(String item)  { System.out.println("Processing order for: " + item); }
}
class PaymentProcessor {
    void processPayment(double amt) { System.out.println("Payment of Rs." + amt + " processed"); }
}

// CONTROLLER — receives UI event, delegates to domain — does NO business logic itself
class OrderController {
    private OrderProcessor   op = new OrderProcessor();
    private PaymentProcessor pp = new PaymentProcessor();

    // Called when user clicks "Place Order" in the UI
    public void handlePlaceOrder(String item, double price) {
        op.processOrder(item);    // delegate
        pp.processPayment(price); // delegate
    }
}

public class GRASPController {
    public static void main(String[] args) {
        OrderController controller = new OrderController();
        controller.handlePlaceOrder("Laptop", 75000.0);
    }
}
```

```
output
Processing order for: Laptop  
Payment of Rs.75000.0 processed
```

### 5–9. High Cohesion · Polymorphism · Indirection · Pure Fabrication · Protected Variation

**High Cohesion** — A class should focus on one closely related set of responsibilities. Low cohesion = class does too many unrelated things = hard to understand and maintain.
**Polymorphism** — Assign varying behaviour to the types themselves (via overriding), not to a giant if-else chain. getArea() varies by shape → put it in each Shape subclass.
**Indirection** — Introduce a mediating class to avoid direct coupling between two classes. Related patterns: Adapter, Bridge, Mediator. Example: Salary class sits between caller and Employee.
**Pure Fabrication** — When no domain class is a good fit (assigning responsibility there would violate cohesion/coupling), invent an artificial "service" class — e.g., a Logger or Formatter utility.
**Protected Variation** — Wrap predicted change-points behind a stable interface so other classes aren't affected when the implementation changes. Closely related to OCP.

## SOLID

**S** — Single Responsibility | **O** — Open/Closed | **L** — Liskov Substitution | **I** — Interface Segregation | **D** — Dependency Inversion
Introduced by Robert C. Martin. Goal: low coupling, high cohesion, easier to extend without breaking things.

### S — Single Responsibility Principle (SRP)

"A class should have one, and only one, reason to change." — each class handles exactly ONE job. If it does two things, split it.

Violation: Book class holds data AND does searchBook(). Fix: move searchBook() to a new InventoryView class.

``` java
// BAD — Book has two responsibilities: hold data AND search inventory
class BookBad {
    String title, author;
    String getTitle()              { return title; }
    void   setTitle(String t)       { this.title = t; }
    void   searchBook()             { /* search logic — does NOT belong here! */ }
}

// GOOD — split: Book only holds data; InventoryView only searches
class Book {
    String title, author;
    String getTitle()  { return title; }
    void   setTitle(String t) { this.title = t; }
}

class InventoryView {
    Book book;
    InventoryView(Book book) { this.book = book; }
    void searchBook()        { System.out.println("Searching: " + book.getTitle()); }
}

public class SRP {
    public static void main(String[] args) {
        Book b = new Book();
        b.setTitle("Clean Code");
        new InventoryView(b).searchBook();
    }
}
```

```
output
Searching: Clean Code
```

### O — Open/Closed Principle (OCP)

"Open for extension, closed for modification." Add new features by extending (new subclass / implement interface) — never edit existing working code.

``` java
// BAD — adding BiographyDiscount forces us to MODIFY DiscountManager
class CookbookDiscountBad  { String get() { return "30% Dec 1-24"; } }
class BiographyDiscountBad { String get() { return "50% birthday";  } }
class DiscountManagerBad {                      // must keep editing this!
    void processCookbook(CookbookDiscountBad d)  { System.out.println(d.get()); }
    void processBiography(BiographyDiscountBad d) { System.out.println(d.get()); }
    // every new type = another new method here  ← OCP VIOLATION
}

// GOOD — DiscountManager depends on interface; never needs to change again
interface BookDiscount {
    String getBookDiscount();
}
class CookbookDiscount implements BookDiscount {
    public String getBookDiscount() { return "30% between Dec 1 and 24"; }
}
class BiographyDiscount implements BookDiscount {
    public String getBookDiscount() { return "50% on subject's birthday"; }
}
class DiscountManager {
    // works with ANY BookDiscount — never needs to change
    void processBookDiscount(BookDiscount discount) {
        System.out.println(discount.getBookDiscount());
    }
}

public class OCP {
    public static void main(String[] args) {
        DiscountManager dm = new DiscountManager();
        dm.processBookDiscount(new CookbookDiscount());
        dm.processBookDiscount(new BiographyDiscount());
    }
}
```

```
output
30% between Dec 1 and 24  
50% on subject's birthday
```

### L — Liskov Substitution Principle (LSP)

"Derived types must be completely substitutable for their base types." A subclass must not break any behaviour that the parent promised.

Classic violation: AudiobookDelivery extends BookDelivery but can't implement getDeliveryLocations() — audiobooks aren't physical. Fix: introduce OfflineDelivery and OnlineDelivery branches so neither subclass inherits a method it can't honour.

``` java
// BAD — AudiobookDelivery can't honour getDeliveryLocations() (no physical location)
class BookDeliveryBad {
    void getDeliveryLocations() { System.out.println("Physical store"); }
}
class AudiobookDeliveryBad extends BookDeliveryBad {
    @Override
    void getDeliveryLocations() {
        throw new UnsupportedOperationException("Audiobooks have no physical delivery!"); // VIOLATION
    }
}

// GOOD — split hierarchy so each subclass only inherits what makes sense
class BookDelivery { String title; int userID; }  // base: only shared data

class OfflineDelivery extends BookDelivery {
    void getDeliveryLocations() { System.out.println("Physical store locations"); }
}
class OnlineDelivery extends BookDelivery {
    void getSoftwareOptions()   { System.out.println("Available audio players"); }
}

class HardcoverDelivery extends OfflineDelivery {
    @Override
    void getDeliveryLocations() { System.out.println("Hardcover: 3 store locations"); }
}
class AudiobookDelivery extends OnlineDelivery {
    @Override
    void getSoftwareOptions() { System.out.println("Audiobook: Spotify, Audible"); }
}

public class LSP {
    public static void main(String[] args) {
        OfflineDelivery h = new HardcoverDelivery();
        h.getDeliveryLocations();      // works perfectly

        OnlineDelivery a = new AudiobookDelivery();
        a.getSoftwareOptions();         // works perfectly — no broken methods
    }
}
```

```
output
Hardcover: 3 store locations  
Audiobook: Spotify, Audible
```

### I — Interface Segregation Principle (ISP)

"Clients should not be forced to implement interfaces they do not use." Break fat interfaces into smaller focused ones — each class implements only what it needs.

Violation: HardcoverUI is forced to implement listenSample() (hardcovers can't play audio). Fix: split BookAction → HardcoverAction + AudioAction. The IUser → ILogger + IMail split in the slides is also a common exam answer.

``` java
// BAD — fat interface forces HardcoverUI to implement listenSample() (not applicable)
interface BookActionBad {
    void seeReviews();
    void searchSecondhand();
    void listenSample();        // hardcover can't listen — ISP VIOLATION
}
class HardcoverUIBad implements BookActionBad {
    public void seeReviews()       { System.out.println("show reviews"); }
    public void searchSecondhand()  { System.out.println("search secondhand"); }
    public void listenSample()     {}  // FORCED empty method — violation!
}

// GOOD — split into focused role interfaces
interface BookAction      { void seeReviews(); }           // common
interface HardcoverAction extends BookAction { void searchSecondhand(); }
interface AudioAction     extends BookAction { void listenSample(); }

class HardcoverUI implements HardcoverAction {
    public void seeReviews()       { System.out.println("Hardcover: show reviews"); }
    public void searchSecondhand()  { System.out.println("Hardcover: search secondhand"); }
    // No listenSample() — clean!
}
class AudiobookUI implements AudioAction {
    public void seeReviews()  { System.out.println("Audiobook: show reviews"); }
    public void listenSample() { System.out.println("Audiobook: play sample"); }
    // No searchSecondhand() — clean!
}

public class ISP {
    public static void main(String[] args) {
        new HardcoverUI().seeReviews();
        new HardcoverUI().searchSecondhand();
        new AudiobookUI().listenSample();
    }
}
```

```
output
Hardcover: show reviews  
Hardcover: search secondhand  
Audiobook: play sample
```

### D — Dependency Inversion Principle (DIP)

"High-level modules should not depend on low-level modules. Both should depend on abstractions." Shelf shouldn't directly reference Book — it should use a Product interface. Adding DVD never requires changing Shelf.

``` java
// BAD — high-level Shelf is tightly coupled to low-level Book
class BookBadDIP {
    void seeReviews() { System.out.println("Book reviews"); }
    void readSample()  { System.out.println("Book sample"); }
}
class ShelfBad {
    BookBadDIP book;  // tightly coupled — can't add DVD without editing Shelf!
    void addBook(BookBadDIP book) { this.book = book; }
}

// GOOD — both depend on the Product abstraction
interface Product {
    void seeReviews();
    void getSample();
}
class BookDIP implements Product {
    public void seeReviews() { System.out.println("Book: see reviews"); }
    public void getSample()  { System.out.println("Book: read sample"); }
}
class DVD implements Product {
    public void seeReviews() { System.out.println("DVD: see reviews"); }
    public void getSample()  { System.out.println("DVD: watch trailer"); }
}
class Shelf {
    Product p;  // depends on abstraction — holds Book, DVD, or anything!
    void addProduct(Product product) { this.p = product; }
}

public class DIP {
    public static void main(String[] args) {
        Shelf shelf = new Shelf();

        shelf.addProduct(new BookDIP());
        shelf.p.seeReviews();

        shelf.addProduct(new DVD());   // Shelf didn't change at all!
        shelf.p.getSample();
    }
}
```

```
output
Book: see reviews  
DVD: watch trailer
```

## Singleton

Ensures only **one instance** of a class ever exists. Three things to remember: **(1)** private static field to store the instance, **(2)** private constructor so nobody can call `new` from outside, **(3)** public static `getInstance()` method as the only entry point.

Write the 3-line pattern from memory: private static field · private constructor · public static getInstance(). Then name 3 benefits: controlled access, reduced namespace, lazy initialization.

The pattern itself (minimal — write this in exam)

``` java
class Singleton {
    // (1) private static field — holds the single instance
    private static Singleton obj;

    // (2) private constructor — blocks "new Singleton()" from outside
    private Singleton() {}

    // (3) public static getInstance() — the only way to get the instance
    public static Singleton getInstance() {
        if (obj == null) {
            obj = new Singleton();  // create only once
        }
        return obj;               // always return the same object
    }

    public static void main(String[] args) {
        Singleton s1 = Singleton.getInstance();
        Singleton s2 = Singleton.getInstance();
        System.out.println(s1 == s2);  // true — same object!
    }
}
```

```
output
true
```

Full Printer example (from slides — shared office printer)

``` java
class Printer {
    private static Printer printer;
    private int nrOfPages;

    private Printer() {}

    public static Printer getInstance() {
        return printer == null ? printer = new Printer() : printer;
    }

    public void print(String text) {
        System.out.println(text);
        System.out.println("Pages printed today: " + (++nrOfPages));
        System.out.println("---------");
    }
}

class Employee {
    private final String name, role, assignment;

    Employee(String name, String role, String assignment) {
        this.name = name;
        this.role = role;
        this.assignment = assignment;
    }

    public void printCurrentAssignment() {
        // Every employee gets the SAME printer — Singleton!
        Printer sharedPrinter = Printer.getInstance();
        sharedPrinter.print("Employee: " + name + "\nRole: " + role + "\nAssignment: " + assignment);
    }
}

public class Main {
    public static void main(String[] args) {
        Employee graham = new Employee("Graham", "CEO",       "Making executive decisions");
        Employee sara   = new Employee("Sara",   "Consultant", "Consulting the company");
        Employee tim    = new Employee("Tim",    "Salesman",   "Selling the company's products");
        graham.printCurrentAssignment();
        sara.printCurrentAssignment();
        tim.printCurrentAssignment();
    }
}
```

Save as SingletonPrinter.java → javac SingletonPrinter.java → java Main

```
output
Employee: Graham  
Role: CEO  
Assignment: Making executive decisions  
Pages printed today: 1  
\---------  
Employee: Sara  
...(page count keeps going up — same printer!)
```

## Factory Method

**"Define an interface for creating an object, but let subclasses decide which class to instantiate."** Also called *Virtual Constructor*. The client never calls `new ConcreteProduct()` directly — it calls the factory method.



4 roles: **Product** (interface) · **ConcreteProduct** (actual class) · **Creator** (declares the abstract factory method) · **ConcreteCreator** (overrides it to return a specific product).

Key distinction: Factory Method uses inheritance — subclass decides what to create. Abstract Factory uses composition — you inject a factory object. Builder vs Factory: Factory creates in one call; Builder assembles step-by-step.

``` java
// PRODUCT — the common interface for all created objects
interface Animal {
    void speak();
}

// CONCRETE PRODUCTS
class Dog implements Animal {
    public void speak() { System.out.println("Dog says: Woof!"); }
}
class Cat implements Animal {
    public void speak() { System.out.println("Cat says: Meow!"); }
}

// CREATOR — abstract class with the factory method
abstract class AnimalFactory {
    // Factory method — subclass decides what to instantiate
    public abstract Animal createAnimal();

    // Can use the factory method internally
    public void makeAnimalSpeak() {
        Animal a = createAnimal();
        a.speak();
    }
}

// CONCRETE CREATORS — override factory method to return specific product
class DogFactory extends AnimalFactory {
    @Override
    public Animal createAnimal() { return new Dog(); }
}
class CatFactory extends AnimalFactory {
    @Override
    public Animal createAnimal() { return new Cat(); }
}

public class FactoryMethod {
    public static void main(String[] args) {
        AnimalFactory f1 = new DogFactory();
        f1.makeAnimalSpeak();   // client doesn't know it's a Dog

        AnimalFactory f2 = new CatFactory();
        f2.makeAnimalSpeak();   // client doesn't know it's a Cat
    }
}
```

## Builder

**"Separate the construction of a complex object from its representation."** A **Director** drives the sequence of build steps; a **ConcreteBuilder** does the actual assembly. Swap the builder to get a completely different product.



4 roles: **Builder** (interface — defines build steps) · **ConcreteBuilder** (implements steps, holds the product) · **Director** (calls steps in the right order) · **Product** (the complex object).

Scenario from slides: Burger restaurant — Chef (Director) tells CheeseBurgerBuilder or VegBurgerBuilder (ConcreteBuilder) to build each part. Same Director, different Builder → different Burger.

``` java
// PRODUCT — the complex object being built step-by-step
class Burger {
    private String bun, meat, salad, cheese, sauce;

    public void setBun(String b)    { bun    = b; }
    public void setMeat(String m)   { meat   = m; }
    public void setSalad(String s)  { salad  = s; }
    public void setCheese(String c) { cheese = c; }
    public void setSauce(String s)  { sauce  = s; }

    public void print() {
        System.out.println("Burger → bun:" + bun + " meat:" + meat +
            " salad:" + salad + " cheese:" + cheese + " sauce:" + sauce);
    }
}

// BUILDER interface — defines what steps exist
interface BurgerBuilder {
    void buildBun();
    void buildMeat();
    void buildSalad();
    void buildCheese();
    void buildSauce();
    Burger getBurger();
}

// CONCRETE BUILDER 1 — CheeseBurger
class CheeseBurgerBuilder implements BurgerBuilder {
    private Burger burger = new Burger();
    public void buildBun()    { burger.setBun("White Bread"); }
    public void buildMeat()   { burger.setMeat("Beef"); }
    public void buildSalad()  { burger.setSalad("Iceberg"); }
    public void buildCheese() { burger.setCheese("American"); }
    public void buildSauce()  { burger.setSauce("Secret Sauce"); }
    public Burger getBurger() { return burger; }
}

// CONCRETE BUILDER 2 — VegBurger
class VegBurgerBuilder implements BurgerBuilder {
    private Burger burger = new Burger();
    public void buildBun()    { burger.setBun("Whole Wheat"); }
    public void buildMeat()   { burger.setMeat("Veggie Patty"); }
    public void buildSalad()  { burger.setSalad("Spinach"); }
    public void buildCheese() { burger.setCheese("None"); }
    public void buildSauce()  { burger.setSauce("Mayo"); }
    public Burger getBurger() { return burger; }
}

// DIRECTOR — calls builder steps in the correct order
class Chef {
    private BurgerBuilder builder;

    public void setBuilder(BurgerBuilder b) { this.builder = b; }

    public Burger build() {
        builder.buildBun();
        builder.buildMeat();
        builder.buildSalad();
        builder.buildCheese();
        builder.buildSauce();
        return builder.getBurger();
    }
}

public class BuilderPattern {
    public static void main(String[] args) {
        Chef chef = new Chef();   // same Director

        chef.setBuilder(new CheeseBurgerBuilder());  // swap builder → different product
        chef.build().print();

        chef.setBuilder(new VegBurgerBuilder());
        chef.build().print();
    }
}
```

```
output
Burger → bun:White Bread meat:Beef salad:Iceberg cheese:American sauce:Secret Sauce  
Burger → bun:Whole Wheat meat:Veggie Patty salad:Spinach cheese:None sauce:Mayo
```

## Adapter

The Adapter lets two incompatible interfaces work together. **4 roles to name in exam:** Target (interface client expects) · Adapted (existing incompatible interface) · Adapter (the bridge class) · Client (uses the Target).



Scenario: `AudioPlayer` plays mp3 natively. `VlcPlayer` / `Mp4Player` implement a different interface. `MediaAdapter` bridges them so `AudioPlayer` can play all formats.

This scenario is copied word-for-word in 4 exam papers. Memorise the 4 class/interface names: MediaPlayer, AdvancedMediaPlayer, MediaAdapter, AudioPlayer. Know which role each plays.

``` java
// TARGET — what the client works with
interface MediaPlayer {
    void play(String audioType, String fileName);
}

// ADAPTEE — existing interface with incompatible methods
interface AdvancedMediaPlayer {
    void playVlc(String fileName);
    void playMp4(String fileName);
}

class VlcPlayer implements AdvancedMediaPlayer {
    public void playVlc(String fileName) { System.out.println("Playing vlc: " + fileName); }
    public void playMp4(String fileName) {}  // not supported
}

class Mp4Player implements AdvancedMediaPlayer {
    public void playVlc(String fileName) {}  // not supported
    public void playMp4(String fileName) { System.out.println("Playing mp4: " + fileName); }
}

// ADAPTER — implements Target, wraps Adaptee internally
class MediaAdapter implements MediaPlayer {
    AdvancedMediaPlayer advancedPlayer;

    MediaAdapter(String audioType) {
        if (audioType.equalsIgnoreCase("vlc"))
            advancedPlayer = new VlcPlayer();
        else if (audioType.equalsIgnoreCase("mp4"))
            advancedPlayer = new Mp4Player();
    }

    public void play(String audioType, String fileName) {
        if (audioType.equalsIgnoreCase("vlc"))
            advancedPlayer.playVlc(fileName);
        else if (audioType.equalsIgnoreCase("mp4"))
            advancedPlayer.playMp4(fileName);
    }
}

// CLIENT — only knows about MediaPlayer, not Vlc/Mp4 details
class AudioPlayer implements MediaPlayer {
    MediaAdapter mediaAdapter;

    public void play(String audioType, String fileName) {
        if (audioType.equalsIgnoreCase("mp3")) {
            System.out.println("Playing mp3: " + fileName);
        } else if (audioType.equalsIgnoreCase("vlc") || audioType.equalsIgnoreCase("mp4")) {
            mediaAdapter = new MediaAdapter(audioType);  // delegate to adapter
            mediaAdapter.play(audioType, fileName);
        } else {
            System.out.println("Format not supported: " + audioType);
        }
    }
}

public class AdapterPattern {
    public static void main(String[] args) {
        AudioPlayer player = new AudioPlayer();
        player.play("mp3", "song.mp3");
        player.play("vlc", "movie.vlc");
        player.play("mp4", "video.mp4");
        player.play("avi", "clip.avi");
    }
}
```

```
output
Playing mp3: song.mp3  
Playing vlc: movie.vlc  
Playing mp4: video.mp4  
Format not supported: avi
```

## Proxy

A Proxy stands in for a real object. **Virtual Proxy** (what exam always tests): delays creation of an expensive object until it's actually needed. The `ProxyImage` holds a reference to `RealImage` but only creates it on the first `display()` call.



**3 types to name in exam:** Virtual (lazy loading) · Protection (access control) · Remote (remote object).

Draw this class diagram: Subject interface → RealImage (expensive, loads on disk) and ProxyImage (lightweight, creates RealImage lazily). ProxyImage has a null check — if null, create; else reuse.

``` java
// Subject — shared interface for both Real and Proxy
interface Image {
    void display();
}

// RealImage — expensive: loads from disk when created
class RealImage implements Image {
    private String fileName;

    RealImage(String fileName) {
        this.fileName = fileName;
        loadFromDisk();   // expensive — runs in constructor
    }

    private void loadFromDisk() {
        System.out.println("Loading from disk: " + fileName);
    }

    public void display() {
        System.out.println("Displaying: " + fileName);
    }
}

// ProxyImage — lightweight wrapper, creates RealImage only when needed
class ProxyImage implements Image {
    private String fileName;
    private RealImage realImage;  // starts as null — not loaded yet

    ProxyImage(String fileName) {
        this.fileName = fileName;
        // Note: we do NOT create RealImage here
    }

    public void display() {
        if (realImage == null) {
            realImage = new RealImage(fileName);  // load ONLY on first call
        }
        realImage.display();                      // reuse on subsequent calls
    }
}

public class ProxyPattern {
    public static void main(String[] args) {
        Image image = new ProxyImage("photo.jpg");

        System.out.println("First call:");
        image.display();   // loads from disk, then displays

        System.out.println("\nSecond call:");
        image.display();   // does NOT reload — cached
    }
}
```

```
output
First call:  
Loading from disk: photo.jpg  
Displaying: photo.jpg  
```

Second call:
Displaying: photo.jpg

## Chain of Responsibility

A request is passed along a chain of handlers. Each handler either processes it (if within its limit) or passes it to the next. Decouples the sender from the receiver. The chain order matters — set it up in `main()` using `setSuccessor()`.

For the logging system variant (also in exam): same exact structure — just replace Manager/VP/CEO with ConsoleLogger/FileLogger/ErrorLogger, and replace approval limit with log level.

``` java
// Abstract handler — stores successor, defines the chain logic
abstract class TransactionProcessor {
    private TransactionProcessor successor;  // next handler in chain

    abstract protected double getApprovalLimit();
    abstract protected String getDesignation();

    public void setSuccessor(TransactionProcessor successor) {
        this.successor = successor;
    }

    public void approve(double amount) {
        if (amount <= 0) {
            System.out.println("Invalid amount.");
            return;
        }
        if (amount <= getApprovalLimit()) {
            // This handler can approve it
            System.out.println(getDesignation() + " approved ₹" + amount);
        } else {
            // Too large — pass to next handler
            if (successor == null)
                System.out.println("Amount ₹" + amount + " exceeds max limit! Rejected.");
            else
                successor.approve(amount);
        }
    }
}

// Concrete handlers
class Manager extends TransactionProcessor {
    protected double getApprovalLimit() { return 100000.0; }   // 1 lakh
    protected String getDesignation()   { return "Manager"; }
}

class VicePresident extends TransactionProcessor {
    protected double getApprovalLimit() { return 1000000.0; }  // 10 lakhs
    protected String getDesignation()   { return "Vice President"; }
}

class CEO extends TransactionProcessor {
    protected double getApprovalLimit() { return 2500000.0; }  // 25 lakhs
    protected String getDesignation()   { return "CEO"; }
}

public class ChainOfResponsibility {
    public static void main(String[] args) {
        // Build the chain: Manager → VP → CEO
        Manager      manager = new Manager();
        VicePresident vp     = new VicePresident();
        CEO           ceo    = new CEO();

        manager.setSuccessor(vp);   // manager passes to vp if too big
        vp.setSuccessor(ceo);         // vp passes to ceo if too big

        manager.approve(50000.0);     // Manager handles (< 1L)
        manager.approve(500000.0);    // VP handles (1L–10L)
        manager.approve(2000000.0);   // CEO handles (10L–25L)
        manager.approve(3000000.0);   // Rejected! (> 25L)
    }
}
```

```
output
Manager approved ₹50000.0  
Vice President approved ₹500000.0  
CEO approved ₹2000000.0  
Amount ₹3000000.0 exceeds max limit! Rejected.
```

## MVC

Splits an application into three parts: **Model** (data + business rules), **View** (what the user sees), **Controller** (handles user input, talks to Model, updates View). Goal: loose coupling between UI and logic.

Flow to memorise: Client → Controller → Model → Controller → View → Client. Draw this as a diagram in the exam.

``` java
// MODEL — holds data and business logic
class Employee {
    private String name;
    private String department;

    public Employee(String name, String dept) { this.name = name; this.department = dept; }
    public String getName()        { return name; }
    public void   setName(String n)  { this.name = n; }
    public String getDepartment()   { return department; }
    public void   setDepartment(String d) { this.department = d; }
}

// VIEW — displays data, knows nothing about business logic
class EmployeeView {
    public void printEmployeeDetails(String name, String dept) {
        System.out.println("Employee: " + name + " | Department: " + dept);
    }
}

// CONTROLLER — middleman: receives input, updates model, tells view to refresh
class EmployeeController {
    private Employee     model;
    private EmployeeView view;

    EmployeeController(Employee model, EmployeeView view) {
        this.model = model;
        this.view  = view;
    }

    // Input from user → update model
    public void setEmployeeName(String name)  { model.setName(name); }
    public void setDepartment(String dept)    { model.setDepartment(dept); }

    // Refresh view with latest model data
    public void updateView() {
        view.printEmployeeDetails(model.getName(), model.getDepartment());
    }
}

public class MVCDemo {
    public static void main(String[] args) {
        Employee           model      = new Employee("Alice", "Engineering");
        EmployeeView       view       = new EmployeeView();
        EmployeeController controller = new EmployeeController(model, view);

        controller.updateView();             // initial display

        controller.setEmployeeName("Bob");  // user changes data
        controller.setDepartment("Finance");
        controller.updateView();             // view refreshes automatically
    }
}
```

```
output
Employee: Alice | Department: Engineering  
Employee: Bob | Department: Finance
```

# Unit 4: Structural & Behavioral Patterns

## Factory

**"Define an interface for creating an object, but let subclasses decide which class to instantiate."** Also called *Virtual Constructor*. The client only talks to the Product interface — it never calls `new ConcreteProduct()` directly.



4 roles: **Product** (interface) · **ConcreteProduct** (actual class) · **Creator** (declares factory method) · **ConcreteCreator** (decides which ConcreteProduct to make).

Key difference from Abstract Factory: Factory Method uses inheritance (subclass decides), Abstract Factory uses composition (object holds a factory). Builder vs Factory: Builder constructs step-by-step; Factory creates in one shot.

``` java
// PRODUCT — the interface all created objects share
interface Animal {
    void speak();
}

// CONCRETE PRODUCTS
class Dog implements Animal {
    public void speak() { System.out.println("Dog says: Woof!"); }
}
class Cat implements Animal {
    public void speak() { System.out.println("Cat says: Meow!"); }
}

// CREATOR — declares the factory method (abstract)
abstract class AnimalFactory {
    // Factory method — subclass decides what to create
    public abstract Animal createAnimal();

    // Can also have shared logic that uses the factory method
    public void makeAnimalSpeak() {
        Animal a = createAnimal();   // calls the factory method
        a.speak();
    }
}

// CONCRETE CREATORS — override factory method to return specific product
class DogFactory extends AnimalFactory {
    @Override
    public Animal createAnimal() { return new Dog(); }
}
class CatFactory extends AnimalFactory {
    @Override
    public Animal createAnimal() { return new Cat(); }
}

public class FactoryMethod {
    public static void main(String[] args) {
        AnimalFactory factory1 = new DogFactory();
        factory1.makeAnimalSpeak();   // client doesn't know it's a Dog

        AnimalFactory factory2 = new CatFactory();
## Builder
        factory2.makeAnimalSpeak();   // client doesn't know it's a Cat
    }
}
```

**"Separate the construction of a complex object from its representation."** A **Director** drives the build steps; a **Builder** does the actual assembly. Swap the ConcreteBuilder to get a different product. From the slides: a burger restaurant with CheeseBurger vs VegBurger builders.



4 roles: **Builder** (interface for steps) · **ConcreteBuilder** (implements steps) · **Director** (calls steps in order) · **Product** (the complex object).

Builder vs Factory: Factory creates in one call. Builder builds step-by-step. Use Builder when the object needs many optional parts or a fixed sequence of assembly steps.

``` java
// PRODUCT — the complex object being built
class Burger {
    private String bun, meat, salad, cheese, sauce;

    public void setBun(String b)    { bun    = b; }
    public void setMeat(String m)   { meat   = m; }
    public void setSalad(String s)  { salad  = s; }
    public void setCheese(String c) { cheese = c; }
    public void setSauce(String s)  { sauce  = s; }

    public void print() {
        System.out.println("Burger: bun=" + bun + " | meat=" + meat +
            " | salad=" + salad + " | cheese=" + cheese + " | sauce=" + sauce);
    }
}

// BUILDER interface — defines what steps exist
interface BurgerBuilder {
    void buildBun();
    void buildMeat();
    void buildSalad();
    void buildCheese();
    void buildSauce();
    Burger getBurger();
}

// CONCRETE BUILDER 1 — assembles a CheeseBurger
class CheeseBurgerBuilder implements BurgerBuilder {
    private Burger burger = new Burger();
    public void buildBun()    { burger.setBun("White Bread"); }
    public void buildMeat()   { burger.setMeat("Beef"); }
    public void buildSalad()  { burger.setSalad("Iceberg"); }
    public void buildCheese() { burger.setCheese("American"); }
    public void buildSauce()  { burger.setSauce("Secret Sauce"); }
    public Burger getBurger() { return burger; }
}

// CONCRETE BUILDER 2 — assembles a VegBurger
class VegBurgerBuilder implements BurgerBuilder {
    private Burger burger = new Burger();
    public void buildBun()    { burger.setBun("Whole Wheat"); }
    public void buildMeat()   { burger.setMeat("Veggie Patty"); }
    public void buildSalad()  { burger.setSalad("Spinach"); }
    public void buildCheese() { burger.setCheese("None"); }
    public void buildSauce()  { burger.setSauce("Mayo"); }
    public Burger getBurger() { return burger; }
}

// DIRECTOR — calls builder steps in the right order
class Chef {
    private BurgerBuilder builder;

    public void setBuilder(BurgerBuilder builder) { this.builder = builder; }

    public Burger build() {
        builder.buildBun();
        builder.buildMeat();
        builder.buildSalad();
        builder.buildCheese();
        builder.buildSauce();
        return builder.getBurger();
    }
}

public class BuilderPattern {
    public static void main(String[] args) {
        Chef chef = new Chef();

        chef.setBuilder(new CheeseBurgerBuilder());
        chef.build().print();

        chef.setBuilder(new VegBurgerBuilder());
        chef.build().print();
    }
}
```

```
output
Burger: bun=White Bread | meat=Beef | salad=Iceberg | cheese=American | sauce=Secret Sauce  
Burger: bun=Whole Wheat | meat=Veggie Patty | salad=Spinach | cheese=None | sauce=Mayo
```

**"Create new objects by copying (cloning) an existing object."** Use when creating an object from scratch is expensive or complex. In Java, implement the `Cloneable` interface and override `clone()`.

## Prototype



When to use: object creation is expensive, classes to instantiate are specified at runtime, or you want copies with slightly different state.

``` java
// Prototype — must implement Cloneable and override clone()
class Shape implements Cloneable {
    private String type;
    private String color;

    Shape(String type, String color) {
        this.type  = type;
        this.color = color;
        System.out.println("Expensive construction of: " + type);  // imagine this is costly
    }

    // clone() creates a copy without running the expensive constructor again
    @Override
    public Shape clone() {
        try {
            return (Shape) super.clone();   // shallow copy
        } catch (CloneNotSupportedException e) {
            return null;
        }
    }

    public void setColor(String c) { this.color = c; }

    @Override
    public String toString() { return type + " [" + color + "]"; }
}

public class PrototypePattern {
    public static void main(String[] args) {
        // Create one expensive original
        Shape original = new Shape("Circle", "Red");

        // Clone it — no expensive constructor runs again
        Shape copy1 = original.clone();
        Shape copy2 = original.clone();
        copy2.setColor("Blue");  // tweak the copy's state

        System.out.println("Original: " + original);
        System.out.println("Copy 1:   " + copy1);
        System.out.println("Copy 2:   " + copy2);
        System.out.println("Same object? " + (original == copy1)); // false — different objects
    }
}
```

```
output
Expensive construction of: Circle  
Original: Circle \[Red\]  
Copy 1: Circle \[Red\]  
Copy 2: Circle \[Blue\]  
Same object? false
```

**"Provide a unified interface to a set of interfaces in a subsystem."** A Facade class hides the complexity of multiple subsystems behind one simple interface. The client only talks to the Facade.

## Facade



Classic exam question: HomeManager controlling TV, Light, MusicSystem, SecuritySystem — identify this as Facade.

If the exam shows a diagram of one class calling many subsystem classes, the answer is Facade. A Facade class can often be a Singleton (only one entry point needed).

``` java
// Complex subsystem classes — each does its own thing
class TV {
    void on()  { System.out.println("TV on"); }
    void off() { System.out.println("TV off"); }
}
class Light {
    void dim()  { System.out.println("Lights dimmed"); }
    void full() { System.out.println("Lights full"); }
}
class MusicSystem {
    void play() { System.out.println("Music playing"); }
    void stop() { System.out.println("Music stopped"); }
}
class SecuritySystem {
    void arm()   { System.out.println("Security armed"); }
    void disarm() { System.out.println("Security disarmed"); }
}

// FACADE — simple interface that hides all the subsystem complexity
class HomeManager {
    private TV             tv      = new TV();
    private Light          light   = new Light();
    private MusicSystem   music   = new MusicSystem();
    private SecuritySystem security = new SecuritySystem();

    // Client just calls one method — Facade handles all the subsystem calls
    public void movieMode() {
        System.out.println("--- Movie Mode ---");
        security.disarm();
        light.dim();
        tv.on();
        music.stop();
    }

    public void leaveMode() {
        System.out.println("--- Leave Mode ---");
        tv.off();
        music.stop();
        light.full();
        security.arm();
    }
}

public class FacadePattern {
    public static void main(String[] args) {
        HomeManager home = new HomeManager();
        home.movieMode();   // client calls ONE method — subsystems hidden
        home.leaveMode();
    }
}
```

```
output
\--- Movie Mode ---  
Security disarmed  
Lights dimmed  
TV on  
Music stopped  
\--- Leave Mode ---  
TV off  
Music stopped  
Lights full  
Security armed
```

**"Use sharing to support a large number of fine-grained objects efficiently."** Split object state into **intrinsic** (shared, stored in flyweight) and **extrinsic** (context-specific, passed in). A FlyweightFactory caches and reuses flyweight objects.

## Flyweight

Intrinsic = shared internal state (e.g. character font/size). Extrinsic = context-dependent state (e.g. character position on screen). The factory returns an existing flyweight instead of creating a new one each time.

``` java
import java.util.*;

// FLYWEIGHT — stores intrinsic (shared) state
class TreeType {
    private String name, color;   // intrinsic — same for all trees of this type

    TreeType(String name, String color) {
        this.name = name; this.color = color;
        System.out.println("Creating TreeType: " + name);
    }

    // extrinsic state (x, y position) is passed in — NOT stored here
    void draw(int x, int y) {
        System.out.println("Drawing " + color + " " + name + " at (" + x + "," + y + ")");
    }
}

// FLYWEIGHT FACTORY — caches and reuses TreeType objects
class TreeFactory {
    private static Map<String, TreeType> cache = new HashMap<>();

    public static TreeType getTreeType(String name, String color) {
        String key = name + "_" + color;
        // Return existing flyweight if already created — key savings!
        if (!cache.containsKey(key)) {
            cache.put(key, new TreeType(name, color));
        }
        return cache.get(key);
    }
}

// Tree holds extrinsic state (position) and a reference to shared flyweight
class Tree {
    private int x, y;
    private TreeType type;  // shared object

    Tree(int x, int y, TreeType type) { this.x = x; this.y = y; this.type = type; }
    void draw() { type.draw(x, y); }
}

public class FlyweightPattern {
    public static void main(String[] args) {
        // 4 trees, but only 2 TreeType objects created (Oak and Pine shared)
        Tree[] forest = {
            new Tree(1, 2, TreeFactory.getTreeType("Oak",  "Green")),
            new Tree(3, 5, TreeFactory.getTreeType("Pine", "Dark Green")),
            new Tree(7, 1, TreeFactory.getTreeType("Oak",  "Green")),   // reused!
            new Tree(2, 9, TreeFactory.getTreeType("Pine", "Dark Green")), // reused!
        };
        for (Tree t : forest) t.draw();
    }
}
```

```
output
Creating TreeType: Oak  
Creating TreeType: Pine  
Drawing Green Oak at (1,2)  
Drawing Dark Green Pine at (3,5)  
Drawing Green Oak at (7,1)  
Drawing Dark Green Pine at (2,9)
```

**"Encapsulate a request as an object."** Decouples the sender (Invoker) from the receiver (the object that actually does the work). 5 roles: **Command** (interface with execute()) · **ConcreteCommand** (binds Receiver to action) · **Receiver** (does the real work) · **Invoker** (holds and fires Commands) · **Client** (creates Commands and sets Receivers).

## Command

``` java
import java.util.*;

// COMMAND interface
interface Order {
    void execute();
}

// RECEIVER — knows how to do the actual work
class Stock {
    private String name     = "ABC";
    private int    quantity  = 10;

    public void buy()  { System.out.println("Stock [" + name + " qty:" + quantity + "] BOUGHT"); }
    public void sell() { System.out.println("Stock [" + name + " qty:" + quantity + "] SOLD"); }
}

// CONCRETE COMMANDS — bind Receiver to a specific action
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

// INVOKER — queues and fires commands without knowing what they do
class Broker {
    private List<Order> orderList = new ArrayList<>();

    public void takeOrder(Order order) { orderList.add(order); }

    public void placeOrders() {
        for (Order order : orderList) order.execute();
        orderList.clear();
    }
}

// CLIENT — creates Commands and gives them to Invoker
public class CommandPattern {
    public static void main(String[] args) {
        Stock     abcStock       = new Stock();
        BuyStock  buyStockOrder  = new BuyStock(abcStock);
        SellStock sellStockOrder = new SellStock(abcStock);

        Broker broker = new Broker();
        broker.takeOrder(buyStockOrder);
        broker.takeOrder(sellStockOrder);
        broker.placeOrders();  // fires all queued commands
    }
}
```

```
output
Stock \[ABC qty:10\] BOUGHT  
Stock \[ABC qty:10\] SOLD
```

**"Provide a way to access elements of a collection sequentially without exposing its underlying implementation."** 4 roles: **Iterator** (interface: hasNext, next) · **ConcreteIterator** (tracks position) · **Aggregate** (collection interface: createIterator) · **ConcreteAggregate** (returns ConcreteIterator).

## Iterator

``` java
// ITERATOR interface — defines traversal operations
interface Iterator {
    boolean hasNext();
    Object  next();
}

// AGGREGATE interface — defines how to get an iterator
interface Container {
    Iterator getIterator();
}

// CONCRETE AGGREGATE — a collection of names
class NameRepository implements Container {
    private String[] names = { "Alice", "Bob", "Charlie", "David" };

    public Iterator getIterator() {
        return new NameIterator();
    }

    // CONCRETE ITERATOR — inner class, knows the collection's internals
    private class NameIterator implements Iterator {
        int index = 0;

        public boolean hasNext() {
            return index < names.length;
        }

        public Object next() {
            return hasNext() ? names[index++] : null;
        }
    }
}

// CLIENT — uses Iterator, doesn't know it's a String array inside
public class IteratorPattern {
    public static void main(String[] args) {
        NameRepository repo     = new NameRepository();
        Iterator       iterator = repo.getIterator();

        while (iterator.hasNext()) {
            System.out.println("Name: " + iterator.next());
        }
    }
}
```

An **Anti-Pattern** is a commonly occurring solution that generates decidedly negative consequences — a "bad idea" that seems reasonable at first. Three levels: **Development** (code level) · **Architecture** (system level) · **Management** (process level).

## Anti-Patterns



**Pattern vs Anti-Pattern:** Pattern = repeatable good solution. Anti-Pattern = recognised poor solution + a refactored solution to fix it.

Analysis Paralysis — Management Anti-Pattern

**What it is:** The team spends so long analysing the problem that no actual development happens. Analysis goes beyond providing meaningful value.
**Symptoms:** Multiple project restarts, cost of analysis exceeds expectation with no end point, design decisions made during analysis phase, no user interaction in analysis.
**Causes:** Management insists all analysis must finish before design begins, waterfall mindset, goals not well defined.
**Refactored Solution:** Switch to incremental development — build in small internal + external increments rather than trying to know everything upfront.

Vendor Lock-In — Architecture Anti-Pattern

**What it is:** A project becomes completely dependent on a specific vendor's technology. When the vendor changes their product, the entire application breaks.
**Symptoms:** Commercial product upgrades drive your maintenance cycle, promised features never arrive, unable to switch vendors without full rewrite.
**Causes:** Product selected on marketing alone, no technical isolation layer, application requires deep product-specific knowledge.
**Refactored Solution:** Introduce an **Isolation Layer** — an abstraction that separates your application from the vendor technology. Your app talks to the isolation layer; only the layer knows about the vendor.

The Blob (God Class) — Development Anti-Pattern

Blob appears in 4+ papers. Always mention: symptoms (one class with 60+ attributes/operations), causes (no OO architecture), solution (refactor into smaller SRP classes).

**What it is:** One class monopolises all processing while all others just hold data. The "God Class" does everything.
**Symptoms:** Single class with 60+ attributes/operations, disparate unrelated responsibilities in one class, class is too complex to reuse or test, expensive to load into memory.
**Causes:** Lack of OO architecture, lack of architecture enforcement, too limited design review.
**Refactored Solution (3 steps):**
Step 1 — Identify and categorise related attributes/operations into cohesive contracts.
Step 2 — Find natural homes for each contract and migrate operations there (e.g. move catalog operations from LIBRARY to CATALOG).
Step 3 — Remove far-coupled and redundant associations; replace transient associations with type specifiers.

``` java
// THE BLOB (BAD) — one class does everything
class LibraryBlob {
    // Data (should belong elsewhere)
    String libraryName;
    String[] catalogNames;
    String[] bookTitles;
    String[] memberNames;
    int[]    memberIds;

    // Operations — completely unrelated things crammed into one class
    void searchCatalog(){ }
    void addBook()      { }
    void removeBook()   { }
    void registerMember(){ }
    void issueLoan()    { }
    void returnLoan()   { }
    void sendEmail()    { }
    void generateReport(){ }
    // ... 60+ more methods — this IS the Blob
}

// REFACTORED (GOOD) — each class has one focused responsibility (SRP)
class Library {
    String name;
}

class Catalog {
    String[] bookTitles;
    void searchCatalog()  { System.out.println("Catalog: searching..."); }
    void addBook(String t) { System.out.println("Catalog: added " + t); }
}

class MemberRegistry {
    String[] members;
    void register(String m) { System.out.println("Registered: " + m); }
}

class LoanService {
    void issueLoan(String book, String member) {
        System.out.println("Loan issued: " + book + " → " + member);
    }
    void returnLoan(String book) {
        System.out.println("Returned: " + book);
    }
}

public class BlobAntiPattern {
    public static void main(String[] args) {
        Catalog        catalog  = new Catalog();
        MemberRegistry registry = new MemberRegistry();
        LoanService    loans    = new LoanService();

        catalog.addBook("Clean Code");
        registry.register("Alice");
        loans.issueLoan("Clean Code", "Alice");
        loans.returnLoan("Clean Code");
    }
}
```

```
output
Catalog: added Clean Code  
Registered: Alice  
Loan issued: Clean Code → Alice  
Returned: Clean Code
```

Quick Reference — All 4 Anti-Patterns

**Analysis Paralysis** — Over-analysing, never building. Fix: incremental development.
**Vendor Lock-In** — Tightly coupled to one vendor. Fix: isolation layer / abstraction.
**The Blob** — One God Class does everything. Fix: split using SRP into focused classes.
**Lava Flow** — Dead code and obsolete design frozen in place because nobody dares remove it (fear of breaking something). Fix: document and progressively refactor; unit tests give courage to remove.
