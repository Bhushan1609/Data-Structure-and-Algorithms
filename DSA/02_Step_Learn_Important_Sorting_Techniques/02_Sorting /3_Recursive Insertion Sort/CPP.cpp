//Problem Link : https://www.geeksforgeeks.org/problems/insertion-sort/1

#include<bits/stdc++.h>
using namespace std;

void recusive_insertion_sort(vector<int>&vec,int i){
    if(i>=vec.size())
        return ;
    
    int j=i;
    while(j>0 && vec[j]<vec[j-1]){
        swap(vec[j],vec[j-1]);
        j--;
    }
    recusive_insertion_sort(vec,i+1);
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

    recusive_insertion_sort(vec,0);

    cout<<"After Sorting : ";
    for(auto &i:vec)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}