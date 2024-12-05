let arr=[13,46,24,52,20,9];
recursiveInsertionSort(arr);
console.log(arr);

function recursion(arr,i){
    if(i>=arr.length)return;
    let j=i;
    while(j>0 && arr[j-1]>arr[j]){
        let temp=arr[j-1];
        arr[j-1]=arr[j];
        arr[j]=temp;
        j-=1;
    }
    recursion(arr,i+1);
}
function recursiveInsertionSort(arr){
    recursion(arr,0);
}