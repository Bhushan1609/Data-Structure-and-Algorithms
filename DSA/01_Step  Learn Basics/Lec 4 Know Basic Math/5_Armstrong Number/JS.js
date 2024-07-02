const cin=require("prompt-sync")();
let n=parseInt(cin());
let add=0;
let dup=n;
while(n != 0){
    let cube=n%10;
    add+=(cube*cube*cube);
    n=Math.floor(n/10);
}
if(dup===add)console.log("YES");
else console.log("NO");