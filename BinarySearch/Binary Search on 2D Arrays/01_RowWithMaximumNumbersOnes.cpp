#include <bits/stdc++.h>
using namespace std;
//O(n*m)
int callbrute(vector <vector <int>> arr ){
    int index = -1;
    int counter = -1;
    for (int i = 0 ; i  < arr.size() ; i++){
        int count = -1;
        for (int j = 0 ; j < arr[0].size() ; j++){
            if(arr[i][j] == 1){
                count++;
            }
        }
        if(count > counter){
            counter = count ;
            index = i;
        }
    }
    return index;
} 
int calloptimal(vector <vector<int>> arr){
    int index = -1;
    int counter = -1;
    for(int i = 0 ; i < arr.size() ; i++){
        int start = 0;
        int end = arr[0].size() - 1;
        int ans = -1;
        while(start <= end){
            int mid = end - (end - start)/2;
            if(arr[i][mid] == 1){
                ans = mid;
                end = mid-1;
            }
            else start = mid + 1;
        }
        if(ans != -1){
            int countZeros = arr[0].size() - ans ;
            if(countZeros > counter){
                counter = (arr[0].size() - ans);
                index = i;
            }
        }
    }
    return index;
}
int main(){
    vector <vector <int>> arr = {
        {0,0,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1}
    };
    cout << callbrute(arr) << endl;
    cout << calloptimal(arr) << endl;
    return 0;
}