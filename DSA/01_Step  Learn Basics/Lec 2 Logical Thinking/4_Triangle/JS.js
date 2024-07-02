const cin=require("prompt-sync")();
let n=parseInt(cin());
for(let i=1;i<=n;i++){
    let s="";
    for(let j=0;j<i;j++) s+=i;
    console.log(s);
}