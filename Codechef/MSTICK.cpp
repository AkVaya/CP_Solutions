#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll nax = 1e5 + 69;
ll st1[nax][18],st2[nax][18],lg[nax];
ll a[nax],pref[nax],suff[nax];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n;
	pref[0] = 0;
	suff[n+1] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		st1[i][0] = a[i];
		st2[i][0] = a[i];
		pref[i] = max(a[i],pref[i-1]);
	}
	for (int i = n; i >= 1; --i)
		suff[i] = max(a[i],suff[i+1]);
	lg[1] = 0;
	for (int i = 2; i <= n+2; ++i)
		lg[i] = lg[i/2]+1;
	for (int j = 1; j <= 17; ++j)
		for (int i = 1; i + (1LL<<j) <= n+1; ++i){
			st1[i][j] = min(st1[i][j-1],st1[i + (1LL<<(j-1))][j-1]);
			st2[i][j] = max(st2[i][j-1],st2[i + (1LL<<(j-1))][j-1]);
		}
	int l,r,res = 0;
	cin>>q;
	cout<<fixed<<setprecision(1);
	while(q--){
		cin>>l>>r;
		l++;
		r++;
		ll j = lg[r-l+1];
		ll val = min(st1[l][j],st1[r-(1LL<<j)+1][j]);
		ll mx1 = max(st2[l][j],st2[r-(1LL<<j)+1][j]);
		ll mx2 = max(pref[l-1],suff[r+1]);
		//cout<<val<<' '<<mx1<<' '<<mx2<<endl;
		double res = ((double)mx1-val)/2.0;
		res = max(res,(double)mx2);
		cout<<(double)val + res<<'\n';
	}
	return 0;
}