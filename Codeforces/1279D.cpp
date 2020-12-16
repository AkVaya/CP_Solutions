#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 998244353;
void mult(ll &a, ll b){
	a*=b;
	a%=M;
}
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
	ll n,k,x;
	cin>>n;
	map<ll,ll> m;
	map<ll,vector<ll> > temp;
	for (int i = 0; i < n; ++i)
	{
		cin>>k;
		while(k--){
			cin>>x;
			m[x]++;
			temp[i].push_back(x);
		}
	}
	ll num = 0,den=binpow(n,M-2);
	mult(den,binpow(n,M-2));
	for (int i = 0; i < n; ++i)
	{
		x=temp[i].size();
		for (auto j : temp[i])
		{
			num+=(den*((binpow(x,M-2)*m[j])%M))%M;
			num%=M;
		}
	}
	cout<<(num+M)%M<<endl;
	return 0;
}