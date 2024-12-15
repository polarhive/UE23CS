var fs = require('fs');

// Opening a File
console.log("Going to open file");
fs.open('test1.txt', 'r+', function (err, data) {
    if (err) {
        return console.error(err);
    }
    console.log(data);
    console.log("File Opened Successfully");
});

// Reading from a File (Asynchronous)
fs.readFile('test1.txt', function (err, data) {
    if (err) throw err;
    console.log(data.toString());
});
console.log("Reading the contents of the file");

// Reading from a File (Synchronous)
var data = fs.readFileSync('test1.txt', 'utf8');
console.log(data);
console.log("Reading the contents of the file");

// Writing to a File
console.log("Going to write into existing file");
fs.writeFile('test1.txt', 'PES University', function (err) {
    if (err) {
        return console.error(err);
    }
    console.log("Data written successfully");
    console.log("Let's read newly written data");
    fs.readFile('test1.txt', function (err, data) {
        if (err) throw err;
        console.log(data.toString());
        console.log("Asynchronous Read " + data.toString());
    });
});

// Truncating a File
console.log("Going to open file");
fs.open('test1.txt', 'r+', function (err, fd) {
    if (err) {
        return console.error(err);
    }
    var buf = new Buffer(1024);
    console.log("File Opened Successfully");
    console.log("Going to truncate file after 3 bytes");

    // Truncate the opened file
    fs.ftruncate(fd, 3, function (err) {
        if (err) {
            console.log(err);
        }
        console.log("File truncated successfully");
        console.log("Going to read the same file");

        fs.read(fd, buf, 0, buf.length, 0, function (err, bytes) {
            if (err) throw err;
            if (bytes > 0) {
                console.log(buf.slice(0, bytes).toString());
            }
            fs.close(fd, function (err) {
                if (err) throw err;
            });
        });
    });
});

// Deleting a File
fs.unlink('test1.txt', function () {
    console.log("File deletion complete");
});

// Append Data to File
fs.appendFile("test1.txt", "\nContent to be Written is this again and again!!!", function (err) {
    if (err) console.log(err);
    console.log("Write Successful!!!");
});

// Open File and Write to it
fs.open("test1.txt", "w", function (err, file) {
    if (err) throw err;
    fs.write(file, "Contents for writing this", function (err) {
        if (err) throw err;
        console.log("Saved!!");
    });
});

// Read File and Process Each Line
var data = fs.readFileSync("test.txt", 'utf-8');
var lines = data.split(/\r?\n/);
lines.forEach((line) => {
    var words = line.split(',');
    console.log(words[1]);
});

// Using readline to process input line by line
var readline = require('readline');
var r1 = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false
});

r1.on('line', function (line) {
    var words = line.split(',');
    console.log(words[1]);
});
