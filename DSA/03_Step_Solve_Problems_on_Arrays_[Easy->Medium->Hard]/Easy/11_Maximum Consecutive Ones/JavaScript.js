let arr=[1,1,0,1,1,1,0,1,1];
let cnt=0,maxi=-1;
for(let i=0;i<arr.length;i++){
    if(arr[i]==1)cnt++;
    else {
        maxi=Math.max(maxi,cnt);
        cnt=0;
    }
}
console.log(maxi);