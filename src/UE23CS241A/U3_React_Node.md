# React and NodeJS

# States

- State is used with React Component Classes to make them dynamic.
- It enables the component to keep track of changing information in between renders.
- An instance of React Component Class can be defined as an object of a set of observable properties that control the behavior of the component
- An object that holds some information that may change over the lifetime of the component and to control the behavior after each change 
- Can only be used in class components
## Conventions of using states

> When using State, we need the state of a component to always exist i.e., we need to set an initial state.

Initial state, should define the State in the constructor of the component’s class.

```js
class MyClass extends React.Component {
	constructor(props) {
		super(props); this.state = { attribute : "value" }; 
		}
}
```


> [!warning] State should never be updated explicitly.
> Use `setstate()`
- Takes a single parameter and expects an object which should contain the set of values to be updated.
- Once the update is done the method implicitly calls the `render()` method to repaint the page.
- State updates are independent
## Introduction to Life Cycle Methods

- The series of events that happen from the starting of a React component to its ending.
- Every component in React should go through the following lifecycle of events.
- **Mounting** - Birth of the Component
- **Updating** - Growing of component
- **Unmounting** - End of the component

`componentWillMount()`
- Executed before rendering, on both the server and the client side

`constructor()`
- Called before the component is mounted.
- Implementation requires calling of `super(props)` before further moving. Otherwise, `this.props` it will be undefined in the constructor, which can lead to a major error in the application.
- Supports Initializing the state and Binding our component

`render()`
- Most useful life cycle method as it is the only method that is required
- Handles the rendering of component while accessing this.state and this.props

`componentDidMount()`
- The best place to initiate API calls in order to fetch data from remote servers
- Use setState which will cause another rendering but It will happen before the browser updates the UI. This is to ensure that the user won’t see the intermediate state
- AJAX requests and DOM or state updates should occur here
- Also used for integration with other JavaScript frameworks like Node.js and any functions with late execution such as setTimeout or setInterval

`componentWillReceiveProps()`
- Allows us to match the incoming props against our current props and make logical
- We get our current props by calling this.props and the new value is the nextProps argument passed
to the method
- It is invoked as soon as the props are updated before another render method is called

`shouldComponentUpdate()`
- Allows a component to exit the Update life cycle if there’s no reason to use a replacement render.
- It may be a no-op that returns true. Means while updating the component, we’ll re-render.

`componentWillUpdate()`
- Called just before the rendering

`componentDidUpdate()`
- Is invoked immediately after updating occurs. Not called for the initial render.
- Will not be invoked if shouldcomponentUpdate() returns false.

`componentWillUnmount()`
- Called when a component is being removed from the DOM

---
# Stateless Components

> A component that has no internal state management in it

- Can be written as functions that just return the JSX element
- Simple functional components without having a local state
- Usually associated with how a concept is presented to the user
- Properties are passed like regular parameters. The props are displayed like {props.name}
- Hook in react is available to add state behavior in functional component

> Sample code

```js
function Demo(props) {
	return <h1> Welcome to REACT JS, {props.Name} </h1>; 
}
```
- Code to render such components remains the same.
`ReactDOM.render(<Demo/>, destination)` 


| Stateless component<br>                                             | Stateful component                                                                                                           |
| ------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------- |
| Simple functional component                                         | Always a class component                                                                                                     |
| It takes an input (props) and returns<br>the output (react element) | It is created by extending<br>the `React.Component` class                                                                    |
| No internal state management in it                                  | Dependent on it’s state object and can<br>change it’s own state. The component re-<br>renders based on changes to it’s state |
| Also known as Presentational<br>components/Dump components          | Also known as Smart or container<br>Components                                                                               |

---

# Refs and Keys

> Provides a way to access DOM nodes or React elements created in
the render method

- Used to return a reference to the element
- Good use cases for refs to be used:
- Managing focus, text selection, or media playback
- Triggering imperative animations
- Integrating with third-party DOM libraries

### Creating refs:
- `React.createRef()` method is used to attach React elements via the ref attribute.
- Refs are assigned to an instance property when a component is constructed so they can be referenced throughout the component.

