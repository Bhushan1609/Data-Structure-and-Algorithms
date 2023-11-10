// given sorted array
//removeDuplicate and push in the array return lenght of the array
#include <bits/stdc++.h>
using namespace std;
// O(log(n) + n) time
// O(n) space
int callbrute(int arr[] , int n){
    unordered_set<int> st;
    for (int i = 0; i < n ; i++){
        st.insert(arr[i]);
    }
    int index = 0;
    for (auto i : st){
        arr[index] = i;
        index++;
    }
    return index;
}
// O(n) time
// O(1) space
int calloptimal(int arr[] , int n){
    int index = 0;
    for (int j = 1; j < n ; j++){
        if(arr[index] != arr[j]){
            index++;
            arr[index] = arr[j];
        }
    }
    return index+1;
}
int main(){
    int arr[7] = {1,1,2,2,2,3,3};
    int n = 7;
    int ans = callbrute(arr , n);
    cout << ans << endl;
    int arr1[7] = {1,1,2,2,2,3,3};
    ans = calloptimal(arr1 , n);
    cout << ans << endl;
    return 0;
}
