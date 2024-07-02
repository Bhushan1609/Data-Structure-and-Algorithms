const cin=require("prompt-sync")();
let v=[1,2,3,4,5,6,7,8];
let v1=[1,2,3,4,5,6,7,8];
let d=5;
d=d%v.length;
brute(v,d);
optimal(v1,d);
function brute(v,d){
    let temp=[];
    for(let i=0;i<d;i++)temp.push(v[i]);
    for(let i=d;i<v.length;i++){
        v[i-d]=v[i];
    }
    for(let i=v.length-d;i<v.length;i++){
        v[i]=temp[i - (v.length-d)];
    }
    console.log(v);
    return ;
}
function optimal(v1,d){
    reverse(0,d-1,v1);
    reverse(d,v1.length-1,v1);
    reverse(0,v1.length-1,v1);
    console.log(v);
    return ;
}
function reverse(low,high,v1){
    while(low<=high){
        let temp=v[low];
        v1[low]=v1[high];
        v1[high]=temp;
        low++;
        high--;      
    }
}