// Validator library usage
import val from 'validator';

var email = 'xyz@pes.edu';
console.log(val.isEmail(email)); // true

email = 'xyz@.edu';
console.log(val.isEmail(email)); // false

var name = 'john';
console.log(val.isLowercase(name)); // true

name = 'JOHN';
console.log(val.isLowercase(name)); // false

name = '';
console.log(val.isEmpty(name)); // true

name = 'Smith';
console.log(val.isEmpty(name)); // false

// My library usage (assuming './U4_mylib.js' file exists)
const mylib = require('./U4_mylib.js');
console.log(mylib.constant); // MY World
console.log("Add 7 and 10:", mylib.myadd(7, 10)); // 17
// console.log("Difference of 10 and 7:", mylib.mysub(10, 7)); // Uncomment if needed

// Chalk library usage for colored console output
const chalk = require('chalk');
console.log(chalk.blue('Hello world!')); // Prints 'Hello world!' in blue

console.log(chalk.red("Hello chalk world ....")); // Prints 'Hello chalk world ....' in red

console.log(chalk.blue.bgRed.bold("Hello chalk world ....")); // Prints bold, blue text with red background

console.log(chalk.red("I am red line" + chalk.blue.underline.bold("with blue substring") + " that becomes red again"));
// Prints a red line with a blue, underlined, bold substring
