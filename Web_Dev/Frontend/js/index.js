// browser apis 
//  network requests
// service worker
//  web worker 
//  web storage 
//  DOM Events 
//  setTimeout
//  setInterval
//  navigator.geolocation

//Network requests 
// xmlHTTPrequest -XHR
// -fetch

// What does new do 
// --allocates memory 
// --store the reference of memory location in the variable 
// the reference point to 'this' keyword inside the class/functions (constructor function) definition

// xmlHTTPrequest -XHR
// Used for making network request to the server 
//JSON example --> object literal 
var data ={
    name:"name"
}

new xhr1=new XMLHttpRequest() // allocate memory and store the reference in the variable

// xhr.open("Type","URL","isAsync")

xhr.open("GET","https://dummyjson.com/products/1",true) // true -async , false - sync 

xhr.onload=function(){
    console.log(xhr1.responseText)
}

xhr.send() // send the request to the server

//local server url 

// http://127.0.0.1:5500/frontend/index.html

//127:0.0.1===0.0.0.1 =localhost

// port(incoming points) : 5500 -- same machine can have multiple ports but one IP address 
// 5200,80,443