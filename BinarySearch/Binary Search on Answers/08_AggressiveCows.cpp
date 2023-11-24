#include <bits/stdc++.h>
using namespace std;
bool canWePlaceCows(int dist , vector <int>& arr ,int cows){
    int countCowsCanPlace = 0;
    int first = arr[0];
    int second = arr[0];
    for (int i = 0 ; i < arr.size() ; i++){
        second = arr[i];
        if(abs(first - second) >= dist) {
            // cout << "Possible : " << first << " : " << second << endl; 
            countCowsCanPlace++;
            first = arr[i];
        }
    }
    countCowsCanPlace++;
    return countCowsCanPlace >= cows;
}
//O(nlogn) + O((maxi-mini)*n)) 
int callbrute(vector <int>& arr , int cows){
    sort(begin(arr) , end(arr));//O(nlogn)
    int start = 1;
    int n = arr.size();
    int maxi = arr[n-1];
    int mini = arr[0];
    int end = maxi - mini;
    for (int dist = start ; dist <= end ; dist++){//O((maxi-mini) * (n))
        if(canWePlaceCows(dist ,arr , cows)){
            // cout << "Yes we can Place at the distance : " << dist << endl;
            continue;
        }
        else{
            return dist-1;
        }
    }
    return -1;
}
//O(nlogn) + O(log(maxi-mini) * n)
int calloptimal(vector <int> & arr , int cows){
    sort(begin(arr), end(arr));
    int start = 1;
    int n = arr.size();
    int maxi = arr[n-1];
    int mini = arr[0];
    int end = maxi - mini;
    int ans;
    while(start <= end){
        int mid = end - (end - start)/2;
        if(canWePlaceCows(mid , arr , cows)){
            start = mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return start-1 ;
}
int main(){
    vector <int> arr = {0,3,4,7,10,9};
    int cows = 4;
    cout << callbrute(arr,cows) << endl;
    cout << calloptimal(arr , cows) << endl;
    return 0;
}





