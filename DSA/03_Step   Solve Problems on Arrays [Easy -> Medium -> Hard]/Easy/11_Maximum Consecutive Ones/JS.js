const cin=require("prompt-sync")();
let v=[1,0,1,1,1,1,0,0,00,00,0,1,1,1];
let cnt=0,maxi=-Infinity;
for(let i=0;i<v.length;i++){
    if(v[i]==1)cnt++;
    else cnt=0;
    maxi=Math.max(maxi,cnt);
}
console.log(maxi);