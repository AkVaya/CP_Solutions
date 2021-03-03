#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;	
int main(){
	ll n;
	cin>>n;
	ll dp[n+5];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; ++i)
	{
		dp[i] = (dp[i-1] + dp[i-2] + 2)%M;
	}
	cout<<dp[n]<<'\n';
   	return 0;
}