#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e4 + 69;
using ll = long long;
void subsets(vector<ll>& res, ll* a,ll n,ll start){
	for (ll i = 0; i < (1LL<<n); ++i)
	{
		ll curr = 0;
		for (ll j = 0; j < n; ++j)
		{
			if(i&(1LL<<j))
				curr+=a[start + j];
		}
		res.push_back(curr);
	}
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, l, r;
    cin>>n>>l>>r;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    ll res = 0;
    vector<ll> fir, sec;
    subsets(fir, a, n/2, 0);
    subsets(sec, a, n-n/2, n/2);
    sort(sec.begin(), sec.end());
    for(auto i : fir){
    	ll it = lower_bound(sec.begin(), sec.end(), l-i) - sec.begin();
    	ll it2 = upper_bound(sec.begin(), sec.end(), r-i) - sec.begin();
    	res+=(it2-it);
    }
    cout<<res<<'\n';
	return 0;
}