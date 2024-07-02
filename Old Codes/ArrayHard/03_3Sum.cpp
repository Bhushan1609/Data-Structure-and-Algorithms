#include <bits/stdc++.h>
using namespace std;
// O(N3 * log(no. of unique triplets))
// O(2 * no. of the unique triplets)
void callbrute(vector <int>v){
    int n = v.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (v[i] + v[j] + v[k] == 0) {
                    vector<int> temp = {v[i], v[j], v[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    for (auto i : ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
//O(N2 * log(no. of unique triplets))
//O(2 * no. of the unique triplets) + O(N) 
void callbetter(vector <int>v){
    int n = v.size(); 
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            int third = -(v[i] + v[j]);
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {v[i], v[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(v[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    for (auto i  : ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return ;
}
//O(2n)
//constant
void calloptimal(vector<int>v){
    int n = v.size(); 
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (i != 0 && v[i] == v[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = v[i] + v[j] + v[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {v[i], v[j], v[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && v[j] == v[j - 1]) j++;
                while (j < k && v[k] == v[k + 1]) k--;
            }
        }
    }
    for (auto i : ans){
        for (auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
    return ;
}

int main(){
    vector <int> v = { -1, 0, 1, 2, -1, -4};
    callbrute(v);
    cout << endl;
    callbetter(v);
    cout << endl;
    calloptimal(v);
    return 0;
}