// Importing required modules
const express = require("express");
const fileupload = require("express-fileupload");
const fs = require("fs"); // File system module for file manipulation

// Initializing the Express app
var app = express();

// Middleware to handle file uploads
app.use(fileupload());

// Serve the HTML form
app.get('/', (req, res) => {
    res.sendFile(__dirname + '/index.html'); // Serve the HTML file for uploading
});

// Handle file upload via POST request
app.post('/', (req, res) => {
    if (req.files) {
        console.log(req.files); // Log the uploaded file information

        // Select the uploaded file and extract its name
        var file = req.files.file;
        var filename = file.name;
        console.log(filename); // Log the filename

        // Move the uploaded file to the desired location
        file.mv('./files/' + filename, function (err) {
            if (err) {
                res.send(err); // Handle error during file movement
            } else {
                res.send("File " + file.name + " uploaded successfully!"); // Send success message
            }
        });
    } else {
        res.send("No file uploaded");
    }
});

// Start the server
app.listen(3000, function () {
    console.log("Server is running on http://localhost:3000");
});
