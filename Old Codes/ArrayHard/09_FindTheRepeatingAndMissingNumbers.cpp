#include <bits/stdc++.h>
using namespace std;
//O(n*n)
//O(1)
void callbrute(vector<int> a) {
    int n = a.size(); 
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) cnt++;
        }
        if(cnt == 2) repeating = i;
        else if(cnt == 0) missing = i;
        if (repeating != -1 && missing != -1) break;
    }
    cout << "The repeating and missing numbers are: {" << repeating << ", " << missing << "}\n";
    return ;
}
//O(2n)
//O(n)
void callbetter(vector <int>a ){
    int n = a.size(); 
    int hash[n + 1] = {0}; 
    for (int i = 0; i < n; i++) hash[a[i]]++;
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) repeating = i;
        else if (hash[i] == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    cout << "The repeating and missing numbers are: {" << repeating << ", " << missing << "}\n";
    return ;
}
//O(n)
//O(1)
void calloptimal1(vector <int>a ){
    long long n = a.size();
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    cout << "The repeating and missing numbers are: {" << (int)x << ", " << (int)y << "}\n";
    return ;
}
//O(n)
//O(1)
void calloptimal2(vector <int>a ){
    int n = a.size(); 
    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }
    int number = (xr & ~(xr - 1));
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        else {
            zero = zero ^ a[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((i & number) != 0) {
            one = one ^ i;
        }
        else {
            zero = zero ^ i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }
    if (cnt == 2) {
        cout << "The repeating and missing numbers are: {" << (int)one << ", " << (int)zero << "}\n";
        return ;
    }
    cout << "The repeating and missing numbers are: {" << (int)one << ", " << (int)zero << "}\n";
    return ;
}
int main()
{
    vector<int> v = {3, 1, 2, 5, 4, 6, 7, 5};
    callbrute(v); 
    callbetter(v);
    calloptimal1(v);
    calloptimal2(v);
    return 0;
}
