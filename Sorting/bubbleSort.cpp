#include <bits/stdc++.h>
using namespace std;
void printarr(int arr[]){
    for (int i = 0 ; i < 6 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return ;
}
void bubbleSort(int arr[] , int n){
    int swapHappen = 0;
    for (int i = n-1 ; i >= 0 ; i--){
        for (int j = 0 ; j < i ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                swapHappen = 1;
            }
        }
        cout << "runs" << endl;
        if(!swapHappen){
            return ;
        }
    }
    return ;
}
int main(){
    // int arr[6] = {13 , 46 , 24 , 52 , 20 , 9};
    int arr[6] = {1 , 2 , 3 , 4 , 5 , 6};

    printarr(arr);
    bubbleSort(arr , 6);
    printarr(arr);
    return 0;
}