#include <bits/stdc++.h>
using namespace std;
int possible(vector <int>& books , int val ){
    int cnt = 1;
    int sum = 0;
    for (int i = 0 ; i < books.size() ; i++){
        sum += books[i];
        if(sum > val){
            cnt++;
            sum = books[i];
        }       
    }
    return cnt ;
}
int callbrute(vector <int>& books , int students){
    int start = *max_element(begin(books) , end(books));
    int end = accumulate(books.begin() , books.end() , 0);
    for (int i = start ; i <= end ; i++){
        if(possible(books , i) == students){
            return i;
        }
        else continue;
    }
    return -1;
}
//O(log(sum - maxi + 1) * n)
int calloptimal(vector <int>& books , int students){
    int start = *max_element(begin(books) , end(books));
    int end = accumulate(books.begin() , books.end() , 0);
    int ans;
    while(start <= end){
        int mid = (end+start)/2;
        if(possible(books , mid ) > students){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return start;
}
int main(){
    vector <int> books = {25,46,28,49,24};
    int students = 4;
    cout << (int) callbrute(books , students) << endl;
    cout << (int) calloptimal(books , students) << endl;
    return 0;
}