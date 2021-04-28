#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
	int n;
	cin>>n;
	ll v[n], t[n];
	vector<ll> pref(n,0);
	priority_queue<ll,vector<ll>, greater<ll> >pq; 
	for (int i = 0; i < n; ++i)
		cin>>v[i];
	for (int i = 0; i < n; ++i){
		cin>>t[i];
		pref[i] += t[i];
		if(i)
			pref[i]+=pref[i-1];
	}
	vector<ll> res(n,0);
	map<ll,ll> m;
	for (int i = 0; i < n; ++i)
	{
		if(v[i]<=t[i]){
			res[i]+=v[i];
			continue;
		}
		auto ind = lower_bound(pref.begin(), pref.end(),( i ? pref[i-1] : 0) + v[i]) - pref.begin();
		//cout<<i<<' '<<ind<<endl;
		m[i]++;
		if(ind!=n){
			m[ind]--;
			//cout<<ind<<' '<<pref[ind-1]-(i ? pref[i-1] : 0)<<' '<<v[i]<<endl;
			res[ind] +=  (v[i]-(pref[ind-1]-(i ? pref[i-1] : 0)));
			//cout<<ind<<' '<<res[ind]<<endl;
		}
	}
	//cout<<endl;
	for(int i = 1; i < n; ++i){
		m[i]+=m[i-1];
		//cout<<i<<' '<<m[i]<<' '<<res[i]<<endl;
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<res[i] + (m[i] * t[i])<<' ';
	}
	cout<<'\n';
	return 0;
}