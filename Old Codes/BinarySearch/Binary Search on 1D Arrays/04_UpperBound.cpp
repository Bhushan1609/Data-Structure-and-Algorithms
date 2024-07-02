#include <bits/stdc++.h>
using namespace std;
void upperBound(vector <int>& v , int target){
    int start = 0;
    int end = v.size() - 1;
    int ans = v.size(); // placing last index as ans
    while(start <= end){
        int mid = end - (end - start)/2;
        if(v[mid] > target){
            ans = mid;
            end = mid -1;             
        }
        else {
            start = mid + 1;
        }
    }
    cout << "First(smallest) index where {arr[index] > target} is : "<< ans <<  endl;
    return ;
}
int main(){
    vector <int> v = {2,3,6,7,8,8,11,11,11,12};
    int target =12;
    upperBound(v , target); // the first index where {arr[index] >= target}
    // cout <<  upper_bound(v.begin() , v.end() , target) - v.begin() << endl;
    return 0;
}