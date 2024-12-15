// Combined CRUD Operations using MongoDB and Express
const { MongoClient } = require('mongodb');
const express = require('express');
var app = express();

// MongoDB Connection URL
const url = "mongodb://127.0.0.1:27017";
let client;

// Create a new database or use an existing one
MongoClient.connect(url)
  .then((connectedClient) => {
    client = connectedClient;
    const dbo = client.db("university");
    console.log("Connected to MongoDB");

    // Create Collection
    dbo.createCollection("student")
      .then((res) => {
        console.log("Collection Created");

        // Insert One Document
        const data = { name: "Janani", srn: "103" };
        const collection = dbo.collection("student");
        return collection.insertOne(data);
      })
      .then((res) => {
        console.log("1 document inserted");

        // Fetch all student records
        return dbo.collection("student").find().toArray();
      })
      .then((students) => {
        console.log("All students:", students);
        
        // Update a document
        const myquery = { name: "Janani" };
        const newvalue = { $set: { name: "Krishna", age: 21 } };
        return dbo.collection("student").updateOne(myquery, newvalue);
      })
      .then((res) => {
        console.log("Document updated");

        // Delete a document
        const deleteQuery = { name: "Krishna" };
        return dbo.collection("student").deleteOne(deleteQuery);
      })
      .then((res) => {
        console.log("Document deleted");

        // Drop collection
        return dbo.collection("student").drop();
      })
      .then((res) => {
        console.log("Collection dropped");
        client.close();
      })
      .catch((err) => {
        console.error("Error occurred", err);
        client.close();
      });
  })
  .catch((err) => {
    console.error("Error connecting to MongoDB", err);
  });

// Express Server Handling Routes
app.get("/", function(request, response) {
    response.send("Welcome to Express js " + request.path);
});

app.get("/hello", function(request, response) {
    response.send("Welcome to my domain");
});

app.get("/hello/:name", function(request, response) {
    response.send("Welcome to my home page " + request.params.name);
});

app.get("/student/:id", function(req, res, next) {
    if (req.params.id.indexOf("2000") != -1) {
        var err = new Error("Something went Wrong!!!");
        next(err); // Pass error to next middleware
    } else {
        res.send("Everything is fine with " + req.params.id);
        next();
    }
});

app.use("/student", function(req, res) {
    console.log("I am Fine");
});

app.listen(3000, function() {
    console.log("Express server running on port 3000");
});
