#include <bits/stdc++.h>
using namespace std;
int possible(vector <int>& walls , int sumTill){
    int cnt = 1;
    int sum = 0;
    for (int i = 0 ; i < walls.size() ; i++){
        sum += walls[i];
        if(sum > sumTill){
            cnt++;
            sum = walls[i];
        }
    }
    return cnt ;
}
int callbrute(vector <int> & walls , int k){
    int start = *max_element(walls.begin() , walls.end() );
    int end = accumulate(walls.begin() , walls.end() , 0);
    for (int i = start ; i <= end ; i++){
        if(possible(walls , i) <= k) return i;
    }
    return -1;
}
int calloptimal(vector <int>& walls , int k){
    int start = *max_element(walls.begin() , walls.end() );
    int end = accumulate(walls.begin() , walls.end() , 0);
    while(start <= end){
        int mid = end - (end - start)/2;
        if(possible(walls , mid) > k){
            start= mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return start ;
}
int main(){
    vector <int> walls = {10,20,30,40};
    int k = 2;
    cout << callbrute(walls , k) << endl;
    cout << calloptimal(walls , k) << endl;
    return 0;
}