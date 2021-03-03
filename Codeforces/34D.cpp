#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
vector<vector<int> >v;
vector<bool> vis;
vector<int> res;
void dfs(int s,int p){
	vis[s] = true;
	res[s] = p;
	for(auto i : v[s])
		if(i!=p)
			dfs(i,s);
}
int main(){
	int n,fir,sec;
	cin>>n>>fir>>sec;
	v.resize(n+1);
	res.resize(n+1,-1);
	vis.resize(n+1,false);
	for (int i = 1; i <= n; ++i)
	{
		if(i==fir)
			continue;
		int x;
		cin>>x;
		//directed[x].push_back(i);
		v[x].push_back(i);
		v[i].push_back(x);
	}
	dfs(sec,-1);
	for(auto i : res)
		if(i>0)
			cout<<i<<' ';
	cout<<'\n';

   	return 0;
}