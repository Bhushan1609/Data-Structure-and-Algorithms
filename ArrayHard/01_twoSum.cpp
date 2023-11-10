#include <bits/stdc++.h>
using namespace std;
//O(n*n)
//O(1)
void callbrute(vector <int> v , int target){
    int n = v.size();
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if(i != j){
                if((v[i] + v[j]) == target){
                    cout << "YES" << endl;
                    cout << "Numbers are at Indexex: " << min(i,j) << " " << max(i,j) << endl;
                    return ;
                }
            }
        }
    }
    cout << "-1" << endl;
    return ;
}
//O(n*logn)
//O(n)
void callbetter(vector <int> v , int target){
    int n = v.size();
    map<int ,int>mapp;
    for (int i = 0 ; i < n ; i++){
        int exist = target - v[i];
        if(mapp.find(exist) != mapp.end()){
            cout << "YES" << endl;
            cout << "Numbers are at Indexex: " << min(i,mapp[exist]) << " " << max(i,mapp[exist]) << endl;
            return;
        } 
        else{
            mapp[v[i]] = i;
        }
    }
    cout << "-1" << endl;
    return ;
}
// O(n) + O(nlogn)
//O(1)
void calloptimal(vector <int> v , int target){
    int n = v.size();
    sort(v.begin() , v.end());
    int left = 0 , right = n - 1;
    while(left < right){
        int sum = v[left] + v[right];
        if(target == sum ){
            cout << "YES" << endl;
            return ;
        }
        else if(sum < target) left++;
        else right--;
    }
    cout << "-1" << endl;
    return ;
}
int main(){
    vector <int> v= {2,6,5,8,11};
    int target = 14;
    callbrute(v , target);
    callbetter(v,target);
    calloptimal(v,target);
    return 0;
}