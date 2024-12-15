// Importing express
var express = require("express");
var app = express();

// Create a router for handling `/hello` routes
var router = express.Router();

// Define GET route for `/hello`
router.get("/", function (req, res, next) {
    res.send("First Function");
    next();  // Continue to the next middleware
});

// Define another GET route for `/hello`
router.get("/", function (req, res) {
    console.log("Second Function");
    res.send("Second Function Executed");
});

// Dynamic route for `/hello/:msg`
router.get("/:msg", function (req, res) {
    res.send("Hi there, Greetings " + req.params.msg);
});

// POST route to handle saving greeting message
router.post("/", function (req, res) {
    res.send("Hello Greeting Message saved");
});

// PUT route to handle updating greeting message
router.put("/", function (req, res) {
    res.send("Hello Greeting Message updated");
});

// DELETE route to handle deleting greeting message
router.delete("/", function (req, res) {
    res.send("Hello Greeting Message deleted");
});

// Export the router
module.exports = router;

// Main server setup to use the `/hello` router

var app = express();

// Root route
app.get("/", function (req, res) {
    res.send("Welcome to my Page");
});

// Use the `hello` router for `/hello` paths
var hellorouter = require("./hello.js"); // The path where the above router is saved
app.use("/hello", hellorouter);

// Server listening on port 3000
app.listen(3000, function () {
    console.log("Server Listening on 3000");
});
