const cin=require("prompt-sync")();
let n=parseInt(cin());

let x=64+n;
for(let i=1;i<=n;i++){
    let cond=i;
    let s="";
    for (let ch = x; ch >= 'A'.charCodeAt(0) && cond > 0; ch--, cond--) {
        s += String.fromCharCode(ch) + " ";
    }
    console.log(s);
}