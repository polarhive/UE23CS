# Unit 1: Data Definition Language (DDL) and Constraints

| Topic/Feature                       | Description                                                                                 | Command/Syntax Example                                                                                                                   | Citation |
| :---------------------------------- | :------------------------------------------------------------------------------------------ | :--------------------------------------------------------------------------------------------------------------------------------------- | :------- |
| **Database/Schema Creation**        | Creates a new database/schema. In MySQL, `SCHEMA` and `DATABASE` are functionally the same. | `CREATE DATABASE db1;` <br> `USE db1;` <br> `CREATE SCHEMA Library;`                                                                     |          |
| **Table Creation (Basic)**          | Defines a new relation with attribute types and primary keys.                               | `CREATE TABLE students (`<br>`student_id INT AUTO_INCREMENT PRIMARY KEY,` <br>`name VARCHAR(100),` <br>`department VARCHAR(50)` <br>`);` |          |
| **Constraint: Primary Key**         | Defines the primary key for a relation.                                                     | `srn VARCHAR(10) PRIMARY KEY,` <br> `Dnumber INT PRIMARY KEY;`                                                                           |          |
| **Constraint: Foreign Key**         | Enforces referential integrity.                                                             | `FOREIGN KEY (dept_id) INT REFERENCES Department(dept_id);`                                                                              |          |
| **Constraint: Referential Actions** | Specifies the action the DBMS takes on foreign key violation (`ON DELETE`/`ON UPDATE`).     | Options include `SET NULL`, `CASCADE`, and `SET DEFAULT`. `CASCADE` is suitable for "relationship" relations.                            |          |
| **Constraint: Unique Key**          | Specifies alternate keys (Candidate keys) which must be unique.                             | `Dname VARCHAR(15) UNIQUE;`                                                                                                              |          |
| **Constraint: Check**               | Adds constraints on individual tuples to ensure logical integrity.                          | `CHECK (gpa <= 10)` <br> `CHECK (Dept_create_date <= Mgr_start_date);`                                                                   |          |
| **Alter Table (Add Col)**           | Adds a new column to an existing table.                                                     | `ALTER TABLE Student ADD email VARCHAR(50);`                                                                                             |          |
| **Alter Table (Rename Col)**        | Renames an existing column.                                                                 | `ALTER TABLE Student RENAME COLUMN email TO email_id;`                                                                                   |          |

## II. Data Manipulation Language (DML) and DQL

| Topic/Feature | Description | Command/Syntax Example | Citation |
| :--- | :--- | :--- | :--- |
| **Select (Basic DQL)** | Retrieves specific columns. | `SELECT Fname, Lname, email_id FROM Student;` | |
| **Select (Calculated Column)**| Calculates and renames an attribute. | `SELECT fname, salary/12 AS monthly_salary;` | |
| **Insert (Standard)** | Adds new data rows to a table. | `INSERT INTO ... VALUES (%s, %s)` (Used with application placeholders) | |
| **Insert (Using Subquery)** | Inserts results from a `SELECT` query. | `INSERT INTO WORKS_ON_INFO (Emp_name, Proj_name, Hours_week) SELECT E.Lname, P.Pname, W.Hours FROM Project P, WorksOn W, Employee E WHERE P.Pnumber = W.Pno AND W.Essn = E.ssn;` | |
| **Update (Basic DML)** | Modifies attribute values of selected tuples. | `UPDATE Student SET Fname = 'Pranavjeet', Lname = 'Naidu' WHERE srn LIKE '%CS123';` | |
| **Update (Using Subquery)** | Updates based on an aggregate result. | `UPDATE Employee SET Salary = Salary*1.05 WHERE salary < (SELECT AVG(salary) FROM Employee);` | |
| **Delete (DML)** | Removes tuples (rows) based on a `WHERE` clause. | `DELETE FROM Employee WHERE Lname = 'Kota';` | |
| **String Comparison** | Uses `LIKE` for pattern matching (`%` for any string, `_` for any single character). | `SELECT Fname, Lname, bdate FROM EMPLOYEE WHERE Bdate LIKE '196_ _ _ _ _ _ _';` (Finds employees born in 1960s) | |

# Unit 2: Advanced Query Constructs (Joins, Set, Aggregates)

| Topic/Feature | Description | Command/Syntax Example | Citation |
| :--- | :--- | :--- | :--- |
| **Inner Join** | Returns rows only when there is a match in both tables. | `SELECT l.Loan_ID, ... FROM Loan l JOIN Borrower b ON l.Loan_ID = b.Loan_ID;` | |
| **Natural Join** | Implicitly joins tables based on columns with the same name and datatype. | `SELECT col1, col2, col3 FROM table1 NATURAL JOIN table2;` | |
| **Right Outer Join** | Returns all rows from the right table, and matching rows from the left table. | `SELECT s.fname, s.lname, d.dept_name FROM Student AS s RIGHT JOIN Department AS d ON s.dept_id = d.dept_id;` | |
| **Cross Join** | Returns the Cartesian Product (all combinations) of rows from both tables. | `select * from loan cross join borrower;` | |
| **Union Operator** | Combines results from two or more `SELECT` statements, eliminating duplicates by default. | `SELECT col1 FROM table1 UNION SELECT col2 FROM table2` | |
| **Intersection Operator**| Returns tuples common to both queries (explicitly listed in cheatsheet). | `SELECT col1 FROM table1 INTERSECT SELECT col2 FROM table2` | |
| **Except Operator** | Returns tuples from the first query that are not present in the second query. | `SELECT col1 FROM table1 EXCEPT SELECT col2 FROM table2` | |
| **`ALL` Modifier (Set Ops)** | Used with set operations if duplicate tuples should not be removed. | `UNION ALL` | |
| **Aggregate Functions** | Used for calculations like sum, average, max, and count. | `SELECT SUM(salary), AVG(salary) MAX(salary), MIN(salary) FROM Employee;` | |
| **Grouping (`GROUP BY`)** | Groups output rows based on common column values. | `SELECT dno, COUNT(*), AVG(salary) FROM Employee GROUP BY dno;` | |
| **Group Filtering (`HAVING`)**| Filters grouped or aggregated results *after* the `GROUP BY` clause is applied. | `SELECT Category, COUNT(*) FROM Products GROUP BY Category HAVING COUNT(*) > 5;` | |
| **Null Check** | Checks if an attribute value is missing. | `SELECT Fname, Lname FROM EMPLOYEE WHERE Super_ssn IS NULL;` | |
| **Unknown Check** | Tests whether the result of a comparison is `UNKNOWN` (e.g., due to null values). | `SELECT Essn, Pno FROM WORKS_ON WHERE Hours > 10 IS UNKNOWN;` | |
| **Nested Subquery (Example)** | Finds project numbers managed by 'Smith' or worked on by 'Smith'. | `... Pnumber IN ( SELECT Pno FROM WORKS_ON, EMPLOYEE WHERE Essn = Ssn AND Lname = 'Smith' );` | |
| **Correlated Query (Equiv.)**| Example showing how a correlated query can be rewritten as a join. | `SELECT E.Fname, E.Lname FROM EMPLOYEE AS E, DEPENDENT AS D WHERE E.Ssn = D.Essn AND E.Gender = D.Gender;` | |
| **Semi-Join Concepts** | The operation (`S=`) to which modern SQL engines map `EXISTS`, `IN`, and `ANY` subqueries for efficiency. | `T1.X S = T2.Y` | |
| **Anti-Join Concepts** | The operation to which `NOT EXISTS` subqueries are mapped. | N/A (Internal operation, no explicit SQL syntax provided) | |

