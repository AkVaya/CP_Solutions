#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 69;
const int M = 1e9 + 7;
using ll = long long;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<pair<ll,pair<ll,ll> > >v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i].second.first>>v[i].second.second;
		v[i].first = v[i].second.first + v[i].second.second;
	}
	sort(v.begin(),v.end());
	ll res = 1,last = 0;
	for (int i = 1; i < n; ++i)
	{
		if(v[i].second.first-v[i].second.second>=v[last].first){
			res++;
			last = i;
		}
	}
	cout<<res<<'\n';
	return 0;
}