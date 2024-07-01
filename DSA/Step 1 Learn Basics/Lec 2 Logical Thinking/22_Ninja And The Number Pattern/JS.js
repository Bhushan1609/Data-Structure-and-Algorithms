const cin=require("prompt-sync")();
let n=parseInt(cin());

for(let i=0;i<2*n-1;i++){
    let s="";

    for(let j=0;j<2*n-1;j++){
        s+=(n-Math.min(Math.min(i,j),Math.min(2*n-2-i,2*n-2-j)));
    }
    console.log(s);
}



