let arr=[1,2,4,5];
let n=5;
callBrute(arr,n);
callBetter(arr,n);
callOptimal1(arr,n);
callOptimal2(arr,n);

function callBrute(arr,n){
    for(let i=1;i<=n;i++){
        let flag=0;
        for(let j=0;j<arr.length;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(!flag){
            console.log(i);
            return ;
        }
    }
}

function callBetter(arr,n){
    let hash=new Array(n).fill(0);
    for(let i=0;i<arr.length;i++)hash[arr[i]]++;
    for(let i=1;i<hash.length;i++){
        if(!hash[i]) {
            console.log(i);
            return ;
        }
    }
}

function callOptimal1(arr,n){
    let sum=n*(n+1)>>1;
    for(let i=0;i<arr.length;i++) sum-=arr[i];
    console.log(sum);
}

function callOptimal2(arr,n){
    let xorr=0;
    for(let i=1;i<=n;i++) xorr^=i;
    for(let i=0;i<arr.length;i++) xorr^=arr[i];
    console.log(xorr);
}
