const cin=require("prompt-sync")();
let n=parseInt(cin());
rec(n);
function rec(n){
    if(n==0)return ;
    console.log(n);
    rec(n-1);
}