#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[5] = {12,2,4,13,1};
    int maxi = INT_MIN;
    for(int i = 0 ; i < 5 ; i++) maxi = max(maxi , arr[i]); 
    cout << maxi << endl;
    return 0;
}
