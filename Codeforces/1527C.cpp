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
        ll a[n], res = 0;
        map<ll, ll> m;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            res+=(m[a[i]]*(n-i));
            m[a[i]]+=(i+1);
        }
        cout<<res<<'\n';
    }
    return 0;
}