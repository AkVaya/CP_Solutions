#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int main(){
	ll n,k;
	cin>>n>>k;
	ll a[n];
	map<ll,ll> m;
	ll l = INT_MAX, r = 0;
	for (int i = 0; i < n; ++i){
		cin>>a[i];
		m[a[i]]++;
	} 
	k *= 8;
	k/=n;
	k = min(k, 30LL);
	k = (1LL<<k);
	int ind = 1, cnt = m.size();
	if(cnt<=k){
		cout<<"0\n";
		return 0;
	}
	vector<ll> temp, pref;
	pref.push_back(0);
	temp.push_back(0);
	for(auto i : m){
		temp.push_back(i.first);
		pref.push_back(pref[ind-1] + i.second);
		ind++;
	}
	ll mx = 0;
	for (int i = 0; i <= cnt - k; ++i)
	{

		mx = max(mx,pref[i+k]-pref[i]);
	}
	cout<<(n-mx)<<'\n';

	return 0;
}