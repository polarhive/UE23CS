# SE Lab 3: Component Modelling & Architectural Pattern

> Nathan Matthew Paul
> Section: F
> SRN: PES2UG23CS368
> Date: 2025-09-12

## Objective

> Evaluate different architectural styles, select the most appropriate one for a given scenario, and create a comprehensive UML Component Diagram showing modules, interfaces, and dependencies.

## My 5 Components

- **Order Manager Component** – Handles the coffee order process.
- **Payment Service Component** – Handles credit card payments.
- **Menu Service Component** – Stores coffee types and pricing information.
- **UI Controller Component** – Manages touchscreen interactions.
- **Receipt Printer Service Component** – Interfaces with the printer to print receipts.

## Overall Architecture

![[Pasted image 20250912100310.png]]

**Complete component diagram showing interactions between all services.**

- **Order Manager → Payment Service**: “Payment Request” (API call).
- **Order Manager → Menu Service**: “Menu Query” (Database query).
- **Order Manager → Receipt Printer Service**: “Print Order” (Hardware interface).
- **UI Controller → Order Manager**: “Order Input” (REST call).

---

## 1. Order Manager

![[Screenshot 2025-09-12 at 10.04.33.png]]

**Figure 2 – Order Manager component showing provided and required interfaces.**

---

## 2. Menu Service

![[Screenshot 2025-09-12 at 10.05.49.png]]

**Figure 3 – Menu Service component detailing data retrieval for coffee options and pricing.**

---

## 3. UI Controller

![[Pasted image 20250912100636.png]]

**Figure 4 – UI Controller component managing customer interactions and forwarding orders.**

---

## 4. Payments Service

![[Pasted image 20250912100610.png]]

**Figure 5 – Payment Service component responsible for processing card payments securely.**

---

## 5. Printing Service

![[Screenshot 2025-09-12 at 10.06.15.png]]

**Figure 6 – Receipt Printer Service component handling order receipt generation and printing.**

---

## **Architecture Selection:**

I chose **Microservices Architecture** for the Self-Service Coffee Kiosk System.

> [!Important]
> **Architectural Choice:**
>
> > The Microservices architecture was selected because it allows the system’s core functionalities, such as order management, payment processing, menu handling, and receipt printing, to be broken down into independently deployable services. This structure ensures modularity and maintainability.

**Two Reasons for Choosing This Architecture:**

1. The kiosk must support simultaneous customer orders without degrading performance. Microservices enable independent scaling of components like the Order Manager and Payment Service, allowing efficient handling of high customer volume.
2. Fault isolation is essential in this environment. If one service, such as the Payment Service, experiences downtime, the other services, like menu display or order tracking, can continue operating without interruption.

### **Security Advantage:**

Microservices allow sensitive operations, such as credit card payment processing, to be isolated from other parts of the system. This separation reduces the attack surface and ensures that only authorized components communicate with the Payment Service, enhancing data security.

### **Performance Benefit:**

With Microservices, each service can be scaled based on demand. For example, during peak hours, additional instances of the UI Controller or Order Manager can be deployed to maintain responsiveness, ensuring quick customer interactions and minimizing wait times.
