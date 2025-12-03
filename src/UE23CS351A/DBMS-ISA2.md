# Unit 3 - Query Processing and Normalization

## Query Processing and Optimization

### Introduction to strategies of Query processing

Query processing encompasses the techniques used by a Database Management System (DBMS) to execute high-level queries.

1. **Translation**: Query processing begins with the translation of high-level queries, such as those written in SQL, into **low-level expressions** or algebraic operators.
2. **Query Blocks**: Queries are typically decomposed into **query blocks**, which serve as the basic unit for translation into algebraic operators. A query block usually contains a single `SELECT-FROM-WHERE` expression, though it may also contain `GROUP BY` and `HAVING` clauses.
3. **Intermediate Operations**: Operations like the **semi-join** and **anti-join** are introduced when translating nested queries to avoid the performance penalties associated with regular inner joins.
4. **Execution**: The final low-level execution plan is run by the runtime database processor to produce the result efficiently.

### Query optimization

Query optimization is the essential process of selecting the most efficient means to execute an SQL query. The goal is to maximize performance, minimize execution time, reduce resource usage, and deliver faster results.

- **Execution Plan**: A single query can have multiple equivalent execution paths; the query optimizer's task is to choose the optimal plan, typically represented internally as a **query tree** (preferred over a query graph for defining the order of operations).
- **Heuristics for Efficiency**: Query transformation involves applying heuristics to improve efficiency:
    - **Pushing Down Selects**: Moving $\sigma$ (SELECT) operations down the query tree helps **reduce the size of intermediate results** earlier in the process.
    - **Combining Operations**: Replacing Cartesian Product ($\times$) operations combined with SELECT operations with explicit **JOIN** operations is crucial.
    - **Pushing Down Projects**: Moving $\pi$ (PROJECT) operations down the query tree helps eliminate columns that are not needed immediately, minimizing data transfer sizes.
- **Semantic Query Optimization**: This advanced technique optimizes a query by utilizing **semantic information** derived from the database schema and integrity constraints (like functional dependencies, primary keys, foreign keys, or unique constraints) to eliminate redundant operations or simplify the query structure.

## Functional Dependencies

### Functional Dependencies

A functional dependency (FD) is a fundamental constraint established between two sets of attributes within a database. FDs are crucial because they are used to define the formal measure of the "goodness" of relational database designs, particularly during the normalization process.

- A dependency is denoted as $X \rightarrow Y$, where $X$ is the **Determinant** and $Y$ is functionally dependent on $X$.

### Inference Rules

Inference rules, sometimes known as Armstrong's Axioms, allow the derivation of implied functional dependencies ($F^+$) from a given set of initial dependencies ($F$). Examples of derived rules mentioned in the sources include:

- **Augmentation**: If $X \rightarrow Y$ holds, then $X Z \rightarrow Y Z$ also holds (augmenting both sides with attribute $Z$).
- **Decomposition**: If $X \rightarrow Y Z$ holds, then $X \rightarrow Y$ and $X \rightarrow Z$ both hold.
- **Transitivity**: If $X \rightarrow Y$ and $Y \rightarrow Z$ hold, then $X \rightarrow Z$ holds.
- **Union**: If $X \rightarrow Y$ and $X \rightarrow Z$ hold, then $X \rightarrow Y Z$ holds.

## Normal Forms

Normalization aims to produce a high-quality relational design by minimizing redundancy and anomalies. The normal form indicates the degree to which a relation has been normalized.

### Normal Forms Based on Primary Keys

#### First Normal Form (1NF)

A relation schema must be in 1NF for it to be considered a valid relation in the relational model.

- **Definition**: All attributes in the relation must be **atomic**.
- **Requirement**: This rule disallows nested relations, repeating groups, or attributes that contain sets of values within a single field.

#### Second Normal Form (2NF)

2NF builds upon 1NF and addresses dependencies on only a _part_ of the candidate key.

- **Definition**: A relation schema $R$ is in 2NF if it is in 1NF and every **non-prime attribute** $A$ in $R$ is **fully functionally dependent** on the primary key.
    - _Informally_, this means **all attributes depend on the whole key**.
- **Violation**: A violation occurs if a non-prime attribute is only partially dependent on a proper subset of the primary key.
- **Note**: If the primary key consists of a single attribute, the 2NF test need not be applied.

#### Third Normal Form (3NF)

3NF builds upon 2NF and addresses indirect dependencies.

- **Definition (wrt Primary Key)**: A relation schema $R$ is in 3NF if it is in 2NF and no **non-prime attribute** $A$ in $R$ is **transitively dependent** on the primary key.
    - A **transitive dependency** occurs if $X \rightarrow Z$ is derived from $X \rightarrow Y$ and $Y \rightarrow Z$.
    - _Informally_, this means **all attributes depend on nothing but the key**.
