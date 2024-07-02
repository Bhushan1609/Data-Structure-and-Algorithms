const cin=require("prompt-sync")();
let v=[1,2,0,0,0,3,0,0,4,5,0,0];
let v1=[1,2,0,0,0,3,0,0,4,5,0,0];
brute(v);
optimal(v1);
function brute(v){
    let temp=[];
    for(let i=0;i<v.length;i++){
        if(v[i]!=0) temp.push(v[i]);
    }
    for(let i=0;i<temp.length;i++){
        v[i]=temp[i];
    }
    for(let i=temp.length;i<v.length;i++)v[i]=0;
    console.log(v);
}
function optimal(v1){
    let i=0;
    for( i=0;i<v1.length;i++){
        if(v1[i]==0){
            index =i;
            break;
        }
    }
    let j=i+1;
    while(j<v1.length){
        if(v1[j]!=0){
            let temp=v1[i];
            v1[i]=v1[j];
            v1[j]=temp;
            i++;
        }
        j++;
    }
    console.log(v1);

}