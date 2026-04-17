#include<bits/stdc++.h>
using namespace std;

void merge(int start,int mid,int end,vector<int>&arr){
    int i=start,j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid)
        temp.push_back(arr[i++]);
    while(j<=end)
        temp.push_back(arr[j++]);

    for(int i=start;i<=end;i++)
        arr[i]=temp[i-start];
    
    return ;
}

void divide(int start,int end,vector<int>&arr){
    if(start>=end)
        return;
    int mid=(start+end)>>1;
    divide(start,mid,arr);
    divide(mid+1,end,arr);
    merge(start,mid,end,arr);
}

void mergeSort(vector<int>&arr){
    int n=arr.size();
    return divide(0,n-1,arr);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>arr={13,46,24,52,20,9};
    cout<<"Before Sorting : ";
    for(auto &i:arr)
        cout<<i<<" ";
    cout<<endl;

    mergeSort(arr);

    cout<<"After Sorting  : ";
    for(auto &i:arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
//Problem Link : https://www.geeksforgeeks.org/problems/merge-sort/1