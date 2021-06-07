#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e7 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll a[n];
        ll dp[n+1][k+1][2];
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= k; ++j)
                dp[i][j][0] = dp[i][j][1] = -1e18;
        for (int i = 0; i < n; ++i)
            cin>>a[i];
        dp[0][0][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                if(!j){
                    dp[i][j][0] = 0;
                    continue;
                }
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
                ll val = max(dp[i-1][j][1], max(dp[i-1][j-1][0], dp[i-1][j-1][1]));  
                dp[i][j][1] = max(dp[i][j][1], val + a[i-1]*j);
                //cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
            }
        }
        cout<<max(dp[n][k][0], dp[n][k][1])<<'\n';

    }
    return 0;
} 