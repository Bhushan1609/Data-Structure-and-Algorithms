const cin=require("prompt-sync")();
let n=parseInt(cin());
for(let i=1;i<=(Math.sqrt(n));i++){
    if(n%i == 0){
        console.log(i," ");
        if(!(n/i == i))console.log(n/i," ");
    }
}