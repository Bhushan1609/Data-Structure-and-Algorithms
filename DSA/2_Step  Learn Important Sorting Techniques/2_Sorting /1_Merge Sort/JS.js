const cin=require("prompt-sync")();
let v=[43,12,4,566,2,33,78];
mergeSort(v,0,v.length-1);
console.log(v);
function merge(v , low, mid,  high){
	let i=low;
	let j=mid+1;
	let temp=[];
	while(i<=mid && j<=high){
		if(v[i]<=v[j])temp.push(v[i++]);
		else temp.push(v[j++]);
	}
	while(i<=mid)temp.push(v[i++]);
	while(j<=high)temp.push(v[j++]);
	for(let i=low;i<=high;i++) v[i]=temp[i-low];
}
function mergeSort(v, low , high){
    if(low>=high) return;
	let mid=Math.floor((low+high)/2);
	mergeSort(v,low,mid);
	mergeSort(v,mid+1,high);
	merge(v,low,mid,high);
}