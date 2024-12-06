let arr1=[1,1,2,3,4,5];
let arr2=[2,3,4,4,5,6];

callBrute(arr1,arr2);
callOptimal(arr1,arr2);

function callBrute(arr1,arr2){
    let st=new Set();
    let temp=[];
    for(let i=0;i<arr1.length;i++)st.add(arr1[i]);
    for(let i=0;i<arr2.length;i++)st.add(arr2[i]);
    for(let i of st)temp.push(i);
    console.log(temp);
}

function callOptimal(arr1,arr2){
    let i=0,j=0;
    let temp=[];
    while(i<arr1.length && j<arr2.length){
        if(arr1[i]<arr2[j]){
            if(temp.length > 0){
                let nn=temp.length;
                if(temp[nn-1] != arr1[i]){
                    temp.push(arr1[i]);
                }
            }else temp.push(arr1[i]);
            i+=1;
        }else{
            if(temp.length > 0){
                let nn=temp.length;
                if(temp[nn-1] != arr2[j]){
                    temp.push(arr2[j]);
                }
            }else temp.push(arr2[j]);
            j+=1;
        }
    }
    while(i<arr1.length){
        if(temp.length > 0){
            let nn=temp.length;
            if(temp[nn-1] != arr1[i]){
                temp.push(arr1[i]);
            }
        }else temp.push(arr1[i]);
        i+=1;
    }
    while(j<arr2.length){
        if(temp.length > 0){
            let nn=temp.length;
            if(temp[nn-1] != arr2[j]){
                temp.push(arr2[j]);
            }
        }else temp.push(arr2[j]);
        j+=1;
    }
    console.log(temp);
}