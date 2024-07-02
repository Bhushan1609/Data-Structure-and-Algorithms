#include <bits/stdc++.h>
using namespace std;
void recursivebinarysearch(vector <int>& v , int target , int start , int end){
    if(start >= end){
        cout << "Element " << target << " is not present in the array " << endl;
        return ;
    }
    int mid = end - (end - start)/2;
    if(v[mid] == target){
        cout << "Element " << target <<  " Found at the index : " << mid << endl;
        return ;
    }
    else if(v[mid] < target){
        recursivebinarysearch(v , target , mid + 1 , end);
    }
    else{
        recursivebinarysearch(v,target,start , mid-1);
    }
    return ;
}
int main(){
    vector <int> v = {3,4,6,7,9,12,16,17};
    int target = 413;
    int start = 0 ,end = v.size()-1;
    recursivebinarysearch(v , target , start , end);
    return 0;
}