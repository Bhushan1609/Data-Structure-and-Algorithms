#include<bits/stdc++.h>
using namespace std;
// all elements are unique
int calloptimal(vector<int>& arr)
{
	int start = 0;
	int end = arr.size() - 1;
	int mini = INT_MAX;
	while(start <= end){
		int mid = end - (end - start)/2;
		if(arr[start] <= arr[end]){
			mini = min(mini , arr[start]);
			break;
		}
		if(arr[start] <= arr[mid]){
			mini = min(mini , arr[start]);
			start = mid+1;
		}
		else{
			mini = min(mini , arr[mid]);
			end = mid-1;
		}
	}

	return mini;
}
int main(){
    vector <int> v = {22,23,1,2,3,4};
    cout << (int) calloptimal(v) << endl;
    return 0;
}