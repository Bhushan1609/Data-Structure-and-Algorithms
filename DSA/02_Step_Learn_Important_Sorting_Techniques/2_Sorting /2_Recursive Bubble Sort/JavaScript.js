let arr=[13,46,24,52,20,9];
recursiveBubbleSort(arr);
console.log(arr);

function recursion(arr,i){
    if(i<0)return;
    for(let j=0;j<i;j++){
        if(arr[j]>arr[j+1]){
            let temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    recursion(arr,i-1);
}
function recursiveBubbleSort(arr){
    recursion(arr,arr.length-1);
}