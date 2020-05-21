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
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
const ll M =1e9+7;
void solve(){
    ll n;
    cin>>n;
    ll a[n][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>a[i][j];
        }
    }    
    vector<ll> dp(1<<n);
    dp[0]=1;
    for (int mask = 0; mask < 1<<n; ++mask)//mask corresponds to the number of women unpaired 
    {
        ll i=__builtin_popcount(mask);
        for (int j = 0; j < n; ++j)
        {
            if(a[i][j] && !(mask & (1<<j))){
                ll mask2=(mask ^ (1<<j));
                dp[mask2]=(dp[mask2]%M+dp[mask]%M)%M;
            }
        }
    }
    cout<<dp[(1<<n)-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    return 0 ;
}