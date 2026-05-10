# OOAD — Previous Year Questions (Master Topicwise)
**PES University | UE18CS353 / UE19CS353 / UE20CS352 / UE23CS352B**

> Papers covered: Dec 2023, Jul 2023, May 2023, Jan–May 2024, Jun/Jul 2008, Jun–Jul 2009
> Papers with diagrams only (image-based, no text extractable): PYQP 4, 6, 8, 9

---

## TABLE OF CONTENTS
1. [OOP Core Concepts — 4 Pillars, Java Basics](#1-oop-core-concepts)
2. [Constructors, Garbage Collection & Object Class](#2-constructors-garbage-collection--object-class)
3. [Inheritance & Method Overriding](#3-inheritance--method-overriding)
4. [Method Overloading](#4-method-overloading)
5. [Abstract Class & Interface](#5-abstract-class--interface)
6. [Static & Instance Members / Java Output Tracing](#6-static--instance-members--java-output-tracing)
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
20. [Architectural Patterns (MVC, Layered, etc.)](#20-architectural-patterns)
21. [Creational Design Patterns](#21-creational-design-patterns)
22. [Structural Design Patterns](#22-structural-design-patterns)
23. [Behavioral Design Patterns](#23-behavioral-design-patterns)
24. [Anti-Patterns](#24-anti-patterns)
25. [SDLC Models & Requirements Engineering](#25-sdlc-models--requirements-engineering)
26. [Software Testing & Quality](#26-software-testing--quality)
27. [Software Maintenance, DevOps & Configuration Management](#27-software-maintenance-devops--configuration-management)
28. [OO Development — Historical / Broad Concepts](#28-oo-development--historical--broad-concepts)

---

## 1. OOP Core Concepts

> **Frequency: Very High** — appears in almost every paper

---

**Q1.** Elucidate the four main pillars — Abstraction, Encapsulation, Inheritance and Polymorphism — of Object Oriented Programming in two to three lines each.
`[8 M | May 2023 | UE19CS353]`

---

**Q2.** Briefly describe Abstraction, Inheritance and Polymorphism concepts of Object Oriented Programming.
`[6 M | Jan–May 2024 | UE19CS353]`

---

**Q3.** Write briefly, with appropriate examples, about the Analysis and Design phases in Object Oriented Approach for software development. Distinguish this approach from the Procedure-Oriented approach.
`[6 M | Jul 2023 | UE20CS352]`

---

**Q4.** How does object-oriented development differ from traditional software development approach? List the advantages of object-oriented development.
`[10 M | Jun/Jul 2008 | MCA51]`

---

**Q5.** Discuss object-orientation software development.
`[10 M | Jun/Jul 2008 | MCA51]`

---

**Q6.** What are the main advantages of object-oriented development? Explain.
`[8 M | Jun–Jul 2009 | CS72]`

---

**Q7.** With suitable examples explain the following:
i) Object and Identity.
ii) Static and dynamic binding of objects.
`[8 M | Jun–Jul 2009 | CS72]`

---

**Q8.** State the reason why the given code prints output as **false**. Also change the code such that the output in the main function is **true**.
```java
public class MainClass {
    public static void main(String[] args) {
        Classdemo objOne = new Classdemo(10, 20);
        Classdemo objTwo = new Classdemo(10, 20);
        System.out.println(objOne.equals(objTwo)); // prints false
    }
}
class Classdemo {
    int a; int b;
    Classdemo(int a, int b) { this.a = a; this.b = b; }
}
```
`[5 M | Dec 2023 | UE20CS352]`
*(Same question appeared in May 2023 | UE19CS353 — 6 M)*

---

**Q9.** For the following code snippet:
1. Output expected from Line 1 is `"SRN of the student is 10 and name is pranitha"`. Add the required functionalities to the class student to get the desired output.
2. Predict the output of Line 2.
```java
class student {
    int srn;
    String name;
    // add required functions
}
class Demo {
    public static void main(String args[]) {
        student s1 = new student(10, "pranitha");
        System.out.println(s1);         // Line 1
        student s2 = new student(11, "abhay");
        System.out.println(s1 == s2);   // Line 2
    }
}
```
`[6 M | May 2023 | UE19CS353]`

---

## 2. Constructors, Garbage Collection & Object Class

> **Frequency: Very High** — appears in nearly every UE19/UE20 paper

---

**Q10.** Which are the three types of constructors that can be defined in Java? Give examples for each.
`[6 M | Dec 2023 | UE19CS353]`
*(Repeated: Jul 2023 | UE19CS353 — 4 M; May 2023 | UE20CS352 — 6 M; Jan–May 2024 | UE19CS353 — 6 M)*

---

**Q11.** What is the need for constructors in Java? With an example Java program explain default and parameterized constructors.
`[6 M | Jan–May 2024 | UE19CS353]`

---

**Q12.** Briefly describe the need of garbage collector in Java.
`[4 M | Dec 2023 | UE19CS353]`
*(Repeated: Jul 2023 | UE19CS353 — 4 M; Jan–May 2024 | UE19CS353 — 4 M)*

---

**Q13.** Write the output of the following Java program:
```java
class A {
    void show() { System.out.println("show of class A"); }
}
class B extends A {
    void show() { System.out.println("show of class B"); }
    void disp() { System.out.println("show of class B disp"); }
}
class supertest1 {
    public static void main(String args[]) {
        A aobj = new A();
        B bobj = new B();
        A refa;
        refa = aobj;
        refa.show();
        refa = bobj;
        refa.show();
        if (refa instanceof B) {
            ((B) refa).disp();
        }
    }
}
```
`[4 M | Dec 2023 | UE19CS353]`

---

## 3. Inheritance & Method Overriding

> **Frequency: Very High**

---

**Q14.** What is inheritance? Explain different types of inheritance in Java with an example for each.
`[6 M | Dec 2023 | UE19CS353]`
*(Repeated: Jan–May 2024 | UE19CS353 — 4 M)*

---

**Q15.** Explain any two different types of inheritance in Java with an example for each.
`[4 M | Jan–May 2024 | UE19CS353]`

---

**Q16.** State any six differences between abstract class and interface.
`[6 M | Jul 2023 | UE19CS353]`

---

**Q17.** Briefly describe Abstraction, Inheritance and Polymorphism concepts of Object Oriented Programming.
`[6 M | Jan–May 2024 | UE19CS353]`

---

## 4. Method Overloading

> **Frequency: High**

---

**Q18.** State any four differences between Method Overloading and Method Overriding.
`[4 M | Dec 2023 | UE20CS352]`

---

**Q19.** i) Give an example for Method Overloading and Method Overriding.
ii) State the differences between method overloading and method overriding.
`[6 M | Jul 2023 | UE19CS353]`

---

**Q20.** Write short notes about the following. Use code examples as applicable.
1. Method Overloading (2 marks)
2. Static and Instance members in a class (3 marks)
3. Abstract class (3 marks)
`[8 M | Jul 2023 | UE20CS352]`

---

**Q21.** Using method overloading in Java, write a class `NextValue` with a method `getNextValue` that takes either an integer or float as input and:
- Returns next integer if parameter is integer
- Returns float value by adding 0.01 if parameter is float
Write the main method that calls the method with different parameters.
`[4 M | May 2023 | UE20CS352]`

---

## 5. Abstract Class & Interface

> **Frequency: High**

---

**Q22.** Elucidate the need for an abstract class and justify the same with an example.
`[6 M | Dec 2023 | UE20CS352]`

---

**Q23.** State any six differences between abstract class and interface.
`[6 M | Jul 2023 | UE19CS353]`

---

**Q24.** Write short notes about: Method overloading, Static and Instance members in a class, Abstract class.
`[8 M | Jul 2023 | UE20CS352]`

---

## 6. Static & Instance Members / Java Output Tracing

> **Frequency: Medium**

---

**Q25.** Give the output of the Java program given below:
```java
public class StaticDemo {
    static int a = 1, b;
    static void display(int x) {
        System.out.println("x=" + x);
        System.out.println("a=" + a);
        System.out.println("b=" + b);
    }
    static {
        System.out.println("Inside static block");
        b = a * 2;
    }
    public static void main(String[] args) {
        System.out.println("Inside main");
        display(5);
    }
}
```
`[5 M | Dec 2023 | UE20CS352]`

---

**Q26.** Write about the three access specifiers — private, protected and public — that can be used in Java. Using one example class, briefly write about the effect of using the access specifiers on member variables.
`[6 M | Jul 2023 | UE20CS352]`

---

**Q27.** Is the below statement valid in Java? Justify your answer.
```java
Object o = new ArrayList<String>();
```
`[2 M | May 2023 | UE20CS352]`

---

## 7. Generics & Collections

> **Frequency: Medium**

---

**Q28.** What are Generic classes in Java? Write an example program to demonstrate any one generic class in Java.
`[4 M | Dec 2023 | UE19CS353]`
*(Repeated: Jan–May 2024 | UE19CS353 — 6 M)*

---

## 8. Java Code Writing Questions

> **Frequency: High** — complex scenario-based coding

---

**Q29.** Write code to add the following functionality expected by the `MainClass`. The `Employee` object can be created in two ways. The `Manager` is an Employee. In addition, the Manager has an array/list of Employees who are his/her team members.
```java
class Employee {
    private String name;
    private String dept;
}
// Write code here
// Write code here
class MainClass {
    public static void main(String[] args) {
        Employee e1 = new Employee("Employee Name");
        Employee e2 = new Employee("Employee Name", "Employee Department");
        Manager m1 = new Manager("Manager Name", "Manager Department");
        m1.addTeamMember(e1);
        m1.addTeamMember(e2);
        m1.showDetails();
    }
}
```
`[6 M | Jul 2023 | UE20CS352]`

---

**Q30.** Write Java code for the given scenario:
1. The SHIELD assigns the Avengers to a Mission.
2. The Mission has a name, location, strength requirement and list of Avengers assigned.
3. An Avenger has name, weapon and strength level.
4. The `addAvenger` method in Mission takes a list of all Avengers, iterates through the list and assigns all those Avengers to the Mission who have a strength level greater than the Mission's strength requirement.
5. The `showMission` method should display Mission details and list of Avengers assigned using `System.out.println(avenger)` directly.

Expected Output:
```
Save the World New York 9
Iron Man Suit 9
Thor Hammer 10
```
`[8 M | May 2023 | UE20CS352]`

---

## 9. Use Case Diagrams

> **Frequency: Very High** — appears in every paper

---

**Q31.** Write a use case diagram for an **Online Shopping website**, considering any e-commerce application.
`[6 M | Jul 2023 | UE18CS353]`

---

**Q32.** Draw a use case diagram for an **e-commerce website**.
`[6 M | Dec 2023 | UE19CS353]`

---

**Q33.** Draw a use case diagram for a **Railway Reservation System**. In the system, a Passenger logs in and checks for trains available. The passenger can book a ticket and optionally choose a seat and make a card payment. The bank validates the payment. Passengers can also cancel their ticket. The system admin processes cancellations and updates trains.
`[6 M | Dec 2023 | UE20CS352]`

---

**Q34.** Draw a use case diagram for a **railway reservation system** which has all basic features similar to IRCTC portal.
`[6 M | Jul 2023 | UE19CS353]`

---

**Q35.** Identify the use cases and actors and their relationships for **Passport Automation System** and depict it with a Use Case diagram:
- Applicant logs in and submits details
- Verification by passport administrator, regional administrator, and police
- Applicant can optionally seek ECNR status
- Police and administrator verify; if criteria are met, passport is issued
`[8 M | Jul 2023 | UE20CS352]`

---

**Q36.** Draw a Use Case diagram for a **Movie Ticket Booking System**:
- Customer can login and check streaming/upcoming movies
- Customer can book a ticket, optionally choose a seat, and make a card payment
- Bank validates payment
- Customers can cancel; admin processes cancellation and updates movies
- Customers can provide reviews
`[8 M | May 2023 | UE19CS353]`

---

**Q37.** Draw a use case diagram for an **ATM machine**.
`[6 M | Jan–May 2024 | UE19CS353]`

---

**Q38.** Consider a **library management system**. Draw a use case diagram representing primary functionalities. Include at least three actors and five use cases. Briefly explain the significance of one of the relationships in the diagram.
`[5 M | May 2023 | UE18CS353]`

---

**Q39.** Identity the relationship (include/extend/generalization) between these pairs of use cases and depict using appropriate notation:
1. Create new order — Validate customer account
2. Update order — Validate customer account
3. Place order — Login
4. Login account — Change password
5. Choose folder — Upload document
6. Purchase item — Purchase phone — Purchase accessories
`[6 M | May 2023 | UE19CS353]`

---

**Q40.** What is a use case? With a neat diagram explain UML activity diagram.
`[10 M | Jun/Jul 2008 | MCA51]`

---

## 10. Class Diagrams — Relationships & Notation

> **Frequency: Very High**

---

**Q41.** Elucidate **qualified association** and **aggregation** relationship w.r.t class diagram with an example for each.
`[6 M | Dec 2023 | UE19CS353]`
*(Repeated: Dec 2023 | UE20CS352; Jul 2023 | UE19CS353; May 2023 | UE19CS353)*

---

**Q42.** Define the following w.r.t the class diagram:
a) Association b) Aggregation c) Composition d) Multiplicity e) Qualifier f) Generalization
`[6 M | Jul 2023 | UE18CS353]`

---

**Q43.** Explain in a line or two the following terms with respect to a class diagram:
Association, Aggregation, Composition, Qualified Association
`[4 M | Jan–May 2024 | UE19CS353]`

---

**Q44.** Differentiate between Aggregation and Composition relationships w.r.t class diagram.
`[4 M | Jul 2023 | UE19CS353]`

---

**Q45.** Explain the various types of relationships that can be depicted between classes in a class diagram, and provide an illustrative example to support your explanation.
`[5 M | May 2023 | UE18CS353]`

---

**Q46.** What is an association? How do you identify associations? Explain how to eliminate unnecessary associations.
`[8 M | Jun–Jul 2009 | CS72]`

---

**Q47.** Explain UML attribute presentation. Give a complete UML class diagram for the Via Net Bank system.
`[8 M | Jun–Jul 2009 | CS72]`

---

**Q48.** What are coupling and cohesion of objects or software components?
`[6 M | Jun–Jul 2009 | CS72]`

---

## 11. Class Diagrams — Case Study Modeling

> **Frequency: High** — complex multi-part questions worth many marks

---

**Q49.** Draw the Class Diagram to model a **Course and Enrolment Management System**. Identify classes, attributes, relationships and cardinality.
1. A Department manages multiple Sessions.
2. A Session has a Start date, End date, and Name.
3. A session can have multiple semesters running.
4. A student belongs to a semester and to a section. A section has minimum 60 students.
5. A semester has a set of courses offered in it.
6. A student enrols for 5 courses. For electives, minimum 20 students must enrol for it to be offered.
7. An enrolled student's attendance is recorded.
8. An enrolled student's ISA, ESA marks and Grade are recorded.
9. A teacher is assigned to a section for a course.
10. A teacher can also be assigned as class teacher for a section.
`[6–8 M | May 2023 | UE20CS352; Jan–May 2024 | UE18CS353]`

---

**Q50.** Identify at least 6 classes from the following case study: Design software to support a **computerized banking network** including both human cashiers and ATMs shared by a consortium of banks. Each bank maintains its own accounts. Cashier stations communicate with the bank's computer directly. ATMs communicate with a central computer that clears transactions. An ATM accepts a cash card, interacts with the user, carries out the transaction, dispenses cash, and prints receipts. The system must handle concurrent access to the same account correctly.
`[6 M | Dec 2023 | UE18CS353]`

---

**Q51.** For the given scenarios, choose appropriate diagram to model the scenario. Justify your choice and draw the chosen diagram.
i) Every student is assigned a Faculty Advisor. The Faculty Advisor is assigned a minimum of 25 students with no maximum limit. Deans and Chairpersons are not assigned any students as advisees.
ii) An Order consists of multiple Items. The Order total is computed by adding the product of Item Quantity and Item price for each Item.
`[6 M | Jul 2023 | UE19CS353; Jan–May 2024 | UE18CS353]`

---

**Q52.** In the given class model, the responsibility to compute the total marks a Test is being administered for should be assigned to which class? The assignment of method is based on which principle? Write Java code snippet for the same.
`[6 M | Jul 2023 | UE20CS352]`

---

## 12. Component Diagrams

> **Frequency: Medium-High**

---

**Q53.** Describe in a line or two the following elements of component diagram: Port, Dependency, Component, Interface.
`[4 M | Dec 2023 | UE19CS353]`
*(Repeated: Jul 2023 | UE19CS353 — 4 M; Jan–May 2024 | UE19CS353 — 4 M)*

---

**Q54.** Draw a **Component Diagram for ATM Components**.
`[8 M | Dec 2023 | UE18CS353]`

---

**Q55.** Write about the elements in a Component Diagram. Represent the same in an example diagram using the correct notations.
`[4 M | May 2023 | UE20CS352]`

---

## 13. Deployment Diagrams

> **Frequency: Medium**

---

**Q56.** What are the different elements in a Deployment Diagram? Write the notations for these in an example diagram.
`[6 M | Jul 2023 | UE20CS352]`

---

## 14. Activity Diagrams

> **Frequency: High**

---

**Q57.** Develop an activity diagram for **login of an application**. Identify at least 4 activities, specify all the transitions.
`[8 M | Jul 2023 | UE18CS353]`

---

**Q58.** Draw an activity diagram to login and logout for a web-based application.
`[6 M | Jan–May 2024 | UE19CS353]`

---

**Q59.** Draw an activity diagram to perform **withdrawal operation in an ATM machine**. Specify all the activities and events along with swimlanes.
`[6 M | Dec 2023 | UE19CS353]`

---

**Q60.** Draw an activity diagram for the given scenario of **purchasing a ticket**: Activity is started by a Commuter who buys a ticket. The ticket vending machine requests trip information (number and type of tickets, route, destination/zone). Based on the info, the machine calculates payment due and requests payment options (cash, credit/debit card). If payment by card is selected, another actor (Bank) participates by authorizing the payment.
`[6 M | Jul 2023 | UE19CS353]`

---

**Q61.** Consider a process for **order fulfilment in an e-commerce system**. Create an activity diagram that includes swimlanes and demonstrates fork and join constructs. Include at least three swimlanes. Briefly explain the significance of using swimlanes, fork, and join in this activity diagram.
`[5 M | May 2023 | UE18CS353]`

---

**Q62.** Describe in a line or two the following elements of activity diagram with their UML notation:
i) Activity ii) Object Flow
`[4 M | Dec 2023 | UE20CS352]`

---

**Q63.** What are the different types of modeling? With a neat diagram explain UML activity diagram.
`[10 M | Jun/Jul 2008 | MCA51]`

---

**Q64.** With an example of **library member activities**, explain how an activity diagram aids in developing a use-case.
`[10 M | Jun–Jul 2009 | CS72]`

---

## 15. Sequence Diagrams

> **Frequency: Medium-High**

---

**Q65.** Draw a sequence diagram for a **phone calling application**.
`[6 M | Dec 2023 | UE18CS353]`

---

**Q66.** Write the UML sequence and collaboration diagrams for the **telephone call**.
`[8 M | Jun–Jul 2009 | CS72]`

---

**Q67.** For Via Net ATM bank system, develop sequence and collaboration diagrams for **deposit/checking use-case**.
`[6 M | Jun–Jul 2009 | CS72]`

---

## 16. State Diagrams

> **Frequency: High**

---

**Q68.** Draw a state diagram for the **book object** based on the following scenario:
Librarians categorise library books into loanable and non-loanable (reference) books. After cataloguing, books are available for loan. Students borrow books and must return them before the due date. Books that are 12 months past the due date are considered lost. If found, they must be returned. When books are no longer required or have been damaged, they are disposed of.
`[8 M | May 2023 | UE19CS353]`

---

**Q69.** Draw a state diagram for the **Transmission component of a Car** w.r.t. the diagram given.
`[4 M | Dec 2023 | UE20CS352]`

---

**Q70.** Write an activity diagram for the **Dining Philosophers problem**: Five silent philosophers sit at a round table with bowls of noodles. A chopstick is placed between each pair of adjacent philosophers. Each philosopher alternately thinks and eats. A philosopher can only eat when they have both left and right chopsticks. Each chopstick can be held by only one philosopher.
`[6 M | May 2023 | UE19CS353]`

---

**Q71.** Write short notes about the following features of a State diagram with appropriate notations and an example:
i) Order of activities associated with a state transition
ii) Synchronization and Splitting associated with concurrent states
`[4 M | May 2023 | UE20CS352]`

