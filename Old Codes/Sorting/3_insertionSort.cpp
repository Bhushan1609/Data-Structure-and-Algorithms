#include <bits/stdc++.h>
using namespace std;
void printarr(int arr[]){
    for (int i = 0 ; i < 6 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return ;
}
void insertionSort(int arr[] , int n){
    for (int i = 0 ; i < n ; i++){
        int j = i;
        while(j > 0 and arr[j-1] > arr[j]){
            swap(arr[j-1] , arr[j]);
            j--;
        }
    }
    return ;
}
int main(){
    int arr[6] = {13 , 46 , 24 , 52 , 20 , 9};
    printarr(arr);
    insertionSort(arr , 6);
    printarr(arr);
    return 0;
}
