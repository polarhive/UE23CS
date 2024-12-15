// Importing required modules
var http = require('http');
var url = require('url');
var fs = require('fs');
var qs = require('querystring');
var MongoClient = require('mongodb').MongoClient;

// GET Request: Fetching data from MongoDB and sending as JSON response
http.createServer(function (request, response) {
    if (request.method == 'GET') {
        var myurl = url.parse(request.url);
        const url1 = 'mongodb://127.0.0.1:27017';

        MongoClient.connect(url1)
            .then((connectedClient) => {
                client = connectedClient;
                const collection = client.db("university").collection("student");
                return collection.find().toArray(); // Fetch all documents from the 'student' collection
            })
            .then((result) => {
                response.writeHead(200, { 'Content-type': 'application/json' });
                response.write(JSON.stringify(result)); // Send result as JSON response
                client.close();
                response.end();
            })
            .catch((err) => {
                console.log(err);
                response.writeHead(500, { 'Content-type': 'text/plain' });
                response.write("Error connecting to MongoDB");
                response.end();
            });
    }
}).listen(8080);

console.log("GET Server is up and running on http://localhost:8080");

// GET Client: Fetching data from the GET server and logging to the console
var fetch = require('node-fetch');
fetch('http://localhost:8080')
    .then((res) => res.text())
    .then((text) => console.log('Fetched Data:', text))
    .catch((err) => console.error('Error fetching data:', err));


// POST Request: Inserting new data into MongoDB
http.createServer(function (request, response) {
    if (request.method == 'POST') {
        var myurl = url.parse(request.url);
        var query = myurl.query;
        var qobj = qs.parse(query);

        let body = [];
        request.on('data', (chunk) => {
            body.push(chunk);
        })
            .on('end', () => {
                body = Buffer.concat(body).toString(); // Combine data chunks
                console.log("Received POST data:", body);

                const { MongoClient } = require('mongodb');
                const url1 = "mongodb://127.0.0.1:27017";
                let client;

                MongoClient.connect(url1)
                    .then((connectedClient) => {
                        client = connectedClient;
                        const collection = client.db("university").collection("student");
                        return collection.insertOne(JSON.parse(body)); // Insert received data into MongoDB
                    })
                    .then((result) => {
                        console.log("1 document inserted");
                        response.writeHead(200, { 'Content-type': 'application/json' });
                        response.write(JSON.stringify(result)); // Send insert result as response
                        client.close();
                        response.end();
                    })
                    .catch((err) => {
                        console.error("An error occurred:", err);
                        response.writeHead(500, { 'Content-type': 'text/plain' });
                        response.write("Error inserting data into MongoDB");
                        response.end();
                    });
            });
    }
}).listen(8080);

console.log("POST Server is up and running on http://localhost:8080");

// POST Client: Sending data to the POST server
fetch('http://127.0.0.1:8080', {
    method: 'POST',
    headers: { 'Content-type': 'application/json' },
    body: JSON.stringify({ "name": "Krishna", "email": "xyz@gmail.com" }) // Data to be inserted into MongoDB
})
    .then((res) => res.text())
    .then((text) => console.log('Response from POST:', text))
    .catch((err) => console.error('Error posting data:', err));
