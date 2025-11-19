# SQL Lab 10: Neo4j

## Part A: Create Nodes

1. Create Student Nodes

```
CREATE
  (a:Student {name: "Alice", age: 21, major: "CSE"}),
  (b:Student {name: "Bob", age: 22, major: "ECE"}),
  (c:Student {name: "Charlie", age: 20, major: "CSE"})
```

![[Screenshot 2025-10-28 at 14.32.35.png]]

2. Create Professor Nodes

```
CREATE
  (s:Professor {name: "Dr. Smith", department: "CSE"}),
  (j:Professor {name: "Dr. Jones", department: "ECE"})
```

![[Screenshot 2025-10-28 at 14.33.14.png]]

3. Create Course Nodes

```
CREATE
  (cs:Course {code: "CS101", title: "DATA STRUCTURES"}),
  (ec:Course {code: "EC202", title: "DIGITAL SYSTEMS"})
```

![[Screenshot 2025-10-28 at 14.33.31.png]]

## Part B: Create Relationships

4. Enroll Students in Courses

```
MATCH (a:Student {name: "Alice"}), (cs:Course {code: "CS101"})
CREATE (a)-[:ENROLLED_IN]->(cs);

MATCH (b:Student {name: "Bob"}), (ec:Course {code: "EC202"})
CREATE (b)-[:ENROLLED_IN]->(ec);

MATCH (c:Student {name: "Charlie"}), (cs:Course {code: "CS101"})
CREATE (c)-[:ENROLLED_IN]->(cs);
```

![[Screenshot 2025-10-28 at 14.34.58.png]]

5. Assign Professors to Courses

```
MATCH (s:Professor {name: "Dr. Smith"}), (cs:Course {code: "CS101"})
CREATE (s)-[:TEACHES]->(cs);

MATCH (j:Professor {name: "Dr. Jones"}), (ec:Course {code: "EC202"})
CREATE (j)-[:TEACHES]->(ec);
```

![[Screenshot 2025-10-28 at 14.35.15.png]]

![[Screenshot 2025-10-28 at 14.35.35.png]]

6. Create Friendship

```
MATCH (a:Student {name: "Alice"}), (c:Student {name: "Charlie"})
CREATE (a)-[:FRIENDS_WITH]->(c)
```

![[Screenshot 2025-10-28 at 14.35.47.png]]

## Part C: Query the Graph

7. List All Students

```
MATCH (s:Student)
RETURN s
```

![[Pasted image 20251028145245.png]]

8. Find Courses Taught by Dr. Smith

```
MATCH (p:Professor {name: "Dr. Smith"})-[:TEACHES]->(c:Course)
RETURN c.title, c.code
```

![[Pasted image 20251028145231.png]]

9. Find Friends of Charlie

```
MATCH (c:Student {name: "Charlie"})-[:FRIENDS_WITH]-(friend:Student)
RETURN friend.name
```

![[Pasted image 20251028145224.png]]

10. List Students in the Same Course

```
MATCH (s:Student)-[:ENROLLED_IN]->(c:Course)
RETURN c.title AS Course, collect(s.name) AS Students
```

![[Screenshot 2025-10-28 at 14.51.37.png]]

11. Find Professors Who Teach Alice's Courses

```
MATCH (a:Student {name: "Alice"})-[:ENROLLED_IN]->(c:Course)<-[:TEACHES]-(p:Professor)
RETURN p.name, c.title
```

![[Screenshot 2025-10-28 at 14.51.19.png]]

12. Find Friends Enrolled in the Same Course

```
MATCH (s1:Student)-[:FRIENDS_WITH]-(s2:Student),
      (s1)-[:ENROLLED_IN]->(c:Course)<-[:ENROLLED_IN]-(s2:Student)
WHERE id(s1) < id(s2) // Prevents duplicate pairs
RETURN s1.name, s2.name, c.title
```

![[Pasted image 20251028144939.png]]

13. Find Courses with More Than One Student

```
MATCH (s:Student)-[:ENROLLED_IN]->(c:Course)
WITH c, count(s) AS studentCount
WHERE studentCount > 1
RETURN c.title, studentCount
```

![[Screenshot 2025-10-28 at 14.49.20.png]]

## Bonus Query

14. Count Students Per Professor

```
MATCH (p:Professor)-[:TEACHES]->(c:Course)<-[:ENROLLED_IN]-(s:Student)
RETURN p.name AS Professor, count(DISTINCT s) AS NumberOfStudents
```

![[Screenshot 2025-10-28 at 14.48.51.png]]
