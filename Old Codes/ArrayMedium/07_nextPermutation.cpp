#include <bits/stdc++.h>
using namespace std;
void callRecursion(vector <int>& v , vector <int>& dataStructure , vector <int>& mapArray , vector <vector <int>>& storeAllPermutation){
    if(dataStructure.size() == v.size()){
        storeAllPermutation.push_back(dataStructure);
        return ;
    }
    for (int i = 0 ; i < v.size() ; i++){
        if(!mapArray[i]){
            mapArray[i] = 1;
            dataStructure.push_back(v[i]);
            callRecursion(v,dataStructure,mapArray,storeAllPermutation );
            mapArray[i] = 0;
            dataStructure.pop_back();
        }

    }
}
//O(n!*n)
//O(n) + O(n)
void callbrute(vector <int> v){
    vector <int> dataStructure;
    vector <vector<int>>storeAllPermutation;
    vector <int> mapArray(v.size() , 0);
    callRecursion(v , dataStructure , mapArray , storeAllPermutation);
    for (auto i : storeAllPermutation){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
void callRecursion_1(int index , vector <int>& v , vector <vector <int>>& storeAllPermutation){
    if(index >= v.size()){
        storeAllPermutation.push_back(v);
        return ;
    }
    for (int i = index ; i < v.size() ; i++){
        swap(v[index] , v[i]);
        callRecursion_1(index+1 , v , storeAllPermutation);
        swap(v[index] , v[i]);
    }
}
//O(n!*n)
void callbrute1(vector <int> v){
    vector <vector<int>>storeAllPermutation;
    callRecursion_1(0,v,storeAllPermutation);
    for (auto i : storeAllPermutation){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
// O(n*n!) 
void callbetter(vector <int>v){
    next_permutation(v.begin() , v.end());
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
//O(3n)
// O(1)
void calloptimal(vector <int>v){
    int index  = -1;
    int n = v.size();
    for (int i = n-2 ; i >= 0 ; i--){
        if(v[i] < v[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1){
        // just reverse the array 
        // because the input is the last permutation
        // or like 5 4 3 2 1 there is  dip in array from end
        reverse(v.begin() , v.end());
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    else{
        for (int i = n-1 ; i >= 0 ; i--){
            if(v[i] > v[index]){
                swap(v[i] , v[index]);
                break;
            }
        }
    }
    reverse(v.begin() + index + 1 , v.end());
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
int main(){
    vector <int>v = {1,2,3};
    vector <int>v1 = {2,1,5,4,3,0,0};
    callbrute(v);
    callbrute1(v);
    callbetter(v);
    calloptimal(v);
    return 0;
}
