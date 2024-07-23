let dp=new Array(1000001).fill(0);
let h=[1,2,3,4];
let k=2;
console.log(topDown(h.length-1,k,h,dp));
console.log(BottomUp(h.length,h,k));

function topDown( index, k, h,dp){
    if(index<=0) return (index == 0) ? 0 : Infinity;
    if(dp[index] != 0)return dp[index];
    let oneStep=Infinity;
    for(let i=1;i<=k;i++){
        if(index-i >= 0) oneStep=Math.min(oneStep,Math.abs(h[index] - h[index-i]) + topDown(index-i,k,h,dp));
    }
    return dp[index]=oneStep;
}
function BottomUp(n,h,k){
    let dp = new Array(n).fill(Infinity);
        dp[0] = 0;
        for (let index = 1; index < n; index++) {
            for (let i = 1; i <= k; i++) {
                if (index - i >= 0) {
                    dp[index] = Math.min(dp[index], Math.abs(h[index] - h[index - i]) + dp[index - i]);
                }
            }
        }
        return dp[n - 1];
}
