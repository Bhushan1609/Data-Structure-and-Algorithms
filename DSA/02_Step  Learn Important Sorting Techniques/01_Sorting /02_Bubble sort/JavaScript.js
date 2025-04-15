const fs = require('fs');
let inputString=fs.readFileSync('input.txt','utf-8').split('\n').filter(line=>line.trim()!=='');
let currentLine=0;
let output=[];

function readline() {
    return inputString[currentLine++];
}

function bubbleSort(arr){
	let n=arr.length;
	for(let j=n-1;j>=0;j--){
		for(let i=1;i<=j;i++){
			if(arr[i]<arr[i-1]){
				let temp=arr[i];
				arr[i]=arr[i-1];
				arr[i-1]=temp;
			}
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
	output.push("After Sorting : ");
	bubbleSort(arr);
	oneline="";
	for(let i in arr)
		oneline+=arr[i]+" ";
	output.push(oneline);
    fs.writeFileSync('output.txt', output.join('\n'));
}

main();
//Problem Link : https://www.geeksforgeeks.org/problems/bubble-sort/1