var express = require('express');
var app = express();

// Root route with basic request info
app.get("/", function (request, response) {
    // Send a basic message
    // response.send("Welcome to Express js");

    // Send request method info
    // response.send("Welcome to Express js " + request.method);

    // Send original URL
    // response.send("Welcome to Express js " + request.originalUrl);

    // Send path of the request
    response.send("Welcome to Express js " + request.path);
});

// '/hello' route
app.get("/hello", function (request, response) {
    response.send("Welcome to my domain");
});

// '/hello/:name' route with dynamic 'name' parameter
app.get("/hello/:name", function (request, response) {
    response.send("Welcome to my home page " + request.params.name);
});

// Server listening on port 3000
app.listen(3000, function () {
    console.log("Server is running on http://localhost:3000");
});
