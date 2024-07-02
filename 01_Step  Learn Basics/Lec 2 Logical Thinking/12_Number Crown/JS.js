const cin=require("prompt-sync")();
let n=parseInt(cin());
for(let i=1;i<=n;i++){
    let s="";
    for(let j=1;j<=i;j++)s+=j;
    for(let j=1;j<=((n<<1)-1)-(i<<1); j++)s+=" ";
    for(let j=i;j>=1;j--)s+=j;
    console.log(s);
}