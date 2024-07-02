const cin=require("prompt-sync")();
let v=[1,1,2,3,3];
let v1=[1,1,2,3,3];
brute(v);
optimal(v1);
function brute(v){
    let s=new Set();
    for(let i=0;i<v.length;i++) s.add(v[i]);
    let index=0;
    for (let  i  of s) v[index++]=i;
    console.log(v);
}
function optimal(v){
    let i=0;
    let j=0;
    while(j<v.length && i<v.length){
        while(j<v.length && v[i] == v[j]){
            j++;
        }
        i+=1;
        if(j<v.length && i<v.length){
            let temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            j++;
        }
    }
    console.log(v);
}

