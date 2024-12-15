
a)  Use HTML to create a document that contains the following poem by Sir Walter Scott

My Native Land
Breathes there the man, with soul so dead,
Who never to himself hath said, This is my own, my native land!
The page should be designed such that

(i)  The title of the page should be “Poems by Sir Walter Scott”
(ii)  “My Native Land” is displayed as a heading
(iii)  A line should be displayed below the heading
(iv)  The remaining content should be displayed in a paragraph
(v)  The poet’s name should be displayed in italics on the page

Underline the tags that you have used.

b)  “Span and div elements have the exact same  effect when applied around a body of text”.
Accept or reject this statement with suitable justification.

c)  What  are  the  three  approaches  to  applying  styles  to  a  given  HTML  page?  Explain  each  one briefly.

d)

```css
#xyz {
margin: 0;
padding: 3px;
font-family: "Times New Roman", "Times Roman", Roman, serif;
color: #000;
}
```

Based on the code snippet above answer the following questions

(i)  Which selector is used in the above code?
(ii)  What does this statement indicate   padding: 3px;
(iii)  Write  a single line of HTML code that applies the given style to a heading containing the text “Life is beautiful”

2.a)  Complete the code given below to calculate and display the sum and product of a and b 

```js
<script type=”text/javascript”>
     var a=window.prompt(“Enter first value”);
     var b=window.prompt (“Enter second value”);
//TODO: Display the sum and product of a and b

</script>
```

b)

Explain substring and substr functions in Javascript. What is the output of the following script ?

```js
<script type="text/javascript">
         var str = "Apples are round, and apples are juicy.";
         document.write("(1,2): "    + str.substr(1,2));
         document.write("<br />(0,10): "   + str.substring(0, 10));
         document.write("<br />(5): "      + str.substring(5));
 </script>
```

c)  Using  Javascript’s Date object write a program to display the current time in AM/PM format.

e.g If it is 2:45 in the afternoon the script should display 2:45 PM

d)  Using the built-in sort method of the array object to sort the given array in ascending order and display it.

```js
<script type=”text/javascript”>
 var a=[100,89,34,22,140,32,67,199,30]
//TODO: sort the array and display it
</script>
```

3.a)  Write a program using JavaScript and HTML  which contains a button and  a div.  Each time the button is clicked the value in the div must  be increment by 1.

Sample Output:

b)  Mr. X designed the following webpage called page.html.

```js
<html>
   <head>
      <title>Your Title Here</title>
   </head>
   <body>
     <img src="clouds.jpg” id=”sky”>
     <a href="http://somegreatsite.com">Link Name</a> is a link to another nifty site
     <h1 id="name">My name is Alpha</h1>
      <h2 id="fame">I am famous</h2>
       <p id="normal"> This is a normal paragraph! </p>
        <p id="bold">This is a bold paragraph! </p>
     </body>
</html>
```

Help him  write a function change() using only javascript  that can  make the following changes to the DOM of page.html

i)Create a new div whose id is extra. Add the two paragraph elements to this div

ii)Change the image elements source to “sky.jpg”

iii) Remove the h2 element from the page

iv) Change the font color of h1 to red.

c) In  the  context  of  event  handling  what  does  “this”  signify?For  a  given  event  e  what  do  the following properties signify

i)ctrlKey
ii)cancelBubble
iii)keyCode
iv)type
v) screenX

4.  
a) What is client-side scripting? List any three limitations of client-side scripting
b) “Cookies have a number of limitations”. How does HTML5 propose to solve these. Explain.
c)  What are the two types of gradients that can be used on an HTML5 canvas? Complete the given code snippet such that a square with each side 50 pixels is created at coordinates (10,10) on the canvas. Apply a black and white gradient to the square.

```js
<script>
var c=document.getElementById("myCanvas");
var ctx=c.getContext("2d");
var grd=ctx.createLinearGradient(0,0,170,0);

//TODO: Apply a black and white gradient to the square.
</script>
```

d)  Why is a cache manifest required? What are its three parts?

5.  
a)  `https://www.example.com/login.php?user=mickey&passwd=mini`

The URL shown above was displayed in the address bar after submitting an HTML form.
(i)  Which two methods can be used for submitting a form?
(ii)  Which method was used to submit the form referred to above.
(iii)  Write a PHP script to print the two values passed in the query string shown above

b)  What  type  of  array  is  required  for  representing  the  data  shown  below?  How  are  they  different from normal arrays?  Write a PHP script to create an array called $data containing the data given below and then print the contents of the array.

> Hint: You may use for loop or foreach loop for printing the array

K
Na
Ca
Potassium
Sodium
Calcium

c)  What are regular expressions? Name any two functions in PHP used for searching a string.

d)  What are cookies? Explain how cookies are created and deleted in PHP.

---


14CS204

SEMESTER END EXAMINATION (SEE) B.E. III SEMESTER- Nov. 2015

14CS204 – Web Technology I

Note: All answers must be precise and to the point.

1.a)  Use HTML to create a document that contains the following poem by Robert Frost

Stopping By Woods On A Snowy Evening

The woods are lovely, dark, and deep, But I have promises to keep,

And miles to go before I sleep, And miles to go before I sleep.

The page should be designed such that

(i)  The title of the page should be “Poems by Robert Frost”
(ii)  “Stopping By The Woods On A Snowy Evening” is displayed as a heading
(iii)  A line should be displayed below the heading
(iv)  The remaining content should be displayed in a paragraph
(v)  The poet’s name should be displayed in italics on the page

Underline the tags that you have used.

b)  “The only way to apply CSS is by using external stylesheets” Accept or reject this statement with suitable justification.

c)  Explain box model with a suitable diagram.

d)

```css
.ids {
margin: 8px;
padding: 0 3px 0 3px;
font-family: "Times New Roman", "Times Roman", Roman, serif;
color: #000;
}
```

Based on the code snippet above answer the following questions

(i)  Which selector is used in the above code?
(ii)  What does this statement indicate   margin:8px;
(iii)  Write  a single line of HTML code that applies the given style to a paragraph containing the text “Welcome to My World”

2.  a)  Complete the code given below to calculate the area and circumference of a circle

```js
<script type=”text/javascript”>
     var radius=window.prompt(“Enter the value”);
//TODO: Display the area and circumference of circle for the given radius

</script>
```

b) Explain substring and substr functions in Javascript. What is the output of the following program?

```js
<script type="text/javascript">
         var str = "Do good to others to feel good about yourself";
         document.write("(3,4): "    + str.substr(3,4));
         document.write("<br />(0,10): "   + str.substring(0, 10));
         document.write("<br />(8): "      + str.substring(8)); 
</script>
```

c)  Using  Javascript’s Date object write a program to display the current time in AM/PM format. e.g If it is 2:45 in the afternoon the script should display 2:45 PM

d)  Using the built-in sort method of the array object sort the given array in descending order.

```js
<script type=”text/javascript”>
 var a=[100,89,34,22,140,32,67,199,30]
//TODO:
</script>
```

3.  a)  Write a program using JavaScript and HTML which contains a button. When the button is clicked a div with a solid black border that is 2 pixels wide  should be added to the page.

b)  Walt Disney designed the following webpage called page.html.

```html
<html>
   <head>
      <title>It’s a Small World </title>
   </head>
   <body>
     <img src="disney.jpg” id=”goofy”>
     Welcome to <a href="http://smallworld.com">Small World</a>
     <h1 id="name">Disney Small World</h1>
      <h2 id="fame">Unity in Diversity</h2>
       <p id="rides"> Rides Every Hour </p>
        <p id="shows">Shows in the afternoon </p>
     </body>
</html>
```

Help  him  to  write  a  javascript  function  modify()    that  can    make  the  following  changes  to  the DOM of page.html

i)Create a new div whose id is smw. Add the two paragraph elements to this div
ii)Change the image elements source to “small.jpg”
iii) Remove the h1 element from the page
iv) Change the font color of paragraph to red.

c)  What is an event object? For a given event e what do the following properties signify

i)altKey
ii)cancelBubble
iii)keyCode
iv)type
v) client


a)  What is server side scripting? When do we use it?
b)  Tom  is  a  website  designer.  He  wants  to  store  the  user’s  choice  for  font  color  on  the  user’s machine.  He does not want to use cookies. What other technology can Tom use? What are the advantages of using this technology?

c)  What are the two types of gradients that can be used on an HTML5 canvas? Complete the given code snippet such that a square with each side 50 pixels is created at coordinates (50,50) on the canvas. Apply a green and blue gradient to the square.

```js
<script>
var c=document.getElementById("myCanvas");
var ctx=c.getContext("2d");
var grd=ctx.createLinearGradient(0,0,170,0);

//TODO: Apply a blue and green gradient to the square.
</script>
```

d)  What is offline browsing? Why is a cache manifest required for offline browsing? What does the cache manifest contain?

5.  a)  https://www.example.com/login.php

The  URL  shown  above  was  displayed  in  the  address  bar  after  submitting  an  HTML  form containing two fields named username and password.

1. Which two methods can be used for submitting a form?
2. Which method is used in the form shown above
3. Write a  PHP script to print the two values submitted in the form.

