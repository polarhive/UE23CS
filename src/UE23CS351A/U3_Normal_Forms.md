# Query Processing and Normalization

## Query Processing and Optimization

Query processing is defined as the procedure that encompasses the translation of high-level queries into low-level expressions usable at the physical level of the file system, query optimization, and the actual execution of the query to generate the result.

### Introduction to Strategies of Query Processing

The translation of a query from a high-level language like SQL into executable steps is systematic across the query pipeline.

**Steps in Query Processing**

1. **Scanning, Parsing, and Validation:** A query must first be scanned, parsed, and validated.
    - The **scanner** identifies query tokens, such as SQL keywords, attribute names, and relation names.
    - The **parser** checks the query syntax against the rules of the query language.
    - **Validation** confirms that all attribute and relation names are valid and semantically meaningful within the schema of the database being queried.
2. **Internal Representation:** An internal representation of the query is created. This is usually a tree structure known as a **query tree** (or query evaluation/execution tree), or sometimes a graph structure known as a **query graph** (a directed acyclic graph or DAG). In a query tree, leaf nodes represent relations, internal nodes represent relational algebra operators (like SELECT $\sigma$ or JOIN $\bowtie$), and the root node provides the output.
3. **Execution Strategy/Plan:** The DBMS must then devise an execution strategy or **query plan** for retrieving the results from the database files.
4. **Optimization and Code Generation:** The **query optimizer module** produces a good execution plan, and the code generator creates the necessary code to execute that plan. The runtime database processor executes this code.

**Translating SQL Queries and Operators**

SQL queries are translated into an equivalent **extended relational algebra expression**. SQL queries are typically broken down into **query blocks**, which are the basic units that can be translated into algebraic operators and optimized.

Modern SQL engines often use specialized join operators internally for performance when processing subqueries:

- **Semi-Join (S=):** Used for unnesting subqueries involving `EXISTS`, `IN`, and `ANY`. A row from the left table ($T_1$) is returned **as soon as** it finds a match in the right table ($T_2$), contrasting with a standard inner join which seeks all possible matches.
- **Anti-Join (A=):** Used for unnesting subqueries involving `NOT EXISTS`, `NOT IN`, and `ALL`. A row from $T_1$ is returned only if it **does not match** any value in $T_2$. These operators help avoid redundant joins or large intermediate results.

**Algorithms for Implementing Relational Operations**

The selection operation ($\sigma$) is essentially a **search operation** to locate records satisfying a condition, often referred to as a **file scan** (or index scan if an index is used).

| Algorithm                                | Description                                                                                                           | Context/Condition                                                                                              |
| :--------------------------------------- | :-------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------- |
| **S1. Linear Search**                    | The brute force algorithm; retrieves every record in the file and tests the selection condition.                      | No specific structure required. Cost grows linearly ($O(n)$).                                                  |
| **S2. Binary Search**                    | More efficient than linear search.                                                                                    | Used if the selection condition is an equality comparison on a key attribute on which the file is **ordered**. |
| **S3a. Primary Index**                   | Uses the primary index to retrieve the record.                                                                        | Used for equality comparison on a key attribute with a primary index, retrieving at most a single record.      |
| **S4. Primary Index (Multiple Records)** | Uses the index to find the starting record, then retrieves all subsequent or preceding records from the ordered file. | Used for range comparisons (e.g., $>, \geq, <, \leq$) on a key field with a primary index.                     |

The **JOIN operation** is one of the most time-consuming operations in query processing.

