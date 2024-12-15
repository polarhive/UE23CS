// Server 1
// Execute this server code, then go to browser and type localhost:8080, you can see response sent by the server
var url = require('url');
var http = require('http');
var fs = require('fs');

http.createServer(function (request, response) {
    response.writeHead(200, { 'Content-type': 'text/plain' });
    response.write('Welcome to my domain!!!');
    response.end("Welcome to web server");
}).listen(8080);
console.log("Server is up and running on http://localhost:8080");


// Server 2
// Execute this server code, then go to browser and type localhost:8080/file.txt. Server reads the file requested in the URL and then sends it as a response. 
// If the file is not found, it returns a "404 File not found" message
http.createServer(function (request, response) {
    if (request.method == 'GET') {
        var myurl = url.parse(request.url);
        var pathname = myurl.pathname;
        fs.readFile(pathname.substr(1), function (err, data) {
            if (err) {
                response.writeHead(404, { 'Content-type': 'text/html' });
                response.write("<h1> File not found</h1>");
                response.end();
            } else {
                response.writeHead(200, { 'Content-type': 'text/html' });
                response.write(data);
                response.end();
            }
        })
    }

}).listen(8080);
console.log("Server is up and running on http://localhost:8080");


// Server 3
// Execute this server code, then go to browser and type localhost:8080/, server sends index.html file as a response. 
// If you type localhost:8080/file.txt, the server reads the file requested in the URL and sends it as a response. 
// If the file is not found, it returns a "404 File not found" message
http.createServer(function (request, response) {
    if (request.method == 'GET') {
        var myurl = url.parse(request.url);
        var pathname = myurl.pathname;
        if (pathname == '/') {
            pathname = "/index.html";
        }
        fs.readFile(pathname.substr(1), function (err, data) {
            if (err) {
                response.writeHead(404, { 'Content-type': 'text/html' });
                response.write("<h1> File not found</h1>");
                response.end();
            } else {
                response.writeHead(200, { 'Content-type': 'text/html' });
                response.write(data);
                response.end();
            }
        })
    }

}).listen(8080);
console.log("Server is up and running on http://localhost:8080");
