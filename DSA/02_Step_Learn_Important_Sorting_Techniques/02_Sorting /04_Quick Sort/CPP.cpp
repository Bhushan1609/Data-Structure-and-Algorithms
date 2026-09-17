//Problem Link : https://www.geeksforgeeks.org/problems/quick-sort/1

#include<bits/stdc++.h>
using namespace std;

int pivotPlaceFunction(int low,int high,vector<int>&vec){
    int pivot=vec[low];
    int i=low,j=high;
    while(i<j){
        while(vec[i]<=pivot && i<=high) i++;
        while(vec[j]>pivot && j>=low) j--;

        if(i<j)
            swap(vec[i],vec[j]);
    }
    swap(vec[low],vec[j]);
    return j;
}

void qs(int low,int high,vector<int>&vec){
    if(low>=high)
        return;
    int partitionIndex=pivotPlaceFunction(low,high,vec);
    qs(low,partitionIndex-1,vec);
    qs(partitionIndex+1,high,vec);

}

void quick_sort(vector<int>&vec){
    qs(0,vec.size()-1,vec);
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

    quick_sort(vec);

    cout<<"After Sorting : ";
    for(auto &i:vec)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}