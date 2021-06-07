#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e7 + 69;
using ll = long long;
vector<bool> v(nax);
vector<ll> x;
void sieve(){
    v[0]=false;
    v[1]=false;
    for (int i = 2; i < nax; i+=2)
    {
        v[i] = true;
    }
    x.emplace_back(2);
    for (ll i = 3; i <nax; i+=2)
    {
        if (v[i]==false)
        {
            x.emplace_back(i);
            for (ll j = i*i; j < nax; j+=i)
            {
                v[j]=true;
            }
        }
    }
}
int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==2){
            cout<<1<<'\n';
            continue;
        }
        else if(n==3){
            cout<<2<<'\n';
            continue;
        }
        auto it = upper_bound(x.begin(), x.end(), n);
        
        int res = (it-x.begin());
        //cout<<res<<' ';
        it = upper_bound(x.begin(), x.end(), n/2);
        res -= (it-x.begin());
        //cout<<res<<' ';
        res++;
        cout<<res<<'\n';
    }
    return 0;
} 