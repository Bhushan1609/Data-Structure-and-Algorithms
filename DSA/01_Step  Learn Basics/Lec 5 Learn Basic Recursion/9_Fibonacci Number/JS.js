const cin=require("prompt-sync")();
let n=parseInt(cin());
console.log(fibonacci(n));
function fibonacci(n){
    if(n<=1)return n;
    return fibonacci(n-1)+fibonacci(n-2);
}