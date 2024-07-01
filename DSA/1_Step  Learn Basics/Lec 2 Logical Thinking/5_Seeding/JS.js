const cin=require("prompt-sync")();
let n=parseInt(cin());
for(let i=n;i>0;i--){
    let s='';
    for(let j=0;j<i;j++) s+='*';
    console.log(s);
}