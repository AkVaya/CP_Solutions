#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		string s;
		cin>>s;
		map<long long,long long> m;
		long long ans = 0,sum=0,pref[n+1];
		pref[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			pref[i] = pref[i-1] + s[i-1]-'0';
		}
		for (int i = 0; i <= n; ++i)
		{
			pref[i]-=i;
			m[pref[i]]++;
		}
		for(auto i : m)
		{
			ans+=(i.second*(i.second-1))/2;
		}
		cout<<ans<<'\n';
	}
	return 0;
}