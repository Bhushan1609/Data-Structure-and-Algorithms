let arr=[1,2,3,4,5];
rotateOneSpace(arr);
console.log(arr);

function rotateOneSpace(arr){
    let n=arr.length,temp=arr[0];
    for(let i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}
