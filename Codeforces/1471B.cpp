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
        ll sum = 0, mn = INT_MAX;
        cin>>n>>x;
        ll a[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            sum+=a[i];
            ll temp = a[i];
            ll cnt = 0;
            while(temp%x==0){
                temp/=x;
                cnt++;
            }
            mn = min(mn, cnt);
        }
        //cout<<mn<<endl;
        bool check = false;
        for (int i = 0; i < n; ++i)
        {
            if(check){
                ll temp = mn;
                a[i]/=x;
                ll t = x;
                while(temp--){
                    sum+=a[i]*t;
                    t*=x;
                    a[i]/=x;
                }
                continue;
            }
            else{    
                ll temp = a[i];
                ll cnt = 0;
                while(temp%x==0){
                    temp/=x;
                    cnt++;
                }
                if(cnt==mn){
                    check = true;
                    i--;
                    continue;
                }
                cnt = mn+1;
                a[i]/=x;
                ll t = x;
                while(cnt--){
                    sum+=a[i]*t;
                    t*=x;
                    a[i]/=x;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}