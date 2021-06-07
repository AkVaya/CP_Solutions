#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll top[n], bottom[n], cnt[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>cnt[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin>>top[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin>>bottom[i];
        }
        vector<ll> dp(n+1, 0);
        dp[1] = (cnt[1]-1) + abs(bottom[1] - top[1]) + 2;
        ll res = dp[1];
        for (int i = 2; i < n; ++i)
        {
            if(top[i]!=bottom[i]){
                dp[i] = dp[i-1] + 2 - abs(bottom[i] - top[i]) + cnt[i]-1;
                dp[i] = max(dp[i], (cnt[i]-1) + abs(bottom[i] - top[i]) + 2);
            } 
            else
                dp[i] = cnt[i]-1 + 2;
            res = max(res, dp[i]);
            //cout<<i<<' '<<dp[i]<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}