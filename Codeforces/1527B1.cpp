#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
ll M = 1e18;
ll binpow(ll a,ll b,ll m=M) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        int cnt = 0;
        for(auto i : s)
            cnt+=i=='0';
        if(n%2 && s[n/2]=='0' && cnt>1){
            cout<<"ALICE\n";
        }
        else{
            cout<<"BOB\n";
        }
    }
    return 0;
}