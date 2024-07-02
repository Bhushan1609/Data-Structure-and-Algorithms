const cin=require("prompt-sync")();
let n=parseInt(cin());
let cnt=0;
for(let i=1;i<=(Math.sqrt(n));i++){
    if(n%i == 0){
       cnt++;
        if(!(n/i == i))cnt++;
    }
}
if(cnt==2 || n==1)console.log("YES");
else console.log("NO");