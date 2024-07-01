const cin=require("prompt-sync")();
let n=parseInt(cin());

let ch='A';
for(let i=1;i<=n;i++){
    let s="";
    for(let j=0;j<i;j++)s+=(ch+" ");
    ch = String.fromCharCode(ch.charCodeAt(0) + 1);
    console.log(s);
}