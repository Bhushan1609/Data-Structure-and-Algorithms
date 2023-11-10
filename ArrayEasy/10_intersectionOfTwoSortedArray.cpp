#include <bits/stdc++.h>
using namespace std;
//time --> O(n1 * n2)
//space --> O(n2) (visited Array)
void callbrute(vector <int>v1 , vector <int> v2){
    int n1 = v1.size();
    int n2 = v2.size();
    vector <int> temp;
    vector <int> visited(n2,0);
    for (int i = 0 ; i < n1 ; i++){
        for(int j = 0 ; j < n2 ; j++){
            if(v1[i] == v2[j]  and visited[j] == 0){
                temp.push_back(v1[i]);
                visited[j] = 1;
                break;
            }
            if(v2[j] > v1[i]) break;
        }
    }
    for (auto i : temp){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
//O(n1+n2)
// constant
void calloptimal(vector <int>v1 , vector <int>v2){
    int n1 = v1.size() ;
    int n2 = v2.size();
    vector <int> temp;
    int i = 0; 
    int j = 0;
    while(i < n1 and j < n2){
        if(v1[i] < v2[j]) i++;
        else if(v1[i] > v2[j]) j++;
        else {
            temp.push_back(v1[i]);
            i++;
            j++;
        }
    }
    for (auto i: temp){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
int main(){
    vector <int> v1 = {1,2,2,3,3,4,5,6};
    vector <int> v2 = {2,3,3,5,6,6,7};
    callbrute(v1,v2);
    calloptimal(v1,v2);
    return 0;
}