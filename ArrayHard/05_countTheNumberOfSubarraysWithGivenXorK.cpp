#include <bits/stdc++.h>
using namespace std;
//O(n*n*n)
//O(1)
void callbrute(vector<int> a, int k) {
    int n = a.size(); 
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }
            if (xorr == k) cnt++;
        }
    }
    cout << "The number of subarrays with XOR k is: "<< cnt << endl;
    return ;
}
//O(n*n)
//O(1)
void callbetter(vector <int>a , int k){
    int n = a.size(); 
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {
            xorr = xorr ^ a[j];
            if (xorr == k) cnt++;
        }
    }
    cout << "The number of subarrays with XOR k is: "<< cnt << endl;
    return ;
}
//O(nlogn)
//O(n)
void calloptimal(vector <int>a ,int k){
    int n = a.size(); 
    int xr = 0;
    map<int, int> mpp; 
    mpp[xr]++; 
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    cout << "The number of subarrays with XOR k is: "<< cnt << endl;
    return ;
}
int main()
{
    vector<int> v = {4, 2, 2, 6, 4};
    int k = 6;
    callbrute(v , k);
    callbetter(v , k);
    calloptimal(v , k);
    return 0;
}
