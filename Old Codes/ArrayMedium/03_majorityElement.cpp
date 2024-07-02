#include <bits/stdc++.h>
using namespace std;
//O(n*n)
void callbrute(vector <int> v){
    int n = v.size() ; 
    for (int i =0  ; i < n ; i++){
        int cnt = 0;
        for (int j = 0 ; j < n ;j++){
            if(v[j] == v[i]) cnt++;
        }
        if(cnt > n/2){
            cout << "Majority Element is : " << v[i] << endl;
            return ;
        }
    }
    cout << "-1" << endl;
    return ;
}
//O(nlogn)
void callbetter(vector <int>v){
    map<int , int>mapp;
    int n = v.size();
    for (int i = 0 ; i < n ; i++){
        mapp[v[i]]++;
    }
    for (auto i : mapp){
        if(i.second > n/2){
            cout << "Majority Element is : " << i.first << endl;
            return ;
        }
    }
    cout << "-1" << endl;
    return ;
}
//    Moore's Vorting Algorithm
void calloptimal(vector <int>v){
    int n = v.size() ;
    int cnt = 0;
    int ele = v[0];
    for (int i = 1 ; i < n ; i++){
        if(cnt == 0) {
            ele = v[i];
            cnt = 1;
        }
        else if(v[i] == ele) cnt++;
        else cnt--;
    }
    cnt = 0;
    // Till complexity --> O(n)
    //Problem State's always exits majority element so , no need to check again..
    for (int i = 0 ; i < n ; i++){
        if(v[i] == ele) cnt++;
    }
    // for checking this O(n)
    if(cnt > n/2)
        cout << "Majority Element is : " << ele << endl;
        return ;
    cout << "-1" << endl;
    return ;
}
//O(2n)
int main(){
    vector <int> v = {2,2,3,3,1,2,2};
    callbrute(v);
    callbetter(v);
    calloptimal(v);
    return 0;
}