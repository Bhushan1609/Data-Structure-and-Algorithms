const cin=require("prompt-sync")();
let v=[1,1,2,3,3];
let key=3;
for(let i=0;i<v.length;i++){
    if(v[i]===key){
        console.log(i);
        break;
    }
}