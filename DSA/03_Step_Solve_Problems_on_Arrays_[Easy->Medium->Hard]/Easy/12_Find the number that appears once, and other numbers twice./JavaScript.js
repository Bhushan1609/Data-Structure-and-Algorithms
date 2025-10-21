let arr=[1,1,2,3,3,4,4];
callBrute(arr);
callBetter(arr);
callOptimal(arr);

function callBrute(arr){
    for(let i=0;i<arr.length;i++){
        let cnt=0;
        for(let j=0;j<arr.length;j++){
            if(arr[i]==arr[j])cnt++;
        }
        if(cnt==1){
            console.log(arr[i]);
            return;
        }
    }
}
function callBetter(arr){
    let mapp=new Map();
    for(let i of arr){
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
function callOptimal(arr){
    let xorr=0;
    for(let i of arr)xorr ^= i;
    console.log(xorr);
    return;
}