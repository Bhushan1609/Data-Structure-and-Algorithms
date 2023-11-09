#include <bits/stdc++.h>
using namespace std;
int partition(int (&arr)[8] , int low , int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(i < high and arr[i] <= pivot) i++;
        while(j >= low+1 and arr[j] > pivot) j--;
        if(i<j) swap(arr[i] , arr[j]);
    }
    swap(arr[low] , arr[j]);
    return j;
}
void quickSort(int (&arr)[8] , int low , int high){
    if(low < high){
        int partitionIndex = partition(arr , low , high);
        quickSort(arr , low , partitionIndex-1);
        quickSort(arr , partitionIndex+1 , high);
    }
}
void printarr(int arr[]){
    for (int i = 0 ; i < 8 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return ;
}
int main(){
    int arr[8] = {4,6,2,5,7,9,1,3};
    printarr(arr);
    quickSort(arr , 0 , 8-1);
    printarr(arr);
    return 0;
}