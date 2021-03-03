#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll INF = 1e15 + 69; 
ll dp[169][169][169];
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int a[n+1], req[n+1][m+1];
	for (int i = 1; i <= n; ++i){
		cin>>a[i];
	}
	for(int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin>>req[i][j];

	for(int i = 0; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			for (int k = 0; k <= m; ++k)
				dp[i][j][k] = INF;
	if(!a[1])
		for(int j = 1; j <= m; ++j)
			dp[1][1][j] = req[1][j];
	else
		dp[1][1][a[1]] = 0;
	for(int i = 2; i <= n; ++i){
		for(int j = 1; j <= k; ++j){
			if(a[i]){
				dp[i][j][a[i]] = min(dp[i][j][a[i]],dp[i-1][j][a[i]]);
				for(int clr = 1; clr <= m; ++clr)
					if(clr!=a[i])
						dp[i][j][a[i]] = min(dp[i][j][a[i]],dp[i-1][j-1][clr]);
			}
			else{
				for(int clr = 1; clr <= m; ++clr)
				{
					dp[i][j][clr] = min(dp[i][j][clr], req[i][clr] + dp[i-1][j][clr]);
					for(int prev = 1; prev <= m; ++prev)
						if(prev!=clr)
							dp[i][j][clr] = min(dp[i][j][clr], req[i][clr] + dp[i-1][j-1][prev]);
				}
			}
			/*for(int x = 1; x <= m; ++x)
				cout<<dp[i][j][x]<<' ';
			cout<<endl;*/
		} 
		//cout<<endl;
	}
	ll res = INF;
	for (int i = 1; i <= m; ++i)
	{
		//cout<<dp[n][k][i]<<' ';
		res = min(res,dp[n][k][i]);
	}
	cout<<(res>=INF ? -1 : res)<<'\n';
   	return 0;
}
/**
	state 
	i : till i 
	j : exactly j segments or beauty is j
	k : coloring the ith by color k
	initialise

**/