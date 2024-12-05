let arr=[13,46,24,52,20,9];
mergeSort(arr,0,arr.length-1);
console.log(arr);

function merge(arr,low,mid,high){
    let temp=[];
    let left=low,right=mid+1,index=0;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push(arr[left++]);
        }else{
            temp.push(arr[right++]);
        }
    }
    while(left<=mid) temp.push(arr[left++]);
    while(right<=high) temp.push(arr[right++]);
    for(let i=low;i<=high;i++){
        arr[i]=temp[index++];
    }
    return ;
}
function mergeSort(arr,low,high){
    if(low>=high)return;
    let mid=(low+high)>>1;
    mergeSort(arr,0,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}