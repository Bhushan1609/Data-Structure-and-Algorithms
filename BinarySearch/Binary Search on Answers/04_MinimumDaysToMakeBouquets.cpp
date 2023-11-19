#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int>& bloomday , int day , int m , int k){
    int cnt= 0;
    int req = 0;
    for (auto i : bloomday){
        if(i <= day) cnt++;
        else{
            req += (cnt/k);
            cnt = 0;
        }
    }
    req += (cnt/k);
    return (req >= m);
}
//O((maxi - mini + 1) * n )
void callbrute(vector <int>&bloomday ,int m ,int k){
    if(m*k > bloomday.size()) {
        cout << -1 << endl;
        return ;
    }
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (auto i : bloomday){
        mini = min(mini , i);
        maxi = max(maxi , i);
    }
    for (int i = mini ; i <= maxi ; i++){
        if(possible(bloomday , i , m , k)){
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
    return ;
}
// O(log(maxi - mini + 1) * n)
int calloptimal(vector <int>&bloomday ,int m ,int k){
        if((long long)m*k > (long long)bloomday.size()) {
            return -1;
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (auto i : bloomday){
            mini = min(mini , i);
            maxi = max(maxi , i);
        }
        int start = mini;
        int end = maxi;
        int ans = -1;
        while(start <= end){
            int mid = end - (end - start)/2;
            if(possible(bloomday , mid , m , k)){
                ans = mid;
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
int main(){
    vector <int> bloomday = {7,7,7,13,11,12,7};
    int m = 2; //no of bouquets
    int k = 3; //adjacent flower required
    callbrute(bloomday , m , k);
    cout << (int) calloptimal(bloomday , m , k) << endl;
    return 0;
}