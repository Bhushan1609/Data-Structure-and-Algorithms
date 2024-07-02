const cin=require("prompt-sync")();
let v=[43,12,4,566,2,33,78];
bubbleSort(v,0);
console.log(v);
function bubbleSort(v,i){
    if(i>=v.length)return ;
    let maxiIndex=0;
    for(let j=0;j<v.length-i;j++){
        if(v[j]>v[maxiIndex])maxiIndex=j;
    }
    let temp=v[maxiIndex];
    v[maxiIndex]=v[v.length-i-1];
    v[v.length-i-1]=temp;
    bubbleSort(v,i+1)
}