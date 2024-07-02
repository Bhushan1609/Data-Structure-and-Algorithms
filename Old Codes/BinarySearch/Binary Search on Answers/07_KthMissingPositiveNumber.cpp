#include <bits/stdc++.h>
using namespace std;
int callbrute(vector <int>arr , int k){
    for (auto i : arr){
        if(i <= k) k++;
        else return k;
    }
    return k;
}
 int calloptimal(vector <int>arr , int k){
    int start = 0 ;
    int end = arr.size() - 1;
    while(start <= end){
        int mid = end - (end - start)/2;
        if((arr[mid] - (mid + 1)) < k) {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return start + k ;
}
int main(){
    vector <int> arr = {2,3,4,7,11};
    int k = 5;
    cout << (int) callbrute(arr , k) << endl;
    cout << (int) calloptimal(arr , k) << endl;
    return 0;
}