const cin=require("prompt-sync")();
let v=[43,12,4,566,2,33,78];
insertionSort(v,0);
console.log(v);
function insertionSort(v,i){
    if(i>=v.length)return ;
    let j=i;
    while(j>0 && v[j-1]>v[j]){
        let temp=v[j];
        v[j]=v[j-1];
        v[j-1]=temp;
        j-=1;
    }
    insertionSort(v,i+1);
}