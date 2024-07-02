#include <bits/stdc++.h>
using  namespace std;
int main(){
    vector <vector <int>> arr = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24}
    };
    int target = 14;
    int n = arr.size();
    int m =arr[0].size();
    int row = 0 , col = m - 1;
    while(row < n and col >= 0){
        if(arr[row][col] == target){
            cout << "Found" << endl;
            return 0;
        }
        else if(arr[row][col] < target) row++;
        else col--;
    }
    cout << "NotFound" << endl;
    return 0;
}