- **Condition for Problem**: When $X$ is the primary key and we have $X \rightarrow Y$ and $Y \rightarrow Z$, this transitive dependency is only considered a problem leading to a 3NF violation if $Y$ is **not a candidate key**.

### General Definitions of Second and Third Normal Forms

When dealing with relations possessing multiple **candidate keys**, general definitions apply:

- **Prime Attribute**: Any attribute that is a member of _any_ candidate key. Non-prime attributes are all others.
- **General 2NF**: A relation schema $R$ is in 2NF if every non-prime attribute $A$ in $R$ is fully functionally dependent on **every key** of $R$.
- **General 3NF**: A relation schema $R$ is in 3NF if whenever a functional dependency $X \rightarrow A$ holds in $R$, then either:
    - (a) **$X$ is a superkey of $R$**, or
    - (b) **$A$ is a prime attribute of $R$**.
    - Condition (a) handles violations related to non-full functional dependencies (2NF issues) and transitive dependencies involving non-prime attributes (3NF issues).

### Boyce-Codd Normal Form (BCNF)

BCNF is a stricter normal form than 3NF.

- **Definition**: A relation schema $R$ is in BCNF if whenever a functional dependency $X \rightarrow A$ holds in $R$, then **$X$ must be a superkey of $R$**.
- **Relationship to 3NF**: Every BCNF relation is in 3NF, but relations exist that are in 3NF but fail to meet BCNF.
- **3NF but Not BCNF**: A relation is in 3NF but not BCNF if it contains a dependency $X \rightarrow A$ where $X$ is **not a superkey**, but $A$ is a **prime attribute**. This specific scenario satisfies the optional condition (b) of the General 3NF definition, but violates the stricter BCNF rule.
- **Decomposition Constraints**: When decomposing a relation to achieve BCNF, the following properties must be considered:
    1. **Non-additive Join (Lossless Join) Property**: This is **extremely critical** and must be maintained to ensure spurious tuples are not generated when relations are rejoined. The NJB test checks if the decomposition ${R_1, R_2}$ is lossless if either $\left(\left(R_{1} \cap R_{2}\right) \rightarrow\left(R_{1}-R_{2}\right)\right)$ or $\left(\left(R_{1} \cap R_{2}\right) \rightarrow\left(R_{2}-R_{1}\right)\right)$ holds true in the FD closure.
    2. **Dependency Preservation Property**: This property ensures all original FDs are represented in the resulting decomposed relations. It is desirable but is sometimes sacrificed to achieve BCNF.

### Higher Normal Forms

Beyond BCNF, higher normal forms exist, although they are less frequently applied in practice.

- **Fourth Normal Form (4NF)**: Based on keys and **multivalued dependencies (MVDs)**. A relation $R$ is in 4NF if, for every nontrivial MVD $X \rightarrow \rightarrow Y$, $X$ is a **superkey** for $R$. MVDs are a consequence of the 1NF requirement disallowing sets of values within a tuple.
- **Fifth Normal Form (5NF)**: Based on keys and **Join Dependencies (JDs)**. An MVD is a special case of a JD where $n=2$. 5NF is rarely used because discovering relevant join dependencies in practical databases is difficult.

# Unit 4 - Transactions, Concurrency, NoSQL and Modern Databases

## Database Transactions and Concurrency

### Database transactions

A transaction is defined as a collection of operations that must satisfy the "all-or-none" principle: either **all operations occur or none occur**, which is critical for ensuring data integrity. The database starts in a consistent state and must end in a consistent state after the transaction successfully completes, even though the database may be temporarily inconsistent _during_ the execution phase. A successful transaction ends with a `commit` instruction, while a failed transaction ends with an `abort` instruction.

### ACID Properties

The ACID properties guarantee reliability within a database system:

1. **Atomicity (A)**: The all-or-none property; either the entire transaction is completed successfully, or no part of it is executed.
2. **Consistency (C)**: A transaction must preserve the database's consistency. If constraints (explicit constraints like foreign keys or implicit constraints) are met before execution, they must be met afterward.
3. **Isolation (I)**: Concurrent transactions must be unaware of each other's execution. The intermediate results of one transaction are hidden from others. If isolation is violated (e.g., if one transaction accesses data partially updated by another), it results in an inconsistent database state.
4. **Durability (D)**: Once a transaction commits successfully, its changes must permanently persist in the database, even if system failures occur later.

### Concurrency control

Concurrency control is the system procedure responsible for managing simultaneous transactions to ensure that they maintain Atomicity, Isolation, Consistency, and Serializability. This is necessary to prevent **concurrent access anomalies**, where simultaneous operations lead to incorrect final results due to timing issues.

