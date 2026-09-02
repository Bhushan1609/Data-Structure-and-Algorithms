#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>&vec){
    int n=vec.size();
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i;j<n;j++){
            if(vec[j]<vec[minIndex])
                minIndex=j;
        }
        swap(vec[i],vec[minIndex]);
    }
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={13,46,24,52,20,9};

    cout<<"Before Sorting : ";
    for(auto &ele:vec)
        cout<<ele<<" ";
    cout<<endl;

    selection_sort(vec);

    cout<<"After Sorting : ";
    for(auto &ele:vec)
        cout<<ele<<" ";
    cout<<endl;
    return 0;
}

//Problem Link : https://www.geeksforgeeks.org/problems/selection-sort/1