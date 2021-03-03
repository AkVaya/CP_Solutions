#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
	ll n, m,x,y;
	cin>>n>>m;
	vector<pair<ll,ll> > v;
	set<ll> s;
	bool check = false;
	for (int i = 0; i < m; ++i)
	{
		cin>>x>>y;
		if(!x)
			check = true;
		v.push_back({y,x});
		s.insert(y);
	}
	s.insert(0LL);
	sort(v.begin(), v.end());
	
	map<ll,ll> res, sum;
	if(!check){
		cout<<0<<'\n';
		return 0;
	}
	res[0] = 0;
	sum[0] = 1;
	res[n] = 0;
	s.insert(-1LL);
	for (int i = 0; i < m; ++i)
	{
		ll from = v[i].second, to = v[i].first;
		//cout<<from<<' '<<to<<":";
		auto it = s.lower_bound(to);
		if(it==s.begin())
			continue;
		--it;
		auto it2 = s.lower_bound(from);
		if(it2==s.begin())
			continue;
		--it2;
		ll val = *it, val2 = *it2;
		res[to] = (res[to] + (sum[val] - sum[val2] + M)%M)%M;
		sum[to] = (res[to] + sum[val])%M;
		//cout<<res[to]<<endl;
	}
	//for(auto i : res)
		//cout<<i.first<<' '<<i.second<<endl;
	cout<<res[n]<<endl;


   	return 0;
}