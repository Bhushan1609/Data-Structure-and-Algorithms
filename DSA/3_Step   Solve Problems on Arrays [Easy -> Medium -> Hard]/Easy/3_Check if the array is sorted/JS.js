const cin=require("prompt-sync")();
let v=[5,67,890,1,23,345];
let val=1;
for(let i=0;i<v.length-1;i++){
    if(v[i]>v[i+1]){
        val=0;
        break;
    }
}
(val==1) ? console.log("YES") : console.log("NO");