---

**Q72.** With respect to state diagram, describe the following terms in a line or two and give an example for each: State, Event, Guard condition.
`[6 M | Jan–May 2024 | UE19CS353]`

---

**Q73.** Differentiate between guard condition and change event in state modeling.
`[2 M | Dec 2023 | UE19CS353]`

---

**Q74.** Draw the UML state chart diagram to show different states and events responsible for the change of states of a process cooperating systems.
`[6 M | Jun–Jul 2009 | CS72]`

---

## 17. Class Identification

> **Frequency: Medium**

---

**Q75.** What are the different approaches for identifying classes? Explain each briefly.
`[10 M | Jun/Jul 2008 | MCA51]`

---

**Q76.** What is object classification? What are the different approaches for identifying classes? Explain each briefly.
`[5 M | Jun–Jul 2009 | CS72]`

---

**Q77.** How are classes identified using the common class patterns approach? Explain.
`[6 M | Jun–Jul 2009 | CS72]`

---

**Q78.** List and explain Coad and Yourdon clues for finding candidate classes and objects.
`[4 M | Jun–Jul 2009 | CS72]`

---

**Q79.** How can associations, attributes and methods be identified? Give the guidelines.
`[10 M | Jun–Jul 2009 | CS72]`

---

## 18. GRASP Design Principles

