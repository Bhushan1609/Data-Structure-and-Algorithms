let arr=[1,2,1,3,4];
let ans=1;
for(let i=1;i<arr.length;i++){
    if(arr[i]<arr[i-1]){
        ans=0;
        break;
    }
}
console.log(ans);