const fs=require('fs');
let inputString=fs.readFileSync('input.txt','utf-8').split('\n').filter(line=>line.trim()!=='');
let currentLine=0;
let output=[];

function readline() {
    return inputString[currentLine++] ;
}

function f(low,high,arr){
    let pivot=arr[low];
    let i=low;
    let j=high;

    while(i<j){
        while(i<high && arr[i]<=pivot)
            i++;

        while(j>low && arr[j]>pivot)
            j--;

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

function quickSort(low,high,arr){
    if(low<high){
        let partitionIndex=f(low,high,arr);
        quickSort(low,partitionIndex-1,arr);
        quickSort(partitionIndex+1,high,arr);
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

    quickSort(0,arr.length-1,arr);

    output.push("After Sorting : ");
    oneline="";
    for(let i in arr)
        oneline+=arr[i]+" ";
    output.push(oneline);
    fs.writeFileSync('output.txt',output.join('\n'));
}

main();
//Problem Link : https://www.geeksforgeeks.org/problems/quick-sort/1