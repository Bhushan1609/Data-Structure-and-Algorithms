#include <bits/stdc++.h>
using namespace std;
//O(n*n)
//O(1)
void callbrute(vector <int>v1 ){
    int n = v1.size();
    for (int i =1 ; i <= n ; i++){
        int flag = 0;
        for (int j = 0; j < n ; j++){
            if(v1[j] == i){
                flag = 1;
                break;
            }
        }
        if(!flag){
            cout << "Missing Element is : " << i << endl;
            return ;
        }
    }
    return;
}
// O(2n)
//O(n)
void callbetter(vector <int>v1){
    int n  = v1.size();
    vector <int> mapp(n+1 , 0);
    for (int i = 0 ; i < n ; i++){
        mapp[v1[i]] = 1;
    }
    for (int i =1 ; i <= n ; i++){
        if(mapp[i] == 0){
            cout << "Missing Element is : " << i << endl;
            return ; 
        }
    }
    return ;
}
//O(n)
//O(1)
void calloptimal(vector <int>v1){
    int n = v1.size() ;
    int sum = n*(n+1)/2;
    for (int i = 0 ; i < v1.size() ;i++){
        sum -= v1[i];
    }
    cout << "Missing Element is : " << sum << endl;
    return ;
}
//O(n)
void calloptimal2(vector <int>v1){
    int n = v1.size() ;
    int x1 = 0 , x2 = 0;
    for (int i = 0 ; i < n ;i++){
        x1 ^= v1[i];
        x2 ^= i+1;
    }
    cout << "Missing Element is : " << (x1^x2) << endl;
    return ;
}
int main(){
    vector <int> v = {9,6,4,2,3,5,7,0,1};
    callbrute(v);
    callbetter(v);
    calloptimal(v);
    calloptimal2(v);
    return 0;
}