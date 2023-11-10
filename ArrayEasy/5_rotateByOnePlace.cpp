#include <bits/stdc++.h>
using namespace  std;
void rotate(vector <int>& arr){
    int temp = arr[0];
    int n = arr.size();
    for(int i = 1 ; i < n ; i++){
        swap(arr[i] , arr[i-1]);
    }
    arr[n-1] = temp; 
}
int main(){
    vector <int> arr;
    arr.push_back(1); 
    arr.push_back(2); 
    arr.push_back(3); 
    arr.push_back(4); 
    arr.push_back(5); 
    for (int i= 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    rotate(arr);
    for (int i = 0 ; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}