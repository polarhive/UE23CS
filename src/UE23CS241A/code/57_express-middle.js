// Example 1: Static File Serving with express.static

var express = require('express');
var path = require('path');

var app = express();

// Serve static files from the "Folder" directory
app.use(express.static(path.join(__dirname, 'Folder')));

// Listen on port 8080
app.listen(8080, function () {
    console.log("Server is running on port 8080");
});


// Example 2: Middleware with multiple static directories

var express = require('express');
var path = require('path');
var app = express();

// Serve static files from the "public" and "Images" directories
app.use(express.static('public'));
app.use(express.static('Images'));

// Middleware for logging or other tasks can be added here

app.listen(3000, function () {
    console.log("Server is listening on port 3000");
});


// Example 3: Using Middleware in Express

var express = require('express');
var app = express();

// Middleware to log requests
app.use(function (req, res, next) {
    console.log("First MW Function");
    next(); // Move to the next middleware or route
});

// Route middleware - Middleware for a specific route ("/")
app.use("/", function (req, res, next) {
    console.log("Route MW Function 1");
    next();
});

app.use("/", function (req, res, next) {
    console.log("Route MW Function 2");
    next();
});

// Route middleware - Send a response
app.use("/", function (req, res, next) {
    console.log("Route Function");
    res.send("Welcome to my page!!!");
    next(); // It will not proceed to next middleware after this point because response is already sent.
});

// Middleware - This will not be called since the response is sent above
app.use("/", function (req, res, next) {
    console.log("Route MW Function 3");
    next();
});

// Last middleware (will be executed after route is processed if no response is sent earlier)
app.use(function (req, res) {
    console.log("Last MW Function");
});

// Start the server on port 3000
app.listen(3000, function () {
    console.log("Server is running on port 3000");
});
