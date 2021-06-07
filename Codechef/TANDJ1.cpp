#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e6 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        ll val = abs(a-c) + abs(d-b);
        cout<<((val<=k && (k-val)%2==0) ? "YES" : "NO")<<'\n';
    }
    return 0;
} 