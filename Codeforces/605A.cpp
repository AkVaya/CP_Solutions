#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
	int n;
	cin>>n;
	int a[n];
	vector<int> lis(n+1,0);//kind of lis
	int res = INT_MAX;
	for (int i = 0; i < n; ++i){
		cin>>a[i];
		lis[a[i]] = 1 + lis[a[i] - 1];
		//cout<<a[i]<<' '<<lis[a[i]]<<endl;
		res = min(res, n - lis[a[i]]);
	}
	cout<<res<<'\n';
	return 0;
}