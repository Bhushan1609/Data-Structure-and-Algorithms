let dp=new Array(1000001).fill(0);
let h=[1,2,3,4];
console.log(topDown(h.length - 1,h,dp));
console.log(BottomUp(h.length,h));
console.log(spaceOptimize(h.length,h));

function topDown(index,h,dp){
    if(index<=0) return (index == 0) ? 0 : Integer.MAX_VALUE;
    if(dp[index] != 0)return dp[index];
    let oneStep=Infinity,twoStep=Infinity;
    if(index-1 >= 0) oneStep=Math.abs(h[index] - h[index-1]) + topDown(index-1,h,dp);
    if(index-2 >= 0) twoStep=Math.abs(h[index] - h[index-2]) + topDown(index-2,h,dp);
    return dp[index]=Math.min(oneStep,twoStep);
}
function BottomUp(N,h){
    let dp=new Array(N).fill(0);
    for(let i=1;i<N;i++){
        let oneStep=Infinity,twoStep=Infinity;
        if(i-1 >= 0) oneStep=Math.abs(h[i] - h[i-1])+dp[i-1];
        if(i-2 >= 0) twoStep=Math.abs(h[i] - h[i-2])+dp[i-2];
        dp[i]=Math.min(oneStep,twoStep);
    }
    return dp[N-1];
}
function spaceOptimize(N,h){
    let p1=0,p2=0,curr;
    for(let i=1;i<N;i++){
        let oneStep=Infinity,twoStep=Infinity;
        if(i-1 >= 0) oneStep=Math.abs(h[i] - h[i-1])+p1;
        if(i-2 >= 0) twoStep=Math.abs(h[i] - h[i-2])+p2;
        curr=Math.min(oneStep,twoStep);
        p2=p1;
        p1=curr;
    }
    return p1;
}