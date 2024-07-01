const cin=require("prompt-sync")();
let n=parseInt(cin());

for(let i=0;i<n;i++){
    let s="";
    let ch='A';
    for(let j=0;j<n-i-1;j++) s+=" ";
    for(let j=1;j<=2*i+1;j++){
        s+=(ch+" ");
        if(j <= (2*i+1)/2)ch = String.fromCharCode(ch.charCodeAt(0) + 1);
        else {
            ch = String.fromCharCode(ch.charCodeAt(0) - 1);
        }
    }
    for(let j=0;j<n-i-1;j++) s+=" ";
    console.log(s);
}