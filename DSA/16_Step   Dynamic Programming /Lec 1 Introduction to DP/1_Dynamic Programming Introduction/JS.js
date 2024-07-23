console.log(topDown(5));
console.log(bottomUp(5));
console.log(spaceOptimize(5));

function recursion(n,dpr){
    if(n<=1)return n;
    if(dpr[n] != -1)return dpr[n];
    return dpr[n]=(recursion(n-1,dpr) + recursion(n-2,dpr)) % 1000000007;
}
function topDown(n) {
    let dpr=new Array(n+1).fill(-1);
    return recursion(n,dpr);
}
function bottomUp(n) {
   let dp=new Array(n+1).fill(0);
    dp[1]=1;
    for(let i=2;i<=n;i++){
        dp[i]=(dp[i-1] + dp[i-2])%1000000007;
    }
    return dp[n];
}
function spaceOptimize(n) {
    let p1=0,p2=1,ans;
    for(let i=2;i<=n;i++){
        ans=(p1+p2)%1000000007;
        p1=p2;
        p2=ans;
    }
    return p2;
}