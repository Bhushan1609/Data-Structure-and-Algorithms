const cin=require("prompt-sync")();
let n=parseInt(cin());
let ans=0;
while(n != 0){
    ans = ans*10 + n%10;
    n=Math.floor(n/10);
}
console.log(ans);