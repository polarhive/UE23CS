# HTML, CSS and Client Side Scripting

## Introduction to Web Architecture

- **URL** stands for Uniform Resource Locator
- General form: `scheme:object-address`
- For the http protocol the object-address is: `fully qualified domainname/docpath`

## General Web Server Characteristics

Web servers have two main directories:

1. Document root (servable documents)
2. Server root (server system software)

Document root is accessed indirectly by clients

- Its actual location is set by the server configuration file
- Requests are mapped to the actual location

### DNS lookup?

1. OS Recursive Query to DNS Resolver
2. DNS Resolver Iterative Query to the Root Server
3. Root Server Response
4. DNS Resolver Iterative Query to the TLD Server
5. TLD Server Response
6. DNS Resolver Iterative Query to the Google.com NS
7. Google.com NS Response
8. DNS Resolver Response to OS
9. Browser Starts TCP Handshake

---

# Web protocols

> A protocol is a set of rules and guidelines for communicating data. Different applications use different protocols. The web, in particular, uses multiple protocols to communicate. The most important and visible protocols are HTTP and HTTPS.

## HTTP: HyperText Transfer Protocol

Application Layer Protocol used by the Web

> [!Warning]
> The server maintains no information about past client requests

**Client/Server model**

- Client: browser that requests, receives, and “displays” Web Objects
- Server: Web server sends Web Objects (using HTTP protocol) in response to requests

**HTTP runs on TCP:**

- A client initiates TCP connection (creates socket) to server, port 80
- The server accepts TCP connection from client
- HTTP messages (application- layer protocol messages) exchanged between browser (HTTP client) and Web server (HTTP server)
- TCP connection closed

---

# HTTP Request Response Formats, URLs

> [!structure]
> HTTP requests contain a request line, followed by zero or more request headers

- Request line: `<method> <uri> <version>`
- - `<version>` is HTTP version of request (HTTP/1.0 or HTTP/1.1)
- - `<uri>` is typically URL for proxies, URL suffix for servers.
- - `<method>` is either GET, POST, OPTIONS, HEAD, PUT, DELETE, or TRACE.
- Request Header
- Blank line (CRLF)
- Message Body

> [!response]
> HTTP response is a response line followed by zero or more response headers.

- **Response line:**
- `<version> <status code> <status msg>`
- `<version>` is HTTP version of the response.
- `<status code>` is numeric status.
- **Response headers:**
- `<header name>: <header data>`
- Provide additional information about response
- Content-Type: MIME type of content in response body.
- Content-Length: Length of content in response body.

## HTTP methods
- **GET**: Retrieve static or dynamic content
- **POST**: Send content to server through request body
- **OPTIONS**: Get server or file attributes
- **HEAD**: Fetches only header field without any response body
- **PUT**: Write a file to the server
- **DELETE**: Delete a file on the server

## Status Codes

Three-digit number: first digit specifies the general status

- 1 => Informational
- 2 => Success
- 3 => Redirection
- 4 => Client error
- 5 => Server error

> [!Example]
>
> - `<status msg>` is corresponding English text.
> - 200 OK => Request was handled without error
> - 403 Forbidden => Client lacks permission to access file
> - 404 Not found => Server couldn’t find the file.

---

# Basic Mark-up & syntax

**Markup** lets you define elements within a document using tags.

**Hypertext**: cross-referencing /linking between related sections of text and associated graphic material

> [!Elements are defined by tags (markers)]
>
> - Opening tag: `<tag_name>`
> - Closing tag: `</tag_name>`

## Syntax

- `<tag_name>` content… `</tag_name>`
- Not all tags have content, if a tag has no content, its form is `<tag_name/>`
- The container and its content together are called an element

---

# HTML elements & attributes

| Element | Description                                                        |
| ------- | ------------------------------------------------------------------ |
| html    | Surrounds the entire page                                          |
| head    | Contains header info: metadata, CSS, JS                            |
| title   | Displayed on the browser's titlebar and shows up in search engines |
| body    | Content of your website, all visible parts of the page live here   |

---

# HTML5 New Tags

