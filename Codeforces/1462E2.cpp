#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
const ll M = 1e9 + 7;
ll fact[nax];
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
ll comb(ll n, ll r){
	if(!r)
		return 1LL;
	if(n-r<0)
		return 0;
	ll res = fact[n];
	res = (res * binpow(fact[n-r],M-2))%M;
	res = (res * binpow(fact[r],M-2))%M;
	return res;
}
int main(){
	int t;
	cin>>t;
	fact[0] = fact[1] = 1;
	for (ll i = 2; i <= nax; ++i)
	{
		fact[i] = ( i * fact[i-1])%M;
	}
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;
		ll a[n], res = 0;
		set<ll> s;
		vector<ll> cnt(n+1,0);
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			cnt[a[i]]++;
		}	
		sort(a,a+n);
		for(int i = 0; i < n; ++i){
			ll curr = i;
			auto it = upper_bound(a,a+n,(a[i]+k)) - a;
			--it;
			//cout<<curr<<' '<<it<<endl;
			res = (res + (comb(it-(curr + 1) + 1,m-1))%M)%M;
			
		}
		cout<<res<<'\n';
	}
	return 0;
}