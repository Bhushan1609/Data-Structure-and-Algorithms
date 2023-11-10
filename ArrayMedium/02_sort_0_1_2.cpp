#include <bits/stdc++.h>
using namespace std;
//O(nlogn)
void callbrute(vector <int> v){
    sort(v.begin() , v.end());
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
//O(2n)
//O(1)
void callbetter(vector <int> v1){
    int n = v1.size();
    int zero = 0 , one = 0 , two = 0;
    for (auto i : v1){
        if(i == 0) zero++;
        else if(i == 1) one++;
        else if(i == 2) two++;
    }
    int index = 0;
    while(zero--){
        v1[++index] = 0;
    }
    while(one--){
        v1[index++] = 1;
    }
    while(two--){
        v1[index++] = 2;
    }
    for (auto i : v1){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
//O(n)
//constant
void calloptimal(vector <int>v){
    int n = v.size();
    int low  = 0 , mid = 0  , high  = n -1;
    while(mid <= high){
        if(!v[mid]){
            swap(v[low] , v[mid]);
            low++;
            mid++;
        }
        else if(v[mid] == 1){
            mid++;
        }
        else {
            swap(v[mid] , v[high]);
            high--;
        }
    }
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
int main(){
    vector <int> v = {0,1,2,0,1,2,1,2,0,0,0,1};
    callbrute(v);
    vector <int> v1 = {0,1,2,0,1,2,1,2,0,0,0,1};
    callbetter(v1);
    calloptimal(v1);
    return 0;
}