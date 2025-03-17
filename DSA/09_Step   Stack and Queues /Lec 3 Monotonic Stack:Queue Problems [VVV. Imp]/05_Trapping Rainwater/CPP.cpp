#include<bits/stdc++.h>
using namespace std;

//TC-O(2N)
//SC-O(2N)
int callBrute(vector<int>& height) {
    int n=height.size(),ans=0;
    vector<int>p(n),s(n);
    p[0]=height[0];
    s[n-1]=height[n-1];
    for(int i=0;i<n;i++){
        if(i)
            p[i]=max(height[i],p[i-1]);
        if(i!=n-1)
            s[n-i-2]=max(height[n-i-2],s[n-i-1]);
    }
    for(int i=0;i<n;i++){
        if(min(p[i],s[i])-height[i])
            ans+=min(p[i],s[i])-height[i];
    }
    return ans;
}

//TC-O(2N)
//SC-O(N)
int callBetter(vector<int>& height){
    int n=height.size(),ans=0;
    vector<int>s(n);
    int leftMax=height[0];
    s[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--)
        s[i]=max(height[i],s[i+1]);
    for(int i=0;i<n;i++){
        leftMax=max(leftMax,height[i]);
        if(min(leftMax,s[i])-height[i])
            ans+=min(leftMax,s[i])-height[i];
    }
    return ans;
}

//TC-O(N)
//SC-O(1)
int callOptimal(vector<int>& height) {
    int n=height.size();
    int ans=0;
    int left=0,right=n-1;
    int leftMax=0,rightMax=0;
    while(left<right){
        if(height[left]<height[right]){
            if(leftMax-height[left]>0)
                ans+=(leftMax-height[left]);
            leftMax=max(leftMax,height[left]);
            left++;
        }else{
            if(rightMax-height[right]>0)
                ans+=(rightMax-height[right]);
            rightMax=max(rightMax,height[right]);
            right--;
        }
    }
    return ans;
}

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<callBrute(height)<<endl;
    cout<<callBetter(height)<<endl;
    cout<<callOptimal(height)<<endl;
    return 0;
}   