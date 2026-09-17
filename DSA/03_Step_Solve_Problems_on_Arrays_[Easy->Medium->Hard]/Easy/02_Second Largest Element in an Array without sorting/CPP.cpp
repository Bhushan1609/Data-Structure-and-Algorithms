//Problem Link : https://www.naukri.com/code360/problems/second-largest-number_13762781?interviewProblemRedirection=true&search=second%20largest

#include<bits/stdc++.h>
using namespace std;

void callBrute(vector<int>&vec){
    vector<int>vec1=vec;
    int n=vec1.size();
    sort(vec1.begin(),vec1.end());
    int largest=vec1[n-1],second_large=-1;
    for(int i=n-2;i>=0;i--){
        if(vec1[i]!=largest){
            second_large=vec1[i];
            break;
        }
    }
    cout<<second_large<<endl;
    return ;
}

void callBetter(vector<int>&vec){
    int largest=vec[0],second_large=INT_MIN,n=vec.size();
    for(int i=0;i<n;i++)
        largest=max(largest,vec[i]);
    for(int i=0;i<n;i++)
        if(vec[i]>second_large && vec[i]!=largest)
            second_large=vec[i];
    second_large=(second_large==INT_MIN?-1:second_large);
    cout<<second_large<<endl;
    return;
}

void callOptimal(vector<int>&vec){
    int n=vec.size(),largest=vec[0],second_large=INT_MIN;
    for(int i=0;i<n;i++){
        if(vec[i]>largest){
            second_large=largest;
            largest=vec[i];
        }else if(vec[i]>second_large && vec[i]<largest){
            second_large=vec[i];
        }
    }
    second_large=(second_large==INT_MIN?-1:second_large);
    cout<<second_large<<endl;
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={1,2,4,7,7,5};

    callBrute(vec);
    callBetter(vec);
    callOptimal(vec);

    return 0;
}