#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 69;
vector<vector<int> > v;
int all[nax],sz[nax],ind[nax],cnt = 0;
void dfs(int s,int p){
	ind[s] = cnt;
	all[cnt++] = s;
	sz[s]++;
	for(auto i : v[s]){
		if(i==p)
			continue;
		dfs(i,s);
		sz[s] += sz[i];
	}
}
int main(){
   	int n,q;
   	cin>>n>>q;
   	v.resize(n+1);
   	int a = 2,x,y;
   	for (int i = 0; i < n-1; ++i)
   	{
   		cin>>x;
   		v[x].push_back(a++);
   	}
   	dfs(1,-1);
   	while(q--){
   		cin>>x>>y;
   		if(sz[x]>=y)
   			cout<<all[ind[x] + y-1]<<'\n';
   		else
   			cout<<"-1\n";
   	}
   	return 0;
}