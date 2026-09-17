//Problem Link : https://www.naukri.com/code360/problems/ninja-and-the-sorted-check_6581957

#include<bits/stdc++.h>
using namespace std;


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={1,2,2,3,3,4};

    int n=vec.size();
    bool sorted=true;
    for(int i=1;i<n;i++){
        if(vec[i]<vec[i-1])
            sorted=false;
    }
    if(!sorted)
        cout<<"Array is not Sorted"<<endl;
    else
        cout<<"Array is Sorted"<<endl;
    return 0;
}