let arr=[13,46,24,52,20,97];
bubbleSort(arr);
console.log(arr);
function bubbleSort(arr){
    let n=arr.length;
    for(let i=n-1;i>=0;i--){
        let didSwaps=0;
        for(let j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                let temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                didSwaps+=1;
            }
        }
        if(didSwaps === 0) break;
    }
}