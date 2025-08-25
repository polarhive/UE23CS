# Schema

Databases change over time as information is added/deleted/modified

The collection of information stored in the db at a particular time is called instance of the database.

- Schema: variable declarations along with the associated type definitions
- Instances: Value of the variable at a particular point in time in the program

## 3 tier architecture

> It's also called snapshot or db state. Also called current set of occurrences/instances. Many database states can correspond to a particular database schema.

## State v/s Schema

- When we define a new db we specify its db schema only to the dbms
- This point, its empty and no data.
- When we get the first population its called **initial state**
- There on, eery time an `UPDATE` is applied, we get another database state.

![[Screenshot 2025-08-21 at 12.04.06.png]]
