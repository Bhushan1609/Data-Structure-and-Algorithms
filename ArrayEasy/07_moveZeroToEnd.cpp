#include <bits/stdc++.h>
using namespace std;
//O(2n)
//O(n-temp.size())--> space
void brute(vector <int>& v){
    vector <int> temp;
    for (int i = 0 ; i < v.size() ; i++){
        if(v[i]) temp.push_back(v[i]);
    }
    for (int i =0 ; i < v.size() ; i++){
        if(i < temp.size()) v[i] = temp[i];
        else v[i] = 0;
    }
    return;
}
void print(vector <int>&v){
    for (auto i : v) cout << i << " ";
    cout << endl;
    return ;
}
void optimal(vector <int>&v1){
    int j = -1;
    for (int i = 0; i < v1.size() ; i++){
        if(!v1[i]) {
            j = i;
            break;
        }
    }
    if(j == -1) return ;
    for (int i = j + 1; i <v1.size() ; i++){
        if(v1[i]){
            swap(v1[i] , v1[j]);
            j++;
        }
    }
    return ;
}
int main(){
    vector <int>v = {1,0,2,3,2,0,0,4,5,1};
    brute(v);
    print(v);
    vector <int>v1 = {1,0,2,3,2,0,0,4,5,1};
    optimal(v1);//O(n)
    print(v1);
    return 0;
}
