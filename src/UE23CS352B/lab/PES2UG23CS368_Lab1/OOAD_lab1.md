#  OOAD: Lab 1

> Submission Date: 2026-01-08
> Name: **Nathan Matthew Paul**
> SRN: **PES2UG23CS368**
> Section: 6F

---

# Part 1: Star UML

![[Pasted image 20260108150639.png]]

# Part 2: Java Source Code

![[Screenshot 2026-01-08 at 15.16.13.png]]

# Part 3: Java Output

![[Pasted image 20260108152139.png]]

![[Screenshot 2026-01-08 at 15.16.57.png]]

---

# Assignment: Use Case Diagrams (UML)

## Part A – Conceptual Understanding

### 1. Define a Use Case Diagram. What is its purpose?

A **Use Case Diagram** is a visual summary of how users interact with a system.

- **Purpose:** It defines the **scope** of a project. It helps the team understand what the system is supposed to do and ensures that both the developers and the clients are on the same page.

### 2. List and explain the main components

- **Actor:** External entities (people or other systems) that interact with yours.
- **Use Case:** The specific goals or functions (the "ovals").
- **System Boundary:** The box that separates the system’s internal functions from the external world.
- **Relationship:** The lines connecting actors to use cases or connecting use cases to each other.

### 3. Primary vs. Secondary Actors

- **Primary:** The main user who starts a task to get a result (e.g., a **Customer** buying a shirt).
- **Secondary:** An external helper that the system needs to complete the task (e.g., a **Bank** authorizing a payment).

### 4. `<<include>>` vs. `<<extend>>`

- **`<<include>>` (Mandatory):** Part of the main flow. You _must_ do it.
    - _Ex: "Withdraw Cash" **includes** "Identity Check."_
- **`<<extend>>` (Optional):** Only happens if certain conditions are met.
    - _Ex: "Calculate Total" is **extended** by "Apply Holiday Discount" (only if it's a holiday)._

### 5. What is generalization?

Generalization is a "parent-child" relationship. It’s used when you have a general action that can be done in several specific ways.

- _Example:_ "Pay Bill" is the parent. "Pay with Credit Card" and "Pay with PayPal" are the specialized children.

### 6. Why focus on "What" and not "How"?

Because Use Case Diagrams are for **requirements**, not coding. If you worry about "how" (like which database to use), you get distracted from the goal. The diagram should stay simple enough for a non-tech client to understand.

---

## Part B – Online Shopping System

### 7. Identify Actors and Use Cases

- **Actors:** 1. Guest User, 2. Registered Member, 3. Shipping Provider.
- Use Cases: 1. Search Products
    
    2. Add to Cart
    3. Proceed to Checkout
    4. Track Order
    5. Manage Inventory (Admin task)

---

## Part D – Use Case Relationships

### 8. Online Examination System (Relationships)

- **Include:** "Take Exam" **includes** "Login." (You can't take it without logging in).
- **Extend:** "Finish Exam" is **extended** by "Attach Supporting Document." (Only if the student has a reason to upload a file).

---

## Part E – Case Study: Course Registration

### 9. Identify Actors and Use Cases

- **Actors:** Student, Registrar, Faculty Member.
- **Use Cases:** Select Courses, Drop Course, View Schedule, Generate Transcript.

### 10. Justify include/extend relationships

- **Include:** "Select Course" **includes** "Check Prerequisites." _Justification:_ The system must ensure a student is eligible before they can join.
- **Extend:** "Select Course" is **extended** by "Add to Waitlist." _Justification:_ This only happens if the class is already full.

---

## Part F – Short Answer

### 11. Can one use case be associated with multiple actors?

**Yes.** For example, "View Grade" might be accessed by both the **Student** and their **Academic Advisor**.

### 12. Is the System Boundary mandatory?

**Technically no, but highly recommended.** In UML standards, you can leave it out, but without it, it's hard to tell what is "inside" the app and what is "outside." It’s best practice to always include it.

### 13. Three common mistakes

1. **Making a Flowchart:** Using arrows to show a sequence of steps.
2. **Internal Actors:** Listing the "Database" or "Server" as an actor.
3. **No Goals:** Creating use cases that are too small (e.g., "Click Button" is not a use case; "Submit Form" is).

---

## Part G – Application & Analysis

### 14. How does it help in requirements gathering?

It forces the team to identify every possible user and every possible goal. It uncovers "hidden" requirements like realizing you need a "Password Recovery" use case because you forgot you had a "Login" actor.

### 15. Relation between Use Case and Class Diagrams

- **Use Case Diagrams** show **behavior** (what the system does).
- **Class Diagrams** show **structure** (how the data is organized to do it).
- _The link:_ Usually, the nouns in your Use Case (like "Order" or "Customer") become the Classes in your Class Diagram.

---