### Accessing refs:
- When a ref is passed to an element in render, a reference to the node becomes accessible at the current attribute of the ref.

### Callback refs
- Gives more fine-grain control over when refs are set and unset
- The function receives the React component instance or HTML DOM element as its argument,which can be stored and accessed elsewhere

## keys
- Utilized to identify specific virtual DOM elements that have changed, added, or removed.
- Keys should be given to the elements inside the array to give the elements
a stable identity
- Keys only make sense in the context of the surrounding array
- Not specifying the key property will display a warning on the console:

> [!warning]
> Each child in an array or iterator should have a unique "key" prop.

> When returning a list of elements

```js
function Stuff () {
	return (
		[
			<p>Batman</p>,
			<p>Ironman</p>,
			<p>Spiderman</p>
		]
		);
};
```

```js
function Stuff () {
	return (
		[
			<p key=“1”>Batman</p>,
			<p key=“2”>Ironman</p>,
			<p key=“3”>Spiderman</p>
		]
	);
};
```

## Map Function

> Map is a data collection type where data is stored in the form of key-value pairs

- The value stored in the map must be mapped to the key
- The map is a JavaScript function that can be called on any array
- With the map function, we map every element of the array to the custom
components in a single line of code

```js
const numbers = [1, 2, 3, 4, 5];
const doubled = numbers.map((number) => number * 2);
console.log(doubled);
```

## Using map with key property

> The code will result in error, as the list of items does not have the key property

```js
const numbers = [1, 2, 3, 4, 5];
const listItems = numbers.map((number) =>
	<li>{number}</li>);
		ReactDOM.render(
		<ul>{listItems}</ul>,
		document.getElementById('root') 
)
```

> After adding key property

```js
function NumberList(props) {
const numbers = props.numbers;
const listItems = numbers.map((number) =>
	<li key={number.toString()}> {number}
	</li> 
);
	return ( <ul>{listItems}</ul> );
}

const numbers = [1, 2, 3, 4, 5];
ReactDOM.render(
	<NumberList numbers={numbers} />
	document.getElementById('root')
);
```

---

# Hooks

> Hooks allow us to "hook" into React features such as state and lifecycle methods.

- Hooks allow function components to have access to state
- There are 3 rules for hooks:
- Hooks can only be called inside React function components.
- Hooks can only be called at the top level of a component.
- Hooks cannot be conditional
- Hooks will not work in React class components.

## React `useState` Hook

> You need to include Hooks from the React library if you are using React APP.
- The React useState Hook allows us to track state in a function component.
- We initialize our state by calling useState in our function component.
- `useState` accepts an initial state and returns two values:
	- The current state.
	- A function that updates the state

```js
function FavoriteColor() {
	const [color, setColor] = React.useState("");
}
```

- We are destructuring the returned values from useState.
- The first value, color, is our current state.
- The second value, setColor, is the function that is used to update our state.

## React `useEffect` Hook

- `useEffect` Hook allows you to perform side effects in your components.
- useEffect accepts two arguments. The second argument is optional. `useEffect(<function>, <dependency>)`
- If no dependencies are passed then rendering will happen continuously.
- If an empty array is passed as dependency the it runs only on the first render.
- If props or state values are given then render will be called and dependency values changes.

---

# NodeJS

> Fetching a file: To include a module, use the require() function with the name of the module:

```js
const fs=require('fs')
fs.stat('U4L2.js', (err,stats)=>{
	if (err) throw err;
	console.log('Stats of U4L2.js',JSON.stringify(stats))
})
```

> Renaming a file

```js
const fs=require('fs')
fs.rename('U4L2.js',"NewU4L2.js",(err)=>{
	console.log("Rename Succesfull")
})
fs.stat('NewU4L2.js', (err,stats)=>{
	if (err) throw err;
	console.log('Stats of newer.js',JSON.stringify(stats))
})
```

> Non Blocking I/O

```js
const fs=require('fs')
fs.readFile('NewU4L2.js','UTF-8' ,(err,data)=>{
	if(err) throw err
	console.log("Contents:",data)
})
console.log("Reading the Contents");
```

> Blocking I/O

