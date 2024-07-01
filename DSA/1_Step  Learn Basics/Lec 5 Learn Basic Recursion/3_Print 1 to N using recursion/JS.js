const cin=require("prompt-sync")();
let n=parseInt(cin());
rec(1,n);
function rec(a,n){
    if(a>n)return ;
    console.log(a);
    rec(a+1,n);
}