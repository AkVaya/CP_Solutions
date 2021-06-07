#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e6 + 69;
using ll = long long;
const int M = 998244353;
vector<ll> v(nax);
void sieve(){
    for (int i = 2; i < nax; ++i)
    {
        v[i] = (i%2 ? i : 2);
    }
    for (ll i = 3; i <nax; i+=2)
    {
        if (v[i]==i)
        {
            for (ll j = i*i; j < nax; j+=i)
            {
                v[j]= min(i, v[j]);
            }
        }
    }
}
ll fun(ll x){
    ll res = 1;
    while(x>1){
        ll t = v[x], cnt = 0;
        while(x%t==0){
            cnt++;
            x/=t;
        }
        res = (res * (cnt+1))%M;
    }
    return res;
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll res[n+5], pref = 4;
    res[1] = 1;
    res[2] = 3;
    sieve();
    for (ll i = 3; i < n+5; ++i)
    {
        res[i] = (fun(i) + pref)%M;
        pref+=res[i];
        pref%=M;
    }
    cout<<res[n]<<'\n';
    return 0;
} 