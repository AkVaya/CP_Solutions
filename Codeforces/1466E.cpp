#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 69;
const int M = 1e9 + 7;
using ll = long long;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ll a[n];
		ll res = 0;
		vector<ll> cnt(61);
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			int ind = 0;
			ll temp = a[i];
			while(a[i]){
				if(a[i]%2)
					cnt[ind]++;
				ind++;
				a[i]/=2;
			}
			a[i] = temp;
		}
		for (int i = 0; i < n; ++i)
		{
			ll temp1 = 0, temp2 = 0; 
			for (ll j = 0; j < 61; ++j)
			{
				if(a[i] & (1LL<<j)){
					temp1 = (temp1 + (cnt[j]*((1LL<<j)%M))%M)%M;
					temp2 = (temp2 + (n*((1LL<<j)%M))%M)%M;
				}
				else
					temp2 = (temp2 + (cnt[j]*((1LL<<j)%M))%M)%M;
			}
			res = (res + (temp1*temp2)%M)%M;
		}
		cout<<res%M<<'\n';
	}
	return 0;
}