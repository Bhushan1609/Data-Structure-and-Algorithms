#include <bits/stdc++.h>
using namespace std;
#define ld  double
ld callbrute(vector <int> & arr , int k){
    vector <int> sectors(arr.size()-1 , 0);
    ld maxi = INT_MIN;
    while(k != 0){
        int index = -1;
        ld maxDist = -1;
        for (int i = 1 ; i < arr.size() ; i++){
            ld dist = (sectors[i-1]+1);
            ld diff = (arr[i] - arr[i-1]);
            if(diff/dist > maxDist){
                maxDist = diff/dist;
                index = i-1;
            }
        }
        sectors[index] += 1;
        k--;
    }
    for (int i = 1; i < arr.size() ; i++){
        ld dist = (sectors[i-1]+1);
        ld diff = (arr[i] - arr[i-1]);
        maxi = max(maxi , diff/dist);
    }
    return (ld) maxi;
} 
ld callbetter(vector <int> & arr , int k){
    vector <int> sectors(arr.size()-1 , 0);
    priority_queue<pair<ld,int>>pq;
    for (int i = 1 ; i < arr.size() ; i++){
        ld dist = (sectors[i-1]+1);
        ld diff = (arr[i] - arr[i-1]);
        pq.push({diff/dist , i});
    }
    ld maxi = INT_MIN;
    while(k != 0){
        pair <ld , int> top = pq.top();
        pq.pop();
        int index = top.second;
        sectors[index-1] += 1;
        ld dist = (sectors[index-1]+1);
        ld diff = (arr[index] - arr[index-1]);
        pq.push({diff/dist , index});
        k--;
    }
    return (ld) pq.top().first;
} 
int main(){
    vector <int> arr = {1,13,17,23};
    int k = 5;
    cout << (ld) callbrute(arr , k) << endl;
    cout << (ld) callbetter(arr , k) << endl;
    return 0;
}