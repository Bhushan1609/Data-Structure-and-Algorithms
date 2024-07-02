#include<bits/stdc++.h>
using namespace std;
//O(n*n*n)
//O(1)
void callbrute(vector<int> v) {
    int result = INT_MIN;
    for(int i=0;i<v.size()-1;i++) {
        for(int j=i+1;j<v.size();j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= v[k];
            result = max(result,prod);    
        }
    }
    cout<<"The maximum product subarray: "<<result << endl;
    return ;
}
//O(n*n)
//O(1)
void callbetter(vector<int> v) {
    int result = v[0];
    for(int i=0;i<v.size()-1;i++) {
        int p = v[i];
        for(int j=i+1;j<v.size();j++) {
           result = max(result,p);
           p *= v[j];
        }
        result = max(result,p);
    }
    cout<<"The maximum product subarray: "<<result << endl;
    return ;
}
//O(n)
//O(1)
void calloptimal1(vector<int> v) {
    int n = v.size(); 
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= v[i];
        suff *= v[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    cout<<"The maximum product subarray: "<<ans << endl;
    return ;
}
//O(n)
//O(1)
void calloptimal2(vector<int> v) {
    int prod1 = v[0],prod2 = v[0],result = v[0];
    
    for(int i=1;i<v.size();i++) {
        int temp = max({v[i],prod1*v[i],prod2*v[i]});
        prod2 = min({v[i],prod1*v[i],prod2*v[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    cout<<"The maximum product subarray: "<<result << endl;
    return ;
}
int main() {
    vector<int> v = {1,2,-3,0,-4,-5};
    callbrute(v);
    callbetter(v);
    calloptimal1(v);
    calloptimal2(v);
    return 0;
}