Introduces 28 new elements such as:  `<header><footer>,<article>,<nav>,<section>,<time>,<audio>,<video>,<output>`

| Element | Description                  |
| ------- | --------------------------- |
| Article | Defines an article          |
| Footer  | Copyright, colophon         |
| Header  | Page header                 |
| Nav     | Navigation bar              |
| Section | Part/Chapter of the content |

---

# Web Form

> [!Form]
 > A form is a way to send information from a browser to a server. All the components of a form appear as the content of `<form>` tag. The components are called widgets (e.g., text boxes, radio buttons and checkboxes)
 >
> Important attributes of the `<form>` tag
>
> - Method
> - Action
> - Target

```html
<form method=“post” action=“survey.php” target=“_blank”>
 <input type=“text”>
</form>
```

# Response Methods

## GET

> [!Warning]
> NEVER use GET to send sensitive data! (the submitted form data is visible in the URL!

- Appends the form data to the URL, in name/value pairs. )
- The length of a URL is limited (2048 characters)
- Useful for form submissions where a user wants to bookmark the result
- GET is good for non-secure data, like query strings in a Google search

# POST

- Appends the form data inside the body of the HTTP request (the submitted form data is not shown in the URL)
- POST has no size limitations, and can be used to send large amounts of data.
- Form submissions with POST cannot be bookmarked

---

# Inputs, Elements and Controls

> [!Example]
> HTML5 specifications introduced new ***Input types*** and properties:
>
> - email: email address
> - number: spinbox
> - range: slider
> - url: web addresses
> - color: color pickers
> - search: search boxes
> - date: date
> - time: time
> - file: input file selection
> - Tel: phone no.

Format: `<input type="">`

| Type     | Description                     |
| -------- | ------------------------------- |
| text     | Single line input field         |
| radio    | Radio button, one of the choice |
| checkbox | Checkbox, 0 or more             |
| submit   | Submit                          |
| button   | Button                          |

| Attribute   | Description                       |
| ----------- | --------------------------------- |
| Min, Max    | Limits                            |
| Multiple    | Allow selection of multiple files |
| Pattern     | Regex validation                  |
| Placeholder | Hints to aid with data entry      |
| Required    | Mandate response                  |
| Step        | Granularity                       |

# Form validation/regex

1. Number: `<input type="number" min="1" max="10">`
2. Email: `<input type="email"`
3. Range: `<input type="range" min="1" max="10"`

---

# CSS 3.0: Styles & Style sheets

Inline Style - CSS is placed directly into the HTML element.

1) Internal Style Sheet /Embedded Style Sheet - CSS is placed into a separate area within the `<head>` section of a web page using `<style>` tag.

2) External Style Sheet - CSS is placed into a separate file and "connected" to a web page.

## Conflict resolution

Same formatting rules can be defined in all three locations at the same time.

> [!NOTE] Example
> A paragraph element could contain an inline style `(color:red)` but the internal style sheet `(color:blue)` and the external style sheet `(color:green)` give conflicting instructions to the web browser.

> Web browsers need a consistent way of "settling" this disagreement.

We use the term cascading because there is an established order of priority to resolve these formatting conflicts:

 1. Inline style (highest priority)
 2. Internal style sheet (second priority)
 3. External style sheet (third priority)
 4. Web browser default (only if not defined elsewhere)

---

## Selectors, Style properties

Every CSS rule begins with a **selector**. The selector identifies which element or elements in the HTML document will be affected by the declarations in the rule

### Primary Selectors: Select by Tag

``` html
<span>Here's a span with some text.</span> <p>Here's a p with some text.</p> <span>Here's a span with more text.</span>
```

### Primary Selectors: Select by ID

```html
<span id="top">Here's a span with some text.</span> <span>Here's another.</span>
```

### Primary Selectors: Select by Class

> The `.class` selector selects elements with a specific class attribute. To select elements with a specific class, write a period (.) character, followed by the name of the class.

```html
<span class="sky">Here's a span with some text.</span> <span> Another <span class="code">&lt;span&gt;</span>. </span>
```

```css
span.sky { background: DodgerBlue; } .code { font-family: Consolas; }
```

## Pseudo-class selector

