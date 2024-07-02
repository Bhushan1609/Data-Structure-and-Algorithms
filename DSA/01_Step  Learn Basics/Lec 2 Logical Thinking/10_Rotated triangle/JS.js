const cin=require("prompt-sync")();
let n=parseInt(cin());
for(let i=1;i<=(n<<1)-1;i++){
    let s="";
    if(i<=n)for(let j=0;j<i;j++)s+="*";
    else for(let j=0;j<(n-(i-n));j++)s+="*";
    console.log(s);
}