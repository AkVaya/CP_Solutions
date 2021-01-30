#include<bits/stdc++.h>
using namespace std;
const int nax = 1e7 + 69;
const int M = 1e9 + 7;
using ll = long long;
ll binpow(ll a,ll b,ll m=M) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}
int main(){
	ll t;
	cin>>t;
	ll fact[1001];
	fact[0] = fact[1] = 1;
	for (int i = 2; i < 1001; ++i)
	{
		fact[i] = (i * fact[i-1])%M;
	}
	while(t--){
		ll n,k;
		cin>>n>>k;
		set<ll,greater<ll> >s;
		map<ll,ll> m;
		ll a[n],res = 1;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			s.insert(a[i]);
			m[a[i]]++;
		}
		for(auto i : s){
			if(k<=0)
				break;
			if(m[i]>k){
				res = (((fact[m[i]]*binpow(fact[k],M-2))%M)*binpow(fact[m[i]-k],M-2))%M;
			}
			k-=m[i];
		}
		cout<<res<<'\n';

	}
	return 0;
}