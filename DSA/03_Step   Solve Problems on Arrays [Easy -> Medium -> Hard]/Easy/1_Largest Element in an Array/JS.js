const cin=require("prompt-sync")();
let v=[5,67,890,1,23,345];
brute(v);
optimal(v);
function brute(v){
    v.sort();
    console.log(v[v.length-1]);
}
function optimal(v){
    let ans=-Infinity;
    for(let i=0;i<v.length;i++) ans=Math.max(ans,v[i]);
    console.log(ans);
}