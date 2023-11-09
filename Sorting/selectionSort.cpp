#include <bits/stdc++.h>
using namespace std;
void printarr(int arr[]){
    for (int i = 0 ; i < 6 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return ;
}
void selectionSort(int arr[] , int n){
    for (int i = 0 ; i < n-1 ; i++){
        int minIndex = i;
        for (int j = i ; j < n ; j++){
            if(arr[minIndex] > arr[j]) minIndex = j;
        }
        swap(arr[i] , arr[minIndex]);
    }
    return ;
}
int main(){
    int arr[6] = {13 , 46 , 24 , 52 , 20 , 9};
    printarr(arr);
    selectionSort(arr , 6);
    printarr(arr);
    return 0;
}