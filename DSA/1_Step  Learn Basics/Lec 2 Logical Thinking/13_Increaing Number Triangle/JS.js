const cin=require("prompt-sync")();
let n=parseInt(cin());
let start=1;
for(let i=1;i<=n;i++){
    let s="";
    for(let j=0;j<i;j++)s+=((start++)+" ");
    console.log(s);
}