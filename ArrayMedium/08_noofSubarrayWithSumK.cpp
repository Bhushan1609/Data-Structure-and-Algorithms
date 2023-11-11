#include <bits/stdc++.h>
using namespace std;
// O(n*n*n)
// O(1)
void callbrute(vector <int>v , int target){
    int cnt = 0;
    int n = v.size() ; 
    for (int i = 0 ; i < n ; i++){
        for (int j = i ; j < n ; j++){
            int sum = 0;
            for (int k = i ; k <= j ; k++) sum += v[k];
            if(sum == target) cnt++;
        }
    }
    cout << "No of Subarray to sum up target  is : " << cnt << endl;
    return ;
}
// O(n*n)
// O(1)
void callbetter(vector  <int>v , int target){
    int n = v.size();
    int cnt = 0;
    for (int i = 0; i < n ; i++){
        int sum = 0;
        for (int j = i ; j < n ; j++){
            sum += v[j];
            if(sum == target) cnt++;
        }
    }
    cout << "No of Subarray to sum up target  is : " << cnt << endl;
    return ;
}
// O(nlog n)
// O(n)
void calloptimal(vector <int>v ,  int target){
    int n = v.size();
    int cnt = 0;
    int preSum = 0;
    map <int , int> sum_Cnt ;
    //edge case
    sum_Cnt[0] = 1;
    for (int i = 0;  i < n ; i++){
        preSum+= v[i];
        int needSum = preSum - target;
        cnt += sum_Cnt[needSum];
        sum_Cnt[preSum]++;
    }
    cout << "No of Subarray to sum up target  is : " << cnt << endl;
    return ;
}
int main(){
    vector <int> v= {1,2,3,-3,1,1,1,4,2,-3};
    int target = 3;
    callbrute(v , target);
    callbetter(v , target);
    calloptimal(v , target);
    return 0;
}