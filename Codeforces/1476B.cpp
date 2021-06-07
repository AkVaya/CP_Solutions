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
        ll k;
        cin>>n>>k;
        ll a[n], sum = 0;
        ll res = 0;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            if(i){
                ll val = a[i]*100 - k*sum;
                //cout<<a[i]<<' '<<val<<endl;
                if(val>0)
                    val = (val + k - 1)/k;
                val = max(val, 0LL);
                res+=val;
                sum+=val;
            }
            sum+=a[i];
        }
        cout<<res<<'\n';
    }
    return 0;
}