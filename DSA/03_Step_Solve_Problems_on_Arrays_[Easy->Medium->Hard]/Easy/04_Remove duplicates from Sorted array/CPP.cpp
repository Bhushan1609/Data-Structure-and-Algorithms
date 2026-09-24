//Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include<bits/stdc++.h>
#include<set> 
using namespace std;

int callBrute(vector<int>vec){
    int n=vec.size(); 
    set<int>st;
    for(auto i:vec)
        st.insert(i);  
    int index=0; 
    for(auto &i:st)
        vec[index++]=i;
    return index;
}

int callOptimal(vector<int>vec){
    int n=vec.size();
    int i=0;
    for(int j=1;j<n;j++){
        if(vec[i]!=vec[j]){
            vec[i+1]=vec[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={1,1,2,2,2,3,3};

    cout<<callBrute(vec)<<endl;
    cout<<callOptimal(vec)<<endl; 
    return 0;
}
