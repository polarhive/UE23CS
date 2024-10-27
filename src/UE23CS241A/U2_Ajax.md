# XML, AJAX, React

## XML

It was created to better represent data formats with a hierarchical structure.

## JSON (Javascript Object Notation)

It was created as an alternative to XML. Like XML, however, it represents hierarchical data with the use of commas, curly braces and brackets.

| JSON                        | XML                        |
| --------------------------- | -------------------------- |
| Way of representing objects | Markup                     |
| Arrays                      | No arrays                  |
| Less Secure                 | More secure                |
| UTF-8                       | Supports various encodings |
| No tags                     | Has start and end tags     |

## Media elements

A standard approach for browser to play audio without the use of plug-in 

```html
<audio controls="controls"> 
	<source src="song.ogg" type="audio/ogg" /> 
	<source src="song.mp3" type="audio/mp3" /> Your browser does not support the audio element.
</audio>


<video width="320" height="240" controls="controls"> 
	<source src="movie.ogg" type="video/ogg"/>
	<source src="movie.mp4" type="video/mp4" /> <source src="movie.webm" type="video/webm"/>Your browser does not support the video tag.
</video>
```

### Progressbar

- The `<progress>` tag represents the completion progress of a task. 
- Always add the `<label>` tag for describing the task! - Use JavaScript to manipulate the value of the progress bar.

```html
<label for="file">Downloading progress:</label>
<progress id="file" value="32" max="100">32%</progress>
```

### Canvas

 Uses JavaScript to draw graphics on a web page, aka a rectangular area, and you control every pixel of it.
 
```html
<canvas id="myCanvas" width="200" height="100"> Canvas is not supported</canvas>
```

The canvas element has no drawing abilities of its own. All drawing must be done inside a JavaScript using the context object 

```js
var c=document.getElementById("myCanvas"); 
var ctx=c.getContext("2d"); ctx.fillStyle="#FF0000"; ctx.fillRect(50,50,150,75);
```

| Method                                       | Description                                                                                                                                                                         |
| -------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| fillRect(x, y, width, height)                | Draws a rectangle                                                                                                                                                                   |
| strokeRect(x, y, width, height)              | Draws an outline                                                                                                                                                                    |
| clearRect(x, y, width, height)               | Clears the specific rectangular area, making it fully transparent                                                                                                                   |
| moveTo(x, y)                                 | Moves the pen to the coordinates specified by x, y                                                                                                                                  |
| lineTo(x, y)                                 | Draws a line from the current drawing position to the position specified by x and y                                                                                                 |
| arc(x, y, r, sAngle, eAngle, anticlockwise)  | Draws an arc centered at (x,y) with radius `r` starting sAngle; ending eAngle going anticlockwise, defaulting to clockwise                                                          |
| arcTo(x1, y1, x2, y2, radius)                | Draws an arc with the given control points and radius, connected to the previous point by a straight line                                                                           |
| createLinearGradient(x1, y1, x2, y2)         | Creates a linear gradient object with a starting point of (x1, y1) and an end point of (x2, y2)                                                                                     |
| createRadialGradient(x1, y1, r1, x2, y2, r2) | Creates a radial gradient. The parameters represent two circles, one with its center at (x1, y1) and a radius of r1, and the other with its center at (x2, y2) with a radius of r2. |
| fillText(text, x, y [, maxWidth])            | Fills a given text at the given (x,y) position. Optionally with a maximum width to draw.                                                                                            |
| strokeText(text, x, y [, maxWidth])          | Strokes a given text at the given (x,y) position. Optionally with a maximum width to draw                                                                                           |
| drawImage(image, x, y [,width, height])      | Draws the CanvasImageSource specified by the image parameter at the coordinates (x, y) with optional width and height                                                               |

## SVG

- SVG stands for Scalable Vector Graphics. 
- SVG defines vector-based graphics using HTML elements 
- SVG graphics do NOT lose any quality if they are zoomed or resized 

