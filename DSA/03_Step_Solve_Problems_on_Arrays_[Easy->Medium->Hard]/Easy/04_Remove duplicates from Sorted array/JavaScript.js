let arr=[1,1,2,2,2,3,3];
callBrute(arr);
callOptimal(arr);

function callBrute(arr){
    let st=new Set();
    let newArr=arr;
    for(let i=0;i<newArr.length;i++)st.add(newArr[i]);
    let index=0;
    for(let i of st) newArr[index++]=i;
    console.log(newArr);
}


function callOptimal(arr){
    let i=0,currValue=-Infinity;
    for(let j=0;j<arr.length;j++){
        if(arr[j] !== currValue){
            arr[i++]=arr[j];
            currValue=arr[j];
        }
    }
    console.log(arr);
}

