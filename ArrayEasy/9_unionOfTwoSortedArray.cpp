#include <bits/stdc++.h>
using namespace std;
//time --> O(n1logn1 + n2logn2) + O(n1 + n2) space --> O(n1 + n2) + O(n1+n2)
void callbrute(vector <int>v1 , vector <int>v2){
    set <int> st;
    for (int i = 0 ; i < v1.size() ; i++){
        st.insert(v1[i]);
    }
    for (int i = 0 ; i < v2.size() ; i++){
        st.insert(v2[i]);
    }
    vector <int> temp;
    for (auto i: st){
        temp.push_back(i);
    }
    for (auto i: temp){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
// time --> O(n1+n2)
// space --> O(n1+n2)
void calloptimal(vector <int>v1 , vector <int>v2){
    int n1 = v1.size() ;
    int n2 = v2.size();
    vector <int>temp;
    int i = 0;
    int j = 0;
    while(i < n1 and j < n2){
        if(v1[i] <= v2[j]){
            if(temp.size() == 0) temp.push_back(v1[i]);
            else if(temp.back() != v1[i] ){
                temp.push_back(v1[i]);
            }
            i++;
        }
        else{
            if(temp.size() == 0) temp.push_back(v2[j]);
            if(temp.back() != v2[j]){
                temp.push_back(v2[j]);
            }
            j++;
        }
    }
    while(i < n1){
        if(temp.back() != v1[i] ){
            temp.push_back(v1[i]);
        }
        i++;
    }
    
    while(j < n2){
        if(temp.back() != v2[j]){
            temp.push_back(v2[j]);
        }
        j++;
    }
    for (auto k : temp){
        cout << k << " ";
    }
    cout << endl;
    return ;
}
int main(){
    vector <int> v1 = {1,1,2,3,4,5};
    vector <int> v2 = {2,3,4,4,5,6};
    callbrute(v1 , v2);
    calloptimal(v1,v2);
    return 0;
}