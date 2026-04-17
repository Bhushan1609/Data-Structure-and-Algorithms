const fs=require('fs');
let inputString=fs.readFileSync('input.txt','utf-8').split('\n').filter(line=>line.trim()!=='');
let currentLine=0;
let output=[];

function readline() {
    return inputString[currentLine++] ;
}

function merge(start,mid,end,arr){
    let i=start,j=mid+1;
    let temp=[];
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push(arr[i]);
            i++;
        }else{
            temp.push(arr[j]);
            j++;
        }
    }
    while(i<=mid)
        temp.push(arr[i++]);
    while(j<=end)
        temp.push(arr[j++]);

    for(let i=start;i<=end;i++)
        arr[i]=temp[i-start];
    
    return ;
}

function divide(start,end,arr){
    if(start>=end)
        return;
    let mid=Math.floor((start+end)/2);
    divide(start,mid,arr);
    divide(mid+1,end,arr);
    merge(start,mid,end,arr);
}

function mergeSort(arr){
        let n=arr.length;
        divide(0,n-1,arr);
    }

function main(){
    let arr=[13,46,24,52,20,9];
    output.push("Before Sorting : ");
    let oneline="";
    for(let i in arr)
        oneline+=arr[i]+" ";
    output.push(oneline);

    mergeSort(arr);

    output.push("After Sorting : ");
    oneline="";
    for(let i in arr)
        oneline+=arr[i]+" ";
    output.push(oneline);
    fs.writeFileSync('output.txt',output.join('\n'));
}

main();
//Problem Link : https://www.geeksforgeeks.org/problems/merge-sort/1