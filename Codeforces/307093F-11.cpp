#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll a[n], res = 0,curr = 0,l = 0,r = 0;
    multiset<ll> s;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    for (int i = 0; i < n; ++i)
    {
    	s.insert(a[i]);
    	auto mx = s.end();
    	--mx;
    	auto mn = s.begin();
    	while(l<=i && *mx-*mn>m){
    		auto x = s.find(a[l]);
    		s.erase(x);
    		l++;
    		mx = s.end();
    		--mx;
    		mn = s.begin();
    	}

    	res+=(i-l+1);
    	//cout<<*mx<<' '<<*mn<<' '<<i<<' '<<l<<' '<<res<<endl;
    }    
    cout<<res<<'\n';
    return 0;
}