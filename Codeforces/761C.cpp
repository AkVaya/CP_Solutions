#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
#include<ctime>
#include<cmath>
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
const ll M =998244353;
const ll nax=2001;
void add(ll &a,ll b){
    a+=b;
    a%=M;
}
void solve(){
    ll n,m,k;
    cin>>n>>m;
    char s[n][m];
    ll a[n][3];
    for (ll i = 0; i < n; ++i)
    {
        a[i][0]=inf;
        a[i][1]=inf;
        a[i][2]=inf;
        for (ll j = 0; j < m; ++j)
        {
            cin>>s[i][j];
        }
    }
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            ll ind=min(j,m-j);
            if(s[i][j]>='0' && s[i][j]<='9') 
                a[i][0]=min(ind,a[i][0]);
            else if(s[i][j]>='a' && s[i][j]<='z') 
                a[i][1]=min(a[i][1],ind);
            else if(s[i][j]=='#' || s[i][j]=='*' || s[i][j]=='&') 
                a[i][2]=min(a[i][2],ind);
        }
    }
    //for (ll i = 0; i < n; ++i)
    //{
    //    cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
    //}
    ll ans=inf;
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < n; ++j)
        {
            if(i==j)
                continue;
            else{
                for (ll k = 0; k < n; ++k)
                {
                    if(j==k || i==k)
                        continue;
                    ans=min(ans,a[i][0]+a[j][1]+a[k][2]);
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}