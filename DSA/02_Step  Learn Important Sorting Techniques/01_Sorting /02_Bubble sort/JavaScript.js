const fs=require('fs');
let inputString=fs.readFileSync('input.txt','utf-8').split('\n').filter(line=>line.trim()!=='');
let currentLine=0;
let output=[];

function readline() {
    return inputString[currentLine++] ;
}

function bubbleSort(arr){
	let n=arr.length;
	for(let i=n-1;i>=0;i--){
		let swapHappens=false;
		for(let j=0;j<=i-1;j++){
			if(arr[j]>arr[j+1]){
				let temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapHappens|=true;
			}
		}
		if(!swapHappens)
			break;
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

	bubbleSort(arr);

	output.push("After Sorting : ");
	oneline="";
	for(let i in arr)
		oneline+=arr[i]+" ";
	output.push(oneline);
    fs.writeFileSync('output.txt',output.join('\n'));
}

main();
//Problem Link : http://geeksforgeeks.org/problems/bubble-sort/1