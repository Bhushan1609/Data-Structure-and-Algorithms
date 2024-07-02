#include <bits/stdc++.h>
using namespace std;
//[1, 2, 4, 7] and m = 9
// answer --> [1, 2, 4, 7, 9]
int main(){
    vector <int> arr = {1,2,4,7};
    int m = 9;
    cout << lower_bound(arr.begin() , arr.end() , m)  - arr.begin() << endl;
    return 0;
}