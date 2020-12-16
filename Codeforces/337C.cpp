#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const ll M = 1e9+9;
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
int main()
{
	ll n,m,k,res = 0;
	cin>>n>>m>>k;
	if(m<=(n+1)/2){
		res = m;
	}
	else{
		ll x = max(0LL,m-(((n-n%k)/k)*(k-1) + n%k));
		res = (((binpow(2,x+1)-2)*k)%M+m-(x*k)+M)%M;

	}
	cout<<res<<'\n';
    return 0;
}