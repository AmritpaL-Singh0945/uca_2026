function sleep(ms){
    return new Promise((resolve)=>setTimeout(resolve,ms));
}
console.log("Before sleep");
sleep(3000); 
console.log("After sleep");
sleep(2000);

function sleep(ms){
    return new Promise((resolve)=> setTimeout(resolve,ms));
}

function demo(){
    while (true){
        console.log ("before sleep");
    }

}
demo(); 


//stack heap queue

//Stack
//Step1 : console.log("Before sleep"); // executes and stack is empty again
//step2 : sleep(3000) return new Promise((resolve)=>setTimeout(resolve,ms)); // pop out immediately and stack is empty 
//step3 : console.log("After sleep");

// browser apis 
// --fetch 
// --promise
// --DOMevents these are like onClick , on hover
// --setTimeout

// jo bhi hum variables bna rhe hai that is stored in the browser heap 

// Queue 

//  ----> macrotask queue -- setTimeout, DOM events
//  ----> microtask queue -- Promise, Fetch, then , catch , finally,XMLHttpRequest 

// promise --> calls an api and pass the result to a function function(value) {return value};

// microtask queue 
 // function2000(value ) {return value};
// function3000(value) {return value};

//stack -- Stage 2
// function2000 (value) {return value };
// sleep(2000)
// sleep(3000)

// stack -- stage 3
// function3000 (Value) {return value}; // taken by the browser api
// sleep(3000)

// stack -- stage 4
// empty stack 

// fetch("https://getsomedata.get")--> this is performed by browser api 
// results of fetch function fetch("https://getsomedata.get").then(returnvalue=>{console.log(value)});

// returnvalue=>{console.log(value)}; --> this is moved to queue

// microtask queue has more priority than macrotask queue

// any async operation that cant be handled by javascript is handled by browser api 

// javascript event loop (study ourself)

// every async function automatically maps to a promise


// the boolean operators 

// || returns the first true value (can be helpfull in error finding )

// the lighthouse 

// web vitals