> **Frequency: Very High** — appears in every UE19/UE20 paper

---

**Q80.** Explain in a line or two the following GRASP principles with an example:
i) Creator ii) Low Coupling iii) Controller iv) Polymorphism
`[8 M | Dec 2023 | UE19CS353]`
*(Repeated: Jan–May 2024 | UE19CS353 — 8 M)*

---

**Q81.** Explain the **Creator** and **Controller** GRASP principles with an example along with the corresponding class diagram.
`[8 M | Dec 2023 | UE20CS352; Jul 2023 | UE19CS353]`

---

**Q82.** How does the **Creator** pattern in GRASP help in assigning responsibilities?
`[5 M | May 2023 | UE18CS353]`

---

**Q83.** With an appropriate example, explain **Controller** and **High Cohesion** principles in GRASP.
`[6 M | May 2023 | UE19CS353]`

---

**Q84.** Match the following Design Principle names with their definition:
1. Information Expert → a. Combine related responsibilities into one manageable unit
2. High Cohesion → b. Provide a well-defined interface so there's no effect on other units
3. Indirection → c. Assign responsibility to the class which has the required data
4. Protected Variation → d. Introduce an intermediate unit to communicate between other units
`[4 M | Dec 2023 | UE19CS353; May 2023 | UE19CS353]`

