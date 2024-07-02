const cin=require("prompt-sync")();
let n=parseInt(cin());
rec(n);
function rec(n){
    if(n==0)return ;
    console.log("Bhushan");
    rec(n-1);
}