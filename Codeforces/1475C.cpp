#include<bits/stdc++.h>
using namespace std;
const int nax = 1e7 + 69;
const int M = 1e9 + 7;
using ll = long long;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;
		ll a[k],b[k];
		map<ll,ll> m1,m2;
		map<pair<ll,ll>,ll> m3;
		for (int i = 0; i < k; ++i)
		{
			cin>>a[i];
			m1[a[i]]++;
		}
		for (int i = 0; i < k; ++i)
		{
			cin>>b[i];
			m2[b[i]]++;
			m3[{a[i],b[i]}]++;
		}
		ll res = 0;
		for (int i = 0; i < k; ++i)
		{
			--m1[a[i]];
			--m2[b[i]];
			--m3[{a[i],b[i]}];
			res+=(k-i-1 -(m1[a[i]] + m2[b[i]] - m3[{a[i],b[i]}]));
		}
		cout<<res<<'\n';
	}
	return 0;
}