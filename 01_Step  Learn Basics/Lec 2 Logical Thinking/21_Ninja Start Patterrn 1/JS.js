const cin=require("prompt-sync")();
let n=parseInt(cin());

for(let i=1;i<=n;i++){
    let s="";
    if(i==1 || i==n){
        for(let j=1;j<=n;j++)s+="*";
    }
    else{
        for(let j=1;j<=n;j++){
            if(j==1 || j==n)s+="*";
            else s+=' ';
        }
    }
    console.log(s);
}


