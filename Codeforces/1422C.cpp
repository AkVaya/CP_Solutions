#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
const ll M = 1e9 + 7;
ll binpow(ll a,ll b,ll m=M) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res%m;
}
int main(){
	string s;
	cin>>s;
	ll res = 0, cnt = 0, n = s.length(),sum = 0;
	ll suff[n+1];
	suff[n] = 0;
	suff[n-1] = 1;
	for (int i = n-2; i >= 0; --i)
	{
		suff[i] = suff[i+1];
		suff[i] = (suff[i] + ((n-i)*binpow(10,n-i-1))%M)%M;
		//cout<<suff[i]<<' ';
	}
	//cout<<endl;
	for (ll i = 0; i < n; ++i)
	{
		ll curr = (s[i]-'0');
		if(curr==0)
			continue;
		sum+=curr;
		ll k = (i * (i+1))%M;
		ll x = (k * binpow(2,M-2)%M)%M; 
		ll left = (x * binpow(10,n-i-1))%M;
		ll right = suff[i+1];
		ll val = (left+right)%M;
		//cout<<curr<<' '<<left<<' '<<right<<endl;
		res = (res + (val*curr)%M)%M;
	}
	//cout<<res<<' '<<sum<<endl;
	//res = (res - sum + M)%M;
	cout<<res<<endl;

   	return 0;
}