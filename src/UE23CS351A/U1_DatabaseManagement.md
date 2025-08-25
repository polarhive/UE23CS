# Database Management

> [!NOTE] Data
> Raw material, unorganized set of facts.

> [!NOTE] Information
> Data -> Processing -> Information
> To draw some concluctions and make decisions

## Database

> [!Important] Database
>
> A database is a collection of related data representing some aspect of the real world, also called the mini-world or the universe of discourse (UoD). It is a logically coherent collection, meaning it is not just a random assortment of data but is organized with inherent meaning and structure.

## Database Management System

A modern database system is a complex software system whose task is to manage a large, complex collection of data. A general-purpose software system that facilitates the processes of defining, constructing, manipulating and sharing databases among the various users and applications.

- Collection of interrelated data
- Set of programs to access the data
- An environment that is both convenient and efficient to use
- Manage highly valued data in an org.
- Accessed across the org, by many people concurrently

## Building a DB

### [[DDL]]

**Defining** involves specifying data types, structures and constraints of the data to be stored. This maintains integrity of the data.

**Constructing** involved storing the data on the storage medium controlled by the system, it organized in a way that allows for efficient retrieval and ensures its is securely stored and accessed.

### [[DML]]

**Manipulating** includes functions that query the database to retrieve specific data, or updating the db in the mini world. It ensures that changes here follow predefined conditions and maintain consistency.

### [[DCL]]

Sharing a database helps to access data simultaneously and maintain permissions

### [[TCL]]

Actual locks on the db.

---

## Use cases

- OLTP
- OLAP

---

## Views

A collection of interrelated data and a set of programs that allow users to access and modify this data.

### Data Models

Conceptual tools for describing the data, relationships, semantics and constraints.

### [[Data Abstraction]]

Hide the complexity of data through several layers

---

## File based processing system

- Need base usecase
- Keep all data in permanent files
- Written at the request of users in the organization
- Managed by the OS
- Not efficient
- Format inconsistency
- Atomicity problems
- Security problems

### Data redundancy & Inconsistency

### Difficulty in access

### Data isolation

### Integrity problems

### Atomicity problems

### Concurrency access problems

### Security

---

# Advantages of DB

- Supports multiple views
- Self describing nature (metadata)
- Insulation
- Data changes are effected in a controlled manner

# Abstraction

[[Data Abstraction]]

# Instances

[[Schema]]

# Components

![[Screenshot 2025-08-21 at 12.04.28.png]]
