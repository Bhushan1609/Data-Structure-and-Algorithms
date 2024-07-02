#include<bits/stdc++.h>
using namespace std;
bool check(int arr[] , int n){
    for (int i = 0 ; i < n-1 ; i++){
        if(arr[i] <= arr[i+1]) {
            continue;
        }
        else return false;
    }
    return true;
}
int main(){
    int arr[5] = {1 , 2 , 4, 5 , 7};
    if(check(arr , 5)) {
        cout << "YES" << endl; 
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
