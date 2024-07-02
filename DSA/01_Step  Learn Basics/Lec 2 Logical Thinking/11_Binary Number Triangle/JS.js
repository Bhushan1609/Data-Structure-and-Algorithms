const cin=require("prompt-sync")();
let n=parseInt(cin());
for(let i=1;i<=n;i++){
    let s="";
    if((i&1)==1) {
    for(let j=0;j<i;j++){
            if((j&1)==0)s+="1";
            else s+="0";
        }
    }
    else{
        for(let j=0;j<i;j++){
            if((j&1)==1)s+="1";
            else s+="0";
        }
    }
    console.log(s);
}