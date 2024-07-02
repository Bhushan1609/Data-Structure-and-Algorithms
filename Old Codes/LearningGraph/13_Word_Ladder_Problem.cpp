#include <bits/stdc++.h>
using namespace std;
int BFS(vector <char>& vec ,string beginword , string endword , unordered_map<string , int>& storeWords){
    queue<pair <string , int>> q;
    q.push({beginword , 1});
    while(!q.empty()){
        pair <string , int> front = q.front();
        q.pop();
        if(front.first == endword) return front.second;
        for (int i = 0 ; i < front.first.size() ; i++){
            for (int j = 0 ; j < 26 ; j++){
                char first = front.first[i];
                front.first[i] = vec[j]; 
                if(storeWords.find(front.first) != storeWords.end()){
                    q.push({front.first , front.second + 1});
                    // Erasing the map <data>
                    storeWords.erase(front.first);
                }
                // backtrack
                front.first[i] = first;
            }

        }
    }
    return 0;
}
int countSteps(string beginword , string  endword , vector <string> wordlist){
    vector <char> vec;
    unordered_map<string , int> storeWords;
    for (int i = 0 ; i < 26 ; i++){
        char ch = 'a' + i;
        vec.push_back(ch);
    }
    for (auto i : wordlist){
        storeWords[i]++;
    }
    return BFS(vec , beginword , endword , storeWords);
}
int main(){
    string beginword = "hit" , endword = "cog";
    vector <string> wordlist = {"hot" , "dot" ,"dog" , "lot" , "log" , "cog"};
    int ans = countSteps(beginword , endword , wordlist);
    cout << "Minimum Transformation Needed to make : " << endword << " is : " << ans << endl;
    return 0;
}