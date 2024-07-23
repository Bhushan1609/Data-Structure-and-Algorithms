let nums=[1,2,3,1];
let dp=new Array(nums.length+1).fill(-1);
console.log(topDown(nums.length-1,nums,dp));
console.log(BottomUp(nums));
console.log(spaceOptimize(nums));
function topDown(index,nums,dp){
    if(index<=0)return (index == 0) ? nums[0] : 0;
    if(dp[index] != -1)return dp[index];
    let ntake=topDown(index-1,nums,dp);
    let take=nums[index] + topDown(index-2,nums,dp);
    return dp[index] = Math.max(ntake,take);
}
function BottomUp(nums){
    let dp=new Array(nums.length+1).fill(0);
        dp[0]=nums[0];
        for(let index=1;index<nums.length;index++){
            dp[index] = Math.max(dp[index-1],(index>=2) ? (nums[index]+dp[index-2]) : nums[index]);
        }
        return dp[nums.length-1];
}
function spaceOptimize(nums){
    if(nums.length == 1)return nums[0];
    let prev=nums[0];
    let prev2=nums[1];
    for(let index=1;index<nums.length;index++){
        let curr = Math.max(prev,(index>=2) ? (nums[index]+prev2) : prev2);
        prev2=prev;
        prev=curr;
    }
    return prev;
}