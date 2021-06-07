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
        ll n, k;
        cin>>n>>k;
        ll val = (n+k-1)/k;
        cout<<(n+k*val-1)/n<<'\n';
    }
    return 0;
}