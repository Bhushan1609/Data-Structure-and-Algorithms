#include <bits/stdc++.h>
using namespace std;
int calloptimal(vector<int>& arr,  int target) {
	int first = -1;
    int last  = -1;
    int start = 0;
    int end = arr.size() -  1;
    // finding first occurence
    while(start <= end){
		int mid = end - (end - start)/2;
		if(arr[mid] == target){
			first = mid;
			end = mid - 1;
		}
		else if(arr[mid] < target){
			start = mid + 1;
		}
		else{
			end = mid -1;
		}
    }
	start = 0;
	end = arr.size() - 1;
	while(start <= end){
		int mid = end - (end - start)/2;
		if(arr[mid] == target){
			last = mid;
			start = mid + 1;
		}
		else if(arr[mid] < target){
			start = mid + 1;
		}
		else{
			end = mid -1;
		}
	}
	if(last == -1 and first == last) return 0;
	return last - first + 1;
}

int main(){
    vector <int> v = {2,4,6,8,8,8,11,13};
    int target = 8;
    cout << calloptimal(v , target) << endl;
    return 0;
}