b)  What  kind  of  array  is  required  for  representing  the  data  shown  below?  How  are  they  different from  normal  arrays?    Write  a  PHP  script  to  create  an  array    called  $data  containing  the  data given below  and then print the contents of the array.

Hint: You may use for loop or foreach loop for printing the array

France
Italy
Japan
Paris
Rome
Tokyo

c)  What are regular expressions? Name any two functions in PHP used for searching a string.

d)  With respect to cookies answer the following questions
(i)  How can they be created?
(ii)  How are they deleted?
(iii)  How can you access the values stored in cookies?

---
UE18CS204 - Web Technologies - I

1.a. How to create tables using HTML? Write HTML code to design the table shown
below.

1.b. What is HTTP requests and HTTP response? What are the 4 types of HTTP
request methods?

1.c. Using a neat diagram explain CSS box model.

2.a. Write short notes on
1. Oﬄine Browsing
2. Web Workers
3. Hoisting

2.b. Write css rules for the following

1. A div with ID test has some text in it. The colour of text must change from black to Blue when the mouse cursor moves over the div.

2. An embedded style that States paragraph that have class "copper" have red colour font.

3. Add and inline style for the paragraph element given below that indicates that the font colour must be blue

            <p> I like to study</p>

2.c. What are the purpose of the let keyword? Explain with examples
What is the diﬀerence between let and var? Explain with examples

3.a. Display a simple message "Welcome!!" on your demo web page and when the
users hovers over the message a pop up should be displayed with the message
"Welcome to my web page"

3.b. What are events and event handlers? List few event handlers for example.

3.c. What is the use of preventDefault method and use of stopPropagation
method? Explain the code

4.a. What is a web server? How does a web server work?

4.b. With respect to Apache conﬁguration explain the following

1. Listen
2. Document root
3. HTTP authentication

(6.0 Marks)

4.c. How can we achieve basic ﬁle based authentication in Apache?

(6.0 Marks)

5.a. What is the diﬀerence between echo and print? Which function you can use in
PHP to open a ﬁle for reading or writing or for both? Give example for each

(8.0 Marks)

5.b. List and explain the modes of opening a ﬁle using fopen function.

(8.0 Marks)

5.c. What is AJAX? What are the diﬀerent ways to deal with a synchronous code?

(4.0 Marks)


---
UE19CS204 – Web Technologies

1  a) Describe the structure of HTTP Request and Response message using an example.

Answer:

An HTTP request is just a series of lines of text that follow the HTTP protocol. A GET request

might look like this:

This section of text, generated by the user's browser, gets sent across the Internet.

When an origin server receives an HTTP request, it sends an HTTP response:

b)

(2 marks each)
A web page has a form for online registration of a Tennis competition.
-
-  Participant must be able to choose if (s)he has previously participated in the same event

The participants can be adults or children.

-

-

in one or more of the years 2019-20 /2018-19/2017-18
The form should provide the controls to accept above mentioned details as well as the
personal information like name and gender.
The user must be redirected to the server script “/registration” when he submits the
form.
-

The details he enters must be visible in the address bar of his/her browser

Write the HTML code for the form with suitable form elements and default values.

Answer:

Following should be present:

```html
<form action=”/registration” method=”get”> - 2 marks
```

-
-  Radio buttons for adult or child – 1 mark
-  Check box for previous participation – 1 mark
-

Text box for name and radio/text/select for gender – 1 mark
c)  With a neat diagram, explain the CSS Box model and its significance.


CSS box model determines the size, position, and properties (color, background, border size, etc.)  of  each  element.  Every  box  is  composed  of  four  parts  (or  areas),  defined  by  their respective edges: the content edge, padding edge, border edge, and margin edge. Every box has a content area and an optional surrounding margin, padding, and border.

(2 +  3 marks)

d)  Write a JavaScript function to take a string as input parameter and reverse the case of every alphabet  in  the  string.  The  function  should  return  the  modified  string.  Ex.    changeCase

(“HeLlo”) must return “hElLO”.

Answer:

```js
function changeCase(str)

{
var UPPER = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
var LOWER = 'abcdefghijklmnopqrstuvwxyz';
var result = [];

  for(var x=0; x<str.length; x++)  {  // 1 mark
    if(UPPER.indexOf(str[x]) !== -1)  {  // Any approach to identify Uppercase – 1 mark
      result.push(str[x].toLowerCase());  // convert to Lowercase – 1 mark
    }
    else if(LOWER.indexOf(str[x]) !== -1)  { // Any approach to identify Lowercase – 1 mark
      result.push(str[x].toUpperCase());  // convert to Uppercase – 1 mark
    }
    else {
      result.push(str[x]);  //  add to result array/string – 1 mark
    }
  }
return (result.join(''));
}
```



2a)

A HTML page contains the following:

-  A table exists with id “table1”
-  A button “Add” with id “btn1”
-  A div with id “display”

SRN

Add JavaScript to the webpage for the following specifications

• On clicking “Add” a new row with 2 cells are added to the table

• Populate each cell with a random number (between 1 and 200)

• If the cell contains an even number, mouse over should turn the cell green

• If the cell contains an odd number, mouse over should turn the cell red.

• If you click on a cell, the div will be populated with the cell content

Note: Write only vanilla JavaScript code. Assume that body tag has an onload=”init()” handler.

Answer:

function init(){

document.getElementById(“btn1”).onclick = show; // 1 mark

tbl1 = document.getElementById(“table1”);

dsp = document.getElementById(“display”);

}

function show(){

8

num1 =  Math.floor(Math.random()*200)+1;

num2 =  Math.floor(Math.random()*200)+1; // 1 mark

tr = document.createElement(“tr”);

td1 = document.createElement(“td”);

td2 = document.createElement(“td”);

td1.innerHTML = num1; td2.innerHTML = num2; // 1 mark

tr.appendChild(td1); tr.appendChild(td2); tbl1.appendChild(tr); // 1 mark

td1.onmouseover=change; td2.onmouseover=change; // 1 mark

td1.onclick = display; td2.onclick = display; // 1 mark

}

function change(event){

if(event.target.innerHTML%2) // 1 mark

event.target.style.backgroundColor = “red”;

else

event.target.style.backgroundColor = “green”;

}

function display(event){

dsp.innerHTML = event.target.innerHTML; // 1 mark

}

b)  Write briefly about the two methods of geolocation object.

Answer:
navigator.geolocation object allows you to access geo location through two primary functions:
-

getCurrentPosition() : Returns the location of the visitor as a one-time snapshot

-  watchPosition() : Returns the location of the visitor every time the location changes
-  Both  functions  take  the  following  parameters:  Success  callback  function,  Error  callback

4

function (optional) and Geo location options object (optional)

(2 marks each)

SRN

c)

A web page has the following:

-  A select element with options as Song names and value set to URL of an audio file

(ex. <select id=”input1”>

<option value=”faded.mp3”>Faded by Alan Walker </option>
…
</select>)

-  A button to fetch the audio asynchronously from the server
-  A placeholder “div” where the audio fetched is displayed
Write  JavaScript  function as the  click  event  handler for the button. The  function should use
the  “fetch”  API  to  asynchronously  fetch  the  “selected”  audio  file  from  the  server  URL
(specified in the value property) and display it in the div element.
Note:
-
-  Write only JavaScript code. HTML code is not required
Answer:
function fetchdata(){

There should be only one audio element shown at any time

mydiv = document.querySelector("#container");

fetch(document.querySelector(“#input1”).value) // 2 marks – fetch with 2  then

.then(function(response){

return response.blob(); // 1 mark

})

.then(function(data){

aud = document.createElement("audio");

aud.controls=true;

aud.src=URL.createObjectURL(data); // 1 mark

mydiv.firstChild.remove()

mydiv.appendChild(aud); // 1 mark

})

.catch(function(error){

console.log(error.message);

})}

d)  Name  the  methods/events  supported  by  web  workers  for  communication  between  worker

and main threads. Show how they are used with an example.
Answer:
-
-

worker.postmessage(“abc”); //send message to worker thread

worker.onmessage = function(event){ //receive message from worker

Listen for messages, using the onmessage event listener function.

Send messages via the postMessage() function.

console.log(“received message: “+event.data)

}

(1 + 1 + 1 marks)

5

3

SRN

3  a)  What is the significance of key property? Describe with an example.

Answer:

•  When returning an array or list of elements, the individual element should be uniquely

•

identified by a key property

The key property helps React identify each element in the list for rendering or updating

etc.

•  Not specifying the key property will display a warning on the console:

const numbers = [1, 2, 3, 4, 5];

const listItems = numbers.map((number) => <li>{number}</li>);

ReactDOM.render(

<ul>{listItems}</ul>,
document.getElementById('root')

);

(3 + 2 marks)

b)  Write a component “Poster” that includes the movies poster image, a paragraph showing the

movie title and another paragraph showing the movie director’s name. An App component

renders multiple Poster components based on the values of image src, title and director name

stored in an array of objects. The object members are src, title and director. The values in the

array should be passed as properties to the Poster component. Note: Use “map” method or

even a simple for loop to traversing through the array of values.

