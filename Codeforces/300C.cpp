#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1e9 + 7;
const ll nax = 1e6 + 69;
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
bool isGood(ll n,ll a,ll b){
	while(n){
		if(n%10 !=a && n%10 != b)
			return false;
		n/=10;
	}
	return true;
}
ll comb(ll n,ll r){
	ll res = fact[n];
	res = (res * binpow(fact[n-r],M-2))%M;
	res = (res * binpow(fact[r],M-2))%M;
	return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a,b,n, res = 0;
    fact[0] = fact[1] = 1;
    cin>>a>>b>>n;
    for (int i = 2; i <= n; ++i)
    {
    	fact[i] = (i * fact[i-1])%M;
    }
    for (int i = 0; i <= n; ++i)
    {
    	if(!isGood(a*i + b*(n-i),a,b))
    		continue;
    	res = (res + comb(n,i))%M;
    }
    cout<<res<<'\n';
    return 0 ;
}