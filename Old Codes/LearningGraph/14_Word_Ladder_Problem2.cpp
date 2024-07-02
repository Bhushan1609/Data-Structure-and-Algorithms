#include <bits/stdc++.h>
using namespace std;
vector <vector <string>> BFS(string beginword , string endword , unordered_set <string>& storeword){
    vector <vector <string>> answer;
    queue<vector <string>> q;
    q.push({beginword});
    int size = 0;
    while(!q.empty()){
        vector <string> put = q.front();
        string back  = put.back();
        q.pop();
        if(back == endword){
            if(size == 0){
                size = put.size();
                answer.push_back(put);
            }
            else if(put.size() > size) break;
            else{
                answer.push_back(put);
            }
        }
        for (int i = 0 ; i < back.size() ; i++){
            for(int j = 0; j < 26 ; j++){
                char first = back[i];
                back[i] = (char)(j + 'a');
                if(storeword.find(back) != storeword.end()){
                    put.push_back(back);
                    q.push({put});
                }
            }
        }
    }
    return answer;
}
vector <vector <string>> countSteps(string beginword , string endword , vector <string>& wordlist){
    unordered_set<string> storeword(wordlist.begin() , wordlist.end());
    return BFS(beginword , endword , storeword);
}
int main(){
    string beginword = "bat" , endword = "coz";
    vector <string> wordlist = {"pat" , "bot" ,"pot" , "poz" , "coz" };
    vector <vector <string>>  ans = countSteps(beginword , endword , wordlist);
    cout << "Minimum Transformation Needed to make : " << endword << " is : " << endl;
    for (auto i : ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}