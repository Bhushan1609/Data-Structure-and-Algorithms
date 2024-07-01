#include <bits/stdc++.h>
using namespace std;
// O(n*n*n*n)
// O(2 * no. of the quadruplets)
void callbrute(vector <int>v , int target){
    int n = v.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    long long sum = v[i] + v[j];
                    sum += v[k];
                    sum += v[l];
                    if (sum == target) {
                        vector<int> temp = {v[i], v[j], v[k], v[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    for(auto i : ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return ;
}
//O(N3*log(M)), where N = size of the array, M = no. of elements in the set
//O(2 * no. of the quadruplets)+O(N) 
void callbetter(vector <int>v , int target){
    int n = v.size(); 
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                long long sum = v[i] + v[j];
                sum += v[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {v[i], v[j], v[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(v[k]);
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
    return ;
}
//O(N3)
//O(no. of quadruplets)
void calloptimal(vector<int>v ,int target){
    int n = v.size(); 
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && v[i] == v[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && v[j] == v[j - 1]) continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = v[i];
                sum += v[j];
                sum += v[k];
                sum += v[l];
                if (sum == target) {
                    vector<int> temp = {v[i], v[j], v[k], v[l]};
                    ans.push_back(temp);
                    k++; l--;
                    while (k < l && v[k] == v[k - 1]) k++;
                    while (k < l && v[l] == v[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
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
    vector <int> v = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    callbrute(v , target);
    cout << endl;
    callbetter(v , target);
    cout << endl;
    calloptimal(v , target);
    return 0;
}
