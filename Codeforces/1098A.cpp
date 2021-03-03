#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
vector<vector<ll> >v;
vector<ll> s;
int main(){
	ll n, x, y, res= 0;
	cin>>n;
	v.resize(n+1);
	s.resize(n+1,0);
	vector<ll> parent(n+1,0);
	for (int i = 2; i <= n; ++i)
	{
		cin>>x;
		parent[i] = x;
		v[x].push_back(i);
	}
	for (int i = 1; i <= n; ++i){
		cin>>s[i];
	}
	res+=s[1];
	for (int i = 2; i <= n; ++i)
	{
		//cout<<i<<' '<<s[i]<<endl;
		if(s[i]==-1){
			if(!v[i].size()){
			//	cout<<endl;
				continue;
			}
			ll mn = INT_MAX;
			for(auto j : v[i])
				mn = min(mn,s[j]-s[parent[i]]);
			res += mn;
			s[i] = s[parent[i]] + mn;
			if(mn<0){
				cout<<-1<<'\n';
				return 0;
			}
		}
		else{
			if(s[i]<s[parent[i]]){
				cout<<-1<<'\n';
				return 0;	
			}
			res += (s[i] - s[parent[i]]);
		}
		//cout<<s[i]<<endl;
	}
	cout<<res<<'\n';
   	return 0;
}