# Database Management Systems: Comprehensive Overview

## I. Introduction to Data and Database Concepts

### Data and Information

**Data** represents the raw material, like individual puzzle pieces, that serves as the foundation for knowledge. Data is a raw and unorganized fact that must be processed to become meaningful.

**Information** is data that has been processed, organized, structured, or presented in a given context to make it useful. Data is a collection of facts, while information puts those facts into context. Information depends on data, but data does not depend on information. Information is organized and utilized by humans to make decisions and draw conclusions.

### Database (DB) and Database Management System (DBMS)

A **Database** is defined as a collection of related data representing some aspect of the real world, often called the mini-world or the universe of discourse (UoD). A database is a logically coherent collection, meaning it is organized with inherent meaning and structure, and is designed, built, and populated for a specific purpose.

A **Database Management System (DBMS)** is a general-purpose software system that facilitates four primary processes:

1. **Defining**: Specifying the data types, structures, and constraints to ensure the consistency and integrity of the stored data.
2. **Constructing**: Storing the data on a storage medium controlled by the DBMS, organizing it for efficient retrieval and manipulation, and ensuring secure access.
3. **Manipulating**: Including functions like querying the database to retrieve specific data, updating the database to reflect real-world changes, and generating reports, all while maintaining data consistency and following predefined constraints.
4. **Sharing**: Allowing multiple users and programs to access the database simultaneously, provided they have the necessary permissions.

### Modes of Database Usage

Databases are primarily used in two modes:

1. **Online Transaction Processing (OLTP)**: Used by a large number of users for small data retrieval and updates, common in applications like banking, universities, and airlines.
2. **Data Analytics / Online Analytical Processing (OLAP)**: Involves processing data to draw conclusions and create predictive models for business decisions (e.g., loan approval, targeted advertisements).

## II. Challenges of File-Processing Systems and Purpose of DBMS

Traditional **File-processing Systems** store permanent records in various files manipulated by application programs. These systems suffer from several drawbacks, which a DBMS addresses:

|Challenge in File-Processing Systems|Problem Description|DBMS Solution|
|:--|:--|:--|
|**Data Redundancy and Inconsistency**|Details are duplicated across multiple files (e.g., a double major student's info is duplicated for each department), leading to excessive storage use and potential inconsistencies when updates occur.|Stores information in a centralized location, minimizing redundancy and ensuring consistency when changes are made.|
|**Difficulty in accessing the data**|Conventional file systems are not designed for quick and efficient retrieval of data, often requiring manual sifting or the creation of a new specialized application program for every new type of query.|Provides a central information store, fast retrieval capabilities, and a powerful query language (e.g., SQL) for answering new queries.|
|**Data Isolation**|New applications must retrieve appropriate data scattered across various files, making it hard to manage or prevent concurrency; opening a file typically locks it entirely.|Allows multiple transactions to access the same data without interfering with each other and maintains a consistent view of the data.|
|**Integrity Problems**|Implementing constraints (rules) requires editing all existing application programs; adding a new constraint is challenging and extensive.|Allows integrity constraints to be specified directly in the database schema, ensuring the system enforces rules automatically. Updating the schema is sufficient to add a new constraint.|
|**Atomicity Problems**|If a system failure occurs during a multi-step operation (like a funds transfer), the operation might be partially completed, leaving the database in an inconsistent state.|Ensures **Atomicity** (either all steps are performed, or none are) through mechanisms like automatic rollback in case of failure, ensuring reliability and consistency.|
|**Concurrent Access Anomalies**|Simultaneous operations (e.g., two clerks deducting money from the same account) can lead to incorrect final results depending on the timing of writes.|Implements **Transaction and Locking** mechanisms to ensure atomicity and prevent conflicting changes, maintaining data consistency and integrity.|
|**Security Problems**|Lack of a central security system means unauthorized users might accidentally see or change sensitive records (e.g., payroll staff seeing academic records).|Creates a provision for the administrator to define and enforce access controls and permissions for each user or group at the database level.|

## III. Data Abstraction and Schema

### View of Data and Abstraction Levels

A database system is a collection of interrelated data and a set of programs that allow users to access and modify this data. A major purpose of a database system is to provide users with an **abstract view of the data**. **Data abstraction** hides the complexity of underlying data structures from users through several levels.

|Abstraction Level|Description|Example (University DB)|
|:--|:--|:--|
|**Physical Level**|The lowest level; describes _how_ the data is actually stored in the computer.|Specifies how student records, course information, and department data are stored on the hard drive or in memory.|
|**Logical Level**|Describes _what_ kind of data is stored and how different pieces of information are related to each other; provides an organized and simpler view of the entire database structure.|Defines entities (Department, Student, Course) and their attributes (student ID, course code), outlining relationships (e.g., "Students belong to Departments").|
|**View Level**|The highest level; displays only a _part_ of the entire database tailored to individual users' needs and permissions.|A faculty member sees a view showing only their courses and enrolled students, while a student sees a view displaying their registered courses and grades.|

### Data Independence

Data independence refers to the separation between the physical implementation and the logical definition of data, allowing one level to change without affecting the next higher level.

- **Physical Data Independence**: The ability to modify the physical schema (e.g., changing storage size or switching from sequential to random access files, or using new storage devices) without requiring alterations to the conceptual or logical schema.
- **Logical Data Independence**: The ability to modify the logical schema (e.g., insertion or deletion of attributes, or altering relationships) without affecting the external schema or existing application programs.

### Instances and Schema

- **Database Schema**: The overall design of the database, defined by its data model, which includes tools to describe data, relationships, semantics, and constraints. Analogous to variable declarations and associated type definitions in a programming language.
- **Database Instance/State**: The collection of information stored in the database at a particular moment; the actual data present. Analogous to the value of a variable at a specific point in time. A database state that satisfies all integrity constraints is called a **valid state**.

## IV. DBMS Architecture and Users

### Typical DBMS Component Modules

|Module|Function|
|:--|:--|
|**Storage Manager (SDM)**|Controls access to DBMS information stored on disk.|
|**DDL Compiler**|Processes schema definitions specified in the DDL and stores metadata in the catalog.|
|**Query Compiler**|Handles high-level queries; parses and compiles a query and calls the runtime processor for execution.|
|**Run Time DB Processor**|Executes privileged commands, queries, and canned transactions.|
|**Loading Utility**|Loads existing data files into a database, including data conversion tools.|
|**Backup Utility**|Performs periodic backups (Incremental/Total) of the database.|
|**Performance Monitoring Utilities**|Monitors database usage and provides statistics to the DBA.|

### Database Architectures

1. **Centralized Architecture**: All data is stored and managed on a single central server. It often utilizes shared memory and resources, making it suitable for small to medium-sized applications.
2. **Client-Server Architecture**: A model where a client (user/application) interacts with a server (database system) to access and manage data.
    - **Two-Tier**: Client programs send query and transaction requests (via ODBC or JDBC API) directly to the server, which processes the requests.
    - **Three-Tier**: Includes an intermediate **Application Server or Web Server** layer (middle tier) between the client and the database server. This layer stores the business logic, acts as a conduit for partially processed data, and enhances security by ensuring the database server is only accessible via the middle tier.
3. **Parallel Databases**: Designed to run on a cluster of multiple machines (often sharing memory and shared disks). They enable better scalability and higher processing capabilities, ideal for high-performance applications like real-time analytics or large-scale data warehousing.
4. **Distributed Database**: Data is stored across multiple physical locations (machines or geographic locations). Advantages include scalability, fault tolerance (via replication), and improved performance by distributing load.

### Database Users and Administrator

Database users are categorized by how they interact with the system:

- **Naïve Users (Parametric End users)**: Frequently use database applications through predefined interfaces without needing database knowledge (e.g., booking a ticket).
- **Application Programmers (Back-End Developers)**: Computer professionals who develop application programs and connect the application to the database (e.g., writing queries to manage orders).
- **Sophisticated Users**: Individuals proficient in Data Definition Language (DDL) and Data Manipulation Language (DML) commands, often accessing databases directly using query languages like SQL (e.g., Data engineers).

The **Database Administrator (DBA)** is an individual or team responsible for central control of both the data and the programs that access it. DBA Functions include:

1. **Schema definition**: Creating the original database schema using DDL statements.
2. **Storage structure and access-method definition**: Specifying parameters for physical organization and index creation.
3. **Schema and physical-organization modification**: Making changes to enhance performance or reflect organizational needs.
4. **Granting authorization for data access**: Regulating user access by granting permissions.
5. **Routine maintenance**: Performing periodic backups, ensuring disk space, and monitoring performance.

## V. Entity-Relationship (E-R) Model

The E-R model is a graphical representation of a database's logical structure, valued for its simplicity and clarity in database design.

### Core E-R Concepts

- **Entity**: A basic concept, representing a specific thing or object in the mini-world. Entities can be physical (e.g., employee, car) or conceptual (e.g., project, university course). Entities are represented by **rectangles** in an E-R diagram.
- **Entity Set (or Entity Collection)**: A group of entities of the same kind sharing common attributes (e.g., all students, all instructors).
- **Attribute**: Qualities or characteristics of an entity; they signify the type of information stored. Represented by an **oval**.
    - **Key Attribute**: An attribute (or set of attributes) for which each entity must have a unique value; represented by an **underlined attribute in the oval**.
    - **Composite Attribute**: Attributes that can be split into components (e.g., an address split into street, city, state).
    - **Multivalued Attribute**: Attributes that can take up more than a single value for each entity instance (e.g., instructor phone numbers); represented by a **double ellipse**.
    - **Derived Attribute**: Attributes whose value can be calculated from other attributes (e.g., Age derived from Date_of_Birth); represented by a **dashed oval**.
- **Relationship**: Signifies connections between entities (e.g., "advisor" links an instructor to a student). Represented by a **diamond**.
    - **Relationship Set**: A collection of relationships of the same type.
    - **Relationship Attribute**: An attribute associated with the relationship itself, rather than with the participating entities (e.g., Grade for the 'enroll' relationship).
    - **Degree**: The number of entity sets participating in a relationship set (e.g., binary=2, ternary=3).
    - **Recursive Relationship**: A relationship where the same entity set participates more than once in different roles (e.g., Course prerequisites).

### Constraints in E-R Modeling

#### 1. Cardinality Ratio (Mapping Cardinalities)

These express the number of entities to which another entity can be associated via a binary relationship set.

- **One-to-one (1:1)**: An entity in A is associated with at most one entity in B, and vice versa.
- **One-to-many (1:N)**: An entity in A is associated with many entities in B, but an entity in B is associated with at most one entity in A.
- **Many-to-one (N:1)**: An entity in A is associated with at most one entity in B, but an entity in B is associated with many entities in A.
- **Many-to-many (M:N)**: An entity in A is associated with many entities in B, and vice versa.
- **Min-Max Notation (l, h)**: Provides a way to indicate more complex constraints, where $l$ is the minimum participation and $h$ is the maximum participation.

#### 2. Participation Constraints

- **Total Participation**: Every entity in the set _must_ participate in at least one relationship in the set R; indicated by a **double line** connecting the entity set to the relationship diamond.
- **Partial Participation**: It is possible that some entities do not participate in relationships in R.

### Weak Entities

A **weak entity set** is one whose existence is dependent on another entity set, called its **identifying entity set (strong entity)**.

- **Representation**: A weak entity set is depicted by a **double rectangle**.
- **Identifying Relationship**: The relationship linking the weak entity set to the identifying strong entity set, depicted by a **double diamond**.
- **Key**: A weak entity does not have a primary key of its own. Instead, it uses extra attributes called a **discriminator** (or partial key).
- **Discriminator**: Attributes that uniquely identify the weak entity relative to the identifying entity; underlined with a **dashed line**.
- **Key of Weak Entity**: Formed by the combination of the key of the identifying entity set and the discriminator of the weak entity set.
- **Participation**: A weak entity must have **total participation** in its identifying relationship.

## VI. Relational Database Model and Constraints

The relational model represents the database as a collection of **relations** (tables). In this model, a row is called a **tuple**, and a column is called an **attribute**.

### Relational Schema and State

- **Relation Schema**: Denoted by $R(A_1, A_2, \ldots A_n)$, where $R$ is the relation name and $A_i$ are the attributes. This is also known as the **Intention**.
- **Relation State ($r$)**: A set of $n$-tuples; the actual data in the relation at a particular moment. Also known as the **Extension**.

### Relational Constraints

Constraints determine which values are permissible in the database. The main types of schema-based constraints supported in the relational model are:

1. **Domain Constraint**: Specifies that every value in a tuple must be an **atomic value** from the domain of its attribute. This means composite and multi-valued attributes are not allowed in the relational model.
2. **Key Constraints and Constraints on NULLs**:
    - **Superkey (SK)**: A set of one or more attributes that uniquely identifies a tuple in the relation. No two tuples in a valid state can have the same value for the superkey.
    - **Candidate Key**: A "minimal" superkey (removal of any attribute results in a set that is not a superkey). A relation can have more than one candidate key.
    - **Primary Key (PK)**: One candidate key chosen arbitrarily to uniquely identify each tuple. Primary key attributes are underlined and must be chosen with care, preferably attributes whose values rarely change.
    - **Entity Integrity Constraint**: The primary key attributes of each relation **cannot have null values** in any tuple. This is essential because PK values identify individual tuples.
3. **Referential Integrity Constraint (Foreign Key)**:
    - **Foreign Key (FK)**: A set of attributes in relation $R_1$ (referencing relation) that references the primary key attributes (PK) of relation $R_2$ (referenced relation).
    - The value of FK in a tuple of $R_1$ must either be an existing PK value in $R_2$ or be NULL (if NULL is allowed for the FK attribute).

## VII. Reducing ER Diagrams to Relational Schema

An E-R design can be systematically transformed into a relational design.

|Step|E-R Construct|Relational Mapping Action|
|:--|:--|:--|
|**Step 1**|**Regular (Strong) Entity Types**|Create a relation $R$. Include all simple attributes. Choose one key as the **primary key** for $R$.|
|**Step 2**|**Weak Entity Types**|Create a relation $R$. Include all simple attributes of the weak entity $W$. Include the **primary key of the owner entity** as a foreign key in $R$. The **primary key** of $R$ is the combination of the owner's primary key and $W$'s partial key (discriminator).|
|**Step 3**|**Binary 1:1 Relation Types**|Choose one participating relation ($S$) and include the **primary key of the other relation ($T$) as a foreign key** in $S$. (It is generally better to choose the entity with total participation for $S$).|
|**Step 4**|**Binary 1:N Relation Types**|The relation representing the entity on the **N-side** ($S$) includes the **primary key of the entity on the 1-side** ($T$) as a foreign key.|
|**Step 5**|**Binary M:N Relation Types**|Create a **new relation $S$** (a relationship relation). Include the primary keys of both participating entity relations as foreign keys in $S$. Their combination forms the **primary key of $S$**.|
|**Step 6**|**Multivalued Attributes**|Create a **new relation $R$**. It includes the multivalued attribute (or its simple components) and the primary key ($K$) of the owning entity/relationship as a foreign key. The primary key of $R$ is the combination of the attribute and $K$.|
|**Step 7**|**N-ary Relationship Types (N>2)**|Create a **new relation $S$**. Include the primary keys of all participating entity relations as foreign keys in $S$. Their combination forms the primary key of $S$.|

## VIII. Relational Algebra

Relational algebra is a **procedural language** consisting of a set of operations where each operation takes one or two relations as input and produces a new relation as the result (the "closed" property).

### Unary Operators

|Operator|Notation|Function|Description|
|:--|:--|:--|:--|
|**Select**|$\sigma_p(r)$|**Row filter**|Chooses a subset of tuples from a relation that satisfies a selection predicate ($p$). It is a horizontal partition and is commutative.|
|**Project**|$\prod_{A_1, \ldots, A_k}(r)$|**Column selector**|Returns the argument relation with certain attributes ($A_i$) left out. It is a vertical partition and removes duplicate rows from the result, as relations are sets.|
|**Rename**|$\rho_x(E)$|**Naming result**|Provides a name ($x$) to the result of an expression ($E$), useful when referring to results or handling attribute conflicts.|

### Set Operations (Require Type Compatibility)

|Operator|Notation|Function|
|:--|:--|:--|
|**Union**|$r \cup s$|Combines all tuples from $r$ and $s$; duplicate tuples are eliminated.|
|**Intersection**|$r \cap s$|Finds tuples that are present in both input relations.|
|**Set Difference**|$r - s$|Finds tuples that are in $r$ but are not in $s$.|

### Binary Operations

- **Cartesian Product ($\times$)**: Allows combining information from any two relations by constructing a tuple for every possible pair of tuples (one from each input relation). This operation returns all possible combinations of rows, which can be redundant unless filtered.
- **Join ($\bowtie$)**: Often derived from a Cartesian product followed by a selection (e.g., $\sigma_{A=B}(R \times S)$). A **Natural Join** performs an implicit filter by matching columns with the same name and compatible data types.

### Aggregate Functions ($\mathcal{F}$)

Aggregate functions take a collection of values (set or multiset) as input and return a single value. The common functions are **AVERAGE, MINIMUM, MAXIMUM, SUM, and COUNT**.

**Grouping**: Aggregate functions can be combined with grouping attributes to compute summaries for non-overlapping subgroups of data. This is represented using the $\mathcal{F}$ operation where grouping attributes are placed to the left of the symbol.

## IX. Structured Query Language (SQL)

SQL (Structured Query Language) is the language used to interact with and manage relational databases.

### Types of Database Languages

- **Data Definition Language (DDL)**: Used to define the database structure or schema (e.g., `CREATE`, `ALTER`, `DROP`, `TRUNCATE`).
- **Data Manipulation Language (DML)**: Used for managing data within schema objects (e.g., `SELECT`, `INSERT`, `UPDATE`, `DELETE`).
- **Data Control Language (DCL)**: Concerned with rights and permissions (e.g., `GRANT`, `REVOKE`).
- **Transaction Control Language (TCL)**: Used to manage changes made by DML statements.

### SQL Data Types

SQL supports basic data types including numeric (`INTEGER`, `FLOAT`) and character strings (`CHAR(n)` for fixed-length, `VARCHAR(n)` for variable-length).

|Data Type|Description|
|:--|:--|
|**DATE**|Ten positions, components are YEAR, MONTH, and DAY in the format **YYYY-MM-DD**.|
|**BLOB**|Binary Large Object, used to store unstructured binary data such as images, audio, and video files.|
|**CLOB**|Character Large Object, used to store large blocks of character data or documents.|
|**ENUM** (MySQL)|Defines a list of permitted values for a column.|

### DDL Commands (Schema Modification)

|Command|Purpose|Example Syntax|
|:--|:--|:--|
|`CREATE TABLE`|To specify a new relation (table) with attributes and constraints.|`CREATE TABLE table_name (Col_name1 datatype(), ...);`|
|`ALTER TABLE`|Alters the structure of an existing table (e.g., `ADD` or `DROP` a column, `MODIFY` column definition, `RENAME` column/table, `ADD/DROP` constraints).|`ALTER TABLE table_name ADD Col_name datatype();`|
|`DROP TABLE`|Deletes the entire table structure and all its data from the database.|`DROP TABLE table_name;`|
|`TRUNCATE TABLE`|Removes all rows (complete data) from a table, but the table structure remains.|`TRUNCATE TABLE table_name;`|

### DML Commands (Data Modification)

|Command|Purpose|
|:--|:--|
|`INSERT`|Adds new tuples (rows) to a relation.|
|`UPDATE`|Modifies attribute values of selected tuples using `SET` and a `WHERE` clause.|
|`DELETE`|Removes tuples from a relation based on a `WHERE` clause. A missing `WHERE` clause deletes all tuples, similar to `TRUNCATE`, but the table definition remains.|
|`SELECT`|Retrieves data and lists the attributes desired in the result (corresponds to Relational Algebra Projection).|

### SELECT-FROM-WHERE Structure and Clauses

The core SQL query structure uses `SELECT`, `FROM`, and `WHERE` clauses.

- **`DISTINCT`**: Keyword inserted after `SELECT` to force the elimination of duplicate rows in the result.
- **`WHERE` clause**: Specifies conditions that the result must satisfy (row filter), corresponding to Relational Algebra Selection. Supports logical connectives (`AND`, `OR`, `NOT`) and comparison operators.
    - **String Comparison**: The `LIKE` operator is used with patterns: percent (`%`) matches any substring, and underscore (`_`) matches any single character.
- **`ORDER BY` clause**: Used to sort the result in ascending (`ASC`) or descending (`DESC`) order.
- **`AS` clause**: Used to rename relations and attributes (e.g., `old-name AS new-name`).

### Advanced SQL Features

#### 1. Set Operators

Set operations (`UNION`, `INTERSECT`, `EXCEPT`) combine the results of two or more `SELECT` statements. They require the input relations to have the same number of columns and compatible data types.

- `UNION`: Combines results and eliminates duplicates.
- `UNION ALL`: Combines results and retains duplicates.
- `INTERSECT`: Returns common rows, eliminating duplicates.
- `EXCEPT`: Returns rows present in the first query but absent in the second, eliminating duplicates.

#### 2. Null Values and Logic

SQL uses a special **NULL** value to indicate an absent value (unknown, unavailable, or not applicable).

- **Three-Valued Logic**: Comparisons involving NULL result in the logical value **UNKNOWN**, in addition to TRUE and FALSE.
- The `WHERE` predicate only selects a tuple if it evaluates to **TRUE**.
- To check if an attribute value is NULL, SQL uses the operators **`IS NULL`** and **`IS NOT NULL`**.
- When using aggregate functions, NULL values are generally **discarded** before calculation.

#### 3. Grouping and Filtering Groups

- **`GROUP BY` clause**: Used to partition a relation into non-overlapping groups based on specified attributes. Aggregate functions are then applied independently to each group.
- **`HAVING` clause**: Used in conjunction with `GROUP BY` to specify conditions for **groups of tuples**. The `WHERE` clause selects individual tuples _before_ grouping, while the `HAVING` clause selects groups of tuples _after_ grouping.

#### 4. Join Expressions

Join operations combine tuples from two relations based on matching conditions.

|Join Type|Description|
|:--|:--|
|**Natural Join**|Creates an implicit join by combining tables based on columns with the same name and compatible data type, without needing an explicit join condition.|
|**Inner Join**|Selects and combines rows from both tables that satisfy the join predicate (`ON` clause), returning only the matching records.|
|**Left Outer Join**|Returns all tuples from the left table, plus matching tuples from the right table. Non-matching tuples from the right table are padded with NULLs.|
|**Right Outer Join**|Returns all tuples from the right table, plus matching tuples from the left table. Non-matching tuples from the left table are padded with NULLs.|
|**Full Outer Join**|Returns all records from both tables, regardless of whether they match. (Implemented in MySQL using `LEFT OUTER JOIN UNION RIGHT OUTER JOIN`).|
|**Cross Join**|Returns the Cartesian Product (all possible combinations of rows).|

#### 5. Nested Queries (Subqueries)

A nested query is a complete `SELECT-FROM-WHERE` block inside another SQL query (the outer query).

- **Set Comparison Operators**: `IN` (checks set membership), `NOT IN`. Other comparison operators can be used with modifiers:
    - `comp_op ALL`: Returns TRUE if the comparison holds for _every_ element in the set.
    - `comp_op SOME` (or `ANY`): Returns TRUE if the comparison holds for _at least one_ element in the set.
- **`EXISTS` and `NOT EXISTS`**: Boolean functions used in the `WHERE` clause. `EXISTS` returns TRUE if the result of the nested query is not empty. They are typically used with **correlated nested queries** (queries that reference attributes in the outer query).

#### 6. Views and Common Table Expressions (CTEs)

- **Views**: A **virtual table** stored in the database schema, defined by a query. Used primarily to hide complex queries and simplify access, enhancing security and query simplicity. Views are persistent.
- **`WITH` Clause / Common Table Expression (CTE)**: A **temporary result set** defined using the `WITH` clause, available only for the duration of the query in which it occurs. CTEs simplify complex queries by breaking down subqueries. **Recursive CTEs** are defined using `WITH RECURSIVE` and are useful for traversing hierarchical data structures.

#### 7. Procedures, Functions, and Triggers

- **Stored Procedure**: A collection of pre-compiled SQL statements stored inside the database, acting as a subroutine. Parameters can be IN (default), OUT, or INOUT.
- **User-Defined Function (UDF)**: Created by the user, accepts parameters, performs actions, and returns a single value or table.
- **Trigger**: A statement the system executes automatically as a side effect of a database modification. Defining a trigger involves specifying the **Event** (e.g., `INSERT`, `UPDATE`, `DELETE`), the time (`BEFORE` or `AFTER`), the condition, and the action to be taken. Triggers are used to implement complex integrity constraints.

#### 8. Window Functions

Window functions perform calculations across a defined set of rows (a "window") while retaining the original rows. They are essential for analysis that requires both row-level detail and aggregate comparison.

- **Syntax**: `window_function(column) OVER ([PARTITION BY col1] [ORDER BY col2])`.
- **Aggregate Window Functions**: `SUM()`, `AVG()`, `COUNT()`, `MAX()`, `MIN()` calculated within the window.
- **Ranking Window Functions**: Assign a position based on an `ORDER BY` clause within a partition:
    - **`RANK()`**: Assigns ranks; skips ranks upon ties.
    - **`DENSE_RANK()`**: Assigns ranks; does _not_ skip ranks upon ties.
    - **`ROW_NUMBER()`**: Assigns a unique sequential number to each row (no ties).
- **`LAG()`**: Retrieves the value of a column from a **previous** row within the partition.
- **`LEAD()`**: Retrieves the value of a column from a **future** row within the partition.

#### 9. Full Text Search (FTS) in MySQL

FTS searches for words or phrases in large text-based columns using `MATCH(column) AGAINST('search terms')` syntax. It is faster and more powerful than `LIKE` due to the use of special indexes and relevance ranking.

- **Natural Language Mode**: The default mode, ranking results based on relevance (similarity measure).
- **Boolean Mode**: Allows operators (`+`, `-`, `"`, `*`) for complex logic, including including/excluding terms and using wildcards.