Answer:

Class Poster extends React.Component {

render(){

return (

<div>

<img src={props.src}/> // 2 marks

<p>{props.title}</p>
<p>{props.director}</p>

</div>

)}};

Class App extends React.Component {

render(){

var mobj = [{…}]

// 1 mark (map or any other approach to access all array elements

acceptable)

{mobj.map((m)=> {return (<Poster src={m.src} title={m.title}

director={m.director} />)} // 1 mark

)}}}

c)

componentDidMount

componentDidUpdate

componentWillUnmount

Explain the following methods of component life cycle:
-
-
-
Answer:
-

componentDidMount

o  method that is executed after the React Component has been rendered (after the call

-

-

to render method)

componentDidUpdate

o  method that is executed after the React Component has been rendered (after an

update to the component using setState or new props added)

componentWillUnmount

o  method that is executed before the React Component is unmounted

(1 mark each)

5

4

3

SRN

d)

In the game of Minecraft, a player can discover and extract raw materials to craft tools and

items. For example, a player can build an axe using sticks and stones. Write a uncontrolled

form (using only refs, without states), that has

-  Two input elements to read the number of sticks and stones a player has (initial values set

to 1)

-  A compute button that displays the number of axes that can be made out of these

resources.

-  A placeholder div to display the number of axes
Note: For computation use the following logic. Three stones and two sticks can be used to
build an axe. Assuming a player has 10 stones and 4 sticks, we have 3 sets of three sticks (10 /
3) and 2 sets of two stones (4 / 2), hence only 2 (minimum of these numbers) axes can be
built.
Answer:
class Minecraft extends React.Component{

constructor(props){

super(props);

this.setRef=(el)=>{ // 2 marks (two separate set ref methods accepted)

if(el.name=="height")

this.sticknum=el;

else if(el.name=="weight")

this.stonenum=el;

}

this.setOutputRef=(el)=>{this.output=el} // 1 mark

this.handleSubmit=this.handleSubmit.bind(this);

}

handleSubmit=function(event){

var axes;

var stones = parseInt(this.sticknum.value);

var sticks=this.stonenum.value-0;

//axes = calculate number of axes // 1 marks

var stonesset = stones / 3;

var sticksset = sticks / 2;

axes = Math.min(stonesset, sticksset);

8

this.output.innerHTML="Number of Axes: "+axes; // 1 mark

event.preventDefault();

}

render(){

    return(<div>

            <form onSubmit={this.handleSubmit}> // 1 mark

                <label> Stick:</label>

                <input name="stick" defaultValue='1' type="text" ref={this.setRef}/>

                <label> Stone:  </label>

                <input name="stone" defaultValue=’1' type="text" ref={this.setRef}/>

                <input type="submit" value="submit"/>

            </form>

            <h2 ref={this.setOutputRef}/>

        </div> )}}

ReactDOM.render(

<Minecraft/>,

document.querySelector("#container")

)

// 2 input fields with defaultValue and ref – 2 marks (defaultValue missing – reduce 1 mark)

SRN

4  a)  Write in brief the important features of Node JS.

Answer:

Following are some of the important features of Node.js:

  Asynchronous and Event Driven − All APIs of Node.js library are asynchronous, that is, non-

blocking. It essentially means a Node.js based server never waits for an API to return data.

  Very Fast − Being built on Google Chrome's V8 JavaScript Engine, Node.js library is very fast

in code execution.

  Single Threaded but Highly Scalable − Node.js uses a single threaded model with event

looping. Event mechanism helps the server to respond in a non-blocking way

  No Buffering − Node.js applications never buffer any data. These applications simply output

the data in chunks.

  License − Node.js is released under the MIT license

(Any 4 – 1 mark)

b)  Write JavaScript code using NodeJS modules only (not Express JS) to accept a GET request in

the form of http://server:8000/calc?op=add&op1=10&op2=20 and returns back the calculated

output, in this case the addition of 10 and 20, which is 30.  The operations supported by this

basic calculator are addition, subtraction, multiplication and division.

Answer:

var url = require('url');

var http = require('http');

var qs = require('querystring') // 1 mark

http.createServer(function(request,response){

    if(request.method=='GET'){  // 1 mark

var myurl = url.parse(request.url) // 1 mark

var query = myurl.query; // 1 mark

var qobj = qs.parse(query); // 1 mark

var res = 0;

if(qobj.op==”add”) // 1 mark

res = qobj.op1 + qobj.op2;

else if(qobj.op==”sub”)

res = qobj.op1 - qobj.op2;

…

response.writeHead(200,{'Content-type':'text/html'});  // 1 mark

response.write(res); // 1 mark

    }

})).listen(8000);

c)  What are data streams in Node JS? Name the different types of streams with example of each.

Answer:

A stream is an abstract interface for working with streaming data in Node.js. The stream

module provides an API for implementing the stream interface.

  Writable: streams to which data can be written (for example, response on server).

  Readable: streams from which data can be read (for example, request on server).

  Duplex: streams that are both Readable and Writable (for example, net.Socket).

  Transform: Duplex streams that can modify or transform the data as it is written and read

(for example, zlib.createDeflate()).

(2 + 2 marks)

4

8

4

SRN

d)  Write Node JS code using the “readline” module to read every line in “input.txt”. Call the

changeCase(str) function with the line read as the parameter and  write the value returned on

to the console. Note: You do not have to write the changeCase function.

Answer:

readline = require('readline'); // 1 mark

rl = readline.createInterface({ // 1 mark

input:fs.createReadStream("test.txt"),

output:process.stdout,

terminal:false

})

rl.on('line',function(line){  // 1 mark

var rev = changeCase(line);  // 1 mark

console.log(rev);

})

5  a)  What are Express middleware functions? Write briefly about the order of execution of

middleware functions.

Answer:

Middleware functions are functions that have access to the request object (req), the response

object (res), and the next middleware function in the application’s request-response cycle.

These functions are used to modify req and res objects for tasks like parsing request bodies,

adding response headers, etc.

The order in which Middleware in Express are executed is the order in which they are

written/included in your file, given that the route matches also needs to be considered.  The

important thing is to call the next middleware in the order of execution using the “next();”

(2+1 marks – reduce 1 mark if next() is not mentioned)

b)  Write server-side  script in JavaScript to route requests for GET and POST requests for flight

details. The details are stored in the mongodb database in the following format.

{from:”BLR”, to:”DEL”, dept:”12:25”, arrv:”14:25”, flnum:”6E-2428”}

The server script should support the following routes:

-  GET /flights – return details of all flights
-  GET /flights/:from/:to – return details of flight between specific airports
-  POST /flights – save details of a flight and return a success or error message

Answer:
-

app.get("/flights", function(req,res){

…

db.collection('student').find().toArray(function(err,objs){

res.send(objs)

});});

-

app.get("/flights/:from/:to", function(req,res){

…

db.collection('student').find({from:req.params.from,

to:req.params.to}).toArray(function(err,objs){

res.send(objs)

});});

-

app.post("/flights", function(req,res){

…

db.collection('student').insertOne(req.body,function(err,objs){

res.send("Save Successful!!!")

});});

(2 + 3 + 3 marks)

4

3

8

SRN

c)

Ronaldino, a back end developer, has to create at least 4 -5 Express routes each for the

resources “players”, “match” and “teams”. Since he is new to Express, he wants suggestions

on how to structure his JavaScript code. Write an approach that can be taken by him to solve

this problem.

Answer:

He has to use Express Routers to organize the routes in different JS files. And write the routes

specific to each resource in these files.

var playersrouter = require("./players.js")

app.use("/players", playersrouter);

var matchrouter = require("./match.js")

app.use("/match", matchrouter);

var teamsrouter = require("./teams.js")

app.use("/teams", teamsrouter);

(1 + 2 marks)

d)  Write a route called “picsupload” which receives multiple image files in a POST request. The

route function should save each of them under the “pics” folder in the same directory as the

JS file. Any error like, no files uploaded or saving files failed should be handled accordingly.

Note: Write only the server JS code. HTML/client code is not required.

Answer:

const express = require('express');

const fileUpload = require('express-fileupload'); // 1 mark

const app = express();

// default options

app.use(fileUpload()); // 1 mark

app.post('/picsupload', function(req, res) {

  if (!req.files || Object.keys(req.files).length === 0) { // 1 mark

    return res.status(400).send('No files were uploaded.');

  }

for(var i in req.files){ // 1 mark

  let picFile = req.files[i];

  // Use the mv() method to place the file somewhere on your server

  picFile.mv('pics/'+picFile.name, function(err) { // 1 mark

    if (err)

      return res.status(500).send(err); //1 mark

  });

}

 res.send('Files uploaded!');

});

3

6

SRN

PES University, Bangalore

(Established under Karnataka Act No. 16 of 2013)

UE20CS204

August –December 2021: END SEMESTER ASSESSMENT (ESA) B.Tech.  III SEMESTER

UE20CS204:  WEB TECHNOLOGIES

Time: 3 Hrs.                                                 Answer All Questions                                  Max Marks: 100

What is HTTP? Explain the structure of HTTP request message.

Scheme and Solution

