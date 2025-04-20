#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int minIndex=i;
        int minValue=arr[i];
        for(int j=i+1;j<n;j++)
            if(minValue>arr[j])
                minIndex=j,minValue=arr[j];
        swap(arr[i],arr[minIndex]);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>arr={13,46,24,52,20,9};
    cout<<"Before Sorting : "<<endl;
    for(auto &i:arr)
        cout<<i<<" ";
    cout<<endl;

    selectionSort(arr);

    cout<<"After Sorting : "<<endl;
    for(auto &i:arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
//Problem Link : https://www.geeksforgeeks.org/problems/selection-sort/1