A pseudo-class is used to define a special state of an element. For example, it can be used to style an element when a user hovers over it.

> Syntax: `selector:pseudo-class { property:value; }`

> [!NOTE]
> The order of these pseudo-class elements is important. • The `:Link, :Visited, :Focus, :Hover` Order of pseudo-classes.

### Nested Selectors: Descendant

```css
div.items a { color: green; font-weight: bold; }
```

```html
<div class="items"> <a href="#">Item1</a> <a href="#">Item2</a> <a href="#">Item3</a> <ul> <li><a href="#">Item4</a></li> <li><a href="#">Item5</a></li> <li><a href="#">Item6</a></li> </ul> </div>
```

### Nested Selectors: Direct Child

```html
<div> <span>Span #1, in the div. <span>Span #2, in the span that's…</span> </span> </div> <span>Span #3, not in the div at all.</span> div > span { background: DodgerBlue; } span { background: #fff; } Direct child of <div> <span> directly contained in a <div>
```

```css
div > span { background: DodgerBlue; } span { background: #fff; }
```

### Multiple Selectors (Element, Element)

```html
<h1>Welcome…</h1> <h2>My name is…</h2> <p>I live in Duckburg.</p> <p>My best friend is…</p>
```

```css
h1, h2, p { background: yellow; }
```

---

## Box Model

![box model](Pasted%20image%2020240916024819.png)

All HTML elements can be considered as boxes. The term “box model” is used when talking about design and layout. It allows us to add a border around elements and define space between elements.

> CSS box model is essentially a box that **wraps** around every HTML element. It consists of:

- Margins
- Borders
- Padding
- Actual Content

## Div and Span

> There are two elements used commonly to style specific parts of a webpage
> `<span>` To apply style to a part of a paragraph In-line element `<div>` To apply style to a set of elements or paragraphs

### Block-level elements

- A block-level element always starts on a new line, and the browsers automatically add some space (a margin) before and after the element.
- A block-level element always takes up the full width available (stretches out to the left and right as far as it can). Some example block-level elements are: `<div>, <h1>-<h6>, <p>, <ul>, <nav>` In-Line elements
- An inline element does not start on a new line.
- An inline element only takes up as much width as necessary.
- Some example inline-level elements are: `<span>, <a>, <input>,<button>,<img>`
- Block element cannot be nested inside an inline element;

### Position Property CSS – Box Model and Position Property

- By default, the browser determines the positioning of each element
- CSS introduced the position property and a capability to control how and where page elements are displayed

### Position property values

- Static: default value. Elements are positioned in the normal flow of the document
- Absolute: relative to the nearest positioned ancestor. Removed from normal flow
- Relative: is positioned relative to its normal position.
- Fixed: it always stays in the same place.
- Sticky- toggles between relative and fixed, positioned relative until a given offset position is met in the viewport - then it "sticks" in place.

### Element Width and Height CSS – Box Model and Position Property

> [!NOTE] Total width of an element is calculated as
> - Total element width = width + left padding + right padding + left border + right border + left margin + right margin

- The total height of an element is calculated as:
- Total element height = height + top padding + bottom padding + top border + bottom border + top margin + bottom margin
- This `<div>` element will have a total width of `350px: div { width: 320px; padding: 10px; border: 5px solid gray; margin: 0; }`
- Calculation: `320px (width) + 20px (left + right padding) + 10px (left + right border) + 0px (left + right margin) = 350px`


### CSS provides control over the backgrounds of block-level elements

- CSS can set a background color or add background images to HTML5 elements.
- Different properties:
- background-image
- background-position
- background-repeat
- background-attachment

### Length Units CSS

- Box Model and Position Property
- CSS has several different units to represent lengths.
- Most CSS properties take length values, such as width, margin, padding, font-size, etc.
- Each length value is followed by a length unit.
- Negative lengths are allowed only for some CSS properties only.

### Length Units CSS: Box Model and Position Property

Absolute length units These are fixed and the length expressed in this format will appear of the same size Unit Description Calculation cm centimeters

> [!Important] Important conversions
> - 1cm = 96px/2.54 mm millimeters
> - 1in = 2.54cm = 96px px
> - 1px = 1/96th of 1in
> - 1pt = 1/72nd of 1in
> - 1pc = 12pt = 1/6th of 1in

