/*You're sending JSON data in the request body, which includes a name and srn. The response from the server is then converted to text and logged to the console. Sample.txt is end point where JSON data is stored*/
import fetch from 'cross-fetch';
fetch('http://localhost:8080/sample.txt', {
    method: 'POST',
    headers: { 'Content-type': 'application/json' },
    body: JSON.stringify({ "name": "Ram", "srn": "1234" })
})
    .then((res) => res.text())
    .then((res) => console.log(res))


