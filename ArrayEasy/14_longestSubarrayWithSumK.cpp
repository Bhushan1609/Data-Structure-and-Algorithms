#include <bits/stdc++.h>
using namespace std;
//generating all subarray's
//O(n*n*n)
//O(1)
void callbrute(vector <int>v , int needSum){
   int n = v.size();
   int len = 0;
   for (int i = 0 ; i < n ; i++){
       for (int j = i ; j < n ; j++){
           int sum = 0;
           for (int k = i ; k <= j; k++) sum += v[k];
           if(sum == needSum) len = max(len , j-i+1);
       }
   }
   cout << "Maximum Length : " << len << endl;
   return ;
}


//O(n*n)
//O(1)
void callbrute1(vector <int>v , int needSum){
   int n = v.size();
   int len = 0;
   for (int i = 0 ; i < n ; i++){
       int sum = 0;
       for (int j = i ; j < n ; j++){
           sum += v[j];
           if(sum == needSum) len = max(len , j-i+1);
       }
   }
   cout << "Maximum Length : " << len << endl;
   return ;
}
//O(nlogn)
//O(n)
// this is optimal for negatives and zeros
void callbetter(vector <int>v , int needSum){
    int n = v.size();
    int sum = 0 ;
    int  len = 0;
    map<int  , int> mapp;
    for (int i = 0 ; i < n ; i++){
        sum += v[i];
        if(sum == needSum){
            len = max(len ,i+1);
        }
        int remaining = sum - needSum;
        if(mapp.find(remaining) != mapp.end()){
            len = max(len , i - mapp[remaining]);
        }
       if(mapp.find(sum) == mapp.end()){
            mapp[sum] = i;
        }
    }
    cout << "Maximum Length : " << len << endl;
   return ;
}
//O(2n)
//O(1)
void calloptimal(vector<int>& v , int needSum){
    int n = v.size();
    int sum = v[0];
    int left , right ;
    left = right = 0;
    int len = 0;
    while(right < n){
        while(left <= right and sum > needSum){
            sum -= v[left];
            left++;
        }
        if(sum == needSum) {
            len = max(len , right - left + 1);
        }
        right++;
        if(right < n) sum += v[right];
    }
    cout << "Maximum Length : " << len << endl;
    return ;
}
int main(){
    vector <int> v = {1,2,3,1,1,1,4,2,3};
    int needSum = 3;
    callbrute(v , needSum);
    callbrute1(v , needSum);
    callbetter(v , needSum);
    calloptimal(v , needSum);
    return 0;
}