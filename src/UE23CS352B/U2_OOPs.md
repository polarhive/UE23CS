![[Pasted image 20260227091122.png]]

# Java

 Java programming language was originally developed by Sun Microsystems, by James Gosling and released in 1995 as core component of Sun Microsystems' Java platform (Java 1.0). In 2010, Oracle Corporation acquired Sun Microsystems and became the steward of Java.

1. Simple
2. Object Oriented
3. Distributed
4. Robust
5. Secure
6. Portable
7. Interpreted
8. High Performance

# Components

## JVM, JRE, JDK

JVM is a platform-dependent execution environment that converts Java bytecode(.class file) into machine language and executes it. **A specification** where the working of Java Virtual Machine is specified. But implementation provider is independent in choosing the algorithm. Its implementation has been provided by Oracle and other companies.

- **An implementation** Its implementation is known as JRE (Java Runtime Environment).
- **Runtime Instance** Whenever you write Java command on the command prompt to run the Java class, an instance of JVM is created.

---

# Class

```java
class ClassName {
	// attr(var)
	// methods(functions)
}
```

## Attributes

Represent the property or data of an object. Data members of the class

```java
class Student {
	int rollNo; // <<- attr of this class
	String name; // <<- attr of this class
}
```

## Methods

Represent the behaviour or actions an object can perform. It uses attributes to perform and action.

```java
class Student {
	int rollNo; // <<- attr of this class
	String name; // <<- attr of this class
	
	void display() { // <<- display() method
		System.out.println(rollNo + " " + name);
	}
}
```

## Object

> **Object**: An instance of a class that contains **state (attributes)** and **behavior (methods)**

- A real world entity created from a class.
- It represents a specific **instance of a class** and occupies memory.
- If a class is a blueprint, an object is the actual thing made from it.
- Attributes and methods can be accessed via dot(.) operator.
- Object (instance) of a class is created with ‘**new**’ keyword.
- Objects have their own memory.

```java
public class Main {
	public static void main (String[] args) {
		Student s1 = new Student();
		
		s1.rollNo = 1;
		s1.name = "John";
		
		s1.display();
	}
}

```

- **Identitiy**: Unique references: `s1
- **State**: Values of attributes `rollNo, name`
- **Behaviour**: Methods it can perform: `display()`

---

## Abstraction

**Data abstraction** in Object-oriented programming is a process of providing functionality to the users by hiding its implementation details from them. In other words, the user will have just the knowledge of what an entity is doing instead of its internal working. In Java, abstraction is achieved by interfaces and abstract classes. We can achieve 100% abstraction using interfaces.

Abstraction defines an object in terms of its properties (attributes), behavior (methods), and interfaces (means of communicating with other objects). Abstraction refers to the act of representing essential features without including the background details or explanations.

Since classes use the concept of data abstraction, they are known as **Abstract Data Types** **(ADT)**.

**Abstract class in Java:**

- In Java, we can achieve Data Abstraction using Abstract classes and interfaces.
- Interfaces allow 100% abstraction (complete abstraction).
- An Abstract class is a class whose objects can’t be created.
- An Abstract class is created through the use of the abstract keyword. It is used to represent a concept.
- An abstract class can have abstract methods (methods without body) as well as non- abstract methods or concrete methods (methods with the body). A non-abstract class cannot have abstract methods.
- The class has to be declared as abstract if it contains at least one abstract method.
- An abstract class does not allow you to create objects of its type. In this case, we can only use the objects of its subclass.
- Using an abstract class, we can achieve 0 to 100% abstraction.
- There is always a default constructor in an abstract class, it can also have a parameterized constructor.
- The abstract class can also contain final and static methods.

```java
abstract class Animal {
	public abstract void animalSound();
	public void sleep() {
		System.out.println("Zzz");
	}
}

class Dog extends Animal {
	@Override
	public void animalSound() {
		System.out.println("The dog says bow bow");
	}
}

class Main {
	public static void main (String[] args) {
		Dog myDog = new Dog();
		myDog.animalSound();
		myDog.sleep(); 
	}
}
```

![[Pasted image 20260227091901.png]]

---

## Encapsulation

 - The wrapping up of data and functions into a single unit is known as encapsulation.
- The data is not accessible to the outside world, only those function which are wrapped in can access it.
- These functions provide the interface between the object’s data and the program.
- This insulation of the data from direct access by the program is called data hiding or information hiding.

### **Advantages of Encapsulation**

- **Data Hiding**: it is a way of restricting the access of our data members by hiding the implementation details.
- **Increased Flexibility**: We can make the variables of the class read-only or write-only depending on our requirements.
- **Reusability**: Encapsulation also improves the re-usability and is easy to change with new requirements.
- **Testing code is easy**: Encapsulated code is easy to test for unit testing.
- **Freedom to the programmer in implementing the details of the system**: This is one of the major advantages of encapsulation that it gives the programmer freedom in implementing the details of a system.

### **Disadvantages of Encapsulation in Java**

- Can lead to increased complexity, especially if not used properly.
- Can make it more difficult to understand how the system works.
- May limit the flexibility of the implementation.

```java
class Person {
	private String name; // restricted access
	public String getName() {
		return name;
	}
	public void setName(String newName){
		this.name = newName;
	}
}