| Algorithm                            | Description                                                                                                                                                                                                             | Key Mechanism                                                                                                                                                                                                                                                                               |
| :----------------------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **J1. Nested-Loop Join**             | The default (brute force) algorithm; does not require special access paths. For each record $t$ in the outer loop ($R$), every record $s$ from the inner loop ($S$) is retrieved and tested against the join condition. | Iterative comparison of all pairs of tuples.                                                                                                                                                                                                                                                |
| **J2. Index-Based Nested-Loop Join** | An improvement where an index is used on the join attribute of the inner relation ($S$) to find matching tuples quickly, instead of scanning the inner table completely.                                                | Index lookups replace full inner table scans.                                                                                                                                                                                                                                               |
| **J3. Sort-Merge Join**              | The most efficient if both relations ($R$ and $S$) are physically sorted by the join attributes. Both files are scanned concurrently, matching records with the same join values.                                       | Sorting both tables on the join attribute, followed by a single merge pass.                                                                                                                                                                                                                 |
| **J4. Partition-Hash Join**          | Records of files $R$ and $S$ are partitioned into smaller files using the **same hashing function** $h$ on the join attributes.                                                                                         | **Partitioning Phase:** The file with fewer records (say $R$) is hashed into buckets (ideally kept in main memory). **Probing Phase:** A single pass through the other file ($S$) hashes each record and probes the corresponding hash bucket, combining it with matching records from $R$. |

### Query Optimization

**Query Optimization** is the process of planning a good execution strategy to improve the efficiency of SQL queries. The ultimate goal is to **minimize execution time** and reduce system resources (CPU, memory, I/O).

**Process of Optimization**

The optimizer converts the high-level SQL query into an internal tree representation. It explores alternative execution plans by applying **equivalent transformations** on this tree (e.g., changing join order or pushing selections down).

**Types of Query Optimizations**

1. **Heuristic (Rule-Based) Optimization:** This method applies transformation rules to the query tree without numerical cost estimation. It aims for rapid and efficient exploration of execution plans. Key heuristic rules include:
    - Applying **SELECT and PROJECT operations early** to reduce the number of tuples and columns being processed.
    - Replacing `CARTESIAN PRODUCT` combined with `SELECT` operations with `JOIN` operations.
    - Executing the most restrictive filters first.
2. **Cost-Based Optimization:** This is based on estimating the cost (in terms of I/O, CPU time, memory usage, and communication) for each possible execution plan. It uses **statistics from the DBMS catalog** (such as file size, number of records, index levels, attribute selectivity, and histogram distributions). The optimizer chooses the plan that has the **lowest estimated cost**.
3. **Semantic Query Optimization:** This involves rewriting a query into an equivalent but more efficient version by utilizing **semantic information** derived from the database schema and integrity constraints (like functional dependencies or keys). It simplifies or eliminates redundant operations without changing the query's result.
4. **Dynamic Query Optimization:** Decisions are made during query execution, rather than before, using runtime feedback loops to adjust parameters like join order or access paths.

**Optimization Tools and Techniques**

The best way to improve the performance of SELECT operations is to **create indexes** on columns tested in the query. Index entries act as pointers, allowing the query to quickly determine matching rows.

- Without indexing, MySQL performs a **full table scan**, and cost grows linearly ($O(n)$).
- With indexing (e.g., B-tree index), MySQL jumps directly to qualifying records, and cost is drastically reduced ($O(\log n)$).

The **MySQL `EXPLAIN`** tool is powerful for analyzing and optimizing SQL queries. It provides insight into the chosen execution plan, including the order in which tables are accessed and the use of indexes.

## Functional Dependencies

**Functional Dependencies (FDs)** are constraints between two sets of attributes from the database, derived from the meaning and interrelationships of the data attributes. They are fundamental constraints used to specify formal measures of the "goodness" of relational designs and to define normal forms.

### Definition and Constraints

A functional dependency, denoted by **$X \rightarrow Y$**, specifies a constraint on the possible tuples that can form a relation state $r$ of $R$.

