#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
	ll n,m;
	cin>>n>>m;
	if(n<=m){
		cout<<n<<'\n';
		return 0;
	}
	ll res = m;
	n-=m;
	ll l = 1, r = 2e9;
	while(l<=r){
		ll mid = (l + r)/2;
		if(n-(mid * (mid + 1))/2<=0)
			r = mid - 1;
		else l = mid + 1;
	}
	cout<<res + r + 1<<endl;
	return 0;
}