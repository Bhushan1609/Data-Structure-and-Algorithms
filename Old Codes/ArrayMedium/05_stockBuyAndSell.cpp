#include <bits/stdc++.h>
using namespace std;
// O(n*n)
void callbrute(vector <int>v){
    int n = v.size() ;
    int Profit = INT_MIN;
    for (int i = 0; i < n; i++){
        int stockToBuy = v[i];
        for (int j = i+1 ; j < n; j++){
            if(v[j] > stockToBuy) Profit = max(Profit , v[j] - stockToBuy);
        }
    }
    cout << "Profit : " << Profit << endl;
    return ;
}
// O(n)
// O(1)
void calloptimal(vector <int>v){
    int n = v.size() ;
    //Keep track of the minimum element at every index
    int Profit = 0;
    int mini = v[0];
    for (int i = 1; i < n ; i++){
       mini = min(mini , v[i]);
       Profit = max(Profit ,v[i] - mini);
    }
    cout << "Profit : " << Profit << endl;
    return ;
}
int main(){
    vector <int> v= {7,1,5,3,6,4};
    callbrute(v);
    calloptimal(v);
    return 0;
}