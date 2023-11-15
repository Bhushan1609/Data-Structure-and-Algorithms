#include <bits/stdc++.h>
using namespace std;
void lowerBound(vector <int>& v , int target){
    int start = 0;
    int end = v.size() - 1;
    int ans = v.size(); // placing last index as ans
    while(start <= end){
        int mid = end - (end - start)/2;
        if(v[mid] >= target){
            ans = mid;
            end = mid-1;
        }
        else if(v[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    cout << "First index where {arr[index] >= target} is : "<< ans <<  endl;
    return ;
}
int main(){
    vector <int> v = {1,2,3,3,5,8,8,10,10,11};
    int target = 9;
    lowerBound(v , target); // the first index where {arr[index] >= target}
    //int index = lower_bound(v.begin() , v.end() , target) - v.begin();
    return 0;
}