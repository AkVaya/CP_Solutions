#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 69;
using ll = long long ; 
int main(){
	ll n,res = 0,mx = 0;
	cin>>n;
	vector<pair<ll,ll> > v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i].second>>v[i].first;
		if(v[i].second>v[i].first)
			swap(v[i].first,v[i].second);
		res = max(res,v[i].second*v[i].first);
	}
	sort(v.rbegin(),v.rend());
	for (int i = 0; i < n; ++i)
	{
		//cout<<v[i].first<<' '<<v[i].second<<"	";
		res = max(res,min(mx,v[i].second)*v[i].first*2);
		mx = max(mx,v[i].second);
		//cout<<res<<' '<<mx<<endl;
	}
	//cout<<res<<endl;
	if(res%2)
		cout<<res/2<<".5\n";
	else
		cout<<res/2<<".0\n";
	return 0;
}