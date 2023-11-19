#include <bits/stdc++.h>
using namespace std;
bool possible(vector <int>& arr , int div , int  threshold){
    int ans = 0;
    for (auto i : arr){
        ans = ans + ceil((double) i / (double)div);
    }
    return (ans <= threshold);
}
//O(n*n)
int callbrute(vector <int>& arr , int threshold){
    int maxi = *max_element(arr.begin() , arr.end());
    for (int i = 1 ; i <= maxi ; i++){
        if(possible(arr , i , threshold)){
            return i;
        }
    }
    return -1;
}
//O(n*logn)
int calloptimal(vector <int>& arr , int threshold){
    int start = 1;
    int end = *max_element(arr.begin() , arr.end());
    int ans = -1;
    while(start <= end){
        int mid = end - (end - start)/2;
        if(possible(arr , mid , threshold)){
            ans = mid;
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
    }    
    return ans ;
}
int main(){
    vector <int> arr = {1,2,5,9};
    int threshold = 6;
    cout << (int) callbrute(arr , threshold) << endl;
    cout << (int) calloptimal(arr ,threshold) << endl;
    return 0;
}