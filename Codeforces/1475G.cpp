#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 69;
const int M = 1e9 + 7;
using ll = long long;
int n,a[nax];
vector<bool> vis(nax);
map<int,int>m;
vector<int>val(nax);
void dfs(int s){
	vis[s] = true;
	if(!m.count(s))
		return;
	int i = 2;
	while(i*s<=200000){
		if(!vis[i*s])
			dfs(i*s);
		val[s] = max(val[s],val[i*s]);
		i++;
	}
	val[s]+=m[s];
	//cout<<s<<' '<<val[s]<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			m[a[i]]++;
		}
		int mx = 0;
		for (auto i : m)
		{
			if(!vis[i.first])
				dfs(i.first);
			mx = max(mx,val[i.first]);
		}
		cout<<n-mx<<'\n';
		val.clear();
		val.resize(nax,0);
		fill(vis.begin(),vis.end(),false);
		m.clear();
	}
	return 0;
}