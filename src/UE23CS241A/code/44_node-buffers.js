const fs = require('fs');
const zlib = require('zlib');

// Buffers Example 1: Concatenation of Buffers
const buf1 = Buffer.alloc(10, 'Hi welcome');
const buf2 = Buffer.alloc(17, ' to pes university');
console.log("Buffer1:", buf1.toString());
console.log("Buffer2:", buf2.toString());
const totallength = buf1.length + buf2.length;
console.log("Total Length:", totallength);
const buf3 = Buffer.concat([buf1, buf2]);
console.log("Concatenated Buffer:", buf3.toString());
console.log("Concatenated Buffer Length:", buf3.length);

// Buffers Example 2: Buffer Comparison and Copying
const buf4 = Buffer.alloc(10, 'Hi welcome');
const buf5 = Buffer.alloc(10, 'Hi welcome');
var result = buf4.compare(buf5);
if (result < 0) {
    console.log(buf4 + " comes before " + buf5);
} else if (result === 0) {
    console.log(buf4 + " is same as " + buf5);
} else {
    console.log(buf4 + " comes after " + buf5);
}

var buf6 = Buffer.alloc(25);
buf5.copy(buf6);
console.log("Buffer5 content is copied to Buffer6: " + buf6.toString());

// Streams Example 1: Reading from a file stream
var data = '';
var rs = fs.createReadStream('data.txt');
rs.setEncoding('UTF-8');
rs.on('data', function (chunk) {
    data += chunk;
});
rs.on('end', function () {
    console.log("File Content: " + data);
});
rs.on('err', (err) => {
    console.log(err.stack);
});

// Streams Example 2: Writing to a file stream
var dataToWrite = "You are learning Buffers and Streams";
var ws = fs.createWriteStream('ex.txt');
ws.write(dataToWrite, 'UTF-8');
ws.end();
ws.on('finish', function () {
    console.log('Write Completed');
});
ws.on('error', function (err) {
    console.log(err.stack);
});
console.log('Program ended');

// Compression Example: Compressing a file using Gzip
fs.createReadStream('data.txt')
    .pipe(zlib.createGzip())
    .pipe(fs.createWriteStream('data.txt.gz'));

console.log('File compressed');

// Decompression Example: Decompressing a file using Gunzip
fs.createReadStream('data.txt.gz')
    .pipe(zlib.createGunzip())
    .pipe(fs.createWriteStream('data.txt'));
console.log('File Decompressed');