//HTTP:1  Mark

HTTP  stands  for  Hyper  Text  Transfer  Protocol.  This  is  a  basis  for  data

communication  in  the  internet.  The  data  communication  starts  with  a  request

sent from a client and ends with the response received from a web server.

//Structure of HTTP and explanation 3M

•  HTTP  request  is  a  request  line,  followed  by  zero  or  more  request

a)

headers

•  Request line: <method> <uri> <version>

4M

•  <version> is HTTP version of request (HTTP/1.0 or HTTP/1.1)

•  <uri> is typically URL for proxies, URL suffix for servers.

•  <method>  is  either  GET,  POST,  OPTIONS,  HEAD,  PUT,

DELETE, or TRACE.

•  Request Header

•  Blank line (CRLF)

Message Body

1.

Write a HTML code that outputs the following:

b)

10M

NOTE: The  ‘Number’  field  is  a  mandatory  field,  and  takes  in  only  a  10-digit

number. Also, Submit and Reset buttons do their conventional tasks.

Scheme and Solution

<html>
<head>
 <title> My Netflix list </title>
 </head>

SRN

 <body>
//form 1 mark with attributes
 <form method='get' action='save.php' target='_blank'>
//Table 2 mark with proper rows and columns
 <table border="black">
 <tr>
 <td><br/>Name:</td>
//Name input field 0.5M
 <td><input type='text' name='uname'/></td>
 </tr>
 <tr>
 <td><br/>Address:</td>
//textarea 0.5M
 <td><textarea name='uadd' rows='3' cols='20'></textarea></td>
 </tr>
 <tr>
//Number input field 1 Mark with the required pattern
 <td><br/>Number:</td>
 <td><input type="tel" required pattern="[0-9]{10}" name='tele'></td>
 </tr>
 <tr>
//rowspan 1Mark and check boxes 1mark
 <td rowspan=2><br/>Pick you favourite shows:</td>
 <td>Romcom:<br/>
 <input type='checkbox' name='rom' value='TBBT'>TBBT
 <input type='checkbox' name='rom' value='B99'>B99
 <input type='checkbox' name='rom' value='TO'>TO</td>
 </tr>
 <tr>
 <td>Others:<br/>
 <input type='checkbox' name='oth' value='Money Heist'>Money Heist
 <input type='checkbox' name='oth' value='Masterchef'>Masterchef</td>
 </tr>
 <tr>
 <td><br/>Do you watch anime?</td>
//radio buttons 1M
 <td><input type='radio' name='anime' value='Yes'>Yes
 <input type='radio' name='anime' value='No'>No
 <input type='radio' name='anime' value='Sometimes'>Sometimes</td>
 </tr>
 <tr>
 <td>Favourite Naruto character: </td>
 <td>
//Menu Item 1M
 <select name='naruto'>
 <option value='Sasuke'>Sasuke
 <option value='Mighty Guy'>Mighty Guy
 <option value='Kakashi'>Kakashi
 <option value='Naruto'>Naruto
 <option value='Itachi'>Itachi
 </select>
 </td>
 <tr/>
 </table>
 <br/><br/>
//Buttons 1Mark

 <input type='submit' value='Submit'/>

 <input type='reset' value='Reset'/>

 </form>
 </body>
 </html>

SRN

What is the output of the following function? Give an explanation regarding the

same.

var x = 100;

function num() {

if (false) {

var x = 200;

}

console.log(x);

}

num();

Scheme and Solution

Output: //1M

undefined

//explanation 2M

 In this example, we  declared x to be 100 globally. Depending on an if statement,  x

could change to 200, but since the condition was false it should not have  affected the

value  of  x.  Instead,  x  was  hoisted  to  the  top  of  the  num()  function,  and  the  value

became undefined.

Write a code to print “hi” at repeated intervals, where the length of the interval

is the square of the previous interval.

Scheme and Solution

//0.5 Marks

let x = 100

//2M for function

 function log()

 {

 console.log("hi")

 if(true){

x = x*x;

 t = setTimeout(log,x)

 }

 }

//0.5 M

var t = setTimeout(log,x);

c)

d)

2.  a)

Consider the following HTML and JavaScript program:

<html>
<head>
</head>
<body>
<div id="container">
<button id="button">Click me!</button>
</div>
</body>

3M

3M

4M

SRN

<script>
function printWindow(event) {
console.log('Window says hello!');
}
function printTarget(event) {
console.log('Target says hello!');
}
function printContainer(event) {
console.log('Container says hello!');
}
var capture = true;
var button = document.getElementById('button');
var container = document.getElementById('container');
window.addEventListener('click', printWindow);
button.addEventListener('click', printTarget, capture);
container.addEventListener('click', printContainer,capture);
</script>
</html>
i.

The page loads and the user clicks on the window object. What‘s the con-

sole output?

The  user  clicks  on  the  button  that  says  "Click  me!”  What's  the  console

output?

ii.

Scheme and Solution

//1Mark

i. Window says hello!

//3 Marks

ii. Container says hello!

    Target says hello!

    Window says hello!

What  is  Geo  Location?  Explain  the  two  methods  of  navigator.geolocation

object?

Write  a  program  to  display  your  current  location  on  the  browser  when  the

button “Get Current Position” is clicked as shown below.

b)

Scheme and Solution

//1Mark Explanation

The HTML5 geo location  feature lets  you find out the geographic coordinates

(latitude  and  longitude  numbers)  of  the  current  location  of  your  website's

visitor.

//1mark each with one line explanation

getCurrentPosition() and watchPosition()

// function getPos, showPosition, error   1Mark each, body 1Mark

<head>

1M+2M+4M

SRN

<script type="text/javascript">

<!--

var x= document.getElementById("location");
function getPos(){

navigator.geolocation.watchPosition(showPosition,

error);

}
function showPosition(position){
 var x = "Your current location is (" + "Latitude: " + position.coords.latitude +
", " + "Longitude: " +    position.coords.longitude + ")";
                document.getElementById("location").innerHTML = x;
     }

function error(error){

e = error;

}

-->

</script>
</head>
<body>

<button onclick="getPos()">Get Current Position</button>

<div id="location"></div>

</body>

Write jQuery code to perform the following:

1.  For  the  last  paragraph  within  the  div  with  id  “colortext”,  set  the  color  to
green.
2.  On  moving  the  mouse  over  an  h1  element,  the  text  font  size  should  be
increased by 5 times
3. When the first li element with class name “liclass” on the page is clicked, it
fades out in 2 seconds and then fades in 3 seconds
Scheme and Solution
//1Mark
1. $(“div#colortext p:last”).css(“color”,”green”)
//2 Marks
2. $(“h1”).mouseover(function(){
$(this).animate({
fontSize: 5em
}
}
// 2 Marks
3. $(“li.liclass”).click(function(event){
$(this).fadeOut(2000,function(){
$(this).fadeIn(5000, function(){});
});
});

c)

5M

d)  What is AJAX? Explain in detail any 3 XHR object properties.

4M

SRN

Scheme and Solution

//1Mark Explanation

AJAX  stands  for  Asynchronous  JavaScript  And  XML  uses  XMLHttpRequest

object  to  communicate  with  servers.  It  can  send  and  receive  information  in

various formats, including JSON, XML, HTML, and text files.

//3marks any 3 properties of XHR object

Onreadystatechange:  Specifies  an  event-handling  function  to  be  called

whenever the readyState property of an object changes.

readyState:An  integer  property  that  reports  on  the  status  of  a  request.  It  can

have  any  of  these  values:  0  =  Uninitialized,  1  =  Loading,  2  =  Loaded,  3  =

Interactive, and 4 = Completed.

responseText :The data returned by the server in text format.

responseXML :The data returned by the server in XML format.

Status: The HTTP status code returned by the server.

statusText: The HTTP status text returned by the server.

a)  Create a form (as shown below) using uncontrolled components (references) to

take 3 inputs: name, age, and number of vaccine doses taken. Also have a <h2>

tag  inside  the  form  which  displays  “Unsafe”,  “Almost  safe”,  “Safe”  and

“Invalid”  for  the  number  of  doses  being  0,  1,  2  and  ‘any  other  number’

respectively, on submission of the form.

3.

10M

crossdomain

src="https://unpkg.com/react-dom@16/umd/react-

crossdomain

Scheme and Solution

<html>
 <head>
 <title>Question 3a</title>
 <script
src="https://unpkg.com/react@16/umd/react.development.js"> </script>
 <script
dom.development.js"> </script>
 <script src="https://unpkg.com/babel-standalone@6.15.0/babel.min.js">
</script>
 </head>
 <body>
 <div id="container"></div>
 <script type="text/babel">
 var txt,ev;