- If any two tuples ($t_1$ and $t_2$) in $r(R)$ have the same value for $X$ ($t_1[X] = t_2[X]$), they must also have the same value for $Y$ ($t_1[Y] = t_2[Y]$).
- In simpler terms, a set of attributes $X$ functionally determines $Y$ if the value of $X$ determines a unique value for $Y$.
- The constraint $X \rightarrow Y$ must hold on **every** legal relation instance $r(R)$.
- If $X$ is a **candidate key** of $R$, this implies $X \rightarrow Y$ for any subset of attributes $Y$ of $R$.

**Key Terminology**

- **Prime Attribute:** An attribute of $R$ that is a member of **some** candidate key of $R$.
- **Non-prime Attribute:** An attribute that is **not** a member of any candidate key.

**Types of Functional Dependencies**

1. **Full Functional Dependency:** $X \rightarrow Y$ is full if removing **any** attribute $A$ from $X$ causes the dependency to no longer hold (i.e., $(X - {A})$ does not functionally determine $Y$). _Example: ${Ssn, Pnumber} \rightarrow Hours$_.
2. **Partial Functional Dependency:** $X \rightarrow Y$ is partial if **some** attribute $A \in X$ can be removed and the dependency still holds (i.e., $(X - {A}) \rightarrow Y$ remains valid). This often occurs when a non-prime attribute depends only on a portion of the candidate key. _Example: ${Ssn, Pnumber} \rightarrow Ename$ is partial because $Ssn \rightarrow Ename$ holds_.
3. **Transitive Functional Dependency:** If $X \rightarrow Y$ and $Y \rightarrow Z$, then $X \rightarrow Z$ is transitive. This is considered a transitive dependency specifically if $X$ is a key and $Z$ is a non-prime attribute.
4. **Trivial Functional Dependency:** Holds by definition based on the Reflexive Rule; $X \rightarrow Y$ is trivial if $Y$ is a subset of $X$.
5. **Non-Trivial Functional Dependency:** $X \rightarrow Y$ is non-trivial if $Y$ is **not** a subset of $X$ ($Y \not\subseteq X$), meaning $Y$ contains at least one attribute that is not already part of $X$.

### Inference Rules and Closure

Given a set of FDs $F$, additional FDs can be **inferred** or implied that must hold whenever the FDs in $F$ hold.

**Armstrong's Inference Rules (Axioms)**

These rules are a **sound** (every derived FD is valid) and **complete** (all valid FDs can be derived) set of rules:

1. **IR1 (Reflexive):** If $Y \subseteq X$, then $X \rightarrow Y$ always holds.
2. **IR2 (Augmentation):** If $X \rightarrow Y$, then $XZ \rightarrow YZ$ always holds (where $XZ = X \cup Z$).
3. **IR3 (Transitive):** If $X \rightarrow Y$ and $Y \rightarrow Z$, then $X \rightarrow Z$ always holds.

**Additional Derivable Rules**:

- **Decomposition:** If $X \rightarrow YZ$, then $X \rightarrow Y$ and $X \rightarrow Z$.
- **Union/Additive:** If $X \rightarrow Y$ and $X \rightarrow Z$, then $X \rightarrow YZ$.
- **Pseudo-Transitivity:** If $X \rightarrow Y$ and $WY \rightarrow Z$, then $WX \rightarrow Z$.

**Closure Concepts**

The concept of closure is essential in DBMS for key determination, normalization testing, and dependency analysis.

1. **Attribute Closure ($X^+$):** The set of all attributes that are functionally determined by $X$, based on the given set of FDs ($F$). Determining $X^+$ helps check whether $X$ is a superkey or candidate key.

    **Algorithm to Determine $X^+$**:
    
    - Set $X^+ := X$;
    - `repeat`
        - $oldX^+ := X^+$;
        - `for each functional dependency $Y \rightarrow Z$ in $F$ do`
            - `if $X^+ \supseteq Y$ then $X^+ := X^+ \cup Z$;`
    - `until ($X^+ = oldX^+$);`
2. **Functional Dependency Closure ($F^+$):** The set of all FDs that can be logically inferred from $F$ using Armstrong’s Axioms.
    

