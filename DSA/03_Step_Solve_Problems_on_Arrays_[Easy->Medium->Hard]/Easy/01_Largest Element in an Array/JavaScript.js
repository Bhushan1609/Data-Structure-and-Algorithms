let arr=[3,2,1,5,2];
callBrute(arr);
callOptimal(arr);

function callBrute(arr){
    arr.sort();
    console.log(arr[arr.length-1]);
}

function callOptimal(arr){
    let maxi=-Infinity;
    for(let i=0;i<arr.length;i++) maxi=Math.max(maxi,arr[i]);
    console.log(maxi);
}
