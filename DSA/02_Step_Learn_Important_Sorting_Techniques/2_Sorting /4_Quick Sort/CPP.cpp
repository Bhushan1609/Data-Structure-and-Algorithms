#include<bits/stdc++.h>
using namespace std;

int f(int low,int high,vector<int>&arr){
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j){
        while(i<high && arr[i]<=pivot)
            i++;

        while(j>low && arr[j]>pivot)
            j--;

        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}


void quickSort(int low,int high,vector<int>&arr){
    if(low<high){
        int partitionIndex=f(low,high,arr);
        quickSort(low,partitionIndex-1,arr);
        quickSort(partitionIndex+1,high,arr);
    }
    return ;
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

    quickSort(0,arr.size()-1,arr);

    cout<<"After Sorting  : ";
    for(auto &i:arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
//Problem Link : https://www.geeksforgeeks.org/problems/quick-sort/1