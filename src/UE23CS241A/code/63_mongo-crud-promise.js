// Create Database
const { MongoClient } = require('mongodb');
const url = "mongodb://127.0.0.1:27017/university";

MongoClient.connect(url)
    .then((db) => {
        console.log("Database is created");
        db.close();
    })
    .catch((err) => {
        console.log("An Error Occurred", err);
    });


// Create Collection
const { MongoClient } = require('mongodb');
const url1 = "mongodb://127.0.0.1:27017";
let client;

MongoClient.connect(url1)
    .then((connectedClient) => {
        client = connectedClient;
        const dbo = client.db("university");
        return dbo.createCollection("student");
    })
    .then((res) => {
        console.log("Collection Created");
        client.close();
    })
    .catch((err) => {
        console.error("Error occurred", err);
    });


// Insert One
const { MongoClient } = require('mongodb');
const url2 = "mongodb://127.0.0.1:27017";
let client2;

MongoClient.connect(url2)
    .then((connectedClient) => {
        client2 = connectedClient;
        const dbo = client2.db("university");
        const data = { name: "Janani", srn: "103" };
        const collection = client2.db("university").collection("student");
        return collection.insertOne(data);
    })
    .then((res) => {
        console.log("1 document inserted");
        client2.close();
    })
    .catch((err) => {
        console.error("Error occurred", err);
    });


// Insert Many
const { MongoClient } = require('mongodb');
const url3 = "mongodb://127.0.0.1:27017";
let client3;

MongoClient.connect(url3)
    .then((connectedClient) => {
        client3 = connectedClient;
        const dbo = client3.db("university");
        const data = [
            { name: "Ayush", srn: "104" },
            { name: "Ajay", srn: "105" }
        ];
        const collection = client3.db("university").collection("student");
        return collection.insertMany(data);
    })
    .then((res) => {
        console.log(`${res.insertedCount} documents inserted`);
        client3.close();
    })
    .catch((err) => {
        console.error("Error occurred", err);
    });


// Find (Retrieve documents)
const { MongoClient } = require('mongodb');
const url4 = "mongodb://127.0.0.1:27017";

let client4;

MongoClient.connect(url4)
    .then((connectedClient) => {
        let result;
        client4 = connectedClient;
        const dbo = client4.db("university");
        const collection = client4.db("university").collection("student");
        return collection.find({}, { projection: { _id: 0, name: 1 } }).toArray(result);
    })
    .then((res) => {
        console.log("Document fetched");
        console.log(JSON.stringify(res));
    })
    .catch((err) => {
        console.error("An error occurred:", err);
    });


// Update One
const { MongoClient } = require('mongodb');
const url5 = "mongodb://127.0.0.1:27017";
let client5;

MongoClient.connect(url5)
    .then((connectedClient) => {
        client5 = connectedClient;
        const dbo = client5.db("university");
        var myquery = { name: "Ajay" };
        var newvalue = { $set: { name: "Krishna", age: 21 } };
        return dbo.collection("student").updateOne(myquery, newvalue);
    })
    .then((res) => {
        console.log("Document updated");
        console.log(JSON.stringify(res));
    })
    .catch((err) => {
        console.error("Error occurred", err);
    });


// Drop Document (Delete One)
const { MongoClient } = require('mongodb');
const url6 = "mongodb://127.0.0.1:27017";
let client6;

MongoClient.connect(url6)
    .then((connectedClient) => {
        client6 = connectedClient;
        const dbo = client6.db("university");
        var myquery = { name: "Ayush" };
        return dbo.collection("student").deleteOne(myquery);
    })
    .then((res) => {
        console.log("Document deleted");
        client6.close();
    })
    .catch((err) => {
        console.error("Error occurred", err);
    });


// Drop Collection
const { MongoClient } = require('mongodb');
const url7 = "mongodb://127.0.0.1:27017";
let client7;

MongoClient.connect(url7)
    .then((connectedClient) => {
        client7 = connectedClient;
        const dbo = client7.db("university");
        return dbo.collection("student").drop();
    })
    .then((res) => {
        if (res) {
            console.log("Collection deleted");
        }
        client7.close();
    })
    .catch((err) => {
        console.error("Error occurred", err);
    });
