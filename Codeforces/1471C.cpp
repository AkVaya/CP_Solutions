#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        ll n, m, res = 0;
        cin>>n>>m;
        ll k[n], cost[m];
        for (int i = 0; i < n; ++i)
        {
            cin>>k[i];
        }
        set<int> s;
        for (int i = 0; i < m; ++i)
        {
            cin>>cost[i];
            s.insert(i);
        }
        sort(k, k+n, greater<ll>());
        for (int i = 0; i < n; ++i)
        {
            //cout<<k[i]<<' ';
            int val = *s.begin();
            if(k[i]-1<val || cost[k[i]-1]<=cost[val]){
                res+=cost[k[i]-1];
                //cout<<cost[k[i]-1]<<endl;
                continue;
            }
            res+=cost[val];
            //cout<<cost[val]<<endl;
            s.erase(val);
        }
        cout<<res<<endl;
    }
    return 0;
}