#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		vector<int>dp(n+1,0);
		for (int i = 1; i <= n; ++i)
		{
			dp[i]=dp[i-1];
			int diff = 0;
			for (int j = i; j > 0; --j)
			{
				if(s[j-1]-'0')
					diff++;
				else
					diff--;
				if(diff>0){
					dp[i] = max(dp[i],dp[j-1] + i-j+1);
				}
			}
		}
		cout<<dp[n]<<'\n';
	}
	return 0;
}