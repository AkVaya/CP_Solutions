#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e6 + 69;
vector<ll> spf(nax);
void sieve(){
    for (int i = 1; i < nax; ++i)
    {
        spf[i] = (i%2 ? i : 2);
    }
    for (ll i = 3; i <nax; i+=2)
    {
        if (spf[i]==i)
        {
            for (ll j = i*i; j < nax; j+=i)
            {
                spf[j] = min(i, spf[j]);
            }
        }
    }
}
ll fun(ll x){
    ll res = 1;
    //cout<<x<<endl;
    while(x>1){
        int cnt = 0;
        int t = spf[x];
        //cout<<x<<' '<<t<<endl;
        while(x%t==0){
            x/=t;
            cnt++;
        }
        if(cnt%2)
            res*=t;
    }
    //cout<<res<<endl;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int t=1;
    cin>>t;
    while(t--){
        ll n, q, res = 0;
        cin>>n;
        ll a[n];
        map<ll, ll> m;
        ll zer = 0, one = 0;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            //cout<<a[i]<<' ';
            a[i] = fun(a[i]);
            //cout<<a[i]<<endl;
            m[a[i]]++;
            zer = max(zer, m[a[i]]);
        }
        ll cnt = 0;
        for(auto i : m){
            one = max(one, i.second);
            if(i.second%2==0 || i.first==1)
                cnt+=i.second;
        }
        one = max(one, cnt);
        cin>>q;
        while(q--){
            ll x;
            cin>>x;
            if(!x)
                cout<<zer<<'\n';
            else
                cout<<one<<'\n';
        }

    }
    return 0;
}