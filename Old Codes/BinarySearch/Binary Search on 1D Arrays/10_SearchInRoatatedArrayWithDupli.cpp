#include <bits/stdc++.h>
using namespace std;
bool calloptimal(vector<int>&v, int target) {
    int start = 0;
    int end = v.size()-1;
    while(start <= end){
        int mid = end - (end - start)/2;
        if(v[mid] == target) {
            return 1;
        }
        if(v[start] == v[mid] and v[mid] == v[end]){
            start++;
            end--;
            continue;
        }
        else if(v[start] <= v[mid]){
            if(v[start] <= target and target <= v[mid]){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        else{
            if(v[mid] <= target and target <= v[end]){
                start = mid + 1;
            }
            else{
                end = mid -1;
            }
        }
    }
    return 0;
}
int main(){
    vector <int> v = {3,3,1,3,3,3,3};
    int target = 3;
    if(calloptimal(v , target)) cout << "Present" << endl;
    else cout << "Absent" << endl;
    return 0;
}