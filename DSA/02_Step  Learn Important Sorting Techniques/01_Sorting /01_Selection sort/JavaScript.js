const fs=require('fs');
let inputString=fs.readFileSync('input.txt','utf-8').split('\n').filter(line=>line.trim()!=='');
let currentLine=0;
let output=[];

function readline() {
    return inputString[currentLine++] ;
}

function selectionSort(arr){
	let n=arr.length;
	for(let i=0;i<n;i++){
		let minIndex=i;
		let minValue=arr[i];
		for(let j=i+1;j<n;j++)
			if(minValue>arr[j])
				minValue=arr[j],minIndex=j;
		let temp=arr[i];
		arr[i]=arr[minIndex];
		arr[minIndex]=temp;
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
	selectionSort(arr);
	oneline="";
	for(let i in arr)
		oneline+=arr[i]+" ";
	output.push(oneline);
    fs.writeFileSync('output.txt', output.join('\n'));
}

main();
//https://www.geeksforgeeks.org/problems/selection-sort/1