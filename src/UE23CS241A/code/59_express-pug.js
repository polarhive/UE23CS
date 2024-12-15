// Required Modules
var express = require('express');
var bodyParser = require('body-parser');

// Initialize Express app
var app = express();

// Pug setup
app.set('view engine', 'pug');
app.set('views', './views');

// Middleware to parse form data
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// GET request to render the form
app.get('/', function (req, res) {
    res.render('form');  // This will render the 'form.pug' view
});

// POST request to handle form submission
app.post('/', function (req, res) {
    console.log(req.body);  // Log the form data received
    res.send("Received your request!");
});

// Start the server
app.listen(3000, function () {
    console.log("Server is running on http://localhost:3000");
});
