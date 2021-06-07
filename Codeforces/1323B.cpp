#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
bool prime(int k){
    if(k%2==0)
        return false;
    for (int i = 3; i <= sqrt(k); i+=2)
    {
        if(k%i==0)
            return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        ll a[n], b[m], res = 0;
        for (int i = 0; i < n; ++i){
            cin>>a[i];
            if(i && a[i])
                a[i]+=a[i-1];
        }
        for (int i = 0; i < m; ++i){
            cin>>b[i];
            if(i && b[i])
                b[i]+=b[i-1];
        }
        for (int i = 1; i <= n; ++i)
        {
            if(k%i==0){
                ll cnt1 = 0, cnt2 = 0;
                for (int j = 0; j < n; ++j)
                {
                    if(a[j]>=i)
                        cnt1++;
                }
                for (int j = 0; j < m; ++j)
                {
                    if(b[j]>=(k/i))
                        cnt2++;
                }
                res+=cnt1*cnt2;
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}