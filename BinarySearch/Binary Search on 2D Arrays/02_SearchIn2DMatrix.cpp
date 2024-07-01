#include <bits/stdc++.h>
using namespace std;
//O(n*m)
int callbrute(vector <vector <int>> arr ,int target){
    for (int i = 0 ; i  < arr.size() ; i++){
        for (int j = 0 ; j < arr[0].size() ; j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
} 
//O(n*log(m))
int callbetter(vector <vector<int>> arr , int target){
    for(int i = 0 ; i < arr.size() ; i++){
        int start = 0;
        int end = arr[0].size() - 1;
        while(start <= end){
            int mid = end - (end - start)/2;
            if(arr[i][mid] == target) return true;
            if(arr[i][mid]  > target){
                end = mid-1;
            }
            else start = mid + 1;
        }
    }
    return false;
}
//O(log(n*m))
int calloptimal(vector <vector<int>> arr , int target){
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;
    while(start <= end){
        int mid = end - (end - start)/2;
        if(arr[mid][0] < target){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid-1;
        }
    }
    if(ans == -1) return false;
    start = 0;
    end = arr[0].size() - 1;
    while(start <= end){
        int mid = end - (end - start)/2;
        if(arr[ans][mid] == target) return true;
        if(arr[ans][mid]  > target){
            end = mid-1;
        }
        else start = mid + 1;
    }
    return false;
}
bool calloptimal2(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
int main(){
    vector <vector <int>> arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    cout << callbrute(arr , 8) << endl;
    cout << callbetter(arr , 8) << endl;
    cout << calloptimal2(arr , 8) << endl;
    return 0;
}