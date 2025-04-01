#include<bits/stdc++.h>
using namespace std;

int BFS(string beginWord,string endWord,unordered_set<string>&visited){
    queue<pair<string,int>>q;
    q.push({beginWord,1});
    while(!q.empty()){
        int q_size=q.size();
        for(int q_it=0;q_it<q_size;q_it++){
            auto [word,dist]=q.front();
            q.pop();
            for(int i=0;i<word.size();i++){
                for(char ch='a';ch<='z';ch++){
                    char backtrack=word[i];
                    word[i]=ch;
                    if(visited.find(word) != visited.end()){
                        visited.erase(word);
                        if(word==endWord)
                            return dist+1;
                        else
                            q.push({word,dist+1});
                    }
                    word[i]=backtrack;
                }
            }
        }
    }
    return 0;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string beginWord="hit",endWord="cog";
    vector<string>wordList={"hot","dot","dog","lot","log","cog"};
    unordered_set<string>visited;
    for(auto &i:wordList)
        visited.insert(i);
    cout<<"Number of transformation needed are : "<<BFS(beginWord,endWord,visited)<<endl;
    return 0;
}