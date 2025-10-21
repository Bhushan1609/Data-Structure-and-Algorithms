let arr=[1,2,3,4,5];
let d=4;
callBrute(arr,d);
callOptimal(arr,d);

function callBrute(arr,d){
    let n=arr.length,j=0;
    d%=n;
    let temp=[];
    for(let i=0;i<d;i++) temp.push(arr[i]);
    for(let i=d;i<n;i++)arr[i-d]=arr[i];
    for(let i=n-d;i<n;i++)arr[i]=temp[j++];
    console.log(arr);
}

function callOptimal(arr){
    let n=arr.length;
    d%=n;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
    console.log(arr);
}

function reverse(arr,i,j){
    while(i<j){
        let temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i+=1;
        j-=1;
    }
}