class Main {
	public static void main(String[] args) {
		Person myObj = new Person();
		myObj.name = "John"; // err
		System.out.println(myObj.name); // err
	}
}
```

## Composition

The Composition is a way to design or implement the "has-a" relationship.

- Composition and Inheritance both are design techniques.
- The Inheritance is used to implement the "is-a" relationship. The "has-a" relationship is used to ensure the code reusability in our program.
- In Composition, we use an instance variable that refers to another object.

![[Pasted image 20260227092832.png]]

- The Composition represents a part-of relationship.
- Both entities are related to each other in the Composition.
- The Composition between two entities is done when an object contains a composed object, and the composed object cannot exist without another entity.

> For example, if a university HAS-A college-lists, then a university is a whole, and college-lists are parts of that university.

- Favor Composition over Inheritance.
- If a university is deleted, then all corresponding colleges for that university should be deleted.

### **Benefits of using Composition:**

- Composition allows us to reuse the code.
- In Java, we can use multiple Inheritance by using the composition concept.
- The Composition provides better test-ability of a class.
- Composition allows us to easily replace the composed class implementation with a better and improved version.
- Composition allows us to dynamically change our program's behavior by changing the member objects at run time.

```java

class Engine {
	void start() {
		System.out.println("Engine Started");
	}
}

class Car {
	private Engine engine = new Engine(); // engine is created inside car ->> strong ownership
	void drive() {
		engine.start();
		System.out.println("Car is moving");
	}
}

public class Main {
	public static void main (String [] args) {
			Car car = new Car();
			car.drive();
		}
}

/*
Engine started
Car is moving
*/
```

---

## Access Modifiers

> Why Access Modifiers are Important?

- Provide **security**
- Support **encapsulation**
- Control **data visibility**
- Improve **code maintainability**

1. `public`
2. `private`
3. `protected`
4. `default` (no keyword)

![[Pasted image 20260227121705.png]]

---

## Interfaces and Implementations

- Collection of abstract methods and constants that a class must implement.
- Says what a class supporting this interface can do. It does nont say how these will be implemented by the class supporting it, it says **what** and not **how**.
- Used to achieve 100% abstraction and multiple inheritance in Java.
- An interface in java specifies the method signatures, and has no default implementations, in Java 8+ interfaces can have methods with default implementation.

```java
interface InterfaceName {
	// abstract methods
	// constants	
}
```

```java
interface Bicycle {
	void changeCadence(int newVal);
	void changeGear(int newVal);
	void speedUp(int increment);
	void applyBreaks(int decrement);
}
```

```java
class AAABicycle implements Bicycle {
	int cadence = 0;
	int sped = 0;
	int gear = 1;
	
	// The compiler will now require that methods
	// changeCadence, changeGear, speedUp, and applyBrakes
	// all be implemented. Compilation will fail if those
	// methods are missing from this class.
	
	public void changeCadence(int newValue) {
		cadence = newValue;
	}
	public void changeGear(int newValue) {
		gear = newValue;
	}
	public void speedUp(int increment) {
		speed = speed + increment;
	}
	public void applyBreaks(int decrement) {
		speed = speed - decrement;
	}
	public void printStates() {
		System.out.println("cadence:" + cadence 
			+ "speed: " + speed
			+ "gear: " +  gear
		)
	}
}
```

### Interfaces are used to

1. Achieve abstraction
2. Supports the functionality of multiple inheritance
3. Used to achieve loose coupling

It is possible to have a number of implementations for the same interface.

![[Pasted image 20260227122728.png]]

## Constructor

- A constructor **initializes an object** when it is created.
- It has the **same name as its class** and is syntactically similar to a method.
- Constructors have **no explicit return type**.
- Use a constructor to give initial values to the instance variables defined by the class, or to perform any other **start-up** **procedures** required to create a fully formed object.
- All classes have constructors, whether you define one or not, because Java automatically provides a **default constructor** that initializes all member variables to zero or corresponding default value. However, once you define your own constructor, the default constructor is no longer added.
- **Each time a object is created using new operator, constructor is invoked to assign initial values to the data members** **of the class.**

```java
class Student {
	Student() {
		// init
	}
}
// next we create an obj of the above class
Student obj = new Student();
```

### Default

- A constructor that has no parameters. If we don’t define a constructor for a class, then compiler creates a default constructor.
- Default constructor provides default values to the objects like 0, false, null etc depending on the data type of the instance variables.

### Parameterized

-  A constructor with parameters.
- To initialize the fields of a object with given values
- There are no return value statements in a constructor but constructors return the current class instance.

```java
class Student {
	int id;
	String name;
	
	// param const
	
	Studnet(int id, String name) {
		this.id = id;
		this.name = name;
	}
	
	void display() {
		System.out.println(id + "" + name);
	}
}
```

### Copy Constructor

Used to create an exact copy of the existing object

```java
class Student {
	int id;
	String name;
	
	// copy constructor
	
