const cin=require("prompt-sync")();
let n=parseInt(cin());
for(let i=0;i<n;i++){
    let s="";
    for(let j=0;j<n;j++)s+="*";
    console.log(s);
}