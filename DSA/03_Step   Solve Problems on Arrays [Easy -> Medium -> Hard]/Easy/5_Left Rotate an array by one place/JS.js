const cin=require("prompt-sync")();
let v=[1,2,3,4,5];

for(let i=0;i<v.length-1;i++){
    let temp=v[i];
    v[i]=v[i+1];
    v[i+1]=temp;
}
console.log(v);