const express = require("express");
const MongoClient = require("mongodb").MongoClient;
const app = express();
var bodyParser = require('body-parser');
app.use(bodyParser.json());
const url = "mongodb://127.0.0.1:27017";

// Welcome message
app.get("/", (req, res) => {
    res.send("Welcome to the Express-MongoDB Example!");
});

// GET endpoint to retrieve employees based on query parameters
app.get("/student", (req, res) => {
    MongoClient.connect(url)
        .then((connectedClient) => {
            client = connectedClient
        })
        .then(() => {
            let result
            const collection = client.db("university").collection("student")
            return collection.find(req.query).toArray(result)
        })
        .then((result) => {
            console.log((result));
            res.send(result);

        })
        .catch((err) => {
            console.log(err)

        })
})
app.get("/student/:id", (req, res) => {
    MongoClient.connect(url)
        .then((connectedClient) => {
            client = connectedClient
        })
        .then(() => {
            let result
            const collection = client.db("university").collection("student")
            console.log("SRN", +req.params.id)
            return collection.findOne({ srn: req.params.id });
        })
        .then((result) => {
            console.log((result));
            res.send(result);

        })
        .catch((err) => {
            console.log(err)

        })
})
app.post("/student", (req, res) => {

    MongoClient.connect(url)
        .then((connectedClient) => {
            client = connectedClient
        })
        .then(() => {
            let result
            const collection = client.db("university").collection("student");
            console.log(req.body);
            return collection.insertOne(req.body);
        })
        .then((result) => {
            console.log((result));
            res.send(result);

        })
        .catch((err) => {
            console.log(err)

        })
})
app.put("/student/:sid", (req, res) => {

    MongoClient.connect(url)
        .then((connectedClient) => {
            client = connectedClient
        })
        .then(() => {
            let result
            const collection = client.db("university").collection("student");
            console.log(req.body);
            return collection.updateOne({ srn: req.params.sid }, req.body);
        })
        .then((result) => {
            console.log((result));
            res.send(result);

        })
        .catch((err) => {
            console.log(err)

        })
})
app.delete("/student/:sid", (req, res) => {

    MongoClient.connect(url)
        .then((connectedClient) => {
            client = connectedClient
        })
        .then(() => {
            let result
            const collection = client.db("university").collection("student");
            console.log(req.body);
            return collection.deleteOne({ srn: req.params.sid });
        })
        .then((result) => {
            console.log((result));
            res.send(result);

        })
        .catch((err) => {
            console.log(err)

        })
})
app.listen(3000, () => {
    console.log("Server listening on port 3000...");
});

//Client Side for GET Request
/* http://localhost:3000/
 http://localhost:3000/student
 http://localhost:3000/student/102
 http://localhost:3000/student/?dept=cse
 http://localhost:3000/student/?dept=cse&&Hostel=Yes
 */
