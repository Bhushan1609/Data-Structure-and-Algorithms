let n=10;
let dp=new Array(n+1).fill(0);
console.log(topDown(n,dp));
console.log(BotttomUp(n));
console.log(spaceOptimize(n));
function topDown(n,dp){
    if(n<=0)return (n == 0) ? 1 : 0;
    if(dp[n] != 0)return dp[n];
    return dp[n]=topDown(n-1,dp) + topDown(n-2,dp);
}
function BotttomUp (n){
    let dp=new Array(n+1).fill(0);
    dp[0]=dp[1]=1;
    for(let i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
function spaceOptimize(n){
    let dp=new Array(n+1).fill(0);
    dp[0]=dp[1]=1;
    for(let i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}