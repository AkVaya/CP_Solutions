#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
const ll M = 1e9 + 7;
int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	multiset<ll,greater<ll> > s;
	ll a[n];
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	double res = 0;
	for (int i = 0; i < min(n,k+1); ++i)
	{
		double num = sum;
		num += min(m*(n-i),(k-i));
		res = max(res, num /(n-i) );
		sum-=a[i];
	}
	cout<<fixed<<setprecision(10);
	cout<<res<<'\n';
	return 0;
}