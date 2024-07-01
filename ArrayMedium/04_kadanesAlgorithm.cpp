#include <bits/stdc++.h>
using namespace std;
// O(n*n*n)
void callbrute(vector <int> v){
    int n = v.size();
    int addsum = INT_MIN;
    // generate all subarray's 
    for (int i = 0 ; i < n ; i++){
        for (int j = i ;j < n ; j++){
            int sum = 0;
            for (int k = i ; k <= j ; k++) {
                sum += v[k];
                addsum = max(addsum , sum);
            }
        }
    }
    cout << "Maximum sum is : " << addsum << endl;
    return ;
}
//O(n*n)
void callbetter(vector <int>v){
    int n = v.size();
    int addsum = INT_MIN;
    for (int i = 0 ; i < n ; i++){
        int sum = 0;
        for (int j = i ; j < n ; j++){
            sum += v[j];
            addsum = max(addsum , sum);
        }
    }
    cout << "Maximum sum is : " << addsum << endl;
    return ;
}
// kadane's Algorithm
void calloptimal(vector <int>v){
    int n = v.size();
    int addsum = INT_MIN;
    int startIndex , endIndex ,start;
    start = startIndex = endIndex = -1;
    int sum = 0;
    for (int i = 0 ; i < n ; i++){
        if(sum == 0){
            start = i;
        }
        sum += v[i];
        if(sum > addsum){
            addsum = sum;
            startIndex = start ;
            endIndex = i;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    cout << "Maximum sum is : " << addsum << endl;
    //{Printing the array with maximum sum}
    for (int i = startIndex ; i <= endIndex ; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return ;
}
int main(){
    vector <int> v = {-2,-3,4,-1,-2,1,5,-3};
    callbrute(v);
    callbetter(v);
    calloptimal(v);
    return 0;
}