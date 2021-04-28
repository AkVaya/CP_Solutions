#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int main(){
	ll n, res = 0, x, y;
	cin>>n;
	vector<ll> v;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;
		v.push_back(x-y);
		res-=x;
		res+=n*y;
	}
	sort(v.begin(), v.end(), greater<ll>());
	x = 1;
	for(auto i : v)
		res+=(i*x++);
	cout<<res<<'\n';

	return 0;
}