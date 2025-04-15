#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            --j;
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
    insertionSort(arr);
    cout<<"After Sorting : "<<endl;
    for(auto &ele:arr)
        cout<<ele<<" ";
    cout<<endl;
    return 0;
}
// https://www.geeksforgeeks.org/problems/insertion-sort/1