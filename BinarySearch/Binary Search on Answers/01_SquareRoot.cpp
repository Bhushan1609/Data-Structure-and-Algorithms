#include <bits/stdc++.h>
using namespace std;
void callbrute(int n){
    cout << sqrt(n) << endl;
    return ;
}
void callbetter(int n){
    int ans ;
    for (int i = 1; i <= n ; i++){
        if(i*i <= n){
            ans = i;
        }
        else break;
    }
    cout << ans << endl;
    return ;
}
void calloptimal(int n){
    int start= 1;
    int end = n;
    int ans ;
    while(start <= end){
        int mid = end - (end - start)/2;
        if(mid*mid <= n){
            ans = mid;
            start = mid + 1;
        }
        else if(mid*mid > n){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    cout << ans << endl;
    return ;
}
int main(){
    int n = 25;
    callbrute(n);
    callbetter(n); // O(n)
    calloptimal(n);
    return 0;
}