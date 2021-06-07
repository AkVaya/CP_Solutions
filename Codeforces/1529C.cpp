#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e5 + 69;
using ll = long long;
vector<vector<ll> >v;
ll dp[nax][2], val[nax][2];
void dfs(int s, int p){
    for(auto i : v[s]){
        if(i==p)
            continue;
        dfs(i, s);
        ll x = max(dp[i][0] + abs(val[i][0] - val[s][0]), dp[i][1] + abs(val[i][1] - val[s][0]));
        ll y = max(dp[i][0] + abs(val[i][0] - val[s][1]), dp[i][1] + abs(val[i][1] - val[s][1]));
        dp[s][0] += x;
        dp[s][1] += y;
    }
}
int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, x, y;
        cin>>n;
        v.resize(n+1);
        for (int i = 0; i < n; ++i)
        {
            dp[i+1][0] = dp[i+1][1] = 0;
            cin>>val[i+1][0]>>val[i+1][1];
        }
        for (int i = 0; i < n-1; ++i)
        {
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1, -1);
        /*for (int i = 1; i <= n; ++i)
        {
            cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<endl;
        }*/
        
        cout<<max(dp[1][0], dp[1][1])<<'\n';
        v.clear();
    }
    return 0;
} 