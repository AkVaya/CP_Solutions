#include<bits/stdc++.h>
using namespace std;
const int nax = 2e7+1;
using ll = long long;
vector<bool> v(nax);
vector<ll> x;
void sieve(){
	x.emplace_back(2);
	for (ll i = 3; i <nax; i+=2)
	{
		if (v[i]==false)
		{
			x.emplace_back(i);
			for (ll j = i*i; j < nax; j+=i)
			{
				v[j]=true;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	long long n;
	sieve();
	vector<pair<int,int> > ans;
	for (int i = 1; i < x.size(); ++i)
	{
		if(x[i]-x[i-1]==2)
			ans.push_back({x[i-1],x[i]});
	}
	while(scanf("%lld",&n)==1){
		cout<<'('<<ans[n-1].first<<", "<<ans[n-1].second<<")"<<endl;
	}
	return 0;
}