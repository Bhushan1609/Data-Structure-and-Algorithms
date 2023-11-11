
#include <bits/stdc++.h>
using namespace std;
//O(n*n*n)
void callbrute(vector <int>v, int target) {
    int n = v.size();
    int cnt = 0; 
    for (int i = 0 ; i < n; i++) { 
        for (int j = i; j < n; j++) { 
            int sum = 0;
            for (int k = i; k <= j; k++){
                sum += v[k];
            }
            if(sum == target) cnt++;
        }
    }
    cout << "The number of subarrays is: " << cnt << "\n";
    return ;
}
//O(n*n)
void callbetter(vector < int > & v, int target) {
    int n = v.size(); 
    int cnt = 0; 
    for (int i = 0 ; i < n; i++) { 
        int sum = 0;arr
        for (int j = i; j < n; j++) { 
            sum += v[j];
            if (sum == target) cnt++;
        }
    }
    cout << "The number of subarrays is: " << cnt << "\n";
    return ;
}
//O(nlogn)
//O(n)
void calloptimal(vector<int>v, int target) {
    int n = v.size(); 
    map<int,int> mpp;
    int preSum = 0, cnt = 0;
    mpp[0] = 1; 
    for (int i = 0; i < n; i++) {
        preSum += v[i];
        int remove = preSum - target;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    cout << "The number of subarrays is: " << cnt << "\n";
    return ;
}
int main()
{
    vector <int> v = {3, 1, 2, 4};
    int target = 6;
    callbrute(v, target);
    callbetter(v,target);
    calloptimal(v,target);
    return 0;
}

