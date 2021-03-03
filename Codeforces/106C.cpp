#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e3 + 69;
int n,m,c0,d0;
int a[11][4], dp[nax][11];
int main(){
   	cin>>n>>m>>c0>>d0;
   	for (int i = 0; i < m; ++i)
   	{
   		cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
   	}
   	int res = 0;
   	for(int i = 1; i <= n; ++i){
   		for(int j = 0; j < m; ++j){
   			int mx = a[j][0]/a[j][1];
   			for(int q = 0; q <= mx; ++q){
   				if(i-q*a[j][2]>=0)
   					dp[i][j] = max(dp[i-q*a[j][2]][j-1] + a[j][3]*q,dp[i][j]);
   			}
   		}
   	}
   	for(int i = 0; i <= n; ++i){
   		res = max(res,dp[i][m-1] + (n-i)/c0 * d0);
   	}
   	cout<<res<<'\n';
   	return 0;
}