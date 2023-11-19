#include <bits/stdc++.h>
using namespace std;
int func(vector <int>&piles , int h){
    int ans = 0;
    for (int i = 0 ; i < piles.size() ; i++){
        if(piles[i]%h == 0) ans += (piles[i]/h);
        else{
            if(piles[i] < h) ans++;
            else{
                ans++;
                ans +=(piles[i]/h);
            }
        }
    }
    return ans;
}
// O(max(piles) * n)
void callbrute(vector <int>&piles , int h){
    int maxi = *max_element(piles.begin()  , piles.end());
    for (int hr = 1 ; hr <= maxi ; hr++){
        int answer = func(piles , hr);//function to find total hrs to eat bananas
        if(answer <= h){
            cout << "Koko can eat all bananas within h hrs : " << hr << endl;
            return ;
        }
    }
    cout << "Koko can't eat all bananas within h hrs : "<< endl;
    return ;
}
//O(log(maxElement))
void calloptimal(vector <int>&piles , int h){
    int maxi = *max_element(piles.begin()  , piles.end());
    int start = 1 ;
    int end = maxi;
    int hr = 0;
    while(start <= end){
        int mid = end-(end-start)/2;
        if(func(piles , mid) <= h){
            hr = mid;
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
    }
    if(hr != 0){
        cout << "Koko can eat all bananas within h hrs : " << hr << endl;
        return ;
    }
    cout << "Koko can't eat all bananas within h hrs : "<< endl;
    return ;
}
int main(){
    vector <int> piles = {3 ,6,7,11};
    int h = 8;
    callbrute(piles , h);
    calloptimal(piles , h);
    return 0;
}       