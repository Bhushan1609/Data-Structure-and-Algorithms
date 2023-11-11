#include <bits/stdc++.h>
using namespace std;
// O(n*n)
// O(1)
void callbrute(vector <int>v ){
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if (sum == 0) { 
            maxLen = i + 1;
        } 
        else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        } 
        else {
            sumIndexMap[sum] = i;
        }
    }
    cout << "Maximum Legth is : " << maxLen << endl;
    cout << endl;
    return ;
}
//O(n)
//O(n)
void calloptimal(vector<int>v ){
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<v.size();i++) {
        sum += v[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }
    cout << "Maximum Legth is : " << maxi << endl;
    return ;
}

int main(){
    vector <int> v = {9, -3, 3, -1, 6, -5};
    callbrute(v );
    calloptimal(v );
    return 0;
}
