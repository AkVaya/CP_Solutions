#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e7 + 1;
using ll = long long;
vector<ll> v(nax);
void sieve(){
	for (int i = 0; i < nax; ++i)
	{
		v[i] = (i%2 ? i : 2);
	}
	for (ll i = 3; i < nax; i+=2)
	{
		if (v[i]==i)
		{
			for (ll j = 2*i; j < nax; j+=i)
			{
				v[j] = min(v[j],i);
			}
		}
	}
}
ll fun(ll a){
	ll res = 1;
	while(a>1){
		ll x = v[a];
		if(a%(x*x)){
			res*=x;
			a/=x;
		}
		else
			a/=(x*x);
	}
	return res;
}
int main() 
{ 
	sieve();
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		set<ll> s;
		ll a[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			a[i] = fun(a[i]);
		}
		ll res = 0,i = 0;
		while(i<n){
			ll sq = sqrt(a[i]);
			if(s.find(a[i])!=s.end()){
				res++;
				s.clear();
				s.insert(a[i]);
			}
			else
				s.insert(a[i]);
			i++;
		}
		if(s.size())
			res++;
		cout<<res<<'\n';
	}
	return 0; 
}