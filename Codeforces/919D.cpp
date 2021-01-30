#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >v;
vector<int> vis;
string str;
int main(){
	int n,m,x,y;
	cin>>n>>m;
	cin>>str;
	v.resize(n);
	vis.resize(n,0);
	vector<int> in(n,0);
	while(m--){
		cin>>x>>y;
		v[x-1].push_back(y-1);
		in[y-1]++;
	}
	queue<int>q;
	vector<vector<int> > res(n,vector<int>(26,0));
	for (int i = 0; i < n; ++i)
	{
		if(in[i]==0){
			q.push(i);
			res[i][str[i]-'a'] = 1;
		}
	}
	int cnt = 0;
	while(q.size()){
		int curr = q.front();
		q.pop();
		cnt++;
		for (auto x : v[curr])
		{
			in[x]--;
			for (int i = 0; i < 26; ++i)
			{
				res[x][i] = max(res[x][i],((str[x]-'a') == i) + res[curr][i]); 
			}
			if(!in[x])
				q.push(x);
		}
	}
	if(cnt!=n){
		cout<<"-1\n";
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			ans = max(ans,res[i][j]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}