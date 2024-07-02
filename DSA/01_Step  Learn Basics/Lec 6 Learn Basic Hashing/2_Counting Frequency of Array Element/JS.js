const cin=require("prompt-sync")();
let a=[1,2,3,1,2,3];
let m=new Map();
for(let i=0;i<a.length;i++){
    if(m.has(a[i])){
        m.set(a[i],m.get(a[i]) + 1);
    }
    else m.set(a[i],1);
}
for (let [key, value] of m) {
    console.log(key + " -> " + value);
}