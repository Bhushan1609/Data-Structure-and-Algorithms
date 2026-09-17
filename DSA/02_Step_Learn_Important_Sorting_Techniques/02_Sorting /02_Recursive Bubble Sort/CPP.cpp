//Problem Link : http://geeksforgeeks.org/problems/bubble-sort/1

#include<bits/stdc++.h>
using namespace std;

void recursive_bubble_sort(vector<int>&vec,int i){
    if(i<=0)
        return ;

    bool swapHappens=false;
    for(int j=0;j<i;j++){
        if(vec[j]>vec[j+1])
            swapHappens|=true,swap(vec[j],vec[j+1]);
    }
    if(!swapHappens)
        return ;     //allready sorted

    recursive_bubble_sort(vec,i-1);
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

    recursive_bubble_sort(vec,vec.size()-1);

    cout<<"After Sorting : ";
    for(auto &i:vec)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}