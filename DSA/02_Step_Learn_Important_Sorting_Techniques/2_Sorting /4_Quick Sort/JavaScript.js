let arr=[13,46,24,52,20,9];
qs(arr,0,arr.length-1);
console.log(arr);
function givePartitionIndex(arr,low,high){
    let pivot=arr[low];
    let i=low;
    let j=high;
    while(i < j){
        while(arr[i]<=pivot && i<high)i++;
        while(arr[j]>pivot && j>low)j--; 
        if(i<j){
			let temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
    }
    let temp=arr[low];
	arr[low]=arr[j];
	arr[j]=temp;
    return j;
}
function qs(arr,low,high){
    if(low < high){
        let partitionIndex=givePartitionIndex(arr,low,high);
        qs(arr,low,partitionIndex-1);
        qs(arr,partitionIndex+1,high);
    }
}