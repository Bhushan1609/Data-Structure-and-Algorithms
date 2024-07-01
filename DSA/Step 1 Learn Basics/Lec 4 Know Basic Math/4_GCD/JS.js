const cin=require("prompt-sync")();
let a=parseInt(cin());
let b=parseInt(cin());
function gcd (a,b){
    if (b == 0) return a;
    else return gcd(b, a%b);
}
console.log(gcd(a,b));