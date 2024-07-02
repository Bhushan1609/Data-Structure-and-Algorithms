const cin=require("prompt-sync")();
let ar="Bhushan";
if(rec(0,ar.length-1,ar)==1)console.log("YES");
else console.log("NO");
function rec(i,j,ar){
    if(i>j)return 1;
    if(ar[i] != ar[j])return 0;
    return rec(i+1,j-1,ar);
}