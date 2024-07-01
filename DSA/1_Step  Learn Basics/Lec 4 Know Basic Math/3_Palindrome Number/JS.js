const cin=require("prompt-sync")();
let n=parseInt(cin());
let ans=0;
let dup=n;
while(n != 0){
    ans = ans*10 + n%10;
    n=Math.floor(n/10);
}
if(dup===ans)console.log("YES");
else console.log("NO");