- **Isolation Levels**: Different levels dictate how concurrent transactions are protected. The **Read Committed** isolation level, for example, prevents **dirty reads** by only allowing transactions to read committed data.

### Locking

The source mentions that concurrency control systems implement **Transaction and Locking** mechanisms to prevent conflicting changes and ensure consistency.

### Conflict Serializability (Numerical)

A schedule represents the chronological order in which instructions of concurrent transactions are executed. A non-serial schedule is **serializable** if it is equivalent to some serial schedule.

- **Conflicting Operations**: Two operations conflict if they meet three conditions:
    1. They belong to different transactions.
    2. They access the same data item.
    3. At least one of them is a write operation.
- **Test for Conflict Serializability**: To determine if a schedule is conflict serializable, a precedence graph is constructed. If the precedence graph contains a **cycle**, the schedule is **not conflict serializable**.

## NoSQL Databases

### Introduction to NoSQL databases

NoSQL databases are non-tabular databases that store data outside of the rigid relational table format. They emerged largely because traditional SQL systems often imposed too many restrictions (like fixed schemas) or features (like strong consistency) unnecessary for certain applications handling large volumes of unstructured, semi-structured, or polymorphic data.

- **Characteristics**: Most NoSQL systems are built as **distributed databases** designed primarily for **horizontal scalability**, high performance, and continuous availability. They support a **dynamic schema**, allowing developers great flexibility in storing huge amounts of data.
- **Categories**: The main types of NoSQL systems include **document databases** (e.g., MongoDB), **key-value stores** (e.g., Redis, DynamoDB), **wide-column stores** (e.g., Cassandra, BigTable), and **graph databases** (e.g., Neo4j).

### Key-value database

Key-value stores represent the simplest type of NoSQL database.

- **Data Model**: Data is stored as a simple **key-value pair**.
- **Access**: They offer extremely fast access based solely on the key. The value associated with the key can be a simple record, an object, a document, or a complex data structure.
- **Examples**: DynamoDB and Redis are examples of key-value stores.

### Graph databases (Neo4j)

Graph databases, such as Neo4j, are optimized for highly interconnected data.

- **Data Structure**: Data is modeled as a **graph**, composed of:
    - **Nodes (Vertices)**: Represent entities, such as people or products.
    - **Edges (Relationships)**: Connect two nodes and represent the relationships between them (e.g., `FRIEND_OF`).
- **Neo4j Platform**: Neo4j is an open-source graph database implemented in Java. Its primary advantage over relational databases is its ability to handle complex, relationship-heavy queries efficiently by following direct links rather than executing costly joins.
- **Query Language (Cypher)**: Neo4j uses the **Cypher Query Language (CQL)** for simple and readable pattern matching. Examples of clauses include:
    - `MATCH`: Used to search the data for a specified pattern.
    - `CREATE`: Used to create nodes, relationships, and properties.
    - `SET`: Used to update properties or add labels to nodes.
    - `DELETE`/`DETACH DELETE`: Used to remove nodes/relationships, with `DETACH DELETE` removing a node and all associated relationships.

## Vector Databases

### Introduction to Vector databases

Traditional SQL databases support standard primitive data types like integer, float, and string. However, modern data platforms are increasingly evolving to support intricate data types such as **vectors** to accommodate machine learning needs.

- **Definition**: A vector is typically a dynamic array of numbers that describes the location or attributes of an object in a high-dimensional space.
- **Vector Search**: This technique finds similar items by relying on the concept of **vector embeddings**. It operates based on **semantic meaning**, contrasting with traditional **Full-Text Search (FTS)**, which only matches exact words or patterns. Vector search handles context, user intent, and synonyms effectively, making it vital for recommendation systems and question answering.

### Vector search with Relational databases

While relational databases traditionally handled simple data types, they are now evolving to incorporate support for vector data, often represented as a float array, to manage multimedia files and modern analytical needs. The source illustrates this capability in the context of PostgreSQL.

### Vector search with NoSQL databases

Vector embedding and search operations are computationally intensive. NoSQL databases are suitable for handling this workload, especially those built for low-latency operations, such as **in-memory NoSQL databases like Redis**, which can serve real-time results needed for vector search.

## Database Application Connectivity

Database application connectivity refers to the interface that allows external software to interact with the DBMS. The sources illustrate connecting to a MySQL database (e.g., `university_db`) from an application environment. This connectivity is primarily utilized **to enable scalable and lightweight database operations**. Examples provided show the use of functions within an application environment to:

- Create tables (defining primary and foreign keys).
- Insert new data records.
- Update existing data, requiring an explicit `conn.commit()` to apply the change.
- Delete data, requiring the deletion of dependent foreign key records first (e.g., deleting `marks` before deleting the `student`)