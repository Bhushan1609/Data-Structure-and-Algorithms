#include <bits/stdc++.h>
using namespace std;
// time --> O(2n)
//space --> O(n)
void callbrute(vector <int>v){
    int n = v.size();
    vector <int> neg;
    vector <int> pos;
    for (auto i : v){
        if(i > 0) pos.push_back(i);
        else neg.push_back(i);
    }
    for (int i = 0 ; i < n/2 ; i++){
        v[2*i] = pos[i];
        v[2*i+1] = neg[i];
    }
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
//O(n)
//O(n)
void calloptimal(vector <int>v){
    int n = v.size();
    vector <int> answer(n ,0);
    int posindex = 0 , negindex = 1;
    for (int i = 0 ; i < n ; i++){
        if(v[i] > 0){
            answer[posindex] = v[i];
            if(i != (n-2)){
                posindex+=2;
            }
        }
        else {
            answer[negindex] = v[i];
            if(i != (n-1)){
                negindex+=2;
            }
        }
    }
    for (auto i : answer){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
//O(2n)
//O(n)
// Variety 2 where noof(pos) > noof(neg) and vice versa..
void variety2(vector <int>vec){
    int n = vec.size();
    vector <int> pos ;
    vector <int> neg;
    for (int i = 0 ; i < n; i++){
        if(vec[i] < 0) neg.push_back(vec[i]);
        else pos.push_back(vec[i]);
    }
    for (int i =0 ; i < min(neg.size()  , pos.size() ) ; i++){
        vec[2*i] = pos[i];
        vec[2*i + 1] = neg[i];
    }
    bool flag = false;
    int minIndex = 0;
    if(pos.size() > neg.size()) flag = true;
    for (int i = 2*(min(neg.size() , pos.size() )); i < n ;i++){
        if(flag) vec[i] = pos[i-neg.size()]; 
        else vec[i] = neg[i-pos.size()];
    }
    for (auto i : vec){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
int main(){
    vector <int> v= {3,1,-2,-5,2,-4};
    callbrute(v);
    calloptimal(v);
    vector <int> vec = {-1,2,3,4,-3,1};
    // pos --> 2,3,4,1
    // neg --> -1,-3
    // 2 -1 3 -3 4 1
    variety2(vec);
    return 0;
}