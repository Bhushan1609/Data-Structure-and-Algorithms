#include <bits/stdc++.h>
using namespace std;
bool check(int target , vector <int>v){
    int n = v.size();
    for (int i = 0 ; i < n ;i++){
        if(target == v[i]) return true;
    }
    return false;
}
//O(n*n)
//O(1)
void callbrute(vector <int>v ){
    int n = v.size();
    int longest = 1;
    for (int i = 0; i < n ; i++){
        int findNext = v[i];
        findNext++;
        int cnt =  1;
        while(check(findNext , v)){
            findNext++;
            cnt++;
        }
        longest = max(longest , cnt);
    }
    cout << "Longest Consecutive Sequence is : " << longest << endl;
    return ;
}
// O(nlogn) + O(n)
// constant
void callbetter(vector <int> v){
    sort(v.begin() , v.end());
    int n = v.size();
    int longest = 1;
    int cnt = 0;
    int lastSmaller = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        if(v[i]-1 == lastSmaller){
            cnt++;
            lastSmaller = v[i];
        }
        else if(v[i] != lastSmaller){
            cnt = 1;
            lastSmaller = v[i];
        }
        longest = max(cnt , longest);
    }
    cout << "Longest Consecutive Sequence is : " << longest << endl;
    return ;
}
// O(3n) 
// O(n)
void calloptimal(vector <int> v){
    int n = v.size();
    int longest = 1;
    unordered_set <int> put;
    for (int i = 0 ; i < n ; i++) put.insert(v[i]);
    for (auto i : put){
        if(put.find(i-1) == put.end()){
            int cnt = 1;
            int x = i;
            while(put.find(x+1) != put.end()){
                cnt++;
                x++;
            }
            longest = max(longest , cnt);
        }
    }
    cout << "Longest Consecutive Sequence is : " << longest << endl;
    return ;
}

int main(){
    // consecutive squence means --> {1,2,3,4} or {100,1001,102}
    // longest is                     {4}            {3}
    vector <int> v = {102,4,100,1,101,3,2,1,1};
    callbrute(v);
    callbetter(v);
    calloptimal(v);
    return 0;
}