console.log("Inside the worker")

// 3 threads running in parallel

// main thread // worker // XMLHttpRequest 

function heavyProcessing(number){
    let start=Date.now();
    let sum=0;
    for(let i=0;i<number;i++){
        sum+=i;
    }
    let end=Date.now()
    console.log((end-start)/1000);
    self.postMessage(sum); // send the result back to the main thread
    return sum;

}

self.onmessage=function(event){
    const dataFromMainThread=event.data;
    console.log("Data from main thread",dataFromMainThread);
    heavyProcessing(1000000);
}


// we are able to create a new thread because of the browser api  