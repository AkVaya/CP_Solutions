#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
vector<vector<ll> >v;
vector<ll> s;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int start[k][2], end[k][2];
	for (int i = 0; i < k; ++i)
	{
		cin>>start[i][0]>>start[i][1];
	}
	for (int i = 0; i < k; ++i)
	{
		cin>>end[i][0]>>end[i][1];
	}
	string res;
	for (int i = 0; i < m-1; ++i)
		res+="L";
	for (int i = 0; i < n-1; ++i)
		res+="U";
	int x = 0,y = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if(i%2==0)
				res+="R";
			else
				res+="L";
		}
		res+="D";
	}
	cout<<res.size()<<'\n';
	for(auto i : res)
		cout<<i;
	cout<<'\n';
   	return 0;
}