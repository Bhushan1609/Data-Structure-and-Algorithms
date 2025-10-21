let arr=[1,2,4,7,7,5];
callBrute(arr);
callBetter(arr);
callOptimal(arr);

function callBrute(arr){
    let n=arr.length;
    arr.sort();
    let largest=arr[n-1],secondLargest=-Infinity;
    for(let i=n-2;i>=0;i--){
        if(arr[i] != largest){
            secondLargest=arr[i];
            break;
        }
    }
    console.log(secondLargest);
}

function callBetter(arr){
    let n=arr.length,largest=-Infinity,secondLargest=-Infinity;
    for(let i=0;i<n;i++) largest=Math.max(largest,arr[i]);
    for(let i=0;i<n;i++){
        if(largest != arr[i]){
            secondLargest=Math.max(secondLargest,arr[i]);
        }
    }
    console.log(secondLargest);
}

function callOptimal(arr){
    let n=arr.length,largest=-Infinity,secondLargest=-Infinity;
    for(let i=0;i<n;i++){
        if(arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
    }
    console.log(secondLargest);
}