**Equivalence of Sets of FDs**

Two sets of functional dependencies, $E$ and $F$, are **equivalent** if $E^+ = F^+$. This requires that $E$ **covers** $F$ (every FD in $F$ can be inferred from $E$) and $F$ **covers** $E$ (every FD in $E$ can be inferred from $F$). To check coverage (e.g., $F$ covers $G$), one calculates the closure of the LHS attributes of $G$'s dependencies using $F$ and checks if the RHS attributes of $G$ are included.

**Minimal Cover**

A **minimal cover** of a set of functional dependencies $E$ is a minimal set of dependencies that is equivalent to $E$. The minimal set $F$ must satisfy three conditions:

1. Every dependency in $F$ has a **single attribute** for its Right-Hand Side (RHS) (Canonical Form).
2. No dependency $X \rightarrow A$ in $F$ can be replaced by $Y \rightarrow A$, where $Y$ is a proper subset of $X$, and still maintain equivalence (removal of **extraneous attributes** on the LHS).
3. No dependency can be removed from $F$ and still maintain equivalence (removal of **redundant dependencies**).

## Normal Forms

**Normalization** is the process of analyzing a given relation schema based on its FDs and keys to achieve the desirable properties of minimizing redundancy and minimizing insertion, deletion, and update anomalies. The database designer usually normalizes up to 3NF and BCNF.

### Informal Measures of Quality (Database Design Principles)

Relational database design is fundamentally about grouping attributes into "good" relation schemas. Formal theory is primarily applied in the **top-down design methodology** (Design by Analysis), which starts with existing groupings and decomposes them until desirable properties are met.

The sources define four informal measures of quality for relation schema design:

1. **Clear Semantic Attributes (Guideline 1):** Each tuple should ideally represent one entity or relationship instance. Attributes of different entities (e.g., employees and departments) should not be mixed in the same relation. Violating this guideline leads to semantic ambiguities.
2. **Reducing Redundancy and Anomalies (Guideline 2):** A schema should not suffer from insertion, deletion, or update anomalies, which waste storage and cause consistency problems. For example, **update anomaly** requires multiple changes for one fact (e.g., changing a project name); **deletion anomaly** causes loss of unrelated information when a tuple is removed.
3. **Reducing NULL Values (Guideline 3):** Relations should be designed to have as few NULL values as possible, applying only in exceptional cases. Attributes that are frequently NULL can be placed in separate relations with the primary key.
4. **Avoiding Spurious Tuples (Guideline 4):** Relations must be joinable using equality conditions on appropriately related (primary key, foreign key) pairs, guaranteeing that no spurious (meaningless, incorrect) tuples are generated. This property is considered **extremely critical and must be achieved at any cost**.

### Normal Forms Based on Primary Keys

The normal forms are hierarchical, with each higher form being strictly stronger than the preceding one (e.g., every 3NF relation is in 2NF).

1. **First Normal Form (1NF):** A relation schema is in 1NF if the domain of every attribute contains only **atomic (indivisible) values**. This means attributes cannot contain composite values, multivalued attributes, or nested relations (repeating groups). This property is fundamental to the relational model.
2. **Second Normal Form (2NF) (w.r.t Primary Key):** A relation $R$ is in 2NF if it is in 1NF, and every **non-prime attribute** in $R$ is **fully functionally dependent** on the primary key. Informally, this ensures that "all attributes depend on the **whole key**". A violation occurs due to a partial functional dependency involving a non-prime attribute and only a portion of the key.
3. **Third Normal Form (3NF) (w.r.t Primary Key):** A relation $R$ is in 3NF if it is in 2NF, and no **non-prime attribute** $A$ in $R$ is **transitively dependent** on the primary key. Informally, this ensures that "all attributes depend on **nothing but the key**". Transitivity ($X \rightarrow Y$ and $Y \rightarrow Z$, where $X$ is the primary key) is only problematic if $Y$ is **not** a candidate key.

