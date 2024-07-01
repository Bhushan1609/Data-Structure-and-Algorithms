#include <bits/stdc++.h>
using namespace std;
int calloptimal(vector<int> &arr){
    int start = 0;
    int end = arr.size() -1 ;
    int minIndex = -1;
    int mini = 1e9;
    while(start <= end){
        int mid = end - (end - start)/2;
        if(arr[start] <= arr[end]){
            if(mini > arr[start]){
                mini = arr[start];
                minIndex = start;
            }
            break;
        }

        if(arr[start] <= arr[mid]){
            if(mini > arr[start]){
                mini = arr[start];
                minIndex = start;
            }
            start = mid + 1;
        }
        else{
            if(mini > arr[mid]){
                minIndex = mid;
                mini = arr[mid];
            }
            end = mid - 1;
        }
    }    
    return  minIndex;
}
int main(){
    vector <int> v = {5 , 6 , 7 , 1 ,2,3};
    cout << (int) calloptimal(v) << endl;
    return 0;
}