---

**Q85.** Describe briefly the **Pure Fabrication** GRASP Design Principle, with an example.
`[6 M | Jul 2023 | UE20CS352]`

---

**Q86.** In the given class model, what is wrong in terms of GRASP design principles? Show how this can be improved with a structural diagram.
`[6 M | May 2023 | UE20CS352]`

---

**Q87.** What are coupling and cohesion of objects or software components?
`[6 M | Jun–Jul 2009 | CS72]`

---

## 19. SOLID Design Principles

> **Frequency: Very High**

---

**Q88.** Explain SOLID design principles. Give an example for any 2 principles.
`[8 M | Jul 2023 | UE18CS353]`

---

**Q89.** Describe any four SOLID design principles with an example for each.
`[8 M | Jan–May 2024 | UE19CS353]`

---

**Q90.** What SOLID design principle is violated in the given design? How can this be modified to make it a better design? Draw class diagram and code snippet of your design.
`[8 M | Dec 2023 | UE19CS353]`

---

**Q91.** Describe briefly the following:
1. Liskov Substitution Principle (LSP)
2. Interface Segregation Principle
3. Open-Closed Principle
`[6 M | Jul 2023 | UE19CS353]`

---

**Q92.** Describe the **Liskov Substitution Principle (LSP)** and its implications for object-oriented design.
`[5 M | May 2023 | UE18CS353]`

