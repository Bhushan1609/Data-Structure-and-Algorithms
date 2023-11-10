#include <bits/stdc++.h>
using namespace std;
void print(vector <int>v){
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
void bruterotate(vector <int>& v , int k){
    int n = v.size();
    k %= n;
    vector <int> dummyV;
    for (int i =0 ; i < k ; i++){
        dummyV.push_back(v[i]);
    }
    for (int i = k ; i < n ; i++){
        v[i-k] = v[i];
    }
    for (int i = n-k ; i < n ; i++){
        v[i] = dummyV[i-(n-k)];
    }
    return ;
}
void optimalrotate(vector <int>& v , int k){
    int n = v.size() ;
    k %= n;
    reverse(v.begin() , v.begin() + k);
    reverse(v.begin()+k , v.end());
    reverse(v.begin() , v.end() );
    return ;
}
//rotate for right
void r(int start , int end , vector <int>& v){      
    while(start < end){
        swap(v[start] , v[end]);
        start++;end--;
    }
    return ;
}
void rotate(vector<int>& v, int k) {
    int n = v.size() ;
    k %= n;
    r(0 , n-k-1 , v);
    r(n-k , n-1 , v);
    r(0 , n-1 ,v);
    return ;
}
int main(){
    vector <int> v = {1 , 2 , 3 , 4, 5 , 6, 7};
    int k =  3;
    bruterotate(v , k);
    print(v);
    vector <int> v1 = {1 , 2 , 3 , 4, 5 , 6, 7};
    optimalrotate(v1 , k);
    print(v1);
    return 0;
}