const cin=require("prompt-sync")();
let v=[43,12,4,566,2,33,78];
selectionSort(v);
console.log(v);
function selectionSort(v){
    for(let i=0;i<v.length;i++){
        let minindex=i;
        for(let j=i+1;j<v.length;j++){
            if(v[j]<v[minindex])minindex=j;
        }
        let temp=v[i];
        v[i]=v[minindex];
        v[minindex]=temp;
    }
}