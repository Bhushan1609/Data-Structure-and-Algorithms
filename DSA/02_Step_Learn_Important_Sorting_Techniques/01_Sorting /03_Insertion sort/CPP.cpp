//Problem Link : https://www.geeksforgeeks.org/problems/insertion-sort/1

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>&vec){
    int n=vec.size();
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && vec[j]<vec[j-1]){
            swap(vec[j],vec[j-1]);
            j--;
        }
    }
    return ;
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

    insertion_sort(vec);

    cout<<"After Sorting : ";
    for(auto &i:vec)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}