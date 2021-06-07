#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll M = 1e9 + 7;
ll binpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b%2)
            res = (res * a)%M;
        a = (a*a)%M;
        b>>=1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n, m, cnt = 0;
        cin>>n>>m;
        char a[n][m];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin>>a[i][j];
                cnt += (a[i][j] == '#');
            }
        }
        ll res = binpow(2, cnt);
        if(cnt==n*m){
            res--;
            res+=M;
            res%=M;
        }
        cout<<res<<'\n';

    }
    return 0;
}