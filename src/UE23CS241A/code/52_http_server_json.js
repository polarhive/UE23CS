// Server 1 - Handles GET requests and parses JSON data for a single row based on SRN in query string
// Execute this server code, then go to browser and type localhost:8080/sample.txt?srn=18
var url = require('url');
var http = require('http');
var fs = require('fs');
var qs = require('querystring');

http.createServer(function (request, response) {
    if (request.method == 'GET') {
        var myurl = url.parse(request.url);
        var pathname = myurl.pathname;
        if (pathname == '/') {
            pathname = "/index.html";
        }

        // Example URL: http://localhost:8080/sample.txt?srn=1234
        fs.readFile(pathname.substr(1), 'utf-8', function (err, data) {
            if (err) {
                response.writeHead(404, { 'Content-type': 'text/html' });
                response.write("<h1>File not found</h1>");
                response.end();
            } else {
                response.writeHead(200, { 'Content-type': 'text/html' });
                var obj = JSON.parse(data);
                var query = myurl.query; //?srn=1234&&dept=cse
                var qobj = qs.parse(query); //{"srn":"1234"}
                if (obj.srn == qobj.srn)
                    response.write("<h1>" + obj.name + "</h1>");
                response.end();
            }
        })
    }
}).listen(8080);

console.log("Server 1 is up and running on http://localhost:8080");


// Server 2 - Handles GET requests and parses multiple rows of JSON data from a file
// Execute this server code, then go to browser and type localhost:8080/sample1.txt?srn=18
var url = require('url');
var http = require('http');
var fs = require('fs');
var qs = require('querystring');

http.createServer(function (request, response) {
    if (request.method == 'GET') {
        var myurl = url.parse(request.url);
        var pathname = myurl.pathname;
        if (pathname == '/') {
            pathname = "/index.html";
        }

        // Example URL: http://localhost:8080/sample1.txt?srn=1234
        fs.readFile(pathname.substring(1), 'utf-8', function (err, data) {
            if (err) {
                response.writeHead(404, { 'Content-type': 'text/html' });
                response.write("<h1>File not found</h1>");
                response.end();
            } else {
                response.writeHead(200, { 'Content-type': 'text/html' });
                var lines = data.split(/\r?\n/); // Split data into lines

                var query = myurl.query; //?srn=1234&&dept=cse
                var qobj = qs.parse(query); //{"srn":"1234"}
                for (var i in lines) {
                    var obj = JSON.parse(lines[i]);
                    if (obj.srn == qobj.srn)
                        response.write("<h1>" + obj.name + "</h1>");
                }
                response.end();
            }
        })
    }
}).listen(8080);

console.log("Server 2 is up and running on http://localhost:8080");
