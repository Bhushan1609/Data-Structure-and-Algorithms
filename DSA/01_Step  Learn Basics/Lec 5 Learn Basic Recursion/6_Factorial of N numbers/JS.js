const cin=require("prompt-sync")();
let n=parseInt(cin());
console.log(rec(n));
function rec(n){
    if(n==0)return 1;
    return n*rec(n-1);
}