```js
const fs=require('fs')
const data=fs.readFileSync("NewU4L2.js",'UTF-8')
console.log("Reading the file contents...")
console.log("data:",data)
```

## Create Modules in Node.js
- To create a module in Node.js, use exports keyword tells Node.js that the
function can be used outside the module.
- Create a file that you want to export
- Use the ‘require’ keyword to import the file

## The Node File System (fs) module 
### Synchronous vs Asynchronous

- Every method in the fs module has synchronous as well as asynchronous forms.
- Asynchronous methods take the last parameter as the completion function callback
and the first parameter of the callback function as error.
- It is better to use an asynchronous method instead of a synchronous method, as the
former never blocks a program during its execution, whereas the second one does.Fs module operations

Common use for the File System module:
- Read files
- Create files
- Update files
- Delete files
- Rename files

## Buffers Introduction

- Pure JavaScript is Unicode friendly, but it is not so for binary data.
- Working with TCP streams or the file system, it's necessary to handle octet streams.
- Node provides Buffer class which provides instances to store raw data similar to an array of integers but corresponds to a raw memory allocation outside the V8 heap.
- Buffer class is a global class that can be accessed in an application without importing the
buffer module.


## Streams
- Streams are one of the fundamental concepts that power Node.js applications.
- They are data-handling method and are used to read or write input into output
sequentially.
- Streams are a way to handle reading/writing files, network communications, or any kind
of end-to-end information exchange in an efficient way.
- A program reads a file into memory all at once like in the traditional way, whereas streams read chunks of data piece by piece, processing its content without keeping it all in memory.
- This makes streams really powerful when working with large amounts of data, for example, a file size can be larger than your free memory space, making it impossible to read the whole file into the memory in order to process it.
- Streams also give us the power of ‘composability’ in our code

### Why Streams

Streams basically provide two major advantages compared to other data handling
methods:
- Memory efficiency: you don’t need to load large amounts of data in memory before you are able to process it
- Time efficiency: it takes significantly less time to start processing data as soon as you have it, rather than having to wait with processing until the entire payload has been transmitted
 
> There are 4 types of streams in Node.js:

- Writable: streams to which we can write data. For example, fs.createWriteStream() lets us write data to a file using streams.
- Readable: streams from which data can be read. For example: fs.createReadStream() lets us read the contents of a file.
- Duplex: streams that are both Readable and Writable. For example, net.Socket
- Transform: streams that can modify or transform the data as it is written and read. For example, in the instance of file-compression, you can write compressed data and read decompressed data to and from a file.

> In HTTP server, request is a readable stream and response is a writable stream.

### Streams as Events

> Each type of Stream is an EventEmitter instance and throws several events at different instance of times.

For example, some of the commonly used events are
- data − This event is fired when there is data is available to read.
- end − This event is fired when there is no more data to read.
- error − This event is fired when there is any error receiving or writing data.
- finish − This event is fired when all the data has been flushed to underlying system.

## HTTP Module – Web Server using Node

The components of a Node.js application.
Import required modules − We use the require directive to load Node.js modules.
Create server − A server which will listen to client's requests similar to Apache HTTP
Server. Node.js has a built-in module called HTTP, which allows Node.js to transfer
data over the Hyper Text Transfer Protocol (HTTP).
Read request and return response − The server created in an earlier step will read the
HTTP request made by the client which can be a browser or a console and return the
response.
### Creating Node.js Application

1. Import Required Module

We use the require directive to load the `http` module and store the returned HTTP
instance into an `http` variable as follows

2. Create Server

- We use the created http instance and call http.createServer() method to create a server instance.
- Then we bind it at port 8088 using the listen method associated with the server instance.

4. Testing Request & Response

``` js
$node app.js

Verify the Output. Server has started.
Server running at http://127.0.0.1:8088/
```

### URL Module

The URL module splits up a web address into readable parts. To include the URL module, use the require() method: Parse an address with the url.parse() method, and it will return a URL object with each part of the address as properties:

Node.js can be used in database applications
- One of the most popular NoSQL database is MongoDB.
- Node.js can use this module to manipulate MongoDB databasesrequire(‘mongodb’);
