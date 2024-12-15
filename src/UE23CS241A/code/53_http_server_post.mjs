import fs from'fs';
/* HTTP server listens for POST requests and collects the data (JSON file) sent in those requests and writes it to a file based on the request's pathname(sample.txt) */
import http from'http'
import url from 'url'
http.createServer(function(request,response){
    if(request.method=="POST"){
        var myurl=url.parse(request.url);
        var pathname=myurl.pathname;
        let body=[];
        request.on('data',(chunk)=>{
            body.push(chunk);
            console.log(chunk.toString());
        })
        .on('end',()=>{
            body=Buffer.concat(body).toString();
            console.log(body);
            fs.writeFile(pathname.substring(1),body,(err,res)=>{
                response.writeHead(200,{'Content-type':'text/plain'});
                response.end("Message saved");
            })
        })
    }
}).listen(8080);
console.log("Server is up and Running");