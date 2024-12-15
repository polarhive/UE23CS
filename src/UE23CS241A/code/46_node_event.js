// Example 1: Basic EventEmitter with 'addListener' and 'on'

// Import the 'events' module
var events = require('events');

// Create a new EventEmitter instance
var em = new events.EventEmitter();

// Define the first event listener using 'addListener'
em.addListener('FirstEvent', function (data) {
    console.log('First subscriber: ' + data);
});

// Define the second event listener using 'on'
em.on('SecondEvent', function (data) {
    console.log('Second subscriber: ' + data);
});

// Fire FirstEvent and pass some data to it
em.emit('FirstEvent', 'This is my first Node.js event emitter example.');

// Fire SecondEvent and pass some data to it
em.emit('SecondEvent', 'This is my second Node.js event emitter example.');

// Example 2: Using 'on', 'emit', 'removeListener' and handling multiple listeners

var eventEmitter = new events.EventEmitter();

// Define two listeners
var listner1 = function listner1() {
    console.log('Listener1 executed.');
}

var listner2 = function listner2() {
    console.log('Listener2 executed.');
}

// Add the listeners to the 'connection' event
eventEmitter.on('connection', listner1);
eventEmitter.on('connection', listner2);

// Emit the 'connection' event
eventEmitter.emit('connection');

// Remove listener1 from the 'connection' event
eventEmitter.removeListener('connection', listner1);
console.log("Listener1 will not listen now.");

// Emit the 'connection' event again
eventEmitter.emit('connection');

// End of the program
console.log("Program Ended.");

// Example 3: Basic event trigger using 'emit' and 'on' with no arguments

var em = new events.EventEmitter();

// Define a simple event listener
em.on('Event', function () {
    console.log('Event Triggered');
});

// Fire the 'Event' without any data
em.emit('Event');
