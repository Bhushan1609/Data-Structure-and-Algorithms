let arr=[1,0,2,3,2,0,0,4,5,1];
callBrute(arr);
callOptimal(arr);

function callBrute(arr){
    let temp=[];
    for(let i=0;i<arr.length;i++){
        if(arr[i]>0)temp.push(arr[i]);
    }
    for(let i=temp.length;i<arr.length;i++){
        temp.push(0);
    }
    console.log(temp);
}

function callOptimal(arr){
    let left=-1,right=0;
    while(right<arr.length){
        if(arr[right]>0){
            if(left!=-1){
                let temp=arr[left];
                arr[left]=arr[right];
                arr[right]=temp;
                left++;
            }
            right++;
        }else{
            if(left==-1)left=right;
            right+=1;
        }
    }
    console.log(arr);
}