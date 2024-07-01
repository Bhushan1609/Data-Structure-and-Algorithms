const cin=require("prompt-sync")();
let ar=[1,2,3,4,5,6,7,8,9];
rec(0,ar.length-1,ar);
console.log(ar);
function rec(i,j,ar){
    if(i>j)return;
    let temp=parseInt(ar[i]);
    ar[i]=ar[j];
    ar[j]=temp;
    rec(i+1,j-1,ar);
}