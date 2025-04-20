const fs=require('fs');
let inputString=fs.readFileSync('input.txt','utf-8').split('\n').filter(line=>line.trim()!=='');
let currentLine=0;
let output=[];

function readline() {
    return inputString[currentLine++] ;
}

function insertionSort(arr){
	let n=arr.length;
	for(let i=0;i<n;i++){
		let j=i;
		while(j>0 && arr[j]<arr[j-1]){
			let temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			--j;
		}
	}
	return ;
}

function main(){
	let arr=[13,46,24,52,20,9];
	output.push("Before Sorting : ");
	let oneline="";
	for(let i in arr)
		oneline+=arr[i]+" ";
	output.push(oneline);

	insertionSort(arr);

	output.push("After Sorting : ");
	oneline="";
	for(let i in arr)
		oneline+=arr[i]+" ";
	output.push(oneline);
    fs.writeFileSync('output.txt',output.join('\n'));
}

main();
//Problem Link : https://www.geeksforgeeks.org/problems/insertion-sort/1