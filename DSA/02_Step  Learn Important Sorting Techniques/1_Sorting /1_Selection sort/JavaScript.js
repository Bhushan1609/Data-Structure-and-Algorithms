let arr=[13,46,24,52,20,97];
selectionSort(arr);
console.log(arr);
function selectionSort(arr){
    let n=arr.length;
    for(let i=0;i<n-2;i++){
        let mini=i;
        for(let j=i;j<n;j++){
            if(arr[j]<arr[mini]) mini=j;
        }
        let temp=arr[i];
        arr[i]=arr[mini];
        arr[mini]=temp;
    }
}