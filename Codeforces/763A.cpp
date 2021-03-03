#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
vector<vector<int> >v;
int n;
vector<int> val;
bool dfs(int s,int p,int x){
	if(x && val[s]!=val[p])
		return false;
	bool res = true;
	for(auto i : v[s])
		if(i!=p){
			res &= dfs(i,s,1);
			if(!res)
				break;
		}
	return res;
}
int main(){
	int n,x,y;
	cin>>n;
	v.resize(n+1);
	val.resize(n+1);
	for (int i = 0; i < n-1; ++i)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i)
		cin>>val[i];
	int fir = -1, sec = -1;
	for (int i = 1; i <= n; ++i){
		for(auto j : v[i])
			if(val[i]!=val[j]){
				fir = i;
				sec = j;
				break;
			}
		if(fir>0)
			break;
	}
	if(fir<0){
		cout<<"YES\n1\n";
		return 0;
	}
	bool check = true;
	for(auto i : v[fir]){
		check &= dfs(i,fir,0);
		if(!check)
			break;
	}
	if(check){
		cout<<"YES\n"<<fir<<'\n';
		return 0;
	}
	check = true;
	for(auto i : v[sec]){
		check &= dfs(i,sec,0);
		if(!check)
			break;
	}
	if(check){
		cout<<"YES\n"<<sec<<'\n';
		return 0;
	}
	else
		cout<<"NO\n";

   	return 0;
}