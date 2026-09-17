//Problem Link : https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?interviewProblemRedirection=true&search=largest%20element%20in%20the%20array

#include<bits/stdc++.h>
using namespace std;

void callBrute(vector<int>&vec){
    vector<int>vec1=vec;
    int n=vec1.size();
    sort(vec1.begin(),vec1.end());
    cout<<vec1[n-1]<<endl;
    return ;
}

void callOptimal(vector<int>&vec){
    int largest=vec[0];
    int n=vec.size();
    for(int i=0;i<n;i++)
        largest=max(largest,vec[i]);
    cout<<largest<<endl;
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={3,2,1,5,2};

    callBrute(vec);
    callOptimal(vec);

    return 0;
}