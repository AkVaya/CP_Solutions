#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
vector<vector<int> >v;
vector<bool> vis;
vector<int> res;
int dfs(int s){
	int cnt = 0;
	for(auto i : v[s])
		cnt += dfs(i);
	res[s] = cnt;
	if(!res[s])
		res[s]++;
	return res[s];
}
int main(){
	int n;
	cin>>n;
	v.resize(n+1);
	res.resize(n+1,0);
	vis.resize(n+1,false);
	for (int i = 2; i <= n; ++i)
	{
		int x;
		cin>>x;
		v[x].push_back(i);
	}
	dfs(1);
	sort(res.begin()+1,res.end());
	for(int i = 1; i <= n; ++i){
		cout<<res[i]<<' ';
	}
	cout<<'\n';

   	return 0;
}