//class component  with bind 3M
 class NameAgeVacc extends React.Component{
 constructor(props){

SRN

 super(props);

 this.statusoutput = null;

 this.setName=(el)=>{this.nameinput=el}

 this.setAge=(el)=>{this.ageinput=el}

 this.setVacc=(el)=>{this.vaccinput=el}

 this.setStatRef=(el)=>{this.statusoutput=el}

 this.handleSubmit=this.handleSubmit.bind(this);

 }

//handleSubmit function call 2M

 handleSubmit=function(event){

if(this.statusoutput){

 if (this.vaccinput.value == 0)

 this.statusoutput.innerHTML="Unsafe"

 else if (this.vaccinput.value == 1)

 this.statusoutput.innerHTML="Almost Safe"

 else if (this.vaccinput.value == 2)

 this.statusoutput.innerHTML="Safe"

 else

 this.statusoutput.innerHTML="Invalid"

 event.preventDefault();

 }

 }

 render(){

 return(

 <div>
// form elements with onsubmit function call 4M
 <form onSubmit={this.handleSubmit}>
 <label>
 Name:
 </label>
 <input
ref={this.setName}/>
 <br/><br/>
 <label>
 Age:
 </label>
 <input name="age" defaultValue='25' type="text" ref={this.setAge}/>
 <br/><br/>
 <label>
 Vaccine:
 </label>
 <input
ref={this.setVacc}/>
 <br/><br/>
 <h2 ref={this.setStatRef}/>

defaultValue='Zendaya'

defaultValue='0'

name="vaccine"

name="name"

type="text"

type="text"

pattern="[0-9]"

SRN

 <br/>
 <input type="submit" value="submit"/>
 </form>
 </div>
 )
 }
 }
//render the component 1M
 ReactDOM.render(
 <NameAgeVacc/>,
 document.querySelector("#container")
 )
 </script>
 </body>
 </html>

b)  Create a class component which will render a H1 and paragraph element apply

different inline style for H1 and P element created using java script objects (key

value pair).

Scheme and Solution

//2 Marks for creating component and object for style

//1 mark each for creating elements and rendering the component

<body>
<div id="root"></div>
<script type="text/babel">
class StyleInline extends React.Component
{
render(){
var StyleH1={

4M

backgroundColor:"#FF55EE",

fontFamily:"monospace",

textAlign:"center"

};

var StyleP={

color:"#FFEE00",

fontFamily:"sans-serif",

textAlign:"left"

};

return (

<div>
         <h1 style={StyleH1}>Welcome to PES World!</h1>
 <p style={StyleP}> Batch of 2020-2021</p>
 </div>
 )}
 }

ReactDOM.render(  <StyleInline />,    document.getElementById("root")

SRN

);

</script>

</body>

c)  With a neat diagram explain component life cycle.

Scheme and Solution

//Diagram :2 Marks

6M

//Explanation 4 Marks:

Mounting - Birth of the Component

Updating- Growing of component

Unmounting- End of the component

In the entire lifecycle of a React component, the following methods are used to

accomplish the functions:

•componentWillMount() – On client and server side this function gets executed

just before the rendering

•componentDidMount() – After first render it gets executed on the client side

•componentWillReceiveProps()  – This  function  is invoked when the props are

received from the parent class and another render is not being called.

•shouldComponentUpdate() – This Boolean function returns true or false as per

situation  like  if  the  component  needs  to  be  updated  then  true  is  returned  else

false is returned

•thecomponentWillUpdate() – It is called when rendering is not being called

•componentDidUpdate() – It is called just after when render function is called

•componentwillUnmount()  – When a component gets un-mounted  from DOM

then this function is called.

4.

a)  What  are  buffers  in  Node.js?  With  help  of  syntax  explain  any  2  buffer

operations.

Scheme and Solution

//1 Mark

Node provides Buffer class which provides  instances to store raw data similar

to an array of integers.

//Any 2 with explanation: 2 marks each

Creating buffer

Syntax: Buffer.alloc(size, fill, encoding)

Writing to Buffer

Syntax: buf.write(string[, offset][, length][, encoding])

5M

SRN

Reading from Buffer

Syntax: buf.toString([encoding][, start][, end])

Compare Buffer

Syntax:

sourceEnd]]]])

Copy Buffer

Syntax: buf.copy(target[, targetStart[, sourceStart[, sourceEnd]]])

buf.compare(target[,

targetStart[,

targetEnd[,

sourceStart[,

b)  Given a url of the format

http://localhost:8080/sample.txt?gender=xxxx&halloween_heist=yyyy.  Write  a

server  code  to  get  all  objects  from  a  MongoDB  collection  that  satisfies  the

query.  Also  include  code to  “post” one object  given  in  a  post request  body  to

this collection. Handle errors as well.

Scheme and Solution

//2 Marks for importing all modules

var http = require('http');

 var url = require('url');

 var fs = require('fs');

 var qs = require('querystring');

 var MongoClient = require('mongodb').MongoClient;

12M

//2 marks for create server and parse URL

 http.createServer(function(request,response){

 if(request.method=='GET'){

 response.writeHead(200,{'Content-type':'text/html'});

 var myurl = url.parse(request.url)

 var query = myurl.query;

 var qobj = qs.parse(query);

//3 Marks for database connectivity and GET/find the data

 MongoClient.connect('mongodb://localhost:27017',

 {useUnifiedTopology: true},

 function(err,client){

 if(err) throw err;

 const db = client.db('newdb');

 db.collection('any_collection').find({qobj}).toArray(

 function(err,docs){

 if (err) throw err;

 response.writeHead(200,{'Content-type': 'application/json'})

 response.write(JSON.stringify(docs))

 client.close();

 response.end()

 }

 )

 })

 response.end();

 }

// 4 marks for POST method with error handling

 if(request.method == 'POST'){

 var myurl = url.parse(request.url)

 var pathname = myurl.pathname;

 let body = [];

 request.on('data',(chunk)=>{

 body.push(chunk);

SRN

 })

 .on('end',()=>{

 body = Buffer.concat(body).toString()

 MongoClient.connect('mongodb://localhost:27017',

 {useUnifiedTopology: true},

 function(err,client){

 if(err) throw err;

 const db = client.db('newdb');

 db.collection('any_collection').insertOne(JSON.parse(body),

 function(err, res){

 if (err) throw err;

 console.log('document inserted');

 client.close();

 response.end();

 }

 )

 })

 });

 }

 }).listen(8080); //1 Mark

console.log('Server is up and running on http://localhost:8080');

c)  The  following  Node.js  program  uses  the  Node  fs  module  to  read  a  large  file

twice using two different API calls. When run, the programs print the numbers

1 through 5 to the console. List the order in which the numbers are printed and

justify your answer.

var fs = require("fs");

fs.readFile("./sample.txt", function () {

                    console.log("1");

                 });

            console.log("2");

function Fileread(fileName, readcallback) {

                 var f = fs.readFileSync(fileName);

                 console.log("3");

               readcallback();

            }

Fileread("./sample.txt", function () {

             console.log("4");

            });

console.log("5");

Scheme and Solution

Output: //1 Mark

2

3

4

5

1

//2 Marks for explanation

The fs.readFile call will call it’s done callback later so the first log we get is '2'.

Afterwards, Fileread will be called and print '3' and then call its readcallback

3M

which  prints  '4'.  Execution  then  continues  with  '5'  printed  and  later  the

fs.readFile callback will fire, printing '1';

SRN

5.  a)  What is RESTful API? Explain any 4 design specification/constraints of REST

API.

Scheme and Solution

//1 M Explanation on RESTAPI

A  REST  API  (also  known  as  RESTful  API)  is  an  application  programming

interface  (API  or  web  API)  that  conforms  to  the  constraints  of  REST

architectural style and allows for interaction with RESTful web services. REST

stands for representational state transfer

//1 Mark each for any 4 design considerations

Client  Server,  Scalable,  Cacheable,  Uniform  Interface,  Layered  System,  Code

on Demand

5M

b)  When  doing  routing  of  URLs  in  ExpressJS,  we  used  routes  that  contained  a

colon  character  (e.g.  "/hello/:id"  )  yet  we  never  included  a  colon  in  the

hierarchical part of a URL we used.

(i)

(ii)

Explain the purpose of this colon character?

Describe what would happen if we just deleted the colon from the routes.

Scheme and Solution

//2 Marks each

i.

ii.

The  colon character indicates that 'id'  is a route parameter, i.e.,  whatever

the  user  places  in  that  position  in  the  URL  will  be  a  route  parameter

named  ‘id’.  Router  will  attach  this  parameter  to  our  component's  'props'

object  so  we  can  display  the  data  associated  with  this  parameter  in  the

component.

4M

If we delete the colon, Router will only route /hello/id to our component,

instead  of  /hello/anything  to  our  component.  Since  our  component  also

probably

has some dependency on the ‘id’ component on the ‘props’ object, our app may

not render what is required.

c)  Explain  the  role  of  express  middleware  function.  What  are the  different types

of middleware an express application can use?

Scheme and Solution

//2 reduce 1 mark if next is not mentioned +1 Mark(for any 2 types)

Middleware functions are functions that have access to the request object (req),

the response object (res), and the next middleware function in the application’s

request-response cycle. These functions are used to modify req and res objects

for tasks like parsing request bodies, adding response headers, etc.

•  Application-level middleware

•  Router-level middleware

•  Error-handling middleware

•  Built-in middleware

Third-party middleware

d)  Write  a  program  to  upload  a  file  to  Node.js  server  using  express  file  upload

library.

3M

8M

