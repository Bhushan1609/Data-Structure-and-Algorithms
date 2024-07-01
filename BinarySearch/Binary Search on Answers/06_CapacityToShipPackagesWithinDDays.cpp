#include <bits/stdc++.h>
using namespace std;
bool possible(vector <int>& weights , int sum , int days){
    int cnt = 1;
    int psum = 0;
    for(auto i : weights){
        if(i > sum) return false;
        psum += i;
        if(psum > sum){
            psum = i;
            cnt++;
        }
    }
    return (cnt <= days);
}
int callbrute(vector <int>& weights , int days){
    int sum = 0;
    int maxi = INT_MIN;
    for (auto i : weights) {
        sum += i;
        maxi = max(maxi , i);
    }
    for (int i = maxi ; i <= sum ; i++){
        if(possible(weights , i , days)){
            return i;
        }
    }
    return -1;
}
int calloptimal(vector <int>& weights , int days){
    int start = *max_element(weights.begin() , weights.end());
    int end = accumulate(weights.begin() , weights.end() , 0);
    while(start <= end){
        int mid = end - (end - start)/2;
        if(possible(weights , mid , days)){
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
    }
    return start ;
}
int main(){
    vector<int >weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << (int) callbrute(weights , days) << endl;
    cout << (int) calloptimal(weights , days) << endl;
    return 0;
}