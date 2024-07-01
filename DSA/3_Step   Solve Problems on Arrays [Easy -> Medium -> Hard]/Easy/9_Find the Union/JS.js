const cin=require("prompt-sync")();
let a=[1,1,2,3,3,4,5];
let b=[1,2,2,3,5];
let a1=[1,1,2,3,3,4,5];
let b1=[1,2,2,3,5];

brute(a,b);
optimal(a1,b1);

function brute(a,b){
    let s=new Set();
    for(let i=0;i<a.length;i++)s.add(a[i]);
    for(let i=0;i<b.length;i++)s.add(b[i]);
    let ans=[];
    for(let i of s) ans.push(i);
    console.log(ans);
    return;
}
function optimal(a,b){
    let i=0;
    let j=0;
    let n=a.length,m=b.length;
    let ans=[];
    while(i<n && j<m){
        if(a[i] <= b[j]){
            if(ans.length==0 || ans.slice(-1)[0] != a[i]){
                ans.push(a[i]);
            }
            i++;
        }
        else{
            if(ans.length==0 || ans.slice(-1)[0] != b[j]){
                ans.push(b[j]);
            }
            j++;
        }
    }
    while(i<n){
        if(ans.length==0 || ans.slice(-1)[0] != a[i]){
            ans.push(a[i]);
        }
        i++;
    }
    while(j<m){
        if(ans.length==0 || ans.slice(-1)[0] != b[j]){
            ans.push(b[j]);
        }
        j++;
    }
    console.log(ans);
}