---

**Q93.** Explain the Liskov Substitution Principle using an example where LSP is violated and how it can be corrected.
`[4 M | May 2023 | UE20CS352]`

---

**Q94.** State the **Interface Segregation Principle**. Explain the problem and solution with an appropriate example.
`[8 M | Jul 2023 | UE20CS352]`

---

**Q95.** Identify the three SOLID principles violated by this design. Suggest correction so that the violated principles are adhered to.
`[6 M | May 2023 | UE20CS352]`

---

**Q96.** A software designer for a pizza store has proposed a design (shown below). Identify the issues in the proposed design and suggest an appropriate class diagram to address the issues.
`[7 M | May 2023 | UE19CS353]`

---

**Q97.** Class design given below has functionalities of vehicles. A new two-wheeler class is needed. If the new two-wheeler class implements interface `IVehicle`, which design principle is violated? Modify the design in the given class diagram to accommodate the new class.
`[8 M | Jan–May 2024 | UE18CS353]`

---

**Q98.** Fill in the blanks:
i. Violating Dependency Inversion Principle will result in a code with ________ coupling.
ii. Liskov Substitution Principle states that the designer/implementer should be able to replace objects of _________ with the objects of _________.
iii. _________ Principle states that the design should be extensible however modifying existing design should be avoided.
iv. The pattern that hides the complexity related to creation of objects from the client is _________.
v. A _________ is a best practice, a recipe, a time-tested solution to a recurring problem.
`[4–6 M | Dec 2023 | UE20CS352; May 2023 | UE19CS353]`

---

## 20. Architectural Patterns

> **Frequency: High**

---

**Q99.** Define **MVC architectural pattern**. Explain the working of MVC with a neat diagram.
`[6 M | Dec 2023 | UE20CS352]`

---

**Q100.** With a neat flow diagram, explain the working of **MVC architecture pattern**.
`[4 M | May 2023 | UE20CS352]`

---

**Q101.** Contrast **Architectural Views, Styles, and Patterns**. Give an example for each.
`[6 M | Jul 2023 | UE18CS353]`

---

**Q102.** State the difference between Architectural and Design patterns.
`[6 M | Dec 2023 | UE20CS352]`

---

**Q103.** Elaborate on any one architectural design pattern with an illustrative example.
`[5 M | May 2023 | UE18CS353]`

---

**Q104.** Describe briefly (1–2 lines) any six approaches that can be taken to decompose a large system into subsystems or components.
`[6 M | Jan–May 2024 | UE18CS353]`

---

**Q105.** Explain with a neat diagram three-tier architecture.
`[10 M | Jun/Jul 2008 | MCA51]`

---

## 21. Creational Design Patterns

> **Frequency: Very High**

---

### Singleton

**Q106.** With an example show how a class can be made a **Singleton** and what are the benefits of making a class a Singleton.
`[4–5 M | Jul 2023 | UE19CS353; May 2023 | UE19CS353]`

---

**Q107.** Describe the **Singleton creational pattern** with a suitable code snippet.
`[6 M | Dec 2023 | UE19CS353]`

---

**Q108.** What is a singleton class? How to make a class singleton?
`[6 M | Jan–May 2024 | UE19CS353]`

---

### Factory Method

**Q109.** Describe the **Factory Method creational pattern** with a suitable example design and corresponding code snippet.
`[6 M | May 2023 | UE20CS352]`

---

**Q110.** Specify when to use a **Builder pattern**. State the difference between Factory and Abstract Factory pattern.
`[4 M | Jul 2023 | UE19CS353]`

---

### General — Design Patterns Overview

**Q111.** What are Design Patterns? Which are the different types of design patterns, describe in a line or two? Specify pros and cons of design patterns.
`[6 M | Dec 2023 | UE19CS353; Jan–May 2024 | UE19CS353]`

---

**Q112.** What is a Design Pattern? Describe in a line or two the essential elements of a design pattern.
`[6 M | Jul 2023 | UE19CS353]`

---

**Q113.** Define patterns and frameworks. List major differences between patterns and frameworks.
`[6 M | Jun–Jul 2009 | CS72]`

---

**Q114.** Fill in the blanks:
i) _________ pattern refers to creating duplicate objects while keeping performance in mind.
ii) _________ pattern provides the interface according to client requirement while using the services of a class with a different interface.
`[2 M | May 2023 | UE20CS352]`

---

## 22. Structural Design Patterns

> **Frequency: Very High**

---

### Adapter Pattern

**Q115.** Give the UML diagram of the **Adapter pattern** and briefly describe each component.
`[7–8 M | Dec 2023 | UE19CS353; Jan–May 2024 | UE19CS353]`

---

**Q116.** A system has a `MediaPlayer` interface and a concrete class `AudioPlayer` implementing it. AudioPlayer can play mp3 by default. There is another interface `AdvancedMediaPlayer` with concrete classes that can play vlc and mp4. We want to make AudioPlayer play other formats as well.
Identify which design pattern is required and justify. Draw an appropriate class diagram for the scenario.
`[6 M | Jul 2023 | UE19CS353; May 2023 | UE19CS353]`