### Length Units CSS – Box Model and Position Property

Relative length units Relative length expressed in this format will appear relative to other reference elements Unit Description em Relative to the font-size of the element (2em is 2 times current font) ex Relative to the x-height of current font ch Relative to width of the “0” (zero) rem Relative to the font-size of the root element % Relative to the parent element

---

## JavaScript Basics(variables, scope, Builtin Objects)

> Client Side Scripting Language - Originally, LiveScript in NetScape Browser - JavaScript programs are run by an interpreter built into the user's web browser - Now the language has evolved with additional Server Side Scripting capabilities (like in Node.JS

## Pros and Cons of JavaScript

- Pros: Allows more dynamic HTML pages, even complete web applications
- Cons: Requires a JavaScript-enabled browser (requires a client) who trusts the server enough to run the code the server provides -
- JavaScript has some protection in place but can still cause security problems for clients

## JavaScript Basics

1. HTML to define the content of web pages
2. CSS to specify the layout of web pages and give a good look.
3. JavaScript to program the behavior of web pages
4. Web pages are not the only place where JavaScript is used.

```html
<html> <head> <title>Hello World in JavaScript</title> </head> <body> <script type="text/javascript"> document.write("Hello World!"); </script> </body> </html>
```

---

## Interpreting JS

JavaScript generally automatically inserts semicolons at the end of line

```js
x += 10 => x += 10;
```

However, when you wish to place more than one statement on a line, you must separate them with semicolons, like this:

```js
x += 10; y -= 5; z = 0
```

When a statement spans across multiple lines, JavaScript will not raise error if the next line has a valid symbol/literal/token

```js
return a
  + b
```

The first character of a variable name can be only a-z, A-Z, $, or _ . -- Then followed by only the letters a-z, A-Z, 0-9, the $ symbol, and the underscore _. − Variable names are case-sensitive. Count, count and COUNT are three different variables

## Declaration

Variable can be declared using − let (block scope) − var (function or global scope) − Const(block scope) − use without declaring (global scope)

![](Pasted%20image%2020240916025513.png)

> [!Warning]
> JS is loosely typed or dynamic typed

- Primitive Datatypes
	- number
	- string
	- boolean
	- null
	- undefined
- Non-Primitive Datatypes (used with new keyword)
	- Object
	- Boolean
	- Number
	- String
	- Date
	- Array

---

## Operators and Constructs

JavaScript has most of the operators we're used to from C/Java

```js
− Arithmetic (+, - , *, /, %)
− Assignment (=, +=, -=, *=/=, %=, ++, --)
− Logical (&&, ||, !)
− Comparison (<, >, <=, >=, ==, ===,!=,!==)
− Constructs: if, else, while, for, switch, case
```

> [!Important]
> Use `+` to do concatenation if one of the operands is string

```js
let length = 16; // Number
let lastName = "Johnson"; // String
let x = 16 + "Volvo";

```

Output: 16Volve

> When adding a number and a string, JavaScript will treat the number as a string.

```js
let x = "Volvo" + 16; Output: Volve16 let x = 16 + 4 + "Volvo";
```

Output: 20Volve

```js
let x = "Volvo" + 16 + 4;
```

Output: Volve164

> In the first example, JavaScript treats 16 and 4 as numbers, until it reaches "Volvo".
>
> In the second example, since the first operand is a string, all operands are treated as strings.

### Loops

1. for - loops through a block of code a number of times
2. for/in - loops through the properties of an object
3. while - loops through a block of code while a specified condition is true
4. do/while - also loops through a block of code while a specified condition is true

```js
var person = {fname:"John", lname:"Doe", age:25}; var text = ""; var x; for (x in person) { text += person[x]; }
```

### Strict ineq

```js
=== vs ==
```

### Array

Arrays are lists of elements indexed by a numerical value starting with 0 to (length of the array – 1)

