#include<bits/stdc++.h>
using namespace std;
int optimal(string a , string b){
	int n=a.size(),m=b.size();
	vector<int>prev(m+1,0),curr(m+1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1])curr[j]=1+prev[j-1];
			else curr[j]=max(curr[j-1],prev[j]);
		}
		prev=curr;
	}
	return prev[m];
}
int main(){
    string a="abcdabcd";
    string b=a;
    reverse(begin(b),end(b));
    cout<<a.size()-optimal(a,b);
    return 0;
}