---

**Q117.** Write briefly about the **Adapter Structural Design Pattern**. Clearly state the intent, problem, solution structure and example.
`[6 M | Jul 2023 | UE20CS352]`

---

### Proxy Pattern

**Q118.** What is a **Proxy pattern**? Which are the three main variations of proxy pattern?
`[6 M | Jul 2023 | UE19CS353]`

---

**Q119.** Implement the following use case using a **Proxy pattern**. Write both the class diagram and the code snippet. State which type of proxy pattern is suitable.

**Use Case (Library):** If an entire library of books is loaded from a database, it will consume a lot of RAM. The solution displays only the name, author, and availability of books when a list is displayed. When a book is selected, all remaining details are fetched from the database and operations like issue/return can be performed.
`[6 M | Dec 2023 | UE20CS352; Jul 2023 | UE20CS352]`

---

**Q120.** Implement the following use case using a **Proxy pattern**. Write both the class diagram and the code snippet.

**Use Case (Students):** A department has thousands of students. At any given time, only one student's grades are needed. The solution displays only Name, SRN, and Dept when a list is shown. When a student is selected, their grades are fetched from the database.
`[6 M | Jul 2023 | UE20CS352]`

---

**Q121.** Implement the following use case using a **Proxy pattern**.

**Use Case (Music Library):** An entire library of songs loaded from a database would consume a lot of RAM. The solution displays only title, artist, and duration. When a song is selected, the media stream is fetched from the database and play can be performed.
`[6 M | May 2023 | UE20CS352]`

---

### Facade Pattern

**Q122.** Which design pattern is depicted in the given diagram below? Describe the identified pattern in a line or two. Give the pseudo code to implement the same. *(Question references a Facade/HomeManager class diagram)*
`[8 M | Dec 2023 | UE19CS353; May 2023 | UE20CS352]`

---

**Q123.** Identify the structural pattern used in the design diagram below. Justify. Write code to implement the HomeManager class constructor and methods.
`[6 M | May 2023 | UE20CS352]`

---

**Q124.** For a case study depicted in the diagram shown below, identify the appropriate structural design pattern. Write the class structure of the identified pattern. *(References a complex subsystem scenario)*
`[6 M | May 2023 | UE19CS353]`

---

### General Structural

**Q125.** When to use Behavioral patterns? Describe in a line or two Interpreter and Iterator pattern.
`[4 M | Dec 2023 | UE20CS352]`

---

## 23. Behavioral Design Patterns

> **Frequency: Very High**

---

### Chain of Responsibility

**Q126.** Explain the **Chain of Responsibility** behavioral pattern. State the intent, structure and benefits of this pattern.
`[6 M | Jul 2023 | UE20CS352]`

---

**Q127.** Describe the **Chain of Responsibilities pattern** with an example.
`[4 M | May 2023 | UE19CS353]`

---

**Q128.** Briefly describe the intent, structure and participants of the **Chain of Responsibility** design pattern.
`[7 M | Jan–May 2024 | UE19CS353]`

---

**Q129.** For the given scenario, identify which behavioral pattern can be used. Briefly describe the chosen pattern and draw the class diagram for the scenario with the chosen pattern.

**Scenario:** An enterprise has been getting more email than they can handle. The enterprise gets 4 types of email: Fan mail, Complaints, Requests for new features, and Spam. The enterprise has written AI detectors that can tell the type. You need to create a design that can use the detectors to handle incoming email.
`[10 M | Dec 2023 | UE20CS352; Dec 2023 | UE18CS353]`

---

### Command Pattern

**Q130.** Which design pattern is depicted in the given diagram below? Describe the identified pattern in a line or two. Give the pseudo code to implement the same. *(References stock buy/sell command pattern diagram)*
`[8 M | Dec 2023 | UE19CS353]`

---

### Iterator Pattern

**Q131.** Describe the structure of the solution for the **Iterator pattern**.
`[4 M | May 2023 | UE20CS352]`

---

**Q132.** Implement the following use case using a **Chain of Responsibility pattern**. Write both the class diagram and the code snippet for building the chain.

**Use Case (Logging System):** A logging system writes INFO messages to console, ERROR messages to an error log file, and DEBUG messages to a debug log file. The client invokes the console logger irrespective of the type. The console logger checks the type: if INFO, writes to console; else, invokes the error logger. The error logger does the same, invoking the debug logger if not ERROR. The debug logger is the last in the chain.
`[6 M | May 2023 | UE20CS352]`

---

## 24. Anti-Patterns

> **Frequency: High** — at least one question in every paper

---

**Q133.** What is an **Anti-pattern**? Briefly describe the **Vendor Lock-in** anti-pattern.
`[5–6 M | Dec 2023 | UE19CS353; Dec 2023 | UE20CS352]`

---

**Q134.** What is the refactored solution to tackle the **Vendor Lock-in** Anti-pattern?
`[6 M | Jul 2023 | UE20CS352]`

---

**Q135.** State the solution for **Blob, Lava Flow, Vendor Lock-in, and Analysis Paralysis** anti-patterns.
`[4 M | Jul 2023 | UE19CS353]`

---

**Q136.** What is an anti-pattern? State the solution for **Blob** and **Vendor Lock-in** anti-pattern.
`[4 M | May 2023 | UE19CS353]`

---

**Q137.** Mention **symptoms and typical causes** for the **Blob** design anti-pattern.
`[8 M | Jul 2023 | UE20CS352]`

---

**Q138.** Explain with an example the steps for the **refactored solution for the Blob Anti-pattern**.
`[6 M | May 2023 | UE20CS352]`

---

**Q139.** Mention any two symptoms and any two typical causes for the **Analysis Paralysis** design anti-pattern.
`[4 M | May 2023 | UE20CS352]`

---

**Q140.** Differentiate between pattern and anti-pattern.
`[4 M | Jul 2023 | UE19CS353]`