```html
<svg width="100" height="100">
<circle cx="50" cy="50" r="40" stroke="green" stroke-width="4" fill="yellow"/>
</svg>
<rect width="300" height="100" style = "fill:rgb(0,0,255); stroke- width:3; stroke:rgb(0,0,0)"/> 
<circle cx="50" cy="50" r="40" stroke="black" stroke-width="3" fill="red"/>
<ellipse cx="200" cy="80" rx="100" ry="50“ style = "fill:yellow; stroke:purple; stroke-width:2"/>
<polygon points="200,10 250,190 160,210" style = "fill:lime; stroke:purple; stroke-width:1"/>
<text x="0" y="15" fill="red" transform="rotate(30 20,40)">I love SVG</text>
```

## Geolocation

Enables your web application to obtain the geographical position of your website visitors. The user has to accept to share their location. Accessed via JavaScript, through the `navigator.geolocation` object

### Methods

- `navigator.geolocation` object allows you to access geo location through two primary functions: 
	- `getCurrentPosition()` returns the location of the visitor as a one-time snapshot 
	- `watchPosition()` returns the location of the visitor every time the location changes 	
- Both functions take the following parameters:
	- Success callback function 
	- Error callback function (optional) - Geo location options object (optional)

### Associated objects

Success callback function receives position object with these read only properties 
- double latitude
- double longitude
- double accuracy
- double altitude
- double altitudeAccuracy
- double heading (direction)
- double speed

Error callback function receives error object with these two properties 
- short code 
	- 1, meaning PERMISSION_DENIED
	- 2, meaning POSSITION_UNAVAILABLE
	- 3, meaning TIMEOUT
- DOMString message

**Options** object (third parameter to getCurrentPosition or watchPosition)
- enableHighAccuracy // true or false
- timeout // milliseconds
- maximumAge // milliseconds

## Webworker

A web worker is essentially a thread executing a JavaScript file. Makes it possible to execute a JavaScript file asynchronously and autonomously. Helps achieve multi threading in your web applications. To create a web worker: 

```js
var worker = new Worker(“myasync.js"); 
```

Parameter is the URL of the JavaScript file to execute.

### Restrictions

 A web worker does not have access to the DOM of the page that creates the web worker.
 
 - Here is a list of what a web worker can do: 
 - Listen for messages, using the `onmessage` event listener function. 
 - Send messages via the `postMessage()` function. 
 - Send AJAX requests using the `XMLHttpRequest` 
 - Create timers using the `setTimeout()` and `sendInterval()` functions.

## jQuery

> Simplifies the interaction between HTML and JavaScript

> [!Example]
> JavaScript: 
> ```js
> let paras = document.querySelectorAll(“p”) for (let i=0; i<paras.length; i++) paras[i].style.color = “red”
> ```
> 
>  jQuery: 
> 
> ```js
> $(“p”).css(“color”, “red”);
> ```

### Structure

![](Pasted%20image%2020240920144637.png)

| Select By         | Example                                                 |
| ----------------- | ------------------------------------------------------- |
| ID                | `$("#header")`                                          |
| Class             | `$(".updated)`                                          |
| Tag Name          | `$("Table")`                                            |
| Combo             | `$("table.user-list")` or `$("#footer ul.menu li")`     |
| Basic Filters     | `:first, :last, :even, :odd`                            |
| Content Filters   | `:empty , :contains(text), :has(selector)`              |
| Attribute Filters | `[attribute], [attribute=value], [attribute!=value]`    |
| Forms             | `:input, :text, :submit, :password, :enabled, :checked` |
| DOM Manipulation  | `before(), after(), append(), appendTo()`               |
| Attributes        | `addClass(), css(), attr(), html(), val(), text()`      |
| Events            | `click(), on(), bind(), unbind(), live()`               |
| Effects           | `hide(), fadeOut(), toggle(), animate()`                |
| AJAX              | `load(), get(), ajax(), post(), getJSON()`              |

### DOM Manipulation methods

- `append()` : adds a set of elements to the end of the children 
	- `$(“pelem”).append($c1*, c2, …+)` // $c1, $c2, … will be appended to child elements of $pelem. 
	- Similar methods: appendTo, prepend
