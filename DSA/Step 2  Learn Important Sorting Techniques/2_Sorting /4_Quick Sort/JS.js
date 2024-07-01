const cin=require("prompt-sync")();
let v=[43,12,4,566,2,33,78];
quickSort(v,0,v.length-1);
console.log(v);
function partition(v,low,high){
    let pivot=v[low];
    let i=low;
    let j=high;
    while(i < j){
        while(v[i]<=pivot && i<high)i++;
        while(v[j]>pivot && j>low)j--; 
        if(i<j){
			let temp=v[i];
			v[i]=v[j];
			v[j]=temp;
		}
    }
    let temp=v[low];
	v[low]=v[j];
	v[j]=temp;
    return j;
}
function quickSort(v,low,high){
    if(low < high){
        let partitionIndex=partition(v,low,high);
        quickSort(v,low,partitionIndex-1);
        quickSort(v,partitionIndex+1,high);
    }
}