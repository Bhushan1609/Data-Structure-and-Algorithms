#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        bool swapHappens=false;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapHappens|=true;
            }
        }
        if(!swapHappens)
            break;//bcoz already sorted
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
    for(auto &i:arr)
        cout<<i<<" ";
    cout<<endl;

    bubbleSort(arr);

    cout<<"After Sorting : "<<endl;
    for(auto &i:arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
//Problem Link : http://geeksforgeeks.org/problems/bubble-sort/1