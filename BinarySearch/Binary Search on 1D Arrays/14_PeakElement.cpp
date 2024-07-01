#include <bits/stdc++.h>
using namespace std;
int calloptimal(vector <int>& arr){
    int n = arr.size();
    if(n == 1) return 0;
    int start = 1;
    int end = n-2;
    while(start <= end){
        int mid = end - (end - start)/2;
        if(arr[mid-1] < arr[mid] and arr[mid] > arr[mid+1]){
            return mid;
        }
        else if(arr[mid] > arr[mid+1]){
            end = mid -1;
        }
        else{
            start = mid +1;
        }
    }
    if(arr[0] > arr[n-1]) return 0;
    return n-1;	
}
int main(){
    vector <int> v = {1,2,1};
    cout << (int) calloptimal(v) << endl;
    return 0;
}