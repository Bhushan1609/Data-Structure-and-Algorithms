//Problem Link : https://www.geeksforgeeks.org/problems/merge-sort/1

#include<bits/stdc++.h>
using namespace std;

void merge(int low,int mid,int high,vector<int>&vec){
    int left=low;
    int right=mid+1;
    vector<int>temp;

    while(left<=mid && right<=high){
        if(vec[left]<=vec[right]){
            temp.push_back(vec[left]);
            left++;
        }else{
            temp.push_back(vec[right]);
            right++;
        }
    }

    while(left<=mid)
        temp.push_back(vec[left++]);

    while(right<=high)
        temp.push_back(vec[right++]);

    for(int i=low;i<=high;i++)
        vec[i]=temp[i-low];

    return;
}

void divide(int low,int high,vector<int>&vec){
    if(low>=high)
        return ;
    int mid=(low+high)>>1;
    divide(low,mid,vec);
    divide(mid+1,high,vec);
    merge(low,mid,high,vec);
}

void merge_sort(vector<int>&vec){
    int n=vec.size();
    divide(0,n-1,vec);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>vec={13,46,24,52,20,9};

    cout<<"Before Sorting : ";
    for(auto &i:vec)
        cout<<i<<" ";
    cout<<endl;

    merge_sort(vec);

    cout<<"After Sorting : ";
    for(auto &i:vec)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}