## Advanced Database Objects

| Topic/Feature                     | Description                                                                                                       | Command/Syntax Example                                                                                                                                                                     | Citation        |
| :-------------------------------- | :---------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------- |
| **View Creation**                 | Creates a virtual table (`CREATE VIEW`) based on a stored query.                                                  | `CREATE VIEW phy_fall_2017 AS SELECT course_id, sec_id, building, room_no, FROM course, section WHERE course.dept_name = "Physics" AND section.year = 2017;`                               |                 |
| **Common Table Expression (CTE)** | Defines a temporary, non-persistent result set using the `WITH` clause.                                           | `WITH Project_Counts AS (`<br> `SELECT e.Fname, COUNT(w.Pno) AS Proj_Count ... )` <br> `SELECT Fname, Proj_Count, ... FROM Project_Counts;`                                                |                 |
| **Recursive CTEs**                | Used for traversing hierarchical data structures, defined using `WITH RECURSIVE`.                                 | N/A (Keyword mentioned, no full code example)                                                                                                                                              |                 |
| **User-Defined Function (UDF)**   | Accepts parameters and returns a single value or table.                                                           | `CREATE FUNCTION no_of_years(date1 date) RETURNS INTEGER deterministic BEGIN ... RETURN year(date2)-year(date1); END`                                                                      |                 |
| **Stored Procedure**              | A pre-compiled collection of SQL statements acting as a subroutine, stored inside the database.                   | `DELIMITER $$`<br> `CREATE PROCEDURE procedure_name(IN parameter_name data_type) BEGIN` <br> `SELECT * FROM some_table WHERE column_name = parameter_name;` <br> `END$$`<br> `DELIMITER ;` |                 |
| **Trigger Definition Syntax**     | Defines a statement executed automatically based on a database modification event (`INSERT`, `UPDATE`, `DELETE`). | `DELIMITER $$`<br> `CREATE TRIGGER trigger_name FOR EACH ROW (AFTER                                                                                                                        | BEFORE) (INSERT |
| **Trigger Action (Example)**      | Defines a trigger that backs up old data before deletion.                                                         | `DELETE FROM Marks_sample WHERE SRN = 2;` (Execution causing the `BEFORE DELETE` trigger logic to run)                                                                                     |                 |
| **Window Function**               | Performs calculations across a set of table rows related to the current row (e.g., partitioning).                 | `window_function(col2) OVER ([PARTITION BY col1]) AS newcol FROM table1` <br> `AVG(salary) OVER (PARTITION BY department) AS dept_avg_salary FROM Employee;`                               |                 |
| **Full Text Search (Boolean)**    | Matches specified search terms using modifiers like `+` (include).                                                | `SELECT * FROM products WHERE MATCH(prod_name, description) AGAINST('smartphone' IN BOOLEAN MODE)`                                                                                         |                 |
| **Full Text Search (Natural)**    | Ranks and retrieves results based on relevance score.                                                             | `SELECT *, MATCH(title, description) AGAINST('MySQL' IN NATURAL LANGUAGE MODE) AS score FROM articles ...`                                                                                 |                 |

Is there a specific advanced feature, such as working with triggers or demonstrating recursive CTE logic, that you would like to test yourself on next?

# Unit 3: Design Concepts and Implementation

## Query Processing and Optimization

### Relational Algebra Notation (Operators)

Relational algebra is a **procedural language** where operations take relations as input and produce a new relation as output.

|Operation|Notation|Description / Usage|Source|
|:--|:--|:--|:--|
|**Select** (Row Filter)|$\\sigma_p(r)$|Chooses a subset of tuples ($r$) satisfying a predicate ($p$).||
|**Project** (Column Selector)|$\\prod_{A_1, \\\ldots, A_k}(r)$|Returns the relation ($r$) with only the specified attributes ($A_i$).||
|**Join**|$\\bowtie_{condition}$|Combines two relations based on a join condition. Often replaces the combination of Cartesian Product ($\\times$) and Select ($\\sigma$) during optimization.||
|**Cartesian Product**|$\\times$|Combines every tuple from the first relation with every tuple from the second relation.||

### SQL and Relational Algebra Translation/Optimization Examples

Query processing translates high-level SQL into low-level operations. Optimization involves rearranging these operations, often shown in query trees.

|Query Translation / Optimization Step|Example Syntax / Notation|Source|
|:--|:--|:--|
|**Complex Nested SQL Query**|`SELECT Lname, Fname FROM EMPLOYEE WHERE Salary > (SELECT MAX (Salary) FROM EMPLOYEE WHERE Dno=5);`||
|**RA Translation (Inner Block)**|$\\Im_{MAX \\\ Salary}(\\sigma_{Dno=5}(EMPLOYEE))$||
|**RA Translation (Outer Block)**|$\\pi_{Lname, Fname}(\\sigma_{Salary>c}(EMPLOYEE))$||
|**RA Expression (Complex Join)**|$\\Pi_{Pnumber, Dnum, Lname, Address, Bdate}(((((\\sigma_{Plocation = 'Stanford'}(PROJECT)) \\\bowtie_{Dnum=Dnumber}(DEPARTMENT)) \\\bowtie_{Mgr_ssn=Ssn}(EMPLOYEE)))$||
|**Heuristic Optimization (Moving SELECT down)**|Starting with a canonical tree that applies all conditions at once, optimization moves selection operations, like $\\sigma_{Plocation = 'Stanford'}$ on `PROJECT`, down to reduce intermediate result size.||
|**Heuristic Optimization (Replacing Cartesian Product)**|Replacing implicit Cartesian Products and selection conditions with explicit JOIN operations ($\\bowtie$).||

### Extended SQL Operators and Constructs

|Operator/Mode|Usage Context|Source|
|:--|:--|:--|
|**Set Operators**|`UNION`, `UNION ALL`, `INTERSECT`, `EXCEPT`.||
|**Set Comparison Modifiers**|`comp_op ALL`, `comp_op SOME` (or `ANY`).||
|**Existence Checks**|`EXISTS` and `NOT EXISTS` (used, typically with **correlated nested queries**).||
|**Stored Procedures**|Defined by specifying parameters (IN, OUT, or INOUT).||
|**User-Defined Function (UDF)**|Must return a single value or table.||
|**Triggers**|Definition involves specifying the **Event** (`INSERT`, `UPDATE`, `DELETE`), **Time** (`BEFORE` or `AFTER`), condition, and action.||
|**Full-Text Search (Boolean Mode)**|Allows logical operators: `+`, `-`, `\"`, `*` for complex search criteria.||

