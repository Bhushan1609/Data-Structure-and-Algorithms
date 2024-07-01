
#include <bits/stdc++.h>
using namespace std;
pair<int, int> getFloorAndCeil(vector<int> &a, int x) {
    int index= lower_bound(a.begin() , a.end() , x) - a.begin();
    int index2 = -1;
    int start = 0 ; 
    int end = a.size() -1;
    while(start <= end){
        int mid = end - (end - start) / 2;
        if(a[mid] <= x){ // cond^n for floor 
            index2 = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    int ans1 = a[index2];
    int ans2 = a[index];
    ans1 = (a[0] > x) ? -1 : ans1;
    ans2 = (a[index] < x) ? -1 : ans2;
    return {ans1 , ans2};
}
int main(){
    vector <int> v = {3 ,4 ,4 ,7, 8, 10};
    int target = 8;
    pair <int , int> ans = getFloorAndCeil(v , target);
    cout << "Floor : " <<ans.first << " " << "Ceil : " << ans.second << endl;
    return 0;
}