SRN

Scheme and Solution

// 1 mark for importing modules express and express fileupload
```
var express=require("express")
var app= express()

var fileupload= require("express-fileupload")

app.use(fileupload());

//3 marks for post method

app.post('/upload',function(req,res){

    if(!req.files||req.files.length==0)

    return res.status(400).send("No file to upload")

    var sampleFile= req.files.sampleFile;

    sampleFile.mv("./files/"+sampleFile.name,function(err){

        if(err)

        return req.statusCode(500).send(err)

        res.send("File"+sampleFile.name+"Uploaded")

    })

})

//3 Marks for get method and form creation

app.get("/form",function(req,res){

    var

retform="<form  action='http://localhost:3000/upload'  method='post'

encType='multipart/form-data'><input  type='file'  name='sampleFile'/>  <input

type='submit' value='upload'/></form>";

    res.send(retform)

    })

//1 Mark

app.listen(3000,function(){

    console.log("Server is up and running")

})
```
---
11/8/24, 12:20 PM

ESA - DEC 2023 - UE20CS204/UE19CS204 (set- 1)

PES University, Bengaluru

(Established under Karnataka Act 16 of 2013)

END SEMESTER ASSESSMENT (ESA) - DEC 2023

UE20CS204 - Web Technologies

1.a. What is HTTP? Explain the structure of HTTP request message.

(4.0 Marks)

Total Marks : 100.0

1.b. With a neat diagram, explain the CSS Box model and its signiﬁcance.

(4.0 Marks)

about:blank

1/8

11/8/24, 12:20 PM

ESA - DEC 2023 - UE20CS204/UE19CS204 (set- 1)

1.c. Write Code to get following output using lists and table

(6.0 Marks)

about:blank

2/8

11/8/24, 12:20 PM

ESA - DEC 2023 - UE20CS204/UE19CS204 (set- 1)

1.d. Write code to get following output

2.a. Write Breiﬂy about the two methods of the geolocation object

(4.0 Marks)

(6.0 Marks)

about:blank

3/8


2.b. What is web worker?
Name the methods/events supported by web workers for communication
between worker
and main threads. Show how they are used with an example.

(4.0 Marks)

2.c. Write a script to display below texts in web page and onclick on Call
of Duty and Assassins Creed texts the colour of the text should change
to red.
Popular Games
Call of Duty
Assassins Creed
PUBG

(6.0 Marks)

2.d. Write a code to get the following output in browser using html canvas
(6.0 Marks)

3.a. Write a code to get the following output in react using components,
Create a class component called Article1 which is having states such as
name,color and price
if user clicks change color button text red should get changed blue.

3.b. What is the signiﬁcance of key property? Describe with an example.

(4.0 Marks)

(6.0 Marks)

3.c. Create a class component which will render a H1 and paragraph
element apply diﬀerent inline style for H1 and P element created using
java script objects (key value pair).

(6.0 Marks)

about:blank

5/8

11/8/24, 12:20 PM

ESA - DEC 2023 - UE20CS204/UE19CS204 (set- 1)

3.d. With a neat diagram explain any 4 component in component life
cycle.

(4.0 Marks)

4.a. What are buﬀers in Node JS? Write a program to create a buﬀer,write
data to buﬀer and read data from buﬀer
(4.0 Marks)

4.b. In a MongoDB database, there is a “course” collection. From the
collection, write queries to do
the following:

- List all documents
- List documents with code = “UE20CS204”
- List the ﬁrst document with credits = ”4”

(3.0 Marks)

about:blank

6/8

11/8/24, 12:20 PM

ESA - DEC 2023 - UE20CS204/UE19CS204 (set- 1)

4.c. Write a code in node .js server  to
1.Write data into ﬁle called input.txt
2.Read data Asynchronously from input.txt
handle the error properly

(6.0 Marks)

4.d. Write code snippet to connect to a db named “Groceries” on a
Mongodb instance running on localhost:27017 and write the following
details into the “Fruits” collection,insert many documents(at least 5) with
details: Fruit-name and price.
It should handle errors appropriately.
Note: write only the code required to write into the database.

(7.0 Marks)

5.a. What is RESTful API? Explain any 4 design speciﬁcation/constraints of
REST API.

(4.0 Marks)

7/8

11/8/24, 12:20 PM

ESA - DEC 2023 - UE20CS204/UE19CS204 (set- 1)

5.b. Write a code to collect form data for the library card which has ﬁelds
name,sem,branch and Submit in pug template and include pug template
in express code to retrieve the form data.

(8.0 Marks)

5.c. MBappe, a back end developer, has to create at least 4 -5 Express
routes each for the resources “players”,
“match” and “teams”. Since he is new to Express, he wants suggestions on
how to structure his JavaScript
code. Write an approach that can be taken by him to solve this problem.

(4.0 Marks)

5.d. Write a code in express to create a server which have 2 diﬀerent
route paths like /pes/:branch,/pes/branch/id which returns 3 diﬀerent
contents when particular route has been entered in browser
if user enters following paths server should return following contents

/pes/:CSE—-> branch name is CSE

/PES/:CSE/:123→id:123 and name :CSE

(4.0 Marks)

about:blank

8/8

---
UE20/19CS204:  WEB TECHNOLOGIES


1 a

 Create a Placement form with the following controls:

a. A text box to collect the student’s name and SRN

b. A multiline input field to collect college name and address

c. A student should give choice to tick their department from a list

of departments

i. CSE

ii. ECE

iii. MECH

8

d. A collection of three radio buttons for Semester option that are

labelled as follows:

i. IV

ii. V

iii.VI

e. Submit and reset Button

b

c

“The only way to apply CSS is by using external stylesheets”.

Accept or reject this statement with suitable explanation.

With suitable diagram explain CSS Box model and its properties

with example

2

a

b

Give the difference between JSON and XML.

Represent the details of three 6th sem students both in JSON and

XML. Consider the attributes id, name, branch, CGPA

i) What is jQuery? What are its advantages?

ii) For the given HTML code write a jQuery code for sliding all divs

up and down

  <body>
 <button class="btn1">Slide down</button>
 <button class="btn2">Slide up</button>
 <br><br>
  <div>PES</div>
  <div>UNIVERSITY</div>
  <div>BANGALORE</div>
</body>

6

6

10

10(4+3+3)

iii) Write a jQuery code to add a red border to an image “Sample.jpg

on button click

SRN

3

a

i) What would be the output of the following example? Justify your

answer

4(2+2)

 var Test=(props)=>

{

 return (

 <div>

 Hello World 1

 </div>

 <div>

 Hello World 2

 </div>

 );

}

ReactDOM.render(<Test/>, mountNode)

ii)  Which of the following is used to pass data to a component from

outside in React.js? Justify your answer

a.  SetState

b.  Render with arguments

c.  Props

d.  PropTypes

With a neat diagram explain component life cycle.

b

c

6

10

Create  a  complex  component  that  will  render  3  stationary  item

images, name of item, price as shown in the sample figure above.

Create  a  form  input  to  take  the  quantity  from  the  user  When  the

quantity of the item is entered the total bill amount of the order needs

to be calculated and displayed at the bottom.

Add styling using CSS modules in which all class names are scoped

locally by default.

SRN

4

a

i)  Is  Node.js  single  threaded?  Accept  or  reject  and  justify  your

answer

ii)  What is Event Emitter in Node.js? What is the use of on and

emit properties of event emitter?

6(3+3)

b

c

a

b

c

5

Create a simple server (use http request GET method) that will

allow you to display an HTML file on the browser given the

pathname. Set default pathname to index.html. Handle errors by

displaying file not found message

8

6

Imagine you have a MongoDb database “Sampledb” which has col-

lection  “faculty”  with  fields  faculty_ID,  faculty_Name,  Dept,

Designation and contract_type. Write a program to connect to Mon-

goDB database in Node.js to find data of all faculties who work in

CSE department.

Note: Only write Server-Side code

Brief any 4 design specifications for RESTful APIs. What are the

HTTP methods supported by REST?

Write a program to upload a file to Node.js server using express file

upload library.

What are Middleware Functions and what are they used for?

Explain Router-level middleware with an example.

8

6

6

PES University, Bengaluru

(Established under Karnataka Act 16 of 2013)

END SEMESTER ASSESSMENT (ESA) - Jan - May 2024

UE20CS204 - Web Technologies

Total Marks : 100.0

1.a. Create a Placement form with the following controls:

a. A text box to collect the student’s name and SRN

b. A multiline input ﬁeld to collect college name and address

c. A student should give choice to tick their department from a list of departments

    i. CSE

    ii. ECE

    iii. MECH

d. A collection of three radio buttons for Semester option that are labelled as

follows:

    i. IV

    ii. V

    iii.VI

e. Submit and reset Button

(8.0 Marks)

1.b. Describe the structure of HTTP Request and Response message using an
example.

(6.0 Marks)

1.c. With a neat diagram, explain the CSS Box model and its signiﬁcance.

(6.0 Marks)

2.a. What is Geo Location? Explain the two methods of navigator.geolocation
object?
Write a program to display your current location on the browser when the button
“Get Current Position” is clicked as shown below.

