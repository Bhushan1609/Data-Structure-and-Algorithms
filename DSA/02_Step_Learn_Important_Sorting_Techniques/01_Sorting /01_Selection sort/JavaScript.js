const fs=require('fs');
let inputString=fs.readFileSync('input.txt','utf-8').split('\n').filter(line=>line.trim()!=='');
let currentLine=0;
let output=[];

function readline() {
    return inputString[currentLine++] ;
}

function swap(i,j,arr){
	let temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	return ;
}

function selectionSort(arr){
	let n=arr.length;
	for(let i=0;i<n;i++){
		let minIndex=i;
		for(let j=i+1;j<n;j++){
			if(arr[minIndex]>arr[j]){
				minIndex=j;
			}
		}
		swap(i,minIndex,arr);
	}
}

function main(){
	let arr=[13,46,24,52,20,9];
	output.push("Before Sorting : ");
	let oneline="";
	for(let i in arr)
		oneline+=arr[i]+" ";
	output.push(oneline);

	selectionSort(arr);

	output.push("After Sorting : ");
	oneline="";
	for(let i in arr)
		oneline+=arr[i]+" ";
	output.push(oneline);
	fs.writeFileSync('output.txt',output.join('\n'));
}

main();
//Problem Link : https://www.geeksforgeeks.org/problems/selection-sort/1