---

**Q141.** What is an Anti-pattern? Briefly describe the **Lava-Flow** anti-pattern.
`[5 M | Jan–May 2024 | UE19CS353]`

---

**Q142.** What are the significances of Anti-patterns and Generative patterns?
`[6 M | Jun–Jul 2009 | CS72]`

---

## 25. SDLC Models & Requirements Engineering

> **Frequency: High** — mainly in UE18CS353

---

**Q143.** With a diagram, explain the **Software Development Life Cycle (SDLC)**.
`[8 M | Dec 2023 | UE18CS353]`

---

**Q144.** Discuss different phases in the development of software.
`[5 M | May 2023 | UE18CS353]`

---

**Q145.** List 8 activities that are performed during the **feasibility study** of the requirement analysis.
`[8 M | Dec 2023 | UE18CS353]`

---

**Q146.** Explain the advantages of the **waterfall model**.
`[4 M | Dec 2023 | UE18CS353]`

---

**Q147.** Illustrate the advantages and disadvantages of the **Agile SCRUM** model with an example.
`[5 M | May 2023 | UE18CS353]`

---

**Q148.** Differentiate the **Incremental model** and **Evolutionary Model**.
`[5 M | May 2023 | UE18CS353]`

---

**Q149.** Discuss the **V Model** of Software Development Lifecycle — phases, focus, deliverables, how it is similar to and different from the waterfall model.
`[8 M | Jul 2023 | UE18CS353]`

---

**Q150.** Using a skeletal system block diagram, compare and contrast **Iterative** and **Incremental** Development Models.
`[6 M | Jan–May 2024 | UE18CS353]`

---

**Q151.** Briefly explain about the **Requirements Engineering Process** with a neat diagram.
`[6 M | Jul 2023 | UE18CS353]`

---

**Q152.** What is the problem with the following requirement statement? What quality attributes does it not possess? How can it be improved?
`"SR-4: All pages of the application will load in acceptable amount of time."`
`[6 M | Jan–May 2024 | UE18CS353]`

---

**Q153.** Describe what is a **risk** and the steps (with 1 line description) involved in managing risks.
`[8 M | Jan–May 2024 | UE18CS353]`

---

**Q154.** Describe the role of **version control** in a Configuration Management System.
`[4 M | May 2023 | UE18CS353]`

---

**Q155.** Define the following w.r.t Quality of an Agile Scrum project: Sprint Burndown, Team Velocity Metric, Throughput, Cycle Time.
`[4 M | Jul 2023 | UE18CS353]`

---

**Q156.** Explain with a neat figure the different **quality measures** of high quality software.
`[5 M | Jun/Jul 2008 | MCA51]`

---

**Q157.** Describe the **prototyping** software development process.
`[5 M | Jun/Jul 2008 | MCA51]`

---

**Q158.** What is the purpose and need of analysis? Why is analysis a difficult task? Explain.
`[6 M | Jun/Jul 2008 | MCA51]`

---

**Q159.** Explain with the help of an example, the **Rumbaugh et al.'s Object Modeling Technique (OMT)**.
`[10 M | Jun/Jul 2008 | MCA51; Jun–Jul 2009 | CS72]`

---

**Q160.** What is a model? Explain the necessity of modeling and discuss its advantages.
`[6 M | Jun/Jul 2008 | MCA51]`

---

**Q161.** What is UML? What are its advantages?
`[4 M | Jun/Jul 2008 | MCA51]`

---

**Q162.** Describe in detail with a neat figure the **unified approach** to software development.
`[10 M | Jun/Jul 2008 | MCA51]`

---

**Q163.** What is the specific aim of OOSE? What is an objectory? What are the different models with which the objectory is built?
`[6 M | Jun–Jul 2009 | CS72]`

---

**Q164.** Explain object-oriented design axioms and define the corollaries that can be derived from these axioms.
`[10 M | Jun/Jul 2008 | MCA51]`

---

## 26. Software Testing & Quality

> **Frequency: High** — mainly in UE18CS353

---

**Q165.** With a diagram, explain the **levels of testing**.
`[8 M | Dec 2023 | UE18CS353]`

---

**Q166.** Briefly discuss about different levels of testing.
`[8 M | Jul 2023 | UE18CS353]`

---

**Q167.** Write a note on **Black box & White box testing**.
`[4 M | Dec 2023 | UE18CS353]`

---

**Q168.** Differentiate between **Static Testing and Dynamic Testing**.
`[6 M | Jul 2023 | UE18CS353]`

---

**Q169.** Contrast between **Manual and Automation testing**.
`[6 M | Jul 2023 | UE18CS353]`

---

**Q170.** With a diagram, explain the **process of test execution**.
`[6 M | Dec 2023 | UE18CS353]`

---

**Q171.** Differentiate between **VERIFICATION & VALIDATION**.
`[6 M | Dec 2023 | UE18CS353]`

---

**Q172.** Compare and contrast verification and validation in software testing. Provide examples to illustrate each concept.
`[5 M | May 2023 | UE18CS353]`

---

**Q173.** Describe **statement coverage** and **decision coverage** as coverage-based test techniques. Discuss the differences and their importance in ensuring comprehensive test coverage.
`[5 M | May 2023 | UE18CS353]`

---

**Q174.** Explain the principles behind **mutation testing** and **fault injection**. Discuss their advantages and limitations as fault-based test techniques.
`[5 M | May 2023 | UE18CS353]`

---

**Q175.** Describe the **V-model** of the software life cycle and discuss how testing activities are integrated into each stage.
`[5 M | May 2023 | UE18CS353]`

---

**Q176.** Choose the most appropriate types of testing applicable in the following applications:
1. Online shopping website with special sale days (like Amazon Prime Days)
2. File management system with collaborative editing (like Google Drive)
3. Anti-Virus software requiring frequent updates
`[6 M | Jan–May 2024 | UE18CS353]`

---

