# MongoDB and ExpressJS

To create a database in MongoDB, start by creating a MongoClient object, then

specify a connection URL with the correct ip address and the name of the database.

MongoDB will create the database if it does not exist, and make a connection to it

> Creating a Collection

- To create a collection in MongoDB, use the Collection() method
- In MongoDB, a collection is not created until it gets content.

> Insert a single document Into Collection

- To insert a record, or document as it is called in MongoDB, into a collection, use the insertOne() method.
- A document in MongoDB is the same as a record in MySQL
- The first parameter of the insertOne() method is an object containing the name(s) and value(s) of each field in the document you want to insert.
- It also takes a callback function where you can work with any errors, or the result of the insertion

> Select the documents from collection:

- In MongoDB use the find and findOne methods to find data in a collection.
- Just like the SELECT statement is used to find data in a table in a MySQL database.

> Find:

- To select data from a table in MongoDB, we can also use the find() method.
- The find() method returns all occurrences in the selection.
- The first parameter of the find() method is a query object