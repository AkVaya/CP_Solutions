#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        int n, k = 0;
        cin>>n;
        int a[n];
        vector<int> ind;
        for (int i = 0; i < n; ++i){
            cin>>a[i];
            if(a[i])
                ind.push_back(i);
        }
        k = ind.size();
        vector<vector<int> > dp(n+1, vector<int>(k+1, n*n));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = 0;
            for (int j = 1; j <= k; ++j)
            {
                dp[i][j] = dp[i-1][j];
                if(a[i-1]==0){
                    int val = abs(i-1 - ind[j-1]) + dp[i-1][j-1];
                    dp[i][j] = min(dp[i-1][j], val);
                }
            }
        }
        /*for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= k; ++j)
                cout<<dp[i][j]<<' ';
            cout<<'\n';
        }*/
        cout<<dp[n][k]<<'\n';
    }
    return 0;
}