const cin=require("prompt-sync")();
let n=parseInt(cin());
for(let i=0;i<=n;i++){
    let s="";
    for(let j=1;j<(i+1);j++) s+=j;
    console.log(s);
}