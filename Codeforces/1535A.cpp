#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        vector<ll> v(4);
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        v[0] = a;
        v[1] = b;
        v[2] = c;
        v[3] = d;
        sort(v.begin(), v.end());
        if(max(a, b)==v[3] && min(a, b)==v[2])
            cout<<"NO\n";
        else if(max(c, d)==v[3] && min(c, d)==v[2])
            cout<<"NO\n";
        else
            cout<<"YES\n";

    }
    return 0;
}