// browser api --> web workers

console.log("code before the web worker starts ")

//Browser API code 

const webworker1=new Worker("./js/worker.js");

webworker1.postMessage(2000000);
webworker1.onmessage=function(event){
    document.getElementById("result").innerHTML=event.data;

}

console.log("Code after the web workers code ")

