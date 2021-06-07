#include<bits/stdc++.h> 
using namespace std; 
const int nax = 2e4 + 69;
using ll = long long;
const int M = 1e9 + 7;
vector<vector<int> >v;
vector<bool> vis;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        vector<vector<ll> >dp(n+1, vector<ll>(n+1, INT_MIN));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = 0;
            for (int j = 1; j <= i; ++j)
            {
                dp[i][j] = dp[i-1][j];
                if(dp[i-1][j-1]!=INT_MIN && a[i-1] + dp[i-1][j-1]>=0)
                    dp[i][j] = max(dp[i][j], a[i-1] + dp[i-1][j-1]);
                //cout<<dp[i][j]<<' ';
            }
            //cout<<endl;
        }
        for (int i = n; i >= 0; --i)
        {
            //cout<<i<<' '<<dp[n][i]<<endl;
            if(dp[n][i]>=0){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
} 