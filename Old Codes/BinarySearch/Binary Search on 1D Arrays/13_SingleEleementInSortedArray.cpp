#include <bits/stdc++.h>
using namespace std;
int calloptimal(vector <int>& arr){
    int n = arr.size();
	if(n == 1) return arr[0];
	if(arr[0] != arr[1]) return arr[0];
	if(arr[n-1] != arr[n-2]) return arr[n-1];
	int start = 1;
	int end = n - 2;
	while(start <= end){
		int mid = end - (end - start)/2;
		if(arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1]) return arr[mid];
		if((mid&1 and arr[mid] == arr[mid-1]) or (mid%2 == 0 and arr[mid] == arr[mid+1])){
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	return -1;	
}
int main(){
    vector <int> v = {1,1 ,2,2,3,3,4,5,5};
    cout << (int) calloptimal(v) << endl;
    return 0;
}