	Student (Student s) {
		this.id = s.id;
		this.name = new String(s.name);
	}
}
```

---

### Examples

```java
class Rect {
	int a, int b;
	
	Rect() {
		System.out.println("This is a constructor");
	}
	void disp() {
		System.out.println("Display");
	}	
}
```

```java
public class Demo {
	public static void main (Strings[] args) {
	
	Rect r = new Rect();
	
	// r.rect(); cannot explicitly invoke constuctor
	r.disp();
	
	System.out.println(r.a);
	System.out.println(r.b);
	
	}
}
```

If the constructor is made private, you cannot create the instance of the class from outside the class.

By default the access modifier is "default"

```java
class A {
	private A() {} // private constructor	
	void msg() {
		System.out.println("Welcome to OOAD with Java");
	}
}

public class Sample {
	public static void main(String[] args) {
		A obj = new A(); // Compile time err
	}
}
```

## Destructor

## Garbage Collector

- Java Garbage Collection is the process to identify and remove the unused objects from the memory and free space.
- One of the best feature of java programming language is the **automatic garbage collection**, unlike other programming languages such as C where memory allocation and de-allocation is a manual process.
- **Garbage Collector** is the program running in the background that looks into all the objects in the memory and find out objects that are not referenced by any part of the program.
- All these unreferenced objects are deleted and space is reclaimed for allocation to other objects.

There are certain actions to be performed before an object is destroyed like:

- Closing all the database connections or files
- Releasing all the network resources
- Other Housekeeping tasks
- Recovering the heap space allocated during the lifetime of an object
- Release of release locks
- Java provides a mechanism called finalization to do this through `finalize( )` method.

```java
protected void finalize()
{
	// finalize code here
	// actions to perform before an object is destroyed
}

```

## Value Types and Reference Types

Argument is copied to the paramet when some data has to be passed method / functions.

### Formal Parameters

### Actual Parameters

### Pass by Value

![[Pasted image 20260227124826.png]]

 Any modifications to the formal parameter variable inside the called function or method affect only the separate storage location and will not be reflected in the actual parameter in the calling environment

### Pass by Reference

![[Pasted image 20260227124857.png]]

Changes made to formal parameter do get transmitted back to the caller through parameter passing. Any changes to the formal parameter are reflected in the actual parameter in the calling environment as formal parameter receives a reference (or pointer) to the actual data

![[Pasted image 20260227124943.png]]

## Overloading of Methods

A feature that allows a class to have more than one method having the same name, if their argument lists are different.

- Method overloading is also known: Compile Time polymorphism, Static polymorphism, Early Binding.
- **Three ways to overload :** The argument lists of the methods must differ in either of these:
	- Changing the number of parameters
	- Changing the data type of parameters
	- Changing the order of parameters of methods.
- Method overloading has no relation with return-type.

### Overloaded methods

- Have the same name
- Have different parameter lists
- Number of parameters
- Type of parameters
- Order of parameters

 Compiler decides which method to call based on: method signature: **`method name + parameter list (number, type, order)`**

### Benefits

1. Method overloading increases the readability of the program.
2. This provides flexibility to programmers so that they can call the same method for different types of data.
3. This makes the code look clean.
4. This reduces the execution time because the binding is done in compilation time itself.
5. Method overloading minimises the complexity of the code.
6. The code can be used again, which saves memory.

```java
class Calc {
	int add(int a, int b) {
		return a+b;	
	}
	int add(int a, int b, int c) {
		return a + b + c;
	}
	double add(double a, double b) {
		return a+b;
	}
	
	public static void mian (String[] args) {
		Calc calc = new Calc();
		
		System.out.println(calc.add(10,20));
		System.out.println(calc.add(10,20,30));
		System.out.println(calc.add(1.2, 2.3));
	}
}
```

## Method Types

### Instance

Instance method are methods which require an object of its class to be created before it can be called. To invoke a instance method, we have to create an Object of the class in which the method is defined.

By default, all methods are instance type

### Static

Static methods are the methods in Java that can be called without creating an object of class. They are referenced by the class name itself or reference to the Object of that class.

## Attribute Types

### Instance

Instance variables are attributes which require an object of its class to be created before it can be used. To access a instance variable, we have to create an object of the class in which the attribute is defined.

By default, all attributes are instance type.

### Static

Static attributes are the variables that can be accessed without creating an object of class.

They are referenced by the class name itself or reference to the object of that class.

```java
class Example1 {
	public static void main(String[] args) {
		Sample ob1 = new Sample();
		ob1.setName("Ramu");
		System.out.println(ob1.name);
	} 
}

class Sample {
	String name = "";
	public void 
}
```

> The **static** keyword can be used for

- Variable (also known as a class variable)
- Method (also known as a class method)
- Block
- Class

Class variables (or static fields)

- Variables that are **common** to all objects
- They are associated with the **class**, rather than with any object
- Every instance of the class shares a class **variable**, which is in one fixed location in memory
- Any object can change the **value** of a class variable, but class variables can also be manipulated without creating an instance of the class

```java
class Example2 {
	public static void main (String[] args) {
		Sample.setName("Abhiram")
	}
}
```