(7.0 Marks)

2.b. Give the diﬀerence between JSON and XML.

Represent the details of three 6th sem students both in JSON and XML. Consider

the attributes id, name, branch, CGPA

(6.0 Marks)

2.c. A HTML page contains the following:
    - A table exists with id “table1”
    - A button “Add” with id “btn1”
    - A div with id “display”
Add JavaScript to the webpage for the following speciﬁcations

On clicking “Add” a new row with 2 cells are added to the table

Populate each cell with a random number (between 1 and 200)

If the cell contains an even number, mouse over should turn the cell green

If the cell contains an odd number, mouse over should turn the cell red.

If you click on a cell, the div will be populated with the cell content

Note: Write only vanilla JavaScript code. Assume that body tag has an

onload=”init()” handler.

(7.0 Marks)

3.a. With a neat diagram explain component life cycle.

(8.0 Marks)

3.b. Create a class component which will render a H1 and paragraph element apply
diﬀerent inline style for H1 and P element created using java script objects (key
value pair).

(7.0 Marks)

3.c. What is the signiﬁcance of key property? Describe with an example.

(5.0 Marks)

4.a. Write in brief the important features of Node JS.

(6.0 Marks)

4.b. Write JavaScript code using NodeJS modules only (not Express JS) to accept a
GET request in the form of http://server:8000/calc?op=add&op1=10&op2=20 and
returns back the calculated output, in this case the addition of 10 and 20, which is
30. The operations supported by this basic calculator are addition, subtraction,
multiplication and division.

(8.0 Marks)

4.c. What are buﬀers in Node.js? With help of syntax explain any 2 buﬀer
operations.

(6.0 Marks)

5.a. What is RESTful API? Explain any 4 design speciﬁcation/constraints of REST API.
(6.0 Marks)

5.b. What are Middleware Functions and what are they used for? Explain Router-
level middleware with an example.

(8.0 Marks)

5.c. When doing routing of URLs in ExpressJS, we used routes that contained a
colon character (e.g. "/hello/:id" ) yet we never included a colon in the hierarchical
part of a URL we used.

(i) Explain the purpose of this colon character?

(ii) Describe what would happen if we just deleted the colon from the routes.

(6.0 Marks)

11/8/24, 12:39 PM

ESA - DEC 2023 - UE21CS242A (set- 1)

PES University, Bengaluru

(Established under Karnataka Act 16 of 2013)

END SEMESTER ASSESSMENT (ESA) - DEC 2023

UE21CS242A - Web Technologies

1.a. What are the 3 ways to include  CSS styling in CSS. explain with
examples

(6.0 Marks)

Total Marks : 100.0

1.b. Write the code to get the following output using tables

about:blank

1/7

(6.0 Marks)

11/8/24, 12:39 PM

ESA - DEC 2023 - UE21CS242A (set- 1)

1.c. Write a code to get the following code

2.a. What are the diﬀerent ways to get an element from DOM? Explain
any 3 with an example

(5.0 Marks)

(8.0 Marks)

about:blank

2/7

11/8/24, 12:39 PM

ESA - DEC 2023 - UE21CS242A (set- 1)

2.b. Write a JavaScript program to calculate multiplication and division of
two numbers to get output as below.

(6.0 Marks)

2.c. Write jquery code to get the following output

when user clicks Hide button text should hide when user clicks show

button text should get displayed.

(5.0 Marks)

2.d. Write diﬀerence between XML and JSON

(4.0 Marks)

about:blank

3/7

11/8/24, 12:39 PM

ESA - DEC 2023 - UE21CS242A (set- 1)

3.a. Explain the following methods of component life cycle:
-render()
- componentDidMount
- componentDidUpdate
- componentWillUnmount

(4.0 Marks)

3.b. write diﬀerence between Stateless and Stateful components in React

(4.0 Marks)

3.c. Write a code to get the following output in browser using React map
and keys

(6.0 Marks)

about:blank

4/7

11/8/24, 12:39 PM

ESA - DEC 2023 - UE21CS242A (set- 1)

3.d. Write a code to get the following output in react using components,
Create a class component called Article1 which is having states such as
name,color and price
if user clicks
change color button text red should get changed blue.

4.a. Write in Brief important features of Node.JS

(4.0 Marks)

(6.0 Marks)

4.b. What are buﬀers in Node JS? Write a program to create a buﬀer,write
data to buﬀer and read data from buﬀer
(4.0 Marks)

about:blank

5/7

11/8/24, 12:39 PM

ESA - DEC 2023 - UE21CS242A (set- 1)

4.c. Write user deﬁned module in Node js server called calc.js which
contains diﬀerent 3 functions such as
1..to return addition of 2 numbers
2.to return subtraction of 2 numbers
3.to return Multiplication of 2 numbers

write a code to include calc.js in node.js ﬁle and print all result in console

(6.0 Marks)

4.d. Write code snippet to connect to a db named “Groceries” on a
Mongodb instance running on localhost:27017 and write the following
details into the “Fruits” collection,insert many documents(at least 5) with
details: Fruit-name and price.
It should handle errors appropriately.
Note: write only the code required to write into the database.

(6.0 Marks)

5.a. Explain the following
1.What is Web Service?
2.Why Web Services  are useful?
3.What is REST API?

(4.0 Marks)

about:blank

6/7

11/8/24, 12:39 PM

ESA - DEC 2023 - UE21CS242A (set- 1)

5.b. what are middleware functions? Write brieﬂy about the order of
execution of middleware functions

(4.0 Marks)

5.c. Write a code in express to create a server which have 3 diﬀerent
route paths like /pes,/pes/:branch,/pes/branch/id which returns 3
diﬀerent contents when particular route has been entered in browser
if user enters following paths server should return following contents
 /pes —->Hello PES should be returned from the server
/pes/:CSE—-> branch name is CSE
/PES/:CSE/:123→id:123 and name :CSE

(6.0 Marks)

5.d. Write a route called “picsupload” which receives multiple image ﬁles
in a POST request. The route function should save each of them under
the “pics” folder in the same directory as the JS ﬁle. Any error like, no ﬁles
uploaded or saving ﬁles failed should be handled accordingly.
Note: Write only the server JS code. HTML/client code is not required.

(6.0 Marks)

about:blank

7/7

PES University, Bengaluru

(Established under Karnataka Act 16 of 2013)

END SEMESTER ASSESSMENT (ESA) - JULY - 2023

UE21CS242A - Web Technologies

1.a. What is a protocol? Diﬀerentiate between HTTP and HTTPs

(4.0 Marks)

Total Marks : 100.0

1.b. Explain the usage of checkbox and radio button in forms with example.

(6.0 Marks)

1.c. Create a table as shown in ﬁgure below with borders and caption as “Student
Details”

(6.0 Marks)

1.d.
Mention the steps required to add a hyperlink to an image

(4.0 Marks)

2.a. What is Event bubbling in DOM ?

(4.0 Marks)

2.b. Give an example for built in object in JavaScript.

(4.0 Marks)

2.c. Explain JQuery selectors.

(6.0 Marks)

2.d. Explain following HTML New tags with an example:

1. Audio and Video tag
2. Progress Bar

3.a.
Give an example for complex components in React.

(6.0 Marks)

(4.0 Marks)

3.b. Deﬁne Refs wrt React with an example.

(3.0 Marks)

3.c.
Write a note on stateless components

(3.0 Marks)

3.d. Explain 3 phases of Component Lifecycle.

(6.0 Marks)

3.e. Create a class component which will render a H1 and paragraph element apply
diﬀerent inline style for H1 and P element created using java script objects (key
value pair).

(4.0 Marks)

4.a. Write a code snippet that reads from a ﬁle “test.txt” and writes the ﬁrst 20
characters to the ﬁle “test20.txt” (Hint: You can use string methods). The code must
appropriately handle the errors also.
(6.0 Marks)

4.b.
What are the diﬀerent kinds of events that can be ﬁred by streams?

(4.0 Marks)

4.c. Diﬀerentiate between update and save query in MongoDB.

(4.0 Marks)

4.d. Create a MongoDB database Company that has a collection Employee (name,
ssn, age, salary etc). Write a Server code to Insert the documents and retrieve the
same.

(6.0 Marks)

5.a. What is RESTful API? Explain design speciﬁcations of RESTful API.

(4.0 Marks)

5.b. Explain the role of express middleware function with an example

(5.0 Marks)

5.c. How error handling is achieved in ExpressJS

(5.0 Marks)

5.d.
Explain how routing can be achieved in ExpressJS with the help of GET
method

(6.0 Marks)

PES University, Bengaluru

(Established under Karnataka Act 16 of 2013)

END SEMESTER ASSESSMENT (ESA) - May 2023

UE21CS242A - Web Technologies

1.a. What is HTTP? Explain the structure of HTTP request message.

(4.0 Marks)

Total Marks : 100.0

1.b. Create an HTML form with the following controls:

1.  A text box to collect the user’s name
2.  A multiline input ﬁeld to collect user’s address
3.  Three checkboxes, one each for the following items:
1. wireless mouse
2.  Mobile Charger
3. USB
4.  A collection of three radio buttons for Payment option that are labelled as