**Q177.** What are the 3 perspectives for looking at test-related measures? Give one example for each.
`[6 M | Jan–May 2024 | UE18CS353]`

---

**Q178.** What is SEI CMM? Name two reasons why you would want to use it? Enumerate its five levels.
`[8 M | Jan–May 2024 | UE18CS353]`

---

**Q179.** Explain briefly about **code review** and **code inspection**.
`[8 M | Dec 2023 | UE18CS353]`

---

**Q180.** Differentiate between **Coding standards and guidelines** for an organization with at least 2 examples for each.
`[6 M | Jan–May 2024 | UE18CS353]`

---

**Q181.** What is **secure programming**? List the secure programming approaches or practices to overcome software vulnerabilities.
`[6 M | Jan–May 2024 | UE18CS353]`

---

## 27. Software Maintenance, DevOps & Configuration Management

> **Frequency: High** — mainly in UE18CS353

---

**Q182.** Explain the **key issues in software maintenance**.
`[8 M | Dec 2023 | UE18CS353]`

---

**Q183.** Define the following: Preventive Maintenance, Perfective Maintenance, Corrective Maintenance, Adaptive Maintenance.
`[4 M | Jul 2023 | UE18CS353]`

---

**Q184.** Explain briefly about the **4 pillars of DevOps**.
`[8 M | Dec 2023 | UE18CS353]`

---

**Q185.** Enlist the pillars of DevOps and specify a few factors about each pillar.
`[8 M | Jul 2023 | UE18CS353]`

---

**Q186.** Describe the term DevOps. Write briefly about the **DevOps pipeline**.
`[8 M | Jan–May 2024 | UE18CS353]`

---

**Q187.** Explain how **continuous build, integration, and delivery** contribute to shorter development cycles and faster time-to-market. Discuss the role of tools like Jenkins.
`[5 M | May 2023 | UE18CS353]`

---

**Q188.** Discuss the importance of **automated build, testing, and deployment** in the DevOps workflow.
`[5 M | May 2023 | UE18CS353]`

---

**Q189.** Discuss the concept of **affinity** in DevOps and how it fosters cross-functional cooperation.
`[5 M | May 2023 | UE18CS353]`

---

**Q190.** Explain **Software Configuration Management** and its benefits.
`[6 M | Dec 2023 | UE18CS353]`

---

**Q191.** Enlist the benefits of using a **Software Configuration System**.
`[4 M | Jul 2023 | UE18CS353]`

---

**Q192.** Briefly discuss about **ITSM and ITIL**.
`[6 M | Jul 2023 | UE18CS353]`

---

**Q193.** Describe the **ITIL service lifecycle** and its five stages. Discuss the purpose and activities involved in each stage.
`[5 M | May 2023 | UE18CS353]`

---

**Q194.** List any six objectives of **IT Systems Management (ITSM)**.
`[6 M | Jan–May 2024 | UE18CS353]`

---

**Q195.** Name any three challenges of **geographical distance** with respect to Software Development. How can they be overcome?
`[6 M | Jan–May 2024 | UE18CS353]`

---

**Q196.** Discuss Hacking and Software Engineering, and Availability Management.
`[6 M | Jul 2023 | UE18CS353]`

---

## 28. OO Development — Historical / Broad Concepts

> **Frequency: Medium** — mainly in older papers (2008, 2009)

---

**Q197.** What is the importance of prototyping? What are the commonly accepted prototyping approaches? What are their strengths?
`[6 M | Jun–Jul 2009 | CS72]`

---

**Q198.** What are the advantages of modeling? What elements must a modeling language include?
`[6 M | Jun–Jul 2009 | CS72]`

---

**Q199.** Write short notes on: i) Model constraints and comments ii) Stereotype iii) UML meta-model.
`[10 M | Jun/Jul 2008 | MCA51]`

---

**Q200.** Explain clearly the concept of **object-relational mapping**.
`[10 M | Jun/Jul 2008 | MCA51]`

---

**Q201.** What are the guidelines for developing effective documentation? Explain.
`[5 M | Jun–Jul 2009 | CS72]`

---

**Q202.** What is OODBMS? Explain. Discuss the differences between OODBMS and traditional databases.
`[8 M | Jun–Jul 2009 | CS72]`

---

**Q203.** Discuss the four major activities of **designing view layer classes**.
`[8 M | Jun–Jul 2009 | CS72]`

---

**Q204.** What are the guidelines for designing application windows? Discuss.
`[4 M | Jun–Jul 2009 | CS72]`

---

**Q205.** How will a software development project be planned using SE Management?
`[5 M | May 2023 | UE18CS353]`

---

## Quick Reference — Topic Frequency

| Topic | No. of Questions | Frequency |
|---|---|---|
| Use Case Diagrams | 10 | ⭐⭐⭐⭐⭐ |
| SOLID Principles | 11 | ⭐⭐⭐⭐⭐ |
| GRASP Principles | 8 | ⭐⭐⭐⭐⭐ |
| OOP Core Concepts / 4 Pillars | 9 | ⭐⭐⭐⭐⭐ |
| Class Diagrams (relationships) | 8 | ⭐⭐⭐⭐⭐ |
| Constructors & Garbage Collection | 6 | ⭐⭐⭐⭐⭐ |
| Structural Design Patterns (Adapter, Proxy, Facade) | 11 | ⭐⭐⭐⭐⭐ |
| Behavioral Design Patterns (CoR, Command, Iterator) | 7 | ⭐⭐⭐⭐⭐ |
| Anti-Patterns | 10 | ⭐⭐⭐⭐⭐ |
| Creational Design Patterns (Singleton, Factory) | 7 | ⭐⭐⭐⭐ |
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
| DevOps & Configuration Mgmt | 13 | ⭐⭐⭐ (UE18 only) |
| Static/Instance Members | 3 | ⭐⭐ |
| Generics & Collections | 2 | ⭐⭐ |
| Java Code Writing | 2 | ⭐⭐ |
| Deployment Diagrams | 1 | ⭐ |
| Class Identification | 5 | ⭐⭐ |

