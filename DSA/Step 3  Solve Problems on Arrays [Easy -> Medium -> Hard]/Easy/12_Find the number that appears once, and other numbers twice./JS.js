const cin=require("prompt-sync")();
let v=[1,2,1,3,4,3,4];
let v1=[1,2,1,3,4,3,4];
let v2=[1,2,1,3,4,3,4];
brute(v);
better(v1);
optimal(v2);
function brute(v){
    for(let i=0;i<v.length;i++){
        let cnt=0;
        for(let j=0;j<v.length;j++){
            if(v[i]==v[j])cnt++;
        }
        if(cnt==1){
            console.log(v[i]);
            return;
        }
    }
}
function better(v){
    let mapp=new Map();
    for(let i of v){
        if(mapp.has(i)){
            mapp.set(i,mapp.get(i)+1);
        }
        else{
            mapp.set(i,1);
        }
    }
    for(let [k,v] of mapp){
        if(v==1){
            console.log(k);
            return;
        }
    }
}
function optimal(v){
    let xorr=0;
    for(let i of v)xorr ^= i;
    console.log(xorr);
    return;
}