follows:

1.  Net Banking
2.  Google Pay
3.  Cash on Delivery
5.  Submit and reset Button

1.c. What are the 3 ways of including CSS on an HTML page? Give Example

(6.0 Marks)

(7.0 Marks)

1.d. Explain the concept of hoisting in JavaScript? How can we avoid hoisting in Java
Script?
(3.0 Marks)

2.a. Create a HTML form with 2 input ﬁleds and 2 buttons invoke click event on the
buttons to calculate multiplication and division of two numbers by taking form
input from user.

(6.0 Marks)

2.b. Write jQuery code to perform the following:
1. For the last paragraph within the div with id “colortext”, set the color to yellow.
2. On moving the mouse over an h1 element, the text font size should be increased
by 3 times
3. When the ﬁrst li element with class name “liclass” on the page is clicked, it fades
out in 2 seconds and then fades in 3 seconds

(6.0 Marks)

2.c. Explain event.PreventDefault, event.stopPropogation with example

(4.0 Marks)

2.d. What are diﬀerent ways through which we can access the DOM elements? Give
any four with example
(4.0 Marks)

3.a. With a neat diagram explain component life cycle.

(6.0 Marks)

3.b. Given an array of names of 3 fruits  of your choice, render an unordered list
with each fruit name as a list item.

(4.0 Marks)

3.c. What is the diﬀerence between DOM Events and Synthetic Events. Give
example?

(4.0 Marks)

3.d. List out the diﬀerences between stateful and stateless components

(6.0 Marks)

4.a. What are buﬀers in Node.js? With help of syntax explain any 2 buﬀer
operations

(5.0 Marks)

4.b. Explain File system Module in NodeJS with an example

(6.0 Marks)

4.c. Imagine you have a MongoDb database “myDB” which has collection
“students” with ﬁelds student_ID, student_Name,Semester, Department and
Contact_no. Write a program to connect to MongoDB database in Node.js to ﬁnd
data of all students who study in CSE department.
Note: Only write Server Side code

(5.0 Marks)

4.d. Create a module that calculates the area of a circle and circumference of a
circle.
Give the radius, export the module and print the area of circle and circumference
of a circle on the console.

(4.0 Marks)

5.a. What is RESTful API? Explain any 4 design speciﬁcation/constraints of REST API.
(4.0 Marks)

5.b. Explain the role of express middleware function. What are the diﬀerent types
of middleware an express application can use?

(6.0 Marks)

5.c. Write a program to upload a ﬁle under the upload folder in the same directory
as the JS ﬁle with proper error handling.
Note: Write only the server JS code. HTML/client code is not required.

(6.0 Marks)

5.d. Explain Error handling in ExpressJS

(4.0 Marks)

PES University, Bengaluru

(Established under Karnataka Act 16 of 2013)

END SEMESTER ASSESSMENT (ESA) - Jan - May 2024

UE21CS242A - Web Technologies

1.a. What is HTTP? Explain the structure of HTTP request message.

(5.0 Marks)

Total Marks : 100.0

1.b. Write a HTML code that outputs the following:

NOTE: The ‘Number’ ﬁeld is a mandatory ﬁeld, and takes in only a 10-digit number.

Also, Submit and Reset buttons do their conventional tasks.

(10.0 Marks)

1.c. The only way to apply CSS is by using external stylesheets”. Accept or reject this
statement with suitable explanation.
(5.0 Marks)

2.a. Write brieﬂy about the two methods of geolocation object.

(4.0 Marks)

2.b. A HTML page contains the following:
    - A table exists with id “table1”
    - A button “Add” with id “btn1”
    - A div with id “display”
Add JavaScript to the webpage for the following speciﬁcations
    • On clicking “Add” a new row with 2 cells are added to the table
    • Populate each cell with a random number (between 1 and 200)
    • If the cell contains an even number, mouse over should turn the cell green
    • If the cell contains an odd number, mouse over should turn the cell red.
    • If you click on a cell, the div will be populated with the cell content
Note: Write only vanilla JavaScript code. Assume that body tag has an
onload=”init()” handler.

(10.0 Marks)

2.c. Write jQuery code to perform the following:
1. For the last paragraph within the div with id “colortext”, set the color to green.
2. On moving the mouse over an h1 element, the text font size should be increased
by 5 times
3. When the ﬁrst li element with class name “liclass” on the page is clicked, it fades
out in 2 seconds and then fades in 3 seconds

(6.0 Marks)

3.a. Explain the following methods of component life cycle:
- componentDidMount
- componentDidUpdate
- componentWillUnmount

(6.0 Marks)

3.b. Create a class component which will render a H1 and paragraph element apply
diﬀerent inline style for H1 and P element created using java script objects (key
value pair).

(6.0 Marks)

3.c. i) What would be the output of the following example? Justify your answer

var Test=(props)=>

```js
{

return (

<div>
Hello World 1
</div>
<div>
Hello World 2
</div>
);
}
ReactDOM.render(<Test/>, mountNode)
```
ii) Which of the following is used to pass data to a component from outside in

React.js? Justify your answer

a. SetState

b. Render with arguments

c. Props

d. PropTypes

(6.0 Marks)

3.d. What is the signiﬁcance of key property?

(2.0 Marks)

4.a. Develop a basic server using the HTTP GET method that serves HTML ﬁles
based on the provided pathname. If no pathname is provided, the server should
default to serving 'index.html'. Additionally, implement error handling to display a
'File Not Found' message if the requested ﬁle is not found.

(10.0 Marks)

4.b. Write JavaScript code using Node.js modules exclusively (without Express.js) to
handle a GET request in the format http://server:8000/calc?
op=add&op1=10&op2=20. The server should perform the speciﬁed arithmetic
operation (addition, subtraction, multiplication, or division) on the two provided
operands and return the result as the response. For instance, if the operation is
'add' and the operands are 10 and 20, the server should return the result of adding
them, which is 30.
(10.0 Marks)

5.a. What is RESTful API? Explain any 4 design speciﬁcation/constraints of REST API.
(6.0 Marks)

5.b. Write a program to upload a ﬁle to Node.js server using express ﬁle upload
library.

(6.0 Marks)

5.c. Develop a server-side JavaScript script to handle routing for GET and POST
requests related to ﬂight details. Flight details are stored in a MongoDB database
in the following structure:

{from:”BLR”, to:”DEL”, dept:”12:25”, arrv:”14:25”, ﬂnum:”6E-2428”}

The server script should support the following routes:

- GET /ﬂights – return details of all ﬂights
- GET /ﬂights/:from/:to – return details of ﬂight between speciﬁc airports
- POST /ﬂights – save details of a ﬂight and return a success or error message

(8.0 Marks)

---

UE22CS242A - Web Technologies

1.a. What is HTTP? Explain the structure of HTTP request message. (6.0 Marks)

1.b. Create a Placement form with the following controls: (10.0 Marks)

a. A text box to collect the student’s name and SRN
b. A multiline input ﬁeld to collect college name and address
c. A student should give choice to tick their department from a list of departments
    i. CSE
    ii. ECE
    iii. MECH
d. A collection of three radio buttons for Semester option that are labelled as
follows:
    i. IV
    ii. V
    iii.VI
e. Submit and reset Button

1.c. Describe the structure of HTTP Request and Response message using an
example. (5.0 Marks)

1.d. With a neat diagram, explain the CSS Box model and its signiﬁcance. (4.0 Marks)

2.a. What is Geo Location? Explain the two methods of navigator.geolocation
object? Write a program to display your current location on the browser when the button
“Get Current Position” is clicked as shown below. (10.0 Marks)

2.b. What is AJAX? Explain in detail any 3 XHR object properties. (6.0 Marks)

2.c. Give the diﬀerence between JSON and XML.

Represent the details of three 6th sem students both in JSON and XML. Consider the attributes id, name, branch, CGPA (9.0 Marks)

3.a. Create a simple server (use http request GET method) that will allow you to
display an HTML ﬁle on the browser given the pathname. Set default pathname to
index.html. Handle errors by displaying ﬁle not found message (10.0 Marks)

3.b. With a neat diagram explain component life cycle. (8.0 Marks)

3.c. What is the signiﬁcance of key property? Describe with an example. (7.0 Marks)

4.a. What is RESTful API? Explain any 4 design speciﬁcation/constraints of REST API. (6.0 Marks)

4.b. Write server-side script in JavaScript to route requests for GET and POST
requests for ﬂight details. The details are stored in the mongodb database in the
following format. (10.0 Marks)

{from:”BLR”, to:”DEL”, dept:”12:25”, arrv:”14:25”, ﬂnum:”6E-2428”}
The server script should support the following routes:
    - GET /ﬂights – return details of all ﬂights
    - GET /ﬂights/:from/:to – return details of ﬂight between speciﬁc airports
    - POST /ﬂights – save details of a ﬂight and return a success or error message

4.c. Explain the role of express middleware function. What are the diﬀerent types
of middleware an express application can use? (4.0 Marks)

4.d. Write a program to upload a ﬁle to Node.js server using express ﬁle upload
library. (5.0 Marks)
