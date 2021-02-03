#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 69;
const int M = 1e9 + 7;
using ll = long long;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n],cnt1 = 0,cnt2 = 0;
		vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			if(a[i]==i+1)
				cnt1++;
			else v.push_back(i);
		}
		if(cnt1==n){
			cout<<"0\n";
			continue;
		}
		for (int i = 1; i < v.size(); ++i)
			if(v[i]-v[i-1]!=1)
				cnt2++;
		if(cnt2)
			cout<<"2\n";
		else cout<<"1\n";
	}
	return 0;
}