- `after()` adds a set of elements after the specified element 
	- `$(“elem”).after($e1*, $e2,…+)` //$e1, $e2 will be added after $elem under the same parent
	- Similar methods: insertAfter, before, insertBefore

### Attribute methods

Attribute Methods like `css(), attr(), val(), html(), text()` can be used for both setting and getting attributes. Based on whether one or two arguments were passed. 

> [!Example]
> - For Setting `$(“p:last”).css(“color”, “green”);` 
> - For Getting `let pcolor = $(“p:last”).css(“color”)`

### Chaining methods

Most jQuery methods return jQuery objects. You can chain them together to perform multiple operations on the same elements 

```js
-$(“#deleted”).addClass(“red”).fadeOut(“slow”);
```

This will not work as `val()` returns a string

```js
 $(“:button”).val(“Click Me”).click(function(){…})`
```
### Event methods

Register an event handler for an element object passing a function reference to the event method

```js
$(“span#message”).click(function(event){…}); OR $(“span#message”).on(“click”, function(event) {…});
```

### Manually triggering Event

Like with attribute methods, the event methods have a different meaning without arguments. Without the function reference argument, the event methods are treated like a manual firing of event.

```js
$(“span#message”).click();
```

### Keywords: `this` and `ready`

Special event to register for handler once the document has been loaded completely is ready

```js
$(document).ready(function(){
	// test
});
```

 Within any event handler function this element refers to the element for which the handler is called
 
```js
$("p").click(function() { 
	var htmlString = $( this ).html();
}
```

### Effect Methods

Lot of animation/styling effects can be accomplished using the effects methods like `hide, show, toggle, fadein, fadeout`

```js
$(“a#show-cart”).click(function(){ $(“#cart”).slideToggle(“slow”); }); 
```

Or, use the animate method to build custom animations

```js
$("#showdown").click(function(){ $("#my-div").animate({ 
	width: "70%", opacity: 0.4, fontSize: "3em“ }, 1200 ); 
	});
```

## Callback and Promises

As seen in `setInterval`, `setTimeout` and `addEventListener` a function accepts a function reference as an argument. 

They will be called asynchronously based on timer or other events. These function references are called **Callback** functions 

> Example: `div.addEventListener(“keypress”, function(){ … });`

 A promise is used to handle the asynchronous result of an operation. With Promises, we can defer execution of a code block until an `async` request is completed. 
 
The **Promise** object is created using the **new** keyword and contains the promise; this is an *executor* function which has a **resolve** and a **reject** callback. 

Essentially, a promise is a returned object to which you attach callbacks, instead of passing callbacks into a function. 

```js
const promise = new Promise(function(resolve, reject) { 
	// promise description 
});
```

### Example of Promise

```js
var weather; const date = new Promise(
	function(resolve, reject) {
		weather = true; //usually a API call
		if (weather) {
			const dateDetails = { name: 'Cubana Restaurant',
								 location: '55th Street',
								 table: 5
								};
			resolve(dateDetails)}
		else {
			reject(new Error('Bad weather'))
		}
	} 
);
```

```js
date .then(function(done) { console.log('We are going on a date!') console.log(done) }) .catch(function(error) { console.log(error.message) })
```

### Comparison

Callbacks are function passed to another function as a reference. Chaining of Callbacks can be clumsy and lead to **Callback Hell**

Promises use Callbacks and more elegant than Callbacks. Chaining of Promises is supported

---
# SPA / async js

Instead of the default method of the browser loading entire new pages, a single-page application (SPA) interacts with the web browser by dynamically rewriting the current web page with new data from the web server.

Resources are dynamically loaded and added to the page as necessary, usually in response to user actions. The page does not reload at any point in the process, nor does it transfer control to another page 

>Can be built using - AJAX - Frameworks like ReactJS, AngularJS

## Approaches include

- Setting src property of iframe or img element
- A more elegant and complete approach is use of XHR or XMLHttpRequest object 
- First create an XHR object using `var xhr = new XMLHttpRequest();`

### XHR object properties and methods

| Methods                            | Description                                                                                                                                                                                                                                                                                                                                                                                                 |
| ---------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| open(method, url [, asynchronous]) | Initializes the request in preparation for sending to the server. The method parameter is the HTTP method to use, for example “GET” or “POST”. The url is the relative or absolute URL the request will be sent to. The optional asynchronous parameter indicates whether send() returns immediately or after the request is complete (default is true, meaning it does not wait for response to come back) |
| onreadystatechange                 | Function to call whenever the readyState changes                                                                                                                                                                                                                                                                                                                                                            |
| send([body])                       | Initiates the request to the server. The body parameter should contain the body of the request, i.e., a string containing fieldname=value&fieldname2=value2… for POSTs or a null value for GET request                                                                                                                                                                                                      |
| readyState                         | Integer indicating the state of the request, either: `0 (uninitialized) 1 (loading) 2 (response headers received) 3 (some response body received) 4 (request complete)`                                                                                                                                                                                                                                     |
| status                             | HTTP status code returned by the server (e.g., 200, 404, etc.                                                                                                                                                                                                                                                                                                                                               |
| responseXML                        | A Document object representing the server’s response parsed as an XML document (responseType property is set to “document”)                                                                                                                                                                                                                                                                                 |
| responseText                       | Full response from the server as a string (responseType property is set to “text” – default)                                                                                                                                                                                                                                                                                                                |
| response                           | Any other type of response received ((responseType property is set to “blob” or “json”                                                                                                                                                                                                                                                                                                                      |

### XMLHttpRequest

```js
let xmlhttp = new XMLHttpRequest(); 
xmlhttp.open("GET", filepath, true);
xmlhttp.onreadystatechange=handler; 
[xmlhttp.responseType=“json”|“document” |“blob”] // default text 
xmlhttp.send(null);
function handler() { 
	if(this.readyState == 4 && this.status == 200) {
	// use this.response (json/blob) or this.responseText (text) or  // this.responseXML (document) to update a part of the page 
	} 
}
```

---
## jQuery, AJAX and `fetch()` methods

jQuery provides methods that use `XMLHttpRequest` internally to make AJAX requests. 

The methods are 
- `$.ajax`
- `$.get`
- `$.post`
- `$(“elem”).load`

In a single method call, the entire functionality of making an AJAX call using XMLHttpRequest and updating the page can be achieved.

`$.ajax({name:value, name:value, ... })`

```js
$.ajax({url: "demo_test.txt", success: function(result){
	$("#div1").html(result); 
}});
```

```js
$.ajax('/jquery/submitData', { 
	type: 'POST', // http method
	data: { myData: 'This is my data.' }, // data to submit
	success: function (data, status, xhr) { // success callback function
		$('p').append('status: ' + status + ', data: ' + data); }, 
	error: function (jqXhr, textStatus, errorMessage) 
		$('p').append('Error' + errorMessage); 
	}
});
```

### `$.get`

`$.get(url, [data],[callback]);`

```js
$.get('/jquery/getjsondata', // url
	  {name:'Steve'}, // request parameters
		function (data, textStatus, jqXHR) { // success callback function
				$('p').append(data.firstName); 
			}
);
```

Other Variants 

- `$.getJSON(url, [data],[callback]);`
- `$.getScript(url, [data],[callback]);`

### `$.post`

`$.post(url,[data],[callback],[type]);`

```js

$.post('/jquery/submitJSONData', // url 
	   { myData: 'This is my data.' }, // data to be submitted 
	   function(data, status, jqXHR) { // success callback function 
		   $('p').append('status: ' + status + ', data: ' + data); }, 
		   “json”   //response type
		); 
```

Internally uses `$.ajax` with `method=“post”`

### `$.load`

Allows HTML or text content to be loaded from a server and added into an existing DOM element.

`$(‘selector’).load(url,[data],[callback],[type]);`

Example:

```js
$('#msgDiv').load('getData', // url
	{ name: 'bill' }, // data
	function(data, status, jqXGR) { // success callback function 
	console.log('data loaded') 
	} 
);
```

### fetch

Starts the process of fetching a resource from the network. Returns a promise which is fulfilled once the response is available. The promise resolves to the Response object representing the response to your request. The promise does not reject on HTTP errors — it only rejects on network errors. You must use **then** handle to check for HTTP errors.

`const fetchResponsePromise = fetch(resource [, init])`

```js
const mydiv = document.querySelector('.my-div'); 

fetch(‘resp.html') // returns a promise that resolves on response object 
	.then(function(response) { return response.text(); // returns a promise that resolves on text response
	})
	.then(function(text) { mydiv.innerHTML= text; 
});
```

---
# Web Development Stack

> A set of tools typically used in tandem to develop web apps.

Refers to the technologies that individual developer specializes in and use together to develop new pieces of software. As the web development world is continually changing, its technology stacks too change. Top web development stacks.

- Web technology sets that include all the essential parts of a modern app:
	- frontend framework,
	- backend solution
	- database (relational or document-oriented)

- MEAN
- MERN
- Meteor.js
- Flutter
- The serverless Technology stack
- The LAMP technology stack
- Ruby on Rails Tech Stack

---
## MERN

> Stands for **M**ongoDB, **E**xpress, **R**eact, **N**ode

- MongoDB - document database
- Express(.js) - Node.js web framework
- React(.js) - a client-side JavaScript framework
- Node(.js) - the premier JavaScript web server

Allows you to easily construct a 3-tier architecture (frontend, backend, database) entirely using JavaScript and JSON MERN

---
## React.JS

- Front End Library (The top tier of MERN Stack)
- The declarative JavaScript Library for creating dynamic client-side applications 
- Build up complex interfaces through 
	- simple Components
	- connect them to data on your backend server, and render them as HTML
- Strengths:
	- Handling stateful, data-driven interfaces
	- Great support for forms, error handling, events, lists, etc.

---
## Node.JS and Express.JS

- Server side Framework (The middle tier of MERN Stack) 
- Express.js server-side framework, running inside a Node.js server
- Has powerful models for URL routing (matching an incoming URL with a server function), and handling HTTP requests and responses.
- In turn use Node.js MongoDB drivers, either via callbacks for using Promises, to access and update data in your MongoDB database.

---
## MongoDB

- Database Server (The bottom tier of MERN Stack)
- Application data store(user profiles, content, comments, uploads, events, etc.) 
- JSON documents created in the front end can be stored directly in MongoDB for later retrieval through Node.JS and Express.JS.

---
## ReactJS

- An open-source JavaScript library used for building user interfaces specifically for single- page applications.
- Handles the view layer for web and mobile apps. 
- Allows developers to create large web applications that change dynamically, without the need of reloading. 
- Allows to create reusable UI components.
- Works only on user interfaces in the application.

### Properties

> Declarative, Simple, Component based, Supports server side, Mobile support, Extensive, Fast, Easy to learn.
 
> Single way data flow:
> In React JS we cannot make any change to a component directly if needed we provide a callback. 

> Actions flow up and properties flow down. The property of passing a value in the component and rendering it as HTML tags properties

## Virtual DOM

- React maintains a in-memory copy of the actual DOM known as the virtual DOM 
- Manipulating this virtual DOM is extremely fast
- React takes care of updating the real DOM when the time is right
- Compares the changes between your virtual DOM and the real DOM
-  Figuring out which changes actually matter, and making the least amount of DOM changes.

### Making a react app

Using node package manager(npm). To setup a build environment for React involves use of npm (node package manager), webpack, and Babel.

Directly importing Reactjs library in HTML Code. Defined in two .js files (React and ReactDOM) 

```html
<script src="https://unpkg.com/react@17/umd/react.development.js" crossorigin></script> 

<script src="https://unpkg.com/react-dom@17/umd/react- dom.development.js" crossorigin> </script>
```

## React Component

A user control that has code to **represent visual interfaces and data**. An isolated piece of code which can be reused in one or the other module. Contains a root component in which other subcomponents are included.

2 types of components in React.js 

- Stateless Functional Component
- Stateful Class Component

### React Component Example codes

### Stateless Functional Component

```js
function Demo(props) { 
	return <h1> Welcome to REACT JS, {props.Name} </h1>; 
	}
```

### Stateful Class Component

```js
class HelloClass extends React.Component { 
		render() { 
			return React.createElement(‘h1’, null, ’welcome to REACT JS’);
			}
		}
class Demo extends React.Component{ render() { 
	return <h1> Welcome to REACT JS, {props.Name} </h1>; 
	}
}
```

---
## Key terms

**Placeholder**: A place where the component will load 
- **Create component**: Stateless or stateful
- **Call Component**: `ReactDOM.render()` is responsible for rendering a React component. 
	- The first parameter: is a component class name. 
	- Second parameter: is the destination where the component is to be rendered.
	
In our case, we render component inside the `div id=‘root’` 

```js
ReactDOM.render( React.createElement(HelloClass, null, null), document.getElementById('root'));
```

### JSX (JS+XML)

 JavaScript Extension Syntax used to mix HTML with JavaScript. Uses HTML syntax to create elements and components. Has tag name, attributes, and children. JSX compiles the code into pure JavaScript which can be understood by the browser.

```js
<script src="https://unpkg.com/babel-standalone@6.15.0/babel.min.js"> </script> 

<script type="text/babel"> ReactDOM.render(<h1>Welcome to REACTJS</h1>, document.getElementById('root'));
```

### Babel

A JavaScript compiler that can translate markup or programming languages into JavaScript. Available for different conversions. React uses Babel to convert JSX into JavaScript. Please note that `<script type="text/babel">` is needed for using Babel

```js
<script type="text/babel">
ReactDOM.render(<h1>Welcome to REACTJS</h1>, document.getElementById('root'));
</script>
```

---
# Components

Defines the visuals and interactions that make up what the end user percieve when they use you app. 

### Need for Components 

- There may be elements which are similar
- A need to make a change in one will reflect changes in multiple places
- Similar to functions, if we could write code related to the element in one place, changes can be minimized 
- Solution: Reusable piece of JavaScript code that output (via JSX) HTML elements

### Types of Components
 
- **Stateless Functional Component**
	- Includes simple JavaScript functions and immutable properties, i.e., the value for properties cannot be changed.
	- Use hooks to achieve functionality for making changes in properties using JS. 
	- Used mainly for UI.

- **Stateful Class Component**
	- Classes which extend the Component class from React library. 
	- The class component must include the render method which returns HTML.

### First Stateful Component

Creation of a component:

```js
class HelloWorld extends React.Component {
	render() {
		return <p>Hello, componentized world!</p>; 
	} 
}
```

Calling a component: Add the JSX in the render method with a element with the tag name as the Component name

```js
ReactDOM.render( <HelloWorld/>, document.querySelector("#container") );
```

### Parameterized components

 Accepting the properties in the component and passing these properties while calling the components
 
Creation of a component: 

```js
class HelloWorld extends React.Component { render() { return <p>Hello, {this.props.greetTarget}!</p>; } } • Calling a c
```

Calling a component: 

```js
ReactDOM.render( <div> <HelloWorld greetTarget="Batman"/> <HelloWorld greetTarget="Iron Man"/> </div>, document.querySelector("#container") )
```

### Components with Child elements

Creation of a component: 

```js
class Buttonify extends React.Component { render() { 
	return(
		<div><button type={this.props.behavior}>{this.props.children}
		</button></div>
	); 
	} 
} 
```

Calling a component:

```js
ReactDOM.render(
<div> <Buttonify behavior="submit">SEND DATA</Buttonify> </div>,
document.querySelector("#container")
```

---
## Usage of props.children

- Used to display what you include data between the opening and closing JSX tags when invoking a component. 
- A special property that is passed to components automatically 
- Can have one element, multiple elements, or none at all. 
- It’s value is respectively a single child node, an array of child nodes or undefined.

### Introduction to Properties

- Properties are ways in which React components **can be customized**. 
- Props are arguments passed into React components and are passed via HTML attributes.
- Properties are immutable and are same as what attributes are to HTML elements. 
- Their most basic use is in the form of attributes, in JSX. 
- Are actually passed to a constructor and can be accessed by `this.props` 
- Design decision is to use the Attributes specified in hyphen-case in HTML as camelCase in JSX.
- 2 steps to add properties to components 
	- Make the function of your component read the props from the props parameter 
	- When rendering the component, add the prop to the component using the attribute.

### Validating and Setting the property values

Props validation is a tool that will help the developers to avoid future bugs and problems. Validating the type of properties is possible by providing any of the types in **React.PropTypes**

```js
class App extends React.Component { 
	render() {} 
	} 
	Component.propTypes = { /*Definition */};
```

- Setting the default property values
	- Can be overridden by properties passed in initialization using **getDefaultProps()** method.
	- Must return an object. The contents of that object are up to us

### Transferring Properties

- Sending properties down the structural tree while working with multiple components in a hierarchy.
- The properties have to flow down from its parent to every child component that lies on the intended path 
- **transferPropsTo()**: 
	- Passes all the properties of a parent component to a child component unless we explicitly set the value of a child component’s property.
	- ReactComponent transferPropsTo(ReactComponent targetComponent)

---
# Styling the Components and Complex Components

Different ways to style React Components 

- Inline CSS: using style attribute
- CSS in JS: using Libraries JSS and Styled Components 
- CSS modules – css loader and Sass & SCSS 
- Stylable

## Inline CSS

In inline styling we create objects of style and render it inside the components in style attribute using the React technique. In JSX, JavaScript expressions and objects are written inside curly braces the styling is written inside two sets of curly braces `{{}}`.

```js
class MyHeader extends React.Component {
		render() { return ( 
			<h1 style={{color: "red"}}>Hello Style!</h1>
			<p>Add a little style!</p>
		);
	}
}
```

camelCased Property Names

```js
<h1 style={{backgroundColor: "lightblue"}}>Hello Style!</h1>
```

Creation of JavaScript object which contains the css properties and values in the form of key value pair. Passing this as a value to style attribute

```js
class Letter extends React.Component { render() {
	var letterStyle = { padding: 10, 
						margin: 10,
						backgroundColor:"#ffde00",
						color: "#333“,
						display: "inline-block“,
						fontFamily: "monospace",
						fontSize: 32, textAlign: "center“ 
					  }; 
	return(<div style={letterStyle}> {this.props.children} </div>); 
	}
}
```

---
## Complex Components

Combining components to create the complex one 

- Advantage is composability 
- Approach 
	- Identify the major visual elements 
	- Breaking them into individual components

```js
class SrchResult extends React.Component { 
	render() { 
		return (<div><ResImage/><ResCaption/><ResLink/></div>);
	}
}
```

### Subcompenents

```js
class ResImage extends React.Component {
	render() {
		return (<div> <img src=“tiger.jpg”> </img> </div>);
	}
} 
```

```js
class ResLink extends React.Component { 
	render() {
	return (
	<div><a href="https://www.britannica.com/animal/tiger"> britannica.com
	</a></div>);
	}
}
```

```js
class ResCaption extends React.Component { 
	render() { 
		return (<div> <p>tiger | Facts, Information and Habitat…</p> </div>
		); 
	} 
}
```

### Properties from parent to sub component

To avoid hard coding, properties have to be passed from parent components to it’s sub components.

![](Pasted%20image%2020240920211441.png)

![](Pasted%20image%2020240920211452.png)

![](Pasted%20image%2020240920211505.png)

![](Pasted%20image%2020240920211512.png)

### Transferring Properties

Transferring properties was not a tedious as there was only one level of hierarchy 

- If there are multiple levels of components, transferring properties will be very cumbersome.
- To overcome that, we use the `spread operator (…)` `<Display {...this.props}/>`