## Functional Dependencies (FDs) and Normalization

### Functional Dependency Notation (FD) and Closure

|Notation/Concept|Example|Description|Source|
|:--|:--|:--|:--|
|**Functional Dependency**|$X \\\rightarrow Y$ (e.g., $A \\\rightarrow B$, $BC \\\rightarrow D$)|$X$ determines $Y$.||
|**Closure**|$A^+$ or ${B, C}^+$|The set of all attributes functionally determined by $A$ or ${B, C}$.||
|**Multivalued Dependency (MVD)**|$X \\\rightarrow \\\rightarrow Y$|An MVD exists on schema R. A trivial MVD exists if $Y$ is a subset of $X$, or $X \\\cup Y = R$.||

### Numerical Derivation Steps (Inference Rules)

Inference rules (like Armstrong's Axioms) are used to derive new FDs:

|Inference Rule|Example Step/Usage|Source|
|:--|:--|:--|
|**Augmentation**|Given $A \\\rightarrow B$, we derive **$AC \\\rightarrow BC$** (by augmenting both sides with $C$).||
|**Transitivity**|Given $AC \\\rightarrow BC$ and $BC \\\rightarrow D$, we derive **$AC \\\rightarrow D$**.||
|**Union**|Given $AB \\\rightarrow G$ and $AB \\\rightarrow I$, we derive **$AB \\\rightarrow GI$**.||
|**Decomposition**|Given $AD \\\rightarrow EF$, we derive **$AD \\\rightarrow F$**.||

### Numerical Examples for Closure Calculation

- **Closure Example 1**: Given $F = {A \\\rightarrow B, BC \\\rightarrow DE, AEG \\\rightarrow G}$ on $R(A, B, C, D, E, F, G)$.
    - $A^+ = {A, B}$.
    - $AC^+ = {A, C, B, D, E}$.
    - $ADE^+ = {A, D, E, B}$.
- **Closure Example 2**: Given $F = {BC \\\rightarrow DE, D \\\rightarrow F, CF \\\rightarrow G}$.
    - ${B, C}^+ = {B, C, D, E, F, G}$.

### Numerical Examples for Normalization (BCNF Decomposition)

When decomposing a relation $R$ based on an FD $C \\\rightarrow DE$ where $C$ is not a Candidate Key (CK):

|Relation|FD Set|Candidate Key|Decomposition Example|Source|
|:--|:--|:--|:--|:--|
|$R(A, B, C, D, E)$|$A \\\rightarrow BC$, $C \\\rightarrow DE$|$A$|Decomposition results in: $R_1(A, BC)$ and $R_2(C, D, E)$.||

---

# Unit 4: Transactions, Concurrency, NoSQL, and Modern Databases

## Database Transactions and Concurrency

### Transaction Control (MySQL Syntax)

|Operation|SQL Command Example|Context|Source|
|:--|:--|:--|:--|
|**Set Isolation Level**|`SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE;`|Sets the isolation policy for the current session.||
|**Start Transaction**|`START TRANSACTION;`|Marks the beginning of a sequence of operations that must be atomic.||
|**Commit**|`COMMIT;`|Saves all changes made by the transaction permanently to the database.||
|**Rollback**|`ROLLBACK;`|Undoes changes made by the transaction, typically triggered by an error.||
|**Verify Isolation Level**|`SELECT @@transaction_isolation;`|Used to check the current isolation level setting.||

### Conflict Serializability Notation

Conflict serializability relies on identifying conflicting operations between transactions $T_i$ and $T_j$ on data item $Q$.

|Conflict Type|Notation (where $i \\\neq j$)|Conflict Status|Source|
|:--|:--|:--|:--|
|Read-Read|$R_i(Q), R_j(Q)$|**No Conflict**||
|Read-Write|$R_i(Q), W_j(Q)$|**Conflict**||
|Write-Read|$W_i(Q), R_j(Q)$|**Conflict**||
|Write-Write|$W_i(Q), W_j(Q)$|**Conflict**||

The presence of a **cycle** in the resulting precedence graph means the schedule is **not conflict serializable**.

## NoSQL Databases

### Key-Value Database (Redis) Commands

Redis commands operate on simple key-value pairs or specialized data structures (like Lists or Sorted Sets).

|Category|Command Example|Function|Source|
|:--|:--|:--|:--|
|**Basic String Get**|`GET user:1:name`|Gets the value associated with a key.||
|**Basic String Multi-Set**|`MSET user:1:name "Alice" user:2:name "Bob"`|Sets multiple key-value pairs atomically.||
|**Atomic Increment**|`INCR page:views`|Increments the integer value of a key by one.||
|**Increment by N**|`DECRBY items:in_stock 5`|Decrements the integer value by a specified number.||
|**List: Add Left (Push)**|`LPUSH todolist "Call Dad"`|Adds an element to the left (head) of a list.||
|**List: Add Right (Push)**|`RPUSH todolist "Buy groceries"`|Adds an element to the right (tail) of a list.||
|**List: View All**|`LRANGE todolist 0 -1`|Fetches all elements from the list (from index 0 to the last index -1).||
|**List: Check Length**|`LLEN todolist`|Returns the length of the list.||
|**Sorted Set: Add Score**|`ZADD leaderboard 100 "player1" 200 "player2"`|Adds members with specified scores to a Sorted Set.||
|**Sorted Set: Increment**|`ZINCRBY leaderboard 500 "player1"`|Increases a player's score by 500.||
|**Sorted Set: Reverse Range**|`ZREVRANGE leaderboard 0 -1`|Returns all elements in descending score order.||

### Graph Databases (Neo4j/Cypher Query Language)

Neo4j uses Cypher to interact with its graph structure of nodes and relationships.

|Operation|Cypher Command Example|Description|Source|
|:--|:--|:--|:--|
|**Create Simple Node**|`CREATE (n:MOVIE{title:"Movie1"}) RETURN n`|Creates a node with label `MOVIE` and a property `title`.||
|**Create Node with Properties**|`Create (x: Book {title : “Database System”, author: “Navathe”}) return x;`|Properties are key:value pairs, separated by commas.||
|**Create Relationship**|`MATCH (a:PERSON), (b:MOVIE) WHERE a.name = "Person1" AND b.title = "Movie1" CREATE (a)-[:ACTED_IN]->(b) RETURN a,b`|Finds nodes by property and creates a directed relationship `ACTED_IN`.||
|**Return All Nodes**|`MATCH(n) return n`|Searches for (`MATCH`) and returns all nodes in the database.||
|**Search by Property/Filter**|`MATCH (n:Movie{title:'Top Gun'}) RETURN n`|Finds a specific node using the label and an inline property match.||
|**Search by Condition**|`MATCH (person:Person) WHERE person.name STARTS WITH 'An'`|Searches nodes where a property matches a string pattern.||
|**Update Property**|`MATCH (p:PERSON {name: "Person1"}) SET p.age = 54 RETURN p`|Selects a node and updates a property using the `SET` clause.||
|**Add Label**|`MATCH (p:PERSON {name: "Person1"}) SET p:ACTOR RETURN p`|Adds a new label to an existing node using the `SET` clause.||
|**Delete Node** (No relationships)|`MATCH (m:MOVIE {title: "Movie3"}) DELETE m`|Deletes a node (only if it has no relationships).||
|**Delete Node & Rels**|`MATCH (m:MOVIE {title: "Movie2"}) DETACH DELETE m`|Deletes the node and any associated relationships.||
|**Aggregate Count**|`RETURN director.name, COUNT(m)`|Returns the number of matched nodes (`m`) grouped by `director.name`.||

## Database Application Connectivity (Python/MySQL)

The sources detail Python interaction with a MySQL database using the `mysql-connector-python` library.

### Python Setup and Installation

|Function|Code/Command|Source|
|:--|:--|:--|
|**Installation**|`pip install mysql-connector-python`|Command needed to install the connector package.|
|**Execution**|`python filename.py` or `py filename.py`|Command used to run the saved Python file.|

### MySQL Statements (Used in Application Context)

|Operation|SQL Syntax Example|Context|Source|
|:--|:--|:--|:--|
|**Insert Data**|`INSERT INTO students (name, department) VALUES ('Alice Johnson', 'CSE'), ...;`|Inserting multiple rows into the `students` table.||
|**Update Data**|`UPDATE marks SET marks = 95 WHERE student_id = 1 AND subject_id = 1` (Conceptual SQL, parameterized in Python)|Used to modify existing data.||
|**Multi-Table Read (Report)**|`SELECT m.mark_id, s.name, sub.name, m.marks FROM marks m JOIN students s ON m.student_id = s.student_id JOIN subjects sub ON m.subject_id = sub.subject_id`|Complex query using multiple JOINs for a readable report.||

### Python Code Snippets (Executing CRUD Operations)

| Function                  | Python Code Snippet (or equivalent logic)                                                                                      | Source                                                                            |
| :------------------------ | :----------------------------------------------------------------------------------------------------------------------------- | :-------------------------------------------------------------------------------- |
| **Insert (Create)**       | `cursor.execute("INSERT INTO students (name, department) VALUES (%s, %s)", (name, dept))`                                      | Uses `%s` placeholders for parameterized input to prevent SQL injection.          |
| **Update**                | `cursor.execute("UPDATE marks SET marks = %s WHERE student_id = %s AND subject_id = %s", (new_marks, student_id, subject_id))` | Executes an update statement using parameterized inputs.                          |
| **Read (Execute Query)**  | `cursor.execute("SELECT * FROM students")`                                                                                     | Executes a selection query.                                                       |
| **Read (Fetch Results)**  | `for row in cursor.fetchall(): print(row)`                                                                                     | Fetches all results from the executed cursor.                                     |
| **Transaction Save**      | `conn.commit()`                                                                                                                | Necessary function call to save changes (Insert, Update, Delete) to the database. |
| **Delete (Handling FKs)** | `cursor.execute("DELETE FROM marks WHERE student_id = %s", (student_id,))`                                                     | Must delete dependent foreign key data first before deleting the primary record.  |

# Unit 1: Data Definition Language (DDL) and Constraints

| Topic/Feature                       | Description                                                                                 | Command/Syntax Example                                                                                                                   | Citation |
| :---------------------------------- | :------------------------------------------------------------------------------------------ | :--------------------------------------------------------------------------------------------------------------------------------------- | :------- |
| **Database/Schema Creation**        | Creates a new database/schema. In MySQL, `SCHEMA` and `DATABASE` are functionally the same. | `CREATE DATABASE db1;` <br> `USE db1;` <br> `CREATE SCHEMA Library;`                                                                     |          |
| **Table Creation (Basic)**          | Defines a new relation with attribute types and primary keys.                               | `CREATE TABLE students (`<br>`student_id INT AUTO_INCREMENT PRIMARY KEY,` <br>`name VARCHAR(100),` <br>`department VARCHAR(50)` <br>`);` |          |
| **Constraint: Primary Key**         | Defines the primary key for a relation.                                                     | `srn VARCHAR(10) PRIMARY KEY,` <br> `Dnumber INT PRIMARY KEY;`                                                                           |          |
| **Constraint: Foreign Key**         | Enforces referential integrity.                                                             | `FOREIGN KEY (dept_id) INT REFERENCES Department(dept_id);`                                                                              |          |
| **Constraint: Referential Actions** | Specifies the action the DBMS takes on foreign key violation (`ON DELETE`/`ON UPDATE`).     | Options include `SET NULL`, `CASCADE`, and `SET DEFAULT`. `CASCADE` is suitable for "relationship" relations.                            |          |
| **Constraint: Unique Key**          | Specifies alternate keys (Candidate keys) which must be unique.                             | `Dname VARCHAR(15) UNIQUE;`                                                                                                              |          |
| **Constraint: Check**               | Adds constraints on individual tuples to ensure logical integrity.                          | `CHECK (gpa <= 10)` <br> `CHECK (Dept_create_date <= Mgr_start_date);`                                                                   |          |
| **Alter Table (Add Col)**           | Adds a new column to an existing table.                                                     | `ALTER TABLE Student ADD email VARCHAR(50);`                                                                                             |          |
| **Alter Table (Rename Col)**        | Renames an existing column.                                                                 | `ALTER TABLE Student RENAME COLUMN email TO email_id;`                                                                                   |          |

## II. Data Manipulation Language (DML) and DQL

| Topic/Feature | Description | Command/Syntax Example | Citation |
| :--- | :--- | :--- | :--- |
| **Select (Basic DQL)** | Retrieves specific columns. | `SELECT Fname, Lname, email_id FROM Student;` | |
| **Select (Calculated Column)**| Calculates and renames an attribute. | `SELECT fname, salary/12 AS monthly_salary;` | |
| **Insert (Standard)** | Adds new data rows to a table. | `INSERT INTO ... VALUES (%s, %s)` (Used with application placeholders) | |
| **Insert (Using Subquery)** | Inserts results from a `SELECT` query. | `INSERT INTO WORKS_ON_INFO (Emp_name, Proj_name, Hours_week) SELECT E.Lname, P.Pname, W.Hours FROM Project P, WorksOn W, Employee E WHERE P.Pnumber = W.Pno AND W.Essn = E.ssn;` | |
| **Update (Basic DML)** | Modifies attribute values of selected tuples. | `UPDATE Student SET Fname = 'Pranavjeet', Lname = 'Naidu' WHERE srn LIKE '%CS123';` | |
| **Update (Using Subquery)** | Updates based on an aggregate result. | `UPDATE Employee SET Salary = Salary*1.05 WHERE salary < (SELECT AVG(salary) FROM Employee);` | |
| **Delete (DML)** | Removes tuples (rows) based on a `WHERE` clause. | `DELETE FROM Employee WHERE Lname = 'Kota';` | |
| **String Comparison** | Uses `LIKE` for pattern matching (`%` for any string, `_` for any single character). | `SELECT Fname, Lname, bdate FROM EMPLOYEE WHERE Bdate LIKE '196_ _ _ _ _ _ _';` (Finds employees born in 1960s) | |

# Unit 2: Advanced Query Constructs (Joins, Set, Aggregates)

| Topic/Feature | Description | Command/Syntax Example | Citation |
| :--- | :--- | :--- | :--- |
| **Inner Join** | Returns rows only when there is a match in both tables. | `SELECT l.Loan_ID, ... FROM Loan l JOIN Borrower b ON l.Loan_ID = b.Loan_ID;` | |
| **Natural Join** | Implicitly joins tables based on columns with the same name and datatype. | `SELECT col1, col2, col3 FROM table1 NATURAL JOIN table2;` | |
| **Right Outer Join** | Returns all rows from the right table, and matching rows from the left table. | `SELECT s.fname, s.lname, d.dept_name FROM Student AS s RIGHT JOIN Department AS d ON s.dept_id = d.dept_id;` | |
| **Cross Join** | Returns the Cartesian Product (all combinations) of rows from both tables. | `select * from loan cross join borrower;` | |
| **Union Operator** | Combines results from two or more `SELECT` statements, eliminating duplicates by default. | `SELECT col1 FROM table1 UNION SELECT col2 FROM table2` | |
| **Intersection Operator**| Returns tuples common to both queries (explicitly listed in cheatsheet). | `SELECT col1 FROM table1 INTERSECT SELECT col2 FROM table2` | |
| **Except Operator** | Returns tuples from the first query that are not present in the second query. | `SELECT col1 FROM table1 EXCEPT SELECT col2 FROM table2` | |
| **`ALL` Modifier (Set Ops)** | Used with set operations if duplicate tuples should not be removed. | `UNION ALL` | |
| **Aggregate Functions** | Used for calculations like sum, average, max, and count. | `SELECT SUM(salary), AVG(salary) MAX(salary), MIN(salary) FROM Employee;` | |
| **Grouping (`GROUP BY`)** | Groups output rows based on common column values. | `SELECT dno, COUNT(*), AVG(salary) FROM Employee GROUP BY dno;` | |
| **Group Filtering (`HAVING`)**| Filters grouped or aggregated results *after* the `GROUP BY` clause is applied. | `SELECT Category, COUNT(*) FROM Products GROUP BY Category HAVING COUNT(*) > 5;` | |
| **Null Check** | Checks if an attribute value is missing. | `SELECT Fname, Lname FROM EMPLOYEE WHERE Super_ssn IS NULL;` | |
| **Unknown Check** | Tests whether the result of a comparison is `UNKNOWN` (e.g., due to null values). | `SELECT Essn, Pno FROM WORKS_ON WHERE Hours > 10 IS UNKNOWN;` | |
| **Nested Subquery (Example)** | Finds project numbers managed by 'Smith' or worked on by 'Smith'. | `... Pnumber IN ( SELECT Pno FROM WORKS_ON, EMPLOYEE WHERE Essn = Ssn AND Lname = 'Smith' );` | |
| **Correlated Query (Equiv.)**| Example showing how a correlated query can be rewritten as a join. | `SELECT E.Fname, E.Lname FROM EMPLOYEE AS E, DEPENDENT AS D WHERE E.Ssn = D.Essn AND E.Gender = D.Gender;` | |
| **Semi-Join Concepts** | The operation (`S=`) to which modern SQL engines map `EXISTS`, `IN`, and `ANY` subqueries for efficiency. | `T1.X S = T2.Y` | |
| **Anti-Join Concepts** | The operation to which `NOT EXISTS` subqueries are mapped. | N/A (Internal operation, no explicit SQL syntax provided) | |

## Advanced Database Objects

| Topic/Feature                     | Description                                                                                                       | Command/Syntax Example                                                                                                                                                                     | Citation        |
| :-------------------------------- | :---------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------- |
| **View Creation**                 | Creates a virtual table (`CREATE VIEW`) based on a stored query.                                                  | `CREATE VIEW phy_fall_2017 AS SELECT course_id, sec_id, building, room_no, FROM course, section WHERE course.dept_name = "Physics" AND section.year = 2017;`                               |                 |
| **Common Table Expression (CTE)** | Defines a temporary, non-persistent result set using the `WITH` clause.                                           | `WITH Project_Counts AS (`<br> `SELECT e.Fname, COUNT(w.Pno) AS Proj_Count ... )` <br> `SELECT Fname, Proj_Count, ... FROM Project_Counts;`                                                |                 |
| **Recursive CTEs**                | Used for traversing hierarchical data structures, defined using `WITH RECURSIVE`.                                 | N/A (Keyword mentioned, no full code example)                                                                                                                                              |                 |
| **User-Defined Function (UDF)**   | Accepts parameters and returns a single value or table.                                                           | `CREATE FUNCTION no_of_years(date1 date) RETURNS INTEGER deterministic BEGIN ... RETURN year(date2)-year(date1); END`                                                                      |                 |
| **Stored Procedure**              | A pre-compiled collection of SQL statements acting as a subroutine, stored inside the database.                   | `DELIMITER $$`<br> `CREATE PROCEDURE procedure_name(IN parameter_name data_type) BEGIN` <br> `SELECT * FROM some_table WHERE column_name = parameter_name;` <br> `END$$`<br> `DELIMITER ;` |                 |
| **Trigger Definition Syntax**     | Defines a statement executed automatically based on a database modification event (`INSERT`, `UPDATE`, `DELETE`). | `DELIMITER $$`<br> `CREATE TRIGGER trigger_name FOR EACH ROW (AFTER                                                                                                                        | BEFORE) (INSERT |
| **Trigger Action (Example)**      | Defines a trigger that backs up old data before deletion.                                                         | `DELETE FROM Marks_sample WHERE SRN = 2;` (Execution causing the `BEFORE DELETE` trigger logic to run)                                                                                     |                 |
| **Window Function**               | Performs calculations across a set of table rows related to the current row (e.g., partitioning).                 | `window_function(col2) OVER ([PARTITION BY col1]) AS newcol FROM table1` <br> `AVG(salary) OVER (PARTITION BY department) AS dept_avg_salary FROM Employee;`                               |                 |
| **Full Text Search (Boolean)**    | Matches specified search terms using modifiers like `+` (include).                                                | `SELECT * FROM products WHERE MATCH(prod_name, description) AGAINST('smartphone' IN BOOLEAN MODE)`                                                                                         |                 |
| **Full Text Search (Natural)**    | Ranks and retrieves results based on relevance score.                                                             | `SELECT *, MATCH(title, description) AGAINST('MySQL' IN NATURAL LANGUAGE MODE) AS score FROM articles ...`                                                                                 |                 |

Is there a specific advanced feature, such as working with triggers or demonstrating recursive CTE logic, that you would like to test yourself on next?

# Unit 3: Design Concepts and Implementation

## Query Processing and Optimization

### Relational Algebra Notation (Operators)

Relational algebra is a **procedural language** where operations take relations as input and produce a new relation as output.

|Operation|Notation|Description / Usage|Source|
|:--|:--|:--|:--|
|**Select** (Row Filter)|$\sigma_p(r)$|Chooses a subset of tuples ($r$) satisfying a predicate ($p$).||
|**Project** (Column Selector)|$\prod_{A_1, \ldots, A_k}(r)$|Returns the relation ($r$) with only the specified attributes ($A_i$).||
|**Join**|$\bowtie_{condition}$|Combines two relations based on a join condition. Often replaces the combination of Cartesian Product ($\times$) and Select ($\sigma$) during optimization.||
|**Cartesian Product**|$\times$|Combines every tuple from the first relation with every tuple from the second relation.||

### SQL and Relational Algebra Translation/Optimization Examples

Query processing translates high-level SQL into low-level operations. Optimization involves rearranging these operations, often shown in query trees.

|Query Translation / Optimization Step|Example Syntax / Notation|Source|
|:--|:--|:--|
|**Complex Nested SQL Query**|`SELECT Lname, Fname FROM EMPLOYEE WHERE Salary > (SELECT MAX (Salary) FROM EMPLOYEE WHERE Dno=5);`||
|**RA Translation (Inner Block)**|$\Im_{MAX \ Salary}(\sigma_{Dno=5}(EMPLOYEE))$||
|**RA Translation (Outer Block)**|$\pi_{Lname, Fname}(\sigma_{Salary>c}(EMPLOYEE))$||
|**RA Expression (Complex Join)**|$\Pi_{Pnumber, Dnum, Lname, Address, Bdate}(((((\sigma_{Plocation = 'Stanford'}(PROJECT)) \bowtie_{Dnum=Dnumber}(DEPARTMENT)) \bowtie_{Mgr_ssn=Ssn}(EMPLOYEE)))$||
|**Heuristic Optimization (Moving SELECT down)**|Starting with a canonical tree that applies all conditions at once, optimization moves selection operations, like $\sigma_{Plocation = 'Stanford'}$ on `PROJECT`, down to reduce intermediate result size.||
|**Heuristic Optimization (Replacing Cartesian Product)**|Replacing implicit Cartesian Products and selection conditions with explicit JOIN operations ($\bowtie$).||

### Extended SQL Operators and Constructs

|Operator/Mode|Usage Context|Source|
|:--|:--|:--|
|**Set Operators**|`UNION`, `UNION ALL`, `INTERSECT`, `EXCEPT`.||
|**Set Comparison Modifiers**|`comp_op ALL`, `comp_op SOME` (or `ANY`).||
|**Existence Checks**|`EXISTS` and `NOT EXISTS` (used, typically with **correlated nested queries**).||
|**Stored Procedures**|Defined by specifying parameters (IN, OUT, or INOUT).||
|**User-Defined Function (UDF)**|Must return a single value or table.||
|**Triggers**|Definition involves specifying the **Event** (`INSERT`, `UPDATE`, `DELETE`), **Time** (`BEFORE` or `AFTER`), condition, and action.||
|**Full-Text Search (Boolean Mode)**|Allows logical operators: `+`, `-`, `"`, `*` for complex search criteria.||

## Functional Dependencies (FDs) and Normalization

### Functional Dependency Notation (FD) and Closure

|Notation/Concept|Example|Description|Source|
|:--|:--|:--|:--|
|**Functional Dependency**|$X \rightarrow Y$ (e.g., $A \rightarrow B$, $BC \rightarrow D$)|$X$ determines $Y$.||
|**Closure**|$A^+$ or ${B, C}^+$|The set of all attributes functionally determined by $A$ or ${B, C}$.||
|**Multivalued Dependency (MVD)**|$X \rightarrow \rightarrow Y$|An MVD exists on schema R. A trivial MVD exists if $Y$ is a subset of $X$, or $X \cup Y = R$.||

### Numerical Derivation Steps (Inference Rules)

Inference rules (like Armstrong's Axioms) are used to derive new FDs:

|Inference Rule|Example Step/Usage|Source|
|:--|:--|:--|
|**Augmentation**|Given $A \rightarrow B$, we derive **$AC \rightarrow BC$** (by augmenting both sides with $C$).||
|**Transitivity**|Given $AC \rightarrow BC$ and $BC \rightarrow D$, we derive **$AC \rightarrow D$**.||
|**Union**|Given $AB \rightarrow G$ and $AB \rightarrow I$, we derive **$AB \rightarrow GI$**.||
|**Decomposition**|Given $AD \rightarrow EF$, we derive **$AD \rightarrow F$**.||

### Numerical Examples for Closure Calculation

- **Closure Example 1**: Given $F = {A \rightarrow B, BC \rightarrow DE, AEG \rightarrow G}$ on $R(A, B, C, D, E, F, G)$.
    - $A^+ = {A, B}$.
    - $AC^+ = {A, C, B, D, E}$.
    - $ADE^+ = {A, D, E, B}$.
- **Closure Example 2**: Given $F = {BC \rightarrow DE, D \rightarrow F, CF \rightarrow G}$.
    - ${B, C}^+ = {B, C, D, E, F, G}$.

### Numerical Examples for Normalization (BCNF Decomposition)

When decomposing a relation $R$ based on an FD $C \rightarrow DE$ where $C$ is not a Candidate Key (CK):

|Relation|FD Set|Candidate Key|Decomposition Example|Source|
|:--|:--|:--|:--|:--|
|$R(A, B, C, D, E)$|$A \rightarrow BC$, $C \rightarrow DE$|$A$|Decomposition results in: $R_1(A, BC)$ and $R_2(C, D, E)$.||

---

# Unit 4: Transactions, Concurrency, NoSQL, and Modern Databases

## Database Transactions and Concurrency

### Transaction Control (MySQL Syntax)

|Operation|SQL Command Example|Context|Source|
|:--|:--|:--|:--|
|**Set Isolation Level**|`SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE;`|Sets the isolation policy for the current session.||
|**Start Transaction**|`START TRANSACTION;`|Marks the beginning of a sequence of operations that must be atomic.||
|**Commit**|`COMMIT;`|Saves all changes made by the transaction permanently to the database.||
|**Rollback**|`ROLLBACK;`|Undoes changes made by the transaction, typically triggered by an error.||
|**Verify Isolation Level**|`SELECT @@transaction_isolation;`|Used to check the current isolation level setting.||

### Conflict Serializability Notation

Conflict serializability relies on identifying conflicting operations between transactions $T_i$ and $T_j$ on data item $Q$.

|Conflict Type|Notation (where $i \neq j$)|Conflict Status|Source|
|:--|:--|:--|:--|
|Read-Read|$R_i(Q), R_j(Q)$|**No Conflict**||
|Read-Write|$R_i(Q), W_j(Q)$|**Conflict**||
|Write-Read|$W_i(Q), R_j(Q)$|**Conflict**||
|Write-Write|$W_i(Q), W_j(Q)$|**Conflict**||

The presence of a **cycle** in the resulting precedence graph means the schedule is **not conflict serializable**.

## NoSQL Databases

### Key-Value Database (Redis) Commands

Redis commands operate on simple key-value pairs or specialized data structures (like Lists or Sorted Sets).

|Category|Command Example|Function|Source|
|:--|:--|:--|:--|
|**Basic String Get**|`GET user:1:name`|Gets the value associated with a key.||
|**Basic String Multi-Set**|`MSET user:1:name "Alice" user:2:name "Bob"`|Sets multiple key-value pairs atomically.||
|**Atomic Increment**|`INCR page:views`|Increments the integer value of a key by one.||
|**Increment by N**|`DECRBY items:in_stock 5`|Decrements the integer value by a specified number.||
|**List: Add Left (Push)**|`LPUSH todolist "Call Dad"`|Adds an element to the left (head) of a list.||
|**List: Add Right (Push)**|`RPUSH todolist "Buy groceries"`|Adds an element to the right (tail) of a list.||
|**List: View All**|`LRANGE todolist 0 -1`|Fetches all elements from the list (from index 0 to the last index -1).||
|**List: Check Length**|`LLEN todolist`|Returns the length of the list.||
|**Sorted Set: Add Score**|`ZADD leaderboard 100 "player1" 200 "player2"`|Adds members with specified scores to a Sorted Set.||
|**Sorted Set: Increment**|`ZINCRBY leaderboard 500 "player1"`|Increases a player's score by 500.||
|**Sorted Set: Reverse Range**|`ZREVRANGE leaderboard 0 -1`|Returns all elements in descending score order.||

### Graph Databases (Neo4j/Cypher Query Language)

Neo4j uses Cypher to interact with its graph structure of nodes and relationships.

|Operation|Cypher Command Example|Description|Source|
|:--|:--|:--|:--|
|**Create Simple Node**|`CREATE (n:MOVIE{title:"Movie1"}) RETURN n`|Creates a node with label `MOVIE` and a property `title`.||
|**Create Node with Properties**|`Create (x: Book {title : “Database System”, author: “Navathe”}) return x;`|Properties are key:value pairs, separated by commas.||
|**Create Relationship**|`MATCH (a:PERSON), (b:MOVIE) WHERE a.name = "Person1" AND b.title = "Movie1" CREATE (a)-[:ACTED_IN]->(b) RETURN a,b`|Finds nodes by property and creates a directed relationship `ACTED_IN`.||
|**Return All Nodes**|`MATCH(n) return n`|Searches for (`MATCH`) and returns all nodes in the database.||
|**Search by Property/Filter**|`MATCH (n:Movie{title:'Top Gun'}) RETURN n`|Finds a specific node using the label and an inline property match.||
|**Search by Condition**|`MATCH (person:Person) WHERE person.name STARTS WITH 'An'`|Searches nodes where a property matches a string pattern.||
|**Update Property**|`MATCH (p:PERSON {name: "Person1"}) SET p.age = 54 RETURN p`|Selects a node and updates a property using the `SET` clause.||
|**Add Label**|`MATCH (p:PERSON {name: "Person1"}) SET p:ACTOR RETURN p`|Adds a new label to an existing node using the `SET` clause.||
|**Delete Node** (No relationships)|`MATCH (m:MOVIE {title: "Movie3"}) DELETE m`|Deletes a node (only if it has no relationships).||
|**Delete Node & Rels**|`MATCH (m:MOVIE {title: "Movie2"}) DETACH DELETE m`|Deletes the node and any associated relationships.||
|**Aggregate Count**|`RETURN director.name, COUNT(m)`|Returns the number of matched nodes (`m`) grouped by `director.name`.||

## Database Application Connectivity (Python/MySQL)

The sources detail Python interaction with a MySQL database using the `mysql-connector-python` library.

### Python Setup and Installation

|Function|Code/Command|Source|
|:--|:--|:--|
|**Installation**|`pip install mysql-connector-python`|Command needed to install the connector package.|
|**Execution**|`python filename.py` or `py filename.py`|Command used to run the saved Python file.|

### MySQL Statements (Used in Application Context)

|Operation|SQL Syntax Example|Context|Source|
|:--|:--|:--|:--|
|**Insert Data**|`INSERT INTO students (name, department) VALUES ('Alice Johnson', 'CSE'), ...;`|Inserting multiple rows into the `students` table.||
|**Update Data**|`UPDATE marks SET marks = 95 WHERE student_id = 1 AND subject_id = 1` (Conceptual SQL, parameterized in Python)|Used to modify existing data.||
|**Multi-Table Read (Report)**|`SELECT m.mark_id, s.name, sub.name, m.marks FROM marks m JOIN students s ON m.student_id = s.student_id JOIN subjects sub ON m.subject_id = sub.subject_id`|Complex query using multiple JOINs for a readable report.||

### Python Code Snippets (Executing CRUD Operations)

| Function                  | Python Code Snippet (or equivalent logic)                                                                                      | Source                                                                            |
| :------------------------ | :----------------------------------------------------------------------------------------------------------------------------- | :-------------------------------------------------------------------------------- |
| **Insert (Create)**       | `cursor.execute("INSERT INTO students (name, department) VALUES (%s, %s)", (name, dept))`                                      | Uses `%s` placeholders for parameterized input to prevent SQL injection.          |
| **Update**                | `cursor.execute("UPDATE marks SET marks = %s WHERE student_id = %s AND subject_id = %s", (new_marks, student_id, subject_id))` | Executes an update statement using parameterized inputs.                          |
| **Read (Execute Query)**  | `cursor.execute("SELECT * FROM students")`                                                                                     | Executes a selection query.                                                       |
| **Read (Fetch Results)**  | `for row in cursor.fetchall(): print(row)`                                                                                     | Fetches all results from the executed cursor.                                     |
| **Transaction Save**      | `conn.commit()`                                                                                                                | Necessary function call to save changes (Insert, Update, Delete) to the database. |
| **Delete (Handling FKs)** | `cursor.execute("DELETE FROM marks WHERE student_id = %s", (student_id,))`                                                     | Must delete dependent foreign key data first before deleting the primary record.  |