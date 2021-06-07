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
        ll n, x;
        ll sum = 0, mn = 0;
        cin>>n>>x;
        ll a[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            mn+=(a[i] + x - 1)/x;
            sum+=a[i];
        }
        sum = (sum + x-1)/x;
        cout<<min(sum, mn)<<' '<<max(sum, mn)<<'\n';
    }
    return 0;
}