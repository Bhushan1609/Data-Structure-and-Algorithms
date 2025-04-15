#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n=arr.size();
    for(int j=n-1;j>=1;j--){
        for(int i=1;i<=j;i++){
            if(arr[i]<arr[i-1])
                swap(arr[i],arr[i-1]);
        }
    }
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<int>arr={13,46,24,52,20,9};
    cout<<"Before Sorting : "<<endl;
    for(auto &ele:arr)
        cout<<ele<<" ";
    cout<<endl;
    bubbleSort(arr);
    cout<<"After Sorting : "<<endl;
    for(auto &ele:arr)
        cout<<ele<<" ";
    cout<<endl;
    return 0;
}
//Problem Link : https://www.geeksforgeeks.org/problems/bubble-sort/1