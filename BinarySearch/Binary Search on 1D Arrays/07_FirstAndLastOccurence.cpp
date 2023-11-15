#include <bits/stdc++.h>
using namespace std;
//O(n)
//O(1)
void callbrute(vector <int>& v , int target){
    int n = v.size();
    int first , last;
    first = last = -1;
    for(int i = 0 ; i < n ; i++){
        if(v[i] == target){
            if(first == -1){
                first = i;
            }
            else{
                last = i;
            }
        }
    }
    cout << "First Ocuurence is : " << first << " Last Occurence is : " << last << endl;
    return ;
}
pair<int, int> calloptimal(vector<int>& arr, int k){
    int lb = lower_bound(arr.begin() , arr.end() , k) - arr.begin();
    int ub = upper_bound(arr.begin() , arr.end() , k) - arr.begin();
    if(lb == arr.size() or arr[lb] != k){
      return {-1, -1};
    } else {
      return {lb, ub - 1};
    }
}
//normal binary search

pair<int ,int> normibinarysearch(vector <int>& arr ,int k){
    int first = -1;
    int last  = -1;
    int start = 0;
    int end = arr.size() - 1;
    // finding first occurence
    while(start <= end){
      int mid = end - (end - start)/2;
      if(arr[mid] == target){
        first = mid;
        end = mid - 1;
      }
      else if(arr[mid] < target){
        start = mid + 1;
      }
      else{
        end = mid -1;
      }
    }
    start = 0;
    end = arr.size() - 1;
    // second Occurence
    while(start <= end){
      int mid = end - (end - start)/2;
      if(arr[mid] == target){
        last = mid;
        start = mid + 1;
      }
      else if(arr[mid] < target){
        start = mid + 1;
      }
      else{
        end = mid -1;
      }
    }
    return {first , last};
}
int main(){
    vector <int> v = {2,4,6,8,8,8,11,13};
    int target = 8;
    callbrute(v , target);
    pair<int , int> ans  = calloptimal(v , target);
    return 0;
}