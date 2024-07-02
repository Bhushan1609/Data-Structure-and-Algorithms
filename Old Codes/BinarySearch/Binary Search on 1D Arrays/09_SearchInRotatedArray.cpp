#include <bits/stdc++.h>
using namespace std;
//O(n)
void callbrute(vector <int>& v , int target){
    for (int i = 0 ; i < v.size() ; i++){
        if(target == v[i]){
            cout << "Found at the indedx : " << i << endl;
            return ;
        }
    }
    cout << "Element is not exist " << endl;
    return;
}
//O(logn)
void calloptimal(vector<int>& v , int target){
    int start = 0;
    int end = v.size()-1;
    while(start <= end){
        int mid = end - (end - start)/2;
        if(v[mid] == target) {
            cout << "Found at the indedx : " << mid << endl;
            return ;
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
    cout << "Element is not exist " << endl;
    return;
}
int main(){
    vector <int> v = {7,8,9,1,2,3,4,5,6};
    int target = 1;
    callbrute(v , target) ;
    calloptimal(v , target) ;
    return 0;
}