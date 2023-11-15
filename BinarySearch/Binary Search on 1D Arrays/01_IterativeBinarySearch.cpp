#include <bits/stdc++.h>
using namespace std;
void binarysearch(vector <int>& v , int target){
    int start = 0;
    int end = v.size() - 1;
    while(start <= end){
        int mid = end - (end - start)/2;
        if(v[mid] == target){
            cout << "Element " << target <<  " Found at the index : " << mid << endl;
            return ;
        }
        else if(v[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    cout << "Element " << target << " is not present in the array " << endl;
    return ;
}
int main(){
    vector <int> v = {3,4,6,7,9,12,16,17};
    int target = 4;
    binarysearch(v , target);
    return 0;
}