const cin=require("prompt-sync")();
let n=parseInt(cin());
let c=0;
while(n != 0){
    n = Math.floor(n / 10);
    c++;
}
console.log(c);