- Arrays can be created using the new Array method
- `let arr = new Array(100)` creates an array of 100 elements
- `let arr = new Array(10, 20)` creates an array of 2 elements
- Literal arrays using square brackets
- `var alist = *1, “ii”, “gamma”, “4”+;

### Array length property can be modified at runtime

Hence, the length property does not necessarily indicate the number of defined values in the array the array

```js
const arr = [1, 2]; console.log(arr); // [ 1, 2 ] arr.length = 7; 
console.log(arr); // [ 1, 2, <5 empty items> ]
Array Length JavaScript – Arrays console.log(arr[4]); //undefined for (i in arr)
console.log(typeof i + i)); // string 0 // string 1
```

### Functions

Whenever you have a relatively complex piece of code that is likely to be reused, you have a candidate for a function.

The general syntax for a function is:

```js
function function_name([parameter [, ...]]) { statements //optional return statement }```

The general syntax for calling a function is: `[retval =] function_name(*argument *,…++)`


```

### Parameter / Args

Argument list and parameter list mismatch does not give errors. Parameter that is not passed a value in arguments list is treated as undefined To access additional arguments, use the arguments object or the args array to access the values passed.

```js
function func() { // access passed values // using arguments object } 

Parameters and Arguments JavaScript - Functions function func(…args) { // access passed values // using args array 
}
```

### Hoisting

Hoisting is JavaScript's default behavior of moving all variable and function declarations to the top of the current scope (to the top of the current `<script>` or the current function).

Only declarations are hoisted not initializations. Variables and constants declared with let or const are not hoisted!

---

## JavaScript objects and Prototypal Inheritance

In JavaScript, almost "everything" is an object. Booleans can be objects (if defined with the new keyword) Numbers can be objects (if defined with the new keyword). Strings can be objects (if defined with the new keyword). Dates are always objects. Arrays are always objects. All JavaScript values, except primitives, are objects.

An object in JavaScript is a reference data type. An object can be compared to any real world entities. An object is an unordered list of properties consisting of a name (always a string) and a value. When the value of a property is a function, it is called a method.

```js
Var object1= new Object(); Var object2 = object1;
```

A variant of object literal syntax. Specifies object members and their values inside the curly brackets as key-value pairs. A member and its value are delimited using colon `(:)` character.

JavaScript functions are objects themselves. It can be called as a Constructor Function. Once the function constructor is created you create object of that function using new keyword. The function name uses camel case convention

## Prototype Property

Prototype property of an object holds the structure of that object. It is shared by all object instances created using that constructor. This can be used to modify/add properties to all instances after they have been created. Methods should be added to prototype since only one copy of the method is created. If methods are added to constructor, each object instance holds its own copy of the method. `Employee.prototype.showName = function(){…}`

## Builtin objects

`Math - Number - String - Array - Date - window - document`

```js
Array methods
Looping
Sort
Number
NaN
String Object
Date methods
Math
```

---

## DOM Manipulations

When a web page is loaded, the browser creates a Document Object Model of the page. The HTML DOM model is constructed as a tree of Objects. The HTML DOM is a standard object model and programming interface for HTML.

It defines: The HTML elements as objects. The properties of all HTML elements. The methods to access all HTML elements. The events for all HTML elements

> *The W3C Document Object Model (DOM) is a platform and language-neutral interface that allows programs and scripts to dynamically access and update the content, structure, and style of a document.“*

A Web page is a document. This document can be either displayed in the browser window or as the HTML source. But it is the same document in both cases. The DOM is an object-oriented representation of the web page, which can be modified with a scripting language such as JavaScript.

`document.write` executed after the page has finished loading will overwrite the page, or write a new page, or not work. `document.write` practically only appending to the page

Objects have properties and methods, and respond to events. Properties – specify attributes or characteristic of object. Methods – specify functions object can perform. Events methods corresponding to user actions.

## DOM Elements are Objects

- `write(“string”)` writes the given string on the document
- `getElementById()` returns the element having the given id value.
- `getElementsByName()` returns all the elements having the given name value.
- `getElementsByTagName()` returns all the elements having the given tag name.

### Accessing Elements

```js
#demo getElementByID(“demo”) Class .demo getElementsByClassName(“demo”) Tag 

<tag name> like p getElementsByTagName(“p”) Selector (single) Any CSS Selector querySelector(“selector”) Selector (all) querySelectorAll(“selector”)
```

### Traversing the DOM

### Creating Element Objects

### Manipulating Nodes in the DOM

---

## Events and Event Handling in JavaScript

Events Examples of HTML events:

- When a user clicks the mouse, when a web page has loaded. When an image has been loaded.
- When the mouse moves over an element.
- When an input field is changed
- When an HTML form is submitted
- When a user strokes a key

> Events are created by activities associated with specific HTML elements. The process of connecting an event handler to an event is called registration.

There are two distinct approaches to event handler registration:

- Assign element attributes. Inline event handlers.
- Assign handler addresses to object properties. Event handler properties and Event listeners.

There are three ways to assign events to elements:

- Inline event handlers
- Event handler properties
- Add Event listeners

### An element can be assigned the event handler property element

The `.on<event> = handler;`

- It involves two parts: the correct event name it is to be listening for
- The handler callback function.
- For example: `div.onclick = change;` or `div.onmouseover = function(){ … };`

## Event Listeners

An event listener watches for an event on an element.

 `element.addEventListener(event, handler)`

 It takes two mandatory parameters: the event it is to be listening for, the handler callback function

```js
div.addEventListener(“click”, change); div.addEventListener(“keypress”, function(){ … });
  
```

### Event Sources

Source Event Fires When Mouse click the mouse is clicked and released on an element dblclick an element is clicked twice mousemove every time a mouse pointer moves inside an element mouseover every time a mouse pointer is placed over an element Keyboard keydown when a key is pressed down keyup when a key pressed is released keypress when a key is pressed and released Form submit a form is submitted reset a form reset button is clicked focus an input element is clicked and receives focus blur an input element loses focus

## Event object holds the context or details of the event

`target srcElement` the target of the event (most specific element).

Type: the name of event fired (without the on prefix) altKey / shiftKey / ctrlKey / metaKey - true/false to signify if Alt Key or Shift Key or Ctrl Key or Meta Key was pressed charCode keyCode Unicode character code of the pressed key key - Key Character Name (‘a’ or ‘F1’ or ‘CAPS LOCK’) button - Returns which mouse button was pressed clientX, clientY / offsetX, offsetY / screenX, screenY - the coordinates of the mouse pointer when the event

triggered, relative to, the current window / target element / screen.

---

## Event handling

Ways of event propagation in the HTML DOM

- Event bubbling
- Event capturing.
- Target Phase

Propagation is a mechanism that defines how events propagate or travel through the DOM tree to arrive at its target. Event propagation is a way of defining the element order when an event occurs. `<div> <p> /<p> </div>`

> If both `<p> and <div>` elements registered Click event, which element's "click" event should be handled first?

### Event Handling bubbling

Inner most element's event is handled first and then the outer: the `<p>` element's click event is handled first, then the `<div>` element's click event. capturing the outer most element's event is handled first and then the inner: the `<div>` element's click event will

> There are three phases in which an event can propagate to handlers defined in parent elements:

- Capturing phase
- Target phase
- Bubbling phase

```js
elem.addEventListener(“event”, func_ref, flag); flag = true :=> Handler registered for Capturing phase flag = false:=> Handler registered for Bubbling phase (default)
```

### Event Capturing Event Flow

The `eventPhase` event property returns a number that indicates which phase of the event flow is currently being evaluated.

The number is represented by 4 constants: 0 NONE 1 CAPTURING_PHASE. The event flow is in capturing phase 2 AT_TARGET The event flow is in target phase, i.e. it is being evaluated at the event target 3 BUBBLING_PHASE The event flow is in bubbling phase

> IE5-8 Equivalent Purpose `cancelBubble`. A historical alias to `stopPropagation()`.
>
> Setting its value to true before returning prevents propagation `eventPhase` - Specifies which phase of the event flow is being processed cancelable.
>
> Not supported Indicates whether you can cancel the default behavior of an element `preventDefault()` `returnValue`.
>
> It cancels the default behavior of the event (if possible) `stopPropogation()` `cancelBubble` It stops any further bubbling/ capturing of the event. Event Object Properties.