#include<bits/stdc++.h>
using namespace std;
//O(nlogn)
int bruteForce(int arr[] , int n){
    sort(arr , arr+n);
    int end = n-1;
    int endd = n-2;
    while(arr[end] == arr[endd]){
        endd--;
    }
    return arr[endd];
}
//O(2n)
int better(int arr[] , int n){
    int firstLarge = INT_MIN;
    int secondLarge = INT_MIN;
    for (int i =0 ; i < n ; i++){
        if(arr[i] > firstLarge) firstLarge = arr[i];
    }
    for (int i =0 ; i < n ; i++){
        if(arr[i] > secondLarge and arr[i] != firstLarge) secondLarge = arr[i];
    }
    return secondLarge;
}
//O(n)
int optimal(int arr[],int n){
    int firstLarge=INT_MIN,secondLarge=INT_MIN;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] > firstLarge){
            secondLarge = firstLarge;
            firstLarge = arr[i];
        }
        else if (arr[i] > secondLarge && arr[i] != firstLarge){
            secondLarge = arr[i];
        }
    }
    return secondLarge;                
}
int main(){
    int arr[6] = {1,2,4,7,7,5};
    int ans = bruteForce(arr  , 6);
    cout << ans << endl;
    int arr1[6] = {1,2,4,7,7,5};
    ans = better(arr1  , 6);
    cout << ans << endl;
    int arr2[6] = {1,2,4,7,7,5};
    ans = optimal(arr  , 6);
    cout << ans << endl;
    return 0;
}