### General Definitions of Second and Third Normal Forms

These general definitions apply when a relation has multiple candidate keys, defining any attribute in _any_ candidate key as a prime attribute.

- **General Definition of 2NF:** A relation schema $R$ is in 2NF if every non-prime attribute $A$ in $R$ is **fully functionally dependent on every key of R**.
- **General Definition of 3NF:** A relation schema $R$ is in 3NF if whenever an FD $X \rightarrow A$ holds in $R$, then either:
    
    1. $X$ is a **superkey** of $R$, or
    2. $A$ is a **prime attribute** of $R$.
    
    - This definition is equivalent to saying that every non-prime attribute must be both fully functionally dependent and non-transitively dependent on every key of $R$.

### Boyce-Codd Normal Form (BCNF)

**Definition:** A relation schema $R$ is in **Boyce-Codd Normal Form (BCNF)** if whenever an FD $X \rightarrow A$ holds in $R$, then **$X$ must be a superkey of R**.

**Relationship to 3NF:**

BCNF is a **strictly stronger** form of 3NF. A relation can be in 3NF but fail BCNF only if there exists an FD $X \rightarrow A$ where $X$ is not a superkey, but $A$ is a prime attribute.

**Achieving BCNF by Decomposition**

Normalization via decomposition must conform to specific desirable properties:

1. **Non-additive Join or Lossless Join Property:** This property is **extremely critical and must be achieved at any cost**. It ensures that joining the decomposed relations does not generate spurious tuples.
2. **Dependency Preservation Property:** This is desirable but sometimes sacrificed. It ensures that every original FD is represented in some individual decomposed relation.

**Lossless Join Test for Binary Decompositions (NJB Property):** A decomposition $D = {R_1, R_2}$ of $R$ has the lossless join property with respect to $F$ if and only if either:

- The FD $((R_1 \cap R_2) \rightarrow (R_1 - R_2))$ is in $F^+$, **OR**
- The FD $((R_1 \cap R_2) → (R_2 - R_1))$ is in $F^+$.

**BCNF Decomposition Procedure:** If relation $R$ is not in BCNF due to violation $X \rightarrow A$, where $X$ is not a superkey, $R$ may be decomposed into two relations: (i) $R - A$ and (ii) $X \cup A$. This process is repeated if either resulting relation is still not in BCNF.

### Higher Normal Forms

Higher normal forms address anomalies related to multi-valued and join dependencies, which are consequences of the 1NF requirement.

**Fourth Normal Form (4NF)**

4NF is based on **Multi-valued Dependencies (MVDs)**. An MVD ($X \rightarrow \rightarrow Y$) is a constraint stating that if two tuples $t_1$ and $t_2$ agree on $X$, then additional tuples $t_3$ and $t_4$ must exist to ensure that the $Y$ values associated with $X$ are independent of the other attributes ($Z$).

- **Definition:** A relation schema $R$ is in **4NF** if, for every **nontrivial multivalued dependency** $X \rightarrow \rightarrow Y$ in $F^+$, **$X$ is a superkey for R**.

**Fifth Normal Form (5NF) / Project-Join Normal Form (PJNF)**

5NF is based on **Join Dependencies (JDs)**. An MVD is a special case of a JD where $n=2$. A JD, denoted $JD(R_1, R_2, ..., R_n)$, specifies that every legal state $r$ of $R$ must have a **non-additive join decomposition** into $R_1, R_2, ..., R_n$.

- **Definition:** A relation schema $R$ is in **Fifth Normal Form (5NF)** (or **PJNF**) if, for every **nontrivial join dependency** $JD(R_1, R_2, ..., R_n)$ in $F^+$ (implied by $F$), **every $R_i$ is a superkey of R**.
- **Practicality:** 5NF is rarely used in practice because join dependencies are extremely difficult to discover in real-world databases.
